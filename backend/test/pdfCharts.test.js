/**
 * Pure unit tests for backend/services/pdfCharts.js.
 *
 * No DB, no PDFDocument — only the exported math helpers (interpolateColor,
 * scaleLinear, radarPoints, cdsColor). Expected midpoint colors are derived
 * with a small mix() helper so the expectations are independently computed
 * from the raw ramp stops rather than copy-pasted from the implementation.
 */

const {
  CDS_STOPS,
  NO_DATA_COLOR,
  interpolateColor,
  scaleLinear,
  radarPoints,
  cdsColor,
} = require('../services/pdfCharts');

/** Linear mix of two [r, g, b] triples at t ∈ [0, 1], rounded like rgbToHex. */
function mix(a, b, t) {
  return [
    Math.round(a[0] + (b[0] - a[0]) * t),
    Math.round(a[1] + (b[1] - a[1]) * t),
    Math.round(a[2] + (b[2] - a[2]) * t),
  ];
}

/** [r, g, b] → '#rrggbb'. */
function hex(rgb) {
  const to = (n) => n.toString(16).padStart(2, '0');
  return `#${to(rgb[0])}${to(rgb[1])}${to(rgb[2])}`;
}

const STOP_0 = '#1a5f50';
const STOP_LAST = '#be123c';

describe('interpolateColor', () => {
  it('returns #000000 for an empty ramp', () => {
    expect(interpolateColor([], 0.5)).toBe('#000000');
    expect(interpolateColor(null, 0.5)).toBe('#000000');
  });

  it('returns the single stop for any t', () => {
    expect(interpolateColor([{ pos: 0, color: '#123456' }], 0.9)).toBe('#123456');
  });

  it('maps t=0 to the first stop and t=1 to the last stop', () => {
    expect(interpolateColor(CDS_STOPS, 0)).toBe(STOP_0);
    expect(interpolateColor(CDS_STOPS, 1)).toBe(STOP_LAST);
  });

  it('interpolates the midpoint between two stops', () => {
    const a = [245, 158, 11]; // #f59e0b @ 0.4
    const b = [249, 115, 22]; // #f97316 @ 0.6
    const expected = hex(mix(a, b, 0.5));
    expect(interpolateColor(CDS_STOPS, 0.5)).toBe(expected);
  });

  it('clamps out-of-range t to the nearest stop', () => {
    expect(interpolateColor(CDS_STOPS, -3)).toBe(STOP_0);
    expect(interpolateColor(CDS_STOPS, 7)).toBe(STOP_LAST);
  });

  it('handles non-finite t by clamping to the first stop', () => {
    expect(interpolateColor(CDS_STOPS, Number.NaN)).toBe(STOP_0);
    expect(interpolateColor(CDS_STOPS, Infinity)).toBe(STOP_0);
  });
});

describe('scaleLinear', () => {
  it('maps the mid value to the mid range', () => {
    expect(scaleLinear([0, 100], [0, 10])(50)).toBe(5);
  });

  it('clamps out-of-domain values to the range ends', () => {
    const scale = scaleLinear([0, 100], [0, 10]);
    expect(scale(150)).toBe(10);
    expect(scale(-50)).toBe(0);
  });

  it('maps a degenerate domain to the range midpoint', () => {
    expect(scaleLinear([5, 5], [0, 100])(42)).toBe(50);
  });

  it('returns NaN for non-finite input', () => {
    const scale = scaleLinear([0, 1], [0, 10]);
    expect(scale(Infinity)).toBe(Number.NaN);
    expect(scale(Number.NaN)).toBe(Number.NaN);
  });
});

describe('radarPoints', () => {
  it('places the first point of a 4-gon at the top of the circle', () => {
    const pts = radarPoints({ x: 0, y: 0 }, 10, 4);
    expect(pts).toHaveLength(4);
    expect(pts[0][0]).toBeCloseTo(0, 10);
    expect(pts[0][1]).toBeCloseTo(-10, 10);
  });

  it('renders a symmetric polygon for count=4', () => {
    const pts = radarPoints({ x: 0, y: 0 }, 10, 4);
    expect(pts[2][0]).toBeCloseTo(pts[0][0], 10);
    expect(pts[2][1]).toBeCloseTo(-pts[0][1], 10);
    expect(pts[1][0]).toBeCloseTo(-pts[3][0], 10);
    expect(pts[1][1]).toBeCloseTo(pts[3][1], 10);
  });

  it('returns a single top point for count=1', () => {
    const pts = radarPoints({ x: 5, y: 7 }, 10, 1);
    expect(pts).toHaveLength(1);
    expect(pts[0][0]).toBeCloseTo(5, 10);
    expect(pts[0][1]).toBeCloseTo(-3, 10);
  });

  it('returns [] for count < 1 or non-positive radius', () => {
    expect(radarPoints({ x: 0, y: 0 }, 10, 0)).toEqual([]);
    expect(radarPoints({ x: 0, y: 0 }, -10, 4)).toEqual([]);
    expect(radarPoints({ x: 0, y: 0 }, 0, 4)).toEqual([]);
  });
});

describe('cdsColor', () => {
  it('maps ramp endpoints exactly', () => {
    expect(cdsColor(0)).toBe(STOP_0);
    expect(cdsColor(1)).toBe(STOP_LAST);
  });

  it('interpolates at 0.5 between the 0.4 and 0.6 stops', () => {
    const a = [245, 158, 11]; // #f59e0b @ 0.4
    const b = [249, 115, 22]; // #f97316 @ 0.6
    expect(cdsColor(0.5)).toBe(hex(mix(a, b, 0.5)));
  });

  it('returns NO_DATA_COLOR for null/NaN/undefined', () => {
    expect(cdsColor(null)).toBe(NO_DATA_COLOR);
    expect(cdsColor(Number.NaN)).toBe(NO_DATA_COLOR);
    expect(cdsColor(undefined)).toBe(NO_DATA_COLOR);
    expect(NO_DATA_COLOR).toBe('#94a3b8');
  });

  it('clamps out-of-range values to the ramp ends', () => {
    expect(cdsColor(-0.5)).toBe(STOP_0);
    expect(cdsColor(1.5)).toBe(STOP_LAST);
  });
});
