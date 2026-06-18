/**
 * Micro-Concept Taxonomy Test Suite
 * Tests for the micro-concept taxonomy service
 */

const assert = require('assert');
const { MICRO_CONCEPT_RULES, analyzeSubmission, extractEvidence } = require('../services/microConceptTaxonomy.js');

describe('Micro-Concept Taxonomy Test Suite', function() {

  describe('MICRO_CONCEPT_RULES Structure', function() {
    it('should be an object', function() {
      assert.strictEqual(typeof MICRO_CONCEPT_RULES, 'object');
      assert.notStrictEqual(MICRO_CONCEPT_RULES, null);
    });

    it('should have all 25 concepts', function() {
      const expectedConcepts = [
        'Datatypes',
        'Variables',
        'Conditionals',
        'Loops',
        'Functions',
        'Arrays',
        'OOP',
        'Pointers',
        'Strings',
        'Input/Output',
        'Switch/Case',
        'Nested Loops',
        'Recursion',
        'File I/O',
        'Scope',
        'Enums',
        'Structs',
        'Dynamic Memory',
        'Linked Lists',
        'Error Handling',
        'Type Casting',
        'Preprocessor',
        'Namespaces',
        'Inheritance',
        'Polymorphism'
      ];

      expectedConcepts.forEach(concept => {
        assert.ok(MICRO_CONCEPT_RULES.hasOwnProperty(concept), `Missing concept: ${concept}`);
        assert.ok(Array.isArray(MICRO_CONCEPT_RULES[concept]), `Rules for ${concept} should be an array`);
        assert.ok(MICRO_CONCEPT_RULES[concept].length > 0, `Concept ${concept} should have at least one rule`);
      });
    });

    it('should have rules with required properties', function() {
      Object.keys(MICRO_CONCEPT_RULES).forEach(concept => {
        const rules = MICRO_CONCEPT_RULES[concept];
        rules.forEach(rule => {
          assert.ok(rule.id, `Rule missing id in ${concept}`);
          assert.ok(rule.name, `Rule missing name in ${concept}`);
          assert.ok(rule.description, `Rule missing description in ${concept}`);
          assert.ok(typeof rule.detector === 'function', `Rule detector must be a function in ${concept}`);
          // instructorMessage and studentMessage are optional but if present should be string
          if (rule.instructorMessage) {
            assert.strictEqual(typeof rule.instructorMessage, 'string');
          }
          if (rule.studentMessage) {
            assert.strictEqual(typeof rule.studentMessage, 'string');
          }
          // evidenceExtractor is optional but if present should be function
          if (rule.evidenceExtractor) {
            assert.strictEqual(typeof rule.evidenceExtractor, 'function');
          }
        });
      });
    });
  });

  describe('analyzeSubmission function', function() {
    it('should return empty array for no matches', function() {
      const submission = { code: 'int main() { return 0; }', ast_data: { node_types: [] } };
      const exercise = { concept_name: 'Variables', required_ast_nodes: [] };
      const testResults = [];
      const compilerLog = '';

      const result = analyzeSubmission(submission, exercise, testResults, compilerLog);
      assert.ok(Array.isArray(result));
      assert.strictEqual(result.length, 0);
    });

    it('should detect undeclared variable', function() {
      const submission = { code: 'int x = 5; y = x + 10;', ast_data: { node_types: [] } };
      const exercise = { concept_name: 'Variables', required_ast_nodes: [] };
      const testResults = [];
      const compilerLog = "error: 'y' was not declared in this scope";

      const result = analyzeSubmission(submission, exercise, testResults, compilerLog);
      assert.ok(Array.isArray(result));
      assert.strictEqual(result.length, 1);
      assert.strictEqual(result[0].microConceptId, 'var_undeclared');
    });

    it('should detect multiple issues', function() {
      const submission = {
        code: 'if (x = 5) { cout << x << endl; }',
        ast_data: {
          node_types: ['if_statement'],
          if_count: 1,
          else_count: 0
        }
      };
      const exercise = { concept_name: 'Conditionals', required_ast_nodes: ['if_statement'] };
      const testResults = [];
      const compilerLog = "error: lvalue required as left operand of assignment";

      const result = analyzeSubmission(submission, exercise, testResults, compilerLog);
      assert.ok(Array.isArray(result));
      // Should detect at least assignment in conditional and missing else
      assert.ok(result.length >= 1);
      // Check for assignment rule
      const assignmentRule = result.find(r => r.microConceptId === 'cond_assignment_vs_comparison');
      assert.ok(assignmentRule, 'Should detect assignment in conditional');
    });
  });

  describe('extractEvidence function', function() {
    it('should extract evidence from compiler errors', function() {
      const rule = {
        id: 'test_rule',
        evidenceExtractor: (context) => {
          const errorLine = context.compilerErrors.find(e => e.includes('test'));
          return errorLine ? `Compiler: ${errorLine}` : 'No test error';
        }
      };
      const context = {
        compilerErrors: ['error: test error', 'warning: something else']
      };

      const evidence = extractEvidence(rule, context);
      assert.strictEqual(evidence, 'Compiler: error: test error');
    });

    it('should handle missing evidenceExtractor', function() {
      const rule = { id: 'test_rule' };
      const context = {};

      const evidence = extractEvidence(rule, context);
      assert.strictEqual(evidence, 'Deterministic rule matched');
    });

    it('should handle evidenceExtractor throwing error', function() {
      const rule = {
        id: 'test_rule',
        evidenceExtractor: () => { throw new Error('Extractor failed'); }
      };
      const context = {};

      const evidence = extractEvidence(rule, context);
      assert.strictEqual(evidence, 'Pattern detected');
    });
  });
});

console.log('Micro-Concept Taxonomy test suite created');