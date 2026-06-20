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
// computeBatchCDS makes: 4 prep queries (exercise, students, excludedFlags,
// submissions) + 2 bulk writes (cds_scores + cds_snapshots).

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

function getSnapshotCalls() {
  return db.query.mock.calls.filter(c => c[0].includes('cds_snapshots'));
}

function findStudentInBulkScore(sid) {
  const scoreCalls = getScoreCalls();
  if (scoreCalls.length === 0) return null;
  const params = scoreCalls[0][1];
  for (let i = 0; i < params.length; i += 10) {
    if (params[i] === sid) {
      return {
        sid: params[i],
        exercise_id: params[i + 1],
        section_id: params[i + 2],
        ner: params[i + 3],
        nrs: params[i + 4],
        nts: params[i + 5],
        cds: params[i + 6],
        classification: params[i + 7],
        hasFlagged: params[i + 8],
        flagCount: params[i + 9],
      };
    }
  }
  return null;
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

    expect(scores.length).toBe(1); // bulk INSERT
    for (const sid of [1, 2, 3]) {
      const s = findStudentInBulkScore(sid);
      expect(s.cds).toBe(0);
      expect(s.ner).toBe(0.00);
      expect(s.nrs).toBe(0.00);
      expect(s.nts).toBe(0.00);
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
    const s = findStudentInBulkScore(1);

    expect(s.cds).toBe(0);
    expect(s.classification).toBe('Prelim-Very Low');
  });
});

// ── Test: 3. All-Excluded Students (HARDCODING) ──────────────────────────────

describe('CDS State Transition — All Students Have HARDCODING Flags', () => {

  it('all HARDCODING students get CDS=null (not 0 or Unscored)', async () => {
    const exerciseId = 10;
    const students = [makeStudent(1, 'A'), makeStudent(2, 'B')];
    const excluded = [{ student_id: 1 }, { student_id: 2 }];
    const subs = [
      { student_id: 1, attempt_number: 1, is_correct: false, time_spent_seconds: 30, code: '#include<bits/stdc++.h>', is_verified: true, flag_id: 42 },
      { student_id: 2, attempt_number: 1, is_correct: true,  time_spent_seconds: 60, code: '#include<bits/stdc++.h>', is_verified: true, flag_id: 43 },
    ];

    await runBatchCds(exerciseId, students, excluded, subs);

    for (const sid of [1, 2]) {
      const s = findStudentInBulkScore(sid);
      expect(s.cds).toBeNull();
      expect(s.ner).toBeNull();
      expect(s.nrs).toBeNull();
      expect(s.nts).toBeNull();
      expect(s.classification).toBe('Flagged-Pending');
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
    expect(scores.length).toBe(1); // bulk INSERT

    for (const sid of [1, 2, 3]) {
      const s = findStudentInBulkScore(sid);
      expect(Number.isNaN(s.ner)).toBe(false);
      expect(Number.isNaN(s.nrs)).toBe(false);
      expect(Number.isNaN(s.nts)).toBe(false);
      expect(Number.isNaN(s.cds)).toBe(false);
      expect(typeof s.nts).toBe('number');
    }

    // Student 1 has null time → max_time=0 (due to || 0 in reduce)
    // normalizeWithStats(0, timeStats) → nts=0.00 (Math.max(0,0)/denom = 0)
    const student1Score = findStudentInBulkScore(1);
    expect(student1Score.nts).toBe(0.00);
  });
});

// ── Test: 5. HARDCODING vs BLANK_TEMPLATE Parity ─────────────────────────────

describe('CDS State Transition — HARDCODING + BLANK_TEMPLATE Both Get null CDS', () => {

  it('HARDCODING and BLANK_TEMPLATE students both get null CDS', async () => {
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

    const hardcoder = findStudentInBulkScore(1);
    const blankSub  = findStudentInBulkScore(2);
    const normal    = findStudentInBulkScore(3);

    expect(hardcoder.cds).toBeNull();
    expect(hardcoder.classification).toBe('Flagged-Pending');
    expect(blankSub.cds).toBeNull();
    expect(blankSub.classification).toBe('Flagged-Pending');

    // Student 3 (normal): single entry filteredSubMap → hasVariance=false → all 0 → CDS=0
    expect(normal.cds).toBe(0);
    expect(normal.ner).toBe(0.00);
    expect(normal.nrs).toBe(0.00);
    expect(normal.nts).toBe(0.00);
    expect(normal.classification).toBe('Very Low');
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
    const batchScore = findStudentInBulkScore(studentId);
    const batchCds = batchScore.cds;

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

  it('calculateLiveCDS returns CDS=null for flagged student (matches batch)', async () => {
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
    expect(liveResult.cds).toBeNull();
    expect(liveResult.classification).toBe('Flagged-Pending');
    expect(liveResult.ner).toBeNull();
    expect(liveResult.nrs).toBeNull();
    expect(liveResult.nts).toBeNull();
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
    const s1 = findStudentInBulkScore(1);

    expect(s1.ner).toBe(1.0);
    expect(s1.nrs).toBe(1.0);
    expect(s1.nts).toBe(0.00);
    expect(s1.hasFlagged).toBe(true);
    expect(s1.flagCount).toBe(1);
  });
});

// ── Test: Edge — Empty Class ─────────────────────────────────────────────────

describe('CDS State Transition — Empty Class', () => {

  it('exercise with no enrolled students produces 0 processed', async () => {
    const exerciseId = 10;
    await runBatchCds(exerciseId, [], [], []);
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

    const blank    = findStudentInBulkScore(1);
    const hardcode = findStudentInBulkScore(2);
    const normA    = findStudentInBulkScore(3);
    const normB    = findStudentInBulkScore(4);

    expect(blank).not.toBeNull();
    expect(hardcode).not.toBeNull();
    expect(normA).not.toBeNull();
    expect(normB).not.toBeNull();

    // Both flagged → CDS=null
    expect(blank.cds).toBeNull();
    expect(hardcode.cds).toBeNull();

    // Normal students: both have failed=0, total=1
    expect(normA.ner).toBe(0.00);
    expect(normA.nrs).toBe(0.00);
    expect(normA.nts).toBe(0.00);
    expect(normB.nts).toBe(1.00);
  });
});
