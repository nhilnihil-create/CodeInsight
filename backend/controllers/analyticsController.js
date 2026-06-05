const db        = require('../config/db');
const cdsEngine = require('../services/cdsEngine');
const classMisconceptionReport = require('../services/classMisconceptionReport');
const longitudinalReportEngine = require('../services/longitudinalReportEngine');
const { wilsonScore, confidenceLevel } = require('../lib/wilsonScore');
const { evaluateRules } = require('../lib/insightTemplates');

const CONCEPT_ORDER = ['Datatypes','Variables','Conditionals','Loops','Functions','Arrays','OOP'];

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
       (SELECT COUNT(CASE WHEN cs.cds <= 0.33 THEN 1 END)::INTEGER FROM cds_scores cs
        WHERE cs.exercise_id = $1 AND cs.section_id = $2) AS low_count,
       (SELECT COUNT(CASE WHEN cs.cds > 0.33 AND cs.cds <= 0.66 THEN 1 END)::INTEGER FROM cds_scores cs
        WHERE cs.exercise_id = $1 AND cs.section_id = $2) AS moderate_count,
       (SELECT COUNT(CASE WHEN cs.cds > 0.66 THEN 1 END)::INTEGER FROM cds_scores cs
        WHERE cs.exercise_id = $1 AND cs.section_id = $2) AS high_count`,
    [exerciseId, sectionId]
  );
  return statsRes.rows[0] || {};
}

exports.heatmap = async (req, res) => {
  const { sectionId } = req.params;
  try {
    // First, recalculate CDS for all exercises in this section to ensure stable metrics
    const exercises = await db.query(
      `SELECT DISTINCT ex.id FROM exercises ex
       WHERE ex.section_id=$1`,
      [sectionId]
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
       WHERE e.section_id=$1 ORDER BY u.name`,
      [sectionId]
    );

    const scores = await db.query(
      `SELECT cs.student_id, cs.cds, cs.classification, cs.ner, cs.nrs, cs.nts,
              c.name AS concept_name, ex.title AS exercise_title
       FROM cds_scores cs
       JOIN exercises ex ON ex.id=cs.exercise_id
       JOIN concepts c ON c.id=ex.concept_id
       WHERE cs.section_id=$1`,
      [sectionId]
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
        const cl = avg<=0.33?'Low':avg<=0.66?'Moderate':'High';
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
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.getAlerts = async (req, res) => {
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
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.reviewAlert = async (req, res) => {
  try {
    await db.query(
      'UPDATE alerts SET is_reviewed=true WHERE id=$1', [req.params.alertId]
    );
    res.json({ message: 'Alert marked as reviewed' });
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.liveRanking = async (req, res) => {
  try {
    const ranking = await cdsEngine.getLivePeerRanking(req.params.exerciseId, db);
    res.json(ranking);
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.liveCDS = async (req, res) => {
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
    const classAvgClassification =
      classAvgFromSubmitters <= 0.33 ? 'Low' : classAvgFromSubmitters <= 0.66 ? 'Moderate' : 'High';

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
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.studentProfile = async (req, res) => {
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
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.myScores = async (req, res) => {
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
  } catch (err) { res.status(500).json({ message: err.message }); }
};

exports.recentActivity = async (req, res) => {
  try {
    const { sectionId } = req.params;
    const r = await db.query(
      `SELECT
        al.id, al.student_id, al.cds_score as cds, al.exercise_id, al.created_at,
        u.name AS student_name, ex.title AS exercise_title, ex.concept_id,
        c.name AS concept_name,
        CASE
          WHEN al.cds_score > 0.66 THEN 'High'
          WHEN al.cds_score > 0.33 THEN 'Moderate'
          ELSE 'Low'
        END AS difficulty
       FROM alerts al
       JOIN users u ON u.id=al.student_id
       JOIN exercises ex ON ex.id=al.exercise_id
       JOIN concepts c ON c.id=ex.concept_id
       WHERE al.section_id=$1
       ORDER BY al.created_at DESC
       LIMIT 5`,
      [sectionId]
    );
    res.json(r.rows);
  } catch (err) { res.status(500).json({ message: err.message }); }
};

// New endpoint for class misconception report
exports.classMisconceptionReport = async (req, res) => {
  try {
    const { exerciseId } = req.params;
    const report = await classMisconceptionReport.generateClassMisconceptionReport(parseInt(exerciseId));
    res.json(report);
  } catch (err) {
    console.error('Error generating class misconception report:', err);
    res.status(500).json({ message: err.message });
  }
};

// New endpoint for longitudinal report (mastery velocity)
exports.longitudinalReport = async (req, res) => {
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
    res.status(500).json({ message: err.message });
  }
};

// ── NEW: Section-Scoped Analytics Controllers ────────────────────────────────

/**
 * GET /api/analytics/sections/:sectionId/micro-concept-alerts
 * Returns micro-concept alerts for all students in section
 */
exports.getMicroConceptAlerts = async (req, res) => {
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
    res.status(500).json({ message: err.message });
  }
};

/**
 * PUT /api/analytics/micro-concept-alerts/:alertId/mark-reviewed
 */
exports.markMicroConceptAlertReviewed = async (req, res) => {
  try {
    const { alertId } = req.params;
    const result = await db.query(
      `UPDATE alerts SET is_reviewed = true WHERE id = $1 RETURNING *`,
      [alertId]
    );
    res.json(result.rows[0]);
  } catch (err) {
    console.error('Error marking alert reviewed:', err);
    res.status(500).json({ message: err.message });
  }
};

/**
 * GET /api/analytics/sections/:sectionId/class-insights
 * Returns class misconception reports for all exercises in section
 */
exports.getClassInsights = async (req, res) => {
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
    res.status(500).json({ message: err.message });
  }
};

/**
 * GET /api/analytics/sections/:sectionId/class-insights/:exerciseId
 * Auto-triggers batch CDS (default), then returns misconception report + fresh stats.
 * Query: refresh=false to skip CDS recompute (report only).
 */
exports.getClassInsightsByExercise = async (req, res) => {
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
    res.status(500).json({ message: err.message });
  }
};

/**
 * GET /api/analytics/sections/:sectionId/longitudinal
 * Returns longitudinal progress for all students in section
 */
exports.getSectionLongitudinal = async (req, res) => {
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
    res.status(500).json({ message: err.message });
  }
};

/**
 * GET /api/analytics/sections/:sectionId/integrity-flags/:exerciseId
 * Per-exercise flag list (array). Section-wide paginated list: integrityController via routes/integrity.js
 */
exports.getIntegrityFlagsByExercise = async (req, res) => {
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
    res.status(500).json({ message: err.message });
  }
};

/**
 * GET /api/analytics/section/:id/hub — Aggregated Command Center payload (spec §12).
 */
exports.getSectionHub = async (req, res) => {
  const { id } = req.params;
  try {
    const section = await db.query('SELECT * FROM sections WHERE id = $1', [id]);
    if (section.rows.length === 0) {
      return res.status(404).json({ error: 'Section not found' });
    }

    const [cdsResult, submissionsResult, masteryResult, atRiskResult, flagsResult, membersResult] = await Promise.all([
      db.query(`SELECT COALESCE(AVG(cds), 0) as avg_cds, COUNT(*) as n FROM cds_scores WHERE section_id = $1`, [id]),
      db.query(`SELECT COUNT(*) as total, COUNT(*) FILTER (WHERE created_at > NOW() - INTERVAL '7 days') as weekly FROM submissions s JOIN enrollments m ON s.student_id = m.student_id WHERE m.section_id = $1`, [id]),
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
    res.status(500).json({ error: 'Failed to load section analytics' });
  }
};
