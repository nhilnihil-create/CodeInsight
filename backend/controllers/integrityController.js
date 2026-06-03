const db = require('../config/db');

/**
 * Get integrity flags for a section, with optional filtering.
 * GET /api/analytics/integrity-flags/:sectionId
 */
exports.getIntegrityFlags = async (req, res) => {
  try {
    let { sectionId, exerciseId: paramExerciseId } = req.params;
    const { flag_type, student_id, exercise_id: queryExerciseId, page = 1, limit = 50 } = req.query;

    let exercise_id = paramExerciseId || queryExerciseId;

    // If sectionId is missing but exerciseId is present, find the sectionId
    if (!sectionId && exercise_id) {
      const exRes = await db.query('SELECT section_id FROM exercises WHERE id = $1', [exercise_id]);
      if (exRes.rows.length > 0) {
        sectionId = exRes.rows[0].section_id;
      }
    }

    // Build query
    let query = `
      SELECT i.id, i.flag_type, i.severity, i.evidence, i.context_behaviors, i.status, i.instructor_note, i.created_at, i.reviewed_at,
             u.name AS student_name, e.title AS exercise_title
      FROM integrity_flags i
      JOIN users u ON i.student_id = u.id
      JOIN exercises e ON i.exercise_id = e.id
      WHERE 1=1
    `;
    const values = [];
    let valueIndex = 1;

    // Add optional filters
    if (sectionId) {
      query += ` AND i.section_id = $${valueIndex}`;
      values.push(sectionId);
      valueIndex++;
    }
    if (flag_type) {
      query += ` AND i.flag_type = $${valueIndex}`;
      values.push(flag_type);
      valueIndex++;
    }
    if (student_id) {
      query += ` AND i.student_id = $${valueIndex}`;
      values.push(student_id);
      valueIndex++;
    }
    if (exercise_id) {
      query += ` AND i.exercise_id = $${valueIndex}`;
      values.push(exercise_id);
      valueIndex++;
    }

    // Add ordering and pagination
    query += ` ORDER BY i.created_at DESC LIMIT $${valueIndex} OFFSET $${valueIndex + 1}`;
    values.push(limit);
    values.push((page - 1) * limit);

    const result = await db.query(query, values);

    // Get total count for pagination
    let countQuery = `
      SELECT COUNT(*)
      FROM integrity_flags i
      WHERE 1=1
    `;
    const countValues = [];
    let countIndex = 1;
    if (sectionId) {
      countQuery += ` AND i.section_id = $${countIndex}`;
      countValues.push(sectionId);
      countIndex++;
    }
    if (flag_type) {
      countQuery += ` AND i.flag_type = $${countIndex}`;
      countValues.push(flag_type);
      countIndex++;
    }
    if (student_id) {
      countQuery += ` AND i.student_id = $${countIndex}`;
      countValues.push(student_id);
      countIndex++;
    }
    if (exercise_id) {
      countQuery += ` AND i.exercise_id = $${countIndex}`;
      countValues.push(exercise_id);
      countIndex++;
    }
    const countResult = await db.query(countQuery, countValues);
    const totalCount = parseInt(countResult.rows[0].count);

    res.json({
      flags: result.rows,
      pagination: {
        page: parseInt(page),
        limit: parseInt(limit),
        total: totalCount,
        totalPages: Math.ceil(totalCount / limit)
      }
    });
  } catch (err) {
    console.error('Error fetching integrity flags:', err);
    res.status(500).json({ message: err.message });
  }
};

/**
 * Review or dismiss an integrity flag.
 * PUT /api/analytics/integrity-flags/:flagId/review
 */
exports.reviewIntegrityFlag = async (req, res) => {
  try {
    const { flagId } = req.params;
    const { status, instructor_note, instructorNote } = req.body;

    // Use whichever note was provided
    const note = instructor_note || instructorNote || null;

    // Validate inputs
    if (!flagId) {
      return res.status(400).json({ message: 'Flag ID is required' });
    }
    
    // Default to 'reviewed' if status is missing but mark-reviewed was called
    const targetStatus = status || 'reviewed';

    if (!['flagged', 'reviewed', 'dismissed'].includes(targetStatus)) {
      return res.status(400).json({ message: 'Status must be one of: flagged, reviewed, dismissed' });
    }

    // Update the flag
    const result = await db.query(
      `UPDATE integrity_flags
       SET status = $1, instructor_note = $2, reviewed_at = NOW()
       WHERE id = $3
       RETURNING *`,
      [targetStatus, note, flagId]
    );

    if (result.rows.length === 0) {
      return res.status(404).json({ message: 'Integrity flag not found' });
    }

    // Get the updated flag with student and exercise info
    const flagWithDetails = await db.query(
      `SELECT i.id, i.flag_type, i.severity, i.evidence, i.context_behaviors, i.status, i.instructor_note, i.created_at, i.reviewed_at,
              u.name AS student_name, e.title AS exercise_title
       FROM integrity_flags i
       JOIN users u ON i.student_id = u.id
       JOIN exercises e ON i.exercise_id = e.id
       WHERE i.id = $1`,
      [flagId]
    );

    res.json({
      message: 'Integrity flag updated successfully',
      flag: flagWithDetails.rows[0]
    });
  } catch (err) {
    console.error('Error reviewing integrity flag:', err);
    res.status(500).json({ message: err.message });
  }
};