/**
 * backend/services/integrityFlagEngine.js
 *
 * Academic integrity flag persistence and management.
 * Per the research paper, this engine handles:
 *   - Flag creation and persistence (integrity_flags table)
 *   - Flag querying for instructor dashboard
 *   - Flag review/dismissal workflow
 *
 * Detection logic lives in academicIntegrityEngine.js and behavioralAnomalyDetector.js.
 */

const db = require('../config/db');

// ── createFlag ─────────────────────────────────────────────────────────────

async function createFlag(flagData) {
  const { sectionId, exerciseId, studentId, flagType, severity, evidence, contextBehaviors, status, submissionId } = flagData;

  try {
    const result = await db.query(
      `INSERT INTO integrity_flags
       (section_id, exercise_id, student_id, flag_type, severity, evidence, context_behaviors, status, created_at, submission_id)
       VALUES ($1, $2, $3, $4, $5, $6, $7, $8, NOW(), $9)
       ON CONFLICT (exercise_id, student_id, flag_type)
       DO UPDATE SET
         severity = EXCLUDED.severity,
         evidence = EXCLUDED.evidence,
         context_behaviors = EXCLUDED.context_behaviors,
         submission_id = EXCLUDED.submission_id
       RETURNING *`,
      [sectionId, exerciseId, studentId, flagType, severity,
       JSON.stringify(evidence), contextBehaviors, status || 'flagged', submissionId || null]
    );

    return result.rows[0];
  } catch (err) {
    console.error('Error creating integrity flag:', err);
    throw err;
  }
}

// ── Query helpers (unchanged) ───────────────────────────────────────────────

async function getFlagsForExercise(exerciseId) {
  try {
    const result = await db.query(
      `SELECT f.*, u.name AS student_name
       FROM integrity_flags f
       JOIN users u ON f.student_id = u.id
       WHERE f.exercise_id = $1
       ORDER BY f.severity DESC, f.created_at DESC`,
      [exerciseId]
    );

    return result.rows.map(row => ({
      ...row,
      evidence: typeof row.evidence === 'string' ? JSON.parse(row.evidence) : row.evidence,
    }));
  } catch (err) {
    console.error('Error fetching integrity flags:', err);
    throw err;
  }
}

async function getFlagsForSubmission(submissionId) {
  try {
    const result = await db.query(
      `SELECT f.id, f.flag_type, f.severity, f.evidence, f.context_behaviors,
              f.status, f.created_at
       FROM integrity_flags f
       JOIN submissions s ON s.student_id = f.student_id AND s.exercise_id = f.exercise_id
       WHERE s.id = $1
       ORDER BY
         CASE f.severity WHEN 'high' THEN 1 WHEN 'medium' THEN 2 WHEN 'low' THEN 3 ELSE 4 END,
         f.created_at DESC`,
      [submissionId]
    );

    return result.rows.map(row => {
      let evidence = row.evidence;
      if (typeof evidence === 'string') {
        try { evidence = JSON.parse(evidence); } catch (_) {}
      }
      return { ...row, evidence };
    });
  } catch (err) {
    console.error('Error fetching flags for submission:', err);
    throw err;
  }
}

async function getFlagsForSection(sectionId) {
  try {
    const result = await db.query(
      `SELECT f.*, u.name AS student_name, e.title AS exercise_title
       FROM integrity_flags f
       JOIN users u ON f.student_id = u.id
       JOIN exercises e ON f.exercise_id = e.id
       WHERE f.section_id = $1
       ORDER BY e.id, f.severity DESC, f.created_at DESC`,
      [sectionId]
    );

    const grouped = {};
    result.rows.forEach(row => {
      if (!grouped[row.exercise_id]) {
        grouped[row.exercise_id] = {
          exerciseId: row.exercise_id,
          exerciseTitle: row.exercise_title,
          flags: []
        };
      }
      grouped[row.exercise_id].flags.push({
        ...row,
        evidence: typeof row.evidence === 'string' ? JSON.parse(row.evidence) : row.evidence,
      });
    });

    return Object.values(grouped);
  } catch (err) {
    console.error('Error fetching section flags:', err);
    throw err;
  }
}

async function markFlagReviewed(flagId, instructorNote = null) {
  try {
    const result = await db.query(
      `UPDATE integrity_flags
       SET status = 'reviewed', reviewed_at = NOW(), instructor_note = $2
       WHERE id = $1
       RETURNING *`,
      [flagId, instructorNote]
    );
    return result.rows[0];
  } catch (err) {
    console.error('Error marking flag reviewed:', err);
    throw err;
  }
}

// ── Graduated Flagging ──────────────────────────────────────────────────────

async function getWarningCount(studentId, exerciseId, flagType) {
  try {
    const result = await db.query(
      `SELECT COUNT(*)::int AS cnt FROM behavioral_events
       WHERE student_id = $1 AND exercise_id = $2 AND event_type = $3`,
      [studentId, exerciseId, `warning_${flagType}`]
    );
    return result.rows[0].cnt;
  } catch (err) {
    console.error('Error getting warning count:', err);
    return 0;
  }
}

async function createWarningEvent(studentId, exerciseId, flagType, evidence) {
  try {
    await db.query(
      `INSERT INTO behavioral_events (student_id, exercise_id, event_type, payload, occurred_at)
       VALUES ($1, $2, $3, $4, NOW())`,
      [studentId, exerciseId, `warning_${flagType}`, JSON.stringify(evidence)]
    );
  } catch (err) {
    console.error('Error creating warning event:', err);
  }
}

// ── Public API ──────────────────────────────────────────────────────────────

module.exports = {
  createFlag,
  getFlagsForExercise,
  getFlagsForSection,
  getFlagsForSubmission,
  markFlagReviewed,
  getWarningCount,
  createWarningEvent,
};
