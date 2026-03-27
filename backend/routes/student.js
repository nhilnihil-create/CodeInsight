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
        ex.time_limit_minutes, ex.deadline,
        CASE 
          WHEN sub.id IS NOT NULL THEN 'completed'
          WHEN NOW() > ex.deadline THEN 'locked'
          ELSE 'pending'
        END AS status,
        sub.cds AS latest_cds
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id
      LEFT JOIN submissions sub ON sub.exercise_id = ex.id 
        AND sub.student_id = $1
        AND sub.passed = true
      WHERE en.student_id = $1
      ORDER BY ex.created_at DESC
    `, [req.user.id]);
    res.json(r.rows);
  } catch (err) {
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
    
    // Execute code with test cases
    const results = await runAgainstTestCases(code, testCases);
    
    // Calculate CDS
    const cds = cdsEngine.calculateCDS(results, exercise);
    
    res.json({
      passed: results.every(r => r.passed),
      testResults: results,
      cds: cds.score,
      classification: cds.classification
    });
  } catch (err) {
    res.status(500).json({ message: err.message });
  }
});

// Submit code (execute and save submission)
router.post('/exercises/:id/submit', verifyToken, requireRole('student'), async (req, res) => {
  try {
    const { code } = req.body;
    if (!code) return res.status(400).json({ message: 'Code required' });
    
    // Get exercise
    const exRes = await db.query('SELECT * FROM exercises WHERE id = $1', [req.params.id]);
    if (!exRes.rows.length) return res.status(404).json({ message: 'Exercise not found' });
    
    const exercise = exRes.rows[0];
    const testCases = exercise.test_cases || [];
    
    // Execute code
    const results = await runAgainstTestCases(code, testCases);
    const passed = results.every(r => r.passed);
    
    // Calculate CDS
    const cds = cdsEngine.calculateCDS(results, exercise);
    
    // Get attempt number
    const attemptRes = await db.query(
      'SELECT COUNT(*) as count FROM submissions WHERE exercise_id = $1 AND student_id = $2',
      [req.params.id, req.user.id]
    );
    const attempt_number = (attemptRes.rows[0].count || 0) + 1;
    
    // Save submission
    const subRes = await db.query(`
      INSERT INTO submissions (
        exercise_id, student_id, code, test_results, passed, 
        cds, ner, nrs, nts, attempt_number, created_at
      )
      VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, NOW())
      RETURNING *
    `, [
      exercise.id, req.user.id, code,
      JSON.stringify(results), passed,
      cds.score, cds.ner || 0, cds.nrs || 0, cds.nts || 0, attempt_number
    ]);
    
    // Check if auto-alert should trigger
    if (exercise.auto_alert && cds.score > 0.5) {
      await db.query(`
        INSERT INTO alerts (exercise_id, student_id, cds_score, triggered_at)
        VALUES ($1, $2, $3, NOW())
      `, [exercise.id, req.user.id, cds.score]);
    }
    
    res.status(201).json({
      ...subRes.rows[0],
      cds: cds.score,
      classification: cds.classification
    });
  } catch (err) {
    res.status(500).json({ message: err.message });
  }
});

// Get submission attempts for an exercise
router.get('/exercises/:id/attempts', verifyToken, requireRole('student'), async (req, res) => {
  try {
    const r = await db.query(`
      SELECT id, exercise_id, passed, cds, attempt_number, created_at
      FROM submissions
      WHERE exercise_id = $1 AND student_id = $2
      ORDER BY created_at DESC
      LIMIT 10
    `, [req.params.id, req.user.id]);
    
    res.json(r.rows);
  } catch (err) {
    res.status(500).json({ message: err.message });
  }
});

// Get student statistics
router.get('/stats', verifyToken, requireRole('student'), async (req, res) => {
  try {
    const statsRes = await db.query(`
      SELECT
        COUNT(DISTINCT ex.id) as total_exercises,
        COUNT(DISTINCT CASE WHEN sub.passed THEN ex.id END) as completed,
        AVG(sub.cds) as avg_cds,
        STDDEV(sub.cds) as stddev_cds
      FROM exercises ex
      JOIN enrollments en ON en.section_id = ex.section_id
      LEFT JOIN submissions sub ON sub.exercise_id = ex.id AND sub.student_id = $1
      WHERE en.student_id = $1
    `, [req.user.id]);
    
    res.json(statsRes.rows[0] || {});
  } catch (err) {
    res.status(500).json({ message: err.message });
  }
});

module.exports = router;
