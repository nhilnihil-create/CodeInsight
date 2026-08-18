/**
 * Weighted All-Tags Heatmap Integration Tests
 *
 * Drives analyticsController.heatmap against the real codeinsight_test DB.
 * The app's config/db pool is pointed at the dev DB by backend/.env (loaded in
 * jest.config.js), so config/db is mocked with a delegate to the test pool —
 * the same pattern as test/runCheckpointIntegrity.test.js.
 *
 * Verifies the weighted multi-tag heatmap aggregation:
 *   - one aggregated row per (student, concept); cell cds = SUM(cds*w)/SUM(w)
 *   - secondary-only concepts still appear (no primary-only filter)
 *   - legacy exercises without exercise_concept_tags fall back to ex.concept_id
 *   - classification labels via countLabel thresholds
 *   - classAverages.avgCDS is the weighted average across all students
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

const assert = require('assert');
const analyticsController = require('../controllers/analyticsController');
const {
  pool: testPool,
  seedTestInstructor,
  seedTestSection,
  seedTestConcept,
  seedTestExercise,
  seedEnrollment,
} = require('./setup');

// ── Helpers ─────────────────────────────────────────────────────────────────

async function seedConceptByName(name) {
  const { rows } = await testPool.query(
    `INSERT INTO concepts (name) VALUES ($1)
     ON CONFLICT (name) DO UPDATE SET name = $1
     RETURNING id`,
    [name]
  );
  return rows[0].id;
}

async function seedTag(exerciseId, conceptId, weight, isPrimary) {
  await testPool.query(
    `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary)
     VALUES ($1, $2, $3, $4)`,
    [exerciseId, conceptId, weight, isPrimary]
  );
}

async function seedStudent(name, email) {
  const { rows } = await testPool.query(
    `INSERT INTO users (name, email, password_hash, role)
     VALUES ($1, $2, 'hashed_pw', 'student')
     ON CONFLICT (email) DO UPDATE SET name = $1
     RETURNING id`,
    [name, email]
  );
  return rows[0].id;
}

async function seedCds(studentId, exerciseId, sectionId, cds) {
  await testPool.query(
    `INSERT INTO cds_scores (student_id, exercise_id, section_id, cds, classification)
     VALUES ($1, $2, $3, $4, 'Medium')`,
    [studentId, exerciseId, sectionId, cds]
  );
}

async function seedCdsNull(studentId, exerciseId, sectionId, classification) {
  await testPool.query(
    `INSERT INTO cds_scores (student_id, exercise_id, section_id, cds, classification)
     VALUES ($1, $2, $3, NULL, $4)`,
    [studentId, exerciseId, sectionId, classification]
  );
}

function mockRes() {
  return {
    status: jest.fn().mockReturnThis(),
    json: jest.fn().mockReturnThis(),
  };
}

async function callHeatmap(sectionId, instructorId) {
  const req = {
    params: { sectionId: String(sectionId) },
    user: { id: instructorId, role: 'instructor' },
  };
  const res = mockRes();
  const next = jest.fn();
  await analyticsController.heatmap(req, res, next);
  if (next.mock.calls.length > 0) throw next.mock.calls[0][0];
  assert.strictEqual(res.json.mock.calls.length, 1, 'heatmap should respond via res.json');
  return res.json.mock.calls[0][0];
}

const close = (a, b, tol) => Math.abs(a - b) < tol;

describe('heatmap weighted all-tags', function() {
  it('returns one row per (student, concept) with weighted-average cell cds', async function() {
    const instructorId = await seedTestInstructor();
    const sectionId = await seedTestSection(instructorId);
    const loops = await seedTestConcept();
    const arrays = await seedConceptByName('Arrays');

    // E1: primary-tagged exercise (Loops, weight 1.0)
    const e1 = await seedTestExercise(sectionId, loops, { title: 'Primary Loop Ex' });
    await seedTag(e1, loops, 1.0, true);

    // E2: exercise tagged with 2 concepts — Loops secondary (0.5), Arrays primary (1.0)
    const e2 = await seedTestExercise(sectionId, arrays, { title: 'Multi-Tag Ex' });
    await seedTag(e2, loops, 0.5, false);
    await seedTag(e2, arrays, 1.0, true);

    const s1 = await seedStudent('Student One', 'h1@test.com');
    const s2 = await seedStudent('Student Two', 'h2@test.com');
    await seedEnrollment(s1, sectionId);
    await seedEnrollment(s2, sectionId);

    await seedCds(s1, e1, sectionId, 0.6);
    await seedCds(s1, e2, sectionId, 0.8);
    await seedCds(s2, e1, sectionId, 0.3);
    await seedCds(s2, e2, sectionId, 0.4);

    const body = await callHeatmap(sectionId, instructorId);

    // Concepts list contains both concepts
    assert.ok(body.concepts.includes('Loops'), `expected Loops in concepts, got ${body.concepts}`);
    assert.ok(body.concepts.includes('Arrays'), `expected Arrays in concepts, got ${body.concepts}`);

    // Students list contains both students
    const studentIds = body.students.map(st => st.id);
    assert.ok(studentIds.includes(s1), 's1 should appear in students');
    assert.ok(studentIds.includes(s2), 's2 should appear in students');

    // One aggregated cell per (student, concept)
    assert.ok(body.scores[s1] && body.scores[s1]['Loops'], 'no Loops cell for s1');
    assert.ok(body.scores[s1] && body.scores[s1]['Arrays'], 'no Arrays cell for s1');
    assert.ok(body.scores[s2] && body.scores[s2]['Loops'], 'no Loops cell for s2');
    assert.ok(body.scores[s2] && body.scores[s2]['Arrays'], 'no Arrays cell for s2');

    // Weighted cell: (0.6*1.0 + 0.8*0.5) / (1.0 + 0.5) = 1.0/1.5 = 0.6667
    assert.ok(close(body.scores[s1]['Loops'].cds, 0.666667, 0.001),
      `s1 Loops cds expected ~0.6667 (weighted avg), got ${body.scores[s1]['Loops'].cds}`);
    // ... and NOT a plain mean of the two contributions (0.7)
    assert.ok(!close(body.scores[s1]['Loops'].cds, 0.7, 0.001),
      's1 Loops cds should not be a plain mean of the two exercise contributions');

    // Arrays cell for s1 is a single contribution: 0.8
    assert.ok(close(body.scores[s1]['Arrays'].cds, 0.8, 0.001),
      `s1 Arrays cds expected 0.8, got ${body.scores[s1]['Arrays'].cds}`);

    // s2 Loops: (0.3*1.0 + 0.4*0.5) / 1.5 = 0.5/1.5 = 0.3333
    assert.ok(close(body.scores[s2]['Loops'].cds, 0.333333, 0.001),
      `s2 Loops cds expected ~0.3333, got ${body.scores[s2]['Loops'].cds}`);
  });

  it('keeps secondary-only concepts in the concepts list and scores columns', async function() {
    const instructorId = await seedTestInstructor();
    const sectionId = await seedTestSection(instructorId);
    const loops = await seedTestConcept();
    const arrays = await seedConceptByName('Arrays');

    const e1 = await seedTestExercise(sectionId, loops, { title: 'Loops Ex' });
    await seedTag(e1, loops, 1.0, true);

    // Arrays is tagged ONLY as a secondary concept — no is_primary tag anywhere
    const e2 = await seedTestExercise(sectionId, arrays, { title: 'Mixed Ex' });
    await seedTag(e2, loops, 1.0, true);
    await seedTag(e2, arrays, 0.5, false);

    const s1 = await seedStudent('Secondary Student', 'sec@test.com');
    await seedEnrollment(s1, sectionId);
    await seedCds(s1, e1, sectionId, 0.5);
    await seedCds(s1, e2, sectionId, 0.7);

    const body = await callHeatmap(sectionId, instructorId);

    assert.ok(body.concepts.includes('Arrays'),
      `secondary-only concept must appear in concepts, got ${body.concepts}`);
    assert.ok(body.scores[s1] && body.scores[s1]['Arrays'],
      'secondary-only concept must get a scores column');
    assert.ok(close(body.scores[s1]['Arrays'].cds, 0.7, 0.001),
      `Arrays cell expected 0.7, got ${body.scores[s1]['Arrays'].cds}`);
  });

  it('falls back to ex.concept_id with weight 1.0 for untagged legacy exercises', async function() {
    const instructorId = await seedTestInstructor();
    const sectionId = await seedTestSection(instructorId);
    const loops = await seedTestConcept();

    // No exercise_concept_tags rows for this exercise at all
    const e = await seedTestExercise(sectionId, loops, { title: 'Legacy Ex' });
    const s1 = await seedStudent('Legacy Student', 'legacy@test.com');
    await seedEnrollment(s1, sectionId);
    await seedCds(s1, e, sectionId, 0.55);

    const body = await callHeatmap(sectionId, instructorId);

    assert.ok(body.concepts.includes('Loops'),
      `legacy concept must resolve via COALESCE(pt.name, c.name), got ${body.concepts}`);
    assert.ok(body.scores[s1] && body.scores[s1]['Loops'],
      'legacy exercise must produce a Loops cell');
    assert.ok(close(body.scores[s1]['Loops'].cds, 0.55, 0.001),
      `legacy cell expected 0.55 (weight 1.0 fallback), got ${body.scores[s1]['Loops'].cds}`);
    assert.ok(close(body.classAverages['Loops'].avgCDS, 0.55, 0.001),
      `legacy avgCDS expected 0.55, got ${body.classAverages['Loops'].avgCDS}`);
  });

  it('maps cell and class-average CDS to countLabel classifications', async function() {
    const instructorId = await seedTestInstructor();
    const sectionId = await seedTestSection(instructorId);
    const loops = await seedTestConcept();

    const e = await seedTestExercise(sectionId, loops, { title: 'Class Ex' });
    await seedTag(e, loops, 1.0, true);

    // countLabel thresholds: cds <= 0.40 Low, <= 0.60 Moderate, > 0.60 High
    const sLow = await seedStudent('Low Student', 'low@test.com');
    const sMod = await seedStudent('Mod Student', 'mod@test.com');
    const sHigh = await seedStudent('High Student', 'high@test.com');
    for (const s of [sLow, sMod, sHigh]) await seedEnrollment(s, sectionId);
    await seedCds(sLow, e, sectionId, 0.25);
    await seedCds(sMod, e, sectionId, 0.50);
    await seedCds(sHigh, e, sectionId, 0.75);

    const body = await callHeatmap(sectionId, instructorId);

    assert.strictEqual(body.scores[sLow]['Loops'].classification, 'Low',
      `0.25 should be Low, got ${body.scores[sLow]['Loops'].classification}`);
    assert.strictEqual(body.scores[sMod]['Loops'].classification, 'Moderate',
      `0.50 should be Moderate, got ${body.scores[sMod]['Loops'].classification}`);
    assert.strictEqual(body.scores[sHigh]['Loops'].classification, 'High',
      `0.75 should be High, got ${body.scores[sHigh]['Loops'].classification}`);
    // Class average = (0.25 + 0.50 + 0.75) / 3 = 0.50 -> Moderate
    assert.strictEqual(body.classAverages['Loops'].classification, 'Moderate',
      `avg 0.5 should be Moderate, got ${body.classAverages['Loops'].classification}`);
  });

  it('computes avgCDS per concept in classAverages as a weighted average', async function() {
    const instructorId = await seedTestInstructor();
    const sectionId = await seedTestSection(instructorId);
    const loops = await seedTestConcept();
    const arrays = await seedConceptByName('Arrays');

    const e1 = await seedTestExercise(sectionId, loops, { title: 'E1' });
    await seedTag(e1, loops, 1.0, true);
    const e2 = await seedTestExercise(sectionId, arrays, { title: 'E2' });
    await seedTag(e2, loops, 0.5, false);
    await seedTag(e2, arrays, 1.0, true);

    const s1 = await seedStudent('Avg One', 'avg1@test.com');
    const s2 = await seedStudent('Avg Two', 'avg2@test.com');
    await seedEnrollment(s1, sectionId);
    await seedEnrollment(s2, sectionId);
    await seedCds(s1, e1, sectionId, 0.5);
    await seedCds(s1, e2, sectionId, 0.7);
    await seedCds(s2, e1, sectionId, 0.2);
    await seedCds(s2, e2, sectionId, 0.4);

    const body = await callHeatmap(sectionId, instructorId);

    // Loops: (0.5*1 + 0.7*0.5 + 0.2*1 + 0.4*0.5) / (1+0.5+1+0.5) = 1.0/3.0 = 0.3333
    const expected = (0.5 * 1.0 + 0.7 * 0.5 + 0.2 * 1.0 + 0.4 * 0.5) / 3.0;
    assert.ok(close(body.classAverages['Loops'].avgCDS, expected, 0.001),
      `avgCDS expected ${expected}, got ${body.classAverages['Loops'].avgCDS}`);
    // plain mean would be (0.5+0.7+0.2+0.4)/4 = 0.45
    assert.ok(!close(body.classAverages['Loops'].avgCDS, 0.45, 0.001),
      'avgCDS must not be a plain mean');
    // Arrays: (0.7*1 + 0.4*1) / 2 = 0.55
    assert.ok(close(body.classAverages['Arrays'].avgCDS, 0.55, 0.001),
      `Arrays avgCDS expected 0.55, got ${body.classAverages['Arrays'].avgCDS}`);
  });

  it('returns blankReasons for null-CDS Flagged-Pending and Unscored cells', async function() {
    const instructorId = await seedTestInstructor();
    const sectionId = await seedTestSection(instructorId);
    const loops = await seedTestConcept();
    const arrays = await seedConceptByName('Arrays');

    // E1: tagged to Arrays (will have non-null CDS for all students)
    const e1 = await seedTestExercise(sectionId, arrays, { title: 'Array Exercise' });
    await seedTag(e1, arrays, 1.0, true);

    // E2: tagged to Loops (will have null CDS for both students)
    const e2 = await seedTestExercise(sectionId, loops, { title: 'Loop Exercise' });
    await seedTag(e2, loops, 1.0, true);

    const s1 = await seedStudent('Flagged Student', 'flagged@test.com');
    const s2 = await seedStudent('Unscored Student', 'unscored@test.com');
    await seedEnrollment(s1, sectionId);
    await seedEnrollment(s2, sectionId);

    // Both students have non-null CDS on the Arrays exercise (so they appear in grid)
    await seedCds(s1, e1, sectionId, 0.5);
    await seedCds(s2, e1, sectionId, 0.3);

    // s1 has Flagged-Pending on the Loops exercise
    await seedCdsNull(s1, e2, sectionId, 'Flagged-Pending');
    // s2 has Unscored on the Loops exercise
    await seedCdsNull(s2, e2, sectionId, 'Unscored');

    const body = await callHeatmap(sectionId, instructorId);

    // Both students appear in the grid
    const studentIds = body.students.map(st => st.id);
    assert.ok(studentIds.includes(s1), 's1 should appear');
    assert.ok(studentIds.includes(s2), 's2 should appear');

    // Their Loops cells are blank — absent from scores (cds IS NOT NULL filter)
    assert.ok(!body.scores[s1]?.['Loops'],
      's1 Loops should not appear in scores (null CDS)');
    assert.ok(!body.scores[s2]?.['Loops'],
      's2 Loops should not appear in scores (null CDS)');

    // blankReasons exist for both students on Loops
    assert.ok(body.blankReasons[s1], 's1 should have blankReasons');
    assert.ok(body.blankReasons[s1]['Loops'], 's1 should have blankReason for Loops');
    assert.strictEqual(body.blankReasons[s1]['Loops'].classification, 'Flagged-Pending',
      's1 Loops should be Flagged-Pending');
    assert.strictEqual(body.blankReasons[s1]['Loops'].exerciseTitle, 'Loop Exercise',
      's1 Loops exercise title should be Loop Exercise');

    assert.ok(body.blankReasons[s2], 's2 should have blankReasons');
    assert.ok(body.blankReasons[s2]['Loops'], 's2 should have blankReason for Loops');
    assert.strictEqual(body.blankReasons[s2]['Loops'].classification, 'Unscored',
      's2 Loops should be Unscored');

    // Their Arrays cells are still colored (non-null CDS)
    assert.ok(close(body.scores[s1]['Arrays'].cds, 0.5, 0.001),
      's1 Arrays should have non-null CDS');
    assert.ok(close(body.scores[s2]['Arrays'].cds, 0.3, 0.001),
      's2 Arrays should have non-null CDS');

    // No blankReasons for Arrays (those cells are colored)
    const s1ArraysReason = body.blankReasons[s1]?.['Arrays'];
    assert.ok(!s1ArraysReason, 's1 should not have blankReason for Arrays');
  });

  it('does not include blankReasons entries for colored cells', async function() {
    const instructorId = await seedTestInstructor();
    const sectionId = await seedTestSection(instructorId);
    const loops = await seedTestConcept();

    const e = await seedTestExercise(sectionId, loops, { title: 'No Blank Ex' });
    await seedTag(e, loops, 1.0, true);

    const s1 = await seedStudent('All Colored', 'colored@test.com');
    await seedEnrollment(s1, sectionId);
    await seedCds(s1, e, sectionId, 0.45);

    const body = await callHeatmap(sectionId, instructorId);

    assert.ok(body.blankReasons, 'blankReasons should exist in response');
    assert.ok(Object.keys(body.blankReasons).length === 0 || !body.blankReasons[s1],
      'no blankReasons for a student with all colored cells');
  });
});
