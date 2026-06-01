/**
 * Longitudinal Report Engine Test Suite
 * Tests for the longitudinal report engine service
 */

const assert = require('assert');

// We need to mock the modules before requiring the service
jest.mock('../config/db', () => ({
  query: jest.fn()
}));

const db = require('../config/db');
const { calculateMasteryVelocity } = require('../services/longitudinalReportEngine');

describe('Longitudinal Report Engine Test Suite', function() {
  // Reset mocks before each test
  beforeEach(() => {
    jest.clearAllMocks();
  });

  describe('calculateMasteryVelocity', function() {
    it('should return insufficient data message when less than 2 scores exist', async function() {
      // Mock database query to return only 1 score
      db.query.mockResolvedValueOnce({ rows: [
        { cds: 0.5, classification: 'Moderate', computed_at: '2026-05-01', exercise_title: 'Exercise 1', exercise_id: 1 }
      ] });

      const result = await calculateMasteryVelocity(1, 1);

      assert.strictEqual(result.studentId, 1);
      assert.strictEqual(result.conceptId, 1);
      assert.strictEqual(result.masteryVelocity, 0);
      assert.strictEqual(result.progressTrend, 'insufficient_data');
      assert.strictEqual(result.message, 'Need at least 2 exercises to calculate mastery velocity');
      assert.strictEqual(result.scores.length, 1);
      assert.ok(Array.isArray(result.recommendations));
      assert.ok(result.recommendations.length > 0);
    });

    it('should calculate mastery velocity for improving student', async function() {
      // Mock database query to return 3 scores showing improvement
      db.query.mockResolvedValueOnce({ rows: [
        { cds: 0.3, classification: 'Low', computed_at: '2026-05-01', exercise_title: 'Exercise 1', exercise_id: 1 },
        { cds: 0.5, classification: 'Moderate', computed_at: '2026-05-10', exercise_title: 'Exercise 2', exercise_id: 2 },
        { cds: 0.7, classification: 'High', computed_at: '2026-05-20', exercise_title: 'Exercise 3', exercise_id: 3 }
      ] });

      // Mock concept query
      db.query.mockResolvedValueOnce({ rows: [{ name: 'Conditionals' }] });

      const result = await calculateMasteryVelocity(1, 1);

      assert.strictEqual(result.studentId, 1);
      assert.strictEqual(result.conceptId, 1);
      assert.strictEqual(result.conceptName, 'Conditionals');
      // Improvement: 0.7 - 0.3 = 0.4 over 19 days = ~0.021 per day * 100 = 2.1
      assert.ok(result.masteryVelocity > 0);
      assert.strictEqual(result.progressTrend, 'improving_rapidly'); // > 0.5 threshold
      assert.strictEqual(result.firstScore, 0.3);
      assert.strictEqual(result.lastScore, 0.7);
      assert.strictEqual(result.scoreImprovement, 0.4);
      assert.strictEqual(result.timeSpanDays, 19);
      assert.ok(Array.isArray(result.scores));
      assert.strictEqual(result.scores.length, 3);
      assert.ok(Array.isArray(result.insights));
      assert.ok(result.insights.length > 0);
      assert.ok(Array.isArray(result.recommendations));
      assert.ok(result.recommendations.length > 0);
    });

    it('should calculate mastery velocity for declining student', async function() {
      // Mock database query to return 3 scores showing decline
      db.query.mockResolvedValueOnce({ rows: [
        { cds: 0.8, classification: 'High', computed_at: '2026-05-01', exercise_title: 'Exercise 1', exercise_id: 1 },
        { cds: 0.6, classification: 'Moderate', computed_at: '2026-05-10', exercise_title: 'Exercise 2', exercise_id: 2 },
        { cds: 0.4, classification: 'Low', computed_at: '2026-05-20', exercise_title: 'Exercise 3', exercise_id: 3 }
      ] });

      // Mock concept query
      db.query.mockResolvedValueOnce({ rows: [{ name: 'Loops' }] });

      const result = await calculateMasteryVelocity(1, 2);

      assert.strictEqual(result.studentId, 1);
      assert.strictEqual(result.conceptId, 2);
      assert.strictEqual(result.conceptName, 'Loops');
      // Decline: 0.4 - 0.8 = -0.4 over 19 days = ~-0.021 per day * 100 = -2.1
      assert.ok(result.masteryVelocity < 0);
      assert.strictEqual(result.progressTrend, 'declining_rapidly'); // < -0.5 threshold
      assert.strictEqual(result.firstScore, 0.8);
      assert.strictEqual(result.lastScore, 0.4);
      assert.strictEqual(result.scoreImprovement, -0.4);
      assert.strictEqual(result.timeSpanDays, 19);
      assert.ok(Array.isArray(result.scores));
      assert.strictEqual(result.scores.length, 3);
      assert.ok(Array.isArray(result.insights));
      assert.ok(result.insights.length > 0);
      assert.ok(Array.isArray(result.recommendations));
      assert.ok(result.recommendations.length > 0);
    });

    it('should handle database errors gracefully', async function() {
      // Mock database query to throw an error
      db.query.mockRejectedValueOnce(new Error('Database connection failed'));

      const result = await calculateMasteryVelocity(1, 1);

      assert.strictEqual(result.studentId, 1);
      assert.strictEqual(result.conceptId, 1);
      assert.strictEqual(result.error, 'Failed to calculate mastery velocity');
      assert.strictEqual(result.message, 'Database connection failed');
    });
  });
});

console.log('Longitudinal Report Engine test suite created');