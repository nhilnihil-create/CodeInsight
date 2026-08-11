/**
 * backend/services/pdfReport.js
 *
 * PDF "Section Visual Report" — the PDF tier of the export overhaul
 * (Phase 4). Reuses the exportService data fetchers (no duplicated SQL)
 * and the pdfCharts vector primitives (no duplicated drawing math).
 *
 * Page plan (full class report):
 *   1. Cover             — section name, course/term, instructor, generated date
 *   2. Executive summary — class avg CDS, at-risk count (per-student avg
 *                          CDS > 0.60 — the same signal the dashboard uses),
 *                          integrity flag counts by severity, submission total
 *   3. Class overview    — avg-CDS-per-date line chart, student × day activity
 *                          heatmap (≤ 12 rows × ≤ 14 cols), CDS distribution bars
 *   4. Per-student pages — CDS trend line, concept radar, activity heatmap
 *                          snippet. Capped to the top 25 students by activity
 *                          so a full 60-student report stays bounded.
 *   5. Integrity flags table + appendix — zebra-striped wrapped table plus a
 *                          per-student roster-count appendix.
 *
 * Dossier mode (opts.studentId): cover + that student's pages + their flags.
 */

const PDFDocument = require('pdfkit');
const db = require('../config/db');
const { AppError } = require('../lib/AppError');
const {
  fetchRoster,
  fetchCds,
  fetchConceptMastery,
  fetchHeatmap,
  fetchIntegrity,
  fetchLongitudinal,
  getSectionMeta,
  formatIsoDate,
  formatIsoTimestamp,
} = require('./exportService');
const {
  renderLineChart,
  renderBarChart,
  renderRadarChart,
  renderHeatmapGrid,
  cdsColor,
  CDS_STOPS,
} = require('./pdfCharts');

// ── Limits ──────────────────────────────────────────────────────────────────

/** Enrollments beyond this are rejected with 413 TOO_LARGE. */
const MAX_REPORT_STUDENTS = 60;

/**
 * Per-student pages are capped to the 25 most active students (by total
 * heatmap events) so a full 60-student report stays bounded: cover +
 * summary + overview + 2×25 student pages + flags/appendix ≈ 55 pages.
 */
const MAX_STUDENT_PAGES = 25;

/** Class-overview heatmap grid caps (rows = students, cols = days). */
const HEATMAP_MAX_ROWS = 12;
const HEATMAP_MAX_COLS = 14;

/**
 * At-risk threshold. The app's canonical at-risk signal (dashboard banner +
 * at-risk roster in analyticsController) is a per-student AVERAGE CDS above
 * 0.60, so the executive summary uses the same rule.
 */
const AT_RISK_THRESHOLD = 0.60;

// ── Layout constants (A4 points) ────────────────────────────────────────────

const PAGE_WIDTH = 595.28;
const PAGE_HEIGHT = 841.89;
const MARGIN = 40;
const CONTENT_WIDTH = PAGE_WIDTH - MARGIN * 2; // 515.28
const BOTTOM_Y = PAGE_HEIGHT - MARGIN; // 801.89

const INK = '#0f172a';
const MUTED = '#64748b';
const SUBTLE = '#94a3b8';
const BORDER = '#cbd5e1';
const ZEBRA = '#f8fafc';
const HEADER_BG = '#eef2f7';
const ACCENT = '#1a5f50';
const TREND_COLOR = '#1a5f50';
const RADAR_COLOR = '#f59e0b';
const BAR_COLOR = '#10b981';

// ── Small pdfkit helpers ────────────────────────────────────────────────────

function makeDocument() {
  // compress: false keeps content streams plaintext (inspectable, and the
  // DB-backed tests can search decoded text); negligible size impact at
  // this report scale.
  return new PDFDocument({
    size: 'A4',
    margins: { top: MARGIN, bottom: MARGIN, left: MARGIN, right: MARGIN },
    compress: false,
    info: { Producer: 'CodeInsight', Creator: 'CodeInsight Section Visual Report' },
  });
}

/** Wrap doc.end() in a Promise resolving to the assembled Buffer. */
function collectBuffer(doc) {
  return new Promise((resolve, reject) => {
    const chunks = [];
    doc.on('data', (c) => chunks.push(c));
    doc.on('end', () => resolve(Buffer.concat(chunks)));
    doc.on('error', reject);
    doc.end();
  });
}

/** Does `y + needed` still fit inside the bottom margin? */
function fits(y, needed) {
  return y + needed <= BOTTOM_Y;
}

/**
 * Section header: bold title + thin rule. Returns the y below the rule.
 * y defaults to the current doc.y so callers can chain after doc.text().
 */
function pageTitle(doc, title, y = doc.y) {
  doc.save();
  doc.font('Helvetica-Bold').fontSize(14).fillColor(INK);
  doc.text(title, MARGIN, y, { width: CONTENT_WIDTH });
  const ruleY = doc.y + 6;
  doc.strokeColor(BORDER).lineWidth(0.8);
  doc.moveTo(MARGIN, ruleY).lineTo(PAGE_WIDTH - MARGIN, ruleY).stroke();
  doc.restore();
  return ruleY + 12;
}

/** Small sub-section heading above a chart. Returns the y below it. */
function chartTitle(doc, text, y) {
  doc.save();
  doc.font('Helvetica-Bold').fontSize(10).fillColor(INK);
  doc.text(text, MARGIN, y, { width: CONTENT_WIDTH });
  doc.restore();
  return y + 16;
}

/** Label/value line ("At-Risk Students: 3"). Returns the y below it. */
function kvLine(doc, label, value, y, { labelWidth = 130 } = {}) {
  doc.save();
  doc.font('Helvetica-Bold').fontSize(10).fillColor(MUTED);
  doc.text(label, MARGIN, y, { width: labelWidth });
  doc.font('Helvetica').fontSize(10).fillColor(INK);
  doc.text(String(value === null || value === undefined ? '—' : value), MARGIN + labelWidth, y, {
    width: CONTENT_WIDTH - labelWidth,
  });
  doc.restore();
  return y + 16;
}

/** Labeled stat box. */
function statBlock(doc, x, y, w, label, value) {
  doc.save();
  doc.rect(x, y, w, 52).lineWidth(0.8).strokeColor(BORDER).stroke();
  doc.font('Helvetica-Bold').fontSize(18).fillColor(ACCENT);
  doc.text(String(value), x + 10, y + 10, { width: w - 20 });
  doc.font('Helvetica').fontSize(8).fillColor(MUTED);
  doc.text(label, x + 10, y + 34, { width: w - 20 });
  doc.restore();
}

/**
 * Manual table row with wrapped cells. Returns the row height drawn so
 * callers can page-break between rows.
 */
function drawRow(doc, x, y, widths, cells, { bold = false, zebra = false } = {}) {
  const pad = 4;
  doc.save();
  doc.font(bold ? 'Helvetica-Bold' : 'Helvetica').fontSize(8).fillColor(INK);
  const heights = cells.map((c, i) => {
    const text = String(c === null || c === undefined ? '' : c);
    return Math.max(doc.heightOfString(text, { width: widths[i] - pad * 2 }) + pad * 2, 16);
  });
  const rowH = Math.max(...heights);
  const totalW = widths.reduce((a, b) => a + b, 0);

  if (zebra) {
    doc.fillColor(ZEBRA);
    doc.rect(x, y, totalW, rowH).fill();
  }
  if (bold) {
    doc.fillColor(HEADER_BG);
    doc.rect(x, y, totalW, rowH).fill();
  }

  doc.font(bold ? 'Helvetica-Bold' : 'Helvetica').fontSize(8).fillColor(INK);
  let cx = x;
  cells.forEach((c, i) => {
    const text = String(c === null || c === undefined ? '' : c);
    doc.text(text, cx + pad, y + pad, { width: widths[i] - pad * 2 });
    cx += widths[i];
  });

  doc.strokeColor(BORDER).lineWidth(0.4);
  doc.rect(x, y, totalW, rowH).stroke();
  doc.restore();
  return rowH;
}

// ── Data shaping (pure) ─────────────────────────────────────────────────────

/** Per-date average CDS → { labels: [dates], values: [avg] }. */
function avgCdsByDate(cdsRows) {
  const byDate = new Map();
  for (const row of cdsRows) {
    const date = formatIsoDate(row.date);
    const v = Number(row.cds);
    if (!date || !Number.isFinite(v)) continue;
    if (!byDate.has(date)) byDate.set(date, []);
    byDate.get(date).push(v);
  }
  const dates = [...byDate.keys()].sort();
  return {
    labels: dates,
    values: dates.map((d) => {
      const arr = byDate.get(d);
      return arr.reduce((a, b) => a + b, 0) / arr.length;
    }),
  };
}

/** CDS distribution buckets using CDS_STOPS positions as the boundaries. */
function cdsDistribution(cdsRows, stops = CDS_STOPS) {
  const bounds = stops.map((s) => s.pos);
  const buckets = bounds.slice(0, -1).map((_, i) => ({
    label: `${bounds[i].toFixed(1)}–${bounds[i + 1].toFixed(1)}`,
    count: 0,
  }));
  for (const row of cdsRows) {
    const v = Number(row.cds);
    if (!Number.isFinite(v)) continue;
    const idx = buckets.findIndex((b, i) => v >= bounds[i] && v < bounds[i + 1]);
    buckets[idx === -1 ? buckets.length - 1 : idx].count += 1;
  }
  return buckets;
}

/** Count of enrolled students whose average CDS exceeds AT_RISK_THRESHOLD. */
function atRiskCount(cdsRows) {
  const byStudent = new Map();
  for (const row of cdsRows) {
    const v = Number(row.cds);
    if (!Number.isFinite(v)) continue;
    const key = row.email || row.name;
    if (!byStudent.has(key)) byStudent.set(key, []);
    byStudent.get(key).push(v);
  }
  let atRisk = 0;
  for (const values of byStudent.values()) {
    if (values.reduce((a, b) => a + b, 0) / values.length > AT_RISK_THRESHOLD) atRisk += 1;
  }
  return atRisk;
}

/** Integrity flag counts by severity, most severe first. */
function severityCounts(integrityRows) {
  const order = ['critical', 'high', 'medium', 'low'];
  const counts = new Map();
  for (const row of integrityRows) {
    const key = String(row.severity || 'medium').toLowerCase();
    counts.set(key, (counts.get(key) || 0) + 1);
  }
  return [...counts.entries()].sort(
    (a, b) => order.indexOf(a[0]) - order.indexOf(b[0]) || String(a[0]).localeCompare(String(b[0]))
  );
}

/** Total events per student (keyed by email), for activity ranking. */
function studentActivity(heatmapRows) {
  const totals = new Map();
  for (const row of heatmapRows) {
    const key = row.email || row.name;
    totals.set(key, (totals.get(key) || 0) + (Number(row.events) || 0));
  }
  return totals;
}

/**
 * Student × day activity matrix for renderHeatmapGrid. rows = top students
 * by total events (≤ maxRows), cols = most recent days with activity
 * (≤ maxCols). colorFn returns cdsColor(normalized events) — event counts
 * are normalized to 0–1 within the grid and passed through the CDS ramp —
 * or null for a day with no activity (hatched "No Data" cell).
 */
function buildHeatmap(heatmapRows, { maxRows = HEATMAP_MAX_ROWS, maxCols = HEATMAP_MAX_COLS } = {}) {
  const byStudent = new Map();
  let globalMax = 0;
  for (const row of heatmapRows) {
    const key = row.name || row.email;
    if (!byStudent.has(key)) byStudent.set(key, new Map());
    const events = Number(row.events) || 0;
    byStudent.get(key).set(formatIsoDate(row.date), events);
    if (events > globalMax) globalMax = events;
  }
  const ranked = [...byStudent.entries()]
    .map(([name, days]) => ({
      name,
      days,
      total: [...days.values()].reduce((a, b) => a + b, 0),
    }))
    .sort((a, b) => b.total - a.total || String(a.name).localeCompare(String(b.name)))
    .slice(0, maxRows);

  const dates = [...new Set(heatmapRows.map((r) => formatIsoDate(r.date)))].sort().slice(-maxCols);
  const normalize = globalMax > 0 ? (v) => v / globalMax : () => 0;

  return {
    rowLabels: ranked.map((s) => s.name),
    colLabels: dates,
    colorFn: (r, c) => {
      const events = ranked[r].days.get(dates[c]);
      return events === undefined || events === null ? null : cdsColor(normalize(events));
    },
  };
}

/** Concept axes + CMI normalized to 0–1 (CMI is stored 0–100). */
function conceptRadarData(conceptRows, email) {
  const seen = new Map();
  for (const row of conceptRows) {
    if (email && row.email !== email) continue;
    if (!seen.has(row.concept)) seen.set(row.concept, row);
  }
  return {
    axes: [...seen.keys()],
    values: [...seen.values()].map((r) => Math.min(1, Math.max(0, (Number(r.cmi) || 0) / 100))),
  };
}

/**
 * Normalized per-student report bundle. `studentId` filters longitudinal
 * (which carries student_id) and integrity rows; email keys the other
 * fetchers (which carry name/email but no id).
 */
function buildStudentReport(studentId, { cdsRows, conceptRows, heatmapRows, integrityRows, longitudinalRows }) {
  const long = longitudinalRows.find((s) => String(s.student_id) === String(studentId)) || null;
  const email =
    (long && long.email) ||
    (cdsRows[0] && cdsRows[0].email) ||
    (conceptRows[0] && conceptRows[0].email) ||
    (heatmapRows[0] && heatmapRows[0].email) ||
    '';
  const name = (long && long.name) || (cdsRows[0] && cdsRows[0].name) || 'Student';

  const progression = (long && long.progression ? long.progression : []).filter((p) =>
    Number.isFinite(Number(p.cds))
  );

  return {
    studentId,
    name,
    email,
    trendLabels: progression.map((p) => formatIsoDate(p.computed_at)),
    trendValues: progression.map((p) => Number(p.cds)),
    currentCds: progression.length ? Number(progression[progression.length - 1].cds) : null,
    avgCds: progression.length
      ? progression.reduce((a, p) => a + Number(p.cds), 0) / progression.length
      : null,
    velocity: long ? long.mastery_velocity : '—',
    radar: conceptRadarData(conceptRows, email),
    heatmap: buildHeatmap(heatmapRows.filter((r) => r.email === email), { maxRows: 1 }),
    flags: integrityRows.filter((r) => String(r.student_id) === String(studentId)),
  };
}

/**
 * True when a built student report carries any renderable data: a CDS trend,
 * concept radar axes, heatmap rows/columns or integrity flags. Used to skip
 * per-student pages for enrolled students with no activity (they still appear
 * in the appendix roster counts).
 */
function hasStudentData(report) {
  return (
    (report.trendValues && report.trendValues.length > 0) ||
    (report.radar && report.radar.axes && report.radar.axes.length > 0) ||
    (report.heatmap && report.heatmap.rowLabels && report.heatmap.rowLabels.length > 0) ||
    (report.heatmap && report.heatmap.colLabels && report.heatmap.colLabels.length > 0) ||
    (report.flags && report.flags.length > 0)
  );
}

// ── Page renderers ──────────────────────────────────────────────────────────

/** Page 1 — cover. */
function drawCover(doc, meta, instructor) {
  const title = (meta && meta.name) || 'Section';
  const course = meta && meta.course_code ? meta.course_code : '—';
  const term = [meta && meta.term, meta && meta.semester, meta && meta.school_year]
    .filter((p) => p)
    .join(' · ');

  const y0 = 200;
  doc.save();
  doc.font('Helvetica-Bold').fontSize(26).fillColor(INK);
  doc.text(title, MARGIN, y0, { width: CONTENT_WIDTH, align: 'center' });
  doc.font('Helvetica').fontSize(13).fillColor(MUTED);
  doc.text(`${course}${term ? ` — ${term}` : ''}`, MARGIN, y0 + 44, { width: CONTENT_WIDTH, align: 'center' });
  doc.text(`Instructor: ${instructor}`, MARGIN, y0 + 72, { width: CONTENT_WIDTH, align: 'center' });
  doc.font('Helvetica').fontSize(10).fillColor(SUBTLE);
  doc.text(`Generated ${formatIsoDate(new Date())}`, MARGIN, y0 + 96, { width: CONTENT_WIDTH, align: 'center' });
  doc.restore();
}

/** Page 2 — executive summary. */
function drawExecutiveSummary(doc, { cdsRows, integrityRows, submissionCount }) {
  doc.addPage();
  let y = pageTitle(doc, 'Executive Summary', MARGIN);

  const cdsValues = cdsRows.map((r) => Number(r.cds)).filter(Number.isFinite);
  const avgCds = cdsValues.length ? cdsValues.reduce((a, b) => a + b, 0) / cdsValues.length : 0;
  const atRisk = atRiskCount(cdsRows);

  const blocks = [
    { label: 'Class Avg CDS', value: avgCds.toFixed(2) },
    { label: 'At-Risk Students', value: String(atRisk) },
    { label: 'Integrity Flags', value: String(integrityRows.length) },
    { label: 'Total Submissions', value: String(submissionCount) },
  ];
  const bw = (CONTENT_WIDTH - 3 * 12) / 4;
  blocks.forEach((b, i) => {
    statBlock(doc, MARGIN + i * (bw + 12), y, bw, b.label, b.value);
  });
  y += 52 + 20;

  y = pageTitle(doc, 'Integrity Flags by Severity', y);
  const counts = severityCounts(integrityRows);
  if (counts.length === 0) {
    doc.save();
    doc.font('Helvetica').fontSize(10).fillColor(MUTED);
    doc.text('No integrity flags recorded.', MARGIN, y);
    doc.restore();
    return;
  }
  const widths = [300, 100];
  y += drawRow(doc, MARGIN, y, widths, ['Severity', 'Flags'], { bold: true });
  counts.forEach(([severity, count], i) => {
    if (!fits(y, 18)) {
      doc.addPage();
      y = pageTitle(doc, 'Integrity Flags by Severity', MARGIN);
      y += drawRow(doc, MARGIN, y, widths, ['Severity', 'Flags'], { bold: true });
    }
    y += drawRow(doc, MARGIN, y, widths, [severity, String(count)], { zebra: i % 2 === 1 });
  });
}

/** Page 3 — class overview: avg-CDS line, CDS distribution bars, heatmap. */
function drawClassOverview(doc, { cdsRows, heatmapRows }) {
  doc.addPage();
  let y = pageTitle(doc, 'Class Overview', MARGIN);

  const trend = avgCdsByDate(cdsRows);
  y = chartTitle(doc, 'Average CDS by date', y);
  renderLineChart(doc, {
    x: MARGIN,
    y,
    w: CONTENT_WIDTH,
    h: 140,
    series: [trend.values],
    labels: trend.labels,
    color: TREND_COLOR,
  });
  y += 140 + 24;

  const dist = cdsDistribution(cdsRows);
  y = chartTitle(doc, 'CDS distribution', y);
  renderBarChart(doc, {
    x: MARGIN,
    y,
    w: CONTENT_WIDTH,
    h: 110,
    values: dist.map((b) => b.count),
    labels: dist.map((b) => b.label),
    colors: CDS_STOPS.map((s) => cdsColor(s.pos)),
    color: BAR_COLOR,
  });
  y += 110 + 24;

  const hm = buildHeatmap(heatmapRows);
  y = chartTitle(doc, 'Daily activity heatmap (normalized events, CDS ramp)', y);
  const cellW = Math.min(34, (CONTENT_WIDTH - 64) / Math.max(hm.colLabels.length, 1));
  const cellH = 20;
  const gridH = cellH * hm.rowLabels.length;
  if (!fits(y, gridH + 18)) {
    doc.addPage();
    y = pageTitle(doc, 'Daily activity heatmap', MARGIN);
  }
  renderHeatmapGrid(doc, {
    x: MARGIN + 64,
    y,
    cellW,
    cellH,
    rows: hm.rowLabels.length,
    cols: hm.colLabels.length,
    colorFn: hm.colorFn,
    rowLabels: hm.rowLabels,
    colLabels: hm.colLabels,
  });
  y += gridH + 18;
  if (!fits(y, 24)) return;
  doc.save();
  doc.font('Helvetica').fontSize(8).fillColor(MUTED);
  doc.text('Cell color follows the CDS ramp on normalized event volume (teal = low activity, rose = high). Rows are the most active students, columns are days.', MARGIN, y, { width: CONTENT_WIDTH });
  doc.restore();
}

/**
 * Per-student pages — two pages each: CDS trend + stats, then concept radar
 * + daily-activity heatmap snippet. Dossier mode additionally appends the
 * student's integrity flags.
 */
function drawStudentPages(doc, student, { dossier = false } = {}) {
  const hasTrend = student.trendValues && student.trendValues.length > 0;
  const hasRadar = student.radar && student.radar.axes && student.radar.axes.length > 0;
  const hasHeat =
    (student.heatmap && student.heatmap.rowLabels && student.heatmap.rowLabels.length > 0) ||
    (student.heatmap && student.heatmap.colLabels && student.heatmap.colLabels.length > 0);
  const hasFlags = student.flags && student.flags.length > 0;

  // Enrolled student with no trend/radar/heatmap data: collapse to a single
  // page — the student's title with either their integrity flags or a
  // no-activity note. The early return also prevents the dossier branch from
  // drawing a flags-only student's flags a second time.
  if (!hasTrend && !hasRadar && !hasHeat) {
    doc.addPage();
    let y = pageTitle(doc, student.name, MARGIN);
    if (hasFlags) {
      y += 12;
      y = drawFlagsTable(doc, student.flags, y);
    } else {
      doc.text('No activity recorded for this student.', MARGIN, y + 12, { width: CONTENT_WIDTH });
    }
    return;
  }

  // Page A — CDS trend.
  doc.addPage();
  let y = pageTitle(doc, student.name, MARGIN);
  y = kvLine(doc, 'Current CDS', student.currentCds === null ? '—' : Number(student.currentCds).toFixed(2), y);
  y = kvLine(doc, 'Average CDS', student.avgCds === null ? '—' : Number(student.avgCds).toFixed(2), y);
  y = kvLine(doc, 'Mastery trend', student.velocity, y);
  y += 8;

  y = chartTitle(doc, 'CDS trend', y);
  renderLineChart(doc, {
    x: MARGIN,
    y,
    w: CONTENT_WIDTH,
    h: 160,
    series: [student.trendValues],
    labels: student.trendLabels,
    color: TREND_COLOR,
  });

  // Page B — concept radar + activity snippet.
  doc.addPage();
  y = pageTitle(doc, 'Concept mastery', MARGIN);
  const center = { x: PAGE_WIDTH / 2, y: y + 115 };
  renderRadarChart(doc, {
    axes: student.radar.axes,
    values: student.radar.values,
    center,
    radius: 95,
    color: RADAR_COLOR,
  });
  y = center.y + 130;

  y = chartTitle(doc, 'Daily activity', y);
  const hm = student.heatmap;
  const cellW = Math.min(34, (CONTENT_WIDTH - 64) / Math.max(hm.colLabels.length, 1));
  const cellH = 22;
  renderHeatmapGrid(doc, {
    x: MARGIN + 64,
    y,
    cellW,
    cellH,
    rows: hm.rowLabels.length,
    cols: hm.colLabels.length,
    colorFn: hm.colorFn,
    rowLabels: hm.rowLabels,
    colLabels: hm.colLabels,
  });

  if (dossier && student.flags.length) {
    doc.addPage();
    y = pageTitle(doc, 'Integrity flags', MARGIN);
    drawFlagsTable(doc, student.flags, y);
  }
}

const FLAG_COLUMNS = ['Student', 'Flag Type', 'Severity', 'Status', 'Created At'];
const FLAG_WIDTHS = [110, 130, 70, 70, 135];

/** Integrity flags table with bold header, zebra rows and wrapped cells. */
function drawFlagsTable(doc, flags, y) {
  y += drawRow(doc, MARGIN, y, FLAG_WIDTHS, FLAG_COLUMNS, { bold: true });
  flags.forEach((row, i) => {
    const cells = [
      row.student_name,
      row.flag_type,
      row.severity,
      row.status,
      formatIsoTimestamp(row.created_at),
    ];
    const sampleH = 20;
    if (!fits(y, sampleH)) {
      doc.addPage();
      y = pageTitle(doc, 'Integrity flags', MARGIN);
      y += drawRow(doc, MARGIN, y, FLAG_WIDTHS, FLAG_COLUMNS, { bold: true });
    }
    y += drawRow(doc, MARGIN, y, FLAG_WIDTHS, cells, { zebra: i % 2 === 1 });
  });
  return y;
}

/** Page 5 — integrity flags table + appendix with per-student roster counts. */
function drawFlagsAndAppendix(doc, { flags, roster, longitudinalRows, enrolledCount, submissionCount, cdsRows }) {
  doc.addPage();
  let y = pageTitle(doc, 'Integrity Flags', MARGIN);

  if (flags.length === 0) {
    doc.save();
    doc.font('Helvetica').fontSize(10).fillColor(MUTED);
    doc.text('No integrity flags recorded for this section.', MARGIN, y);
    doc.restore();
    y += 24;
  } else {
    y = drawFlagsTable(doc, flags, y);
  }

  // Appendix — roster counts.
  y = Math.max(y + 20, doc.y + 20);
  if (!fits(y, 40)) {
    doc.addPage();
    y = MARGIN;
  }
  y = pageTitle(doc, 'Appendix — Roster Counts', y);

  const studentsWithCds = new Set(cdsRows.map((r) => r.email || r.name)).size;
  y = kvLine(doc, 'Enrolled students', String(enrolledCount), y);
  y = kvLine(doc, 'Students with CDS data', String(studentsWithCds), y);
  y = kvLine(doc, 'Total submissions', String(submissionCount), y);
  y = kvLine(doc, 'Integrity flags', String(flags.length), y);
  y += 6;

  const flagsByStudent = new Map();
  for (const row of flags) {
    flagsByStudent.set(String(row.student_id), (flagsByStudent.get(String(row.student_id)) || 0) + 1);
  }
  const longByEmail = new Map(longitudinalRows.map((s) => [s.email, s]));

  const widths = [150, 120, 120, 125];
  y += drawRow(doc, MARGIN, y, widths, ['Student', 'CDS Scores', 'Integrity Flags', 'Mastery Trend'], { bold: true });
  roster.forEach((student, i) => {
    const long = longByEmail.get(student.email);
    const cells = [
      student.name,
      String(long ? long.progression.length : 0),
      String(flagsByStudent.get(long ? String(long.student_id) : '') || 0),
      long ? long.mastery_velocity : '—',
    ];
    if (!fits(y, 20)) {
      doc.addPage();
      y = pageTitle(doc, 'Appendix — Roster Counts', MARGIN);
      y += drawRow(doc, MARGIN, y, widths, ['Student', 'CDS Scores', 'Integrity Flags', 'Mastery Trend'], { bold: true });
    }
    y += drawRow(doc, MARGIN, y, widths, cells, { zebra: i % 2 === 1 });
  });
}

/** Single-page "no data" report for sections without any enrollments. */
function buildNoDataPdf(meta) {
  const doc = makeDocument();
  const name = (meta && meta.name) || 'Section';
  doc.save();
  doc.font('Helvetica-Bold').fontSize(22).fillColor(INK);
  doc.text('No data available', MARGIN, PAGE_HEIGHT / 2 - 40, { width: CONTENT_WIDTH, align: 'center' });
  doc.font('Helvetica').fontSize(11).fillColor(MUTED);
  doc.text(`The visual report for "${name}" is empty — no students are enrolled yet.`, MARGIN, PAGE_HEIGHT / 2 - 6, {
    width: CONTENT_WIDTH,
    align: 'center',
  });
  doc.restore();
  return collectBuffer(doc);
}

async function resolveInstructorName(meta) {
  if (!meta || !meta.instructor_id) return '—';
  const { rows } = await db.query('SELECT name FROM users WHERE id = $1', [meta.instructor_id]);
  return rows.length ? rows[0].name : '—';
}

async function countSubmissions(sectionId) {
  const { rows } = await db.query(
    `SELECT COUNT(*)::int AS count
     FROM submissions s
     JOIN exercises ex ON ex.id = s.exercise_id
     WHERE ex.section_id = $1
       AND s.student_id IN (SELECT student_id FROM enrollments WHERE section_id = $1)`,
    [sectionId]
  );
  return rows[0].count;
}

// ── Public entry point ──────────────────────────────────────────────────────

/**
 * Build the section visual report as a PDF Buffer.
 *
 * Full class report by default; pass opts.studentId for a single-student
 * dossier (cover + that student's pages + their integrity flags).
 * opts.instructorName is optional — when omitted the name is resolved from
 * the sections.instructor_id (fallback '—').
 *
 * Throws AppError 413 TOO_LARGE when the section has more than
 * MAX_REPORT_STUDENTS enrolled students (full reports only — a dossier
 * renders a single student and is unaffected). Sections with no enrollments
 * yield a single-page "No data available" PDF.
 */
async function buildSectionVisualReport(sectionId, { studentId, instructorName } = {}) {
  const meta = await getSectionMeta(sectionId);

  const { rows: countRows } = await db.query(
    'SELECT COUNT(*)::int AS count FROM enrollments WHERE section_id = $1',
    [sectionId]
  );
  const enrolledCount = Number(countRows[0].count);

  // The size guard bounds per-student pages; a dossier only renders one
  // student so a large section does not block it.
  if (!studentId && enrolledCount > MAX_REPORT_STUDENTS) {
    throw new AppError(
      `Section is too large for the visual report (max ${MAX_REPORT_STUDENTS} students).`,
      413,
      'TOO_LARGE'
    );
  }

  if (enrolledCount === 0) {
    return buildNoDataPdf(meta);
  }

  const instructor = instructorName || (await resolveInstructorName(meta));
  const doc = makeDocument();
  drawCover(doc, meta, instructor);

  if (studentId) {
    const [cdsRows, conceptRows, heatmapRows, integrityRows, longitudinalRows] = await Promise.all([
      fetchCds(sectionId, { studentId }),
      fetchConceptMastery(sectionId, { studentId }),
      fetchHeatmap(sectionId, { studentId }),
      fetchIntegrity(sectionId, { studentId }),
      fetchLongitudinal(sectionId, { studentId }),
    ]);

    if (longitudinalRows.length === 0) {
      // studentId is not enrolled in this section — single "no data" page.
      return buildNoDataPdf(meta);
    }

    const student = buildStudentReport(studentId, {
      cdsRows,
      conceptRows,
      heatmapRows,
      integrityRows,
      longitudinalRows,
    });
    drawStudentPages(doc, student, { dossier: true });
    return collectBuffer(doc);
  }

  // Full class report.
  const [cdsRows, conceptRows, heatmapRows, integrityRows, longitudinalRows, submissionCount] = await Promise.all([
    fetchCds(sectionId),
    fetchConceptMastery(sectionId),
    fetchHeatmap(sectionId),
    fetchIntegrity(sectionId),
    fetchLongitudinal(sectionId),
    countSubmissions(sectionId),
  ]);

  drawExecutiveSummary(doc, { cdsRows, integrityRows, submissionCount });
  drawClassOverview(doc, { cdsRows, heatmapRows });

  // Per-student pages: the top students by activity, capped so a full
  // 60-student report stays bounded. longitudinalRows carries student_id,
  // name and email for every enrolled student.
  const activity = studentActivity(heatmapRows);
  const ordered = longitudinalRows
    .map((s) => ({ ...s, activity: activity.get(s.email) || 0 }))
    .sort((a, b) => b.activity - a.activity || String(a.name).localeCompare(String(b.name)))
    .slice(0, MAX_STUDENT_PAGES);

  for (const student of ordered) {
    const report = buildStudentReport(student.student_id, {
      cdsRows,
      conceptRows,
      heatmapRows,
      integrityRows,
      longitudinalRows,
    });
    if (!hasStudentData(report)) continue;
    drawStudentPages(doc, report);
  }

  const roster = await fetchRoster(sectionId);
  drawFlagsAndAppendix(doc, {
    flags: integrityRows,
    roster,
    longitudinalRows,
    enrolledCount,
    submissionCount,
    cdsRows,
  });

  return collectBuffer(doc);
}

module.exports = {
  buildSectionVisualReport,
  // Pure data shapers, exported for the DB-backed pdfReport tests.
  avgCdsByDate,
  cdsDistribution,
  atRiskCount,
  severityCounts,
  buildHeatmap,
  conceptRadarData,
  hasStudentData,
  MAX_REPORT_STUDENTS,
  MAX_STUDENT_PAGES,
  HEATMAP_MAX_ROWS,
  HEATMAP_MAX_COLS,
};
