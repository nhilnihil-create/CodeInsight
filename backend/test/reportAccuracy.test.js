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

  it('excludes concepts with no CDS data and emits null (not 0) for empty weeks', async () => {
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
    // Empty weeks are null, current = last real value.
    const loops = concepts[0];
    assert.ok(loops.series.some((v) => v === null), 'empty weeks must be null');
    assert.strictEqual(loops.current, 62);
  });
});
