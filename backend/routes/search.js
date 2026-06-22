const express = require('express');
const router = express.Router();
const db = require('../config/db');
const logger = require('../lib/logger');
const { verifyToken, requireRole } = require('../middleware/auth');

// Global search across exercises, students, sections
router.get('/', verifyToken, async (req, res, next) => {
  try {
    const { q, type, concept, section_id } = req.query;

    const results = {};

    if (!type || type === 'exercises') {
      let exerciseQuery = 'SELECT e.id, e.title, e.description, e.created_at, e.concept_id, e.section_id, c.name AS concept_name FROM exercises e JOIN concepts c ON e.concept_id = c.id WHERE 1=1';
      const exerciseParams = [];
      let paramIndex = 1;

      if (q) {
        exerciseQuery += ` AND (e.title ILIKE $${paramIndex} OR e.description ILIKE $${paramIndex})`;
        exerciseParams.push(`%${q}%`);
        paramIndex++;
      }

      if (concept) {
        exerciseQuery += ` AND c.name = $${paramIndex}`;
        exerciseParams.push(concept);
        paramIndex++;
      }

      if (section_id) {
        exerciseQuery += ` AND e.section_id = $${paramIndex}`;
        exerciseParams.push(section_id);
        paramIndex++;
      }

      exerciseQuery += ' LIMIT 50';

      const exercises = await db.query(exerciseQuery, exerciseParams);
      results.exercises = exercises.rows;
    }

    if (!type || type === 'students') {
      if (!q) return res.status(400).json({ error: 'Query parameter "q" is required for student search' });
      const students = await db.query(
        'SELECT id, name, email, role FROM users WHERE (name ILIKE $1 OR email ILIKE $1) AND role = $2 LIMIT 20',
        [`%${q}%`, 'student']
      );
      results.students = students.rows;
    }

    if (!type || type === 'sections') {
      if (!q) return res.status(400).json({ error: 'Query parameter "q" is required for section search' });
      const sections = await db.query(
        'SELECT id, name, course_code FROM sections WHERE name ILIKE $1 OR course_code ILIKE $1 LIMIT 20',
        [`%${q}%`]
      );
      results.sections = sections.rows;
    }

    res.json(results);
  } catch (err) {
    logger.error({ err }, 'Search failed');
    next(err);
  }
});

module.exports = router;
