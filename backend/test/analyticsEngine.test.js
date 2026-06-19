// backend/services/analyticsEngine.test.js
// Tests for algorithmic at-risk student analytics engine

const assert = require('assert');
const analyticsEngine = require('../services/analyticsEngine');

describe('analyticsEngine', function() {
  // Constants
  it('exports correct constants', function() {
    assert.strictEqual(analyticsEngine.RETRY_STORM_THRESHOLD, 10);
    assert.strictEqual(analyticsEngine.RETRY_STORM_WINDOW_MIN, 30);
    assert.strictEqual(analyticsEngine.PLATEAU_WINDOW_EXERCISES, 3);
  });

  it('exports all required functions', function() {
    assert.strictEqual(typeof analyticsEngine.trackSubmission, 'function');
    assert.strictEqual(typeof analyticsEngine.detectRetryStorm, 'function');
    assert.strictEqual(typeof analyticsEngine.detectLearningPlateau, 'function');
    assert.strictEqual(typeof analyticsEngine.getDashboardAlerts, 'function');
    assert.strictEqual(typeof analyticsEngine.reviewAlert, 'function');
  });

  describe('detectRetryStorm (no DB)', function() {
    it('returns triggered=false when DB unavailable', async function() {
      // Without a real DB connection, the function should gracefully fail
      const result = await analyticsEngine.detectRetryStorm(999, 999, 999);
      assert.strictEqual(typeof result, 'object');
      assert.strictEqual(result.triggered, false);
    });
  });

  describe('detectLearningPlateau (no DB)', function() {
    it('returns triggered=false when DB unavailable', async function() {
      const result = await analyticsEngine.detectLearningPlateau(999, 999);
      assert.strictEqual(typeof result, 'object');
      assert.strictEqual(result.triggered, false);
    });
  });

  describe('getDashboardAlerts (no DB)', function() {
    it('returns empty alerts when DB unavailable', async function() {
      const result = await analyticsEngine.getDashboardAlerts(999);
      assert.strictEqual(result.totalAlerts, 0);
      assert.strictEqual(result.alerts.length, 0);
      assert.ok(result.bySeverity);
      assert.strictEqual(result.bySeverity.critical, 0);
      assert.strictEqual(result.bySeverity.high, 0);
      assert.strictEqual(result.bySeverity.moderate, 0);
      assert.strictEqual(result.bySeverity.low, 0);
    });
  });

  describe('reviewAlert (no DB)', function() {
    it('returns structured result', async function() {
      const result = await analyticsEngine.reviewAlert(999, 'TEST_TYPE');
      assert.ok(result);
      assert.ok(typeof result.success === 'boolean');
    });
  });

  describe('trackSubmission (no DB)', function() {
    it('does not throw when DB unavailable', async function() {
      // Should not throw — it's designed to be non-blocking
      await analyticsEngine.trackSubmission({
        studentId: 999,
        exerciseId: 999,
        isCorrect: false,
        sectionId: 999,
        attemptNumber: 2,
      });
      // If we get here without throwing, the test passes
      assert.ok(true);
    });
  });
});
