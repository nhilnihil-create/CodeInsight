/**
 * CDS Engine — State-Transition & Boundary Condition Tests
 *
 * Tests the real exported functions from cdsEngine.js with mock DB.
 * Covers edge cases: zero-variance, empty classes, all-excluded
 * students, NaN propagation, HARDCODING special scoring, live vs
 * batch parity, and post-solution cutoff with flagged attempts.
 */

jest.mock('../config/db', () => ({ query: jest.fn() }));
jest.mock('../services/alertEngine', () => ({ generateAlerts: jest.fn() }));

const db = require('../config/db');
const alertEngine = require('../services/alertEngine');
const { computeBatchCDS, calculateLiveCDS, computeClassStats, normalizeWithStats, classify, getLivePeerRanking } = require('../services/cdsEngine');

beforeEach(() => {
  jest.clearAllMocks();
  alertEngine.generateAlerts.mockResolvedValue(undefined);
});

function makeStudent(id, name) {
  return { id, name };
}

// ── Helpers: explicitly set up mock db for computeBatchCDS ────────────────────
// computeBatchCDS makes exactly: 3 prep queries (exercise, students, excludedFlags,
// submissions) + 2 writes per student (cds_scores, cds_snapshots).
// alertEngine.generateAlerts is mocked.

async function runBatchCds(exerciseId, students, excludedFlags, submissions) {
  db.query
    .mockResolvedValueOnce({ rows: [{ id: exerciseId, section_id: 1 }] })
    .mockResolvedValueOnce({ rows: students })
    .mockResolvedValueOnce({ rows: excludedFlags })
    .mockResolvedValueOnce({ rows: submissions });
  return computeBatchCDS(exerciseId, db);
}

function getScoreCalls() {
  return db.query.mock.calls.filter(c => c[0].includes('cds_scores'));
}

// ── Test: 1. Zero-Variance Normalization ─────────────────────────────────────

describe('CDS State Transition — Zero-Variance Normalization', () => {

  it('computeClassStats with identical values returns hasVariance=false', () => {
    const stats = computeClassStats([5, 5, 5, 5, 5]);
    expect(stats.hasVariance).toBe(false);
    expect(stats.denominator).toBe(0);
    expect(stats.min).toBe(5);
    expect(stats.p95).toBe(5);
  });

  it('normalizeWithStats returns 0.00 when hasVariance=false', () => {
    const stats = { min: 5, p95: 5, denominator: 0, hasVariance: false };
    expect(normalizeWithStats(10, stats)).toBe(0.00);
  });

  it('all identical class values produce CDS=0 for all students', async () => {
    const exerciseId = 10;
    const students = [makeStudent(1, 'A'), makeStudent(2, 'B'), makeStudent(3, 'C')];
    const subs = [
      { student_id: 1, attempt_number: 1, is_correct: false, time_spent_seconds: 60, code: 'x', is_verified: true, flag_id: null },
      { student_id: 1, attempt_number: 2, is_correct: true,  time_spent_seconds: 90, code: 'x', is_verified: true, flag_id: null },
      { student_id: 2, attempt_number: 1, is_correct: false, time_spent_seconds: 60, code: 'x', is_verified: true, flag_id: null },
      { student_id: 2, attempt_number: 2, is_correct: true,  time_spent_seconds: 90, code: 'x', is_verified: true, flag_id: null },
      { student_id: 3, attempt_number: 1, is_correct: false, time_spent_seconds: 60, code: 'x', is_verified: true, flag_id: null },
      { student_id: 3, attempt_number: 2, is_correct: true,  time_spent_seconds: 90, code: 'x', is_verified: true, flag_id: null },
    ];

    await runBatchCds(exerciseId, students, [], subs);
    const scores = getScoreCalls();

    expect(scores.length).toBe(3);
    for (const call of scores) {
      expect(call[1][6]).toBe(0);     // cds
      expect(call[1][3]).toBe(0.00);  // ner
      expect(call[1][4]).toBe(0.00);  // nrs
      expect(call[1][5]).toBe(0.00);  // nts
    }
  });
});

// ── Test: 2. Single Student Class ────────────────────────────────────────────

describe('CDS State Transition — Single Student Class', () => {

  it('preliminary class with 1 student produces Preliminary classification', async () => {
    const exerciseId = 10;
    const students = [makeStudent(1, 'Solo')];
    const subs = [
      { student_id: 1, attempt_number: 1, is_correct: false, time_spent_seconds: 30, code: 'x', is_verified: true, flag_id: null },
      { student_id: 1, attempt_number: 2, is_correct: true,  time_spent_seconds: 60, code: 'x', is_verified: true, flag_id: null },
    ];

    await runBatchCds(exerciseId, students, [], subs);
    const scores = getScoreCalls();

    expect(scores.length).toBe(1);
    // Single student: single-value filteredSubMap → hasVariance=false → all 0.00
    // isPreliminaryClass = true (1 < 3)
    expect(scores[0][1][6]).toBe(0);
    expect(scores[0][1][7]).toBe('Preliminary - Low');
  });
});

// ── Test: 3. All-Excluded Students (HARDCODING) ──────────────────────────────

describe('CDS State Transition — All Students Have HARDCODING Flags', () => {

  it('all HARDCODING students get CDS=1 (not 0 or Unscored)', async () => {
    const exerciseId = 10;
    const students = [makeStudent(1, 'A'), makeStudent(2, 'B')];
    const excluded = [{ student_id: 1 }, { student_id: 2 }];
    const subs = [
      { student_id: 1, attempt_number: 1, is_correct: false, time_spent_seconds: 30, code: '#include<bits/stdc++.h>', is_verified: true, flag_id: 42 },
      { student_id: 2, attempt_number: 1, is_correct: true,  time_spent_seconds: 60, code: '#include<bits/stdc++.h>', is_verified: true, flag_id: 43 },
    ];

    await runBatchCds(exerciseId, students, excluded, subs);
    const scores = getScoreCalls();

    expect(scores.length).toBe(2);
    for (const call of scores) {
      expect(call[1][6]).toBe(1);    // cds
      expect(call[1][3]).toBe(1);    // ner
      expect(call[1][4]).toBe(1);    // nrs
      expect(call[1][5]).toBe(1);    // nts
      expect(call[1][7]).toBe('High');
    }
  });
});

// ── Test: 4. NaN Time Spent ──────────────────────────────────────────────────

describe('CDS State Transition — NaN Protection in Normalization', () => {

  it('normalizeWithStats returns 0.00 for NaN input', () => {
    const stats = { min: 5, p95: 50, denominator: 45, hasVariance: true };
    expect(normalizeWithStats(undefined, stats)).toBe(0.00);
    expect(normalizeWithStats(NaN, stats)).toBe(0.00);
    expect(normalizeWithStats('not a number', stats)).toBe(0.00);
  });

  it('student with null time_spent gets 0.00 not NaN for nts', async () => {
    const exerciseId = 10;
    const students = [makeStudent(1, 'A'), makeStudent(2, 'B'), makeStudent(3, 'C')];
    const subs = [
      { student_id: 1, attempt_number: 1, is_correct: true, time_spent_seconds: null, code: 'x', is_verified: true, flag_id: null },
      { student_id: 2, attempt_number: 1, is_correct: true, time_spent_seconds: 120,  code: 'x', is_verified: true, flag_id: null },
      { student_id: 3, attempt_number: 1, is_correct: true, time_spent_seconds: 60,   code: 'x', is_verified: true, flag_id: null },
    ];

    await runBatchCds(exerciseId, students, [], subs);
    const scores = getScoreCalls();

    expect(scores.length).toBe(3);
    for (const call of scores) {
      expect(Number.isNaN(call[1][3])).toBe(false); // ner
      expect(Number.isNaN(call[1][4])).toBe(false); // nrs
      expect(Number.isNaN(call[1][5])).toBe(false); // nts
      expect(Number.isNaN(call[1][6])).toBe(false); // cds
      expect(typeof call[1][5]).toBe('number');     // nts is a number, not NaN
    }

    // Student 1 has null time → max_time=0 (due to || 0 in reduce)
    // normalizeWithStats(0, timeStats) → nts=0.00 (Math.max(0,0)/denom = 0)
    const student1Score = scores.find(c => c[1][0] === 1);
    expect(student1Score[1][5]).toBe(0.00);
  });
});

// ── Test: 5. HARDCODING vs BLANK_TEMPLATE Parity ─────────────────────────────

describe('CDS State Transition — HARDCODING + BLANK_TEMPLATE Both Get CDS=1', () => {

  it('HARDCODING and BLANK_TEMPLATE students both score CDS=1', async () => {
    const exerciseId = 10;
    const students = [makeStudent(1, 'Hardcoder'), makeStudent(2, 'BlankSub'), makeStudent(3, 'Normal')];
    const excluded = [{ student_id: 1 }, { student_id: 2 }];
    const subs = [
      { student_id: 1, attempt_number: 1, is_correct: false, time_spent_seconds: 10, code: 'hardcoded', is_verified: true, flag_id: 42 },
      { student_id: 2, attempt_number: 1, is_correct: false, time_spent_seconds: 10, code: '',          is_verified: true, flag_id: 43 },
      { student_id: 3, attempt_number: 1, is_correct: true,  time_spent_seconds: 60, code: 'real code', is_verified: true, flag_id: null },
      { student_id: 3, attempt_number: 2, is_correct: true,  time_spent_seconds: 45, code: 'real code', is_verified: true, flag_id: null },
    ];

    await runBatchCds(exerciseId, students, excluded, subs);
    const scores = getScoreCalls();

    expect(scores.length).toBe(3);
    const hardcoder = scores.find(c => c[1][0] === 1);
    const blankSub  = scores.find(c => c[1][0] === 2);
    const normal    = scores.find(c => c[1][0] === 3);

    // Both integrity-flagged students get CDS=1
    expect(hardcoder[1][6]).toBe(1);
    expect(hardcoder[1][7]).toBe('High');
    expect(blankSub[1][6]).toBe(1);
    expect(blankSub[1][7]).toBe('High');

    // Student 3 (normal): filteredSubMap has 1 entry → hasVariance=false → all 0 → CDS=0
    expect(normal[1][6]).toBe(0);
    expect(normal[1][3]).toBe(0.00);
    expect(normal[1][4]).toBe(0.00);
    expect(normal[1][5]).toBe(0.00);
    expect(normal[1][7]).toBe('Low');
  });
});

// ── Test: 6. Live CDS vs Batch CDS Parity ────────────────────────────────────

describe('CDS State Transition — Live CDS vs Batch CDS Parity', () => {

  it('calculateLiveCDS produces same CDS as batch for non-flagged student', async () => {
    const exerciseId = 10;
    const studentId = 1;

    // Batch: normal student + flagged student
    const students = [makeStudent(1, 'Normal'), makeStudent(2, 'Flagged')];
    const excluded = [{ student_id: 2 }];
    const subs = [
      { student_id: 1, attempt_number: 1, is_correct: false, time_spent_seconds: 30, code: 'x', is_verified: true, flag_id: null },
      { student_id: 1, attempt_number: 2, is_correct: true,  time_spent_seconds: 60, code: 'x', is_verified: true, flag_id: null },
      { student_id: 2, attempt_number: 1, is_correct: true,  time_spent_seconds: 999, code: 'bad', is_verified: true, flag_id: 42 },
    ];

    await runBatchCds(exerciseId, students, excluded, subs);
    const batchScore = getScoreCalls().find(c => c[1][0] === studentId);
    const batchCds = batchScore[1][6];

    // Reset for live mode (same data)
    jest.clearAllMocks();
    alertEngine.generateAlerts.mockResolvedValue(undefined);

    db.query
      .mockResolvedValueOnce({ rows: [{ id: exerciseId, section_id: 1 }] })
      .mockResolvedValueOnce({ rows: subs })
      .mockResolvedValueOnce({ rows: excluded });

    const liveResult = await calculateLiveCDS(studentId, exerciseId, db);
    expect(liveResult.cds).toBe(batchCds);
  });

  it('calculateLiveCDS returns CDS=1 for flagged student (matches batch)', async () => {
    const exerciseId = 10;
    const studentId = 2;

    jest.clearAllMocks();
    db.query
      .mockResolvedValueOnce({ rows: [{ id: exerciseId, section_id: 1 }] })
      .mockResolvedValueOnce({ rows: [
        { student_id: 1, attempt_number: 1, is_correct: true, time_spent_seconds: 60,  is_verified: true, flag_id: null },
        { student_id: 2, attempt_number: 1, is_correct: true, time_spent_seconds: 999, is_verified: true, flag_id: 42 },
      ] })
      .mockResolvedValueOnce({ rows: [{ student_id: 2 }] });

    const liveResult = await calculateLiveCDS(studentId, exerciseId, db);
    expect(liveResult.cds).toBe(1);
    expect(liveResult.classification).toBe('High');
    expect(liveResult.ner).toBe(1);
    expect(liveResult.nrs).toBe(1);
    expect(liveResult.nts).toBe(1);
  });
});

// ── Test: 7. Post-Solution Cutoff with Flagged Attempt ───────────────────────

describe('CDS State Transition — Post-Solution Cutoff + Flagged Attempt', () => {

  it('flagged correct answer is skipped for cutoff; later unflagged answer used', async () => {
    const exerciseId = 10;
    const students = [makeStudent(1, 'FlaggedPass'), makeStudent(2, 'Other')];
    const subs = [
      // Student 1: attempt 2 is correct but FLAGGED; attempt 4 is correct and clean
      { student_id: 1, attempt_number: 1, is_correct: false, time_spent_seconds: 10, code: 'x', is_verified: true, flag_id: null },
      { student_id: 1, attempt_number: 2, is_correct: true,  time_spent_seconds: 20, code: 'x', is_verified: true, flag_id: 99 },
      { student_id: 1, attempt_number: 3, is_correct: false, time_spent_seconds: 30, code: 'x', is_verified: true, flag_id: null },
      { student_id: 1, attempt_number: 4, is_correct: true,  time_spent_seconds: 40, code: 'x', is_verified: true, flag_id: null },
      // Student 2: single clean correct attempt
      { student_id: 2, attempt_number: 1, is_correct: true, time_spent_seconds: 50, code: 'x', is_verified: true, flag_id: null },
    ];

    await runBatchCds(exerciseId, students, [], subs);
    const scores = getScoreCalls();
    const s1 = scores.find(c => c[1][0] === 1);

    // Student 1: firstAccepted = attempt 4 (attempt 2 has flag_id=99). cutoff=4.
    // counted = attempts 1-4. total=4, failed=2 (attempts 1,3), max_time=40.
    // flaggedAttempts = 1 (attempt 2)
    // Student 2: total=1, failed=0, max_time=50, no flags
    // filteredSubMap = {1: {total:4, failed:2, max_time:40},
    //                   2: {total:1, failed:0, max_time:50}}
    // failedStats = computeClassStats([2, 0]) → min=0, p95=ceil(2*0.95)-1=1, p95=sorted[1]=2, denom=2
    // totalStats = computeClassStats([4, 1]) → min=1, p95=ceil(2*0.95)-1=1, p95=sorted[1]=4, denom=3
    // timeStats = computeClassStats([40, 50]) → min=40, p95=ceil(2*0.95)-1=1, p95=sorted[1]=50, denom=10
    // normalized for student 1:
    //   ner=(2-0)/2=1.0, nrs=(4-1)/3=1.0, nts=(40-40)/10=0.00
    // CDS = 0.40*1 + 0.35*1 + 0.25*0 = 0.75
    expect(s1[1][3]).toBe(1.0);   // ner
    expect(s1[1][4]).toBe(1.0);   // nrs
    expect(s1[1][5]).toBe(0.00);  // nts (capped=40, min=40 => 0/10 = 0)
    expect(s1[1][8]).toBe(true);  // has flagged attempts
    expect(s1[1][9]).toBe(1);     // flag count
  });
});

// ── Test: Edge — Empty Class ─────────────────────────────────────────────────

describe('CDS State Transition — Empty Class', () => {

  it('exercise with no enrolled students produces 0 processed', async () => {
    const exerciseId = 10;
    await runBatchCds(exerciseId, [], [], []);
    // With 0 students, no writes happen
    const dbCalls = db.query.mock.calls.filter(c => c[0].includes('cds_scores') || c[0].includes('cds_snapshots'));
    expect(dbCalls.length).toBe(0);
  });
});

// ── Test: Edge — getLivePeerRanking ──────────────────────────────────────────

describe('CDS State Transition — getLivePeerRanking NULLS LAST', () => {

  it('students with null CDS appear at end of ranking', async () => {
    db.query.mockResolvedValueOnce({ rows: [
      { student_id: 3, name: 'C', cds: 0.8, classification: 'High' },
      { student_id: 1, name: 'A', cds: 0.5, classification: 'Moderate' },
      { student_id: 2, name: 'B', cds: null, classification: 'Unscored' },
    ] });

    const ranking = await getLivePeerRanking(10, db);
    expect(ranking).toHaveLength(3);
    // ORDER BY cs.cds DESC NULLS LAST → 0.8, 0.5, null
    expect(ranking[0].cds).toBe(0.8);
    expect(ranking[1].cds).toBe(0.5);
    expect(ranking[2].cds).toBeNull();
    expect(ranking[0].rank).toBe(1);
    expect(ranking[1].rank).toBe(2);
    expect(ranking[2].rank).toBe(3);
  });
});

// ── Test: Edge — Exercise Not Found ──────────────────────────────────────────

describe('CDS State Transition — Exercise Not Found', () => {

  it('computeBatchCDS throws for nonexistent exercise', async () => {
    db.query.mockResolvedValueOnce({ rows: [] });
    await expect(computeBatchCDS(999, db)).rejects.toThrow('Exercise not found');
    expect(db.query).toHaveBeenCalledTimes(1);
  });

  it('calculateLiveCDS returns null for nonexistent exercise', async () => {
    db.query.mockResolvedValueOnce({ rows: [] });
    const result = await calculateLiveCDS(1, 999, db);
    expect(result).toBeNull();
  });
});

// ── Test: Edge — Mixed Flag Types Parity ─────────────────────────────────────

describe('CDS State Transition — Mixed Flag Types Parity', () => {

  it('BLANK_TEMPLATE and HARDCODING excluded from normalization equally', async () => {
    const exerciseId = 10;
    const students = [makeStudent(1, 'Blank'), makeStudent(2, 'Hardcode'), makeStudent(3, 'NormA'), makeStudent(4, 'NormB')];
    const excluded = [{ student_id: 1 }, { student_id: 2 }];
    const subs = [
      { student_id: 1, attempt_number: 1, is_correct: false, time_spent_seconds: 999, code: '',    is_verified: true, flag_id: 42 },
      { student_id: 2, attempt_number: 1, is_correct: true,  time_spent_seconds: 888, code: 'bad', is_verified: true, flag_id: 43 },
      { student_id: 3, attempt_number: 1, is_correct: true,  time_spent_seconds: 30,  code: 'good', is_verified: true, flag_id: null },
      { student_id: 4, attempt_number: 1, is_correct: true,  time_spent_seconds: 60,  code: 'good', is_verified: true, flag_id: null },
    ];

    await runBatchCds(exerciseId, students, excluded, subs);
    const scores = getScoreCalls();

    expect(scores).toHaveLength(4);
    const blank    = scores.find(c => c[1][0] === 1);
    const hardcode = scores.find(c => c[1][0] === 2);
    const normA    = scores.find(c => c[1][0] === 3);
    const normB    = scores.find(c => c[1][0] === 4);

    // Both flagged → CDS=1
    expect(blank[1][6]).toBe(1);
    expect(hardcode[1][6]).toBe(1);

    // Normal students: both have failed=0, total=1
    // failedValues=[0,0] → hasVariance=false → ner=0.00
    // totalValues=[1,1] → hasVariance=false → nrs=0.00
    // timeValues=[30,60] → min=30, p95=ceil(2*0.95)-1=1, p95=60, denom=30
    // normA: nts=(30-30)/30=0.00
    // normB: nts=(60-30)/30=1.00
    expect(normA[1][3]).toBe(0.00);  // ner
    expect(normA[1][4]).toBe(0.00);  // nrs
    expect(normA[1][5]).toBe(0.00);  // nts
    // Student 4 (NormB): nts=(60-30)/30 = 1.0
    expect(normB[1][5]).toBe(1.00);
  });
});
