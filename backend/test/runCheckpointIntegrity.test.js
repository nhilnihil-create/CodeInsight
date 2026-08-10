/**
 * Run-Checkpoint Integrity Integration Tests (E2E with real PostgreSQL)
 *
 * Covers the /run → run_attempts snapshot + background checkpoint pipeline:
 *  1. POST /api/student/exercises/:id/run persists the per-run behavioral
 *     snapshot (tab_switch_count, paste_count, time_spent_seconds, line_count)
 *     and computes code_growth_delta on subsequent runs.
 *  2. Repeated runs with tabSwitchCount >= 5 upsert a single
 *     PASSIVE_BEHAVIOR_LOG integrity flag whose run_id tracks the latest run
 *     (evidence merged, context_behaviors deduped, submission_id left NULL).
 *  3. GET /api/sections/:section_id/exercises submitted_count counts DISTINCT
 *     students across submissions (no enrollment filter) while total_students
 *     counts enrollments only.
 *  4. POST /api/student/behavioral-events is insert-only and does not mutate
 *     submission.tab_switch_count / paste_count.
 *
 * Requires: PostgreSQL running locally with `codeinsight_test` database and
 * schema loaded (psql -d codeinsight_test -f schema.sql), matching the other
 * real-DB integration tests (see test/setup.js). Cleanup reuses setup.js's
 * clearTestTables (run in its global beforeAll/afterEach hooks).
 *
 * Sandbox note: the /run route compiles C++ synchronously via
 * services/executor. To keep the suite fast and offline we stub the executor
 * with a canned successful result (no Docker/g++ invocation), mirroring the
 * mock-db style already used across backend/test (e.g. pasteCounting.test.js).
 */

// The app's config/db pool is pointed at the dev DB by backend/.env (loaded in
// jest.config.js). For these tests the route handlers' SQL must hit
// codeinsight_test, so config/db is mocked with a delegate to the test pool —
// the same DB the rest of the suite uses via test/setup.js.
jest.mock('../config/db', () => {
  const { pool } = require('./setup');
  return {
    query: (text, values) => pool.query(text, values),
    withTransaction: async (fn) => {
      const client = await pool.connect();
      try {
        await client.query('BEGIN');
        const result = await fn(client);
        await client.query('COMMIT');
        return result;
      } catch (err) {
        try { await client.query('ROLLBACK'); } catch (_) { /* ignore */ }
        throw err;
      } finally {
        client.release();
      }
    },
  };
});

// Stub the C++ sandbox: return a passing result without compiling. isHiddenTestCase
// mirrors the real implementation so visible/hidden semantics stay intact.
jest.mock('../services/executor', () => {
  const runAgainstTestCases = jest.fn();
  return {
    runAgainstTestCases,
    isHiddenTestCase: (tc) => {
      if (!tc) return false;
      if (tc.isVisible === false) return true;
      if (tc.hidden === true) return true;
      if (tc.is_hidden === true) return true;
      return false;
    },
  };
});

process.env.JWT_SECRET = 'test-secret';

const http = require('http');
const express = require('express');
const jwt = require('jsonwebtoken');
const {
  pool: testPool,
  seedTestInstructor,
  seedTestSection,
  seedTestConcept,
  seedEnrollment,
  clearTestTables,
} = require('./setup');
const executorMock = require('../services/executor');

// ── Test app (real routers + real auth middleware, minimal plumbing) ────────

let server;
let basePort;

const app = express();
app.use(express.json());
app.use('/api/student', require('../routes/student'));
app.use('/api/sections', require('../routes/sections'));
// eslint-disable-next-line no-unused-vars
app.use((err, _req, res, _next) => {
  res.status(err.status || 500).json({ message: err.message || 'Internal Server Error' });
});

// ── Helpers ─────────────────────────────────────────────────────────────────

function request({ method, path, token, body }) {
  return new Promise((resolve, reject) => {
    const payload = body === undefined ? null : JSON.stringify(body);
    const headers = { 'Content-Type': 'application/json', Connection: 'close' };
    if (token) headers.Authorization = `Bearer ${token}`;
    const req = http.request({
      host: '127.0.0.1',
      port: basePort,
      method,
      path,
      headers,
    }, (res) => {
      let raw = '';
      res.setEncoding('utf8');
      res.on('data', (chunk) => { raw += chunk; });
      res.on('end', () => {
        let parsed = null;
        try { parsed = JSON.parse(raw); } catch (_) { parsed = raw; }
        resolve({ status: res.statusCode, body: parsed });
      });
    });
    req.on('error', reject);
    if (payload) req.write(payload);
    req.end();
  });
}

function signToken(user) {
  // No jti → verifyToken skips the token_blacklist lookup.
  return jwt.sign({ id: user.id, name: user.name, email: user.email, role: user.role }, process.env.JWT_SECRET);
}

async function waitFor(predicate, { timeoutMs = 5000, intervalMs = 50 } = {}) {
  const deadline = Date.now() + timeoutMs;
  for (;;) {
    const value = await predicate();
    if (value) return value;
    if (Date.now() > deadline) throw new Error('waitFor: condition not met within timeout');
    await new Promise((r) => setTimeout(r, intervalMs));
  }
}

// Give deferred background checkpoints (setImmediate) a chance to finish before cleanup.
async function settleBackground() {
  await new Promise((r) => setImmediate(r));
  await new Promise((r) => setTimeout(r, 150));
}

async function createStudent(label) {
  const { rows } = await testPool.query(
    `INSERT INTO users (name, email, password_hash, role)
     VALUES ($1, $2, 'hashed_pw', 'student')
     RETURNING id`,
    [`RunCheck Student ${label}`, `runcheck.${label}@test.com`]
  );
  return rows[0].id;
}

async function createExercise(sectionId, conceptId, testCases) {
  const { rows } = await testPool.query(
    `INSERT INTO exercises (section_id, concept_id, title, description, starter_code, test_cases, time_limit_minutes)
     VALUES ($1, $2, $3, $4, $5, $6, $7)
     RETURNING id`,
    [
      sectionId,
      conceptId,
      'Run Checkpoint Exercise',
      'Integration fixture for /run + checkpoint tests',
      '#include <iostream>\nint main() { return 0; }',
      JSON.stringify(testCases),
      10,
    ]
  );
  return rows[0].id;
}

async function seedRunScenario() {
  const instructorId = await seedTestInstructor();
  const sectionId = await seedTestSection(instructorId);
  const conceptId = await seedTestConcept();
  const exerciseId = await createExercise(sectionId, conceptId, [
    { input: '', expected_output: 'ok', hidden: false },
  ]);
  return { instructorId, sectionId, conceptId, exerciseId };
}

const SAMPLE_CODE = '#include <iostream>\nint main() { std::cout << "ok" << std::endl; return 0; }';

// Default stubbed sandbox result: one visible test that passes.
executorMock.runAgainstTestCases.mockResolvedValue([
  { input: '', expected: 'ok', actual: 'ok', passed: true, status: 'Success', error: '', hidden: false },
]);

// ── Tests ───────────────────────────────────────────────────────────────────

describe('runCheckpoint integrity — run endpoint snapshot persistence', () => {
  beforeEach(async () => {
    await clearTestTables();
  });

  it('persists run_attempts with behavioral counts and returns a runId', async () => {
    const { exerciseId, sectionId } = await seedRunScenario();
    const studentId = await createStudent('snapshot');
    // The /run gate requires an active enrollment in the exercise's section.
    await seedEnrollment(studentId, sectionId);

    const res = await request({
      method: 'POST',
      path: `/api/student/exercises/${exerciseId}/run`,
      token: signToken({
        id: studentId, name: 'RunCheck Student snapshot', email: 'runcheck.snapshot@test.com', role: 'student',
      }),
      body: {
        code: SAMPLE_CODE,
        tabSwitchCount: 3,
        pasteCount: 2,
        timeSpentSeconds: 120,
        lineCount: 25,
      },
    });

    expect(res.status).toBe(200);
    expect(res.body.runId).toEqual(expect.any(Number));

    const { rows } = await testPool.query(
      `SELECT tab_switch_count, paste_count, time_spent_seconds, line_count, code_growth_delta
       FROM run_attempts WHERE student_id = $1 AND exercise_id = $2`,
      [studentId, exerciseId]
    );
    expect(rows).toHaveLength(1);
    expect(rows[0].tab_switch_count).toBe(3);
    expect(rows[0].paste_count).toBe(2);
    expect(rows[0].time_spent_seconds).toBe(120);
    expect(rows[0].line_count).toBe(25);
    expect(rows[0].code_growth_delta).toBe(0); // first run has no baseline

    await settleBackground();
  });

  it('computes code_growth_delta on a second run as new lineCount - old lineCount', async () => {
    const { exerciseId, sectionId } = await seedRunScenario();
    const studentId = await createStudent('growth');
    // The /run gate requires an active enrollment in the exercise's section.
    await seedEnrollment(studentId, sectionId);
    const token = signToken({
      id: studentId, name: 'RunCheck Student growth', email: 'runcheck.growth@test.com', role: 'student',
    });

    const first = await request({
      method: 'POST',
      path: `/api/student/exercises/${exerciseId}/run`,
      token,
      body: { code: SAMPLE_CODE, lineCount: 25 },
    });
    expect(first.status).toBe(200);

    const second = await request({
      method: 'POST',
      path: `/api/student/exercises/${exerciseId}/run`,
      token,
      body: { code: `${SAMPLE_CODE}\n// added line`, lineCount: 30 },
    });
    expect(second.status).toBe(200);
    expect(second.body.runId).not.toBe(first.body.runId);

    const { rows } = await testPool.query(
      `SELECT line_count, code_growth_delta FROM run_attempts WHERE id = $1`,
      [second.body.runId]
    );
    expect(rows).toHaveLength(1);
    expect(rows[0].line_count).toBe(30);
    expect(rows[0].code_growth_delta).toBe(5); // 30 - 25

    await settleBackground();
  });
});

describe('runCheckpoint integrity — behavioral flag upsert', () => {
  beforeEach(async () => {
    await clearTestTables();
  });

  it('upserts one PASSIVE_BEHAVIOR_LOG flag across two runs and points run_id at the latest run', async () => {
    const { exerciseId, sectionId } = await seedRunScenario();
    const studentId = await createStudent('flag');
    // The /run gate requires an active enrollment in the exercise's section.
    await seedEnrollment(studentId, sectionId);
    const token = signToken({
      id: studentId, name: 'RunCheck Student flag', email: 'runcheck.flag@test.com', role: 'student',
    });

    const run1 = await request({
      method: 'POST',
      path: `/api/student/exercises/${exerciseId}/run`,
      token,
      body: { code: SAMPLE_CODE, tabSwitchCount: 5, lineCount: 10 },
    });
    expect(run1.status).toBe(200);

    // The run checkpoint is deferred (setImmediate); wait until run 1's flag
    // lands so run 2's checkpoint is guaranteed to hit the upsert path.
    await waitFor(async () => {
      const { rows } = await testPool.query(
        `SELECT run_id FROM integrity_flags
         WHERE exercise_id = $1 AND student_id = $2 AND flag_type = 'PASSIVE_BEHAVIOR_LOG'`,
        [exerciseId, studentId]
      );
      return rows.length > 0 && rows[0].run_id === run1.body.runId ? rows[0] : null;
    });

    const run2 = await request({
      method: 'POST',
      path: `/api/student/exercises/${exerciseId}/run`,
      token,
      body: { code: SAMPLE_CODE, tabSwitchCount: 6, lineCount: 12 },
    });
    expect(run2.status).toBe(200);
    expect(run2.body.runId).not.toBe(run1.body.runId);

    // Poll until the flag has been re-pointed at the latest run.
    const flag = await waitFor(async () => {
      const { rows } = await testPool.query(
        `SELECT * FROM integrity_flags
         WHERE exercise_id = $1 AND student_id = $2 AND flag_type = 'PASSIVE_BEHAVIOR_LOG'`,
        [exerciseId, studentId]
      );
      return rows.length > 0 && rows[0].run_id === run2.body.runId ? rows[0] : null;
    });

    // Upsert — exactly one flag row for (exercise, student).
    const { rows: countRows } = await testPool.query(
      `SELECT COUNT(*)::int AS n FROM integrity_flags
       WHERE exercise_id = $1 AND student_id = $2 AND flag_type = 'PASSIVE_BEHAVIOR_LOG'`,
      [exerciseId, studentId]
    );
    expect(countRows[0].n).toBe(1);

    expect(flag.run_id).toBe(run2.body.runId); // tracks the latest run
    expect(flag.submission_id).toBeNull();     // run-level flag: no submission yet
    // Evidence is merged (jsonb ||); the latest run's values win for shared keys.
    expect(flag.evidence.tab_switch_count).toBe(6);
    // context_behaviors are deduped across upserts.
    expect(flag.context_behaviors).toEqual(['PASSIVE_BEHAVIOR_LOG']);

    // Let the remainder of the deferred checkpoint (integrity + anomaly steps)
    // finish so nothing lands in the DB after cleanup.
    await settleBackground();
  });
});

describe('runCheckpoint integrity — getSectionExercises submitted_count', () => {
  beforeEach(async () => {
    await clearTestTables();
  });

  it('counts distinct students across submissions (including un-enrolled) while total_students counts enrollments only', async () => {
    const { instructorId, sectionId, exerciseId } = await seedRunScenario();

    const studentA = await createStudent('a');
    const studentB = await createStudent('b');
    const studentC = await createStudent('c'); // never enrolled in the section
    await seedEnrollment(studentA, sectionId);
    await seedEnrollment(studentB, sectionId);

    // 2 submissions from the un-enrolled student, 1 from an enrolled student.
    for (const attemptNumber of [1, 2]) {
      await testPool.query(
        `INSERT INTO submissions
           (student_id, exercise_id, attempt_number, code, is_correct, time_spent_seconds, test_results, is_verified)
         VALUES ($1, $2, $3, $4, $5, $6, '[]', true)`,
        [studentC, exerciseId, attemptNumber, 'int main() { return 0; }', false, 30]
      );
    }
    await testPool.query(
      `INSERT INTO submissions
         (student_id, exercise_id, attempt_number, code, is_correct, time_spent_seconds, test_results, is_verified)
       VALUES ($1, $2, 1, $3, $4, 30, '[]', true)`,
      [studentA, exerciseId, 'int main() { return 1; }', false]
    );

    const res = await request({
      method: 'GET',
      path: `/api/sections/${sectionId}/exercises`,
      token: signToken({
        id: instructorId, name: 'Test Instructor', email: 'instructor@test.com', role: 'instructor',
      }),
    });

    expect(res.status).toBe(200);
    expect(Array.isArray(res.body)).toBe(true);
    const row = res.body.find((ex) => ex.id === exerciseId);
    expect(row).toBeTruthy();
    expect(row.submitted_count).toBe(2); // distinct students: A (enrolled) + C (un-enrolled)
    expect(row.total_students).toBe(2);  // enrollments only: A + B
  });
});

describe('runCheckpoint integrity — behavioral-events is insert-only', () => {
  beforeEach(async () => {
    await clearTestTables();
  });

  it('records paste/tab_switch events without mutating the submission snapshot counts', async () => {
    const { exerciseId } = await seedRunScenario();
    const studentId = await createStudent('events');
    const token = signToken({
      id: studentId, name: 'RunCheck Student events', email: 'runcheck.events@test.com', role: 'student',
    });

    // Seed a submission with a non-zero behavioral snapshot.
    await testPool.query(
      `INSERT INTO submissions
         (student_id, exercise_id, attempt_number, code, is_correct, time_spent_seconds,
          test_results, is_verified, tab_switch_count, paste_count)
       VALUES ($1, $2, 1, $3, false, 60, '[]', true, 7, 4)`,
      [studentId, exerciseId, 'int main() { return 0; }']
    );

    const now = new Date().toISOString();
    const res = await request({
      method: 'POST',
      path: '/api/student/behavioral-events',
      token,
      body: {
        exerciseId,
        events: [
          { type: 'paste', timestamp: now, payload: { chars: 40 } },
          { type: 'tab_switch', timestamp: now },
          { type: 'not_a_real_event', timestamp: now },
        ],
      },
    });

    expect(res.status).toBe(200);
    // Route echoes the count of events received; invalid types are skipped during insert.
    expect(res.body.received).toBe(3);

    const { rows: events } = await testPool.query(
      `SELECT event_type FROM behavioral_events WHERE student_id = $1 AND exercise_id = $2 ORDER BY id`,
      [studentId, exerciseId]
    );
    expect(events.map((e) => e.event_type)).toEqual(['paste', 'tab_switch']);

    // Insert-only: the submission snapshot is untouched.
    const { rows } = await testPool.query(
      `SELECT tab_switch_count, paste_count FROM submissions WHERE student_id = $1 AND exercise_id = $2`,
      [studentId, exerciseId]
    );
    expect(rows).toHaveLength(1);
    expect(rows[0].tab_switch_count).toBe(7); // unchanged
    expect(rows[0].paste_count).toBe(4);      // unchanged
  });
});

// ── Server lifecycle ─────────────────────────────────────────────────────────

beforeAll(async () => {
  server = app.listen(0, '127.0.0.1');
  await new Promise((resolve) => server.once('listening', resolve));
  basePort = server.address().port;
});

afterAll(async () => {
  if (server) {
    await new Promise((resolve) => server.close(resolve));
  }
});
