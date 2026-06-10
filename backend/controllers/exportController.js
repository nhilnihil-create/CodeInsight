const db = require('../config/db');
const { AppError, codes } = require('../lib/AppError');

/**
 * ExportController — Data Export for thesis defense auditability.
 *
 * Exports behavioral audit logs, CDS scores, and submissions
 * in CSV or JSON format.
 */

function toCSV(headers, rows) {
  return [
    headers.map(h => `"${h}"`).join(','),
    ...rows.map(r => r.map(v => `"${String(v ?? '').replace(/"/g, '""')}"`).join(',')),
  ].join('\n');
}

function sendExport(res, format, filename, headers, rows, data = null) {
  if (format === 'json') {
    const json = rows.map(r => {
      const obj = {};
      headers.forEach((h, i) => { obj[h] = r[i]; });
      return obj;
    });
    return res.json(json);
  }

  // CSV
  const csv = toCSV(headers, rows);
  res.setHeader('Content-Disposition', `attachment; filename="${filename}.${format === 'csv' ? 'csv' : 'json'}"`);
  res.setHeader('Content-Type', 'text/csv;charset=utf-8;');
  res.send(csv);
}

/**
 * GET /api/export/behavioral/:sectionId?format=csv|json
 * Export behavioral audit log for all students in a section.
 */
exports.exportBehavioral = async (req, res, next) => {
  try {
    const { sectionId } = req.params;
    const { format = 'csv' } = req.query;

    const secCond = sectionId === 'all'
      ? `al.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
      : `al.section_id = $1`;
    const params = sectionId === 'all' ? [req.user?.id] : [sectionId];

    const result = await db.query(
      `SELECT al.id, u.name AS student_name, u.email AS student_email,
              ex.title AS exercise_title, c.name AS concept_name,
              al.event_type, al.metadata, al.occurred_at
       FROM audit_log al
       JOIN users u ON u.id = al.student_id
       JOIN exercises ex ON ex.id = al.exercise_id
       JOIN concepts c ON c.id = ex.concept_id
       WHERE ${secCond}
       ORDER BY al.occurred_at DESC
       LIMIT 10000`,
      params
    );

    const headers = ['Student', 'Email', 'Exercise', 'Concept', 'Event Type', 'Metadata', 'Occurred At'];
    const rows = result.rows.map(r => [
      r.student_name,
      r.student_email,
      r.exercise_title,
      r.concept_name,
      r.event_type,
      typeof r.metadata === 'object' ? JSON.stringify(r.metadata) : r.metadata,
      r.occurred_at,
    ]);

    const filename = `behavioral-audit-${sectionId}-${new Date().toISOString().slice(0, 10)}`;
    sendExport(res, format, filename, headers, rows);
  } catch (err) {
    next(err);
  }
};

/**
 * GET /api/export/cds/:sectionId?format=csv|json
 * Export CDS scores and snapshots for all students in a section.
 */
exports.exportCDS = async (req, res, next) => {
  try {
    const { sectionId } = req.params;
    const { format = 'csv' } = req.query;

    const secCond = sectionId === 'all'
      ? `cs.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
      : `cs.section_id = $1`;
    const params = sectionId === 'all' ? [req.user?.id] : [sectionId];

    const result = await db.query(
      `SELECT u.name AS student_name, u.email AS student_email,
              ex.title AS exercise_title, c.name AS concept_name,
              cs.ner, cs.nrs, cs.nts, cs.cds, cs.classification,
              cs.source, cs.has_flagged_attempts, cs.integrity_flag_count,
              cs.computed_at
       FROM cds_scores cs
       JOIN users u ON u.id = cs.student_id
       JOIN exercises ex ON ex.id = cs.exercise_id
       JOIN concepts c ON c.id = ex.concept_id
       WHERE ${secCond} AND cs.visible = true
       ORDER BY cs.computed_at DESC`,
      params
    );

    const headers = ['Student', 'Email', 'Exercise', 'Concept', 'NER', 'NRS', 'NTS', 'CDS', 'Classification', 'Source', 'Flagged', 'Flag Count', 'Computed At'];
    const rows = result.rows.map(r => [
      r.student_name,
      r.student_email,
      r.exercise_title,
      r.concept_name,
      r.ner,
      r.nrs,
      r.nts,
      r.cds,
      r.classification,
      r.source,
      r.has_flagged_attempts,
      r.integrity_flag_count,
      r.computed_at,
    ]);

    const filename = `cds-scores-${sectionId}-${new Date().toISOString().slice(0, 10)}`;
    sendExport(res, format, filename, headers, rows);
  } catch (err) {
    next(err);
  }
};

/**
 * GET /api/export/submissions/:sectionId?format=csv|json
 * Export all submissions for all students in a section.
 */
exports.exportSubmissions = async (req, res, next) => {
  try {
    const { sectionId } = req.params;
    const { format = 'csv' } = req.query;

    const secCond = sectionId === 'all'
      ? `ex.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
      : `ex.section_id = $1`;
    const params = sectionId === 'all' ? [req.user?.id] : [sectionId];

    const result = await db.query(
      `SELECT u.name AS student_name, u.email AS student_email,
              ex.title AS exercise_title, c.name AS concept_name,
              s.attempt_number, s.is_correct, s.time_spent_seconds,
              s.code_growth_delta, s.is_verified, s.is_practice,
              s.submitted_at
       FROM submissions s
       JOIN users u ON u.id = s.student_id
       JOIN exercises ex ON ex.id = s.exercise_id
       JOIN concepts c ON c.id = ex.concept_id
       WHERE ${secCond}
       ORDER BY s.submitted_at DESC
       LIMIT 50000`,
      params
    );

    const headers = ['Student', 'Email', 'Exercise', 'Concept', 'Attempt #', 'Correct', 'Time (sec)', 'Code Growth', 'Verified', 'Practice', 'Submitted At'];
    const rows = result.rows.map(r => [
      r.student_name,
      r.student_email,
      r.exercise_title,
      r.concept_name,
      r.attempt_number,
      r.is_correct,
      r.time_spent_seconds,
      r.code_growth_delta,
      r.is_verified,
      r.is_practice,
      r.submitted_at,
    ]);

    const filename = `submissions-${sectionId}-${new Date().toISOString().slice(0, 10)}`;
    sendExport(res, format, filename, headers, rows);
  } catch (err) {
    next(err);
  }
};

/**
 * GET /api/export/cds-snapshots/:sectionId?format=csv|json
 * Export append-only CDS calculation snapshots for reproducibility audit.
 */
exports.exportCdsSnapshots = async (req, res, next) => {
  try {
    const { sectionId } = req.params;
    const { format = 'csv' } = req.query;

    const secCond = sectionId === 'all'
      ? `ex.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
      : `ex.section_id = $1`;
    const params = sectionId === 'all' ? [req.user?.id] : [sectionId];

    const result = await db.query(
      `SELECT u.name AS student_name,
              ex.title AS exercise_title, c.name AS concept_name,
              sn.ner, sn.nrs, sn.nts, sn.cds, sn.classification,
              sn.class_max_errors, sn.class_max_attempts, sn.effective_max_time,
              sn.calculated_at
       FROM cds_snapshots sn
       JOIN users u ON u.id = sn.student_id
       JOIN exercises ex ON ex.id = sn.exercise_id
       JOIN concepts c ON c.id = ex.concept_id
       WHERE ${secCond}
       ORDER BY sn.calculated_at DESC`,
      params
    );

    const headers = ['Student', 'Exercise', 'Concept', 'NER', 'NRS', 'NTS', 'CDS', 'Classification', 'Class Max Errors', 'Class Max Attempts', 'Effective Max Time', 'Calculated At'];
    const rows = result.rows.map(r => [
      r.student_name,
      r.exercise_title,
      r.concept_name,
      r.ner,
      r.nrs,
      r.nts,
      r.cds,
      r.classification,
      r.class_max_errors,
      r.class_max_attempts,
      r.effective_max_time,
      r.calculated_at,
    ]);

    const filename = `cds-snapshots-${sectionId}-${new Date().toISOString().slice(0, 10)}`;
    sendExport(res, format, filename, headers, rows);
  } catch (err) {
    next(err);
  }
};
