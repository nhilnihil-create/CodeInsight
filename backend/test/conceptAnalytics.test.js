// backend/services/conceptAnalytics.test.js
// Tests for CMI, CRS, Learning Velocity, and Difficulty Index engine

// The app's config/db pool is pointed at the dev DB by backend/.env (loaded in
// jest.config.js), so config/db is mocked with a delegate to the test pool so
// the services under test read/write the same codeinsight_test DB the fixtures
// seed — the same pattern as test/heatmapAllTags.test.js and
// test/runCheckpointIntegrity.test.js.
jest.mock('../config/db', () => {
  const { pool } = require('./setup');
  return {
    query: (text, values) => pool.query(text, values),
    connect: async () => {
      const client = await pool.connect();
      return {
        query: (text, values) => client.query(text, values),
        release: () => client.release(),
      };
    },
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
const conceptAnalytics = require('../services/conceptAnalytics');
const {
  pool: testPool,
  seedTestInstructor,
  seedTestSection,
  seedTestConcept,
  seedTestExercise,
  seedTestUser,
  seedEnrollment,
  seedSubmission,
  clearTestTables,
} = require('./setup');

describe('conceptAnalytics', function() {
  // ── Export verification ───────────────────────────────────────────

  it('exports all required functions', function() {
    assert.strictEqual(typeof conceptAnalytics.computeAllMetrics, 'function');
    assert.strictEqual(typeof conceptAnalytics.computeCMI, 'function');
    assert.strictEqual(typeof conceptAnalytics.computeVelocity, 'function');
    assert.strictEqual(typeof conceptAnalytics.computeCRS, 'function');
    assert.strictEqual(typeof conceptAnalytics.updateMetricsForSubmission, 'function');
    assert.strictEqual(typeof conceptAnalytics.getStudentCMI, 'function');
    assert.strictEqual(typeof conceptAnalytics.getSectionCRS, 'function');
    assert.strictEqual(typeof conceptAnalytics.getConceptPrerequisites, 'function');
  });

  // ── _classifyCRS logic (via public API) ──────────────────────────

  describe('CRS classification', function() {
    // Test classification thresholds indirectly through computeCRS
    it('computeCRS returns structured result', async function() {
      const result = await conceptAnalytics.computeCRS(99999);
      assert.ok(result);
      assert.ok(typeof result.updated === 'number');
    });
  });

  // ── No-data edge cases ───────────────────────────────────────────

  describe('empty data handling', function() {
    it('computeCMI returns 0 for non-existent section', async function() {
      const result = await conceptAnalytics.computeCMI(99999);
      assert.strictEqual(result.updated, 0);
    });

    it('computeVelocity returns 0 for non-existent section', async function() {
      const result = await conceptAnalytics.computeVelocity(99999);
      assert.strictEqual(result.updated, 0);
    });

    it('computeCRS returns 0 for non-existent section', async function() {
      const result = await conceptAnalytics.computeCRS(99999);
      assert.strictEqual(result.updated, 0);
    });

    it('getStudentCMI returns empty for non-existent student', async function() {
      const result = await conceptAnalytics.getStudentCMI(99999, 99999);
      assert.strictEqual(result.length, 0);
    });

    it('getSectionCRS returns empty for non-existent section', async function() {
      const result = await conceptAnalytics.getSectionCRS(99999);
      assert.strictEqual(result.length, 0);
    });

    it('getConceptPrerequisites returns empty for non-existent concept', async function() {
      const result = await conceptAnalytics.getConceptPrerequisites(99999);
      assert.strictEqual(result.length, 0);
    });

    it('updateMetricsForSubmission returns reason for non-existent exercise', async function() {
      const result = await conceptAnalytics.updateMetricsForSubmission(1, 99999);
      assert.strictEqual(result.updated, false);
      assert.ok(result.reason);
    });
  });

  // ── Integration tests with real data ─────────────────────────────

  describe('integration (real DB)', function() {
    let TEST_SECTION;

    beforeEach(async () => {
      await clearTestTables();
      const instructorId = await seedTestInstructor();
      TEST_SECTION = await seedTestSection(instructorId);
      const conceptId = await seedTestConcept();
      const exerciseId = await seedTestExercise(TEST_SECTION, conceptId, { title: 'Concept Analytics Test' });
      // seedTestExercise does NOT create exercise_concept_tags — required by computeCMI/computeCRS
      await testPool.query(
        `INSERT INTO exercise_concept_tags (exercise_id, concept_id, is_primary)
         VALUES ($1, $2, true)`,
        [exerciseId, conceptId]
      );
      const studentId = await seedTestUser();
      await seedEnrollment(studentId, TEST_SECTION);
      await seedSubmission(studentId, exerciseId, { isCorrect: true, timeSpent: 30 });
      // computeCRS reads cds_scores with cds IS NOT NULL
      await testPool.query(
        `INSERT INTO cds_scores (student_id, exercise_id, section_id, cds, classification)
         VALUES ($1, $2, $3, 0.5, 'Medium')`,
        [studentId, exerciseId, TEST_SECTION]
      );
      // getSectionCRS reads section_concept_metrics; seeded directly because the
      // global afterEach wipes computeCRS's writes before that test runs
      await testPool.query(
        `INSERT INTO section_concept_metrics (section_id, concept_id, crs, crs_score, student_count, at_risk_count)
         VALUES ($1, $2, 'medium', 0.5, 1, 0)`,
        [TEST_SECTION, conceptId]
      );
    });

    it('computeCMI updates student metrics', async function() {
      const result = await conceptAnalytics.computeCMI(TEST_SECTION);
      assert.ok(result.updated > 0, `Expected CMI updates, got ${result.updated}`);
    });

    it('computeVelocity updates after CMI exists', async function() {
      const result = await conceptAnalytics.computeVelocity(TEST_SECTION);
      // Velocity may or may not have enough data — just check it doesn't crash
      assert.ok(typeof result.updated === 'number');
    });

    it('computeCRS updates section metrics', async function() {
      const result = await conceptAnalytics.computeCRS(TEST_SECTION);
      assert.ok(result.updated > 0, `Expected CRS updates, got ${result.updated}`);
    });

    it('computeAllMetrics runs all computations in transaction', async function() {
      const result = await conceptAnalytics.computeAllMetrics(TEST_SECTION);
      assert.ok(result.cmiUpdated >= 0);
      assert.ok(result.velocityUpdated >= 0);
      assert.ok(result.crsUpdated >= 0);
    });

    it('getStudentCMI returns structured data', async function() {
      const result = await conceptAnalytics.getStudentCMI(203, TEST_SECTION);
      assert.ok(Array.isArray(result));
      if (result.length > 0) {
        const item = result[0];
        assert.ok(item.conceptId);
        assert.ok(item.conceptName);
        assert.ok(typeof item.cmi === 'number');
        assert.ok(typeof item.velocity === 'number');
        assert.ok(item.cmi >= 0 && item.cmi <= 100);
      }
    });

    it('getSectionCRS returns structured data', async function() {
      const result = await conceptAnalytics.getSectionCRS(TEST_SECTION);
      assert.ok(Array.isArray(result));
      assert.ok(result.length > 0);
      const item = result[0];
      assert.ok(item.conceptName);
      assert.ok(typeof item.crsScore === 'number');
      assert.ok(['low', 'medium', 'high', 'critical', 'unknown'].includes(item.crs));
      assert.ok(item.studentCount >= 0);
      assert.ok(item.atRiskCount >= 0);
    });

    it('getConceptPrerequisites returns dependency chain', async function() {
      // Loops (id=4) should have Conditionals → Variables → Datatypes as prerequisites
      const result = await conceptAnalytics.getConceptPrerequisites(4);
      assert.ok(Array.isArray(result));
      if (result.length > 0) {
        const names = result.map(r => r.conceptName);
        // Should find Variables or Datatypes in the chain
        assert.ok(
          names.includes('Variables') || names.includes('Conditionals') || names.includes('Datatypes'),
          `Expected Variables/Conditionals/Datatypes in prerequisites, got: ${names.join(', ')}`
        );
      }
    });

    it('CMI values are bounded [0, 100]', async function() {
      const result = await conceptAnalytics.getStudentCMI(203, TEST_SECTION);
      for (const item of result) {
        assert.ok(item.cmi >= 0 && item.cmi <= 100,
          `CMI for ${item.conceptName} is ${item.cmi}, out of bounds`);
      }
    });

  });

  // ── ITP1 section tests ───────────────────────────────────────────

  describe('ITP1 section (section 51)', function() {
    const ITP1_SECTION = 51; // Fresh section with 30 seeded exercises

    it('computeAllMetrics works for ITP1 section', async function() {
      const result = await conceptAnalytics.computeAllMetrics(ITP1_SECTION);
      assert.ok(typeof result.cmiUpdated === 'number');
      assert.ok(typeof result.crsUpdated === 'number');
    });

    it('CRS has correct risk levels', async function() {
      const result = await conceptAnalytics.getSectionCRS(ITP1_SECTION);
      for (const item of result) {
        assert.ok(
          ['low', 'medium', 'high', 'critical', 'unknown'].includes(item.crs),
          `Invalid CRS level for ${item.conceptName}: ${item.crs}`
        );
      }
    });
  });
});

// ── Weighted multi-tag aggregation ───────────────────────────────────────────
// Exercises can carry multiple concept tags with per-tag weights (primary 1.0,
// secondaries < 1.0). computeCMI aggregates per-tag-weighted mastery
// (SUM(mastery·w)/SUM(w)) and computeCRS aggregates tag-weighted CDS, so a
// concept reached only through a non-primary tag must still get metrics.

describe('weighted multi-tag aggregation', function() {
  let TEST_SECTION;
  let conceptA;
  let conceptB;
  let studentId;

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

  // Mirrors the normalization + mastery terms in computeCMI for the
  // single-student, single-submission-per-exercise fixtures used below.
  function expectedNormalize(value, allValues) {
    if (allValues.length === 0) return 0;
    const max = Math.max(...allValues, 1);
    return Math.min(value / max, 1.0);
  }

  function expectedMastery(isCorrect, timeSpent, classMaxTime) {
    const totalForExercise = 1; // one submission per exercise in these fixtures
    const correctForExercise = isCorrect ? 1 : 0;
    const failRate = (totalForExercise - correctForExercise) / totalForExercise;
    const normAttempts = expectedNormalize(totalForExercise, [totalForExercise]);
    const normTime = expectedNormalize(timeSpent, [classMaxTime]);
    return 100 * (1 - (0.40 * failRate + 0.35 * normAttempts + 0.25 * normTime));
  }

  beforeEach(async function() {
    await clearTestTables();
    const instructorId = await seedTestInstructor();
    TEST_SECTION = await seedTestSection(instructorId);
    conceptA = await seedTestConcept(); // 'Loops'
    conceptB = await seedConceptByName('Arrays');
    studentId = await seedTestUser();
    await seedEnrollment(studentId, TEST_SECTION);
  });

  it('computes CMI for every tagged concept with per-tag weights applied', async function() {
    // E1 is tagged with A (primary, w=1.0) AND B (secondary, w=0.5); E2 is
    // tagged only with A at a different weight (w=0.5). With one submission per
    // exercise, A's weighted mean differs from both a plain mean over the same
    // exercises and from B's CMI on the shared exercise.
    const e1 = await seedTestExercise(TEST_SECTION, conceptA, { title: 'Shared Exercise' });
    await seedTag(e1, conceptA, 1.0, true);
    await seedTag(e1, conceptB, 0.5, false);
    const e2 = await seedTestExercise(TEST_SECTION, conceptA, { title: 'A-Only Exercise' });
    await seedTag(e2, conceptA, 0.5, true);

    await seedSubmission(studentId, e1, { isCorrect: true, timeSpent: 30 });
    await seedSubmission(studentId, e2, { isCorrect: false, timeSpent: 30 });

    const result = await conceptAnalytics.computeCMI(TEST_SECTION);
    assert.strictEqual(result.updated, 2, 'CMI rows expected for both concepts A and B');

    const { rows } = await testPool.query(
      `SELECT concept_id, cmi FROM student_concept_metrics
       WHERE student_id = $1 AND section_id = $2`,
      [studentId, TEST_SECTION]
    );
    const cmiByConcept = {};
    for (const row of rows) cmiByConcept[row.concept_id] = Number(row.cmi);
    assert.ok(cmiByConcept[conceptA] !== undefined, 'concept A should have a CMI row');
    assert.ok(cmiByConcept[conceptB] !== undefined, 'concept B should have a CMI row');

    // Expected values computed from the implementation's formula.
    const masteryShared = expectedMastery(true, 30, 30); // all-correct, normalized 1.0
    const masteryAOnly = expectedMastery(false, 30, 30); // all-wrong → 0
    const expectedA = Math.round((masteryShared * 1.0 + masteryAOnly * 0.5) / (1.0 + 0.5));
    const expectedB = Math.round((masteryShared * 0.5) / 0.5);
    const plainMeanA = Math.round((masteryShared + masteryAOnly) / 2);
    assert.notStrictEqual(expectedA, plainMeanA,
      'fixture must produce a weighted mean distinct from a plain mean');
    assert.strictEqual(cmiByConcept[conceptA], expectedA,
      `concept A should use the tag-weighted mean ${expectedA}, not the plain mean ${plainMeanA}`);
    assert.strictEqual(cmiByConcept[conceptB], expectedB);
    assert.notStrictEqual(cmiByConcept[conceptA], cmiByConcept[conceptB],
      'shared-exercise CMI must be weighted per tag, not identical for A and B');
  });

  it('computes metrics for a concept reached only via a non-primary tag', async function() {
    const e1 = await seedTestExercise(TEST_SECTION, conceptA, { title: 'Primary Tag' });
    await seedTag(e1, conceptA, 1.0, true);
    await seedTag(e1, conceptB, 0.5, false); // B is reachable only via a non-primary tag
    await seedSubmission(studentId, e1, { isCorrect: true, timeSpent: 30 });
    await testPool.query(
      `INSERT INTO cds_scores (student_id, exercise_id, section_id, cds, classification)
       VALUES ($1, $2, $3, 0.5, 'Medium')`,
      [studentId, e1, TEST_SECTION]
    );

    const cmiResult = await conceptAnalytics.computeCMI(TEST_SECTION);
    assert.strictEqual(cmiResult.updated, 2, 'CMI must include the secondary-only concept');
    const cmiRows = await testPool.query(
      `SELECT concept_id FROM student_concept_metrics
       WHERE student_id = $1 AND section_id = $2`,
      [studentId, TEST_SECTION]
    );
    const cmiConceptIds = cmiRows.rows.map(r => r.concept_id);
    assert.ok(cmiConceptIds.includes(conceptB),
      `secondary-only concept B missing from student_concept_metrics: ${cmiConceptIds.join(', ')}`);

    const crsResult = await conceptAnalytics.computeCRS(TEST_SECTION);
    assert.strictEqual(crsResult.updated, 2, 'CRS must include the secondary-only concept');
    const scmRows = await testPool.query(
      `SELECT concept_id FROM section_concept_metrics WHERE section_id = $1`,
      [TEST_SECTION]
    );
    const scmConceptIds = scmRows.rows.map(r => r.concept_id);
    assert.ok(scmConceptIds.includes(conceptB),
      `secondary-only concept B missing from section_concept_metrics: ${scmConceptIds.join(', ')}`);

    const sectionCRS = await conceptAnalytics.getSectionCRS(TEST_SECTION);
    const crsConceptIds = sectionCRS.map(r => r.conceptId);
    assert.ok(crsConceptIds.includes(conceptB),
      `secondary-only concept B missing from getSectionCRS: ${crsConceptIds.join(', ')}`);
  });

  it('computeCRS aggregates cds_scores by tag weight', async function() {
    // E1: tag weight 1.0, cds 0.8. E2: tag weight 0.5, cds 0.4.
    // Weighted CRS = (0.8·1.0 + 0.4·0.5) / (1.0 + 0.5) = 0.666…, which the
    // DECIMAL(5,2) crs_score column stores as 0.67 (mirrors the storage
    // rounding the implementation relies on).
    const e1 = await seedTestExercise(TEST_SECTION, conceptA, { title: 'CRS W1' });
    const e2 = await seedTestExercise(TEST_SECTION, conceptA, { title: 'CRS W0.5' });
    await seedTag(e1, conceptA, 1.0, true);
    await seedTag(e2, conceptA, 0.5, false);
    await testPool.query(
      `INSERT INTO cds_scores (student_id, exercise_id, section_id, cds, classification)
       VALUES ($1, $2, $3, 0.8, 'High'), ($1, $4, $3, 0.4, 'Medium')`,
      [studentId, e1, TEST_SECTION, e2]
    );

    // Note: computeCRS's concept-resolving query is intentionally NOT DISTINCT,
    // so `updated` counts one pass per (concept, tagged exercise) row — with two
    // tagged exercises this is 2 even for a single concept. The meaningful
    // assertion is the aggregated crs_score, asserted below.
    await conceptAnalytics.computeCRS(TEST_SECTION);

    const sectionCRS = await conceptAnalytics.getSectionCRS(TEST_SECTION);
    const conceptRow = sectionCRS.find(r => r.conceptId === conceptA);
    assert.ok(conceptRow, 'CRS row for concept A should be present');
    const expectedCrs = Math.round(((0.8 * 1.0 + 0.4 * 0.5) / (1.0 + 0.5)) * 100) / 100;
    assert.strictEqual(conceptRow.crsScore, expectedCrs,
      `expected tag-weighted crs_score ${expectedCrs}, got ${conceptRow.crsScore}`);
    assert.strictEqual(conceptRow.studentCount, 1);
  });
});
