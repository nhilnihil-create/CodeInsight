/**
 * DB-backed tests for backend/services/pdfReport.js (real PostgreSQL via
 * test/setup.js). config/db is mocked with a delegate to the codeinsight_test
 * pool (same pattern as exportService.test.js / runCheckpointIntegrity.test.js).
 *
 * Page counts are read from the assembled PDF buffer by counting '/Type /Page'
 * objects (pdfkit writes one per page; the tree node is '/Type /Pages' and is
 * excluded by the word-boundary match). The 0-student "No data" assertion
 * decodes pdfkit's hex-encoded text runs — content streams are plaintext here
 * because pdfReport builds the document with compress: false.
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

const { pool: testPool, seedFullScenario, seedTestInstructor, seedTestSection, seedTestExercise, seedSubmission } = require('./setup');
const {
  buildSectionVisualReport,
  makeDocument,
  collectBuffer,
  drawCover,
  drawDossierPages,
  avgCdsByDate,
  cdsDistribution,
  atRiskCount,
  buildHeatmap,
  hasStudentData,
} = require('../services/pdfReport');

/** Number of '/Type /Page' objects in a rendered PDF buffer. */
const pageCount = (buffer) => (buffer.toString('latin1').match(/\/Type \/Page\b/g) || []).length;

/** Decode pdfkit's hex text runs (<...>) into a searchable string. */
function pdfText(buffer) {
  const s = buffer.toString('latin1');
  let out = '';
  const re = /<([0-9a-f]{2,})>/g;
  let m;
  while ((m = re.exec(s))) out += Buffer.from(m[1], 'hex').toString('latin1');
  return out;
}

/**
 * Decode per-page text (one string per page) from an uncompressed pdfkit PDF.
 * Pages reference a content stream; each stream's TJ hex runs are decoded.
 */
function perPageText(buffer) {
  const s = buffer.toString('latin1');
  const objRe = /(\d+)\s+0\s+obj\s*<<([\s\S]*?)>>\s*endobj/g;
  const contentById = new Map();
  const pageRefs = [];
  const order = [];
  let m;
  while ((m = objRe.exec(s))) {
    const id = Number(m[1]);
    const dict = m[2];
    order.push(id);
    const c = dict.match(/\/Contents\s+(\d+)\s+0\s+R/);
    if (c) contentById.set(id, Number(c[1]));
    if (/\/Type\s*\/Page[^s]/.test(dict)) pageRefs.push(id);
  }
  pageRefs.sort((a, b) => order.indexOf(a) - order.indexOf(b));
  const streamFor = (objId) => {
    const marker = `${objId} 0 obj`;
    const i = s.indexOf(marker);
    const st = s.indexOf('\nstream\n', i);
    const start = st + '\nstream\n'.length;
    const en = s.indexOf('\nendstream\n', start);
    return s.slice(start, en);
  };
  return pageRefs.map((pid) => {
    const content = streamFor(contentById.get(pid));
    const out = [];
    const tjRe = /\[([^\]]*)\]\s*TJ/g;
    let mm;
    while ((mm = tjRe.exec(content))) {
      const hexes = [...mm[1].matchAll(/<([0-9A-Fa-f]+)>/g)].map((x) => {
        let t = '';
        for (let i = 0; i + 1 < x[1].length; i += 2) t += String.fromCharCode(parseInt(x[1].slice(i, i + 2), 16));
        return t;
      });
      out.push(hexes.join(''));
    }
    return out.join(' ');
  });
}

/**
 * Give the first `count` students of a seeded scenario the full chart
 * dataset: 3 CDS scores + 3 submissions + 2 concept metrics each, plus
 * integrity flags for students 0 and 1. Students beyond `count` stay
 * data-free (used to prove no-data students add zero pages).
 */
async function seedRichStudents(seeded, count) {
  const ex2 = await seedTestExercise(seeded.sectionId, seeded.conceptId, { title: 'Test Exercise 2' });
  const ex3 = await seedTestExercise(seeded.sectionId, seeded.conceptId, { title: 'Test Exercise 3' });
  const exercises = [seeded.exerciseId, ex2, ex3];
  const cdsByStudent = [
    [0.15, 0.30, 0.25],
    [0.45, 0.55, 0.70],
    [0.80, 0.75, 0.90],
    [0.10, 0.20, 0.35],
    [0.60, 0.65, 0.85],
  ];

  for (let i = 0; i < count; i += 1) {
    const sid = seeded.studentIds[i];
    const values = cdsByStudent[i % cdsByStudent.length];
    for (let j = 0; j < exercises.length; j += 1) {
      await testPool.query(
        `INSERT INTO cds_scores (student_id, exercise_id, section_id, cds, classification, computed_at)
         VALUES ($1, $2, $3, $4, 'Scored', $5)`,
        [sid, exercises[j], seeded.sectionId, values[j], `2026-08-0${j + 1}T10:00:00Z`]
      );
      await seedSubmission(sid, exercises[j], { attemptNumber: 1, isCorrect: true });
    }
    // Radar data: two concepts with distinct CMI (0–100).
    for (const [conceptName, cmi] of [['Loops', 82], ['Arrays', 45]]) {
      const { rows } = await testPool.query(
        `INSERT INTO concepts (name) VALUES ($1) ON CONFLICT (name) DO NOTHING RETURNING id`,
        [conceptName]
      );
      const cid = rows.length ? rows[0].id : (
        await testPool.query('SELECT id FROM concepts WHERE name = $1', [conceptName])
      ).rows[0].id;
      await testPool.query(
        `INSERT INTO student_concept_metrics (student_id, concept_id, section_id, cmi, velocity, last_updated)
         VALUES ($1, $2, $3, $4, $5, NOW())
         ON CONFLICT (student_id, concept_id, section_id) DO UPDATE SET cmi = $4, velocity = $5`,
        [sid, cid, seeded.sectionId, cmi, 0]
      );
    }
  }

  // Integrity flags for two students (severity spread for the summary table).
  const flagSpecs = [
    { student: 0, type: 'similar_code', severity: 'high', status: 'flagged' },
    { student: 1, type: 'tab_switch', severity: 'low', status: 'reviewed' },
  ];
  for (const spec of flagSpecs) {
    if (spec.student >= count) continue;
    await testPool.query(
      `INSERT INTO integrity_flags (section_id, exercise_id, student_id, flag_type, severity, status, evidence, created_at)
       VALUES ($1, $2, $3, $4, $5, $6, '{}'::jsonb, $7)`,
      [seeded.sectionId, seeded.exerciseId, seeded.studentIds[spec.student], spec.type, spec.severity, spec.status, '2026-08-02T12:00:00Z']
    );
  }

  return seeded;
}

/**
 * Seed the standard scenario plus enough data for real charts: extra
 * exercises, per-student CDS history, daily submissions, concept metrics
 * and integrity flags.
 */
async function seedRichScenario({ studentCount = 5 } = {}) {
  const seeded = await seedFullScenario({ studentCount });
  return seedRichStudents(seeded, studentCount);
}

describe('pdfReport — pure data shapers', () => {
  it('avgCdsByDate groups and averages per date', () => {
    const rows = [
      { date: new Date('2026-08-01T10:00:00Z'), cds: 0.2 },
      { date: new Date('2026-08-01T11:00:00Z'), cds: 0.4 },
      { date: new Date('2026-08-02T10:00:00Z'), cds: 0.6 },
    ];
    const { labels, values } = avgCdsByDate(rows);
    expect(labels).toEqual(['2026-08-01', '2026-08-02']);
    expect(values[0]).toBeCloseTo(0.3, 10);
    expect(values[1]).toBeCloseTo(0.6, 10);
  });

  it('cdsDistribution buckets by CDS_STOPS boundaries', () => {
    const buckets = cdsDistribution([
      { cds: 0.05 }, { cds: 0.25 }, { cds: 0.45 }, { cds: 0.65 }, { cds: 0.85 },
    ]);
    expect(buckets.map((b) => b.count)).toEqual([1, 1, 1, 1, 1]);
    expect(buckets.map((b) => b.label)).toEqual(['0.0–0.2', '0.2–0.4', '0.4–0.6', '0.6–0.8', '0.8–1.0']);
  });

  it('atRiskCount flags students with average CDS above 0.60', () => {
    const rows = [
      { email: 'a@x', cds: 0.7 }, { email: 'a@x', cds: 0.8 }, // avg 0.75 → at risk
      { email: 'b@x', cds: 0.5 }, { email: 'b@x', cds: 0.4 }, // avg 0.45 → safe
      { email: 'c@x', cds: 0.61 }, // exactly at threshold+ε → at risk
    ];
    expect(atRiskCount(rows)).toBe(2);
  });

  it('buildHeatmap normalizes events through the CDS ramp and nulls empty days', () => {
    const rows = [
      { name: 'Ada', email: 'ada@x', date: new Date('2026-08-01'), events: 4 },
      { name: 'Ada', email: 'ada@x', date: new Date('2026-08-02'), events: 2 },
    ];
    const hm = buildHeatmap(rows, { maxRows: 2, maxCols: 2 });
    expect(hm.rowLabels).toEqual(['Ada']);
    expect(hm.colLabels).toEqual(['2026-08-01', '2026-08-02']);
    expect(hm.colorFn(0, 0)).toBe('#be123c'); // 4/4 = 1 → ramp end (rose)
    expect(hm.colorFn(0, 1)).not.toBeNull();
  });

  it('hasStudentData reports false for an empty report and true when any field carries data', () => {
    // The predicate's OR-chain yields a falsy value (not strictly `false`)
    // for an empty report; it is only ever consumed as a boolean gate.
    expect(hasStudentData({})).toBeFalsy();
    expect(hasStudentData({ trendValues: [0.5] })).toBe(true);
    expect(hasStudentData({ radar: { axes: ['Loops'], values: [0.5] } })).toBe(true);
    expect(hasStudentData({ heatmap: { rowLabels: ['X'], colLabels: ['D'] } })).toBe(true);
    expect(hasStudentData({ flags: [{}] })).toBe(true);
  });
});

describe('pdfReport — full class report', () => {
  let seeded;

  beforeEach(async () => {
    seeded = await seedRichScenario({ studentCount: 5 });
  });

  it('produces a PDF with header, body and multiple pages', async () => {
    const buffer = await buildSectionVisualReport(seeded.sectionId);
    expect(buffer.subarray(0, 5).toString('latin1')).toBe('%PDF-');
    expect(buffer.length).toBeGreaterThan(10000);
    // cover + summary + overview + 2×5 student pages + flags/appendix ≥ 4
    expect(pageCount(buffer)).toBeGreaterThanOrEqual(4);
  });

  it('renders a distinct per-student page for every data-active student', async () => {
    // Regression guard: fetchLongitudinal used to drop student_id from its
    // rows, so every per-student header page rendered the FIRST student
    // (5 identical pairs instead of one pair per student).
    const buffer = await buildSectionVisualReport(seeded.sectionId);
    const headers = perPageText(buffer).filter((t) => t.includes('Current CDS'));
    const headerNames = headers.map((t) => (t.match(/Test Student \d/) || [''])[0]);
    expect(headers.length).toBe(5); // one header page per data-active student
    expect(new Set(headerNames).size).toBe(5); // ...and they are all distinct
    for (let i = 0; i < 5; i += 1) {
      expect(headerNames).toContain(`Test Student ${i}`);
    }
  });

  it('rejects sections over 60 students with AppError 413 TOO_LARGE', async () => {
    const db = require('../config/db');
    const realQuery = db.query;
    // Stub only the enrollment COUNT so the guard fires without seeding 61 rows.
    db.query = async (text, values) => {
      if (typeof text === 'string' && /FROM enrollments/.test(text) && /COUNT/.test(text)) {
        return { rows: [{ count: 61 }] };
      }
      return realQuery(text, values);
    };
    try {
      let error = null;
      try {
        await buildSectionVisualReport(seeded.sectionId);
      } catch (err) {
        error = err;
      }
      expect(error).toBeTruthy();
      expect(error.status).toBe(413);
      expect(error.code).toBe('TOO_LARGE');
      expect(error.message).toContain('max 60 students');
    } finally {
      db.query = realQuery;
    }
  });

  it('allows a dossier for a section over 60 students (guard is full-report only)', async () => {
    const db = require('../config/db');
    const realQuery = db.query;
    db.query = async (text, values) => {
      if (typeof text === 'string' && /FROM enrollments/.test(text) && /COUNT/.test(text)) {
        return { rows: [{ count: 61 }] };
      }
      return realQuery(text, values);
    };
    try {
      const buffer = await buildSectionVisualReport(seeded.sectionId, { studentId: seeded.studentIds[0] });
      expect(buffer.subarray(0, 5).toString('latin1')).toBe('%PDF-');
      expect(pageCount(buffer)).toBeGreaterThanOrEqual(1);
    } finally {
      db.query = realQuery;
    }
  });
});

describe('pdfReport — no-data students add zero pages', () => {
  afterEach(async () => {
    // clearTestTables omits student_concept_metrics — wipe it here so no
    // stale concept rows leak into later scenarios.
    await testPool.query('DELETE FROM student_concept_metrics');
  });

  it('renders the same page count with or without inactive enrolled students', async () => {
    // Scenario A: 5 enrolled students, chart data for students 0–2 only
    // (students 3–4 have ZERO data).
    const scenarioA = await seedFullScenario({ studentCount: 5 });
    await seedRichStudents(scenarioA, 3);

    // Scenario B: only the 3 data students, identical inserts.
    const scenarioB = await seedFullScenario({ studentCount: 3 });
    await seedRichStudents(scenarioB, 3);

    const pagesA = pageCount(await buildSectionVisualReport(scenarioA.sectionId));
    const pagesB = pageCount(await buildSectionVisualReport(scenarioB.sectionId));
    // Arithmetic-free invariant: two extra enrolled students with no data
    // must contribute exactly zero pages.
    expect(pagesA).toBe(pagesB);
  });
});

describe('pdfReport — dossier mode', () => {
  let seeded;

  beforeEach(async () => {
    seeded = await seedRichScenario({ studentCount: 5 });
  });

  it('renders fewer pages than the full report', async () => {
    const full = await buildSectionVisualReport(seeded.sectionId);
    const dossier = await buildSectionVisualReport(seeded.sectionId, { studentId: seeded.studentIds[0] });

    // One dense page (header band + stats + charts + tables) — no cover page.
    expect(pageCount(dossier)).toBe(1);
    expect(pageCount(dossier)).toBeLessThan(pageCount(full));
  });

  it('includes the student on the page', async () => {
    const buffer = await buildSectionVisualReport(seeded.sectionId, { studentId: seeded.studentIds[0] });
    const text = pdfText(buffer);
    // The dossier has no cover page — the header band carries the marker
    // text and the student's name.
    expect(text).toContain('STUDENT DOSSIER');
    expect(text).toContain('Test Student 0');
  });

  it('renders the Submissions & Attempts table with the student\'s attempt rows', async () => {
    // seedRichScenario gives every student one submission per exercise (3 total).
    const buffer = await buildSectionVisualReport(seeded.sectionId, { studentId: seeded.studentIds[0] });
    const text = pdfText(buffer);
    expect(text).toContain('Submissions & Attempts');
    expect(text).toContain('Test Exercise');
  });

  it('exposes the document assembly helpers used by the route', () => {
    expect(typeof makeDocument).toBe('function');
    expect(typeof collectBuffer).toBe('function');
    expect(typeof drawCover).toBe('function');
    expect(typeof drawDossierPages).toBe('function');
  });

  it('renders a single page for an enrolled student with no data', async () => {
    const inactive = await seedFullScenario({ studentCount: 1 });
    const buffer = await buildSectionVisualReport(inactive.sectionId, { studentId: inactive.studentIds[0] });

    // One dense page (header + no-activity note) — no cover, no extra pages.
    expect(pageCount(buffer)).toBe(1);
    expect(pdfText(buffer)).toContain('No activity recorded for this student.');
  });
});

describe('pdfReport — edge cases', () => {
  it('yields a single-page "No data" PDF for a section with no enrollments', async () => {
    const instructorId = await seedTestInstructor();
    const sectionId = await seedTestSection(instructorId);
    const buffer = await buildSectionVisualReport(sectionId);

    expect(buffer.subarray(0, 5).toString('latin1')).toBe('%PDF-');
    expect(pageCount(buffer)).toBe(1);
    expect(pdfText(buffer)).toContain('No data');
  });

  it('yields a single-page "No data" PDF when the dossier student is not enrolled', async () => {
    const seeded = await seedFullScenario({ studentCount: 1 });
    // A student id that is not enrolled in the seeded section.
    const { rows } = await testPool.query(
      `INSERT INTO users (name, email, password_hash, role) VALUES ($1, $2, 'hashed_pw', 'student') RETURNING id`,
      ['Unenrolled Student', 'unenrolled@test.com']
    );
    const buffer = await buildSectionVisualReport(seeded.sectionId, { studentId: rows[0].id });
    expect(pageCount(buffer)).toBe(1);
    expect(pdfText(buffer)).toContain('No data');
  });
});
