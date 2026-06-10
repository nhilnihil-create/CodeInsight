// Stream Matcher Tests
// Tests for token-based output grading + structured validation.
// streamMatcher.js has ZERO existing tests — all written fresh.

const assert = require('assert');
const { tokenize, validateOutput, gradeSubmission } = require('../services/streamMatcher');

// ── Tokenizer Tests ──────────────────────────────────────────────────────────

describe('streamMatcher — tokenize', function() {
  it('splits on whitespace', function() {
    const tokens = tokenize('hello world');
    assert.deepStrictEqual(tokens, ['hello', 'world']);
  });

  it('collapses multiple spaces', function() {
    const tokens = tokenize('hello    world');
    assert.deepStrictEqual(tokens, ['hello', 'world']);
  });

  it('strips carriage returns', function() {
    const tokens = tokenize('hello\r\nworld');
    assert.deepStrictEqual(tokens, ['hello', 'world']);
  });

  it('trims leading/trailing whitespace', function() {
    const tokens = tokenize('  hello  ');
    assert.deepStrictEqual(tokens, ['hello']);
  });

  it('lowercases everything', function() {
    const tokens = tokenize('Hello WORLD');
    assert.deepStrictEqual(tokens, ['hello', 'world']);
  });

  it('returns empty array for empty string', function() {
    const tokens = tokenize('');
    assert.deepStrictEqual(tokens, []);
  });

  it('returns empty array for whitespace-only string', function() {
    const tokens = tokenize('   \t\n  ');
    assert.deepStrictEqual(tokens, []);
  });

  it('handles null input (null ?? "" → empty → [])', function() {
    const tokens = tokenize(null);
    assert.deepStrictEqual(tokens, []);
  });

  it('handles undefined input (undefined ?? "" → empty → [])', function() {
    const tokens = tokenize(undefined);
    assert.deepStrictEqual(tokens, []);
  });

  it('handles numeric input (coerced to string)', function() {
    const tokens = tokenize(42);
    assert.deepStrictEqual(tokens, ['42']);
  });

  it('handles multi-line output', function() {
    const tokens = tokenize('Line 1\nLine 2\nLine 3');
    assert.deepStrictEqual(tokens, ['line', '1', 'line', '2', 'line', '3']);
  });

  it('handles trailing newline', function() {
    const tokens = tokenize('hello\n');
    assert.deepStrictEqual(tokens, ['hello']);
  });
});

// ── validateOutput — Exact Mode ──────────────────────────────────────────────

describe('validateOutput — exact mode', function() {
  it('passes when tokens match exactly', function() {
    const result = validateOutput('hello world', 'hello world', 'exact');
    assert.strictEqual(result.passed, true);
    assert.strictEqual(result.reason, null);
  });

  it('passes when whitespace differs (tokens same)', function() {
    const result = validateOutput('hello   world', 'hello world', 'exact');
    assert.strictEqual(result.passed, true);
  });

  it('passes when case differs (lowercased)', function() {
    const result = validateOutput('Hello WORLD', 'hello world', 'exact');
    assert.strictEqual(result.passed, true);
  });

  it('fails when token count differs', function() {
    const result = validateOutput('hello world', 'hello', 'exact');
    assert.strictEqual(result.passed, false);
    assert.ok(result.reason.includes('Length mismatch'));
  });

  it('fails when token value differs', function() {
    const result = validateOutput('hello world', 'hello there', 'exact');
    assert.strictEqual(result.passed, false);
    assert.ok(result.reason.includes('Token mismatch'));
    assert.strictEqual(result.divergenceIndex, 1);
  });

  it('reports divergence index on first mismatch', function() {
    const result = validateOutput('a b c d', 'a b x d', 'exact');
    assert.strictEqual(result.divergenceIndex, 2);
  });

  it('passes with both empty', function() {
    const result = validateOutput('', '', 'exact');
    assert.strictEqual(result.passed, true);
  });

  it('fails when actual is empty but expected is not', function() {
    const result = validateOutput('', 'hello', 'exact');
    assert.strictEqual(result.passed, false);
  });

  it('fails when expected is empty but actual is not', function() {
    const result = validateOutput('hello', '', 'exact');
    assert.strictEqual(result.passed, false);
  });
});

// ── validateOutput — Contains Mode ───────────────────────────────────────────

describe('validateOutput — contains mode', function() {
  it('passes when expected is substring of actual', function() {
    const result = validateOutput('the answer is 42', '42', 'contains');
    assert.strictEqual(result.passed, true);
  });

  it('passes when expected equals actual', function() {
    const result = validateOutput('hello world', 'hello world', 'contains');
    assert.strictEqual(result.passed, true);
  });

  it('fails when expected is not in actual', function() {
    const result = validateOutput('hello world', 'goodbye', 'contains');
    assert.strictEqual(result.passed, false);
  });

  it('passes when expected is empty', function() {
    const result = validateOutput('anything', '', 'contains');
    assert.strictEqual(result.passed, true);
  });

  it('is case-insensitive', function() {
    const result = validateOutput('The Answer Is 42', 'answer', 'contains');
    assert.strictEqual(result.passed, true);
  });

  it('matches token sequence, not substring', function() {
    // 'is 42' as tokens should match within 'the answer is 42'
    const result = validateOutput('the answer is 42', 'is 42', 'contains');
    assert.strictEqual(result.passed, true);
  });

  it('fails when tokens are in wrong order', function() {
    const result = validateOutput('hello world', 'world hello', 'contains');
    assert.strictEqual(result.passed, false);
  });
});

// ── validateOutput — Regex Mode ──────────────────────────────────────────────

describe('validateOutput — regex mode', function() {
  it('passes when output matches pattern', function() {
    const result = validateOutput('42', '^\\d+$', 'regex');
    assert.strictEqual(result.passed, true);
  });

  it('fails when output does not match pattern', function() {
    const result = validateOutput('abc', '^\\d+$', 'regex');
    assert.strictEqual(result.passed, false);
  });

  it('handles invalid regex gracefully', function() {
    const result = validateOutput('anything', '[invalid', 'regex');
    assert.strictEqual(result.passed, false);
    assert.ok(result.reason.includes('Invalid regex'));
  });

  it('is case-insensitive by default', function() {
    const result = validateOutput('HELLO', 'hello', 'regex');
    assert.strictEqual(result.passed, true);
  });

  it('matches partial output', function() {
    const result = validateOutput('Result: 42', '42', 'regex');
    assert.strictEqual(result.passed, true);
  });

  it('supports complex patterns', function() {
    const result = validateOutput('Sum: 10', 'Sum:\\s*\\d+', 'regex');
    assert.strictEqual(result.passed, true);
  });
});

// ── Default Mode (exact) ─────────────────────────────────────────────────────

describe('validateOutput — default mode', function() {
  it('defaults to exact when no type specified', function() {
    const result = validateOutput('hello world', 'hello world');
    assert.strictEqual(result.passed, true);
  });

  it('fails like exact mode by default', function() {
    const result = validateOutput('hello world', 'hello');
    assert.strictEqual(result.passed, false);
  });
});

// ── gradeSubmission (legacy wrapper) ─────────────────────────────────────────

describe('gradeSubmission — legacy wrapper', function() {
  it('delegates to exact comparison', function() {
    const result = gradeSubmission('hello world', 'hello world');
    assert.strictEqual(result.passed, true);
    assert.strictEqual(result.divergenceIndex, null);
  });

  it('reports divergence on mismatch', function() {
    const result = gradeSubmission('a b c', 'a x c');
    assert.strictEqual(result.passed, false);
    assert.strictEqual(result.divergenceIndex, 1);
  });

  it('returns empty token arrays for empty input', function() {
    const result = gradeSubmission('', '');
    assert.strictEqual(result.passed, true);
  });
});

// ── Edge Cases: Real C++ Output Scenarios ────────────────────────────────────

describe('streamMatcher — Real C++ Output Scenarios', function() {
  it('handles trailing newline from cout', function() {
    // C++: cout << "Hello" << endl; produces "Hello\n"
    const result = validateOutput('Hello\n', 'hello', 'exact');
    assert.strictEqual(result.passed, true);
  });

  it('handles multiple lines of output', function() {
    const result = validateOutput('1\n2\n3\n', '1 2 3', 'exact');
    assert.strictEqual(result.passed, true);
  });

  it('detects off-by-one error in numeric output', function() {
    const result = validateOutput('Sum: 10', 'Sum: 11', 'exact');
    assert.strictEqual(result.passed, false);
    assert.strictEqual(result.divergenceIndex, 1);
  });

  it('handles extra spaces between values', function() {
    const result = validateOutput('1  2  3', '1 2 3', 'exact');
    assert.strictEqual(result.passed, true);
  });

  it('contains mode for "substring in output" checking', function() {
    // Student outputs "Result: 42 (correct)" — we only care about 42
    const result = validateOutput('Result: 42 (correct)', '42', 'contains');
    assert.strictEqual(result.passed, true);
  });

  it('regex mode for flexible output matching', function() {
    // Accept "Sum: 42" or "Sum = 42" or "42"
    const result = validateOutput('Sum = 42', 'Sum[:\\s=]*\\d+', 'regex');
    assert.strictEqual(result.passed, true);
  });
});

// ── Return Structure Verification ────────────────────────────────────────────

describe('validateOutput — Return Structure', function() {
  it('returns all expected fields on success', function() {
    const result = validateOutput('hello', 'hello', 'exact');
    assert.ok('passed' in result);
    assert.ok('divergenceIndex' in result);
    assert.ok('actualTokens' in result);
    assert.ok('expectedTokens' in result);
    assert.ok('reason' in result);
  });

  it('returns all expected fields on failure', function() {
    const result = validateOutput('hello', 'world', 'exact');
    assert.ok('passed' in result);
    assert.ok('divergenceIndex' in result);
    assert.ok('actualTokens' in result);
    assert.ok('expectedTokens' in result);
    assert.ok('reason' in result);
    assert.ok(result.reason !== null);
  });

  it('actualTokens are tokenized actual output', function() {
    const result = validateOutput('Hello World', 'hello world', 'exact');
    assert.deepStrictEqual(result.actualTokens, ['hello', 'world']);
  });

  it('expectedTokens are tokenized expected output', function() {
    const result = validateOutput('Hello World', 'hello world', 'exact');
    assert.deepStrictEqual(result.expectedTokens, ['hello', 'world']);
  });
});

console.log('Stream Matcher test suite loaded — all assertions are active.');
