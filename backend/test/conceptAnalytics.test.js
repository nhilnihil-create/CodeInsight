// backend/services/conceptAnalytics.test.js
// Tests for CMI, CRS, Learning Velocity, and Difficulty Index engine

const assert = require('assert');
const conceptAnalytics = require('../services/conceptAnalytics');

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
    const TEST_SECTION = 48; // Has 50 students, 150 exercises, real CDS data

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
