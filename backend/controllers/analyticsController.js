const db        = require('../config/db');
const cdsEngine = require('../services/cdsEngine');
const classMisconceptionReport = require('../services/classMisconceptionReport');
const longitudinalReportEngine = require('../services/longitudinalReportEngine');

const CONCEPT_ORDER = ['Datatypes','Variables','Conditionals','Loops','Functions','Arrays','OOP'];

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
    
    // Calculate class metrics
    const cdsValues = scores.rows.map(s => parseFloat(s.cds || 0));
    const classAvg = cdsValues.length > 0 ? cdsValues.reduce((a,b)=>a+b,0) / cdsValues.length : 0;
    const classMin = cdsValues.length > 0 ? Math.min(...cdsValues) : 0;
    const classMax = cdsValues.length > 0 ? Math.max(...cdsValues) : 0;
    
    // Classify class average
    const classAvgClassification = classAvg <= 0.33 ? 'Low' : classAvg <= 0.66 ? 'Moderate' : 'High';
    
    // Determine reliability
    const studentCount = scores.rows.length;
    const submissionCount = await db.query(
      'SELECT COUNT(*) as count FROM submissions WHERE exercise_id=$1',
      [exerciseId]
    );
    const isPreliminary = studentCount < 3;
    const reliability = isPreliminary ? 'Preliminary' : 'Accurate';
    
    res.json({
      exercise: { id: exercise.id, title: exercise.title, timeLimitMinutes: exercise.time_limit_minutes },
      studentCount,
      submissionCount: submissionCount.rows[0].count,
      preliminary: isPreliminary,
      reliability,
      classAverage: {
        ner: scores.rows.length > 0 ? (scores.rows.reduce((a,s)=>a + parseFloat(s.ner || 0), 0) / scores.rows.length) : 0,
        nrs: scores.rows.length > 0 ? (scores.rows.reduce((a,s)=>a + parseFloat(s.nrs || 0), 0) / scores.rows.length) : 0,
        nts: scores.rows.length > 0 ? (scores.rows.reduce((a,s)=>a + parseFloat(s.nts || 0), 0) / scores.rows.length) : 0,
        cds: classAvg,
        classification: classAvgClassification,
        min: classMin,
        max: classMax
      },
      rankings: scores.rows.map(s => ({
        studentId: s.student_id,
        name: s.name,
        totalAttempts: s.total_attempts,
        failedAttempts: s.failed_attempts,
        ner: parseFloat(s.ner || 0),
        nrs: parseFloat(s.nrs || 0),
        nts: parseFloat(s.nts || 0),
        cds: parseFloat(s.cds || 0),
        classification: s.classification
      }))
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
 * Returns class misconception report for specific exercise
 */
exports.getClassInsightsByExercise = async (req, res) => {
  try {
    const { sectionId, exerciseId } = req.params;

    // Verify exercise belongs to section
    const exerciseRes = await db.query(
      `SELECT id FROM exercises WHERE id = $1 AND section_id = $2`,
      [exerciseId, sectionId]
    );

    if (!exerciseRes.rows.length) {
      return res.status(404).json({ message: 'Exercise not found in section' });
    }

    const report = await classMisconceptionReport.generateClassMisconceptionReport(exerciseId);
    res.json(report);
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
 * GET /api/analytics/sections/:sectionId/integrity-flags
 * Returns all integrity flags for section grouped by exercise
 */
exports.getIntegrityFlags = async (req, res) => {
  try {
    const { sectionId } = req.params;
    const integrityFlagEngine = require('../services/integrityFlagEngine');

    const flags = await integrityFlagEngine.getFlagsForSection(sectionId);
    res.json(flags);
  } catch (err) {
    console.error('Error fetching integrity flags:', err);
    res.status(500).json({ message: err.message });
  }
};

/**
 * GET /api/analytics/sections/:sectionId/integrity-flags/:exerciseId
 * Returns integrity flags for specific exercise
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
 * PUT /api/analytics/integrity-flags/:flagId/mark-reviewed
 */
exports.markIntegrityFlagReviewed = async (req, res) => {
  try {
    const { flagId } = req.params;
    const { instructorNote } = req.body;
    const integrityFlagEngine = require('../services/integrityFlagEngine');

    const flag = await integrityFlagEngine.markFlagReviewed(flagId, instructorNote);
    res.json(flag);
  } catch (err) {
    console.error('Error marking flag reviewed:', err);
    res.status(500).json({ message: err.message });
  }
};
