/**
 * Student Dashboard / Progress Section-Filter Leak Regression Tests
 * (E2E with real PostgreSQL)
 *
 * Guards against the bug where the "completed" count in the completion KPI was
 * computed globally (across all of the student's sections) while the "total"
 * was scoped to the active section. For a student enrolled in multiple
 * sections this produced impossible percentages (e.g. 280% = 14/5).
 *
 * Scenario: 1 instructor, 2 sections (A and B), 1 student enrolled in both,
 * 5 exercises in section A and 13 in section B, all with a correct submission.
 *   - /dashboard?sectionId=A  → total 5,  completed 5,  percentage 100
 *   - /dashboard?sectionId=B  → total 13, completed 13, percentage 100
 *   - /dashboard (no section) → total 18, completed 18, percentage 100
 *   - /progress mirrors the same expectations.
 *
 * Requires: PostgreSQL running locally with `codeinsight_test` database and
 * schema loaded (psql -d codeinsight_test -f schema.sql), matching the other
 * real-DB integration tests (see test/setup.js). Cleanup reuses setup.js's
 * clearTestTables (run in its global beforeAll/afterEach hooks).
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

process.env.JWT_SECRET = 'test-secret';

const http = require('http');
const express = require('express');
const jwt = require('jsonwebtoken');
const {
  pool: testPool,
  seedTestInstructor,
  seedTestConcept,
  seedEnrollment,
  clearTestTables,
} = require('./setup');

// ── Test app (real student router + real auth middleware, minimal plumbing) ─

let server;
let basePort;

const app = express();
app.use(express.json());
app.use('/api/student', require('../routes/student'));
// eslint-disable-next-line no-unused-vars
app.use((err, _req, res, _next) => {
  res.status(err.status || 500).json({ message: err.message || 'Internal Server Error' });
});

// ── Helpers ─────────────────────────────────────────────────────────────────

function request({ method, path, token }) {
  return new Promise((resolve, reject) => {
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
    req.end();
  });
}

function signToken(user) {
  // No jti → verifyToken skips the token_blacklist lookup.
  return jwt.sign({ id: user.id, name: user.name, email: user.email, role: user.role }, process.env.JWT_SECRET);
}

async function createSection(instructorId, name, courseCode) {
  const { rows } = await testPool.query(
    `INSERT INTO sections (name, course_code, instructor_id)
     VALUES ($1, $2, $3)
     RETURNING id`,
    [name, courseCode, instructorId]
  );
  return rows[0].id;
}

async function createExercise(sectionId, conceptId, title) {
  const { rows } = await testPool.query(
    `INSERT INTO exercises (section_id, concept_id, title, description, starter_code, test_cases, time_limit_minutes, is_draft)
     VALUES ($1, $2, $3, $4, $5, $6, $7, false)
     RETURNING id`,
    [
      sectionId,
      conceptId,
      title,
      'Section-filter leak regression fixture',
      '#include <iostream>\nint main() { return 0; }',
      JSON.stringify([{ input: '', expected_output: 'ok', hidden: false }]),
      10,
    ]
  );
  return rows[0].id;
}

async function seedCorrectSubmission(studentId, exerciseId) {
  await testPool.query(
    `INSERT INTO submissions
       (student_id, exercise_id, attempt_number, code, is_correct, time_spent_seconds, test_results, is_verified)
     VALUES ($1, $2, 1, $3, true, 30, $4, true)`,
    [studentId, exerciseId, 'int main() { return 0; }', JSON.stringify([{ passed: true }])]
  );
}

// Seeds 1 instructor, 2 sections, 1 student enrolled in both, 5 exercises in
// section A and 13 in section B, each with a correct submission.
async function seedScenario() {
  const instructorId = await seedTestInstructor();
  const conceptId = await seedTestConcept();
  const sectionA = await createSection(instructorId, 'Section A', 'CSA');
  const sectionB = await createSection(instructorId, 'Section B', 'CSB');

  const { rows } = await testPool.query(
    `INSERT INTO users (name, email, password_hash, role)
     VALUES ($1, $2, 'hashed_pw', 'student')
     RETURNING id`,
    ['Multi-Section Student', 'multisection@test.com']
  );
  const studentId = rows[0].id;
  await seedEnrollment(studentId, sectionA);
  await seedEnrollment(studentId, sectionB);

  const exerciseIdsA = [];
  for (let i = 0; i < 5; i++) {
    exerciseIdsA.push(await createExercise(sectionA, conceptId, `A Exercise ${i + 1}`));
  }
  const exerciseIdsB = [];
  for (let i = 0; i < 13; i++) {
    exerciseIdsB.push(await createExercise(sectionB, conceptId, `B Exercise ${i + 1}`));
  }

  for (const id of exerciseIdsA) await seedCorrectSubmission(studentId, id);
  for (const id of exerciseIdsB) await seedCorrectSubmission(studentId, id);

  return { studentId, sectionA, sectionB };
}

// ── Tests ───────────────────────────────────────────────────────────────────

describe('student dashboard / progress — section-filter completion leak', () => {
  beforeEach(async () => {
    await clearTestTables();
  });

  it('scopes /dashboard completion to the active section (no 280% leak)', async () => {
    const { studentId, sectionA, sectionB } = await seedScenario();
    const token = signToken({
      id: studentId, name: 'Multi-Section Student', email: 'multisection@test.com', role: 'student',
    });

    const resA = await request({ method: 'GET', path: `/api/student/dashboard?sectionId=${sectionA}`, token });
    expect(resA.status).toBe(200);
    expect(resA.body.completion.total).toBe(5);
    expect(resA.body.completion.completed).toBe(5);
    expect(resA.body.completion.percentage).toBe(100);

    const resB = await request({ method: 'GET', path: `/api/student/dashboard?sectionId=${sectionB}`, token });
    expect(resB.status).toBe(200);
    expect(resB.body.completion.total).toBe(13);
    expect(resB.body.completion.completed).toBe(13);
    expect(resB.body.completion.percentage).toBe(100);

    // No section → global scope across both enrollments.
    const resAll = await request({ method: 'GET', path: '/api/student/dashboard', token });
    expect(resAll.status).toBe(200);
    expect(resAll.body.completion.total).toBe(18);
    expect(resAll.body.completion.completed).toBe(18);
    expect(resAll.body.completion.percentage).toBe(100);
  });

  it('scopes /progress completion to the active section', async () => {
    const { studentId, sectionA, sectionB } = await seedScenario();
    const token = signToken({
      id: studentId, name: 'Multi-Section Student', email: 'multisection@test.com', role: 'student',
    });

    const resA = await request({ method: 'GET', path: `/api/student/progress?sectionId=${sectionA}`, token });
    expect(resA.status).toBe(200);
    expect(resA.body.completion.total).toBe(5);
    expect(resA.body.completion.completed).toBe(5);
    expect(resA.body.completion.percentage).toBe(100);

    const resB = await request({ method: 'GET', path: `/api/student/progress?sectionId=${sectionB}`, token });
    expect(resB.status).toBe(200);
    expect(resB.body.completion.total).toBe(13);
    expect(resB.body.completion.completed).toBe(13);
    expect(resB.body.completion.percentage).toBe(100);

    const resAll = await request({ method: 'GET', path: '/api/student/progress', token });
    expect(resAll.status).toBe(200);
    expect(resAll.body.completion.total).toBe(18);
    expect(resAll.body.completion.completed).toBe(18);
    expect(resAll.body.completion.percentage).toBe(100);
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