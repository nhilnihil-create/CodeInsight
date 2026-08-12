/**
 * backend/services/exportService.js
 *
 * Domain registry + format dispatch for instructor-facing section exports.
 * Handles CSV (hand-rolled writer), XLSX (exceljs) and JSON (raw DB rows),
 * filename/header generation, and the section ownership guard.
 *
 * DOMAINS: each domain provides a fetch(sectionId, opts) query and the
 * columns used by the CSV/XLSX writers. JSON output skips the columns and
 * emits fetchRows() with raw DB fidelity.
 */

const db = require('../config/db');
const ExcelJS = require('exceljs');
const { AppError, codes } = require('../lib/AppError');
const { toCsv } = require('./csvWriter');

const MAX_EXPORT_ROWS = 25000;

const EXPORT_FORMATS = ['csv', 'xlsx', 'json'];

const MIME_TYPES = {
  csv: 'text/csv; charset=utf-8',
  xlsx: 'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet',
  json: 'application/json; charset=utf-8',
};

// ── Filename / header helpers ───────────────────────────────────────────────

/**
 * Strip filesystem/reserved filename characters ([\\/:*?"<>|]), collapse
 * whitespace runs, trim, and cap the result at 60 chars.
 */
function sanitizeFilename(name) {
  return String(name === null || name === undefined ? '' : name)
    .replace(/[\\/:*?"<>|]/g, '')
    .replace(/\s+/g, ' ')
    .trim()
    .slice(0, 60);
}

/**
 * Build an export filename: {sanitized}_{domain}_{YYYY-MM-DD}.{ext}
 * date defaults to today (local calendar date).
 */
function buildExportFilename({ sectionName, domain, ext, date }) {
  const d = date || new Date();
  const pad = (n) => String(n).padStart(2, '0');
  const dateStr = `${d.getFullYear()}-${pad(d.getMonth() + 1)}-${pad(d.getDate())}`;
  const base = sanitizeFilename(sectionName) || 'export';
  return `${base}_${domain}_${dateStr}.${ext}`;
}

/**
 * Set Content-Type + RFC 5987 Content-Disposition download headers.
 */
function setDownloadHeaders(res, filename, mimeType) {
  res.setHeader('Content-Type', mimeType);
  res.setHeader(
    'Content-Disposition',
    `attachment; filename="${filename}"; filename*=UTF-8''${encodeURIComponent(filename)}`
  );
}

// ── Section meta / ownership ────────────────────────────────────────────────

/**
 * Fetch { name, course_code, term, semester, school_year, instructor_id }
 * for a section, or null. The extra term/semester/school_year fields feed
 * the PDF visual report cover page (backend/services/pdfReport.js).
 */
async function getSectionMeta(sectionId) {
  const { rows } = await db.query(
    'SELECT name, course_code, term, semester, school_year, instructor_id FROM sections WHERE id = $1',
    [sectionId]
  );
  return rows.length ? rows[0] : null;
}

/**
 * Verify that an instructor owns the given section.
 * Throws AppError 404 NOT_FOUND for a missing section and
 * AppError 403 FORBIDDEN when the section belongs to someone else.
 */
async function assertInstructorOwnsSection(sectionId, instructorId) {
  const owned = await db.query(
    'SELECT 1 FROM sections WHERE id = $1 AND instructor_id = $2',
    [sectionId, instructorId]
  );
  if (owned.rows.length) return true;

  const exists = await db.query('SELECT 1 FROM sections WHERE id = $1', [sectionId]);
  if (!exists.rows.length) {
    throw new AppError('Section not found', 404, codes.NOT_FOUND);
  }
  throw new AppError('Access denied: section does not belong to this instructor', 403, codes.FORBIDDEN);
}

// ── Value formatters (CSV/XLSX) ─────────────────────────────────────────────

function formatPassed(value) {
  if (value === null || value === undefined) return '';
  return value ? 'Yes' : 'No';
}

/** Numeric CDS percent 0–100 ("85.0") — canonical submissions column. */
function formatCdsPercent(value) {
  if (value === null || value === undefined) return '';
  return (Number(value) * 100).toFixed(1);
}

/** Legacy CDS percent string ("85.0%") — legacy alias column. */
function formatCdsPercentString(value) {
  if (value === null || value === undefined) return '';
  return `${(Number(value) * 100).toFixed(1)}%`;
}

/** ISO-8601 date (YYYY-MM-DD) using the local calendar date of the value. */
function formatIsoDate(value) {
  if (!value) return '';
  const d = value instanceof Date ? value : new Date(value);
  if (Number.isNaN(d.getTime())) return '';
  const pad = (n) => String(n).padStart(2, '0');
  return `${d.getFullYear()}-${pad(d.getMonth() + 1)}-${pad(d.getDate())}`;
}

/** Full ISO-8601 timestamp (UTC, e.g. "2026-03-01T12:00:00.000Z"). */
function formatIsoTimestamp(value) {
  if (!value) return '';
  const d = value instanceof Date ? value : new Date(value);
  if (Number.isNaN(d.getTime())) return '';
  return d.toISOString();
}

function formatSource(value) {
  if (value === null || value === undefined) return '';
  if (Array.isArray(value)) return value.join('; ');
  return String(value);
}

function formatEvidence(value) {
  if (value === null || value === undefined) return '';
  if (typeof value === 'string') return value;
  return JSON.stringify(value);
}

// ── Domain definitions ──────────────────────────────────────────────────────

const ROSTER_COLUMNS = [
  { key: 'name', header: 'Name', width: 30 },
  { key: 'email', header: 'Email', width: 40 },
  { key: 'enrolled_at', header: 'Enrolled At', width: 20, format: formatIsoDate },
];

const SUBMISSIONS_COLUMNS = [
  { key: 'name', header: 'Student Name', width: 25 },
  { key: 'email', header: 'Email', width: 35 },
  { key: 'title', header: 'Exercise', width: 30 },
  { key: 'attempt_number', header: 'Attempt', width: 10 },
  { key: 'passed', header: 'Passed', width: 10, format: formatPassed },
  { key: 'cds', header: 'CDS (%)', width: 12, format: formatCdsPercent, numeric: true },
  { key: 'submitted', header: 'Submitted', width: 25, format: formatIsoTimestamp },
  { key: 'code', header: 'Code', width: 60 },
];

/**
 * Legacy submissions shape — byte-compatible with the pre-overhaul
 * /api/export/section/:sectionId output: exactly 7 columns, CDS emitted as
 * a "12.3%" string (fixes applied: ISO-8601 dates, BOM, ownership guard).
 */
const SUBMISSIONS_LEGACY_COLUMNS = [
  { key: 'name', header: 'Name', width: 25 },
  { key: 'email', header: 'Email', width: 35 },
  { key: 'title', header: 'Exercise', width: 30 },
  { key: 'attempt_number', header: 'Attempt', width: 10 },
  { key: 'passed', header: 'Passed', width: 10, format: formatPassed },
  { key: 'cds', header: 'CDS', width: 10, format: formatCdsPercentString },
  { key: 'submitted', header: 'Submitted', width: 20, format: formatIsoTimestamp },
];

const INTEGRITY_COLUMNS = [
  { key: 'student_name', header: 'Student', width: 25 },
  { key: 'exercise_title', header: 'Exercise', width: 30 },
  { key: 'flag_type', header: 'Flag Type', width: 25 },
  { key: 'severity', header: 'Severity', width: 12 },
  { key: 'status', header: 'Status', width: 12 },
  { key: 'source', header: 'Source', width: 30, format: formatSource },
  { key: 'created_at', header: 'Created At', width: 25, format: formatIsoTimestamp },
  { key: 'reviewed_at', header: 'Reviewed At', width: 25, format: formatIsoTimestamp },
  { key: 'evidence', header: 'Evidence', width: 50, format: formatEvidence },
];

// ── Domain fetchers ─────────────────────────────────────────────────────────

/** Enrolled students in the section (Name, Email, Enrolled At). */
async function fetchRoster(sectionId, opts = {}) {
  let query = `
    SELECT u.name, u.email, e.enrolled_at
    FROM enrollments e
    JOIN users u ON u.id = e.student_id
    WHERE e.section_id = $1`;
  const values = [sectionId];
  if (opts.studentId) {
    values.push(opts.studentId);
    query += ` AND e.student_id = $${values.length}`;
  }
  query += ' ORDER BY u.name';
  const { rows } = await db.query(query, values);
  return rows;
}

/**
 * Submissions for the section's exercises by enrolled students.
 * opts.legacyShape mirrors the pre-overhaul /api/export/section/:sectionId
 * join (every enrolled student incl. those without submissions; submitted
 * timestamp from created_at) while the canonical shape uses submitted_at.
 */
async function fetchSubmissions(sectionId, opts = {}) {
  const legacy = opts.legacyShape === true;
  const dateCol = legacy ? 's.created_at' : 's.submitted_at';
  const values = [sectionId];

  let query;
  if (legacy) {
    query = `
      SELECT u.name, u.email, ex.title, s.attempt_number, s.is_correct AS passed,
             s.cds, s.created_at AS submitted, s.code
      FROM enrollments en
      JOIN users u ON u.id = en.student_id
      LEFT JOIN submissions s ON s.student_id = u.id
      LEFT JOIN exercises ex ON ex.id = s.exercise_id
      WHERE en.section_id = $1`;
  } else {
    query = `
      SELECT u.name, u.email, ex.title, s.attempt_number, s.is_correct AS passed,
             s.cds, s.submitted_at AS submitted, s.code
      FROM submissions s
      JOIN users u ON u.id = s.student_id
      JOIN exercises ex ON ex.id = s.exercise_id
      WHERE ex.section_id = $1
        AND s.student_id IN (SELECT student_id FROM enrollments WHERE section_id = $1)`;
  }

  if (opts.studentId) {
    values.push(opts.studentId);
    query += ` AND s.student_id = $${values.length}`;
  }
  if (opts.startDate) {
    values.push(opts.startDate);
    query += ` AND ${dateCol} >= $${values.length}`;
  }
  if (opts.endDate) {
    values.push(opts.endDate);
    query += ` AND ${dateCol} <= $${values.length}`;
  }
  query += ` ORDER BY u.name, ${dateCol}` + (legacy ? '' : ', s.id');

  const { rows } = await db.query(query, values);
  // pg returns DECIMAL as a string; normalize cds to a number (0–1) for
  // numeric cells and raw-fidelity JSON output.
  return rows.map((row) => ({
    ...row,
    cds: row.cds === null || row.cds === undefined ? null : Number(row.cds),
  }));
}

/** Integrity flags for the section (mirrors integrityFlagEngine.getFlagsForSection). */
async function fetchIntegrity(sectionId, opts = {}) {
  let query = `
    SELECT f.id, f.flag_type, f.severity, f.evidence, f.context_behaviors,
           f.context_behaviors AS source, f.status,
           f.instructor_note, f.created_at, f.reviewed_at, f.submission_id, f.run_id,
           u.name AS student_name, u.id AS student_id,
           e.title AS exercise_title, e.id AS exercise_id
    FROM integrity_flags f
    JOIN users u ON f.student_id = u.id
    JOIN exercises e ON f.exercise_id = e.id
    WHERE f.section_id = $1`;
  const values = [sectionId];
  if (opts.studentId) {
    values.push(opts.studentId);
    query += ` AND f.student_id = $${values.length}`;
  }
  if (opts.startDate) {
    values.push(opts.startDate);
    query += ` AND f.created_at >= $${values.length}`;
  }
  if (opts.endDate) {
    values.push(opts.endDate);
    query += ` AND f.created_at <= $${values.length}`;
  }
  query += ' ORDER BY e.id, f.severity DESC, f.created_at DESC, f.id';
  const { rows } = await db.query(query, values);
  return rows;
}

// ── Phase 2: concept mastery / completion / longitudinal domains ────────────

const CONCEPT_MASTERY_COLUMNS = [
  { key: 'name', header: 'Student Name', width: 25 },
  { key: 'email', header: 'Email', width: 35 },
  { key: 'concept', header: 'Concept', width: 30 },
  { key: 'cmi', header: 'Concept Mastery Index', width: 12, numeric: true },
  { key: 'velocity', header: 'Mastery Velocity', width: 12, numeric: true },
  { key: 'last_updated', header: 'Last Updated', width: 25, format: formatIsoTimestamp },
];

/** Concept × student CMI/velocity (mirrors analyticsController.getConceptMasteryReport). */
async function fetchConceptMastery(sectionId, opts = {}) {
  let query = `
    SELECT u.name, u.email, c.name AS concept, scm.cmi, scm.velocity, scm.last_updated
    FROM student_concept_metrics scm
    JOIN users u ON u.id = scm.student_id
    JOIN concepts c ON c.id = scm.concept_id
    WHERE scm.section_id = $1`;
  const values = [sectionId];
  if (opts.studentId) {
    values.push(opts.studentId);
    query += ` AND scm.student_id = $${values.length}`;
  }
  if (opts.startDate) {
    values.push(opts.startDate);
    query += ` AND scm.last_updated >= $${values.length}`;
  }
  if (opts.endDate) {
    values.push(opts.endDate);
    query += ` AND scm.last_updated <= $${values.length}`;
  }
  query += ' ORDER BY u.name, c.name';
  const { rows } = await db.query(query, values);
  // pg returns DECIMAL as a string; normalize CMI/velocity to numbers.
  return rows.map((row) => ({
    ...row,
    cmi: row.cmi === null || row.cmi === undefined ? null : Number(row.cmi),
    velocity: row.velocity === null || row.velocity === undefined ? null : Number(row.velocity),
  }));
}

const COMPLETION_COLUMNS = [
  { key: 'exercise', header: 'Exercise', width: 40 },
  { key: 'on_time', header: 'On-Time (%)', width: 15, numeric: true },
  { key: 'late', header: 'Late (%)', width: 12, numeric: true },
  { key: 'missing', header: 'Missing (%)', width: 15, numeric: true },
];

/**
 * Per-exercise completion percentages over enrolled students
 * (mirrors analyticsController.getCompletionReport: on-time/late/missing).
 */
async function fetchCompletion(sectionId, opts = {}) {
  let join = 'LEFT JOIN submissions sub ON sub.exercise_id = ex.id';
  const values = [sectionId];
  if (opts.studentId) {
    values.push(opts.studentId);
    join += ` AND sub.student_id = $${values.length}`;
  }
  if (opts.startDate) {
    values.push(opts.startDate);
    join += ` AND sub.submitted_at >= $${values.length}`;
  }
  if (opts.endDate) {
    values.push(opts.endDate);
    join += ` AND sub.submitted_at <= $${values.length}`;
  }
  const { rows } = await db.query(
    `SELECT ex.title AS exercise,
            COUNT(DISTINCT sub.student_id) AS submitted,
            (SELECT COUNT(*) FROM enrollments WHERE section_id = $1) AS total,
            COUNT(DISTINCT CASE WHEN ex.deadline IS NULL OR sub.submitted_at <= ex.deadline THEN sub.student_id END) AS on_time,
            COUNT(DISTINCT CASE WHEN ex.deadline IS NOT NULL AND sub.submitted_at > ex.deadline THEN sub.student_id END) AS late
     FROM exercises ex
     ${join}
     WHERE ex.section_id = $1
     GROUP BY ex.id, ex.title, ex.created_at
     ORDER BY ex.created_at DESC, ex.id DESC
     LIMIT 25001`,
    values
  );
  return rows.map((row) => {
    const total = Number(row.total) || 1;
    const onTime = Number(row.on_time) || 0;
    const late = Number(row.late) || 0;
    const submitted = Number(row.submitted) || 0;
    const missing = Math.max(0, total - submitted);
    return {
      exercise: row.exercise,
      on_time: Math.round((onTime / total) * 100),
      late: Math.round((late / total) * 100),
      missing: Math.round((missing / total) * 100),
    };
  });
}

const LONGITUDINAL_COLUMNS = [
  { key: 'name', header: 'Student Name', width: 25 },
  { key: 'email', header: 'Email', width: 35 },
  { key: 'progression', header: 'Progression', width: 80, format: formatEvidence },
  { key: 'mastery_velocity', header: 'Mastery Velocity', width: 18 },
];

/** Per-student CDS progression + mastery velocity (mirrors analyticsController.getSectionLongitudinal). */
async function fetchLongitudinal(sectionId, opts = {}) {
  // Date filters live in the LEFT JOIN's ON clause so students with no in-range
  // scores still appear (mirrors analyticsController.getSectionLongitudinal).
  let csJoin = 'LEFT JOIN cds_scores cs ON cs.student_id = u.id AND cs.section_id = $1';
  const values = [sectionId];
  if (opts.startDate) {
    values.push(opts.startDate);
    csJoin += ` AND cs.computed_at >= $${values.length}`;
  }
  if (opts.endDate) {
    values.push(opts.endDate);
    csJoin += ` AND cs.computed_at <= $${values.length}`;
  }
  let where = 'WHERE e.section_id = $1';
  if (opts.studentId) {
    values.push(opts.studentId);
    where += ` AND u.id = $${values.length}`;
  }
  const query = `
    SELECT u.id AS student_id, u.name, u.email,
           cs.cds, cs.classification, cs.computed_at,
           ex.title AS exercise_title, ex.id AS exercise_id,
           c.id AS concept_id, c.name AS concept_name
    FROM users u
    JOIN enrollments e ON e.student_id = u.id
    ${csJoin}
    LEFT JOIN exercises ex ON cs.exercise_id = ex.id
    LEFT JOIN concepts c ON ex.concept_id = c.id
    ${where}
    ORDER BY u.name, cs.computed_at ASC`;
  const { rows } = await db.query(query, values);

  const studentMap = {};
  for (const row of rows) {
    if (!studentMap[row.student_id]) {
      // Keep student_id on the row: pdfReport's per-student loop keys on it,
      // and buildStudentReport matches longitudinal rows by student_id.
      studentMap[row.student_id] = { student_id: row.student_id, name: row.name, email: row.email, progression: [] };
    }
    if (row.cds !== null) {
      studentMap[row.student_id].progression.push({
        cds: Number(row.cds),
        classification: row.classification,
        computed_at: row.computed_at,
        exercise_title: row.exercise_title,
        exercise_id: row.exercise_id,
        concept_id: row.concept_id,
        concept_name: row.concept_name,
      });
    }
  }
  return Object.values(studentMap).map((student) => {
    const { progression } = student;
    let masteryVelocity = 'stable';
    if (progression.length >= 2) {
      const recent = progression.slice(-3);
      const cdsValues = recent.map((p) => p.cds);
      const trend = cdsValues[cdsValues.length - 1] - cdsValues[0];
      if (trend > 0.1) masteryVelocity = 'improving';
      else if (trend < -0.1) masteryVelocity = 'declining';
    }
    return { ...student, mastery_velocity: masteryVelocity };
  });
}

// ── Phase 2b: cds / heatmap / behavioral / catalog / settings / alerts ──────

const CDS_COLUMNS = [
  { key: 'name', header: 'Student Name', width: 25 },
  { key: 'email', header: 'Email', width: 35 },
  { key: 'date', header: 'Date', width: 14, format: formatIsoDate },
  { key: 'cds', header: 'CDS (%)', width: 12, format: formatCdsPercent, numeric: true },
  { key: 'classification', header: 'Classification', width: 20 },
];

/**
 * CDS history — one row per student per calendar day (latest score of the
 * day; null/unscored rows dropped).
 */
async function fetchCds(sectionId, opts = {}) {
  let query = `
    SELECT t.name, t.email, t.date, t.cds, t.classification
    FROM (
      SELECT DISTINCT ON (u.id, cs.computed_at::date)
             u.name, u.email, cs.computed_at::date AS date, cs.cds, cs.classification
      FROM cds_scores cs
      JOIN users u ON u.id = cs.student_id
      WHERE cs.section_id = $1
        AND cs.cds IS NOT NULL`;
  const values = [sectionId];
  if (opts.studentId) {
    values.push(opts.studentId);
    query += ` AND cs.student_id = $${values.length}`;
  }
  if (opts.startDate) {
    values.push(opts.startDate);
    query += ` AND cs.computed_at >= $${values.length}`;
  }
  if (opts.endDate) {
    values.push(opts.endDate);
    query += ` AND cs.computed_at <= $${values.length}`;
  }
  query += `
      ORDER BY u.id, cs.computed_at::date, cs.computed_at DESC, cs.id DESC
    ) t
    ORDER BY t.name, t.date
    LIMIT 25001`;
  const { rows } = await db.query(query, values);
  // pg returns DECIMAL as a string; normalize cds to a number (0–1) for
  // numeric cells and raw-fidelity JSON output.
  return rows.map((row) => ({
    ...row,
    cds: row.cds === null || row.cds === undefined ? null : Number(row.cds),
  }));
}

const HEATMAP_COLUMNS = [
  { key: 'name', header: 'Student Name', width: 25 },
  { key: 'date', header: 'Date', width: 14, format: formatIsoDate },
  { key: 'events', header: 'Events', width: 12, numeric: true },
];

/**
 * Daily submission activity — one row per (student, local calendar date)
 * with an event count. Date bucketing matches the analytics daily-trend
 * pattern (submitted_at::date); section scoping mirrors the heatmap
 * where-clause (exercises join + enrollment guard).
 */
async function fetchHeatmap(sectionId, opts = {}) {
  let query = `
    SELECT u.name, s.submitted_at::date AS date, COUNT(*)::INTEGER AS events
    FROM submissions s
    JOIN users u ON u.id = s.student_id
    JOIN exercises ex ON ex.id = s.exercise_id
    WHERE ex.section_id = $1
      AND s.student_id IN (SELECT student_id FROM enrollments WHERE section_id = $1)`;
  const values = [sectionId];
  if (opts.studentId) {
    values.push(opts.studentId);
    query += ` AND s.student_id = $${values.length}`;
  }
  if (opts.startDate) {
    values.push(opts.startDate);
    query += ` AND s.submitted_at >= $${values.length}`;
  }
  if (opts.endDate) {
    values.push(opts.endDate);
    query += ` AND s.submitted_at <= $${values.length}`;
  }
  query += ' GROUP BY u.name, u.id, s.submitted_at::date ORDER BY u.name, s.submitted_at::date LIMIT 25001';
  const { rows } = await db.query(query, values);
  return rows;
}

const BEHAVIORAL_COLUMNS = [
  { key: 'name', header: 'Student Name', width: 25 },
  { key: 'event_type', header: 'Event Type', width: 25 },
  { key: 'timestamp', header: 'Timestamp', width: 25, format: formatIsoTimestamp },
  { key: 'payload', header: 'Payload', width: 60, format: formatEvidence },
];

/**
 * Behavioral telemetry for the section's exercises (tab_switch / paste /
 * warning_* events logged to behavioral_events by /run and the integrity
 * warning pipeline). Payload is native JSONB in JSON output and stringified
 * in CSV/XLSX via formatEvidence.
 */
async function fetchBehavioral(sectionId, opts = {}) {
  let query = `
    SELECT u.name, be.event_type, be.occurred_at AS timestamp, be.payload
    FROM behavioral_events be
    JOIN users u ON u.id = be.student_id
    JOIN exercises ex ON ex.id = be.exercise_id
    WHERE ex.section_id = $1
      AND be.student_id IN (SELECT student_id FROM enrollments WHERE section_id = $1)`;
  const values = [sectionId];
  if (opts.studentId) {
    values.push(opts.studentId);
    query += ` AND be.student_id = $${values.length}`;
  }
  if (opts.startDate) {
    values.push(opts.startDate);
    query += ` AND be.occurred_at >= $${values.length}`;
  }
  if (opts.endDate) {
    values.push(opts.endDate);
    query += ` AND be.occurred_at <= $${values.length}`;
  }
  query += ' ORDER BY be.occurred_at DESC, be.id DESC LIMIT 25001';
  const { rows } = await db.query(query, values);
  return rows;
}

const CATALOG_COLUMNS = [
  { key: 'exercise', header: 'Exercise', width: 40 },
  { key: 'description', header: 'Description', width: 60 },
  { key: 'starter_code', header: 'Starter Code', width: 60 },
  { key: 'time_limit', header: 'Time Limit (sec)', width: 16, numeric: true },
  { key: 'concept', header: 'Concept/Topic', width: 25 },
];

/**
 * Section exercise catalog (title, description, starter code, time limit,
 * concept). Starter code ships as raw multiline text — the CSV cell round-
 * trip stress case. Static content: studentId/date filters intentionally
 * skipped.
 */
async function fetchCatalog(sectionId, opts = {}) {
  const { rows } = await db.query(
    `SELECT ex.title AS exercise, ex.description, ex.starter_code,
            ex.time_limit_minutes * 60 AS time_limit,
            c.name AS concept
     FROM exercises ex
     LEFT JOIN concepts c ON c.id = ex.concept_id
     WHERE ex.section_id = $1
     ORDER BY ex.title, ex.id
     LIMIT 25001`,
    [sectionId]
  );
  return rows;
}

const SETTINGS_COLUMNS = [
  { key: 'section', header: 'Section', width: 30 },
  { key: 'course_code', header: 'Course Code', width: 15 },
  { key: 'term', header: 'Term', width: 15 },
  { key: 'instructor', header: 'Instructor', width: 25 },
  { key: 'semester', header: 'Semester', width: 15 },
  { key: 'join_policy', header: 'Join Policy', width: 15 },
  { key: 'max_size', header: 'Max Size', width: 12, numeric: true },
];

/**
 * One-row settings snapshot of the section's scalar configuration columns
 * (term/semester/policy/size from the sections row). Static content:
 * studentId/date filters intentionally skipped.
 */
async function fetchSettings(sectionId, opts = {}) {
  const { rows } = await db.query(
    `SELECT s.name AS section, s.course_code, s.term, s.semester,
            s.join_policy, s.max_size, u.name AS instructor
     FROM sections s
     LEFT JOIN users u ON u.id = s.instructor_id
     WHERE s.id = $1
     LIMIT 25001`,
    [sectionId]
  );
  return rows;
}

const ALERTS_COLUMNS = [
  { key: 'name', header: 'Student Name', width: 25 },
  { key: 'alert_type', header: 'Alert Type', width: 20 },
  { key: 'severity', header: 'Severity', width: 12 },
  { key: 'status', header: 'Status', width: 14, format: formatReviewStatus },
  { key: 'details', header: 'Message/Details', width: 50, format: formatAlertDetails },
  { key: 'created_at', header: 'Created At', width: 25, format: formatIsoTimestamp },
];

/** Review lifecycle for alert rows: true → 'reviewed', false → 'unreviewed'. */
function formatReviewStatus(value) {
  if (value === null || value === undefined) return '';
  return value ? 'reviewed' : 'unreviewed';
}

/** Human-readable alert detail line composed from the raw score row. */
function formatAlertDetails(value, row) {
  const parts = [];
  if (row.cds_score !== null && row.cds_score !== undefined) {
    parts.push(`CDS ${(Number(row.cds_score) * 100).toFixed(1)}%`);
  }
  if (row.concept_name) parts.push(`Concept: ${row.concept_name}`);
  if (row.exercise_title) parts.push(`Exercise: ${row.exercise_title}`);
  return parts.join('; ');
}

/**
 * Alerts for the section (alerts table, mirroring the dashboard alert query
 * in analyticsEngine.getDashboardAlerts: severity derived from the same CASE
 * over classification/cds_score, review status from is_reviewed).
 */
async function fetchAlerts(sectionId, opts = {}) {
  let query = `
    SELECT u.name,
           al.classification AS alert_type,
           CASE
             WHEN al.classification = 'RETRY_STORM' THEN 'high'
             WHEN al.classification = 'LEARNING_PLATEAU' THEN 'moderate'
             WHEN al.cds_score > 0.80 THEN 'critical'
             WHEN al.cds_score > 0.60 THEN 'high'
             WHEN al.cds_score > 0.40 THEN 'moderate'
             ELSE 'low'
           END AS severity,
           al.is_reviewed AS status,
           al.cds_score, al.concept_name, ex.title AS exercise_title,
           al.created_at
    FROM alerts al
    JOIN users u ON u.id = al.student_id
    JOIN exercises ex ON ex.id = al.exercise_id
    WHERE al.section_id = $1`;
  const values = [sectionId];
  if (opts.studentId) {
    values.push(opts.studentId);
    query += ` AND al.student_id = $${values.length}`;
  }
  if (opts.startDate) {
    values.push(opts.startDate);
    query += ` AND al.created_at >= $${values.length}`;
  }
  if (opts.endDate) {
    values.push(opts.endDate);
    query += ` AND al.created_at <= $${values.length}`;
  }
  query += ` ORDER BY
      CASE
        WHEN al.classification = 'RETRY_STORM' THEN 1
        WHEN al.cds_score > 0.80 THEN 2
        WHEN al.cds_score > 0.60 THEN 3
        WHEN al.classification = 'LEARNING_PLATEAU' THEN 4
        ELSE 5
      END,
      al.cds_score DESC NULLS LAST, al.created_at DESC, al.id DESC
    LIMIT 25001`;
  const { rows } = await db.query(query, values);
  // pg returns DECIMAL as a string; normalize cds_score to a number.
  return rows.map((row) => ({
    ...row,
    cds_score: row.cds_score === null || row.cds_score === undefined ? null : Number(row.cds_score),
  }));
}


const DOMAINS = {
  roster: {
    fetch: fetchRoster,
    columns: ROSTER_COLUMNS,
    sheetName: 'roster',
  },
  submissions: {
    fetch: fetchSubmissions,
    columns: SUBMISSIONS_COLUMNS,
    legacyColumns: SUBMISSIONS_LEGACY_COLUMNS,
    sheetName: 'submissions',
  },
  integrity: {
    fetch: fetchIntegrity,
    columns: INTEGRITY_COLUMNS,
    sheetName: 'integrity',
  },
  concept_mastery: {
    fetch: fetchConceptMastery,
    columns: CONCEPT_MASTERY_COLUMNS,
    sheetName: 'concept_mastery',
  },
  completion: {
    fetch: fetchCompletion,
    columns: COMPLETION_COLUMNS,
    sheetName: 'completion',
  },
  longitudinal: {
    fetch: fetchLongitudinal,
    columns: LONGITUDINAL_COLUMNS,
    sheetName: 'longitudinal',
  },
  cds: {
    fetch: fetchCds,
    columns: CDS_COLUMNS,
    sheetName: 'cds',
  },
  heatmap: {
    fetch: fetchHeatmap,
    columns: HEATMAP_COLUMNS,
    sheetName: 'heatmap',
  },
  behavioral: {
    fetch: fetchBehavioral,
    columns: BEHAVIORAL_COLUMNS,
    sheetName: 'behavioral',
  },
  catalog: {
    fetch: fetchCatalog,
    columns: CATALOG_COLUMNS,
    sheetName: 'catalog',
  },
  settings: {
    fetch: fetchSettings,
    columns: SETTINGS_COLUMNS,
    sheetName: 'settings',
  },
  alerts: {
    fetch: fetchAlerts,
    columns: ALERTS_COLUMNS,
    sheetName: 'alerts',
  },
};

// ── Format dispatch ─────────────────────────────────────────────────────────

/** Fetch raw rows for a domain (throws 400 for unknown domains). */
async function fetchRows(domain, sectionId, opts = {}) {
  const def = DOMAINS[domain];
  if (!def) {
    throw new AppError(`Unknown export domain: ${domain}`, 400, codes.VALIDATION);
  }
  return def.fetch(sectionId, opts);
}

/** Build a single-sheet XLSX workbook buffer (header bold, row 1 frozen). */
async function buildXlsx(def, rows, opts = {}) {
  const columns = opts.legacyShape && def.legacyColumns ? def.legacyColumns : def.columns;
  const workbook = new ExcelJS.Workbook();
  const worksheet = workbook.addWorksheet(def.sheetName);
  worksheet.columns = columns.map((col) => ({ header: col.header, key: col.key, width: col.width }));

  const headerRow = worksheet.getRow(1);
  headerRow.eachCell((cell) => {
    cell.font = { bold: true };
  });
  worksheet.views = [{ state: 'frozen', ySplit: 1 }];

  for (const row of rows) {
    const record = {};
    for (const col of columns) {
      let value = row[col.key];
      if (col.format) value = col.format(value, row);
      if (col.numeric && value !== '') value = Number(value);
      record[col.key] = value;
    }
    worksheet.addRow(record);
  }

  return workbook.xlsx.writeBuffer();
}

/**
 * Produce an export for a domain in the given format.
 * Returns { buffer, mimeType, filename, extension }.
 * Enforces the 25,000-row cap (AppError 413 TOO_LARGE).
 */
async function formatExport(domain, sectionId, format, opts = {}) {
  const def = DOMAINS[domain];
  if (!def) {
    throw new AppError(`Unknown export domain: ${domain}`, 400, codes.VALIDATION);
  }
  if (!EXPORT_FORMATS.includes(format)) {
    throw new AppError(`Unsupported export format: ${format}`, 400, codes.VALIDATION);
  }

  const rows = await def.fetch(sectionId, opts);
  if (rows.length > MAX_EXPORT_ROWS) {
    throw new AppError(
      `Export of domain "${domain}" exceeds the ${MAX_EXPORT_ROWS}-row limit. ` +
        'Narrow the export with date/student filters or contact an administrator.',
      413,
      'TOO_LARGE'
    );
  }

  const meta = await getSectionMeta(sectionId);
  const sectionName = meta ? meta.name : String(sectionId);
  const filename = buildExportFilename({ sectionName, domain, ext: format });
  const mimeType = MIME_TYPES[format];

  let buffer;
  if (format === 'csv') {
    buffer = toCsv(rows, opts.legacyShape && def.legacyColumns ? def.legacyColumns : def.columns);
  } else if (format === 'xlsx') {
    buffer = await buildXlsx(def, rows, opts);
  } else {
    buffer = Buffer.from(JSON.stringify(rows), 'utf8');
  }

  return { buffer, mimeType, filename, extension: format };
}

module.exports = {
  DOMAINS,
  EXPORT_FORMATS,
  MAX_EXPORT_ROWS,
  sanitizeFilename,
  buildExportFilename,
  setDownloadHeaders,
  getSectionMeta,
  assertInstructorOwnsSection,
  fetchRows,
  formatExport,
  // Domain fetchers + formatters reused by the PDF report builder
  // (backend/services/pdfReport.js) so PDF generation never duplicates SQL.
  fetchRoster,
  fetchCds,
  fetchConceptMastery,
  fetchHeatmap,
  fetchIntegrity,
  fetchLongitudinal,
  formatIsoDate,
  formatIsoTimestamp,
};
