/**
 * Integration Test Setup
 *
 * Connects to the real PostgreSQL test database (codeinsight_test).
 * Provides seed data, cleanup, and test utilities for E2E tests.
 *
 * Requires: PostgreSQL running locally with `codeinsight_test` database
 *           and schema loaded (run: psql -d codeinsight_test -f schema.sql)
 */

const { Pool } = require('pg');

const testPool = new Pool({
  host:     process.env.TEST_DB_HOST || 'localhost',
  port:     process.env.TEST_DB_PORT || '5432',
  database: 'codeinsight_test',
  user:     process.env.TEST_DB_USER || 'codeuser',
  password: process.env.TEST_DB_PASSWORD || 'codepassword123',
  max: 5,
  idleTimeoutMillis: 10000,
});

// ── Seed Data ───────────────────────────────────────────────────────────────

async function seedTestUser() {
  const { rows } = await testPool.query(
    `INSERT INTO users (name, email, password_hash, role)
     VALUES ($1, $2, 'hashed_pw', $3)
     ON CONFLICT (email) DO UPDATE SET name=$1, role=$3
     RETURNING id`,
    ['Test Student', 'student@test.com', 'student']
  );
  return rows[0].id;
}

async function seedTestInstructor() {
  const { rows } = await testPool.query(
    `INSERT INTO users (name, email, password_hash, role)
     VALUES ($1, $2, 'hashed_pw', $3)
     ON CONFLICT (email) DO UPDATE SET name=$1, role=$3
     RETURNING id`,
    ['Test Instructor', 'instructor@test.com', 'instructor']
  );
  return rows[0].id;
}

async function seedTestSection(instructorId) {
  const { rows } = await testPool.query(
    `INSERT INTO sections (name, course_code, instructor_id)
     VALUES ($1, $2, $3)
     ON CONFLICT DO NOTHING
     RETURNING id`,
    ['Test Section', 'CS101', instructorId]
  );
  if (rows.length === 0) {
    const existing = await testPool.query(
      `SELECT id FROM sections WHERE name=$1 AND instructor_id=$2`,
      ['Test Section', instructorId]
    );
    return existing.rows[0].id;
  }
  return rows[0].id;
}

async function seedTestConcept() {
  const { rows } = await testPool.query(
    `INSERT INTO concepts (name)
     VALUES ($1)
     ON CONFLICT (name) DO UPDATE SET name=$1
     RETURNING id`,
    ['Loops']
  );
  return rows[0].id;
}

async function seedTestExercise(sectionId, conceptId, opts = {}) {
  const starterCode = opts.starterCode || '#include <iostream>\nusing namespace std;\nint main() {\n  return 0;\n}';
  const referenceSolution = opts.referenceSolution || null;

  const { rows } = await testPool.query(
    `INSERT INTO exercises (section_id, concept_id, title, description, starter_code, reference_solution, time_limit_minutes)
     VALUES ($1, $2, $3, $4, $5, $6, $7)
     RETURNING id`,
    [
      sectionId,
      conceptId,
      opts.title || 'Test Exercise',
      opts.description || 'Test Description',
      starterCode,
      referenceSolution,
      opts.timeLimit || 60
    ]
  );
  return rows[0].id;
}

async function seedEnrollment(studentId, sectionId) {
  await testPool.query(
    `INSERT INTO enrollments (student_id, section_id)
     VALUES ($1, $2)
     ON CONFLICT DO NOTHING`,
    [studentId, sectionId]
  );
}

async function seedSubmission(studentId, exerciseId, opts = {}) {
  // is_verified defaults to true: these fixtures seed submissions that
  // participate in CDS computation, which only processes verified
  // submissions (schema default is false; pass isVerified:false to opt out).
  const isVerified = opts.isVerified !== undefined ? opts.isVerified : true;
  const { rows } = await testPool.query(
    `INSERT INTO submissions (student_id, exercise_id, attempt_number, code, is_correct, time_spent_seconds, test_results, is_verified)
     VALUES ($1, $2, $3, $4, $5, $6, $7, $8)
     RETURNING id`,
    [
      studentId,
      exerciseId,
      opts.attemptNumber || 1,
      opts.code || 'int main() { return 0; }',
      opts.isCorrect || false,
      opts.timeSpent || 30,
      JSON.stringify(opts.testResults || [{ passed: opts.isCorrect || false }]),
      isVerified
    ]
  );
  return rows[0].id;
}

// ── Cleanup ─────────────────────────────────────────────────────────────────

async function clearTestTables() {
  const tables = [
    'cds_job_queue', 'cds_snapshots', 'cds_scores', 'alerts', 'integrity_flags',
    'submissions', 'exercises', 'enrollments', 'sections',
    'concepts', 'users'
  ];
  for (const table of tables) {
    try {
      await testPool.query(`DELETE FROM ${table}`);
    } catch (e) {
      // Table might not exist or have no data — skip
    }
  }
  // Reset sequences
  await testPool.query(`
    ALTER SEQUENCE users_id_seq RESTART WITH 1;
    ALTER SEQUENCE sections_id_seq RESTART WITH 1;
    ALTER SEQUENCE concepts_id_seq RESTART WITH 1;
    ALTER SEQUENCE exercises_id_seq RESTART WITH 1;
    ALTER SEQUENCE submissions_id_seq RESTART WITH 1;
    ALTER SEQUENCE cds_scores_id_seq RESTART WITH 1;
    ALTER SEQUENCE cds_snapshots_id_seq RESTART WITH 1;
    ALTER SEQUENCE alerts_id_seq RESTART WITH 1;
    ALTER SEQUENCE integrity_flags_id_seq RESTART WITH 1;
    ALTER SEQUENCE cds_job_queue_id_seq RESTART WITH 1;
  `);
}

// ── Full Seed (one-call setup for a typical test) ────────────────────────────

async function seedFullScenario(opts = {}) {
  await clearTestTables();

  const instructorId = await seedTestInstructor();
  const sectionId = await seedTestSection(instructorId);
  const conceptId = await seedTestConcept();
  const exerciseId = await seedTestExercise(sectionId, conceptId, opts.exercise || {});

  const studentIds = [];
  const studentCount = opts.studentCount || 3;
  for (let i = 0; i < studentCount; i++) {
    const { rows } = await testPool.query(
      `INSERT INTO users (name, email, password_hash, role)
       VALUES ($1, $2, 'hashed_pw', 'student')
       ON CONFLICT (email) DO NOTHING
       RETURNING id`,
      [`Test Student ${i}`, `student${i}@test.com`]
    );
    const sid = rows.length > 0 ? rows[0].id :
      (await testPool.query(`SELECT id FROM users WHERE email=$1`, [`student${i}@test.com`])).rows[0].id;
    await seedEnrollment(sid, sectionId);
    studentIds.push(sid);
  }

  return { instructorId, sectionId, conceptId, exerciseId, studentIds };
}

// ── Global Setup/Teardown ────────────────────────────────────────────────────

beforeAll(async () => {
  await clearTestTables();
});

afterEach(async () => {
  await clearTestTables();
});

afterAll(async () => {
  await testPool.end();
});

module.exports = {
  pool: testPool,
  seedTestUser,
  seedTestInstructor,
  seedTestSection,
  seedTestConcept,
  seedTestExercise,
  seedEnrollment,
  seedSubmission,
  seedFullScenario,
  clearTestTables,
};
