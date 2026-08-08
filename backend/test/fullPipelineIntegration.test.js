/**
 * Full Pipeline Integration Test
 *
 * Tests the complete data flow from submission → CDS scoring → integrity
 * flagging → alert generation using the real PostgreSQL test database.
 *
 * Fills the gap between unit tests (isolated logic) and E2E tests
 * (browser-automated full stack): validates that services wire correctly
 * with real database operations across the entire pipeline.
 *
 * Each test seeds its own data because setup.js has a global afterEach
 * that clears all tables.
 *
 * Requires: PostgreSQL running locally with `codeinsight_test` database
 * and schema loaded.
 */

const { Pool } = require('pg');
const cdsEngine = require('../services/cdsEngine');
const alertEngine = require('../services/alertEngine');
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

describe('Full Pipeline Integration — Submission → CDS → Alert', function() {
  beforeEach(async () => {
    await clearTestTables();
  });

  it('seeds a complete scenario with instructor, section, concept, exercise, and enrolled students', async () => {
    const scenario = await seedFullScenario({ studentCount: 5, exercise: { timeLimit: 60 } });
    strictEqual(scenario.studentIds.length, 5, 'student count');
    ok(scenario.instructorId > 0, 'instructor id');
    ok(scenario.sectionId > 0, 'section id');
    ok(scenario.conceptId > 0, 'concept id');
    ok(scenario.exerciseId > 0, 'exercise id');
  });

  it('submits correct and incorrect attempts for each student, then computes CDS and generates alerts', async () => {
    const scenario = await seedFullScenario({ studentCount: 5, exercise: { timeLimit: 60 } });

    // Submit 3 attempts per student (first 2 incorrect, 3rd varies)
    for (let i = 0; i < scenario.studentIds.length; i++) {
      const sid = scenario.studentIds[i];
      const isCorrect = i < 3; // students 0-2 eventually get it right

      for (let attempt = 1; attempt <= 3; attempt++) {
        await seedSubmission(sid, scenario.exerciseId, {
          attemptNumber: attempt,
          isCorrect: attempt === 3 ? isCorrect : false,
          timeSpent: 30 + attempt * 10,
          code: '#include <iostream>\nint main() { int x = 1; return x; }',
          testResults: [
            { passed: attempt === 3 },
            { passed: attempt === 3 },
          ],
        });
      }
    }

    // Verify 15 submissions
    const { rows: countRows } = await testPool.query(
      'SELECT COUNT(*) AS cnt FROM submissions WHERE exercise_id = $1',
      [scenario.exerciseId]
    );
    strictEqual(parseInt(countRows[0].cnt), 15, 'submission count');

    // Compute batch CDS
    const cdsResult = await cdsEngine.computeBatchCDS(scenario.exerciseId, testPool);
    ok(cdsResult, 'batch CDS result exists');

    const { rows: scoreRows } = await testPool.query(
      'SELECT COUNT(*) AS cnt FROM cds_scores WHERE exercise_id = $1',
      [scenario.exerciseId]
    );
    const scoreCount = parseInt(scoreRows[0].cnt);
    ok(scoreCount > 0, `CDS scores exist (${scoreCount})`);
    ok(scoreCount <= 5, 'at most one score per student');

    // Verify snapshots created
    const { rows: snapRows } = await testPool.query(
      'SELECT COUNT(*) AS cnt FROM cds_snapshots WHERE exercise_id = $1',
      [scenario.exerciseId]
    );
    ok(parseInt(snapRows[0].cnt) > 0, 'CDS snapshots exist');

    // Generate alerts
    const alertResult = await alertEngine.generateAlerts(scenario.exerciseId, testPool);
    ok(alertResult, 'alert result exists');

    const { rows: alertRows } = await testPool.query(
      'SELECT COUNT(*) AS cnt FROM alerts WHERE exercise_id = $1',
      [scenario.exerciseId]
    );
    const alertCount = parseInt(alertRows[0].cnt);

    const { rows: highCds } = await testPool.query(
      "SELECT COUNT(*) AS cnt FROM cds_scores WHERE exercise_id = $1 AND classification = 'High'",
      [scenario.exerciseId]
    );
    strictEqual(alertCount, parseInt(highCds[0].cnt),
      'alerts match high-CDS count');
  });

  it('produces consistent CDS between live and batch computation', async () => {
    // 10 valid submitters → CONFIDENT tier → every student gets a real CDS value
    const scenario = await seedFullScenario({ studentCount: 10, exercise: { timeLimit: 60 } });

    // Submit the same pattern for each student
    for (const sid of scenario.studentIds) {
      for (let attempt = 1; attempt <= 3; attempt++) {
        await seedSubmission(sid, scenario.exerciseId, {
          attemptNumber: attempt,
          isCorrect: attempt >= 3,
          timeSpent: 30,
          code: `int main() { return ${attempt}; }`,
          testResults: [{ passed: attempt >= 3 }],
        });
      }
    }

    // Batch compute
    await cdsEngine.computeBatchCDS(scenario.exerciseId, testPool);

    // Compare with live
    const { rows: batchScores } = await testPool.query(
      'SELECT student_id, cds FROM cds_scores WHERE exercise_id = $1 ORDER BY student_id',
      [scenario.exerciseId]
    );

    for (const batch of batchScores) {
      const live = await cdsEngine.calculateLiveCDS(batch.student_id, scenario.exerciseId, testPool);
      ok(live, 'live CDS result');
      ok(typeof live.cds === 'number', 'live CDS is number');
      // Allow small floating point difference between batch (DB-stored) and live (computed fresh)
      ok(Math.abs(live.cds - parseFloat(batch.cds)) < 0.02,
        `CDS values match for student ${batch.student_id}`);
    }
  });

  it('maintains referential integrity across all pipeline tables', async () => {
    const scenario = await seedFullScenario({ studentCount: 2, exercise: { timeLimit: 60 } });

    for (const sid of scenario.studentIds) {
      await seedSubmission(sid, scenario.exerciseId, { attemptNumber: 1 });
    }
    await cdsEngine.computeBatchCDS(scenario.exerciseId, testPool);
    await alertEngine.generateAlerts(scenario.exerciseId, testPool);

    const checks = [
      { label: 'submissions reference valid exercises',
        query: `SELECT COUNT(*) FROM submissions s LEFT JOIN exercises e ON s.exercise_id = e.id WHERE e.id IS NULL` },
      { label: 'cds_scores reference valid exercises',
        query: `SELECT COUNT(*) FROM cds_scores cs LEFT JOIN exercises e ON cs.exercise_id = e.id WHERE e.id IS NULL` },
      { label: 'cds_scores reference valid students',
        query: `SELECT COUNT(*) FROM cds_scores cs LEFT JOIN users u ON cs.student_id = u.id WHERE u.id IS NULL` },
      { label: 'alerts reference valid exercises',
        query: `SELECT COUNT(*) FROM alerts a LEFT JOIN exercises e ON a.exercise_id = e.id WHERE e.id IS NULL` },
      { label: 'alerts reference valid students',
        query: `SELECT COUNT(*) FROM alerts a LEFT JOIN users u ON a.student_id = u.id WHERE u.id IS NULL` },
    ];

    for (const check of checks) {
      const { rows } = await testPool.query(check.query);
      strictEqual(parseInt(rows[0].count), 0, `${check.label}: no orphaned rows`);
    }
  });
});

describe('Full Pipeline Integration — Edge Cases', function() {
  beforeEach(async () => {
    await clearTestTables();
  });

  it('handles CDS computation for exercise with no submissions', async () => {
    const scenario = await seedFullScenario({ studentCount: 1 });
    const result = await cdsEngine.computeBatchCDS(scenario.exerciseId, testPool);
    ok(result, 'batch CDS returned without error');
  });

  it('handles alert generation when no CDS scores exist', async () => {
    const scenario = await seedFullScenario({ studentCount: 1 });
    await testPool.query('DELETE FROM cds_scores');
    const result = await alertEngine.generateAlerts(999999, testPool);
    ok(result, 'alert generation returned without error');
  });
});
