const express = require('express');
const router  = express.Router();
const { verifyToken } = require('../middleware/auth');
const db = require('../config/db');
const { AppError, codes } = require('../lib/AppError');

router.get('/', verifyToken, async (req, res, next) => {
  try {
    const r = await db.query(
      `SELECT id, section_id, exercise_id, message, notification_type, is_read, created_at
         FROM notifications
        WHERE student_id = $1
        ORDER BY created_at DESC
        LIMIT 50`,
      [req.user.id]
    );
    res.json({ notifications: r.rows });
  } catch (err) { next(err); }
});

router.post('/:id/read', verifyToken, async (req, res, next) => {
  try {
    const r = await db.query(
      `UPDATE notifications SET is_read = true
         WHERE id = $1 AND student_id = $2
         RETURNING id, is_read`,
      [req.params.id, req.user.id]
    );
    if (!r.rows.length) throw new AppError('Notification not found', 404, codes.NOT_FOUND);
    res.json(r.rows[0]);
  } catch (err) { next(err); }
});

router.post('/read-all', verifyToken, async (req, res, next) => {
  try {
    const r = await db.query(
      `UPDATE notifications SET is_read = true WHERE student_id = $1 AND is_read = false`,
      [req.user.id]
    );
    res.json({ updated: r.rowCount || 0 });
  } catch (err) { next(err); }
});

module.exports = router;
