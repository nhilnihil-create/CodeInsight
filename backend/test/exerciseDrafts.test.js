/**
 * Exercise Drafts Integration Tests (E2E with real PostgreSQL)
 *
 * Covers GET /api/exercises/drafts endpoint:
 *  1. Returns only drafts for the authenticated instructor
 *  2. Returns empty array for instructor with no drafts
 *  3. Excludes drafts from other instructors
 *  4. Includes concept_name and concept_tags
 *  5. Returns 403 for students
 *  6. Returns 401 for unauthenticated
 *  7. Ordered by created_at DESC
 */

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
  seedTestSection,
  seedTestConcept,
  clearTestTables,
} = require('./setup');

// ── Test app ──────────────────────────────────────────────────────────────

let server;
let basePort;

const app = express();
app.use(express.json());
app.use('/api/exercises', require('../routes/exercises'));
// eslint-disable-next-line no-unused-vars
app.use((err, _req, res, _next) => {
  res.status(err.status || 500).json({ message: err.message || 'Internal Server Error' });
});

// ── Helpers ───────────────────────────────────────────────────────────────

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
  return jwt.sign({ id: user.id, name: user.name, email: user.email, role: user.role }, process.env.JWT_SECRET);
}

async function seedExercise({ instructorId, sectionId, conceptId, title, isDraft, createdAt }) {
  const { rows } = await testPool.query(
    `INSERT INTO exercises (section_id, concept_id, title, description, created_by, is_draft, created_at)
     VALUES ($1, $2, $3, $4, $5, $6, $7)
     RETURNING id`,
    [sectionId, conceptId, title || 'Draft Ex', 'desc', instructorId, isDraft ?? true, createdAt || new Date()]
  );
  return rows[0].id;
}

// ── Server lifecycle ─────────────────────────────────────────────────────

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

describe('GET /api/exercises/drafts', () => {
  beforeEach(async () => {
    await clearTestTables();
  });

  it('returns only drafts for the authenticated instructor', async () => {
    const instructorId = await seedTestInstructor();
    const sectionId = await seedTestSection(instructorId);
    const conceptId = await seedTestConcept();

    const d1 = await seedExercise({ instructorId, sectionId, conceptId, title: 'Draft 1', isDraft: true });
    const d2 = await seedExercise({ instructorId, sectionId, conceptId, title: 'Draft 2', isDraft: true });
    await seedExercise({ instructorId, sectionId, conceptId, title: 'Published', isDraft: false });

    const token = signToken({
      id: instructorId, name: 'Test Instructor', email: 'instructor@test.com', role: 'instructor',
    });

    const res = await request({ method: 'GET', path: '/api/exercises/drafts', token });
    expect(res.status).toBe(200);
    expect(Array.isArray(res.body)).toBe(true);
    expect(res.body).toHaveLength(2);
    expect(res.body.every(r => r.is_draft === true)).toBe(true);
  });

  it('returns empty array for instructor with no drafts', async () => {
    const instructorId = await seedTestInstructor();

    const token = signToken({
      id: instructorId, name: 'Test Instructor', email: 'instructor@test.com', role: 'instructor',
    });

    const res = await request({ method: 'GET', path: '/api/exercises/drafts', token });
    expect(res.status).toBe(200);
    expect(res.body).toEqual([]);
  });

  it('excludes drafts from other instructors', async () => {
    const instructorA = await seedTestInstructor();
    const sectionA = await seedTestSection(instructorA);
    const conceptId = await seedTestConcept();

    // Create instructor B directly
    const { rows: bRows } = await testPool.query(
      `INSERT INTO users (name, email, password_hash, role)
       VALUES ($1, $2, 'hashed_pw', 'instructor')
       RETURNING id`,
      ['Instructor B', 'instructor.b@test.com']
    );
    const instructorB = bRows[0].id;
    const sectionB = await seedTestSection(instructorB);

    await seedExercise({ instructorId: instructorA, sectionId: sectionA, conceptId, title: 'A Draft', isDraft: true });
    await seedExercise({ instructorId: instructorB, sectionId: sectionB, conceptId, title: 'B Draft', isDraft: true });

    const tokenA = signToken({
      id: instructorA, name: 'Test Instructor', email: 'instructor@test.com', role: 'instructor',
    });

    const res = await request({ method: 'GET', path: '/api/exercises/drafts', token: tokenA });
    expect(res.status).toBe(200);
    expect(res.body).toHaveLength(1);
    expect(res.body[0].title).toBe('A Draft');
    expect(res.body[0].created_by).toBe(instructorA);
  });

  it('includes concept_name and concept_tags', async () => {
    const instructorId = await seedTestInstructor();
    const sectionId = await seedTestSection(instructorId);
    const conceptId = await seedTestConcept();

    const exerciseId = await seedExercise({ instructorId, sectionId, conceptId, title: 'Tagged Draft', isDraft: true });

    await testPool.query(
      `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary) VALUES ($1, $2, $3, $4)`,
      [exerciseId, conceptId, 1.0, true]
    );

    const token = signToken({
      id: instructorId, name: 'Test Instructor', email: 'instructor@test.com', role: 'instructor',
    });

    const res = await request({ method: 'GET', path: '/api/exercises/drafts', token });
    expect(res.status).toBe(200);
    expect(res.body).toHaveLength(1);

    const draft = res.body[0];
    expect(draft.concept_name).toBe('Loops');
    expect(Array.isArray(draft.concept_tags)).toBe(true);
    expect(draft.concept_tags).toHaveLength(1);
    expect(draft.concept_tags[0].concept_name).toBe('Loops');
    expect(Number(draft.concept_tags[0].weight)).toBeCloseTo(1.0);
    expect(draft.concept_tags[0].is_primary).toBe(true);
  });

  it('returns 403 for students', async () => {
    const { rows } = await testPool.query(
      `INSERT INTO users (name, email, password_hash, role) VALUES ($1, $2, 'x', 'student') RETURNING id`,
      ['Draft Student', 'draft.student@test.com']
    );
    const studentId = rows[0].id;

    const token = signToken({
      id: studentId, name: 'Draft Student', email: 'draft.student@test.com', role: 'student',
    });

    const res = await request({ method: 'GET', path: '/api/exercises/drafts', token });
    expect(res.status).toBe(403);
  });

  it('returns 401 for unauthenticated', async () => {
    const res = await request({ method: 'GET', path: '/api/exercises/drafts' });
    expect(res.status).toBe(401);
  });

  it('returns drafts ordered by created_at DESC', async () => {
    const instructorId = await seedTestInstructor();
    const sectionId = await seedTestSection(instructorId);
    const conceptId = await seedTestConcept();

    const now = new Date();
    const t1 = new Date(now.getTime() - 300000); // 5 min ago
    const t2 = new Date(now.getTime() - 200000); // ~3 min ago
    const t3 = new Date(now.getTime() - 100000); // ~1.5 min ago

    const id1 = await seedExercise({ instructorId, sectionId, conceptId, title: 'Oldest', isDraft: true, createdAt: t1 });
    const id2 = await seedExercise({ instructorId, sectionId, conceptId, title: 'Middle', isDraft: true, createdAt: t2 });
    const id3 = await seedExercise({ instructorId, sectionId, conceptId, title: 'Newest', isDraft: true, createdAt: t3 });

    const token = signToken({
      id: instructorId, name: 'Test Instructor', email: 'instructor@test.com', role: 'instructor',
    });

    const res = await request({ method: 'GET', path: '/api/exercises/drafts', token });
    expect(res.status).toBe(200);
    expect(res.body).toHaveLength(3);
    expect(res.body[0].id).toBe(id3);
    expect(res.body[1].id).toBe(id2);
    expect(res.body[2].id).toBe(id1);
  });
});
