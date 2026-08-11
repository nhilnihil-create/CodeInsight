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
 * Fetch { name, course_code, instructor_id } for a section, or null.
 */
async function getSectionMeta(sectionId) {
  const { rows } = await db.query(
    'SELECT name, course_code, instructor_id FROM sections WHERE id = $1',
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
};
