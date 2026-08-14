/**
 * Export route integration tests (real PostgreSQL via test/setup.js).
 *
 * Ad-hoc express app + http server + jwt.sign helper (pattern from
 * runCheckpointIntegrity.test.js; no supertest dependency). config/db is
 * mocked with a delegate to the codeinsight_test pool.
 *
 * Covers: 401 no token, 403 student role, 403 foreign instructor, 400 bad
 * domain/format, 404 unknown section, 200 csv (BOM + Content-Disposition),
 * 200 xlsx, 200 json, and the legacy alias' 7-column shape.
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
const ExcelJS = require('exceljs');
const { parse } = require('csv-parse/sync');
const {
  pool: testPool,
  seedFullScenario,
} = require('./setup');

// ── Test app (real router + real auth middleware) ───────────────────────────

let server;
let basePort;

const app = express();
app.use(express.json());
app.use('/api/export', require('../routes/export'));
// Real error handler so Joi validation errors map to 400 (the route relies on it).
app.use(require('../middleware/errorHandler').errorHandler);

function request({ method, path, token }) {
  return new Promise((resolve, reject) => {
    const headers = { Connection: 'close' };
    if (token) headers.Authorization = `Bearer ${token}`;
    const req = http.request({
      host: '127.0.0.1',
      port: basePort,
      method,
      path,
      headers,
    }, (res) => {
      const chunks = [];
      res.on('data', (chunk) => chunks.push(chunk));
      res.on('end', () => {
        const buffer = Buffer.concat(chunks);
        const contentType = res.headers['content-type'] || '';
        const body = contentType.includes('application/json')
          ? JSON.parse(buffer.toString('utf8'))
          : buffer.toString('utf8');
        resolve({ status: res.statusCode, body, buffer, headers: res.headers });
      });
    });
    req.on('error', reject);
    req.end();
  });
}

function signToken(user) {
  return jwt.sign(
    { id: user.id, name: user.name, email: user.email, role: user.role },
    process.env.JWT_SECRET
  );
}

function instructorToken(id) {
  return signToken({ id, name: 'Test Instructor', email: 'instructor@test.com', role: 'instructor' });
}

const CSV_BOM_BYTES = Buffer.from([0xef, 0xbb, 0xbf]);
const stripBom = (text) => text.replace(/^\uFEFF/, '');
const parseCsv = (buffer) => parse(stripBom(buffer.toString('utf8')), {
  columns: true,
  skip_empty_lines: true,
});

// ── Tests ───────────────────────────────────────────────────────────────────

describe('export routes — auth and guards', () => {
  let seeded;

  beforeEach(async () => {
    seeded = await seedFullScenario({ studentCount: 3 });
  });

  it('401 when no token is provided', async () => {
    const res = await request({
      method: 'GET',
      path: `/api/export/roster/${seeded.sectionId}`,
    });
    expect(res.status).toBe(401);
  });

  it('403 for a student role', async () => {
    const studentId = seeded.studentIds[0];
    const res = await request({
      method: 'GET',
      path: `/api/export/roster/${seeded.sectionId}`,
      token: signToken({ id: studentId, name: 'Test Student 0', email: 'student0@test.com', role: 'student' }),
    });
    expect(res.status).toBe(403);
  });

  it('403 when an instructor exports another instructor\'s section', async () => {
    const { rows } = await testPool.query(
      `INSERT INTO users (name, email, password_hash, role) VALUES ($1, $2, 'hashed_pw', 'instructor') RETURNING id`,
      ['Foreign Instructor', 'foreign.instructor@test.com']
    );
    const foreignId = rows[0].id;

    const res = await request({
      method: 'GET',
      path: `/api/export/roster/${seeded.sectionId}`,
      token: instructorToken(foreignId),
    });
    expect(res.status).toBe(403);
  });
});

describe('export routes — canonical endpoint', () => {
  let seeded;

  beforeEach(async () => {
    seeded = await seedFullScenario({ studentCount: 3 });
  });

  it('400 for an unknown domain', async () => {
    const res = await request({
      method: 'GET',
      path: `/api/export/not-a-domain/${seeded.sectionId}`,
      token: instructorToken(seeded.instructorId),
    });
    expect(res.status).toBe(400);
    expect(res.body.message).toContain('not-a-domain');
  });

  it('400 for an unsupported format', async () => {
    const res = await request({
      method: 'GET',
      path: `/api/export/roster/${seeded.sectionId}?format=pdf`,
      token: instructorToken(seeded.instructorId),
    });
    expect(res.status).toBe(400);
  });

  it('404 for an unknown section', async () => {
    const res = await request({
      method: 'GET',
      path: '/api/export/roster/999999999',
      token: instructorToken(seeded.instructorId),
    });
    expect(res.status).toBe(404);
  });

  it('200 csv with UTF-8 BOM and RFC 5987 Content-Disposition filename', async () => {
    const res = await request({
      method: 'GET',
      path: `/api/export/roster/${seeded.sectionId}?format=csv`,
      token: instructorToken(seeded.instructorId),
    });

    expect(res.status).toBe(200);
    expect(res.headers['content-type']).toContain('text/csv');
    expect(res.buffer.subarray(0, 3)).toEqual(CSV_BOM_BYTES);

    const cd = res.headers['content-disposition'];
    expect(cd).toContain('attachment; filename=');
    expect(cd).toMatch(/filename="Test Section_roster_\d{4}-\d{2}-\d{2}\.csv"/);
    expect(cd).toContain(`filename*=UTF-8''${encodeURIComponent('Test Section_roster_')}`);

    const records = parseCsv(res.buffer);
    expect(records).toHaveLength(3);
    expect(Object.keys(records[0])).toEqual(['Student ID', 'Student Name', 'Student Email', 'Date of Enrollment']);
  });

  it('200 xlsx with a single roster sheet', async () => {
    const res = await request({
      method: 'GET',
      path: `/api/export/roster/${seeded.sectionId}?format=xlsx`,
      token: instructorToken(seeded.instructorId),
    });

    expect(res.status).toBe(200);
    expect(res.headers['content-type']).toContain('application/vnd.openxmlformats-officedocument.spreadsheetml.sheet');
    expect(res.headers['content-disposition']).toMatch(/filename=".+\.xlsx"/);

    const workbook = new ExcelJS.Workbook();
    await workbook.xlsx.load(res.buffer);
    expect(workbook.worksheets).toHaveLength(1);
    const ws = workbook.getWorksheet('roster');
    expect(ws).toBeTruthy();
    expect(ws.actualRowCount).toBe(4); // header + 3 students
    expect(ws.getRow(1).getCell(1).value).toBe('Student ID');
    expect(ws.getRow(1).getCell(4).value).toBe('Date of Enrollment');
  });

  it('200 json with raw rows', async () => {
    const res = await request({
      method: 'GET',
      path: `/api/export/roster/${seeded.sectionId}?format=json`,
      token: instructorToken(seeded.instructorId),
    });

    expect(res.status).toBe(200);
    expect(res.headers['content-type']).toContain('application/json');
    expect(Array.isArray(res.body)).toBe(true);
    expect(res.body).toHaveLength(3);
    expect(Object.keys(res.body[0]).sort()).toEqual(['email', 'enrolled_at', 'name', 'student_id']);
  });

  it('defaults to csv when format is omitted', async () => {
    const res = await request({
      method: 'GET',
      path: `/api/export/roster/${seeded.sectionId}`,
      token: instructorToken(seeded.instructorId),
    });
    expect(res.status).toBe(200);
    expect(res.headers['content-type']).toContain('text/csv');
    expect(res.buffer.subarray(0, 3)).toEqual(CSV_BOM_BYTES);
  });

  it('200 csv summary for the unified student summary domain', async () => {
    await testPool.query(
      `INSERT INTO cds_scores (student_id, exercise_id, section_id, cds, classification, computed_at)
       VALUES ($1, $2, $3, 0.7, 'moderate', $4)`,
      [seeded.studentIds[0], seeded.exerciseId, seeded.sectionId, '2026-04-05 08:00:00']
    );

    const res = await request({
      method: 'GET',
      path: `/api/export/summary/${seeded.sectionId}?format=csv`,
      token: instructorToken(seeded.instructorId),
    });

    expect(res.status).toBe(200);
    expect(res.headers['content-type']).toContain('text/csv');
    expect(res.headers['content-disposition']).toMatch(/filename="Test Section_summary_\d{4}-\d{2}-\d{2}\.csv"/);

    const records = parseCsv(res.buffer);
    expect(records).toHaveLength(1);
    expect(Object.keys(records[0])).toEqual([
      'Student ID', 'Student Name', 'Student Email', 'CDS (%)', 'Mastery (%)',
    ]);
    expect(records[0]['CDS (%)']).toBe('70.0');
  });

  it('400 when exporting student_attempts without a studentId', async () => {
    const res = await request({
      method: 'GET',
      path: `/api/export/student_attempts/${seeded.sectionId}`,
      token: instructorToken(seeded.instructorId),
    });

    expect(res.status).toBe(400);
    expect(res.body.message).toContain('studentId');
  });

  it('200 csv student_attempts for a single student', async () => {
    await testPool.query(
      `INSERT INTO submissions
         (student_id, exercise_id, attempt_number, code, is_correct, time_spent_seconds, test_results, is_verified, cds)
       VALUES ($1, $2, 1, 'int main() { return 0; }', true, 30, '[]', true, 0.55)`,
      [seeded.studentIds[0], seeded.exerciseId]
    );

    const res = await request({
      method: 'GET',
      path: `/api/export/student_attempts/${seeded.sectionId}?studentId=${seeded.studentIds[0]}`,
      token: instructorToken(seeded.instructorId),
    });

    expect(res.status).toBe(200);
    expect(res.headers['content-type']).toContain('text/csv');
    const records = parseCsv(res.buffer);
    expect(records).toHaveLength(1);
    expect(Object.keys(records[0])).toEqual([
      'Exercise', 'Attempt', 'Passed', 'CDS (%)', 'Mastery (%)', 'Submitted',
    ]);
    expect(records[0].Exercise).toBe('Test Exercise');
    expect(records[0]['CDS (%)']).toBe('55.0');
  });
});

describe('export routes — legacy alias /api/export/section/:sectionId', () => {
  let seeded;

  beforeEach(async () => {
    seeded = await seedFullScenario({ studentCount: 3 });
  });

  it('200 csv keeping the 7-column submissions shape with "12.3%" CDS', async () => {
    await testPool.query(
      `INSERT INTO submissions
         (student_id, exercise_id, attempt_number, code, is_correct, time_spent_seconds, test_results, is_verified, cds)
       VALUES ($1, $2, 1, $3, true, 30, '[]', true, 0.8534)`,
      [seeded.studentIds[0], seeded.exerciseId, 'int main() { return 0; }']
    );

    const res = await request({
      method: 'GET',
      path: `/api/export/section/${seeded.sectionId}?format=csv`,
      token: instructorToken(seeded.instructorId),
    });

    expect(res.status).toBe(200);
    expect(res.headers['content-type']).toContain('text/csv');
    expect(res.buffer.subarray(0, 3)).toEqual(CSV_BOM_BYTES);
    expect(res.headers['content-disposition']).toMatch(/filename=".+_submissions_\d{4}-\d{2}-\d{2}\.csv"/);

    const records = parseCsv(res.buffer);
    // Byte-compatible with the pre-overhaul endpoint: LEFT JOIN on submissions
    // over the 3 enrolled students → 3 rows (the submitter's row populated, the
    // other two empty), not roster + submission rows.
    expect(records).toHaveLength(3);
    expect(Object.keys(records[0])).toEqual([
      'Name', 'Email', 'Exercise', 'Attempt', 'Passed', 'CDS', 'Submitted',
    ]);
    expect(records[0].Code).toBeUndefined();

    const withSubmission = records.find((r) => r.CDS !== '');
    expect(withSubmission).toBeTruthy();
    expect(withSubmission.Passed).toBe('Yes');
    expect(withSubmission.CDS).toBe('85.3%');
    expect(withSubmission.Submitted).toMatch(/^\d{4}-\d{2}-\d{2}T\d{2}:\d{2}:\d{2}\.\d{3}Z$/);
  });

  it('200 xlsx for the legacy alias', async () => {
    const res = await request({
      method: 'GET',
      path: `/api/export/section/${seeded.sectionId}?format=xlsx`,
      token: instructorToken(seeded.instructorId),
    });

    expect(res.status).toBe(200);
    expect(res.headers['content-type']).toContain('application/vnd.openxmlformats-officedocument.spreadsheetml.sheet');

    const workbook = new ExcelJS.Workbook();
    await workbook.xlsx.load(res.buffer);
    const ws = workbook.getWorksheet('submissions');
    expect(ws).toBeTruthy();
    expect(ws.getRow(1).getCell(1).value).toBe('Name');
    expect(ws.getRow(1).getCell(7).value).toBe('Submitted');
  });

  it('400 for json on the legacy alias (csv|xlsx only)', async () => {
    const res = await request({
      method: 'GET',
      path: `/api/export/section/${seeded.sectionId}?format=json`,
      token: instructorToken(seeded.instructorId),
    });
    expect(res.status).toBe(400);
  });
});

describe('export routes — visual report (PDF)', () => {
  let seeded;

  beforeEach(async () => {
    seeded = await seedFullScenario({ studentCount: 3 });
  });

  it('401 when no token is provided', async () => {
    const res = await request({
      method: 'GET',
      path: `/api/export/visual-report/${seeded.sectionId}`,
    });
    expect(res.status).toBe(401);
  });

  it('403 when an instructor exports another instructor\'s section', async () => {
    const { rows } = await testPool.query(
      `INSERT INTO users (name, email, password_hash, role) VALUES ($1, $2, 'hashed_pw', 'instructor') RETURNING id`,
      ['Foreign Instructor VR', 'foreign.vr@test.com']
    );
    const res = await request({
      method: 'GET',
      path: `/api/export/visual-report/${seeded.sectionId}`,
      token: instructorToken(rows[0].id),
    });
    expect(res.status).toBe(403);
  });

  it('404 for an unknown section', async () => {
    const res = await request({
      method: 'GET',
      path: '/api/export/visual-report/999999999',
      token: instructorToken(seeded.instructorId),
    });
    expect(res.status).toBe(404);
  });

  it('200 application/pdf with a .pdf Content-Disposition filename', async () => {
    const res = await request({
      method: 'GET',
      path: `/api/export/visual-report/${seeded.sectionId}`,
      token: instructorToken(seeded.instructorId),
    });

    expect(res.status).toBe(200);
    expect(res.headers['content-type']).toContain('application/pdf');
    expect(res.buffer.subarray(0, 5).toString('latin1')).toBe('%PDF-');

    const cd = res.headers['content-disposition'];
    expect(cd).toContain('attachment; filename=');
    expect(cd).toMatch(/filename="Test Section_visual-report_\d{4}-\d{2}-\d{2}\.pdf"/);
  });

  it('200 pdf dossier when ?studentId is provided', async () => {
    const res = await request({
      method: 'GET',
      path: `/api/export/visual-report/${seeded.sectionId}?studentId=${seeded.studentIds[0]}`,
      token: instructorToken(seeded.instructorId),
    });
    expect(res.status).toBe(200);
    expect(res.headers['content-type']).toContain('application/pdf');
    expect(res.buffer.subarray(0, 5).toString('latin1')).toBe('%PDF-');
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
