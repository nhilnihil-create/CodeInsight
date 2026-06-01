/**
 * Class Misconception Report Test Suite
 * Tests for the class misconception report service
 */

const assert = require('assert');

// We need to mock the modules before requiring the service
jest.mock('../config/db', () => ({
  query: jest.fn()
}));
jest.mock('../services/microConceptEngine.js', () => ({
  getMicroConceptFeedback: jest.fn()
}));

// Get the mocked modules
const db = require('../config/db');
const microConceptEngine = require('../services/microConceptEngine.js');

const { generateClassMisconceptionReport } = require('../services/classMisconceptionReport');

describe('Class Misconception Report Test Suite', function() {
  // Reset mocks before each test
  beforeEach(() => {
    jest.clearAllMocks();
  });

  describe('generateClassMisconceptionReport', function() {
    it('should return a report with zero students when no submissions exist', async function() {
      // Mock exercise exists
      db.query.mockResolvedValueOnce({ rows: [{ id: 1, title: 'Test Exercise', concept_name: 'Variables', ast_nodes: '[]' }] });
      // Mock no submissions
      db.query.mockResolvedValueOnce({ rows: [] });

      const result = await generateClassMisconceptionReport(1);

      assert.strictEqual(result.exerciseId, 1);
      assert.strictEqual(result.totalStudents, 0);
      assert.strictEqual(result.mostCommonIssue, null);
      assert.strictEqual(result.affectedCount, 0);
      assert.strictEqual(result.affectedPercent, 0);
      assert.strictEqual(result.secondIssue, null);
      assert.strictEqual(result.secondCount, 0);
      assert.strictEqual(result.classSummary, 'No submissions found for this exercise.');
      assert.strictEqual(result.rootCause, 'Insufficient data');
      assert.strictEqual(result.recommendedAction, 'Wait for more student submissions.');
      assert.strictEqual(result.beforeAdvancing, 'Ensure students have attempted the exercise.');
    });

    it('should detect and report the most common issue when submissions exist', async function() {
      // Mock exercise exists
      db.query.mockResolvedValueOnce({ rows: [{ id: 1, title: 'Test Exercise', concept_name: 'Variables', ast_nodes: '[]' }] });
      // Mock submissions: two students, both with the same issue (undeclared variable)
      db.query.mockResolvedValueOnce({ rows: [
        { student_id: 1, attempt_number: 1, code: 'int x = 5; y = x + 10;', test_results: '[]', compiler_log: "error: 'y' was not declared in this scope" },
        { student_id: 2, attempt_number: 1, code: 'int a = 5; b = a + 10;', test_results: '[]', compiler_log: "error: 'b' was not declared in this scope" }
      ] });

      // Mock microConceptEngine feedback for each submission
      // For the first submission
      microConceptEngine.getMicroConceptFeedback.mockResolvedValueOnce({
        hasFeedback: true,
        detectedCount: 1,
        issues: [{ id: 'var_undeclared', name: 'Undeclared Variable', description: 'Variable used without declaration' }],
        instructorNotes: ['Remind students to declare variables before use.'],
        studentMessages: ['You used a variable without declaring it.'],
        evidence: ["error: 'y' was not declared in this scope"],
        summary: 'One undeclared variable detected.',
        suggestedAction: 'Review variable declaration.'
      });
      // For the second submission
      microConceptEngine.getMicroConceptFeedback.mockResolvedValueOnce({
        hasFeedback: true,
        detectedCount: 1,
        issues: [{ id: 'var_undeclared', name: 'Undeclared Variable', description: 'Variable used without declaration' }],
        instructorNotes: ['Remind students to declare variables before use.'],
        studentMessages: ['You used a variable without declaring it.'],
        evidence: ["error: 'b' was not declared in this scope"],
        summary: 'One undeclared variable detected.',
        suggestedAction: 'Review variable declaration.'
      });

      const result = await generateClassMisconceptionReport(1);

      assert.strictEqual(result.exerciseId, 1);
      assert.strictEqual(result.totalStudents, 2);
      assert.strictEqual(result.mostCommonIssue.id, 'var_undeclared');
      assert.strictEqual(result.mostCommonIssue.name, 'Undeclared Variable');
      assert.strictEqual(result.mostCommonIssue.description, 'Variable used without declaration');
      assert.strictEqual(result.affectedCount, 2);
      assert.strictEqual(result.affectedPercent, 100);
      assert.strictEqual(result.secondIssue, null);
      assert.strictEqual(result.secondCount, 0);
      // Check that the summary mentions the issue
      assert.ok(result.classSummary.includes('2 out of 2 students'));
      assert.ok(result.classSummary.includes('Undeclared Variable'));
      // Check root cause and recommended action are generated
      assert.ok(result.rootCause.length > 0);
      assert.ok(result.recommendedAction.length > 0);
      assert.ok(result.beforeAdvancing.length > 0);
    });

    it('should handle AST parsing errors gracefully', async function() {
      // Mock exercise exists
      db.query.mockResolvedValueOnce({ rows: [{ id: 1, title: 'Test Exercise', concept_name: 'Variables', ast_nodes: '[]' }] });
      // Mock submissions: one student with code that might cause AST parsing issues (but we'll mock the engine to return no feedback)
      db.query.mockResolvedValueOnce({ rows: [
        { student_id: 1, attempt_number: 1, code: 'invalid code @#$%', test_results: '[]', compiler_log: '' }
      ] });

      // Mock microConceptEngine feedback for the submission (no feedback)
      microConceptEngine.getMicroConceptFeedback.mockResolvedValueOnce({
        hasFeedback: false,
        detectedCount: 0,
        issues: [],
        instructorNotes: [],
        studentMessages: [],
        evidence: [],
        summary: 'No specific micro-concept issues detected',
        suggestedAction: 'Continue with good practices.'
      });

      const result = await generateClassMisconceptionReport(1);

      assert.strictEqual(result.exerciseId, 1);
      assert.strictEqual(result.totalStudents, 1);
      assert.strictEqual(result.mostCommonIssue, null);
      assert.strictEqual(result.affectedCount, 0);
      assert.strictEqual(result.affectedPercent, 0);
      assert.strictEqual(result.secondIssue, null);
      assert.strictEqual(result.secondCount, 0);
      assert.strictEqual(result.classSummary, 'No significant misconceptions detected among the 1 students who submitted this exercise.');
      assert.strictEqual(result.rootCause, 'Students demonstrated adequate understanding of the core concepts.');
      assert.strictEqual(result.recommendedAction, 'Continue to the next concept or provide enrichment activities for advanced students.');
      assert.strictEqual(result.beforeAdvancing, 'Monitor for any emerging issues in the next exercise.');
    });
  });
});

console.log('Class Misconception Report test suite created');