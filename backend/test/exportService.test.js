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
