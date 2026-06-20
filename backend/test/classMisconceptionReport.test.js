/**
 * Class Misconception Report Test Suite
 * Tests for the class misconception report service
 */

const assert = require('assert');

// We need to mock the modules before requiring the service
const mockDbQuery = jest.fn();
jest.mock('../config/db', () => ({
  query: (...args) => mockDbQuery(...args)
}));
jest.mock('../services/microConceptEngine.js', () => ({
  getMicroConceptFeedback: jest.fn()
}));

// Get the mocked modules
const db = require('../config/db');
const microConceptEngine = require('../services/microConceptEngine.js');

const { generateClassMisconceptionReport } = require('../services/classMisconceptionReport');

// Helper: default mock for run_attempts queries (always return empty)
function mockRunAttemptsEmpty(count = 1) {
  for (let i = 0; i < count; i++) {
    mockDbQuery.mockResolvedValueOnce({ rows: [] });
  }
}

describe('Class Misconception Report Test Suite', function() {
  // Reset mocks before each test
  beforeEach(() => {
    mockDbQuery.mockClear();
    microConceptEngine.getMicroConceptFeedback.mockClear();
  });

  describe('generateClassMisconceptionReport', function() {
    it('should return a report with zero students when no submissions exist', async function() {
      // Mock exercise exists
      mockDbQuery.mockResolvedValueOnce({ rows: [{ id: 1, title: 'Test Exercise', concept_name: 'Variables', ast_nodes: '[]' }] });
      // Mock no submissions
      mockDbQuery.mockResolvedValueOnce({ rows: [] });

      const result = await generateClassMisconceptionReport(1);

      assert.strictEqual(result.exerciseId, 1);
      assert.strictEqual(result.totalStudents, 0);
      assert.strictEqual(result.mostCommonIssue, null);
      assert.strictEqual(result.affectedCount, 0);
      assert.strictEqual(result.affectedPercent, 0);
      assert.strictEqual(result.secondIssue, null);
      assert.strictEqual(result.secondCount, 0);
      assert.deepStrictEqual(result.commonErrors, []);
      assert.strictEqual(result.classSummary, 'No submissions found for this exercise.');
      assert.strictEqual(result.recommendedAction, 'Wait for more student submissions.');
    });

    it('should detect and report the most common issue when submissions exist', async function() {
      // Mock exercise exists
      mockDbQuery.mockResolvedValueOnce({ rows: [{ id: 1, title: 'Test Exercise', concept_name: 'Variables', ast_nodes: '[]' }] });
      // Mock submissions: two students, both with the same issue (undeclared variable)
      mockDbQuery.mockResolvedValueOnce({ rows: [
        { student_id: 1, attempt_number: 1, code: 'int x = 5; y = x + 10;', test_results: '[]', compiler_log: "[Line 5:10] ERROR: 'y' was not declared in this scope", time_limit_hit: false },
        { student_id: 2, attempt_number: 1, code: 'int a = 5; b = a + 10;', test_results: '[]', compiler_log: "[Line 5:10] ERROR: 'b' was not declared in this scope", time_limit_hit: false }
      ] });
      // Mock run_attempts queries (one per student)
      mockRunAttemptsEmpty(2);

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
      // Verify commonErrors includes the undeclared pattern
      assert.ok(result.commonErrors.length >= 1);
      assert.ok(result.commonErrors.some(e => e.normalized.includes("was not declared")));
      assert.strictEqual(result.commonErrors[0].count, 2);
      assert.strictEqual(result.commonErrors[0].affectedPercent, 100);
      // Summary references the raw common error (data-driven, not taxonomy name)
      assert.ok(result.classSummary.includes('of 2 students'));
      assert.ok(result.classSummary.includes('undeclared'));
      // Combined recommendedAction includes the error details
      assert.ok(result.recommendedAction.includes('undeclared identifier'));
      assert.ok(result.recommendedAction.includes('2 students'));
    });

    it('should handle AST parsing errors gracefully', async function() {
      // Mock exercise exists
      mockDbQuery.mockResolvedValueOnce({ rows: [{ id: 1, title: 'Test Exercise', concept_name: 'Variables', ast_nodes: '[]' }] });
      // Mock submissions: one student with code that might cause AST parsing issues (but we'll mock the engine to return no feedback)
      mockDbQuery.mockResolvedValueOnce({ rows: [
        { student_id: 1, attempt_number: 1, code: 'invalid code @#$%', test_results: '[]', compiler_log: '', time_limit_hit: false }
      ] });
      // Mock run_attempts query for the student
      mockRunAttemptsEmpty(1);

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
      assert.deepStrictEqual(result.commonErrors, []);
      assert.strictEqual(result.classSummary, 'No significant issues detected among 1 students.');
      assert.strictEqual(result.recommendedAction, 'No issues found. Proceed to next concept or provide enrichment activities.');
    });

    describe('commonErrors - raw compiler error aggregation', function() {
      it('should filter out std namespace errors (cout, cin, string, etc.)', async function() {
        mockDbQuery.mockResolvedValueOnce({ rows: [{ id: 2, title: 'IO Exercise', concept_name: 'I/O', ast_nodes: '[]' }] });
        mockDbQuery.mockResolvedValueOnce({ rows: [
          { student_id: 1, attempt_number: 1, code: '#include <iostream> int main(){cout << "hi";}', test_results: '[]', compiler_log: "[Line 1:30] ERROR: 'cout' was not declared in this scope", time_limit_hit: false },
          { student_id: 2, attempt_number: 1, code: '#include <iostream> int main(){cin >> x;}', test_results: '[]', compiler_log: "[Line 1:30] ERROR: 'cin' was not declared in this scope", time_limit_hit: false },
          { student_id: 3, attempt_number: 1, code: '#include <string> string s;', test_results: '[]', compiler_log: "[Line 1:15] ERROR: 'string' does not name a type", time_limit_hit: false },
        ] });
        mockRunAttemptsEmpty(3);
        for (let i = 0; i < 3; i++) {
          microConceptEngine.getMicroConceptFeedback.mockResolvedValueOnce({
            hasFeedback: false, detectedCount: 0, issues: [],
            instructorNotes: [], studentMessages: [], evidence: [],
            summary: 'No issues', suggestedAction: ''
          });
        }
        const result = await generateClassMisconceptionReport(2);
        assert.deepStrictEqual(result.commonErrors, []);
        assert.strictEqual(result.classSummary.includes('No significant issues'), true);
      });

      it('should group similar errors across students and rank by frequency', async function() {
        mockDbQuery.mockResolvedValueOnce({ rows: [{ id: 3, title: 'Syntax', concept_name: 'Basics', ast_nodes: '[]' }] });
        mockDbQuery.mockResolvedValueOnce({ rows: [
          { student_id: 1, attempt_number: 1, code: 'int x', test_results: '[]', compiler_log: "[Line 1:6] ERROR: expected ';' before 'x' token", time_limit_hit: false },
          { student_id: 2, attempt_number: 1, code: 'int y', test_results: '[]', compiler_log: "[Line 1:6] ERROR: expected ';' before 'y' token", time_limit_hit: false },
          { student_id: 3, attempt_number: 1, code: 'int z', test_results: '[]', compiler_log: "[Line 5:1] ERROR: expected '}' at end of input", time_limit_hit: false },
        ] });
        mockRunAttemptsEmpty(3);
        for (let i = 0; i < 3; i++) {
          microConceptEngine.getMicroConceptFeedback.mockResolvedValueOnce({
            hasFeedback: false, detectedCount: 0, issues: [],
            instructorNotes: [], studentMessages: [], evidence: [],
            summary: 'No issues', suggestedAction: ''
          });
        }
        const result = await generateClassMisconceptionReport(3);
        assert.strictEqual(result.commonErrors.length, 2);
        assert.strictEqual(result.commonErrors[0].count, 2);
        assert.strictEqual(result.commonErrors[0].friendly.includes('Missing semicolon'), true);
        assert.strictEqual(result.commonErrors[0].affectedPercent, 66.7);
        assert.strictEqual(result.commonErrors[1].count, 1);
        assert.strictEqual(result.commonErrors[1].friendly.includes('Missing closing brace'), true);
        assert.strictEqual(result.commonErrors[1].affectedPercent, 33.3);
      });

      it('should only include top 3 common errors', async function() {
        mockDbQuery.mockResolvedValueOnce({ rows: [{ id: 4, title: 'Many Errors', concept_name: 'Basics', ast_nodes: '[]' }] });
        mockDbQuery.mockResolvedValueOnce({ rows: [
          { student_id: 1, attempt_number: 1, code: 'a', test_results: '[]', compiler_log: "[Line 1:1] ERROR: expected ';' before 'a' token", time_limit_hit: false },
          { student_id: 2, attempt_number: 1, code: 'b', test_results: '[]', compiler_log: "[Line 1:1] ERROR: 'b' was not declared in this scope", time_limit_hit: false },
          { student_id: 3, attempt_number: 1, code: 'c', test_results: '[]', compiler_log: "[Line 1:1] ERROR: expected '}' at end of input", time_limit_hit: false },
          { student_id: 4, attempt_number: 1, code: 'd', test_results: '[]', compiler_log: "[Line 1:1] ERROR: redefinition of 'd'", time_limit_hit: false },
          { student_id: 5, attempt_number: 1, code: 'e', test_results: '[]', compiler_log: "[Line 1:1] ERROR: 'e' does not name a type", time_limit_hit: false },
        ] });
        mockRunAttemptsEmpty(5);
        for (let i = 0; i < 5; i++) {
          microConceptEngine.getMicroConceptFeedback.mockResolvedValueOnce({
            hasFeedback: false, detectedCount: 0, issues: [],
            instructorNotes: [], studentMessages: [], evidence: [],
            summary: 'No issues', suggestedAction: ''
          });
        }
        const result = await generateClassMisconceptionReport(4);
        assert.strictEqual(result.commonErrors.length, 3);
      });

      it('should adapt narrative when common errors exist but no taxonomy issues', async function() {
        mockDbQuery.mockResolvedValueOnce({ rows: [{ id: 5, title: 'Missing Semicolons', concept_name: 'Basics', ast_nodes: '[]' }] });
        mockDbQuery.mockResolvedValueOnce({ rows: [
          { student_id: 1, attempt_number: 1, code: 'int x', test_results: '[]', compiler_log: "[Line 1:6] ERROR: expected ';' before end of line", time_limit_hit: false },
          { student_id: 2, attempt_number: 1, code: 'int y', test_results: '[]', compiler_log: "[Line 1:6] ERROR: expected ';' before end of line", time_limit_hit: false },
        ] });
        mockRunAttemptsEmpty(2);
        for (let i = 0; i < 2; i++) {
          microConceptEngine.getMicroConceptFeedback.mockResolvedValueOnce({
            hasFeedback: false, detectedCount: 0, issues: [],
            instructorNotes: [], studentMessages: [], evidence: [],
            summary: 'No issues', suggestedAction: ''
          });
        }
        const result = await generateClassMisconceptionReport(5);
        assert.ok(result.classSummary.includes('of 2 students'));
        assert.ok(result.recommendedAction.includes('Most frequent'));
        assert.ok(result.recommendedAction.includes('Practice resolving'));
      });

      it('should include both taxonomy issues and common errors in same report', async function() {
        mockDbQuery.mockResolvedValueOnce({ rows: [{ id: 6, title: 'Mixed', concept_name: 'Basics', ast_nodes: '[]' }] });
        mockDbQuery.mockResolvedValueOnce({ rows: [
          { student_id: 1, attempt_number: 1, code: 'int x; y = 5;', test_results: '[]', compiler_log: "[Line 1:12] ERROR: 'y' was not declared in this scope\n[Line 1:8] ERROR: expected ';' before 'y'", time_limit_hit: false },
          { student_id: 2, attempt_number: 1, code: 'int a; b = 5;', test_results: '[]', compiler_log: "[Line 1:12] ERROR: 'b' was not declared in this scope\n[Line 1:8] ERROR: expected ';' before 'b'", time_limit_hit: false },
        ] });
        mockRunAttemptsEmpty(2);
        microConceptEngine.getMicroConceptFeedback.mockResolvedValueOnce({
          hasFeedback: true, detectedCount: 1,
          issues: [{ id: 'var_undeclared', name: 'Undeclared Variable', description: 'Variable used without declaration' }],
          instructorNotes: [], studentMessages: [], evidence: [], summary: '', suggestedAction: ''
        });
        microConceptEngine.getMicroConceptFeedback.mockResolvedValueOnce({
          hasFeedback: true, detectedCount: 1,
          issues: [{ id: 'var_undeclared', name: 'Undeclared Variable', description: 'Variable used without declaration' }],
          instructorNotes: [], studentMessages: [], evidence: [], summary: '', suggestedAction: ''
        });
        const result = await generateClassMisconceptionReport(6);
        assert.strictEqual(result.mostCommonIssue.id, 'var_undeclared');
        assert.strictEqual(result.affectedCount, 2);
        assert.ok(result.commonErrors.length > 0);
        const semicolon = result.commonErrors.find(e => e.friendly.includes('Missing semicolon'));
        assert.ok(semicolon, 'Missing semicolon should appear in commonErrors');
        assert.strictEqual(semicolon.count, 2);
        const undeclared = result.commonErrors.find(e => e.friendly.includes('undeclared identifier'));
        assert.ok(undeclared, 'Undeclared identifier should appear in commonErrors');
        assert.strictEqual(undeclared.count, 2);
      });

      it('should handle run_attempts errors in addition to submission errors', async function() {
        mockDbQuery.mockResolvedValueOnce({ rows: [{ id: 7, title: 'Run Errors', concept_name: 'Basics', ast_nodes: '[]' }] });
        mockDbQuery.mockResolvedValueOnce({ rows: [
          { student_id: 1, attempt_number: 2, code: 'fixed code', test_results: '[]', compiler_log: '', time_limit_hit: false },
        ] });
        // Run attempts query returns an earlier error
        mockDbQuery.mockResolvedValueOnce({ rows: [
          { compiler_log: "[Line 1:6] ERROR: expected ';' before 'x' token" }
        ] });
        microConceptEngine.getMicroConceptFeedback.mockResolvedValueOnce({
          hasFeedback: false, detectedCount: 0, issues: [],
          instructorNotes: [], studentMessages: [], evidence: [],
          summary: 'No issues', suggestedAction: ''
        });
        const result = await generateClassMisconceptionReport(7);
        assert.strictEqual(result.commonErrors.length, 1);
        assert.strictEqual(result.commonErrors[0].friendly.includes('Missing semicolon'), true);
        assert.strictEqual(result.commonErrors[0].count, 1);
      });
    });
  });
});

console.log('Class Misconception Report test suite created');