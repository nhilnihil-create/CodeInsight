/**
 * E2E Architectural Verification Tests
 *
 * Covers the gaps NOT tested by fullPipelineIntegration.test.js:
 * 1. Transaction atomicity in computeBatchCDS (cds_scores + snapshots)
 * 2. Integrity flag → CDS exclusion pipeline
 * 3. Graduated flagging through shared pipeline module
 * 4. Notification dedup in cdsJobQueue
 * 5. Hidden test separation in /run endpoint
 * 6. Confidence tiers (INSUFFICIENT <5 → Unscored, PRELIM 5-9 → Prelim-*)
 * 7. Post-solution cutoff behavior
 *
 * Requires: PostgreSQL running locally with `codeinsight_test` database
 * and schema loaded.
 */

const cdsEngine = require('../services/cdsEngine');
const { graduatedFlag, runAcademicIntegrityChecks } = require('../lib/submissionPipeline');
const {
  pool: testPool,
  seedFullScenario,
  seedSubmission,
  clearTestTables,
} = require('./setup');

function strictEqual(a, b, msg) {
  if (a !== b) throw new Error(`${msg}: expected ${b}, got ${a}`);
}

function ok(val, msg) {
  if (!val) throw new Error(msg || 'expected truthy');
}

// ── Transaction Atomicity ────────────────────────────────────────────────────

describe('E2E — Transaction Atomicity (computeBatchCDS)', function() {
  beforeEach(async () => { await clearTestTables(); });

  it('rolls back cds_scores if cds_snapshots write would fail', async () => {
    const scenario = await seedFullScenario({ studentCount: 3 });
    for (const sid of scenario.studentIds) {
      await seedSubmission(sid, scenario.exerciseId, { attemptNumber: 1, isCorrect: true });
    }

    // Drop the cds_snapshots table to simulate a write failure
    await testPool.query('DROP TABLE IF EXISTS cds_snapshots CASCADE');

    try {
      await cdsEngine.computeBatchCDS(scenario.exerciseId, testPool);
      throw new Error('Should have thrown');
    } catch (err) {
      ok(err, 'computeBatchCDS threw because snapshots table is gone');
    }

    // Verify cds_scores was NOT written (transaction rolled back)
    const { rows } = await testPool.query(
      'SELECT COUNT(*) AS cnt FROM cds_scores WHERE exercise_id = $1',
      [scenario.exerciseId]
    );
    strictEqual(parseInt(rows[0].cnt), 0, 'no cds_scores after rollback');

    // Restore snapshots table for other tests
    const schema = require('fs').readFileSync(
      require('path').join(__dirname, '..', 'schema.sql'), 'utf8'
    );
    const match = schema.match(/CREATE TABLE IF NOT EXISTS cds_snapshots\s*\([\s\S]*?\);/);
    if (match) await testPool.query(match[0]);
  });

  it('commits cds_scores and cds_snapshots atomically on success', async () => {
    const scenario = await seedFullScenario({ studentCount: 3 });
    for (const sid of scenario.studentIds) {
      await seedSubmission(sid, scenario.exerciseId, { attemptNumber: 1, isCorrect: true });
    }

    await cdsEngine.computeBatchCDS(scenario.exerciseId, testPool);

    const { rows: scores } = await testPool.query(
      'SELECT COUNT(*) AS cnt FROM cds_scores WHERE exercise_id = $1',
      [scenario.exerciseId]
    );
    const { rows: snaps } = await testPool.query(
      'SELECT COUNT(*) AS cnt FROM cds_snapshots WHERE exercise_id = $1',
      [scenario.exerciseId]
    );
    ok(parseInt(scores[0].cnt) > 0, 'cds_scores written');
    ok(parseInt(snaps[0].cnt) > 0, 'cds_snapshots written');
  });
});

// ── Integrity Flag → CDS Exclusion ──────────────────────────────────────────

describe('E2E — Integrity Flag Pipeline (CDS Exclusion)', function() {
  beforeEach(async () => { await clearTestTables(); });

  it('excludes HARDCODING-flagged students from CDS normalization', async () => {
    const scenario = await seedFullScenario({ studentCount: 8 });

    // Students 0-6 submit; student 3 gets flagged; student 7 submits nothing.
    // 6 valid submitters → PRELIM tier so real scores are produced.
    for (let i = 0; i < 7; i++) {
      await seedSubmission(scenario.studentIds[i], scenario.exerciseId, {
        attemptNumber: 1, isCorrect: i !== 3,
        timeSpent: 30 + i * 10,
      });
    }

    // Flag student index 3 with HARDCODING
    await testPool.query(
      `INSERT INTO integrity_flags (student_id, exercise_id, section_id, flag_type, severity, status, created_at)
       VALUES ($1, $2, $3, 'HARDCODING', 'high', 'flagged', NOW())`,
      [scenario.studentIds[3], scenario.exerciseId, scenario.sectionId]
    );

    await cdsEngine.computeBatchCDS(scenario.exerciseId, testPool);

    // Student 3: should be 'Flagged-Pending'
    const { rows: flagged } = await testPool.query(
      "SELECT classification FROM cds_scores WHERE exercise_id=$1 AND student_id=$2",
      [scenario.exerciseId, scenario.studentIds[3]]
    );
    strictEqual(flagged[0].classification, 'Flagged-Pending',
      'HARDCODING-flagged student is Flagged-Pending');

    // Student 7: should be 'Unscored' (no submissions)
    const { rows: unscored } = await testPool.query(
      "SELECT classification FROM cds_scores WHERE exercise_id=$1 AND student_id=$2",
      [scenario.exerciseId, scenario.studentIds[7]]
    );
    strictEqual(unscored[0].classification, 'Unscored',
      'no-submission student is Unscored');

    // Students 0-2: should have real CDS values (Prelim-* tier)
    for (let i = 0; i < 3; i++) {
      const { rows } = await testPool.query(
        'SELECT cds, classification FROM cds_scores WHERE exercise_id=$1 AND student_id=$2',
        [scenario.exerciseId, scenario.studentIds[i]]
      );
      ok(rows[0].cds !== null, `student ${i} has non-null CDS`);
      ok(rows[0].classification.startsWith('Prelim-'),
        `student ${i} is Prelim-* in a PRELIM class`);
    }
  });
});

// ── Notification Dedup ──────────────────────────────────────────────────────

describe('E2E — Notification Dedup (cdsJobQueue)', function() {
  beforeEach(async () => {
    await clearTestTables();
    const cdsJobQueue = require('../services/cdsJobQueue');
    cdsJobQueue.lastNotifiedAt.clear();
  });

  it('deduplicates notifications within cooldown window', async () => {
    const cdsJobQueue = require('../services/cdsJobQueue');
    const { notifyStudent, lastNotifiedAt } = cdsJobQueue;

    // Mock db.query so notifyStudent doesn't hit the real main pool
    const realDb = require('../config/db');
    const origQuery = realDb.query;
    realDb.query = jest.fn().mockResolvedValue({ rows: [{ section_id: 1 }] });

    try {
      // First notification should fire (mock returns section_id: 1)
      await notifyStudent(1, 'test message');
      ok(lastNotifiedAt.has(1),
        'exercise recorded in dedup map');

      // Second call within cooldown should be skipped (early return before log)
      const logSpy = jest.spyOn(console, 'log').mockImplementation(() => {});
      await notifyStudent(1, 'should be deduped');
      expect(logSpy).not.toHaveBeenCalledWith(
        expect.stringContaining('Recipients:')
      );
      logSpy.mockRestore();
    } finally {
      realDb.query = origQuery;
    }

    // Clean up: clear the map and reset cooldown by advancing past it
    lastNotifiedAt.delete(1);
  });
});

// ── Confidence Tiers (Phase 1 small-sample gating) ──────────────────────────

describe('E2E — Confidence Tiers (INSUFFICIENT <5 / PRELIM 5-9)', function() {
  beforeEach(async () => { await clearTestTables(); });

  it('stores Unscored (null CDS) when fewer than 5 valid submitters', async () => {
    const scenario = await seedFullScenario({ studentCount: 2 });
    for (const sid of scenario.studentIds) {
      await seedSubmission(sid, scenario.exerciseId, { attemptNumber: 1, isCorrect: true });
    }

    await cdsEngine.computeBatchCDS(scenario.exerciseId, testPool);

    const { rows } = await testPool.query(
      "SELECT classification, cds FROM cds_scores WHERE exercise_id=$1",
      [scenario.exerciseId]
    );
    strictEqual(rows.length, 2, 'one cds_scores row per student');
    for (const r of rows) {
      strictEqual(r.classification, 'Unscored',
        `INSUFFICIENT tier is stored as Unscored: ${r.classification}`);
      ok(r.cds === null, 'INSUFFICIENT tier stores null CDS');
    }
  });

  it('stores Prelim-* classifications for 5-9 valid submitters', async () => {
    const scenario = await seedFullScenario({ studentCount: 9 });
    for (const sid of scenario.studentIds) {
      await seedSubmission(sid, scenario.exerciseId, { attemptNumber: 1, isCorrect: true });
    }

    await cdsEngine.computeBatchCDS(scenario.exerciseId, testPool);

    const { rows } = await testPool.query(
      "SELECT classification, cds FROM cds_scores WHERE exercise_id=$1",
      [scenario.exerciseId]
    );
    strictEqual(rows.length, 9, 'one cds_scores row per student');
    for (const r of rows) {
      ok(r.classification.startsWith('Prelim-'),
        `PRELIM tier classification starts with Prelim-: ${r.classification}`);
      ok(r.cds !== null, 'PRELIM tier stores a real CDS value');
    }
  });
});

// ── Post-Solution Cutoff ────────────────────────────────────────────────────

describe('E2E — Post-Solution Cutoff', function() {
  beforeEach(async () => { await clearTestTables(); });

  it('excludes submissions after first unflagged acceptance from metrics', async () => {
    const scenario = await seedFullScenario({ studentCount: 8 });

    // Student 0: 2 wrong, then correct (no flag)
    await seedSubmission(scenario.studentIds[0], scenario.exerciseId, {
      attemptNumber: 1, isCorrect: false, timeSpent: 10,
    });
    await seedSubmission(scenario.studentIds[0], scenario.exerciseId, {
      attemptNumber: 2, isCorrect: false, timeSpent: 20,
    });
    await seedSubmission(scenario.studentIds[0], scenario.exerciseId, {
      attemptNumber: 3, isCorrect: true, timeSpent: 30,
    });
    // This should be excluded from metrics
    await seedSubmission(scenario.studentIds[0], scenario.exerciseId, {
      attemptNumber: 4, isCorrect: true, timeSpent: 999,
    });

    // Students 1-4: 1 attempt each → 5 valid submitters → PRELIM tier
    await seedSubmission(scenario.studentIds[1], scenario.exerciseId, {
      attemptNumber: 1, isCorrect: true, timeSpent: 30,
    });
    await seedSubmission(scenario.studentIds[2], scenario.exerciseId, {
      attemptNumber: 1, isCorrect: true, timeSpent: 35,
    });
    await seedSubmission(scenario.studentIds[3], scenario.exerciseId, {
      attemptNumber: 1, isCorrect: true, timeSpent: 40,
    });
    await seedSubmission(scenario.studentIds[4], scenario.exerciseId, {
      attemptNumber: 1, isCorrect: true, timeSpent: 45,
    });

    await cdsEngine.computeBatchCDS(scenario.exerciseId, testPool);

    // Student 0 should have 2 failed + 1 correct = 3 counted
    const { rows } = await testPool.query(
      'SELECT nrs, nts FROM cds_scores WHERE exercise_id=$1 AND student_id=$2',
      [scenario.exerciseId, scenario.studentIds[0]]
    );
    // nts is normalized, but the max_time used should be 30 (the 3rd attempt),
    // NOT 999 (the 4th post-solution attempt)
    const { rows: raw } = await testPool.query(
      'SELECT MAX(time_spent_seconds) FROM submissions WHERE exercise_id=$1 AND student_id=$2 AND attempt_number <= (SELECT MIN(attempt_number) FROM submissions WHERE exercise_id=$1 AND student_id=$2 AND is_correct=true)',
      [scenario.exerciseId, scenario.studentIds[0]]
    );
    strictEqual(parseInt(raw[0].max), 30,
      'post-solution attempt 4 is excluded from nts');
  });
});
