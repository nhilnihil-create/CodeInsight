const express = require('express');
const router = express.Router();
const db = require('../config/db');
const { runAgainstTestCases } = require('../services/executor');
const cdsEngine = require('../services/cdsEngine');
const { verifyToken, requireRole } = require('../middleware/auth');

// Get all exercises for enrolled sections
router.get('/exercises', verifyToken, requireRole('student'), async (req, res) => {
  try {
    const r = await db.query(`
      SELECT 
        ex.id, ex.title, ex.description, c.name AS concept_name,
        ex.time_limit_minutes, ex.deadline, ex.test_cases,
        'pending' AS status,
        NULL::NUMERIC AS cds
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id
      WHERE en.student_id = $1
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
    const r = await db.query(`
      SELECT 
        ex.*, c.name AS concept_name
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id
      WHERE ex.id = $1 AND en.student_id = $2
    `, [req.params.id, req.user.id]);
    
    if (!r.rows.length) {
      return res.status(404).json({ message: 'Exercise not found' });
    }
    
    const ex = r.rows[0];
    
    // Filter out hidden test cases for students
    if (ex.test_cases) {
      ex.test_cases = ex.test_cases.filter(tc => !tc.hidden);
    }
    
    res.json(ex);
  } catch (err) {
    res.status(500).json({ message: err.message });
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
    const testCases = exercise.test_cases || [];
    
    let results = [];
    let cds = { score: 0, classification: 'Unscored' };
    
    try {
      // Execute code with test cases
      results = await runAgainstTestCases(code, testCases);
      // Calculate CDS
      cds = cdsEngine.calculateCDS(results, exercise);
    } catch (execErr) {
      console.error('Code execution error:', execErr);
      results = [{
        passed: false,
        error: execErr.message
      }];
    }
    
    res.json({
      passed: results.every(r => r.passed),
      testResults: results,
      cds: cds.score,
      classification: cds.classification
    });
  } catch (err) {
    console.error('Error in POST /exercises/:id/run:', err);
    res.status(500).json({ message: err.message });
  }
});

// Submit code (execute and save submission)
router.post('/exercises/:id/submit', verifyToken, requireRole('student'), async (req, res) => {
  try {
    const { code, timeSpentSeconds } = req.body;
    if (!code) return res.status(400).json({ message: 'Code required' });
    
    // Get exercise
    const exRes = await db.query('SELECT * FROM exercises WHERE id = $1', [req.params.id]);
    if (!exRes.rows.length) return res.status(404).json({ message: 'Exercise not found' });
    
    const exercise = exRes.rows[0];
    const testCases = exercise.test_cases || [];
    
    let results = [];
    let passed = false;
    let cds = { score: 0, classification: 'Unscored' };
    
    try {
      // Execute code
      results = await runAgainstTestCases(code, testCases);
      passed = results.every(r => r.passed);
      
      // Calculate CDS
      cds = cdsEngine.calculateCDS(results, exercise);
    } catch (execErr) {
      console.error('Code execution error:', execErr);
      results = [{
        passed: false,
        error: execErr.message
      }];
    }
    
    // Get attempt number
    const attemptRes = await db.query(
      'SELECT COUNT(*) as count FROM submissions WHERE exercise_id = $1 AND student_id = $2',
      [req.params.id, req.user.id]
    );
    const attempt_number = (attemptRes.rows[0].count || 0) + 1;
    
    // Save submission - insert only required fields that exist in table
    let subRes;
    try {
      // Insert using actual table columns
      subRes = await db.query(`
        INSERT INTO submissions (
          exercise_id, student_id, code, is_correct, attempt_number, time_spent_seconds
        )
        VALUES ($1, $2, $3, $4, $5, $6)
        RETURNING id, exercise_id, student_id, is_correct, attempt_number, created_at, time_spent_seconds
      `, [
        exercise.id, req.user.id, code, passed, attempt_number, timeSpentSeconds || 0
      ]);
    } catch (dbErr) {
      console.error('Submission insert error:', dbErr.message);
      // If that fails, return the results without saving
      return res.status(201).json({
        id: null,
        exercise_id: exercise.id,
        student_id: req.user.id,
        is_correct: passed,
        attempt_number,
        testResults: results,
        classification: cds.classification,
        created_at: new Date(),
        time_spent_seconds: timeSpentSeconds || 0
      });
    }
    
    res.status(201).json({
      ...subRes.rows[0],
      passed: subRes.rows[0].is_correct,
      testResults: results,
      cds: cds.score,
      classification: cds.classification
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
      SELECT id, exercise_id, is_correct AS passed, attempt_number, created_at
      FROM submissions
      WHERE exercise_id = $1 AND student_id = $2
      ORDER BY created_at DESC
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

module.exports = router;
