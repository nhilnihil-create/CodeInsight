const db = require('../config/db');
const { withTransaction } = require('../config/db');

/**
 * Get a single integrity flag with full details.
 * GET /api/analytics/integrity-flags/:flagId
 */
exports.getIntegrityFlagDetail = async (req, res, next) => {
  try {
    const { flagId } = req.params;
    const result = await db.query(`
      SELECT i.id, i.flag_type, i.severity, i.evidence, i.context_behaviors, i.status, i.instructor_note, i.created_at, i.reviewed_at,
             u.name AS student_name, u.id AS student_id, e.title AS exercise_title, e.id AS exercise_id,
             s.name AS section_name
      FROM integrity_flags i
      JOIN users u ON i.student_id = u.id
      JOIN exercises e ON i.exercise_id = e.id
      JOIN sections s ON i.section_id = s.id
      WHERE i.id = $1
    `, [flagId]);

    if (result.rows.length === 0) {
      return res.status(404).json({ error: 'Integrity flag not found' });
    }

    const flag = result.rows[0];

    // Parse evidence JSON if present
    let evidence = [];
    if (flag.evidence) {
      evidence = typeof flag.evidence === 'string' ? JSON.parse(flag.evidence) : flag.evidence;
    }
    if (!Array.isArray(evidence)) evidence = [];

    res.json({
      id: flag.id,
      flagType: flag.flag_type,
      severity: flag.severity,
      status: flag.status,
      studentName: flag.student_name,
      studentId: flag.student_id,
      exerciseTitle: flag.exercise_title,
      exerciseId: flag.exercise_id,
      sectionName: flag.section_name,
      evidence,
      contextBehaviors: flag.context_behaviors,
      instructorNote: flag.instructor_note,
      createdAt: flag.created_at,
      reviewedAt: flag.reviewed_at,
      confidence: flag.severity === 'high' ? 90 : flag.severity === 'medium' ? 70 : 50,
    });
  } catch (err) {
    console.error('getIntegrityFlagDetail error:', err);
    next(err);
  }
};

/**
 * Get integrity flags for a section, with optional filtering.
 * GET /api/analytics/integrity-flags/:sectionId
 */
exports.getIntegrityFlags = async (req, res, next) => {
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

    // Build query — default to pending ('flagged') flags unless status filter provided
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

    // Default to pending flags only
    const statusFilter = req.query.status; // caller can override to see all
    if (statusFilter === 'all') {
      // no status filter
    } else {
      query += ` AND i.status = $${valueIndex}`;
      values.push(statusFilter || 'flagged');
      valueIndex++;
    }

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

    // Get total count for pagination — mirrors the same status filter
    let countQuery = `
      SELECT COUNT(*)
      FROM integrity_flags i
      WHERE 1=1
    `;
    const countValues = [];
    let countIndex = 1;
    if (statusFilter === 'all') {
      // no status filter
    } else {
      countQuery += ` AND i.status = $${countIndex}`;
      countValues.push(statusFilter || 'flagged');
      countIndex++;
    }
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
    next(err);
  }
};

/**
 * Review or dismiss an integrity flag.
 * PUT /api/analytics/integrity-flags/:flagId/review
 */
exports.reviewIntegrityFlag = async (req, res, next) => {
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

    // Atomic multi-table update within a transaction
    const result = await withTransaction(async (client) => {
      // a) Update integrity_flags status
      const flagRes = await client.query(
        `UPDATE integrity_flags
         SET status = $1, instructor_note = $2, reviewed_at = NOW()
         WHERE id = $3
         RETURNING *`,
        [targetStatus, note, flagId]
      );

      if (flagRes.rows.length === 0) {
        throw Object.assign(new Error('Integrity flag not found'), { status: 404 });
      }

      const flag = flagRes.rows[0];

      // b) Update corresponding alerts — mark matching alert as reviewed
      await client.query(
        `UPDATE alerts
         SET is_reviewed = true
         WHERE student_id = $1 AND exercise_id = $2 AND section_id = $3 AND is_reviewed = false`,
        [flag.student_id, flag.exercise_id, flag.section_id]
      );

      // c) Re-evaluate cds_scores.has_flagged_attempts
      //    If no remaining unreviewed flags for this student+exercise, flip to false
      const remainingRes = await client.query(
        `SELECT COUNT(*)::int AS cnt FROM integrity_flags
         WHERE student_id = $1 AND exercise_id = $2 AND status = 'flagged'`,
        [flag.student_id, flag.exercise_id]
      );

      if (remainingRes.rows[0].cnt === 0) {
        await client.query(
          `UPDATE cds_scores
           SET has_flagged_attempts = false
           WHERE student_id = $1 AND exercise_id = $2`,
          [flag.student_id, flag.exercise_id]
        );
      }

      // Return flag details for the response
      const detailsRes = await client.query(
        `SELECT i.id, i.flag_type, i.severity, i.evidence, i.context_behaviors, i.status, i.instructor_note, i.created_at, i.reviewed_at,
                u.name AS student_name, e.title AS exercise_title
         FROM integrity_flags i
         JOIN users u ON i.student_id = u.id
         JOIN exercises e ON i.exercise_id = e.id
         WHERE i.id = $1`,
        [flagId]
      );

      return detailsRes.rows[0];
    });

    res.json({
      message: 'Integrity flag updated successfully',
      flag: result
    });
  } catch (err) {
    console.error('Error reviewing integrity flag:', err);
    next(err);
  }
};