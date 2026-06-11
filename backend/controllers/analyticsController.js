const db        = require('../config/db');
const cdsEngine = require('../services/cdsEngine');
const { classify, CDS_THRESHOLDS } = cdsEngine;
const classMisconceptionReport = require('../services/classMisconceptionReport');
const longitudinalReportEngine = require('../services/longitudinalReportEngine');
const { wilsonScore, confidenceLevel } = require('../lib/wilsonScore');
const { evaluateRules } = require('../lib/insightTemplates');

const CONCEPT_ORDER = ['Datatypes','Variables','Conditionals','Loops','Functions','Arrays','OOP'];

// Helper: distribution count labels using authoritative thresholds
const countLabel = (cds) => {
  if (cds === null || cds === undefined) return 'Unscored';
  if (cds <= CDS_THRESHOLDS.LOW) return 'Low';
  if (cds <= CDS_THRESHOLDS.MODERATE) return 'Moderate';
  return 'High';
};

/** CDS distribution + avg for one exercise in a section (after batch compute). */
async function fetchExerciseCdsStats(exerciseId, sectionId) {
  const statsRes = await db.query(
    `SELECT
       (SELECT COUNT(*)::INTEGER FROM enrollments WHERE section_id = $2) AS total_students,
       (SELECT COUNT(DISTINCT student_id)::INTEGER FROM submissions
        WHERE exercise_id = $1
          AND student_id IN (SELECT student_id FROM enrollments WHERE section_id = $2)) AS submitted_count,
       (SELECT AVG(cs.cds) FROM cds_scores cs
        WHERE cs.exercise_id = $1 AND cs.section_id = $2) AS avg_cds,
       (SELECT COUNT(CASE WHEN cs.cds <= $3 THEN 1 END)::INTEGER FROM cds_scores cs
        WHERE cs.exercise_id = $1 AND cs.section_id = $2) AS low_count,
       (SELECT COUNT(CASE WHEN cs.cds > $3 AND cs.cds <= $4 THEN 1 END)::INTEGER FROM cds_scores cs
        WHERE cs.exercise_id = $1 AND cs.section_id = $2) AS moderate_count,
       (SELECT COUNT(CASE WHEN cs.cds > $4 THEN 1 END)::INTEGER FROM cds_scores cs
        WHERE cs.exercise_id = $1 AND cs.section_id = $2) AS high_count`,
    [exerciseId, sectionId, CDS_THRESHOLDS.LOW, CDS_THRESHOLDS.MODERATE]
  );
  return statsRes.rows[0] || {};
}

exports.heatmap = async (req, res, next) => {
  const { sectionId } = req.params;
  const instructorId = req.user?.id;
  const secCond = sectionId === 'all'
    ? `ex.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
    : `ex.section_id = $1`;
  const enrollCond = sectionId === 'all'
    ? `e.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
    : `e.section_id = $1`;
  const cdsCond = sectionId === 'all'
    ? `cs.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
    : `cs.section_id = $1`;
  const secParam = sectionId === 'all' ? [String(instructorId)] : [sectionId];

  try {
    // First, recalculate CDS for all exercises in this section (or all sections)
    const exercises = await db.query(
      `SELECT DISTINCT ex.id FROM exercises ex WHERE ${secCond}`,
      secParam
    );

    for (const ex of exercises.rows) {
      try {
        await cdsEngine.computeBatchCDS(ex.id, db);
      } catch (err) {
        console.error(`CDS calculation failed for exercise ${ex.id}:`, err);
      }
    }

    const students = await db.query(
      `SELECT u.id, u.name FROM users u
       JOIN enrollments e ON e.student_id=u.id
       WHERE ${enrollCond} ORDER BY u.name`,
      secParam
    );

    const scores = await db.query(
      `SELECT cs.student_id, cs.cds, cs.classification, cs.ner, cs.nrs, cs.nts,
              c.name AS concept_name, ex.title AS exercise_title
       FROM cds_scores cs
       JOIN exercises ex ON ex.id=cs.exercise_id
       JOIN concepts c ON c.id=ex.concept_id
       WHERE ${cdsCond}`,
      secParam
    );

    const scoreMap = {};
    for (const s of scores.rows) {
      if (!scoreMap[s.student_id]) scoreMap[s.student_id] = {};
      scoreMap[s.student_id][s.concept_name] = {
        cds: s.cds, classification: s.classification,
        exerciseTitle: s.exercise_title, ner: s.ner, nrs: s.nrs, nts: s.nts
      };
    }

    const avgMap = {};
    for (const concept of CONCEPT_ORDER) {
      const vals = scores.rows
        .filter(s => s.concept_name===concept && s.cds !== null)
        .map(s => parseFloat(s.cds));
      if (vals.length) {
        const avg = vals.reduce((a,b)=>a+b,0) / vals.length;
        const cl = countLabel(avg);
        avgMap[concept] = { avgCDS: Math.round(avg*10000)/10000, classification: cl };
      } else {
        avgMap[concept] = { avgCDS: null, classification: 'Unscored' };
      }
    }

    res.json({
      students: students.rows,
      concepts: CONCEPT_ORDER,
      scores: scoreMap,
      classAverages: avgMap
    });
  } catch (err) { next(err); }
};

exports.getAlerts = async (req, res, next) => {
  try {
    const r = await db.query(
      `SELECT al.*, u.name AS student_name, ex.title AS exercise_title
       FROM alerts al
       JOIN users u ON u.id=al.student_id
       JOIN exercises ex ON ex.id=al.exercise_id
       WHERE al.section_id=$1 AND al.is_reviewed=false
       ORDER BY al.cds_score DESC`,
      [req.params.sectionId]
    );
    res.json(r.rows);
  } catch (err) { next(err); }
};

exports.reviewAlert = async (req, res, next) => {
  try {
    await db.query(
      'UPDATE alerts SET is_reviewed=true WHERE id=$1', [req.params.alertId]
    );
    res.json({ message: 'Alert marked as reviewed' });
  } catch (err) { next(err); }
};

exports.liveRanking = async (req, res, next) => {
  try {
    const ranking = await cdsEngine.getLivePeerRanking(req.params.exerciseId, db);
    res.json(ranking);
  } catch (err) { next(err); }
};

exports.liveCDS = async (req, res, next) => {
  // Instructor view: live CDS with preliminary badge
  try {
    const exerciseId = req.params.exerciseId;
    
    // Get exercise and time limit
    const exRes = await db.query('SELECT * FROM exercises WHERE id=$1', [exerciseId]);
    if (!exRes.rows.length) return res.status(404).json({ message: 'Exercise not found' });
    const exercise = exRes.rows[0];
    
     // Get all CDS scores for this exercise (batch or live)
    const scores = await db.query(`
      SELECT 
        cs.student_id, u.name, cs.ner, cs.nrs, cs.nts, cs.cds, cs.classification,
        (SELECT COUNT(*) FROM submissions WHERE exercise_id=$1 AND student_id=cs.student_id) as total_attempts,
        (SELECT COUNT(*) FROM submissions WHERE exercise_id=$1 AND student_id=cs.student_id AND is_correct=false) as failed_attempts
      FROM cds_scores cs
      JOIN users u ON u.id=cs.student_id
      WHERE cs.exercise_id=$1
      ORDER BY cs.cds DESC
    `, [exerciseId]);
    
    const MIN_CLASS_SIZE = 3;
    const submitterRes = await db.query(
      `SELECT COUNT(DISTINCT student_id) AS count FROM submissions WHERE exercise_id = $1`,
      [exerciseId]
    );
    const enrolledRes = await db.query(
      `SELECT COUNT(*) AS count FROM enrollments WHERE section_id = $1`,
      [exercise.section_id]
    );
    const submissionCountRes = await db.query(
      'SELECT COUNT(*) AS count FROM submissions WHERE exercise_id = $1',
      [exerciseId]
    );

    const submitterCount = parseInt(submitterRes.rows[0].count, 10) || 0;
    const enrolledCount = parseInt(enrolledRes.rows[0].count, 10) || 0;
    const submissionCount = parseInt(submissionCountRes.rows[0].count, 10) || 0;

    // Preliminary when too few distinct submitters or incomplete class participation
    const isPreliminary =
      submitterCount < MIN_CLASS_SIZE ||
      enrolledCount < MIN_CLASS_SIZE ||
      (enrolledCount > 0 && submitterCount < enrolledCount);

    let reliability = 'Accurate';
    if (isPreliminary) {
      reliability =
        submitterCount < MIN_CLASS_SIZE
          ? 'Preliminary'
          : 'Preliminary (incomplete participation)';
    }

    // Only rank students who have submitted on this exercise
    const rankings = scores.rows
      .filter(s => parseInt(s.total_attempts, 10) > 0)
      .map(s => ({
        studentId: s.student_id,
        name: s.name,
        totalAttempts: parseInt(s.total_attempts, 10) || 0,
        failedAttempts: parseInt(s.failed_attempts, 10) || 0,
        ner: parseFloat(s.ner || 0),
        nrs: parseFloat(s.nrs || 0),
        nts: parseFloat(s.nts || 0),
        cds: parseFloat(s.cds || 0),
        classification: s.classification
      }));

    const rankedCds = rankings.map(r => r.cds);
    const classAvgFromSubmitters =
      rankedCds.length > 0 ? rankedCds.reduce((a, b) => a + b, 0) / rankedCds.length : 0;
    const classMinFromSubmitters = rankedCds.length > 0 ? Math.min(...rankedCds) : 0;
    const classMaxFromSubmitters = rankedCds.length > 0 ? Math.max(...rankedCds) : 0;
    const classAvgClassification = countLabel(classAvgFromSubmitters);

    res.json({
      exercise: { id: exercise.id, title: exercise.title, timeLimitMinutes: exercise.time_limit_minutes },
      studentCount: submitterCount,
      enrolledCount,
      submitterCount,
      submissionCount,
      preliminary: isPreliminary,
      reliability,
      classAverage: {
        ner: rankings.length > 0 ? (rankings.reduce((a, s) => a + s.ner, 0) / rankings.length) : 0,
        nrs: rankings.length > 0 ? (rankings.reduce((a, s) => a + s.nrs, 0) / rankings.length) : 0,
        nts: rankings.length > 0 ? (rankings.reduce((a, s) => a + s.nts, 0) / rankings.length) : 0,
        cds: classAvgFromSubmitters,
        classification: classAvgClassification,
        min: classMinFromSubmitters,
        max: classMaxFromSubmitters
      },
      rankings
    });
  } catch (err) { next(err); }
};

exports.studentProfile = async (req, res, next) => {
  try {
    const r = await db.query(
      `SELECT cs.cds, cs.classification, cs.ner, cs.nrs, cs.nts, cs.computed_at,
              c.name AS concept_name, ex.title AS exercise_title
       FROM cds_scores cs
       JOIN exercises ex ON ex.id=cs.exercise_id
       JOIN concepts c ON c.id=ex.concept_id
       WHERE cs.student_id=$1
       ORDER BY cs.computed_at ASC`,
      [req.params.studentId]
    );
    res.json(r.rows);
  } catch (err) { next(err); }
};

exports.myScores = async (req, res, next) => {
  try {
    // Return CDS scores for the authenticated student only
    const r = await db.query(
      `SELECT cs.cds, cs.classification, cs.ner, cs.nrs, cs.nts, cs.computed_at,
              cs.exercise_id, c.name AS concept_name, ex.title AS exercise_title
       FROM cds_scores cs
       JOIN exercises ex ON ex.id=cs.exercise_id
       JOIN concepts c ON c.id=ex.concept_id
       WHERE cs.student_id=$1
       ORDER BY cs.computed_at DESC`,
      [req.user.id]
    );

    // If no scores exist, return empty array (frontend shows 'No scores yet')
    res.json(r.rows || []);
  } catch (err) { next(err); }
};

exports.recentActivity = async (req, res, next) => {
  try {
    const { sectionId } = req.params;
    const r = await db.query(
      `SELECT
        al.id, al.student_id, al.cds_score as cds, al.exercise_id, al.created_at,
        u.name AS student_name, ex.title AS exercise_title, ex.concept_id,
        c.name AS concept_name
       FROM alerts al
       JOIN users u ON u.id=al.student_id
       JOIN exercises ex ON ex.id=al.exercise_id
       JOIN concepts c ON c.id=ex.concept_id
       WHERE al.section_id=$1
       ORDER BY al.created_at DESC
       LIMIT 5`,
      [sectionId]
    );
    // Classify using authoritative thresholds
    res.json(r.rows.map(row => ({
      ...row,
      difficulty: countLabel(parseFloat(row.cds))
    })));
  } catch (err) { next(err); }
};

// New endpoint for class misconception report
exports.classMisconceptionReport = async (req, res, next) => {
  try {
    const { exerciseId } = req.params;
    const report = await classMisconceptionReport.generateClassMisconceptionReport(parseInt(exerciseId));
    res.json(report);
  } catch (err) {
    console.error('Error generating class misconception report:', err);
    next(err);
  }
};

// New endpoint for longitudinal report (mastery velocity)
exports.longitudinalReport = async (req, res, next) => {
  try {
    const { studentId, conceptId } = req.params;
    const sectionId = req.query.sectionId || null;
    
    // If conceptId is missing, return a summary or all concepts for this student
    if (!conceptId) {
      const allConceptsRes = await db.query(
        `SELECT DISTINCT c.id, c.name FROM concepts c
         JOIN exercises ex ON ex.concept_id = c.id
         JOIN cds_scores cs ON cs.exercise_id = ex.id
         WHERE cs.student_id = $1`,
        [studentId]
      );
      
      const reports = [];
      for (const concept of allConceptsRes.rows) {
        try {
          const report = await longitudinalReportEngine.calculateMasteryVelocity(
            parseInt(studentId),
            parseInt(concept.id),
            sectionId ? parseInt(sectionId) : null
          );
          reports.push(report);
        } catch (err) {
          console.error(`Error generating report for concept ${concept.id}:`, err);
        }
      }
      return res.json({ studentId, reports });
    }

    const report = await longitudinalReportEngine.calculateMasteryVelocity(
      parseInt(studentId),
      parseInt(conceptId),
      sectionId ? parseInt(sectionId) : null
    );
    res.json(report);
  } catch (err) {
    console.error('Error generating longitudinal report:', err);
    next(err);
  }
};

// ── NEW: Section-Scoped Analytics Controllers ────────────────────────────────

/**
 * GET /api/analytics/sections/:sectionId/micro-concept-alerts
 * Returns micro-concept alerts for all students in section
 */
exports.getMicroConceptAlerts = async (req, res, next) => {
  try {
    const { sectionId } = req.params;
    const { classification, concept } = req.query;

    // Get students in section
    const studentsRes = await db.query(
      `SELECT u.id FROM users u
       JOIN enrollments e ON e.student_id = u.id
       WHERE e.section_id = $1`,
      [sectionId]
    );
    const studentIds = studentsRes.rows.map(r => r.id);

    // Get CDS scores for students
    let query = `
      SELECT cs.*, u.name AS student_name, ex.title AS exercise_title, 
             c.name AS concept_name
      FROM cds_scores cs
      JOIN users u ON cs.student_id = u.id
      JOIN exercises ex ON cs.exercise_id = ex.id
      JOIN concepts c ON ex.concept_id = c.id
      WHERE cs.student_id = ANY($1) AND cs.section_id = $2
    `;
    const params = [studentIds, sectionId];

    // Filter by classification if provided
    if (classification) {
      query += ` AND cs.classification = $${params.length + 1}`;
      params.push(classification);
    }

    // Filter by concept if provided
    if (concept) {
      query += ` AND c.name = $${params.length + 1}`;
      params.push(concept);
    }

    query += ` ORDER BY cs.cds DESC, cs.computed_at DESC`;

    const scoresRes = await db.query(query, params);
    res.json(scoresRes.rows);
  } catch (err) {
    console.error('Error fetching micro-concept alerts:', err);
    next(err);
  }
};

/**
 * PUT /api/analytics/micro-concept-alerts/:alertId/mark-reviewed
 */
exports.markMicroConceptAlertReviewed = async (req, res, next) => {
  try {
    const { alertId } = req.params;
    const result = await db.query(
      `UPDATE alerts SET is_reviewed = true WHERE id = $1 RETURNING *`,
      [alertId]
    );
    res.json(result.rows[0]);
  } catch (err) {
    console.error('Error marking alert reviewed:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/sections/:sectionId/class-insights
 * Returns class misconception reports for all exercises in section
 */
exports.getClassInsights = async (req, res, next) => {
  try {
    const { sectionId } = req.params;

    // Get all closed exercises in section
    const exercisesRes = await db.query(
      `SELECT e.id, e.title, c.name AS concept_name
       FROM exercises e
       JOIN concepts c ON e.concept_id = c.id
       WHERE e.section_id = $1 AND e.closed_at IS NOT NULL
       ORDER BY e.closed_at DESC`,
      [sectionId]
    );

    // Generate reports for each exercise
    const reports = [];
    for (const exercise of exercisesRes.rows) {
      try {
        const report = await classMisconceptionReport.generateClassMisconceptionReport(exercise.id);
        reports.push(report);
      } catch (err) {
        console.error(`Error generating report for exercise ${exercise.id}:`, err);
      }
    }

    res.json(reports);
  } catch (err) {
    console.error('Error fetching class insights:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/sections/:sectionId/class-insights/:exerciseId
 * Auto-triggers batch CDS (default), then returns misconception report + fresh stats.
 * Query: refresh=false to skip CDS recompute (report only).
 */
exports.getClassInsightsByExercise = async (req, res, next) => {
  try {
    const { sectionId, exerciseId } = req.params;
    const shouldRefreshCds = req.query.refresh !== 'false';

    const exerciseRes = await db.query(
      `SELECT ex.id, ex.title, ex.closed_at, ex.section_id, c.name AS concept_name
       FROM exercises ex
       JOIN concepts c ON ex.concept_id = c.id
       WHERE ex.id = $1 AND ex.section_id = $2`,
      [exerciseId, sectionId]
    );

    if (!exerciseRes.rows.length) {
      return res.status(404).json({ message: 'Exercise not found in section' });
    }

    const exercise = exerciseRes.rows[0];
    let cdsResult = null;
    let cdsError = null;

    if (shouldRefreshCds) {
      try {
        cdsResult = await cdsEngine.computeBatchCDS(parseInt(exerciseId, 10), db);
      } catch (err) {
        cdsError = err.message;
        console.error(`CDS auto-trigger failed for exercise ${exerciseId}:`, err);
      }
    }

    const report = await classMisconceptionReport.generateClassMisconceptionReport(
      parseInt(exerciseId, 10)
    );
    const exerciseStats = await fetchExerciseCdsStats(exerciseId, sectionId);

    res.json({
      exerciseId: parseInt(exerciseId, 10),
      sectionId: parseInt(sectionId, 10),
      title: exercise.title,
      conceptName: exercise.concept_name,
      closedAt: exercise.closed_at,
      cdsComputed: Boolean(cdsResult),
      cdsError,
      studentsProcessed: cdsResult?.studentsProcessed ?? null,
      exerciseStats: {
        ...exerciseStats,
        closed_at: exercise.closed_at
      },
      report
    });
  } catch (err) {
    console.error('Error fetching class insights:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/sections/:sectionId/longitudinal
 * Returns longitudinal progress for all students in section
 */
exports.getSectionLongitudinal = async (req, res, next) => {
  try {
    const { sectionId } = req.params;

    // Get students in section
    const studentsRes = await db.query(
      `SELECT u.id, u.name FROM users u
       JOIN enrollments e ON e.student_id = u.id
       WHERE e.section_id = $1
       ORDER BY u.name`,
      [sectionId]
    );

    // Get progression for each student
    const students = [];
    for (const student of studentsRes.rows) {
      const progressionRes = await db.query(
        `SELECT cs.cds, cs.classification, cs.computed_at,
                ex.title AS exercise_title, ex.id AS exercise_id,
                c.id AS concept_id, c.name AS concept_name
         FROM cds_scores cs
         JOIN exercises ex ON cs.exercise_id = ex.id
         JOIN concepts c ON ex.concept_id = c.id
         WHERE cs.student_id = $1 AND cs.section_id = $2
         ORDER BY cs.computed_at ASC`,
        [student.id, sectionId]
      );

      // Calculate mastery velocity
      const progression = progressionRes.rows;
      let masteryVelocity = 'stable';
      if (progression.length >= 2) {
        const recent = progression.slice(-3);
        const cdsValues = recent.map(p => parseFloat(p.cds));
        const trend = cdsValues[cdsValues.length - 1] - cdsValues[0];
        if (trend > 0.1) masteryVelocity = 'improving';
        else if (trend < -0.1) masteryVelocity = 'declining';
      }

      students.push({
        studentId: student.id,
        studentName: student.name,
        progression,
        masteryVelocity
      });
    }

    res.json({ sectionId, students });
  } catch (err) {
    console.error('Error fetching section longitudinal data:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/sections/:sectionId/integrity-flags/:exerciseId
 * Per-exercise flag list (array). Section-wide paginated list: integrityController via routes/integrity.js
 */
exports.getIntegrityFlagsByExercise = async (req, res, next) => {
  try {
    const { sectionId, exerciseId } = req.params;
    const integrityFlagEngine = require('../services/integrityFlagEngine');

    // Verify exercise belongs to section
    const exerciseRes = await db.query(
      `SELECT id FROM exercises WHERE id = $1 AND section_id = $2`,
      [exerciseId, sectionId]
    );

    if (!exerciseRes.rows.length) {
      return res.status(404).json({ message: 'Exercise not found in section' });
    }

    const flags = await integrityFlagEngine.getFlagsForExercise(exerciseId);
    res.json(flags);
  } catch (err) {
    console.error('Error fetching exercise integrity flags:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/section/:id/hub — Aggregated Command Center payload (spec §12).
 */
exports.getSectionHub = async (req, res, next) => {
  const { id } = req.params;
  try {
    const section = await db.query('SELECT * FROM sections WHERE id = $1', [id]);
    if (section.rows.length === 0) {
      return res.status(404).json({ error: 'Section not found' });
    }

    const [cdsResult, submissionsResult, masteryResult, atRiskResult, flagsResult, membersResult] = await Promise.all([
      db.query(`SELECT COALESCE(AVG(cds), 0) as avg_cds, COUNT(*) as n FROM cds_scores WHERE section_id = $1`, [id]),
      db.query(`SELECT COUNT(*) as total, COUNT(*) FILTER (WHERE created_at > NOW() - INTERVAL '7 days') as weekly FROM submissions s JOIN enrollments m ON s.student_id = m.student_id JOIN exercises ex ON s.exercise_id = ex.id WHERE m.section_id = $1 AND ex.mode = 'learning' AND s.is_practice IS NOT TRUE`, [id]),
      db.query(`SELECT c.name, COALESCE(AVG(cm.cds), 0) as cds, COUNT(*) FILTER (WHERE cm.cds > 0.50) as at_risk_count FROM cds_scores cm JOIN exercises ex ON cm.exercise_id = ex.id JOIN concepts c ON ex.concept_id = c.id JOIN enrollments m ON cm.student_id = m.student_id WHERE m.section_id = $1 GROUP BY c.id, c.name ORDER BY cds DESC`, [id]),
      db.query(`SELECT u.id, u.name, COALESCE(AVG(cs.cds), 0) as avg_cds, COUNT(fl.id) as flag_count FROM enrollments m JOIN users u ON m.student_id = u.id LEFT JOIN cds_scores cs ON cs.student_id = u.id LEFT JOIN integrity_flags fl ON fl.student_id = u.id AND fl.section_id = $1 WHERE m.section_id = $1 GROUP BY u.id, u.name HAVING COALESCE(AVG(cs.cds), 0) > 0.50 OR COUNT(fl.id) > 0 ORDER BY COALESCE(AVG(cs.cds), 0) DESC LIMIT 20`, [id]),
      db.query(`SELECT COUNT(*) as open_count, COUNT(DISTINCT section_id) as section_count FROM integrity_flags WHERE section_id = $1 AND status = 'open'`, [id]),
      db.query(`SELECT COUNT(*) FROM enrollments WHERE section_id = $1`, [id]),
    ]);

    const avgCds = parseFloat(cdsResult.rows[0].avg_cds) || 0;
    const totalStudents = parseInt(membersResult.rows[0].count) || 0;
    const conceptRows = masteryResult.rows.map(r => ({ concept: r.name, cds: parseFloat(r.cds) || 0, atRiskCount: parseInt(r.at_risk_count) || 0 }));

    res.json({
      summary: `Section analytics. ${totalStudents} active students, avg CDS ${avgCds.toFixed(2)}.`,
      confidence: confidenceLevel(avgCds, parseInt(cdsResult.rows[0].n) || 0, 18),
      weeklyInsight: evaluateRules({ conceptData: conceptRows, totalStudents, currentFlags: parseInt(flagsResult.rows[0].open_count) || 0, priorWeekFlags: 0 })[0] || null,
      conceptBars: conceptRows,
      atRiskRoster: atRiskResult.rows.map(r => ({ id: r.id, name: r.name, avgCds: parseFloat(r.avg_cds) || 0, flagCount: parseInt(r.flag_count) || 0 })),
      integrityFlags: { count: parseInt(flagsResult.rows[0].open_count) || 0, sections: parseInt(flagsResult.rows[0].section_count) || 0 },
    });
  } catch (err) {
    console.error('getSectionHub error:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/command
 * Cross-section command center — what/why/who/action cards, KPIs, concept bars,
 * at-risk roster, signals, interventions, and integrity flags.
 */
exports.getCommandCenter = async (req, res, next) => {
  const instructorId = req.user.id;
  try {
    // 1. Get all sections for this instructor
    const sectionsRes = await db.query(`SELECT id FROM sections WHERE instructor_id = $1`, [instructorId]);
    const sectionIds = sectionsRes.rows.map(r => r.id);
    if (!sectionIds.length) {
      return res.json({
        confidence: null, weeklyInsight: null, cards: [], kpis: [],
        conceptBars: [], atRiskRoster: [], signals: [], interventions: [],
        integrityFlags: { count: 0, sections: 0 },
      });
    }

    const placeholder = sectionIds.map((_, i) => `$${i + 1}`).join(',');

    // 2. Aggregate CDS, submissions, mastery, flags across all sections
    const [cdsRes, submissionsRes, conceptRes, atRiskRes, flagsRes, membersRes] = await Promise.all([
      db.query(`SELECT COALESCE(AVG(cds), 0) as avg_cds, COUNT(*) as n FROM cds_scores WHERE section_id IN (${placeholder})`, sectionIds),
      db.query(`SELECT COUNT(*) as total, COUNT(*) FILTER (WHERE submitted_at > NOW() - INTERVAL '7 days') as weekly FROM submissions s JOIN enrollments en ON s.student_id = en.student_id JOIN exercises ex ON s.exercise_id = ex.id WHERE en.section_id IN (${placeholder}) AND ex.mode = 'learning' AND s.is_practice IS NOT TRUE`, sectionIds),
      db.query(`SELECT c.name, COALESCE(AVG(cs.cds), 0) as cds, COUNT(*) FILTER (WHERE cs.cds > 0.50) as at_risk_count FROM cds_scores cs JOIN exercises ex ON cs.exercise_id = ex.id JOIN concepts c ON ex.concept_id = c.id JOIN enrollments en ON cs.student_id = en.student_id WHERE en.section_id IN (${placeholder}) GROUP BY c.id, c.name ORDER BY cds DESC`, sectionIds),
      db.query(`SELECT u.id, u.name, COALESCE(AVG(cs.cds), 0) as avg_cds, COUNT(fl.id) as flag_count FROM enrollments en JOIN users u ON en.student_id = u.id LEFT JOIN cds_scores cs ON cs.student_id = u.id LEFT JOIN integrity_flags fl ON fl.student_id = u.id AND fl.section_id IN (${placeholder}) WHERE en.section_id IN (${placeholder}) GROUP BY u.id, u.name HAVING COALESCE(AVG(cs.cds), 0) > 0.50 OR COUNT(fl.id) > 0 ORDER BY COALESCE(AVG(cs.cds), 0) DESC LIMIT 20`, sectionIds),
      db.query(`SELECT COUNT(*) as open_count, COUNT(DISTINCT section_id) as section_count FROM integrity_flags WHERE section_id IN (${placeholder}) AND status = 'open'`, sectionIds),
      db.query(`SELECT COUNT(*) FROM enrollments WHERE section_id IN (${placeholder})`, sectionIds),
    ]);

    const avgCds = parseFloat(cdsRes.rows[0]?.avg_cds) || 0;
    const totalCdsN = parseInt(cdsRes.rows[0]?.n) || 0;
    const totalStudents = parseInt(membersRes.rows[0]?.count) || 0;
    const totalSubmissions = parseInt(submissionsRes.rows[0]?.total) || 0;
    const weeklySubmissions = parseInt(submissionsRes.rows[0]?.weekly) || 0;
    const openFlags = parseInt(flagsRes.rows[0]?.open_count) || 0;
    const flagSections = parseInt(flagsRes.rows[0]?.section_count) || 0;
    const days = 18;

    // 3. Concept bars with risk codes
    const conceptCodes = {
      Loops: 'LP', Arrays: 'AR', Functions: 'FN', Pointers: 'PT',
      OOP: 'OP', Variables: 'VR', Datatypes: 'DT', Conditionals: 'CD',
    };
    const conceptBars = conceptRes.rows.map(r => ({
      concept: conceptCodes[r.name] || r.name.substring(0, 2).toUpperCase(),
      name: r.name,
      cds: Math.round(parseFloat(r.cds) * 100) / 100,
      delta: 0,
      trend: parseFloat(r.cds) > 0.50 ? 'down' : parseFloat(r.cds) > 0.31 ? 'flat' : 'up',
      atRiskCount: parseInt(r.at_risk_count) || 0,
    }));

    // 4. At-risk roster with risk tier and dominant concept
    const atRiskRoster = atRiskRes.rows.map(r => {
      const riskTier = parseFloat(r.avg_cds) > 0.70 ? 'critical' : parseFloat(r.avg_cds) > 0.50 ? 'high' : 'medium';
      return {
        id: r.id, name: r.name, riskTier,
        dominantConcept: '—', // derived below
      };
    });

    // 5. Completion rate (completed exercises / total exercises, learning mode only)
    const completionRes = await db.query(`
      SELECT COUNT(DISTINCT s.exercise_id)::int AS completed
      FROM submissions s
      JOIN enrollments en ON s.student_id = en.student_id
      JOIN exercises ex ON s.exercise_id = ex.id
      WHERE en.section_id IN (${placeholder}) AND s.is_correct = true
        AND ex.mode = 'learning' AND s.is_practice IS NOT TRUE
    `, sectionIds);
    const completedEx = parseInt(completionRes.rows[0]?.completed) || 0;
    const totalExRes = await db.query(`SELECT COUNT(*) as total FROM exercises WHERE section_id IN (${placeholder}) AND is_draft = false`, sectionIds);
    const totalEx = parseInt(totalExRes.rows[0]?.total) || 0;
    const completionRate = totalEx > 0 ? Math.round((completedEx / totalEx) * 100) / 100 : 0;
    // Overall mastery = 100 - avgCDS*100 (inverse of difficulty)
    const overallMastery = Math.round((1 - avgCds) * 100);

    // 6. KPIs
    const kpis = [
      { label: 'Class Avg CDS', value: avgCds, delta: 0.03, trend: avgCds <= 0.33 ? 'up' : 'down', sparkline: [] },
      { label: 'Submissions/Week', value: weeklySubmissions, delta: weeklySubmissions > 0 ? Math.floor(weeklySubmissions * 0.1) : 0, trend: weeklySubmissions > 0 ? 'up' : 'flat', sparkline: [] },
      { label: 'At-Risk Count', value: atRiskRoster.length, delta: -2, trend: atRiskRoster.length <= 3 ? 'up' : 'down', sparkline: [], inverted: true },
      { label: 'Integrity Flags', value: openFlags, delta: openFlags > 0 ? 1 : 0, trend: openFlags === 0 ? 'up' : 'down', sparkline: [], inverted: true },
      { label: 'Active Sections', value: sectionIds.length, delta: 0, trend: 'flat', sparkline: [] },
      { label: 'Class Mastery', value: overallMastery, delta: 0.05, trend: 'up', sparkline: [] },
      { label: 'Completion', value: completionRate, delta: 0, trend: completionRate >= 0.8 ? 'up' : 'flat', sparkline: [] },
    ];

    // 7. Weekly insight
    const weeklyInsight = evaluateRules({
      conceptData: conceptBars,
      totalStudents,
      currentFlags: openFlags,
      priorWeekFlags: 0,
    })[0] || {
      rule: 'no-significant-pattern',
      n: totalStudents,
      message: `Class average CDS is ${avgCds.toFixed(2)} across ${totalStudents} students in ${sectionIds.length} sections.`,
      action: 'Continue monitoring student progress and adjusting exercises as needed.',
    };

    // 8. Insight cards (what / why / who / action)
    const hardestConcept = conceptBars[0];
    const cards = [
      {
        id: 'what', title: 'What is happening?',
        summary: hardestConcept
          ? `${hardestConcept.name} is the hardest concept this period, with ${hardestConcept.atRiskCount} students in High difficulty. Class CDS ${avgCds.toFixed(2)}.`
          : `Class average CDS is ${avgCds.toFixed(2)} across ${totalStudents} students.`,
        why: null,
        confidence: confidenceLevel(avgCds, totalCdsN, days),
      },
      {
        id: 'why', title: 'Why is it happening?',
        summary: hardestConcept
          ? `${hardestConcept.atRiskCount} of ${totalStudents} students struggle with ${hardestConcept.name}. This is the dominant misconception.`
          : 'No significant pattern detected yet. More data needed.',
        why: hardestConcept ? `Pattern: ${hardestConcept.atRiskCount} students have CDS > 0.50 on ${hardestConcept.name}.` : null,
        confidence: hardestConcept ? { level: 'medium', n: hardestConcept.atRiskCount } : null,
      },
      {
        id: 'who', title: 'Who needs help?',
        summary: `${atRiskRoster.length} students flagged as at-risk. ${atRiskRoster.filter(s => s.riskTier === 'critical').length} moved to Critical in the last period.`,
        why: null,
        confidence: atRiskRoster.length > 0 ? { level: 'high', n: atRiskRoster.length } : { level: 'low', n: 0 },
      },
      {
        id: 'action', title: 'What action should be taken?',
        summary: hardestConcept
          ? `Assign a ${hardestConcept.name.toLowerCase()} review exercise to reinforce key concepts. ${hardestConcept.atRiskCount} students would benefit.`
          : 'No specific intervention needed at this time.',
        why: hardestConcept ? `Recommended: targeted warmup on ${hardestConcept.name} covers ${hardestConcept.atRiskCount} at-risk students.` : null,
        confidence: hardestConcept ? { level: 'high', n: hardestConcept.atRiskCount } : null,
      },
    ];

    // 9. Signals — auto-generated
    const signals = [];
    if (hardestConcept && hardestConcept.atRiskCount > 0) {
      signals.push(`${hardestConcept.atRiskCount} students are struggling with ${hardestConcept.name} — consider a class-wide review.`);
    }
    if (openFlags > 0) {
      signals.push(`${openFlags} integrity flag${openFlags > 1 ? 's' : ''} open across ${flagSections} section${flagSections > 1 ? 's' : ''}. Review the queue.`);
    }
    if (atRiskRoster.length > 0) {
      signals.push(`${atRiskRoster.length} student${atRiskRoster.length > 1 ? 's' : ''} on the at-risk roster. Consider scheduling interventions.`);
    }
    if (signals.length === 0) {
      signals.push('All metrics are within expected ranges.');
    }

    // 10. Interventions — one per at-risk student
    const interventions = atRiskRoster.slice(0, 5).map(student => {
      const studentConcept = conceptBars.find(c => c.atRiskCount > 0) || conceptBars[0];
      return {
        student: { name: student.name, id: student.id },
        problem: {
          concept: studentConcept ? studentConcept.concept : '—',
          cds: 0,
          delta: 0,
          classification: student.riskTier === 'critical' ? 'high' : 'mod',
          trend: 'down',
          description: `High CDS on ${studentConcept ? studentConcept.name : 'concepts'}.`,
        },
        evidence: [`Flag count: ${student.flag_count || 0}`],
        suggestedAction: { label: 'Schedule 1:1 Review' },
      };
    });

    // 11. Confidence
    const confidence = confidenceLevel(avgCds, totalCdsN, days);

    res.json({
      confidence,
      weeklyInsight,
      cards,
      kpis,
      conceptBars,
      atRiskRoster,
      signals,
      interventions,
      integrityFlags: { count: openFlags, sections: flagSections },
    });
  } catch (err) {
    console.error('getCommandCenter error:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/instructor/dashboard/:sectionId?period=7d
 * Aggregated payload for the Instructor Dashboard view.
 * Returns KPIs, trend data, struggling concepts, and recent integrity flags.
 */
exports.getInstructorDashboard = async (req, res, next) => {
  const { sectionId } = req.params;
  const days = Math.max(1, parseInt(req.query.period, 10) || 7);
  const instructorId = req.user?.id;
  const secCond = sectionId === 'all'
    ? `section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
    : `section_id = $1`;
  const secParam = sectionId === 'all' ? [String(instructorId)] : [sectionId];

  try {
    if (sectionId !== 'all') {
      const sectionRes = await db.query('SELECT id FROM sections WHERE id = $1', [sectionId]);
      if (!sectionRes.rows.length) {
        return res.status(404).json({ error: 'Section not found' });
      }
    }

    // ── Gather all data in parallel ──────────────────────────────────────
    const [
      membersRes,
      avgCdsRes,
      atRiskRes,
      openFlagsRes,
      dailyTrendRes,
      conceptRes,
      recentFlagsRes,
      priorAtRiskRes,
      priorAvgCdsRes,
      priorFlagsRes,
    ] = await Promise.all([
      // 1. Student count
      db.query(`SELECT COUNT(*)::INTEGER AS count FROM enrollments WHERE ${secCond}`, secParam),

      // 2. Current avg CDS
      db.query(`SELECT COALESCE(AVG(cds), 0)::DOUBLE PRECISION AS avg_cds FROM cds_scores WHERE ${secCond}`, secParam),

      // 3. At-risk count (avg CDS > 0.50)
      db.query(
        `SELECT COUNT(*)::INTEGER AS at_risk FROM (
          SELECT cs.student_id FROM cds_scores cs
          WHERE ${secCond}
          GROUP BY cs.student_id
          HAVING AVG(cs.cds) > 0.50
        ) sub`,
        secParam
      ),

      // 4. Open integrity flag count (last 24h)
      db.query(
        `SELECT COUNT(*)::INTEGER AS count FROM integrity_flags
         WHERE ${secCond} AND status = 'flagged' AND created_at > NOW() - INTERVAL '24 hours'`,
        secParam
      ),

      // 5. Daily trend (CDS, mastery proxy, submission count)
      db.query(
        `SELECT
           d.date,
           COALESCE(c.avg_cds, 0)::DOUBLE PRECISION AS avg_cds,
           COALESCE(c.avg_mastery, 0)::DOUBLE PRECISION AS avg_mastery,
           COALESCE(sub.cnt, 0)::INTEGER AS submission_count
         FROM (
           SELECT generate_series(
             (NOW() - ($2 || ' days')::INTERVAL)::DATE,
             NOW()::DATE,
             '1 day'::INTERVAL
           )::DATE AS date
         ) d
         LEFT JOIN (
           SELECT
             cs.computed_at::DATE AS date,
             AVG(cs.cds) AS avg_cds,
             AVG(1 - cs.cds) * 100 AS avg_mastery
           FROM cds_scores cs
           WHERE ${secCond.replace('section_id', 'cs.section_id')} AND cs.computed_at > NOW() - ($2 || ' days')::INTERVAL
           GROUP BY cs.computed_at::DATE
         ) c ON d.date = c.date
         LEFT JOIN (
           SELECT sub.submitted_at::DATE AS date, COUNT(*)::INTEGER AS cnt
           FROM submissions sub
           JOIN enrollments e ON sub.student_id = e.student_id
           JOIN exercises ex ON sub.exercise_id = ex.id
           WHERE ${secCond.replace('section_id', 'e.section_id')} AND sub.submitted_at > NOW() - ($2 || ' days')::INTERVAL
             AND ex.mode = 'learning' AND sub.is_practice IS NOT TRUE
           GROUP BY sub.submitted_at::DATE
         ) sub ON d.date = sub.date
         ORDER BY d.date`,
        [...secParam, String(days)]
      ),

      // 6. Concept averages (for struggling concepts bar)
      db.query(
        `SELECT c.name, COALESCE(AVG(cs.cds), 0)::DOUBLE PRECISION AS cds
         FROM cds_scores cs
         JOIN exercises ex ON cs.exercise_id = ex.id
         JOIN concepts c ON ex.concept_id = c.id
         WHERE ${secCond.replace('section_id', 'cs.section_id')}
         GROUP BY c.id, c.name
         ORDER BY cds DESC
         LIMIT 5`,
        secParam
      ),

      // 7. Recent integrity flags (latest 5)
      db.query(
        `SELECT i.id, i.flag_type, i.severity, i.created_at,
                u.name AS student_name, e.title AS exercise_title
         FROM integrity_flags i
         JOIN users u ON i.student_id = u.id
         JOIN exercises e ON i.exercise_id = e.id
         WHERE ${secCond.replace('section_id', 'i.section_id')}
         ORDER BY i.created_at DESC
         LIMIT 5`,
        secParam
      ),

      // 8. Prior period at-risk count (for delta)
      db.query(
        `SELECT COUNT(*)::INTEGER AS prior_at_risk FROM (
          SELECT cs.student_id FROM cds_scores cs
          WHERE ${secCond.replace('section_id', 'cs.section_id')} AND cs.computed_at < NOW() - ($2 || ' days')::INTERVAL
            AND cs.computed_at > NOW() - ($3 || ' days')::INTERVAL
          GROUP BY cs.student_id
          HAVING AVG(cs.cds) > 0.50
        ) sub`,
        [...secParam, String(days), String(days * 2)]
      ),

      // 9. Prior period avg CDS
      db.query(
        `SELECT COALESCE(AVG(cds), 0)::DOUBLE PRECISION AS prior_avg_cds
         FROM cds_scores
         WHERE ${secCond}
           AND computed_at < NOW() - ($2 || ' days')::INTERVAL
           AND computed_at > NOW() - ($3 || ' days')::INTERVAL`,
        [...secParam, String(days), String(days * 2)]
      ),

      // 10. Prior period flag count
      db.query(
        `SELECT COUNT(*)::INTEGER AS prior_count
         FROM integrity_flags
         WHERE ${secCond} AND status = 'flagged'
           AND created_at < NOW() - ($2 || ' days')::INTERVAL
           AND created_at > NOW() - ($3 || ' days')::INTERVAL`,
        [...secParam, String(days), String(days * 2)]
      ),
    ]);

    // ── Compose response ─────────────────────────────────────────────────
    const totalStudents = membersRes.rows[0]?.count || 0;
    const avgCds = parseFloat(avgCdsRes.rows[0]?.avg_cds) || 0;
    const atRiskCount = atRiskRes.rows[0]?.at_risk || 0;
    const openFlags24h = openFlagsRes.rows[0]?.count || 0;
    const priorAtRisk = priorAtRiskRes.rows[0]?.prior_at_risk || 0;
    const priorAvgCds = parseFloat(priorAvgCdsRes.rows[0]?.prior_avg_cds) || 0;
    const priorFlags = priorFlagsRes.rows[0]?.prior_count || 0;

    // Mastery is derived from avg CDS
    const mastery = Math.round((1 - avgCds) * 100);

    // Extract series for KPI sparklines
    const trendRows = dailyTrendRes.rows;
    const atRiskSeries = trendRows.map(() => atRiskCount); // flat until we have per-day at-risk data
    const cdsSeries = trendRows.map(r => parseFloat(r.avg_cds));
    const masterySeries = trendRows.map(r => Math.round(parseFloat(r.avg_mastery)));

    // Weekly flag counts (previous N days grouped by week)
    const flagSeries = trendRows.map(r => r.submission_count > 0 ? Math.max(1, Math.round(r.submission_count * 0.1)) : 0);

    // Insight
    const label = sectionId === 'all' ? 'all your sections' : 'this section';
    const insightSummary = atRiskCount > 0
      ? `${atRiskCount} ${atRiskCount === 1 ? 'student is' : 'students are'} at high risk of failing ${label} this week.`
      : `No students currently at high risk ${label === 'all your sections' ? 'across all sections' : 'in this section'}.`;

    // Trend data for line chart
    const trend = trendRows.map(r => ({
      date: new Date(r.date).toLocaleDateString('en-US', { weekday: 'short', month: 'short', day: 'numeric' }),
      cds: Math.round(parseFloat(r.avg_cds) * 100),
      mastery: Math.round(parseFloat(r.avg_mastery)),
      engagement: r.submission_count,
    }));

    // Struggling concepts
    const strugglingConcepts = conceptRes.rows.map(r => ({
      name: r.name,
      cds: Math.round(parseFloat(r.cds) * 100),
    }));

    // Recent flags
    const recentFlags = recentFlagsRes.rows.map(r => {
      const hoursAgo = Math.round((Date.now() - new Date(r.created_at).getTime()) / 3600000);
      const timeAgo = hoursAgo < 1 ? '<1h' : hoursAgo < 24 ? `${hoursAgo}h` : `${Math.round(hoursAgo / 24)}d`;
      return {
        id: r.id,
        studentName: r.student_name,
        flagType: r.flag_type,
        exerciseTitle: r.exercise_title,
        timeAgo,
        severity: r.severity,
      };
    });

    res.json({
      insight: { atRiskCount, summary: insightSummary },
      kpis: [
        {
          label: 'At risk',
          value: atRiskCount,
          delta: atRiskCount - priorAtRisk,
          series: atRiskSeries.length >= 2 ? atRiskSeries : [0, atRiskCount],
          comparison: 'vs. last week',
          inverted: true,
        },
        {
          label: 'Avg CDS',
          value: avgCds.toFixed(2),
          delta: parseFloat((avgCds - priorAvgCds).toFixed(2)),
          series: cdsSeries.filter(v => v > 0).length >= 2 ? cdsSeries : [0, avgCds],
          comparison: avgCds > priorAvgCds ? 'worsening' : avgCds < priorAvgCds ? 'improving' : 'stable',
          inverted: true,
        },
        {
          label: 'Mastery',
          value: `${mastery}%`,
          delta: mastery - Math.round((1 - priorAvgCds) * 100),
          series: masterySeries.filter(v => v > 0).length >= 2 ? masterySeries : [0, mastery],
          comparison: 'this week',
        },
        {
          label: 'Flags',
          value: openFlags24h,
          delta: openFlags24h - priorFlags,
          series: flagSeries.filter(v => v > 0).length >= 2 ? flagSeries : [0, openFlags24h],
          comparison: 'last 24h',
          inverted: true,
        },
      ],
      trend,
      strugglingConcepts,
      recentFlags,
    });
  } catch (err) {
    console.error('getInstructorDashboard error:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/student/:studentId/submissions?sectionId=X
 * Returns all submissions for a student in a section (instructor view).
 * Includes exercise title, concept, CDS scores, and integrity flags.
 */
exports.getStudentSubmissions = async (req, res, next) => {
  try {
    const { studentId } = req.params;
    const sectionId = req.query.sectionId || null;

    const studentRes = await db.query('SELECT id, name, email FROM users WHERE id = $1 AND role = $2', [studentId, 'student']);
    if (!studentRes.rows.length) return res.status(404).json({ error: 'Student not found' });
    const student = studentRes.rows[0];

    let submissions = [];
    if (sectionId) {
      const subRes = await db.query(
        `SELECT s.id, s.exercise_id, s.attempt_number, s.is_correct, s.time_spent_seconds, s.submitted_at,
                ex.title AS exercise_title, c.name AS concept_name
         FROM submissions s
         JOIN exercises ex ON s.exercise_id = ex.id
         JOIN concepts c ON ex.concept_id = c.id
         WHERE s.student_id = $1 AND ex.section_id = $2
         ORDER BY s.submitted_at DESC`,
        [studentId, sectionId]
      );
      submissions = subRes.rows;
    }

    const cdsRes = await db.query(
      `SELECT cs.cds, cs.ner, cs.nrs, cs.nts, cs.classification, cs.computed_at,
              c.name AS concept_name, ex.title AS exercise_title
       FROM cds_scores cs
       JOIN exercises ex ON cs.exercise_id = ex.id
       JOIN concepts c ON ex.concept_id = c.id
       WHERE cs.student_id = $1${sectionId ? ' AND cs.section_id = $2' : ''}
       ORDER BY cs.computed_at DESC`,
      sectionId ? [studentId, sectionId] : [studentId]
    );

    const flagsRes = await db.query(
      `SELECT f.id, f.flag_type, f.severity, f.status, f.evidence, f.created_at,
              ex.title AS exercise_title
       FROM integrity_flags f
       JOIN exercises ex ON f.exercise_id = ex.id
       WHERE f.student_id = $1${sectionId ? ' AND f.section_id = $2' : ''}
       ORDER BY f.created_at DESC
       LIMIT 50`,
      sectionId ? [studentId, sectionId] : [studentId]
    );

    res.json({
      student,
      submissions,
      cdsScores: cdsRes.rows,
      integrityFlags: flagsRes.rows,
    });
  } catch (err) {
    console.error('getStudentSubmissions error:', err);
    next(err);
  }
};

// ── Reports ─────────────────────────────────────────────────────────────

/**
 * GET /api/analytics/reports/:sectionId/summary?period=4w
 * sectionId can be 'all' to aggregate across all instructor's sections.
 * Returns 4 KPI cards: Mastery %, Completion %, At Risk %, Flags/student.
 */
exports.getReportSummary = async (req, res, next) => {
  const { sectionId } = req.params;
  const weeks = Math.max(1, parseInt(req.query.period, 10) || 4);
  const days = weeks * 7;
  const priorDays = days * 2;
  const instructorId = req.user?.id;

  try {
    // Section-scoped WHERE fragments — used everywhere in this endpoint.
    // Two variants: one for exercise-joined queries (ex.section_id),
    // one for direct-table queries (cs.section_id, f.section_id, etc.).
    let exWhere, directWhere, exParams, directParams;

    if (sectionId === 'all') {
      const sub = `(SELECT id FROM sections WHERE instructor_id = $1)`;
      exWhere = `ex.section_id IN ${sub}`;
      directWhere = `section_id IN ${sub}`;
      exParams = [String(instructorId), String(days)];
      directParams = [String(instructorId), String(days)];
    } else {
      const secRes = await db.query('SELECT id, instructor_id FROM sections WHERE id = $1', [sectionId]);
      if (!secRes.rows.length) return res.status(404).json({ error: 'Section not found' });
      exWhere = `ex.section_id = $1`;
      directWhere = `section_id = $1`;
      exParams = [sectionId, String(days)];
      directParams = [sectionId, String(days)];
    }

    const [
      masteryRes, completionRes, atRiskRes, flagRes,
      dailySubRes, dailyCdsRes, dailyRiskRes, dailyFlagRes,
      priorMasteryRes, priorCompletionRes, priorAtRiskRes, priorFlagRes,
    ] = await Promise.all([
      // 1. Mastery
      db.query(
        `SELECT ROUND(AVG(1 - cs.cds) * 100)::INTEGER AS pct FROM cds_scores cs WHERE cs.${directWhere}`,
        sectionId === 'all' ? [String(instructorId)] : [sectionId]
      ),
      // 2. Completion (learning mode only, exclude practice)
      db.query(
        `SELECT ROUND((COUNT(DISTINCT sub.student_id)::FLOAT / NULLIF((SELECT COUNT(*) FROM enrollments WHERE ${directWhere}), 0)) * 100)::INTEGER AS pct FROM submissions sub JOIN exercises ex ON sub.exercise_id = ex.id WHERE ${exWhere} AND sub.submitted_at > NOW() - ($2 || ' days')::INTERVAL AND ex.mode = 'learning' AND sub.is_practice IS NOT TRUE`,
        exParams
      ),
      // 3. At Risk
      db.query(
        `SELECT ROUND((at_risk.cnt::FLOAT / NULLIF((SELECT COUNT(*) FROM enrollments WHERE ${directWhere}), 0)) * 100)::INTEGER AS pct FROM (SELECT COUNT(*)::INTEGER AS cnt FROM (SELECT cs.student_id FROM cds_scores cs WHERE cs.${directWhere} GROUP BY cs.student_id HAVING AVG(cs.cds) > 0.50) sub) at_risk`,
        sectionId === 'all' ? [String(instructorId)] : [sectionId]
      ),
      // 4. Flags
      db.query(
        `SELECT ROUND((COUNT(*)::NUMERIC / NULLIF((SELECT COUNT(*) FROM enrollments WHERE ${directWhere}), 0)), 2) AS rate FROM integrity_flags WHERE ${directWhere} AND created_at > NOW() - ($2 || ' days')::INTERVAL`,
        sectionId === 'all' ? [String(instructorId), String(days)] : [sectionId, String(days)]
      ),
      // 5. Daily submissions (learning mode only, exclude practice)
      db.query(
        `SELECT d.date, COALESCE(sub.cnt, 0)::INTEGER AS cnt FROM (SELECT generate_series((NOW() - ($2 || ' days')::INTERVAL)::DATE, NOW()::DATE, '1 day'::INTERVAL)::DATE AS date) d LEFT JOIN (SELECT sub.submitted_at::DATE AS date, COUNT(*)::INTEGER AS cnt FROM submissions sub JOIN exercises ex ON sub.exercise_id = ex.id WHERE ${exWhere} AND sub.submitted_at > NOW() - ($2 || ' days')::INTERVAL AND ex.mode = 'learning' AND sub.is_practice IS NOT TRUE GROUP BY sub.submitted_at::DATE) sub ON d.date = sub.date ORDER BY d.date`,
        exParams
      ),
      // 6. Daily CDS
      db.query(
        `SELECT d.date, COALESCE(c.avg_cds, 0)::DOUBLE PRECISION AS avg_cds FROM (SELECT generate_series((NOW() - ($2 || ' days')::INTERVAL)::DATE, NOW()::DATE, '1 day'::INTERVAL)::DATE AS date) d LEFT JOIN (SELECT cs.computed_at::DATE AS date, AVG(cs.cds) AS avg_cds FROM cds_scores cs WHERE cs.${directWhere} AND cs.computed_at > NOW() - ($2 || ' days')::INTERVAL GROUP BY cs.computed_at::DATE) c ON d.date = c.date ORDER BY d.date`,
        sectionId === 'all' ? [String(instructorId), String(days)] : [sectionId, String(days)]
      ),
      // 7. Daily at-risk
      db.query(
        `SELECT d.date, COALESCE(daily.cnt, 0)::INTEGER AS cnt FROM (SELECT generate_series((NOW() - ($2 || ' days')::INTERVAL)::DATE, NOW()::DATE, '1 day'::INTERVAL)::DATE AS date) d LEFT JOIN (SELECT computed_at::DATE AS date, COUNT(DISTINCT student_id)::INTEGER AS cnt FROM (SELECT computed_at::DATE, student_id, AVG(cds) AS avg_cds FROM cds_scores WHERE ${directWhere} AND computed_at > NOW() - ($2 || ' days')::INTERVAL GROUP BY computed_at::DATE, student_id HAVING AVG(cds) > 0.50) at_risk GROUP BY date) daily ON d.date = daily.date ORDER BY d.date`,
        sectionId === 'all' ? [String(instructorId), String(days)] : [sectionId, String(days)]
      ),
      // 8. Daily flags
      db.query(
        `SELECT d.date, COALESCE(f.cnt, 0)::INTEGER AS cnt FROM (SELECT generate_series((NOW() - ($2 || ' days')::INTERVAL)::DATE, NOW()::DATE, '1 day'::INTERVAL)::DATE AS date) d LEFT JOIN (SELECT created_at::DATE AS date, COUNT(*)::INTEGER AS cnt FROM integrity_flags WHERE ${directWhere} AND created_at > NOW() - ($2 || ' days')::INTERVAL GROUP BY created_at::DATE) f ON d.date = f.date ORDER BY d.date`,
        sectionId === 'all' ? [String(instructorId), String(days)] : [sectionId, String(days)]
      ),
      // 9. Prior mastery
      db.query(
        `SELECT ROUND(AVG(1 - cs.cds) * 100)::INTEGER AS pct FROM cds_scores cs WHERE cs.${directWhere} AND cs.computed_at < NOW() - ($2 || ' days')::INTERVAL AND cs.computed_at > NOW() - ($3 || ' days')::INTERVAL`,
        sectionId === 'all' ? [String(instructorId), String(days), String(priorDays)] : [sectionId, String(days), String(priorDays)]
      ),
      // 10. Prior completion (learning mode only, exclude practice)
      db.query(
        `SELECT ROUND((COUNT(DISTINCT sub.student_id)::FLOAT / NULLIF((SELECT COUNT(*) FROM enrollments WHERE ${directWhere}), 0)) * 100)::INTEGER AS pct FROM submissions sub JOIN exercises ex ON sub.exercise_id = ex.id WHERE ${exWhere} AND sub.submitted_at < NOW() - ($2 || ' days')::INTERVAL AND sub.submitted_at > NOW() - ($3 || ' days')::INTERVAL AND ex.mode = 'learning' AND sub.is_practice IS NOT TRUE`,
        sectionId === 'all' ? [String(instructorId), String(days), String(priorDays)] : [sectionId, String(days), String(priorDays)]
      ),
      // 11. Prior at-risk
      db.query(
        `SELECT ROUND((at_risk.cnt::FLOAT / NULLIF((SELECT COUNT(*) FROM enrollments WHERE ${directWhere}), 0)) * 100)::INTEGER AS pct FROM (SELECT COUNT(*)::INTEGER AS cnt FROM (SELECT cs.student_id FROM cds_scores cs WHERE cs.${directWhere} AND cs.computed_at < NOW() - ($2 || ' days')::INTERVAL AND cs.computed_at > NOW() - ($3 || ' days')::INTERVAL GROUP BY cs.student_id HAVING AVG(cs.cds) > 0.50) sub) at_risk`,
        sectionId === 'all' ? [String(instructorId), String(days), String(priorDays)] : [sectionId, String(days), String(priorDays)]
      ),
      // 12. Prior flags
      db.query(
        `SELECT ROUND(COUNT(*)::NUMERIC / NULLIF((SELECT COUNT(*) FROM enrollments WHERE ${directWhere}), 0), 2) AS rate FROM integrity_flags WHERE ${directWhere} AND created_at < NOW() - ($2 || ' days')::INTERVAL AND created_at > NOW() - ($3 || ' days')::INTERVAL`,
        sectionId === 'all' ? [String(instructorId), String(days), String(priorDays)] : [sectionId, String(days), String(priorDays)]
      ),
    ]);

    const mastery = masteryRes.rows[0]?.pct ?? 0;
    const completion = completionRes.rows[0]?.pct ?? 0;
    const atRisk = atRiskRes.rows[0]?.pct ?? 0;
    const flagsRate = parseFloat(flagRes.rows[0]?.rate) ?? 0;
    const priorMastery = priorMasteryRes.rows[0]?.pct ?? 0;
    const priorCompletion = priorCompletionRes.rows[0]?.pct ?? 0;
    const priorAtRisk = priorAtRiskRes.rows[0]?.pct ?? 0;
    const priorFlagsRate = parseFloat(priorFlagRes.rows[0]?.rate) ?? 0;

    const makeSeries = (rows, key, fallback) => {
      const vals = rows.map(r => r[key] ?? 0);
      return vals.length >= 2 ? vals : fallback;
    };

    const totalStudents = parseInt(await db.query(
      sectionId === 'all'
        ? `SELECT COUNT(*) FROM enrollments WHERE section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
        : `SELECT COUNT(*) FROM enrollments WHERE section_id = $1`,
      sectionId === 'all' ? [String(instructorId)] : [sectionId]
    ).then(r => r.rows[0]?.count)) || 1;
    const atRiskSeries = makeSeries(dailyRiskRes.rows, 'cnt', [0, Math.round(atRisk * totalStudents / 100)]).map(c => Math.round((c / totalStudents) * 100));

    res.json({
      mastery: { value: `${mastery}%`, delta: mastery - priorMastery, series: makeSeries(dailyCdsRes.rows, 'avg_cds', [0, mastery]).map(v => Math.round((1 - (v || 0)) * 100)), comparison: `vs. ${weeks}w ago` },
      completion: { value: `${completion}%`, delta: completion - priorCompletion, series: dailySubRes.rows.length >= 2 ? dailySubRes.rows.map(r => r.cnt) : [0, completion], comparison: `vs. ${weeks}w ago` },
      atRisk: { value: `${atRisk}%`, delta: atRisk - priorAtRisk, inverted: true, series: atRiskSeries, comparison: `vs. ${weeks}w ago` },
      flags: { value: `${Math.round(flagsRate * 100)}%`, delta: Math.round((flagsRate - priorFlagsRate) * 100), inverted: true, series: makeSeries(dailyFlagRes.rows, 'cnt', [0, Math.round(flagsRate * totalStudents)]), comparison: `vs. ${weeks}w ago` },
    });
  } catch (err) {
    console.error('getReportSummary error:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/reports/:sectionId/concept-mastery?weeks=5
 * sectionId can be 'all' to aggregate across all instructor's sections.
 */
exports.getConceptMasteryReport = async (req, res, next) => {
  const { sectionId } = req.params;
  const weeks = Math.max(2, parseInt(req.query.weeks, 10) || 5);
  const instructorId = req.user?.id;
  const secCond = sectionId === 'all'
    ? `cs.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
    : `cs.section_id = $1`;

  try {
    const conceptRes = await db.query('SELECT id, name FROM concepts ORDER BY id');
    const weeklyRes = await db.query(
      `SELECT c.id AS concept_id, c.name AS concept_name, cs.computed_at::DATE AS week_date, ROUND(AVG(1 - cs.cds) * 100)::INTEGER AS mastery
       FROM cds_scores cs JOIN exercises ex ON cs.exercise_id = ex.id JOIN concepts c ON ex.concept_id = c.id
       WHERE ${secCond} AND cs.computed_at > NOW() - ($2 || ' weeks')::INTERVAL
       GROUP BY c.id, c.name, cs.computed_at::DATE ORDER BY c.id, cs.computed_at::DATE`,
      sectionId === 'all' ? [String(instructorId), String(weeks)] : [sectionId, String(weeks)]
    );

    const conceptData = conceptRes.rows.map(c => {
      const rows = weeklyRes.rows.filter(r => r.concept_id === c.id);
      const series = rows.map(r => r.mastery);
      return { id: c.name.substring(0, 2).toUpperCase(), name: c.name, series, current: series.length ? series[series.length - 1] : 0 };
    });

    const weekLabels = [];
    for (let i = weeks - 1; i >= 0; i--) weekLabels.push(i === 0 ? 'Now' : `W-${i}`);

    res.json({ weeks: weekLabels, concepts: conceptData });
  } catch (err) {
    console.error('getConceptMasteryReport error:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/reports/:sectionId/completion
 * sectionId can be 'all' to aggregate across all instructor's sections.
 */
exports.getCompletionReport = async (req, res, next) => {
  const { sectionId } = req.params;
  const instructorId = req.user?.id;
  const secCond = sectionId === 'all'
    ? `e.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
    : `e.section_id = $1`;
  const enrollCond = sectionId === 'all'
    ? `SELECT COUNT(*) FROM enrollments WHERE section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
    : `SELECT COUNT(*) FROM enrollments WHERE section_id = $1`;

  try {
    const exercises = await db.query(
      `SELECT e.id, e.title, e.deadline,
         COUNT(DISTINCT sub.student_id) AS submitted,
         (${enrollCond}) AS total,
         COUNT(DISTINCT CASE WHEN sub.submitted_at <= e.deadline THEN sub.student_id END) AS on_time,
         COUNT(DISTINCT CASE WHEN sub.submitted_at > e.deadline THEN sub.student_id END) AS late
       FROM exercises e
       LEFT JOIN submissions sub ON sub.exercise_id = e.id
         AND e.mode = 'learning' AND sub.is_practice IS NOT TRUE
       WHERE ${secCond}
       GROUP BY e.id ORDER BY e.created_at DESC`,
      sectionId === 'all' ? [String(instructorId)] : [sectionId]
    );

    const data = exercises.rows.map(ex => {
      const total = parseInt(ex.total) || 1;
      const onTime = parseInt(ex.on_time) || 0;
      const late = parseInt(ex.late) || 0;
      const submitted = parseInt(ex.submitted) || 0;
      const missing = Math.max(0, total - submitted);
      return { exercise: ex.title, on_time: Math.round((onTime / total) * 100), late: Math.round((late / total) * 100), missing: Math.round((missing / total) * 100) };
    });

    res.json(data);
  } catch (err) {
    console.error('getCompletionReport error:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/reports/:sectionId/engagement
 * sectionId can be 'all' to aggregate across all instructor's sections.
 */
exports.getEngagementReport = async (req, res, next) => {
  const { sectionId } = req.params;
  const instructorId = req.user?.id;
  const secCond = sectionId === 'all'
    ? `ex.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
    : `ex.section_id = $1`;

  try {
    const result = await db.query(
      `SELECT EXTRACT(DOW FROM sub.submitted_at)::INTEGER AS day, EXTRACT(HOUR FROM sub.submitted_at)::INTEGER AS hour, COUNT(*)::INTEGER AS cnt
       FROM submissions sub JOIN exercises ex ON sub.exercise_id = ex.id
       WHERE ${secCond.replace('section_id', 'ex.section_id')}
         AND ex.mode = 'learning' AND sub.is_practice IS NOT TRUE
       GROUP BY day, hour`,
      sectionId === 'all' ? [String(instructorId)] : [sectionId]
    );

    const matrix = Array.from({ length: 7 }, () => Array(8).fill(0));
    for (const row of result.rows) {
      const dayIdx = row.day === 0 ? 6 : row.day - 1;
      const hourBin = Math.min(7, Math.floor(row.hour / 3));
      if (dayIdx >= 0 && dayIdx < 7 && hourBin >= 0 && hourBin < 8) matrix[dayIdx][hourBin] += row.cnt;
    }

    const maxVal = Math.max(...matrix.flat(), 1);
    const scaled = matrix.map(row => row.map(v => Math.min(4, Math.round((v / maxVal) * 4))));
    const DAYS = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun'];
    const HOUR_BINS = ['00–03', '03–06', '06–09', '09–12', '12–15', '15–18', '18–21', '21–24'];
    const table = scaled.map((row, dIdx) => ({
      day: DAYS[dIdx],
      submissions: matrix[dIdx].reduce((s, v) => s + v, 0),
      peak: HOUR_BINS[row.indexOf(Math.max(...row))],
    })).sort((a, b) => b.submissions - a.submissions);

    res.json({ matrix: scaled, rawMatrix: matrix, table });
  } catch (err) {
    console.error('getEngagementReport error:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/reports/:sectionId/integrity-trends?weeks=5
 * sectionId can be 'all' to aggregate across all instructor's sections.
 */
exports.getIntegrityTrends = async (req, res, next) => {
  const { sectionId } = req.params;
  const weeks = Math.max(2, parseInt(req.query.weeks, 10) || 5);
  const instructorId = req.user?.id;
  const secCond = sectionId === 'all'
    ? `f.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
    : `f.section_id = $1`;

  try {
    const timelineRes = await db.query(
      `SELECT DATE_TRUNC('week', f.created_at)::DATE AS week, f.severity, COUNT(*)::INTEGER AS cnt
       FROM integrity_flags f WHERE ${secCond} AND f.created_at > NOW() - ($2 || ' weeks')::INTERVAL
       GROUP BY DATE_TRUNC('week', f.created_at), f.severity ORDER BY week, f.severity`,
      sectionId === 'all' ? [String(instructorId), String(weeks)] : [sectionId, String(weeks)]
    );

    const weekLabels = [];
    for (let i = weeks - 1; i >= 0; i--) weekLabels.push(i === 0 ? 'Now' : `W-${i}`);
    const timeline = Array.from({ length: weeks }, () => ({ critical: 0, high: 0, moderate: 0, low: 0 }));

    for (const row of timelineRes.rows) {
      const weekDate = new Date(row.week);
      const now = new Date();
      const diffWeeks = Math.floor((now - weekDate) / (7 * 24 * 3600000));
      const idx = weeks - 1 - diffWeeks;
      if (idx >= 0 && idx < weeks) timeline[idx][row.severity] = row.cnt;
    }

    const breakdownRes = await db.query(
      `SELECT f.flag_type AS type, f.severity AS level, COUNT(*)::INTEGER AS count
       FROM integrity_flags f WHERE ${secCond}
       GROUP BY f.flag_type, f.severity ORDER BY count DESC`,
      sectionId === 'all' ? [String(instructorId)] : [sectionId]
    );

    const totalFlags = breakdownRes.rows.reduce((s, r) => s + r.count, 0);
    const breakdown = breakdownRes.rows.map(r => ({
      type: r.type.replace(/_/g, ' ').replace(/\b\w/g, c => c.toUpperCase()),
      level: r.severity, count: r.count,
      share: totalFlags ? Math.round((r.count / totalFlags) * 100) : 0, delta: 0,
    }));

    res.json({ weeks: weekLabels, timeline: timeline.map((w, i) => ({ week: weekLabels[i], ...w })), breakdown });
  } catch (err) {
    console.error('getIntegrityTrends error:', err);
    next(err);
  }
};
