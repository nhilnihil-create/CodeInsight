/**
 * backend/services/pdfCharts.js
 *
 * Chart primitives for the PDF "Section Visual Report". The rendering
 * functions are thin wrappers over pdfkit's vector API (doc = a PDFDocument
 * instance) — every piece of math (color interpolation, linear scaling,
 * radar geometry) lives in the pure exported helpers so it can be
 * unit-tested without ever constructing a PDFDocument.
 *
 * The CDS color ramp mirrors frontend/src/pages/instructor/Heatmap.jsx
 * exactly. CDS is a struggle index: 0 = not struggling, 1 = struggling
 * hardest, so high CDS renders in rose.
 */

// ── CDS color ramp (mirror of Heatmap.jsx `cdsColor` stops) ─────────────────

const CDS_STOPS = [
  { pos: 0.0, rgb: [26, 95, 80] },     // #1a5f50
  { pos: 0.2, rgb: [16, 185, 129] },   // #10b981
  { pos: 0.4, rgb: [245, 158, 11] },   // #f59e0b
  { pos: 0.6, rgb: [249, 115, 22] },   // #f97316
  { pos: 0.8, rgb: [225, 29, 72] },    // #e11d48
  { pos: 1.0, rgb: [190, 18, 60] },    // #be123c
];

/** Neutral gray used for "no data" cells (slate-400). */
const NO_DATA_COLOR = '#94a3b8';

/** Default ink for chart strokes and gridlines. */
const AXIS_COLOR = '#cbd5e1';
const GRID_COLOR = '#e2e8f0';
const DEFAULT_CHART_COLOR = '#334155';
const MUTED_LABEL = '#64748b';

// ── Pure helpers (the unit-testable surface) ────────────────────────────────

/** [r, g, b] (0–255) → '#rrggbb' hex string. */
function rgbToHex(rgb) {
  const to = (n) => Math.round(n).toString(16).padStart(2, '0');
  return `#${to(rgb[0])}${to(rgb[1])}${to(rgb[2])}`;
}

/** '#rrggbb' hex string → [r, g, b]; malformed input → [0, 0, 0]. */
function hexToRgb(hex) {
  const m = /^#?([0-9a-f]{6})$/i.exec(String(hex).trim());
  if (!m) return [0, 0, 0];
  const n = parseInt(m[1], 16);
  return [(n >> 16) & 255, (n >> 8) & 255, n & 255];
}

/** Normalize a ramp stop to { pos, color: '#rrggbb' }. */
function normalizeStop(stop) {
  return {
    pos: Number(stop.pos) || 0,
    color: stop.color || rgbToHex(stop.rgb),
  };
}

/**
 * Linear interpolation between the stops of a color ramp.
 * stops: [{ pos, color }] (or { pos, rgb }), sorted by pos — the same shape
 * Heatmap.jsx uses. t is clamped to [0, 1] so out-of-range inputs clamp to
 * the nearest stop. Returns a '#rrggbb' hex string; empty/malformed ramps
 * fall back to '#000000'.
 */
function interpolateColor(stops, t) {
  if (!Array.isArray(stops) || stops.length === 0) return '#000000';
  const norm = stops.map(normalizeStop);
  if (norm.length === 1) return norm[0].color;

  const raw = Number(t);
  const clamped = Number.isFinite(raw) ? Math.min(1, Math.max(0, raw)) : 0;

  let lower = norm[0];
  let upper = norm[norm.length - 1];
  for (let i = 0; i < norm.length - 1; i += 1) {
    if (clamped >= norm[i].pos && clamped <= norm[i + 1].pos) {
      lower = norm[i];
      upper = norm[i + 1];
      break;
    }
  }

  const span = upper.pos - lower.pos || 1;
  const f = (clamped - lower.pos) / span;
  const a = hexToRgb(lower.color);
  const b = hexToRgb(upper.color);
  return rgbToHex([
    a[0] + (b[0] - a[0]) * f,
    a[1] + (b[1] - a[1]) * f,
    a[2] + (b[2] - a[2]) * f,
  ]);
}

/**
 * CDS (0–1) → hex color across the app's ramp; null/undefined/NaN (no data)
 * → NO_DATA_COLOR. Values outside [0, 1] clamp to the ramp ends, matching the
 * frontend's Math.min/Math.max clamp.
 */
function cdsColor(cds) {
  if (cds === null || cds === undefined || Number.isNaN(Number(cds))) return NO_DATA_COLOR;
  return interpolateColor(CDS_STOPS, Number(cds));
}

/**
 * Linear scale with out-of-domain clamping:
 *   scaleLinear([0, 100], [0, 10])(50) === 5, (150) === 10, (-50) === 0.
 * A degenerate domain (min === max) maps every input to the range midpoint.
 * Returns NaN for non-finite input.
 */
function scaleLinear(domain, range) {
  const d0 = domain[0];
  const d1 = domain[1];
  const r0 = range[0];
  const r1 = range[1];
  const dSpan = d1 - d0;
  const rSpan = r1 - r0;
  return (value) => {
    const v = Number(value);
    if (!Number.isFinite(v)) return Number.NaN;
    if (dSpan === 0) return r0 + rSpan / 2;
    const f = Math.min(1, Math.max(0, (v - d0) / dSpan));
    return r0 + f * rSpan;
  };
}

/**
 * Vertices of a regular `count`-gon centered at `center` with the given
 * radius. The default startAngle (-π/2) puts the first point at the top
 * (12 o'clock) so symmetric axes render balanced; each subsequent point
 * advances 2π/count. count < 1 → []; count === 1 → a single top point.
 * Returns an array of [x, y] pairs.
 */
function radarPoints(center, radius, count, startAngle = -Math.PI / 2) {
  if (!count || count < 1 || !(radius > 0)) return [];
  const points = [];
  const step = (2 * Math.PI) / count;
  for (let i = 0; i < count; i += 1) {
    const angle = startAngle + i * step;
    points.push([center.x + radius * Math.cos(angle), center.y + radius * Math.sin(angle)]);
  }
  return points;
}

// ── Small drawing helpers ───────────────────────────────────────────────────

function clampNumber(v, lo, hi) {
  const n = Number(v);
  return Number.isFinite(n) ? Math.min(hi, Math.max(lo, n)) : lo;
}

/** Truncate a label with an ellipsis so its rendered width fits maxWidth. */
function truncateLabel(doc, text, maxWidth) {
  const s = String(text === null || text === undefined ? '' : text);
  if (doc.widthOfString(s) <= maxWidth) return s;
  let out = s;
  while (out.length > 1 && doc.widthOfString(`${out}\u2026`) > maxWidth) {
    out = out.slice(0, -1);
  }
  return `${out}\u2026`;
}

/** Centered gray "No data" placeholder inside a chart's bounding box. */
function drawNoData(doc, x, y, w, h) {
  doc.save();
  doc.font('Helvetica').fontSize(7).fillColor(NO_DATA_COLOR);
  doc.text('No data', x, y + h / 2 - 4, { width: w, align: 'center' });
  doc.restore();
}

/** Hatched gray cell for missing heatmap data, with a label on roomy cells. */
function drawNoDataCell(doc, cx, cy, cellW, cellH) {
  doc.save();
  doc.fillColor('#f1f5f9');
  doc.rect(cx, cy, cellW, cellH).fill();
  doc.strokeColor(AXIS_COLOR).lineWidth(0.4);
  const step = Math.max(3, Math.min(cellW, cellH) / 3);
  for (let i = -cellH; i <= cellW; i += step) {
    doc.moveTo(cx + i, cy + cellH).lineTo(cx + i + cellH, cy).stroke();
  }
  if (cellW >= 24 && cellH >= 10) {
    doc.font('Helvetica').fontSize(5).fillColor(NO_DATA_COLOR);
    doc.text('No Data', cx, cy + cellH / 2 - 3, { width: cellW, align: 'center' });
  }
  doc.restore();
}

/** Collect every finite numeric value across one or more series. */
function collectSeriesValues(series) {
  const out = [];
  for (const s of Array.isArray(series) ? series : []) {
    const values = Array.isArray(s) ? s : s && Array.isArray(s.values) ? s.values : [];
    for (const v of values) {
      const n = v === null || v === undefined ? Number.NaN : Number(v);
      if (Number.isFinite(n)) out.push(n);
    }
  }
  return out;
}

// ── Renderers ───────────────────────────────────────────────────────────────

/**
 * Line chart with axes, min/max gridlines and one polyline per series.
 * series: [{ values: number[] }] or a flat number[]; values may contain
 * null/undefined gaps (skipped). labels: x-axis labels (truncated to their
 * cell). Single data points render as a dot. The y-domain spans at least
 * [0, 1] (the CDS range) and includes any out-of-range values.
 */
function renderLineChart(doc, { x, y, w, h, series, labels, color = DEFAULT_CHART_COLOR }) {
  const seriesList = (Array.isArray(series) ? series : []).map((s) => ({
    values: Array.isArray(s) ? s : s && Array.isArray(s.values) ? s.values : [],
  }));
  const count = seriesList.reduce((max, s) => Math.max(max, s.values.length), 0);
  const values = collectSeriesValues(seriesList);

  doc.save();
  doc.strokeColor(AXIS_COLOR).lineWidth(0.6);
  doc.moveTo(x, y).lineTo(x, y + h).stroke(); // left axis
  doc.moveTo(x, y + h).lineTo(x + w, y + h).stroke(); // baseline

  if (values.length === 0) {
    drawNoData(doc, x, y, w, h);
    doc.restore();
    return;
  }

  const yMin = Math.min(0, ...values);
  const yMax = Math.max(1e-9, ...values, 1);
  const xFor = (i) => (count === 1 ? x + w / 2 : x + (i / (count - 1)) * w);
  const yFor = scaleLinear([yMin, yMax], [y + h, y]);

  // Gridlines at data min/max with value tags.
  for (const [gv, gy] of [[yMin, yFor(yMin)], [yMax, yFor(yMax)]]) {
    doc.strokeColor(GRID_COLOR).lineWidth(0.4);
    doc.moveTo(x, gy).lineTo(x + w, gy).stroke();
    doc.save();
    doc.font('Helvetica').fontSize(6).fillColor(MUTED_LABEL);
    doc.text(gv.toFixed(2), x - 30, gy - 3, { width: 26, align: 'right' });
    doc.restore();
  }

  for (const s of seriesList) {
    const pts = s.values
      .map((v, i) => [xFor(i), yFor(v === null || v === undefined ? Number.NaN : Number(v))])
      .filter((p) => Number.isFinite(p[1]));
    if (pts.length === 0) continue;
    if (pts.length === 1) {
      doc.save();
      doc.fillColor(color);
      doc.circle(pts[0][0], pts[0][1], 2.4).fill();
      doc.restore();
      continue;
    }
    doc.save();
    doc.strokeColor(color).lineWidth(1.4).lineCap('round').lineJoin('round');
    doc.moveTo(pts[0][0], pts[0][1]);
    for (const [px, py] of pts.slice(1)) doc.lineTo(px, py);
    doc.stroke();
    doc.restore();
  }

  if (Array.isArray(labels) && labels.length) {
    const cellW = w / Math.max(count, 1);
    if (cellW >= 8) {
      doc.save();
      doc.font('Helvetica').fontSize(6).fillColor(MUTED_LABEL);
      labels.slice(0, count).forEach((label, i) => {
        doc.text(truncateLabel(doc, label, cellW - 2), xFor(i) - cellW / 2, y + h + 5, {
          width: cellW,
          align: 'center',
        });
      });
      doc.restore();
    }
  }
  doc.restore();
}

/**
 * Vertical bar chart, y-scale from 0. values may contain null/undefined
 * (skipped); empty input renders a "No data" placeholder. Pass `colors` to
 * color bars individually (defaults to `color` for every bar).
 */
function renderBarChart(doc, { x, y, w, h, values, labels, color = DEFAULT_CHART_COLOR, colors }) {
  const nums = (Array.isArray(values) ? values : []).map((v) =>
    v === null || v === undefined ? Number.NaN : Number(v)
  );
  doc.save();
  doc.strokeColor(AXIS_COLOR).lineWidth(0.6);
  doc.moveTo(x, y + h).lineTo(x + w, y + h).stroke();

  const finite = nums.filter((v) => Number.isFinite(v));
  if (nums.length === 0 || finite.length === 0) {
    drawNoData(doc, x, y, w, h);
    doc.restore();
    return;
  }

  const max = Math.max(0, ...finite, 1e-9);
  const barW = w / nums.length;
  const gap = Math.max(1, Math.min(4, barW * 0.25));
  const scale = scaleLinear([0, max], [0, h]);

  nums.forEach((v, i) => {
    if (!Number.isFinite(v)) return;
    const bh = scale(v);
    doc.save();
    doc.fillColor((Array.isArray(colors) && colors[i]) || color);
    doc.rect(x + i * barW + gap / 2, y + h - bh, Math.max(barW - gap, 1), bh).fill();
    doc.restore();
  });

  if (Array.isArray(labels) && labels.length && barW >= 10) {
    doc.save();
    doc.font('Helvetica').fontSize(6).fillColor(MUTED_LABEL);
    labels.slice(0, nums.length).forEach((label, i) => {
      doc.text(truncateLabel(doc, label, barW - 2), x + i * barW, y + h + 5, {
        width: barW,
        align: 'center',
      });
    });
    doc.restore();
  }
  doc.restore();
}

/**
 * Radar chart: polygon + axis spokes + labels. axes = string labels around
 * the center; values = 0–1 normalized radius per axis (clamped). Handles a
 * single axis (spoke + dot) and empty input ("No data").
 */
function renderRadarChart(doc, { axes, values, center, radius, color = DEFAULT_CHART_COLOR }) {
  const names = Array.isArray(axes) ? axes : [];
  const nums = (Array.isArray(values) ? values : []).map((v) => clampNumber(v, 0, 1));

  if (names.length === 0) {
    drawNoData(doc, center.x - radius, center.y - radius, radius * 2, radius * 2);
    return;
  }

  const n = names.length;
  const outer = radarPoints(center, radius, n);
  const scaled = outer.map((p, i) => {
    const v = Number.isFinite(nums[i]) ? nums[i] : 0;
    return [center.x + (p[0] - center.x) * v, center.y + (p[1] - center.y) * v];
  });

  doc.save();
  // Spokes + outer ring.
  doc.strokeColor(GRID_COLOR).lineWidth(0.5);
  for (const p of outer) {
    doc.moveTo(center.x, center.y).lineTo(p[0], p[1]).stroke();
  }
  doc.save();
  doc.strokeColor(GRID_COLOR).lineWidth(0.6);
  doc.moveTo(outer[0][0], outer[0][1]);
  for (let i = 1; i < outer.length; i += 1) doc.lineTo(outer[i][0], outer[i][1]);
  if (outer.length > 1) doc.closePath();
  doc.stroke();
  doc.restore();

  if (n === 1) {
    doc.save();
    doc.fillColor(color);
    doc.circle(scaled[0][0], scaled[0][1], 2.4).fill();
    doc.restore();
  } else {
    // Value polygon.
    doc.save();
    doc.fillColor(color).fillOpacity(0.12).strokeColor(color).lineWidth(1.2);
    doc.moveTo(scaled[0][0], scaled[0][1]);
    for (let i = 1; i < scaled.length; i += 1) doc.lineTo(scaled[i][0], scaled[i][1]);
    doc.closePath();
    doc.fillAndStroke();
    doc.restore();
  }

  // Axis labels.
  doc.save();
  doc.font('Helvetica').fontSize(6.5).fillColor(MUTED_LABEL);
  const step = (2 * Math.PI) / n;
  const labelWidth = Math.min(radius * 2, 90);
  names.forEach((name, i) => {
    const angle = -Math.PI / 2 + i * step;
    const dx = Math.cos(angle);
    const dy = Math.sin(angle);
    const lx = center.x + dx * (radius + 10);
    const ly = center.y + dy * (radius + 10);
    doc.text(truncateLabel(doc, name, labelWidth), lx - labelWidth / 2, ly - 3, {
      width: labelWidth,
      align: 'center',
    });
  });
  doc.restore();
  doc.restore();
}

/**
 * Heatmap grid: rows × cols cells colored by colorFn(row, col). colorFn
 * returns a '#rrggbb' hex string, or null for a "No Data" cell (hatched gray
 * + small label). rowLabels/colLabels are truncated to their cell width;
 * column labels are skipped entirely on cells too narrow to read.
 */
function renderHeatmapGrid(doc, { x, y, cellW, cellH, rows, cols, colorFn, rowLabels, colLabels }) {
  const nRows = Number(rows) || 0;
  const nCols = Number(cols) || 0;

  if (nRows === 0 || nCols === 0) {
    drawNoData(doc, x, y, Math.max(cellW * 4, 120), Math.max(cellH * 2, 60));
    return;
  }

  doc.save();
  for (let r = 0; r < nRows; r += 1) {
    for (let c = 0; c < nCols; c += 1) {
      const cx = x + c * cellW;
      const cy = y + r * cellH;
      const color = colorFn ? colorFn(r, c) : null;
      if (color) {
        doc.save();
        doc.fillColor(color);
        doc.rect(cx, cy, cellW, cellH).fill();
        doc.restore();
      } else {
        drawNoDataCell(doc, cx, cy, cellW, cellH);
      }
    }
  }

  // Cell borders.
  doc.strokeColor(GRID_COLOR).lineWidth(0.3);
  for (let c = 0; c <= nCols; c += 1) {
    doc.moveTo(x + c * cellW, y).lineTo(x + c * cellW, y + nRows * cellH).stroke();
  }
  for (let r = 0; r <= nRows; r += 1) {
    doc.moveTo(x, y + r * cellH).lineTo(x + nCols * cellW, y + r * cellH).stroke();
  }

  // Column labels (date-like), skipped when cells are too narrow.
  if (Array.isArray(colLabels) && cellW >= 10) {
    doc.save();
    doc.font('Helvetica').fontSize(5.5).fillColor(MUTED_LABEL);
    colLabels.slice(0, nCols).forEach((label, c) => {
      doc.text(truncateLabel(doc, label, cellW - 1), x + c * cellW, y + nRows * cellH + 3, {
        width: cellW,
        align: 'center',
      });
    });
    doc.restore();
  }

  // Row labels (student names), right-aligned in the left margin gutter.
  if (Array.isArray(rowLabels)) {
    doc.save();
    doc.font('Helvetica').fontSize(6).fillColor(MUTED_LABEL);
    rowLabels.slice(0, nRows).forEach((label, r) => {
      const text = truncateLabel(doc, label, 60);
      doc.text(text, x - 64, y + r * cellH + cellH / 2 - 3, { width: 60, align: 'right' });
    });
    doc.restore();
  }
  doc.restore();
}

module.exports = {
  CDS_STOPS,
  NO_DATA_COLOR,
  rgbToHex,
  cdsColor,
  interpolateColor,
  scaleLinear,
  radarPoints,
  renderLineChart,
  renderBarChart,
  renderRadarChart,
  renderHeatmapGrid,
};
