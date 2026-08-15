/**
 * Report Accuracy Tests
 * Verifies the data-accuracy fixes to the analytics report endpoints:
 *  1. getCompletionReport — on_time + late never exceed submitted (a student
 *     who submitted before AND after the deadline is counted in exactly one
 *     bucket by their EARLIEST submission).
 *  2. getConceptMasteryReport — only concepts with actual CDS data appear
 *     (no phantom flat-0% lines); missing weeks are null, not 0.
 */

const assert = require('assert');

jest.mock('../config/db', () => ({ query: jest.fn() }));
jest.mock('../services/classMisconceptionReport', () => ({ generateClassMisconceptionReport: jest.fn() }));
jest.mock('../services/longitudinalReportEngine', () => ({ calculateMasteryVelocity: jest.fn() }));
jest.mock('../services/cdsEngine', () => ({
  classify: jest.fn(() => 'moderate'),
  CDS_THRESHOLDS: { LOW: 0.4, MODERATE: 0.6 },
  getConfidenceTier: jest.fn(() => 'medium'),
  CONFIDENCE: {},
  computeBatchCDS: jest.fn(),
  getLivePeerRanking: jest.fn(),
}));

const db = require('../config/db');
const ctrl = require('../controllers/analyticsController');

function makeRes() {
  return { json: jest.fn(), status: jest.fn(() => ({ json: jest.fn() })) };
}

describe('getCompletionReport accuracy', () => {
  beforeEach(() => jest.clearAllMocks());

  const rows = [
    // Exercise 1: 10 enrolled, 8 submitted. Student 1 submitted on-time (first
    // submission before deadline) AND late — must count as on-time only.
    { id: 1, title: 'Lab 1', deadline: new Date('2026-08-01T00:00:00Z'), total: '10', submitted: '8', on_time: '8', late: '1' },
    // Exercise 2: all 10 submitted, first submissions all after deadline.
    { id: 2, title: 'Lab 2', deadline: new Date('2026-08-01T00:00:00Z'), total: '10', submitted: '10', on_time: '0', late: '10' },
  ];

  it('caps late so on_time + late never exceeds submitted', async () => {
    db.query.mockResolvedValueOnce({ rows });

    const req = { params: { sectionId: '7' }, user: { id: 1 } };
    const res = makeRes();
    await ctrl.getCompletionReport(req, res, jest.fn());

    const data = res.json.mock.calls[0][0];

    // Exercise 1: late clamped to submitted - on_time = 0 (the one "late"
    // student already has an on-time first submission).
    const lab1 = data.find((d) => d.exercise === 'Lab 1');
    assert.strictEqual(lab1.on_time, 80);
    assert.strictEqual(lab1.late, 0);
    assert.strictEqual(lab1.on_time + lab1.late + lab1.missing, 100);

    // Exercise 2: everyone late.
    const lab2 = data.find((d) => d.exercise === 'Lab 2');
    assert.strictEqual(lab2.late, 100);
    assert.strictEqual(lab2.on_time + lab2.late + lab2.missing, 100);
  });
});

describe('getConceptMasteryReport accuracy', () => {
  beforeEach(() => jest.clearAllMocks());

  it('excludes concepts with no CDS data and emits 0 (not null) for empty weeks', async () => {
    // conceptRes returns the FULL taxonomy (incl. concepts never used here).
    db.query
      .mockResolvedValueOnce({
        rows: [
          { id: 1, name: 'Loops', slug: 'loops', knowledge_area_code: 'SDF-PMD' },
          { id: 2, name: 'Arrays', slug: 'arrays', knowledge_area_code: 'SDF-FDS' },
          { id: 3, name: 'Recursion', slug: 'recursion', knowledge_area_code: 'SDF-PMD' },
        ],
      })
      .mockResolvedValueOnce({
        // Only Loops has data — and only in the most recent week.
        rows: [
          { concept_id: 1, slug: 'loops', concept_name: 'Loops', week_date: new Date(), mastery: 62 },
        ],
      });

    const req = { params: { sectionId: '7' }, query: { weeks: '5' }, user: { id: 1 } };
    const res = makeRes();
    await ctrl.getConceptMasteryReport(req, res, jest.fn());

    const { concepts } = res.json.mock.calls[0][0];

    // Arrays and Recursion never appear — no phantom 0% lines.
    assert.deepStrictEqual(concepts.map((c) => c.name), ['Loops']);
    // Empty weeks are 0 (continuous curve), current = last real value.
    const loops = concepts[0];
    assert.ok(loops.series.every((v) => v === 0 || v === 62), 'weeks are 0 or the measured value');
    assert.ok(loops.series.includes(62), 'measured week present');
    assert.strictEqual(loops.current, 62);
  });

  it('buckets mid-week measurements into their week slot (range, not exact date)', async () => {
    // A measurement made 3 days ago (mid-week, NOT an exact week anchor) must
    // land in the "Now" slot — previously exact-date equality dropped it to null.
    const threeDaysAgo = new Date(Date.now() - 3 * 24 * 60 * 60 * 1000);
    db.query
      .mockResolvedValueOnce({
        rows: [{ id: 1, name: 'Variables', slug: 'variables', knowledge_area_code: 'SDF-FPC' }],
      })
      .mockResolvedValueOnce({
        rows: [
          { concept_id: 1, slug: 'variables', concept_name: 'Variables', week_date: threeDaysAgo, mastery: 74 },
        ],
      });

    const req = { params: { sectionId: '7' }, query: { weeks: '5' }, user: { id: 1 } };
    const res = makeRes();
    await ctrl.getConceptMasteryReport(req, res, jest.fn());

    const { weeks, concepts } = res.json.mock.calls[0][0];
    assert.strictEqual(weeks.length, 5);
    assert.strictEqual(weeks[4], 'Now');

    const v = concepts[0];
    // The mid-week measurement lands in the final (Now) slot.
    assert.strictEqual(v.series[4], 74);
    // Earlier weeks are 0 so the line curves up from the baseline.
    assert.ok(v.series.slice(0, 4).every((x) => x === 0));
    assert.strictEqual(v.current, 74);
  });

  it('emits 0 for weeks after the last measurement (continuous curve, class-trend style)', async () => {
    // One measurement ~8 days ago (W-1 slot) and nothing since: missing weeks
    // are 0, so the chart draws one continuous line from the 0 baseline
    // through the point — the dashboard Class Trend style, no orphan dot.
    const eightDaysAgo = new Date(Date.now() - 8 * 24 * 60 * 60 * 1000);
    db.query
      .mockResolvedValueOnce({
        rows: [{ id: 1, name: 'Loops', slug: 'loops', knowledge_area_code: 'SDF-PMD' }],
      })
      .mockResolvedValueOnce({
        rows: [
          { concept_id: 1, slug: 'loops', concept_name: 'Loops', week_date: eightDaysAgo, mastery: 77 },
        ],
      });

    const req = { params: { sectionId: '7' }, query: { weeks: '5' }, user: { id: 1 } };
    const res = makeRes();
    await ctrl.getConceptMasteryReport(req, res, jest.fn());

    const { weeks, concepts } = res.json.mock.calls[0][0];
    const loops = concepts[0];
    // 8 days ago → W-1 (index 3 of 5); index 4 (Now) and 0..2 are 0 → the
    // line is continuous from baseline through the point.
    assert.strictEqual(loops.series[3], 77);
    assert.strictEqual(loops.series[4], 0);
    assert.deepStrictEqual(loops.series.slice(0, 3), [0, 0, 0]);
    assert.strictEqual(loops.current, 77);
    assert.strictEqual(weeks[4], 'Now');
  });
});
