const express = require('express');
const router  = express.Router();
const db = require('../config/db');
const { runAgainstTestCases } = require('../services/executor');
const cdsEngine = require('../services/cdsEngine');
const { verifyToken, requireRole } = require('../middleware/auth');
const { AppError, codes } = require('../lib/AppError');

// Get all exercises for enrolled sections
router.get('/exercises', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const r = await db.query(`
      SELECT
        ex.id, ex.title, ex.description, c.name AS concept_name,
        ex.time_limit_minutes, ex.deadline, ex.test_cases,
        CASE WHEN cs.cds IS NOT NULL THEN 'completed' ELSE 'pending' END AS status,
        cs.cds
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id
      LEFT JOIN cds_scores cs ON cs.exercise_id = ex.id AND cs.student_id = $1
      WHERE en.student_id = $1 AND ex.is_draft = false
      ORDER BY ex.created_at DESC
    `, [req.user.id]);
    res.json(r.rows);
  } catch (err) { next(err); }
});

// Get single exercise details
router.get('/exercises/:id', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const r = await db.query(`
      SELECT ex.*, c.name AS concept_name
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id
      WHERE ex.id = $1 AND en.student_id = $2
    `, [req.params.id, req.user.id]);

    if (!r.rows.length) throw new AppError('Exercise not found', 404, codes.NOT_FOUND);

    const ex = r.rows[0];
    if (ex.test_cases) {
      let testCases = typeof ex.test_cases === 'string' ? JSON.parse(ex.test_cases) : ex.test_cases;
      ex.test_cases = testCases.filter(tc => !tc.hidden);
    }

    const completedRes = await db.query(`
      SELECT id, submitted_at FROM submissions
      WHERE exercise_id = $1 AND student_id = $2 AND is_correct = true
      LIMIT 1
    `, [req.params.id, req.user.id]);
    ex.isCompleted = completedRes.rows.length > 0;
    ex.completedAt = ex.isCompleted ? completedRes.rows[0].submitted_at : null;
    res.json(ex);
  } catch (err) { next(err); }
});

// Run code (visible tests only)
router.post('/exercises/:id/run', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const { code } = req.body;
    if (!code) throw new AppError('Code required', 400, codes.VALIDATION);

    const exRes = await db.query('SELECT * FROM exercises WHERE id = $1', [req.params.id]);
    if (!exRes.rows.length) throw new AppError('Exercise not found', 404, codes.NOT_FOUND);

    const exercise = exRes.rows[0];
    const testCases = typeof exercise.test_cases === 'string'
      ? JSON.parse(exercise.test_cases) : (exercise.test_cases || []);
    const visibleTC = testCases.filter(tc => !tc.hidden);

    if (!visibleTC.length) {
      return res.json({
        passed: true, testResults: [], compilerError: null, microConceptFeedback: null,
        message: 'No visible test cases',
      });
    }

    let results = [];
    let compilerError = null;
    try {
      results = await runAgainstTestCases(code, visibleTC, exercise.time_limit_minutes * 60, true);
      const compileErrorResult = results.find(r => r.status === 'Compile Error');
      if (compileErrorResult) compilerError = compileErrorResult.error;
    } catch (execErr) {
      compilerError = execErr.message;
      results = [{
        input: 'N/A', expected: 'N/A', actual: '', passed: false,
        status: 'Execution Error', error: execErr.message, hidden: false,
      }];
    }

    res.json({
      passed: results.every(r => r.passed),
      testResults: results,
      compilerError,
      microConceptFeedback: null,
    });
  } catch (err) { next(err); }
});

// Submit code (all tests, save submission, persist behavioral events)
router.post('/exercises/:id/submit', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const { code, timeSpentSeconds, behavioralEvents = [] } = req.body;
    if (!code) throw new AppError('Code required', 400, codes.VALIDATION);

    const exRes = await db.query('SELECT * FROM exercises WHERE id = $1', [req.params.id]);
    if (!exRes.rows.length) throw new AppError('Exercise not found', 404, codes.NOT_FOUND);

    const exercise = exRes.rows[0];
    const allTestCases = typeof exercise.test_cases === 'string'
      ? JSON.parse(exercise.test_cases) : (exercise.test_cases || []);
    const visibleTestCases = allTestCases.filter(tc => !tc.hidden);

    let allResults = [];
    let visibleResults = [];
    let passed = false;
    let compilerError = null;

    try {
      allResults = await runAgainstTestCases(code, allTestCases, exercise.time_limit_minutes * 60, false);
      const compileErrorResult = allResults.find(r => r.status === 'Compile Error');
      if (compileErrorResult) compilerError = compileErrorResult.error;
      passed = allResults.every(r => r.passed);
      visibleResults = allResults.filter(r => !r.hidden);
    } catch (execErr) {
      compilerError = execErr.message;
      visibleResults = [{
        input: 'N/A', expected: 'N/A', actual: '', passed: false,
        status: 'Execution Error', error: execErr.message, hidden: false,
      }];
    }

    const attemptRes = await db.query(
      'SELECT COUNT(*)::int AS count FROM submissions WHERE exercise_id = $1 AND student_id = $2',
      [req.params.id, req.user.id]
    );
    const attempt_number = (attemptRes.rows[0].count || 0) + 1;

    const subRes = await db.query(`
      INSERT INTO submissions
        (exercise_id, student_id, code, is_correct, attempt_number, time_spent_seconds, submitted_at)
      VALUES ($1, $2, $3, $4, $5, $6, NOW())
      RETURNING id, exercise_id, student_id, is_correct, attempt_number, submitted_at, time_spent_seconds
    `, [exercise.id, req.user.id, code, passed, attempt_number, timeSpentSeconds || 0]);

    // Persist behavioral events (passive logging — HIGH #1)
    if (Array.isArray(behavioralEvents) && behavioralEvents.length) {
      try {
        const values = [];
        const placeholders = [];
        behavioralEvents.forEach((ev, i) => {
          const base = i * 5;
          placeholders.push(`($${base + 1}, $${base + 2}, $${base + 3}, $${base + 4}, $${base + 5})`);
          values.push(
            req.user.id,
            exercise.id,
            ev.type || 'unknown',
            ev.timestamp || new Date().toISOString(),
            JSON.stringify(ev.payload || {})
          );
        });
        await db.query(
          `INSERT INTO behavioral_events
             (student_id, exercise_id, event_type, occurred_at, payload)
           VALUES ${placeholders.join(',')}`,
          values
        );
      } catch (evErr) {
        // Non-fatal: behavioural events are observational
        // eslint-disable-next-line no-console
        console.warn('Failed to persist behavioral events:', evErr.message);
      }
    }

    // Live CDS for student-facing display
    let liveCDS = null;
    try {
      liveCDS = await cdsEngine.calculateLiveCDS(req.user.id, exercise.id, db);
      if (liveCDS && liveCDS.cds !== null) {
        await db.query(`
          INSERT INTO cds_scores (student_id, exercise_id, section_id, ner, nrs, nts, cds, classification, has_flagged_attempts, integrity_flag_count, source, visible, computed_at)
          VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, 'live', false, NOW())
          ON CONFLICT (student_id, exercise_id)
          DO UPDATE SET ner=$4, nrs=$5, nts=$6, cds=$7, classification=$8, has_flagged_attempts=$9, integrity_flag_count=$10, source='live', visible=false, computed_at=NOW()
        `, [
          req.user.id, exercise.id, exercise.section_id,
          liveCDS.ner || 0, liveCDS.nrs || 0, liveCDS.nts || 0,
          liveCDS.cds || 0, liveCDS.classification || 'Unscored',
          liveCDS.hasFlaggedAttempt || false, liveCDS.integrityFlagCount || 0,
        ]);
      }
    } catch (liveErr) {
      // eslint-disable-next-line no-console
      console.warn('Live CDS calculation failed:', liveErr.message);
    }

    res.status(201).json({
      ...subRes.rows[0],
      passed: subRes.rows[0].is_correct,
      testResults: visibleResults,
      compilerError,
      hiddenTestCount: allTestCases.filter(tc => tc.hidden).length,
      liveCDS,
      isCompleted: subRes.rows[0].is_correct,
      message: 'Submission saved successfully',
    });
  } catch (err) { next(err); }
});

router.get('/exercises/:id/attempts', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const r = await db.query(`
      SELECT id, exercise_id, is_correct AS passed, attempt_number, submitted_at
      FROM submissions WHERE exercise_id = $1 AND student_id = $2
      ORDER BY submitted_at DESC LIMIT 10
    `, [req.params.id, req.user.id]);
    res.json(r.rows || []);
  } catch (err) { next(err); }
});

router.get('/stats', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const totalRes = await db.query(`
      SELECT COUNT(DISTINCT ex.id)::int AS total
      FROM exercises ex
      JOIN enrollments en ON en.section_id = ex.section_id
      WHERE en.student_id = $1 AND ex.is_draft = false
    `, [req.user.id]);
    const completedRes = await db.query(`
      SELECT COUNT(DISTINCT exercise_id)::int AS completed
      FROM submissions WHERE student_id = $1 AND is_correct = true
    `, [req.user.id]);
    const total = totalRes.rows[0].total || 0;
    const completed = completedRes.rows[0].completed || 0;
    res.json({
      total_exercises: total,
      completed_exercises: completed,
      pending_exercises: total - completed,
      average_cds: 0,
    });
  } catch (err) { next(err); }
});

module.exports = router;
