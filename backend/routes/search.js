const express = require('express');
const router = express.Router();
const db = require('../config/db');
const { verifyToken, requireRole } = require('../middleware/auth');

// Global search across exercises, students, sections
router.get('/', verifyToken, async (req, res) => {
  try {
    const { q, type } = req.query;
    if (!q) return res.status(400).json({ error: 'Query parameter "q" is required' });

    const results = {};

    if (!type || type === 'exercises') {
      const exercises = await db.query(
        'SELECT id, title, description, created_at FROM exercises WHERE title ILIKE $1 OR description ILIKE $1 LIMIT 20',
        [`%${q}%`]
      );
      results.exercises = exercises.rows;
    }

    if (!type || type === 'students') {
      const students = await db.query(
        'SELECT id, name, email, role FROM users WHERE (name ILIKE $1 OR email ILIKE $1) AND role = $2 LIMIT 20',
        [`%${q}%`, 'student']
      );
      results.students = students.rows;
    }

    if (!type || type === 'sections') {
      const sections = await db.query(
        'SELECT id, name, course_code FROM sections WHERE name ILIKE $1 OR course_code ILIKE $1 LIMIT 20',
        [`%${q}%`]
      );
      results.sections = sections.rows;
    }

    res.json(results);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

module.exports = router;
