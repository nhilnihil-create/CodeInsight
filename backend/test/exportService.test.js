/**
 * Export service tests.
 *
 * Three layers:
 *  1. Pure unit tests: sanitizeFilename / buildExportFilename.
 *  2. formatExport dispatch (csv/xlsx/json + legacy shape + row cap) with a
 *     stubbed DOMAINS fetch so no DB rows are required.
 *  3. DB-backed tests: real fetchers against codeinsight_test via test/setup.js
 *     seeds (seedFullScenario + a submission whose code contains \n), plus the
 *     ownership guard and section metadata lookups.
 *
 * config/db is mocked with a delegate to the test pool (pattern from
 * runCheckpointIntegrity.test.js) so every SQL statement hits codeinsight_test.
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

const ExcelJS = require('exceljs');
const { parse } = require('csv-parse/sync');
const { pool: testPool, seedFullScenario } = require('./setup');
const {
  DOMAINS,
  sanitizeFilename,
  buildExportFilename,
  getSectionMeta,
  assertInstructorOwnsSection,
  formatExport,
} = require('../services/exportService');

const BOM = '\uFEFF';
const stripBom = (text) => text.replace(/^\uFEFF/, '');
const parseCsv = (buffer) => parse(stripBom(buffer.toString('utf8')), {
  columns: true,
  skip_empty_lines: true,
});

const MULTILINE_CODE = '#include <iostream>\nint main() {\n  std::cout << "hi";\n  return 0;\n}';

// ── 1. Pure unit tests ──────────────────────────────────────────────────────

describe('sanitizeFilename', () => {
  it('strips reserved filename characters', () => {
    expect(sanitizeFilename('My/Section:*?"<>|Name')).toBe('MySectionName');
    expect(sanitizeFilename('a\\b:c')).toBe('abc');
  });

  it('collapses whitespace runs and trims', () => {
    expect(sanitizeFilename('  CS  101   Section  ')).toBe('CS 101 Section');
  });

  it('keeps non-ASCII characters', () => {
    expect(sanitizeFilename('Café Section 一')).toBe('Café Section 一');
  });

  it('caps the result at 60 characters', () => {
    const long = 'x'.repeat(100);
    expect(sanitizeFilename(long)).toHaveLength(60);
    expect(sanitizeFilename(`  ${long}  `)).toHaveLength(60);
  });

  it('returns empty string for nullish/empty input', () => {
    expect(sanitizeFilename(null)).toBe('');
    expect(sanitizeFilename(undefined)).toBe('');
    expect(sanitizeFilename('   ')).toBe('');
  });
});

describe('buildExportFilename', () => {
  it('builds {sanitized}_{domain}_{YYYY-MM-DD}.{ext} with a custom date', () => {
    const date = new Date(2026, 0, 5); // local, TZ-independent
    expect(buildExportFilename({ sectionName: 'CS 101 / Section A', domain: 'submissions', ext: 'csv', date }))
      .toBe('CS 101 Section A_submissions_2026-01-05.csv');
    expect(buildExportFilename({ sectionName: 'Roster', domain: 'roster', ext: 'xlsx', date }))
      .toBe('Roster_roster_2026-01-05.xlsx');
  });

  it('defaults to today with a padded YYYY-MM-DD date', () => {
    const now = new Date();
    const pad = (n) => String(n).padStart(2, '0');
    const expectedDate = `${now.getFullYear()}-${pad(now.getMonth() + 1)}-${pad(now.getDate())}`;
    const name = buildExportFilename({ sectionName: 'Fall 2026', domain: 'integrity', ext: 'json' });
    expect(name).toBe(`Fall 2026_integrity_${expectedDate}.json`);
  });

  it('falls back to "export" when the section name sanitizes to empty', () => {
    const date = new Date(2026, 0, 5);
    expect(buildExportFilename({ sectionName: '***', domain: 'roster', ext: 'csv', date }))
      .toBe('export_roster_2026-01-05.csv');
  });
});

// ── 2. formatExport dispatch (stubbed fetch, no DB rows) ────────────────────

describe('formatExport — format dispatch (stubbed fetch)', () => {
  const originalFetch = DOMAINS.submissions.fetch;
  const STUB_ID = 99999; // never seeded → section meta falls back to the id

  const ROWS = [
    {
      name: 'Ada Lovelace',
      email: 'ada@test.com',
      title: 'Loops Lab',
      attempt_number: 1,
      passed: true,
      cds: 0.85,
      submitted: new Date('2026-03-01T12:00:00.000Z'),
      code: MULTILINE_CODE,
    },
    {
      name: 'Grace Hopper',
      email: 'grace@test.com',
      title: null,
      attempt_number: null,
      passed: null,
      cds: null,
      submitted: null,
      code: null,
    },
    {
      name: 'Lin "Instructor", Jr.',
      email: 'lin@test.com',
      title: 'Loops Lab',
      attempt_number: 2,
      passed: false,
      cds: 0.4,
      submitted: new Date('2026-03-02T09:30:00.000Z'),
      code: 'x = 1;',
    },
  ];

  beforeEach(() => {
    DOMAINS.submissions.fetch = jest.fn();
  });

  afterEach(() => {
    DOMAINS.submissions.fetch = originalFetch;
  });

  it('returns csv buffer with BOM, canonical headers and round-trippable cells', async () => {
    DOMAINS.submissions.fetch.mockResolvedValue(ROWS);
    const out = await formatExport('submissions', STUB_ID, 'csv');

    expect(out.extension).toBe('csv');
    expect(out.mimeType).toBe('text/csv; charset=utf-8');
    expect(out.filename).toMatch(/^99999_submissions_\d{4}-\d{2}-\d{2}\.csv$/);
    expect(out.buffer.subarray(0, 3)).toEqual(Buffer.from([0xef, 0xbb, 0xbf]));

    const records = parseCsv(out.buffer);
    expect(records).toHaveLength(3);
    expect(Object.keys(records[0])).toEqual([
      'Student Name', 'Email', 'Exercise', 'Attempt', 'Passed', 'CDS (%)', 'Submitted', 'Code',
    ]);
    // Multiline code cell survives the round trip intact.
    expect(records[0].Code).toBe(MULTILINE_CODE);
    expect(records[0]['CDS (%)']).toBe('85.0');
    expect(records[0].Passed).toBe('Yes');
    expect(records[0].Submitted).toBe('2026-03-01T12:00:00.000Z');
    // Embedded quotes survive.
    expect(records[2]['Student Name']).toBe('Lin "Instructor", Jr.');
    expect(records[2].Passed).toBe('No');
    expect(records[2]['CDS (%)']).toBe('40.0');
    // Null-heavy row renders empty fields.
    expect(records[1].Passed).toBe('');
    expect(records[1]['CDS (%)']).toBe('');
    expect(records[1].Submitted).toBe('');
    expect(records[1].Code).toBe('');
  });

  it('builds a single-sheet xlsx with bold frozen header, numeric CDS (%) and multiline cell', async () => {
    DOMAINS.submissions.fetch.mockResolvedValue(ROWS);
    const out = await formatExport('submissions', STUB_ID, 'xlsx');

    expect(out.extension).toBe('xlsx');
    expect(out.mimeType).toBe('application/vnd.openxmlformats-officedocument.spreadsheetml.sheet');

    const workbook = new ExcelJS.Workbook();
    await workbook.xlsx.load(out.buffer);
    expect(workbook.worksheets).toHaveLength(1);
    const ws = workbook.getWorksheet('submissions');
    expect(ws).toBeTruthy();

    expect(ws.actualRowCount).toBe(4); // header + 3 data rows
    const header = ws.getRow(1);
    expect(header.getCell(1).value).toBe('Student Name');
    expect(header.getCell(6).value).toBe('CDS (%)');
    expect(header.getCell(1).font.bold).toBe(true);
    expect(ws.views[0].state).toBe('frozen');
    expect(ws.views[0].ySplit).toBe(1);

    // CDS (%) is numeric; Passed is "Yes"/"No"; multiline code preserved.
    expect(ws.getRow(2).getCell(6).value).toBe(85);
    expect(ws.getRow(2).getCell(5).value).toBe('Yes');
    expect(ws.getRow(2).getCell(8).value).toBe(MULTILINE_CODE);
    expect(ws.getRow(4).getCell(6).value).toBe(40);
    expect(ws.getRow(4).getCell(5).value).toBe('No');
    expect(ws.getRow(3).getCell(6).value).toBeFalsy(); // null cds → empty cell
  });

  it('emits raw-fidelity JSON (cds 0–1, booleans, ISO timestamps)', async () => {
    DOMAINS.submissions.fetch.mockResolvedValue(ROWS);
    const out = await formatExport('submissions', STUB_ID, 'json');

    expect(out.extension).toBe('json');
    expect(out.mimeType).toBe('application/json; charset=utf-8');
    const parsed = JSON.parse(out.buffer.toString('utf8'));
    expect(parsed).toHaveLength(3);
    expect(parsed[0].cds).toBe(0.85);
    expect(parsed[0].passed).toBe(true);
    expect(parsed[0].submitted).toBe('2026-03-01T12:00:00.000Z');
    expect(parsed[0].code).toBe(MULTILINE_CODE);
    expect(parsed[1].cds).toBeNull();
  });

  it('legacy shape emits exactly the 7 pre-overhaul columns with "12.3%" CDS', async () => {
    DOMAINS.submissions.fetch.mockResolvedValue(ROWS);
    const out = await formatExport('submissions', STUB_ID, 'csv', { legacyShape: true });

    const records = parseCsv(out.buffer);
    expect(records).toHaveLength(3);
    expect(Object.keys(records[0])).toEqual([
      'Name', 'Email', 'Exercise', 'Attempt', 'Passed', 'CDS', 'Submitted',
    ]);
    expect(records[0].CDS).toBe('85.0%');
    expect(records[0].Code).toBeUndefined();
    expect(records[0].Submitted).toBe('2026-03-01T12:00:00.000Z');
  });

  it('rejects formats outside csv|xlsx|json with 400', async () => {
    await expect(formatExport('submissions', STUB_ID, 'pdf')).rejects.toMatchObject({
      status: 400,
      code: 'VALIDATION_ERROR',
    });
  });

  it('rejects unknown domains with 400', async () => {
    await expect(formatExport('not-a-domain', STUB_ID, 'csv')).rejects.toMatchObject({
      status: 400,
      code: 'VALIDATION_ERROR',
    });
  });

  it('throws AppError 413 TOO_LARGE above the 25,000-row cap', async () => {
    const tooMany = Array.from({ length: 25001 }, (_, i) => ({ name: `Student ${i}` }));
    DOMAINS.submissions.fetch.mockResolvedValue(tooMany);

    const err = await formatExport('submissions', STUB_ID, 'csv').catch((e) => e);
    expect(err).toBeInstanceOf(Error);
    expect(err.status).toBe(413);
    expect(err.code).toBe('TOO_LARGE');
    expect(err.message).toContain('25000');
  });

  it('allows exactly 25,000 rows', async () => {
    const atCap = Array.from({ length: 25000 }, (_, i) => ({ name: `Student ${i}` }));
    DOMAINS.submissions.fetch.mockResolvedValue(atCap);
    await expect(formatExport('submissions', STUB_ID, 'json')).resolves.toBeTruthy();
  });
});

// ── 3. DB-backed tests (real fetchers + ownership, codeinsight_test) ────────

describe('exportService — DB-backed fetchers and ownership', () => {
  let seeded;

  beforeEach(async () => {
    seeded = await seedFullScenario({ studentCount: 3 });
  });

  describe('roster domain', () => {
    it('returns one row per enrolled student with ISO dates', async () => {
      const out = await formatExport('roster', seeded.sectionId, 'csv');
      const records = parseCsv(out.buffer);

      expect(records).toHaveLength(3);
      expect(Object.keys(records[0])).toEqual(['Name', 'Email', 'Enrolled At']);

      const { rows } = await testPool.query(
        'SELECT enrolled_at FROM enrollments WHERE student_id = $1 AND section_id = $2',
        [seeded.studentIds[0], seeded.sectionId]
      );
      const d = new Date(rows[0].enrolled_at);
      const pad = (n) => String(n).padStart(2, '0');
      expect(records[0]['Enrolled At']).toBe(`${d.getFullYear()}-${pad(d.getMonth() + 1)}-${pad(d.getDate())}`);
    });

    it('produces a header-only file for an empty section', async () => {
      const { rows } = await testPool.query(
        `INSERT INTO sections (name, course_code, instructor_id) VALUES ($1, $2, $3) RETURNING id`,
        ['Empty Section', 'CS-EMPTY', seeded.instructorId]
      );
      const emptySectionId = rows[0].id;

      const out = await formatExport('roster', emptySectionId, 'csv');
      expect(out.buffer.toString('utf8')).toBe(`${BOM}Name,Email,Enrolled At\r\n`);
      const records = parseCsv(out.buffer);
      expect(records).toHaveLength(0);
    });
  });

  describe('submissions domain', () => {
    it('returns canonical columns with multiline code and formatted CDS', async () => {
      const { rows: subRows } = await testPool.query(
        `INSERT INTO submissions
           (student_id, exercise_id, attempt_number, code, is_correct, time_spent_seconds, test_results, is_verified, cds)
         VALUES ($1, $2, 2, $3, true, 30, '[]', true, 0.8534)
         RETURNING id`,
        [seeded.studentIds[0], seeded.exerciseId, MULTILINE_CODE]
      );

      const out = await formatExport('submissions', seeded.sectionId, 'csv');
      const records = parseCsv(out.buffer);

      // Only the one actual submission appears (canonical joins submissions).
      expect(records).toHaveLength(1);
      expect(Object.keys(records[0])).toEqual([
        'Student Name', 'Email', 'Exercise', 'Attempt', 'Passed', 'CDS (%)', 'Submitted', 'Code',
      ]);
      expect(records[0].Code).toBe(MULTILINE_CODE);
      expect(records[0].Passed).toBe('Yes');
      expect(records[0].Attempt).toBe('2');
      expect(records[0]['CDS (%)']).toBe('85.3');

      const { rows: rawSub } = await testPool.query(
        'SELECT submitted_at FROM submissions WHERE id = $1',
        [subRows[0].id]
      );
      expect(records[0].Submitted).toBe(new Date(rawSub[0].submitted_at).toISOString());
    });

    it('supports startDate/endDate/studentId filters', async () => {
      await testPool.query(
        `INSERT INTO submissions
           (student_id, exercise_id, attempt_number, code, is_correct, time_spent_seconds, test_results, is_verified)
         VALUES ($1, $2, 1, $3, false, 30, '[]', true)`,
        [seeded.studentIds[0], seeded.exerciseId, 'int main() { return 1; }']
      );

      // Wide, plain-ISO range: the seeded submission (created now, in 2026) falls
      // inside for any Postgres session timezone.
      const out = await formatExport('submissions', seeded.sectionId, 'json', {
        startDate: '2020-01-01',
        endDate: '2030-01-01',
        studentId: seeded.studentIds[0],
      });
      const parsed = JSON.parse(out.buffer.toString('utf8'));
      expect(parsed).toHaveLength(1);
      expect(parsed[0].name).toBe('Test Student 0');

      // The endDate bound actually binds: a range entirely before the submission yields nothing.
      const before = await formatExport('submissions', seeded.sectionId, 'json', {
        startDate: '2000-01-01',
        endDate: '2001-01-01',
        studentId: seeded.studentIds[0],
      });
      expect(JSON.parse(before.buffer.toString('utf8'))).toHaveLength(0);

      // studentId of a student with no submission yields nothing.
      const other = await formatExport('submissions', seeded.sectionId, 'json', {
        startDate: '2020-01-01',
        endDate: '2030-01-01',
        studentId: seeded.studentIds[1],
      });
      expect(JSON.parse(other.buffer.toString('utf8'))).toHaveLength(0);
    });
  });

  describe('integrity domain', () => {
    it('exports flags with native evidence in JSON and stringified in CSV', async () => {
      await testPool.query(
        `INSERT INTO integrity_flags
           (section_id, exercise_id, student_id, flag_type, severity, evidence, context_behaviors, status)
         VALUES ($1, $2, $3, $4, $5, $6::jsonb, $7::text[], $8)`,
        [
          seeded.sectionId,
          seeded.exerciseId,
          seeded.studentIds[0],
          'SIMILAR_CODE',
          'high',
          JSON.stringify({ similarity: 0.87, matched: ['main'] }),
          ['COPY_PASTE'],
          'flagged',
        ]
      );

      const jsonOut = await formatExport('integrity', seeded.sectionId, 'json');
      const parsed = JSON.parse(jsonOut.buffer.toString('utf8'));
      expect(parsed).toHaveLength(1);
      expect(parsed[0].flag_type).toBe('SIMILAR_CODE');
      expect(parsed[0].severity).toBe('high');
      expect(parsed[0].status).toBe('flagged');
      expect(parsed[0].evidence).toEqual({ similarity: 0.87, matched: ['main'] }); // native object
      expect(parsed[0].source || parsed[0].context_behaviors).toEqual(['COPY_PASTE']); // native array

      const csvOut = await formatExport('integrity', seeded.sectionId, 'csv');
      const records = parseCsv(csvOut.buffer);
      expect(records).toHaveLength(1);
      // Stringified jsonb: key order is normalized by Postgres, so parse and compare.
      expect(JSON.parse(records[0].Evidence)).toEqual({ similarity: 0.87, matched: ['main'] });
      expect(records[0].Source).toBe('COPY_PASTE'); // behavior tags joined with '; ' in CSV
      expect(records[0]['Flag Type']).toBe('SIMILAR_CODE');
      expect(records[0].Severity).toBe('high');
      expect(records[0].Status).toBe('flagged');
    });
  });

  describe('section meta and ownership guard', () => {
    it('getSectionMeta returns name, course_code and instructor_id', async () => {
      const meta = await getSectionMeta(seeded.sectionId);
      expect(meta).toMatchObject({
        name: 'Test Section',
        course_code: 'CS101',
        instructor_id: seeded.instructorId,
      });
    });

    it('getSectionMeta returns null for a missing section', async () => {
      await expect(getSectionMeta(999999999)).resolves.toBeNull();
    });

    it('assertInstructorOwnsSection resolves for the owning instructor', async () => {
      await expect(assertInstructorOwnsSection(seeded.sectionId, seeded.instructorId)).resolves.toBe(true);
    });

    it('assertInstructorOwnsSection rejects with 403 FORBIDDEN for a foreign instructor', async () => {
      const { rows } = await testPool.query(
        `INSERT INTO users (name, email, password_hash, role) VALUES ($1, $2, 'hashed_pw', 'instructor') RETURNING id`,
        ['Foreign Instructor', 'foreign.instructor@test.com']
      );
      const foreignId = rows[0].id;

      await expect(assertInstructorOwnsSection(seeded.sectionId, foreignId)).rejects.toMatchObject({
        status: 403,
        code: 'FORBIDDEN',
      });
    });

    it('assertInstructorOwnsSection rejects with 404 NOT_FOUND for a missing section', async () => {
      await expect(assertInstructorOwnsSection(999999999, seeded.instructorId)).rejects.toMatchObject({
        status: 404,
        code: 'NOT_FOUND',
      });
    });
  });
});

describe('exportService — Phase 2 domains (concept_mastery, completion, longitudinal)', () => {
  let seeded;

  beforeEach(async () => {
    // student_concept_metrics is not part of setup's clearTestTables — clean it here.
    await testPool.query('DELETE FROM student_concept_metrics');
    await testPool.query('DELETE FROM cds_scores');
    seeded = await seedFullScenario({ studentCount: 3 });
  });

  afterEach(async () => {
    await testPool.query('DELETE FROM student_concept_metrics');
  });

  describe('concept_mastery domain', () => {
    it('exports one row per student × concept with Concept Mastery Index, Mastery Velocity and ISO Last Updated', async () => {
      const { rows: second } = await testPool.query(
        `INSERT INTO concepts (name) VALUES ($1) RETURNING id`, ['Arrays']
      );
      for (const sid of seeded.studentIds) {
        await testPool.query(
          `INSERT INTO student_concept_metrics (student_id, concept_id, section_id, cmi, velocity, last_updated)
           VALUES ($1, $2, $3, $4, $5, $6)`,
          [sid, seeded.conceptId, seeded.sectionId, 0.75, 0.1, new Date('2026-04-01T08:00:00.000Z')]
        );
        await testPool.query(
          `INSERT INTO student_concept_metrics (student_id, concept_id, section_id, cmi, velocity, last_updated)
           VALUES ($1, $2, $3, $4, $5, $6)`,
          [sid, second[0].id, seeded.sectionId, 0.5, -0.2, new Date('2026-04-02T08:00:00.000Z')]
        );
      }

      const out = await formatExport('concept_mastery', seeded.sectionId, 'csv');
      const records = parseCsv(out.buffer);
      expect(records).toHaveLength(6);
      expect(Object.keys(records[0])).toEqual(['Student Name', 'Email', 'Concept', 'Concept Mastery Index', 'Mastery Velocity', 'Last Updated']);
      // Ordered by student name then concept name, so 'Arrays' precedes 'Loops'.
      const arraysRow = records.find((r) => r.Concept === 'Arrays');
      const loopsRow = records.find((r) => r.Concept === 'Loops');
      expect(arraysRow).toBeDefined();
      expect(loopsRow).toBeDefined();
      expect(loopsRow['Concept Mastery Index']).toBe('0.75');
      expect(loopsRow['Mastery Velocity']).toBe('0.1');
      expect(loopsRow['Last Updated']).toBe('2026-04-01T08:00:00.000Z');
      expect(arraysRow['Concept Mastery Index']).toBe('0.5');
      expect(arraysRow['Mastery Velocity']).toBe('-0.2');
      expect(arraysRow['Last Updated']).toBe('2026-04-02T08:00:00.000Z');

      const jsonOut = await formatExport('concept_mastery', seeded.sectionId, 'json');
      const parsed = JSON.parse(jsonOut.buffer.toString('utf8'));
      expect(parsed).toHaveLength(6);
      expect(parsed.find((r) => r.concept === 'Loops').cmi).toBe(0.75); // raw numeric, not a pg DECIMAL string
      expect(parsed.find((r) => r.concept === 'Loops').velocity).toBe(0.1);
      expect(parsed.find((r) => r.concept === 'Arrays').velocity).toBe(-0.2);
    });

    it('supports studentId/startDate/endDate filters', async () => {
      await testPool.query(
        `INSERT INTO student_concept_metrics (student_id, concept_id, section_id, cmi, velocity, last_updated)
         VALUES ($1, $2, $3, 0.8, 0.05, $4)`,
        [seeded.studentIds[0], seeded.conceptId, seeded.sectionId, new Date('2026-04-01T08:00:00.000Z')]
      );

      const filtered = await formatExport('concept_mastery', seeded.sectionId, 'json', {
        studentId: seeded.studentIds[0],
      });
      expect(JSON.parse(filtered.buffer.toString('utf8'))).toHaveLength(1);

      const before = await formatExport('concept_mastery', seeded.sectionId, 'json', {
        startDate: '2026-01-01',
        endDate: '2026-02-01',
      });
      expect(JSON.parse(before.buffer.toString('utf8'))).toHaveLength(0);
    });

    it('produces a header-only file for a section without metrics', async () => {
      const out = await formatExport('concept_mastery', seeded.sectionId, 'csv');
      expect(out.buffer.toString('utf8')).toBe(`${BOM}Student Name,Email,Concept,Concept Mastery Index,Mastery Velocity,Last Updated\r\n`);
      expect(parseCsv(out.buffer)).toHaveLength(0);
    });
  });

  describe('completion domain', () => {
    it('exports per-exercise on-time/late/missing percentages over enrolled students', async () => {
      // Seeded exercise: no deadline (every submission counts as on-time).
      // Future-deadline exercise and past-deadline exercise added for late/missing math.
      const now = Date.now();
      const MIN = 60 * 1000;
      const { rows: future } = await testPool.query(
        `INSERT INTO exercises (section_id, concept_id, title, description, deadline, created_at)
         VALUES ($1, $2, 'Future deadline', 'Test Description', $3, $4) RETURNING id`,
        [seeded.sectionId, seeded.conceptId, new Date(now + 7 * 24 * 60 * MIN), new Date(now - 10 * MIN)]
      );
      const { rows: past } = await testPool.query(
        `INSERT INTO exercises (section_id, concept_id, title, description, deadline, created_at)
         VALUES ($1, $2, 'Past deadline', 'Test Description', $3, $4) RETURNING id`,
        [seeded.sectionId, seeded.conceptId, new Date(now - 24 * 60 * MIN), new Date(now - 20 * MIN)]
      );

      // Student0 submits to all three; Student1 on-time to the future one only; Student2 nothing.
      for (const exId of [seeded.exerciseId, future[0].id, past[0].id]) {
        await testPool.query(
          `INSERT INTO submissions (student_id, exercise_id, attempt_number, code, is_correct, is_verified)
           VALUES ($1, $2, 1, 'int main() { return 0; }', true, true)`,
          [seeded.studentIds[0], exId]
        );
      }
      await testPool.query(
        `INSERT INTO submissions (student_id, exercise_id, attempt_number, code, is_correct, is_verified)
         VALUES ($1, $2, 1, 'int main() { return 0; }', true, true)`,
        [seeded.studentIds[1], future[0].id]
      );

      const out = await formatExport('completion', seeded.sectionId, 'csv');
      const records = parseCsv(out.buffer);
      expect(records).toHaveLength(3);
      expect(Object.keys(records[0])).toEqual(['Exercise', 'On-Time (%)', 'Late (%)', 'Missing (%)']);

      const byTitle = Object.fromEntries(records.map((r) => [r.Exercise, r]));
      // No deadline: 1 of 3 students submitted, all on-time → 33% on-time, 67% missing.
      expect(byTitle['Test Exercise']).toEqual({
        Exercise: 'Test Exercise', 'On-Time (%)': '33', 'Late (%)': '0', 'Missing (%)': '67',
      });
      // Future deadline: 2 of 3 on-time.
      expect(byTitle['Future deadline']).toEqual({
        Exercise: 'Future deadline', 'On-Time (%)': '67', 'Late (%)': '0', 'Missing (%)': '33',
      });
      // Past deadline: student0's submission is late → 33% late, 67% missing.
      expect(byTitle['Past deadline']).toEqual({
        Exercise: 'Past deadline', 'On-Time (%)': '0', 'Late (%)': '33', 'Missing (%)': '67',
      });
    });

    it('keeps raw percentages in JSON', async () => {
      await testPool.query(
        `INSERT INTO submissions (student_id, exercise_id, attempt_number, code, is_correct, is_verified)
         VALUES ($1, $2, 1, 'int main() { return 0; }', true, true)`,
        [seeded.studentIds[0], seeded.exerciseId]
      );

      const jsonOut = await formatExport('completion', seeded.sectionId, 'json');
      const parsed = JSON.parse(jsonOut.buffer.toString('utf8'));
      expect(parsed).toHaveLength(1);
      expect(parsed[0].exercise).toBe('Test Exercise');
      expect(parsed[0].on_time).toBe(33);
      expect(parsed[0].late).toBe(0);
      expect(parsed[0].missing).toBe(67);
    });
  });

  describe('longitudinal domain', () => {
    async function seedCds(studentId, exerciseId, cds, computedAt) {
      await testPool.query(
        `INSERT INTO cds_scores (student_id, exercise_id, section_id, cds, classification, computed_at)
         VALUES ($1, $2, $3, $4, $5, $6)`,
        [studentId, exerciseId, seeded.sectionId, cds, 'proficient', computedAt]
      );
    }

    it('groups cds history per student with computed mastery velocity', async () => {
      // Three distinct exercises so each student has a unique (student, exercise) row.
      const exercises = [seeded.exerciseId];
      const MIN = 60 * 1000;
      const now = Date.now();
      for (const [title, ageMin] of [['E2', 10], ['E3', 20]]) {
        const { rows } = await testPool.query(
          `INSERT INTO exercises (section_id, concept_id, title, description, created_at)
           VALUES ($1, $2, $3, 'Test Description', $4) RETURNING id`,
          [seeded.sectionId, seeded.conceptId, title, new Date(now - ageMin * MIN)]
        );
        exercises.push(rows[0].id);
      }
      // Student0 improving (0.4 → 0.6 → 0.8); Student1 declining (0.8 → 0.6 → 0.4); Student2 no scores.
      await seedCds(seeded.studentIds[0], exercises[0], 0.4, '2026-04-01');
      await seedCds(seeded.studentIds[0], exercises[1], 0.6, '2026-04-08');
      await seedCds(seeded.studentIds[0], exercises[2], 0.8, '2026-04-15');
      await seedCds(seeded.studentIds[1], exercises[0], 0.8, '2026-04-01');
      await seedCds(seeded.studentIds[1], exercises[1], 0.6, '2026-04-08');
      await seedCds(seeded.studentIds[1], exercises[2], 0.4, '2026-04-15');

      const out = await formatExport('longitudinal', seeded.sectionId, 'csv');
      const records = parseCsv(out.buffer);
      expect(records).toHaveLength(3);
      expect(Object.keys(records[0])).toEqual(['Student Name', 'Email', 'Progression', 'Mastery Velocity']);

      const byName = Object.fromEntries(records.map((r) => [r['Student Name'], r]));
      expect(byName['Test Student 0']['Mastery Velocity']).toBe('improving');
      expect(byName['Test Student 1']['Mastery Velocity']).toBe('declining');
      expect(byName['Test Student 2']['Mastery Velocity']).toBe('stable');
      expect(byName['Test Student 2'].Progression).toBe('[]');

      // Progression is JSON in CSV (formatEvidence); verify parsed contents.
      const prog = JSON.parse(byName['Test Student 0'].Progression);
      expect(prog).toHaveLength(3);
      expect(prog.map((p) => p.cds)).toEqual([0.4, 0.6, 0.8]);
      expect(prog[0].exercise_title).toBe('Test Exercise');
      expect(prog[0].concept_name).toBe('Loops');

      const jsonOut = await formatExport('longitudinal', seeded.sectionId, 'json');
      const parsed = JSON.parse(jsonOut.buffer.toString('utf8'));
      expect(parsed).toHaveLength(3);
      const s0 = parsed.find((s) => s.name === 'Test Student 0');
      expect(s0.mastery_velocity).toBe('improving');
      expect(s0.progression).toHaveLength(3);
      expect(s0.progression[0].cds).toBe(0.4);
      expect(typeof s0.progression[0].computed_at).toBe('string'); // ISO-8601, raw fidelity
    });

    it('returns every enrolled student even with an empty score range', async () => {
      const out = await formatExport('longitudinal', seeded.sectionId, 'json', {
        startDate: '2000-01-01',
        endDate: '2001-01-01',
      });
      const parsed = JSON.parse(out.buffer.toString('utf8'));
      expect(parsed).toHaveLength(3);
      for (const row of parsed) {
        expect(row.progression).toEqual([]);
        expect(row.mastery_velocity).toBe('stable');
      }
    });
  });

  // ── Phase 2b DB-backed domains: cds / heatmap / behavioral / catalog / settings / alerts ──

  describe('Phase 2b export domains', () => {
    let seeded;

    beforeEach(async () => {
      // clearTestTables() deliberately omits behavioral_events — wipe it here.
      await testPool.query('DELETE FROM behavioral_events');
      seeded = await seedFullScenario({ studentCount: 3 });
    });

    afterEach(async () => {
      await testPool.query('DELETE FROM behavioral_events');
    });

    describe('cds domain', () => {
      it('exports one row per student per day (latest score), dropping null/unscored rows', async () => {
        const { rows: secondExercise } = await testPool.query(
          `INSERT INTO exercises (section_id, concept_id, title, description)
           VALUES ($1, $2, 'Lab 2', 'Second lab for date coverage')
           RETURNING id`,
          [seeded.sectionId, seeded.conceptId]
        );
        const { rows: thirdExercise } = await testPool.query(
          `INSERT INTO exercises (section_id, concept_id, title, description)
           VALUES ($1, $2, 'Lab 3', 'Third lab for same-day coverage')
           RETURNING id`,
          [seeded.sectionId, seeded.conceptId]
        );

        await testPool.query(
          `INSERT INTO cds_scores (student_id, exercise_id, section_id, cds, classification, computed_at)
           VALUES ($1, $2, $3, 0.8534, 'proficient', $4)`,
          [seeded.studentIds[0], seeded.exerciseId, seeded.sectionId, '2026-04-01 08:00:00']
        );
        // Same-day, later score for student 0 on 2026-04-01 — must win the
        // DISTINCT ON tiebreak (latest computed_at, latest id), not be a
        // second per-exercise row.
        await testPool.query(
          `INSERT INTO cds_scores (student_id, exercise_id, section_id, cds, classification, computed_at)
           VALUES ($1, $2, $3, 0.6, 'revised', $4)`,
          [seeded.studentIds[0], thirdExercise[0].id, seeded.sectionId, '2026-04-01 09:00:00']
        );
        await testPool.query(
          `INSERT INTO cds_scores (student_id, exercise_id, section_id, cds, classification, computed_at)
           VALUES ($1, $2, $3, 0.4, 'developing', $4)`,
          [seeded.studentIds[0], secondExercise[0].id, seeded.sectionId, '2026-04-08 08:00:00']
        );
        await testPool.query(
          `INSERT INTO cds_scores (student_id, exercise_id, section_id, cds, classification, computed_at)
           VALUES ($1, $2, $3, 0.9, 'needs_support', $4)`,
          [seeded.studentIds[1], seeded.exerciseId, seeded.sectionId, '2026-04-01 08:00:00']
        );
        // Null-cds "Unscored" placeholder row — excluded from the daily grain.
        await testPool.query(
          `INSERT INTO cds_scores (student_id, exercise_id, section_id, cds, classification, computed_at)
           VALUES ($1, $2, $3, NULL, 'Unscored', $4)`,
          [seeded.studentIds[1], secondExercise[0].id, seeded.sectionId, '2026-04-09 08:00:00']
        );

        const out = await formatExport('cds', seeded.sectionId, 'csv');
        const records = parseCsv(out.buffer);
        expect(records).toHaveLength(3);
        expect(Object.keys(records[0])).toEqual(['Student Name', 'Email', 'Date', 'CDS (%)', 'Classification']);

        const s0 = records.filter((r) => r['Student Name'] === 'Test Student 0');
        expect(s0).toHaveLength(2);
        expect(s0[0]).toMatchObject({
          Date: '2026-04-01',
          'CDS (%)': '60.0', // the LATEST score of the day wins the DISTINCT ON
          Classification: 'revised',
        });
        expect(s0[0].Email).toBe('student0@test.com');
        expect(s0[1].Date).toBe('2026-04-08');
        expect(s0[1]['CDS (%)']).toBe('40.0');

        const jsonOut = await formatExport('cds', seeded.sectionId, 'json');
        const parsed = JSON.parse(jsonOut.buffer.toString('utf8'));
        expect(parsed).toHaveLength(3);
        for (const raw of parsed) {
          expect(raw.cds).not.toBeNull(); // no null placeholder rows
          expect(raw.classification).not.toBe('Unscored');
          expect(typeof raw.date).toBe('string'); // ISO-8601 raw fidelity
        }
        // ::date returns a local-midnight Date; the JSON ISO instant is
        // TZ-shifted, but the local calendar day must be the bucketed date.
        const localDay = (iso) => {
          const d = new Date(iso);
          const pad = (n) => String(n).padStart(2, '0');
          return `${d.getFullYear()}-${pad(d.getMonth() + 1)}-${pad(d.getDate())}`;
        };
        const latest = parsed.find(
          (r) => r.name === 'Test Student 0' && localDay(r.date) === '2026-04-01'
        );
        expect(latest).toBeTruthy();
        expect(latest.cds).toBe(0.6); // DECIMAL normalized to 0–1 number
        expect(latest.classification).toBe('revised');
      });

      it('supports studentId and date-range filters', async () => {
        await testPool.query(
          `INSERT INTO cds_scores (student_id, exercise_id, section_id, cds, classification, computed_at)
           VALUES ($1, $2, $3, 0.7, 'moderate', $4)`,
          [seeded.studentIds[0], seeded.exerciseId, seeded.sectionId, '2026-04-05 08:00:00']
        );

        const filtered = await formatExport('cds', seeded.sectionId, 'json', {
          studentId: seeded.studentIds[0],
        });
        expect(JSON.parse(filtered.buffer.toString('utf8'))).toHaveLength(1);

        const outOfRange = await formatExport('cds', seeded.sectionId, 'json', {
          startDate: '2026-01-01',
          endDate: '2026-02-01',
        });
        expect(JSON.parse(outOfRange.buffer.toString('utf8'))).toHaveLength(0);
      });
    });

    describe('heatmap domain', () => {
      it('buckets submissions into one row per student per day with an event count', async () => {
        for (let i = 1; i <= 2; i++) {
          await testPool.query(
            `INSERT INTO submissions (student_id, exercise_id, attempt_number, code, is_correct, submitted_at, is_verified)
             VALUES ($1, $2, $3, 'int main() { return 0; }', true, $4, true)`,
            [seeded.studentIds[0], seeded.exerciseId, i, '2026-04-01 12:00:00']
          );
        }
        await testPool.query(
          `INSERT INTO submissions (student_id, exercise_id, attempt_number, code, is_correct, submitted_at, is_verified)
           VALUES ($1, $2, 3, 'int main() { return 0; }', true, $3, true)`,
          [seeded.studentIds[0], seeded.exerciseId, '2026-04-02 12:00:00']
        );
        await testPool.query(
          `INSERT INTO submissions (student_id, exercise_id, attempt_number, code, is_correct, submitted_at, is_verified)
           VALUES ($1, $2, 1, 'int main() { return 0; }', true, $3, true)`,
          [seeded.studentIds[1], seeded.exerciseId, '2026-04-01 12:00:00']
        );

        const out = await formatExport('heatmap', seeded.sectionId, 'csv');
        const records = parseCsv(out.buffer);
        expect(records).toHaveLength(3);
        expect(Object.keys(records[0])).toEqual(['Student Name', 'Date', 'Events']);

        const s0Apr1 = records.find((r) => r['Student Name'] === 'Test Student 0' && r.Date === '2026-04-01');
        const s0Apr2 = records.find((r) => r['Student Name'] === 'Test Student 0' && r.Date === '2026-04-02');
        const s1 = records.find((r) => r['Student Name'] === 'Test Student 1');
        expect(s0Apr1.Events).toBe('2');
        expect(s0Apr2.Events).toBe('1');
        expect(s1.Events).toBe('1');

        const jsonOut = await formatExport('heatmap', seeded.sectionId, 'json');
        const parsed = JSON.parse(jsonOut.buffer.toString('utf8'));
        expect(parsed).toHaveLength(3);
        const raw = parsed.find((r) => r.events === 2);
        expect(raw).toBeTruthy();
        expect(raw.name).toBe('Test Student 0');
        // ::date returns a local-midnight Date; the JSON ISO instant is TZ-shifted,
        // but the local calendar day must be the bucketed date in any timezone.
        const d = new Date(raw.date);
        const pad = (n) => String(n).padStart(2, '0');
        expect(`${d.getFullYear()}-${pad(d.getMonth() + 1)}-${pad(d.getDate())}`).toBe('2026-04-01');
      });

      it('supports date-range filters', async () => {
        await testPool.query(
          `INSERT INTO submissions (student_id, exercise_id, attempt_number, code, is_correct, submitted_at, is_verified)
           VALUES ($1, $2, 1, 'int main() { return 0; }', true, $3, true)`,
          [seeded.studentIds[0], seeded.exerciseId, '2026-04-05 12:00:00']
        );

        const out = await formatExport('heatmap', seeded.sectionId, 'json', {
          startDate: '2026-04-01',
          endDate: '2026-04-02',
        });
        expect(JSON.parse(out.buffer.toString('utf8'))).toHaveLength(0);
      });
    });

    describe('behavioral domain', () => {
      it('exports events with native JSONB payload in JSON and stringified in CSV', async () => {
        const payload = { count: 3, chars: 42 };
        const { rows } = await testPool.query(
          `INSERT INTO behavioral_events (student_id, exercise_id, event_type, occurred_at, payload)
           VALUES ($1, $2, $3, $4, $5::jsonb)
           RETURNING occurred_at`,
          [seeded.studentIds[0], seeded.exerciseId, 'tab_switch', '2026-04-01 09:15:00', JSON.stringify(payload)]
        );
        await testPool.query(
          `INSERT INTO behavioral_events (student_id, exercise_id, event_type, occurred_at, payload)
           VALUES ($1, $2, $3, $4, $5::jsonb)`,
          [seeded.studentIds[1], seeded.exerciseId, 'warning_SIMILAR_CODE', '2026-04-02 10:00:00', JSON.stringify({ reason: 'similar' })]
        );

        const csvOut = await formatExport('behavioral', seeded.sectionId, 'csv');
        const records = parseCsv(csvOut.buffer);
        expect(records).toHaveLength(2);
        expect(Object.keys(records[0])).toEqual(['Student Name', 'Event Type', 'Timestamp', 'Payload']);

        const s0 = records.find((r) => r['Student Name'] === 'Test Student 0');
        expect(s0['Event Type']).toBe('tab_switch');
        expect(s0.Timestamp).toBe(new Date(rows[0].occurred_at).toISOString());
        expect(JSON.parse(s0.Payload)).toEqual(payload);

        const jsonOut = await formatExport('behavioral', seeded.sectionId, 'json');
        const parsed = JSON.parse(jsonOut.buffer.toString('utf8'));
        expect(parsed).toHaveLength(2);
        expect(parsed.find((r) => r.name === 'Test Student 0').payload).toEqual(payload); // native JSONB object
        expect(parsed[0].timestamp).toMatch(/^\d{4}-\d{2}-\d{2}T\d{2}:\d{2}:\d{2}/); // ISO-8601 string
      });

      it('supports studentId and date-range filters', async () => {
        await testPool.query(
          `INSERT INTO behavioral_events (student_id, exercise_id, event_type, occurred_at, payload)
           VALUES ($1, $2, 'paste', '2026-04-01 09:15:00', '{"n":1}'::jsonb)`,
          [seeded.studentIds[0], seeded.exerciseId]
        );

        const filtered = await formatExport('behavioral', seeded.sectionId, 'json', {
          studentId: seeded.studentIds[0],
        });
        expect(JSON.parse(filtered.buffer.toString('utf8'))).toHaveLength(1);

        const outOfRange = await formatExport('behavioral', seeded.sectionId, 'json', {
          startDate: '2026-01-01',
          endDate: '2026-02-01',
        });
        expect(JSON.parse(outOfRange.buffer.toString('utf8'))).toHaveLength(0);
      });
    });

    describe('catalog domain', () => {
      it('exports the exercise catalog with a round-trippable multiline starter code', async () => {
        const MULTILINE_STARTER = '#include <iostream>\n\nint main() {\n  // multiline stress case\n  std::cout << "started";\n  return 0;\n}\n';
        await testPool.query(
          `INSERT INTO exercises (section_id, concept_id, title, description, starter_code, time_limit_minutes)
           VALUES ($1, $2, $3, $4, $5, 45)`,
          [seeded.sectionId, seeded.conceptId, 'Bubble Sort Lab', 'Sort an array of integers', MULTILINE_STARTER]
        );

        const out = await formatExport('catalog', seeded.sectionId, 'csv');
        const records = parseCsv(out.buffer);
        expect(records).toHaveLength(2); // seeded exercise + the new one
        expect(Object.keys(records[0])).toEqual(['Exercise', 'Description', 'Starter Code', 'Time Limit (sec)', 'Concept/Topic']);

        const bubble = records.find((r) => r.Exercise === 'Bubble Sort Lab');
        expect(bubble.Description).toBe('Sort an array of integers');
        expect(bubble['Starter Code']).toBe(MULTILINE_STARTER); // multiline round trip
        expect(bubble['Time Limit (sec)']).toBe('2700'); // 45 minutes → seconds
        expect(bubble['Concept/Topic']).toBe('Loops');

        const seededRow = records.find((r) => r.Exercise === 'Test Exercise');
        expect(seededRow['Time Limit (sec)']).toBe('3600'); // seed default 60 minutes

        const jsonOut = await formatExport('catalog', seeded.sectionId, 'json');
        const parsed = JSON.parse(jsonOut.buffer.toString('utf8'));
        const raw = parsed.find((r) => r.exercise === 'Bubble Sort Lab');
        expect(raw.starter_code).toBe(MULTILINE_STARTER);
        expect(raw.time_limit).toBe(2700); // INT number, raw fidelity
      });
    });

    describe('settings domain', () => {
      it('exports the section row as a single settings record', async () => {
        await testPool.query(
          `UPDATE sections SET term = $1, semester = $2, join_policy = $3, max_size = $4 WHERE id = $5`,
          ['Fall 2026', '1st Semester', 'request', 40, seeded.sectionId]
        );

        const out = await formatExport('settings', seeded.sectionId, 'csv');
        const records = parseCsv(out.buffer);
        expect(records).toHaveLength(1);
        expect(Object.keys(records[0])).toEqual(['Section', 'Course Code', 'Term', 'Instructor', 'Semester', 'Join Policy', 'Max Size']);
        expect(records[0]).toEqual({
          Section: 'Test Section',
          'Course Code': 'CS101',
          Term: 'Fall 2026',
          Instructor: 'Test Instructor',
          Semester: '1st Semester',
          'Join Policy': 'request',
          'Max Size': '40',
        });

        const jsonOut = await formatExport('settings', seeded.sectionId, 'json');
        const parsed = JSON.parse(jsonOut.buffer.toString('utf8'));
        expect(parsed).toHaveLength(1);
        expect(parsed[0].course_code).toBe('CS101');
        expect(parsed[0].instructor).toBe('Test Instructor');
        expect(parsed[0].join_policy).toBe('request');
        expect(parsed[0].max_size).toBe(40); // INT number, raw fidelity
      });
    });

    describe('alerts domain', () => {
      it('exports alerts with derived severity, review status and composed details', async () => {
        const { rows } = await testPool.query(
          `INSERT INTO alerts (student_id, exercise_id, section_id, cds_score, classification, concept_name, is_reviewed, created_at)
           VALUES ($1, $2, $3, 0.85, 'CDS_HIGH', 'Loops', false, $4)
           RETURNING created_at`,
          [seeded.studentIds[0], seeded.exerciseId, seeded.sectionId, '2026-04-01 08:00:00']
        );
        await testPool.query(
          `INSERT INTO alerts (student_id, exercise_id, section_id, cds_score, classification, concept_name, is_reviewed, created_at)
           VALUES ($1, $2, $3, 0.5, 'RETRY_STORM', 'Arrays', true, $4)`,
          [seeded.studentIds[1], seeded.exerciseId, seeded.sectionId, '2026-04-02 08:00:00']
        );

        const csvOut = await formatExport('alerts', seeded.sectionId, 'csv');
        const records = parseCsv(csvOut.buffer);
        expect(records).toHaveLength(2);
        expect(Object.keys(records[0])).toEqual(['Student Name', 'Alert Type', 'Severity', 'Status', 'Message/Details', 'Created At']);

        const s0 = records.find((r) => r['Student Name'] === 'Test Student 0');
        expect(s0['Alert Type']).toBe('CDS_HIGH');
        expect(s0.Severity).toBe('critical'); // cds 0.85 > 0.80
        expect(s0.Status).toBe('unreviewed');
        expect(s0['Message/Details']).toBe('CDS 85.0%; Concept: Loops; Exercise: Test Exercise');
        expect(s0['Created At']).toBe(new Date(rows[0].created_at).toISOString());

        const s1 = records.find((r) => r['Student Name'] === 'Test Student 1');
        expect(s1['Alert Type']).toBe('RETRY_STORM');
        expect(s1.Severity).toBe('high'); // classification overrides the cds-only tiers
        expect(s1.Status).toBe('reviewed');
        expect(s1['Message/Details']).toBe('CDS 50.0%; Concept: Arrays; Exercise: Test Exercise');

        const jsonOut = await formatExport('alerts', seeded.sectionId, 'json');
        const parsed = JSON.parse(jsonOut.buffer.toString('utf8'));
        expect(parsed).toHaveLength(2);
        const raw = parsed.find((r) => r.name === 'Test Student 0');
        expect(raw.cds_score).toBe(0.85); // DECIMAL normalized to number
        expect(raw.status).toBe(false);   // raw is_reviewed boolean (format only in CSV/XLSX)
        expect(raw.severity).toBe('critical');
      });

      it('supports studentId and date-range filters', async () => {
        await testPool.query(
          `INSERT INTO alerts (student_id, exercise_id, section_id, cds_score, classification, created_at)
           VALUES ($1, $2, $3, 0.7, 'CDS_HIGH', $4)`,
          [seeded.studentIds[0], seeded.exerciseId, seeded.sectionId, '2026-04-05 08:00:00']
        );

        const filtered = await formatExport('alerts', seeded.sectionId, 'json', {
          studentId: seeded.studentIds[0],
        });
        expect(JSON.parse(filtered.buffer.toString('utf8'))).toHaveLength(1);

        const outOfRange = await formatExport('alerts', seeded.sectionId, 'json', {
          startDate: '2026-01-01',
          endDate: '2026-02-01',
        });
        expect(JSON.parse(outOfRange.buffer.toString('utf8'))).toHaveLength(0);
      });
    });
  });
});

