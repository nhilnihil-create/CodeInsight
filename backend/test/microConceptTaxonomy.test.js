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

  describe('F1 regression — cond_assignment_vs_comparison regex', function() {
    // Detector path only: empty compilerLog so the fixed regex is what fires.
    const detect = (code) => {
      const submission = {
        code,
        ast_data: { node_types: ['if_statement'], if_count: 1, else_count: 0 }
      };
      const exercise = { concept_name: 'Conditionals', required_ast_nodes: [] };
      return analyzeSubmission(submission, exercise, [], '');
    };

    const hasAssignRule = (result) =>
      result.some(r => r.microConceptId === 'cond_assignment_vs_comparison');

    it('does NOT fire on if (a == b)', function() {
      // cond_missing_else may co-fire (if_count 1, else_count 0) — ignore it.
      assert.strictEqual(hasAssignRule(detect('if (a == b) { cout << a; }')), false);
    });

    it('does NOT fire on if (a != b)', function() {
      assert.strictEqual(hasAssignRule(detect('if (a != b) {...}')), false);
    });

    it('does NOT fire on if (a <= b)', function() {
      assert.strictEqual(hasAssignRule(detect('if (a <= b) {...}')), false);
    });

    it('does NOT fire on if (a >= b)', function() {
      assert.strictEqual(hasAssignRule(detect('if (a >= b) {...}')), false);
    });

    it('fires on if (a = b)', function() {
      assert.strictEqual(hasAssignRule(detect('if (a = b) {...}')), true);
    });

    it('fires on if (a = b == c)', function() {
      assert.strictEqual(hasAssignRule(detect('if (a = b == c) {...}')), true);
    });
  });

  describe('var_comma_operator rule', function() {
    const detect = (code) => {
      const submission = { code, ast_data: { node_types: [] } };
      const exercise = { concept_name: 'Variables', required_ast_nodes: [] };
      return analyzeSubmission(submission, exercise, [], '');
    };

    const hasCommaRule = (result) =>
      result.some(r => r.microConceptId === 'var_comma_operator');

    it('detects comma operator chaining statements', function() {
      const result = detect('int x; x = 5, y = 10; cout << x;');
      assert.strictEqual(hasCommaRule(result), true);
    });

    it('does NOT fire on for-headers', function() {
      const result = detect('for (int i = 0, j = 0; i < n; i++) { }');
      assert.strictEqual(hasCommaRule(result), false);
    });

    it('does NOT fire on function arguments', function() {
      const result = detect('f(a, b);');
      assert.strictEqual(hasCommaRule(result), false);
    });

    it('does NOT fire on declarations', function() {
      const result = detect('int a = 1, b = 2;');
      assert.strictEqual(hasCommaRule(result), false);
    });
  });

  describe('loop_goto_loop rule', function() {
    const detect = (code) => {
      const submission = { code, ast_data: { node_types: [] } };
      const exercise = { concept_name: 'Loops', required_ast_nodes: [] };
      return analyzeSubmission(submission, exercise, [], '');
    };

    const hasGotoRule = (result) =>
      result.some(r => r.microConceptId === 'loop_goto_loop');

    it('detects backward goto (loop emulation)', function() {
      const result = detect('int main() { int a = 0; loop_start: if (a >= 10) goto loop_end; a = a + 1; goto loop_start; loop_end: return 0; }');
      assert.strictEqual(hasGotoRule(result), true);
    });

    it('does NOT fire on forward goto', function() {
      const result = detect('int main() { goto cleanup; cleanup: return 0; }');
      assert.strictEqual(hasGotoRule(result), false);
    });
  });

  describe('sw_duffs_device rule', function() {
    const detect = (code) => {
      const submission = {
        code,
        ast_data: { node_types: ['switch_statement', 'do_statement'] }
      };
      const exercise = { concept_name: 'Switch/Case', required_ast_nodes: [] };
      return analyzeSubmission(submission, exercise, [], '');
    };

    const hasDuffRule = (result) =>
      result.some(r => r.microConceptId === 'sw_duffs_device');

    it("detects Duff's device (canonical snippet)", function() {
      // Canonical Duff's device from fuzzing test 9 in microConceptEdgeCases.test.js.
      const code = [
        'int n = (count + 7) / 8;',
        'switch (count % 8) {',
        '  case 0: do { *to = *from++;',
        '  case 7: *to = *from++;',
        '  case 6: *to = *from++;',
        '  case 5: *to = *from++;',
        '  case 4: *to = *from++;',
        '  case 3: *to = *from++;',
        '  case 2: *to = *from++;',
        '  case 1: *to = *from++;',
        '  } while (--n > 0);',
        '}'
      ].join('\n');
      const result = detect(code);
      assert.strictEqual(hasDuffRule(result), true);
    });

    it('does NOT fire on a plain switch with a do-while inside a case', function() {
      const result = detect('switch (x) { case 1: break; case 2: do { work(); } while (y); break; }');
      assert.strictEqual(hasDuffRule(result), false);
    });
  });
});

console.log('Micro-Concept Taxonomy test suite created');