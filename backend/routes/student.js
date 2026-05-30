const express = require('express');
const router = express.Router();
const db = require('../config/db');
const { runAgainstTestCases } = require('../services/executor');
const cdsEngine = require('../services/cdsEngine');
const { verifyToken, requireRole } = require('../middleware/auth');
const fs = require('fs');

// Get all exercises for enrolled sections
router.get('/exercises', verifyToken, requireRole('student'), async (req, res) => {
  try {
    const r = await db.query(`
      SELECT 
        ex.id, ex.title, ex.description, c.name AS concept_name,
        ex.time_limit_minutes, ex.deadline, ex.test_cases,
        CASE 
          WHEN cs.cds IS NOT NULL THEN 'completed'
          ELSE 'pending'
        END AS status,
        cs.cds
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id
      LEFT JOIN cds_scores cs ON cs.exercise_id = ex.id AND cs.student_id = $1
      WHERE en.student_id = $1 AND ex.is_draft = false
      ORDER BY ex.created_at DESC
    `, [req.user.id]);
    res.json(r.rows);
  } catch (err) {
    console.error('Error in GET /exercises:', err);
    res.status(500).json({ message: err.message });
  }
});

// Get single exercise details
router.get('/exercises/:id', verifyToken, requireRole('student'), async (req, res) => {
  try {
    console.log(`[DEBUG] GET /exercises/:id called with id=${req.params.id}, studentId=${req.user.id}`);
    
    const r = await db.query(`
      SELECT 
        ex.*, c.name AS concept_name
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id
      WHERE ex.id = $1 AND en.student_id = $2
    `, [req.params.id, req.user.id]);
    
    console.log(`[DEBUG] Query returned ${r.rows.length} rows`);
    
    if (!r.rows.length) {
      console.log(`[DEBUG] No exercise found - student not enrolled or exercise does not exist`);
      return res.status(404).json({ message: 'Exercise not found' });
    }
    
    const ex = r.rows[0];
    
    // Filter out hidden test cases for students
    if (ex.test_cases) {
      console.log(`[DEBUG] test_cases type: ${typeof ex.test_cases}, length: ${typeof ex.test_cases === 'string' ? ex.test_cases.length : ex.test_cases.length}`);
      // Parse if it's a string (from database)
      let testCases = typeof ex.test_cases === 'string' ? JSON.parse(ex.test_cases) : ex.test_cases;
      ex.test_cases = testCases.filter(tc => !tc.hidden);
      console.log(`[DEBUG] Filtered to ${ex.test_cases.length} visible test cases`);
    }
    
    // BUG FIX #4: Check if student already completed this exercise
    const completedRes = await db.query(`
      SELECT id, submitted_at FROM submissions 
      WHERE exercise_id = $1 AND student_id = $2 AND is_correct = true
      LIMIT 1
    `, [req.params.id, req.user.id]);
    
    if (completedRes.rows.length > 0) {
      ex.isCompleted = true;
      ex.completedAt = completedRes.rows[0].submitted_at;
    } else {
      ex.isCompleted = false;
    }
    
    console.log(`[DEBUG] Returning exercise successfully`);
    res.json(ex);
  } catch (err) {
    console.error(`[ERROR] GET /exercises/:id failed:`, err);
    res.status(500).json({ message: err.message, details: err.stack });
  }
});

// Run code (execute test cases, don't save)
router.post('/exercises/:id/run', verifyToken, requireRole('student'), async (req, res) => {
  try {
    const { code } = req.body;
    if (!code) return res.status(400).json({ message: 'Code required' });
    
    // Get exercise
    const exRes = await db.query('SELECT * FROM exercises WHERE id = $1', [req.params.id]);
    if (!exRes.rows.length) return res.status(404).json({ message: 'Exercise not found' });
    
    const exercise = exRes.rows[0];
    
    // Parse test_cases if it's a string (from database)
    let testCases = typeof exercise.test_cases === 'string' ? JSON.parse(exercise.test_cases) : exercise.test_cases;
    
    // CRITICAL: Filter to VISIBLE test cases only for Run endpoint
    // Hidden test cases are NOT executed in Run mode
    const visibleTC = (testCases || []).filter(tc => !tc.hidden);
    
    if (!visibleTC.length) {
      return res.json({ 
        passed: true,
        testResults: [],
        compilerError: null,
        microConceptFeedback: null,
        message: 'No visible test cases'
      });
    }
    
    let results = [];
    let compilerError = null;
    
    try {
      // Execute code with VISIBLE tests only - maskHidden=true (safety redundancy)
      results = await runAgainstTestCases(code, visibleTC, exercise.time_limit_minutes * 60, true);
      
      // Extract compiler error if present
      const compileErrorResult = results.find(r => r.status === 'Compile Error');
      if (compileErrorResult) {
        compilerError = compileErrorResult.error;
      }
    } catch (execErr) {
      console.error('Code execution error:', execErr);
      compilerError = execErr.message;
      results = [{
        input: 'N/A',
        expected: 'N/A',
        actual: '',
        passed: false,
        status: 'Execution Error',
        error: execErr.message,
        hidden: false
      }];
    }
    
    res.json({
      passed: results.every(r => r.passed),
      testResults: results,
      compilerError: compilerError,
      microConceptFeedback: null
    });
  } catch (err) {
    console.error('Error in POST /exercises/:id/run:', err);
    res.status(500).json({ message: err.message });
  }
});

// Submit code (execute against ALL tests including hidden, save submission, return only visible)
router.post('/exercises/:id/submit', verifyToken, requireRole('student'), async (req, res) => {
  try {
    const { code, timeSpentSeconds } = req.body;
    console.log(`[DEBUG SUBMIT INCOMING] student=${req.user?.id} exercise=${req.params.id} time=${new Date().toISOString()} code_len=${code ? code.length : 0} timeSpentSeconds=${timeSpentSeconds}`);
    try { fs.appendFileSync('/tmp/submit_debug.log', JSON.stringify({ ts: new Date().toISOString(), student: req.user?.id, exercise: req.params.id, codePreview: (code||'').slice(0,200), codeLength: (code||'').length, timeSpentSeconds }) + '\n'); } catch(e) {}
    if (!code) return res.status(400).json({ message: 'Code required' });
    
    // Get exercise
    const exRes = await db.query('SELECT * FROM exercises WHERE id = $1', [req.params.id]);
    if (!exRes.rows.length) return res.status(404).json({ message: 'Exercise not found' });
    
    const exercise = exRes.rows[0];
    
    // Parse test_cases if it's a string (from database)
    let allTestCases = typeof exercise.test_cases === 'string' ? JSON.parse(exercise.test_cases) : exercise.test_cases;
    allTestCases = allTestCases || [];
    const visibleTestCases = allTestCases.filter(tc => !tc.hidden);
    
    let allResults = [];
    let visibleResults = [];
    let passed = false;
    let compilerError = null;
    
    try {
      // CRITICAL: Execute code against ALL test cases (including hidden)
      // maskHidden=false means we need to run all tests to determine correctness
      allResults = await runAgainstTestCases(code, allTestCases, exercise.time_limit_minutes * 60, false);
      
      // Extract compiler error if present in any result
      const compileErrorResult = allResults.find(r => r.status === 'Compile Error');
      if (compileErrorResult) {
        compilerError = compileErrorResult.error;
      }
      
      // Determine if ALL tests (including hidden) passed
      passed = allResults.every(r => r.passed);
      
      // Filter results to ONLY show visible test cases to the student
      visibleResults = allResults.filter(r => !r.hidden);
      
    } catch (execErr) {
      console.error('Code execution error:', execErr);
      compilerError = execErr.message;
      // If execution error, show it but mark as not passed
      visibleResults = [{
        input: 'N/A',
        expected: 'N/A',
        actual: '',
        passed: false,
        status: 'Execution Error',
        error: execErr.message,
        hidden: false
      }];
    }
    
    // Get attempt number
    const attemptRes = await db.query(
      'SELECT COUNT(*) as count FROM submissions WHERE exercise_id = $1 AND student_id = $2',
      [req.params.id, req.user.id]
    );
    const attempt_number = (attemptRes.rows[0].count || 0) + 1;
    
    // Save submission - run against ALL tests, but only store visible results
    let subRes;
    try {
      // We do not store full test_results in DB (some deployments lack this column).
      // Insert submission using existing columns only.
      subRes = await db.query(`
        INSERT INTO submissions (
          exercise_id, student_id, code, is_correct, attempt_number, time_spent_seconds, submitted_at
        )
        VALUES ($1, $2, $3, $4, $5, $6, $7)
        RETURNING id, exercise_id, student_id, is_correct, attempt_number, submitted_at, time_spent_seconds
      `, [
        exercise.id, req.user.id, code, passed, attempt_number, timeSpentSeconds || 0, new Date()
      ]);
    } catch (dbErr) {
      console.error('Submission insert error:', dbErr.message);
      // If insert fails, still return the results to show user feedback
      return res.status(201).json({
        id: null,
        exercise_id: exercise.id,
        student_id: req.user.id,
        is_correct: passed,
        attempt_number,
        testResults: visibleResults,
        compilerError: compilerError,
        message: 'Code executed but submission not saved (DB error)',
        submitted_at: new Date(),
        time_spent_seconds: timeSpentSeconds || 0
      });
    }
    
    // Calculate live CDS for display
    let liveCDS = null;
    try {
      liveCDS = await cdsEngine.calculateLiveCDS(req.user.id, exercise.id, db);
      
      // CRITICAL FIX #1: Persist liveCDS to cds_scores table immediately
      // This ensures My Progress page has data to display
      if (liveCDS && liveCDS.cds !== null) {
        await db.query(`
          INSERT INTO cds_scores (student_id, exercise_id, section_id, ner, nrs, nts, cds, classification, source, visible, computed_at)
          VALUES ($1, $2, $3, $4, $5, $6, $7, $8, 'live', false, NOW())
          ON CONFLICT (student_id, exercise_id)
          DO UPDATE SET ner=$4, nrs=$5, nts=$6, cds=$7, classification=$8, source='live', visible=false, computed_at=NOW()
        `, [
          req.user.id, exercise.id, exercise.section_id,
          liveCDS.ner || 0, liveCDS.nrs || 0, liveCDS.nts || 0,
          liveCDS.cds || 0, liveCDS.classification || 'Unscored'
        ]);
        
        console.log(`[DEBUG] Saved liveCDS for student ${req.user.id} on exercise ${exercise.id}: ${liveCDS.cds} (${liveCDS.classification})`);
      }
    } catch (liveErr) {
      console.error('Error calculating or saving live CDS:', liveErr);
    }
    
    // Return response with ONLY visible results to student
    res.status(201).json({
      ...subRes.rows[0],
      passed: subRes.rows[0].is_correct,
      testResults: visibleResults,
      compilerError: compilerError,
      hiddenTestCount: allTestCases.filter(tc => tc.hidden).length,
      liveCDS: liveCDS,
      isCompleted: subRes.rows[0].is_correct,
      message: 'Submission saved successfully'
    });
  } catch (err) {
    console.error('Error in POST /exercises/:id/submit:', err);
    res.status(500).json({ message: err.message });
  }
});

// Get submission attempts for an exercise
router.get('/exercises/:id/attempts', verifyToken, requireRole('student'), async (req, res) => {
  try {
    const r = await db.query(`
      SELECT id, exercise_id, is_correct AS passed, attempt_number, submitted_at
      FROM submissions
      WHERE exercise_id = $1 AND student_id = $2
      ORDER BY submitted_at DESC
      LIMIT 10
    `, [req.params.id, req.user.id]);
    
    res.json(r.rows || []);
  } catch (err) {
    console.error('Error in GET /exercises/:id/attempts:', err);
    res.status(500).json({ message: err.message });
  }
});

// Get student statistics
router.get('/stats', verifyToken, requireRole('student'), async (req, res) => {
  try {
    // Total exercises this student is enrolled in
    const totalRes = await db.query(`
      SELECT COUNT(DISTINCT ex.id) as total
      FROM exercises ex
      JOIN enrollments en ON en.section_id = ex.section_id
      WHERE en.student_id = $1
    `, [req.user.id]);
    
    const total = parseInt(totalRes.rows[0]?.total || 0);
    
    res.json({
      total_exercises: total,
      completed_exercises: 0,
      pending_exercises: total,
      average_cds: 0
    });
  } catch (err) {
    console.error('Error in GET /stats:', err);
    res.status(500).json({ message: err.message });
  }
});

// TEMPORARY DEBUG ROUTE - remove after investigation
// POST /internal/debug/submit
// Body: { exerciseId, code }
// Protected by X-Debug-Token header (set DEBUG_TOKEN env) or allowed locally.
router.post('/internal/debug/submit', async (req, res) => {
  try {
    const token = req.headers['x-debug-token'];
    const allowedToken = process.env.DEBUG_TOKEN || 'local-debug';
    // In production, require token match
    if (process.env.NODE_ENV === 'production' && token !== allowedToken) {
      return res.status(403).json({ message: 'Forbidden' });
    }

    const { exerciseId, code } = req.body;
    if (!exerciseId || !code) return res.status(400).json({ message: 'exerciseId and code required' });

    const exRes = await db.query('SELECT * FROM exercises WHERE id = $1', [exerciseId]);
    if (!exRes.rows.length) return res.status(404).json({ message: 'Exercise not found' });
    const exercise = exRes.rows[0];

    // Parse test cases
    const allTestCases = typeof exercise.test_cases === 'string' ? JSON.parse(exercise.test_cases) : (exercise.test_cases || []);

    // Run against ALL tests (including hidden) and return raw results
    const results = await runAgainstTestCases(code, allTestCases, (exercise.time_limit_minutes || 5) * 60, false);

    res.json({
      exerciseId,
      passed: results.every(r => r.passed),
      hiddenTestCount: allTestCases.filter(tc => tc.hidden).length,
      results
    });
  } catch (err) {
    console.error('[DEBUG] /internal/debug/submit error:', err);
    res.status(500).json({ message: err.message });
  }
});

module.exports = router;
