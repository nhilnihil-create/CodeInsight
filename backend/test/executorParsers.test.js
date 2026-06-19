/**
 * Tests for executor.js parser functions (pure logic, no Docker dependency).
 * These tests only cover parseCompilerError, parseSanitizerOutput, and isSafe.
 */

const { isSafe } = require('../services/executor');

describe('executor — isSafe (static analysis)', function() {
  it('blocks system() call', function() {
    expect(isSafe('system("ls")')).toBe(false);
  });

  it('blocks exec() call', function() {
    expect(isSafe('exec("rm -rf /")')).toBe(false);
  });

  it('blocks fork() call', function() {
    expect(isSafe('fork()')).toBe(false);
  });

  it('blocks popen() call', function() {
    expect(isSafe('popen("cat /etc/passwd")')).toBe(false);
  });

  it('allows safe code', function() {
    expect(isSafe('int main() { return 0; }')).toBe(true);
  });

  it('allows safe code with function named execute (not exec)', function() {
    expect(isSafe('void execute() { return; }')).toBe(true);
  });

  it('ignores blocked keywords inside comments (single-line)', function() {
    const code = 'int main() {\n  // system("dangerous")\n  return 0;\n}';
    expect(isSafe(code)).toBe(true);
  });

  it('ignores blocked keywords inside block comments', function() {
    const code = 'int main() {\n  /* exec("evil") */\n  return 0;\n}';
    expect(isSafe(code)).toBe(true);
  });

  it('blocks mixed safe/unsafe code', function() {
    const code = 'int main() { return 0; }\nvoid hack() { system("ls"); }';
    expect(isSafe(code)).toBe(false);
  });

  it('detects blocked keyword even with whitespace before parenthesis', function() {
    expect(isSafe('fork ()')).toBe(false);
  });

  it('handles empty code', function() {
    expect(isSafe('')).toBe(true);
  });

  it('handles null code (throws or returns true)', function() {
    expect(() => isSafe(null)).not.toThrow();
  });
});

describe('executor — parseSanitizerOutput', function() {
  const { parseSanitizerOutput } = require('../services/executor');

  it('detects heap-buffer-overflow', function() {
    const stderr = '==1==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x...\n' +
      'READ of size 4 at solution.cpp:10';
    const result = parseSanitizerOutput(stderr, '');
    expect(result).toBeTruthy();
    expect(result.status).toBe('Runtime Error');
    expect(result.message).toContain('heap-buffer-overflow');
  });

  it('detects stack-buffer-overflow', function() {
    const stderr = 'AddressSanitizer: stack-buffer-overflow on address 0x...\n' +
      'WRITE of size 4 at solution.cpp:15';
    const result = parseSanitizerOutput(stderr, '');
    expect(result).toBeTruthy();
    expect(result.message).toContain('stack-buffer-overflow');
  });

  it('detects use-after-free', function() {
    const stderr = 'AddressSanitizer: heap-use-after-free on address 0x...\n' +
      'READ of size 8 at solution.cpp:20';
    const result = parseSanitizerOutput(stderr, '');
    expect(result).toBeTruthy();
    expect(result.message).toContain('heap-use-after-free');
  });

  it('detects memory leaks', function() {
    const stderr = 'LeakSanitizer: detected memory leaks\n' +
      'Direct leak of 24 byte(s) in 1 object(s)';
    const result = parseSanitizerOutput(stderr, '');
    expect(result).toBeTruthy();
    expect(result.status).toBe('Success');
    expect(result.message).toContain('LeakSanitizer');
  });

  it('returns null for clean output', function() {
    expect(parseSanitizerOutput('', 'Hello World\n')).toBeNull();
  });

  it('returns null for irrelevant stderr', function() {
    expect(parseSanitizerOutput('some random error', '')).toBeNull();
  });
});

describe('executor — parseCompilerError', function() {
  const { parseCompilerError } = require('../services/executor');

  it('formats a simple compilation error', function() {
    const code = 'int main() {\n  return\n}';
    const errorOutput = 'solution.cpp:2:8: error: expected expression\n' +
      '    2 |   return\n' +
      '      |        ^';
    const result = parseCompilerError(errorOutput, code);
    expect(result).toContain('ERROR');
    expect(result).toContain('Line 2');
  });

  it('returns fallback for empty error output', function() {
    expect(parseCompilerError('', 'int main() {}')).toBe('Compilation failed');
  });

  it('returns fallback for null error output', function() {
    expect(parseCompilerError(null, 'int main() {}')).toBe('Compilation failed');
  });

  it('returns fallback for null source code', function() {
    expect(parseCompilerError('some error', null)).toBe('some error');
  });

  it('formats multiple errors', function() {
    const code = 'int main() {\n  undefined_function();\n  another_undefined();\n}';
    const errorOutput = [
      'solution.cpp:2:3: error: use of undeclared identifier \'undefined_function\'',
      'solution.cpp:3:3: error: use of undeclared identifier \'another_undefined\'',
    ].join('\n');
    const result = parseCompilerError(errorOutput, code);
    expect(result).toContain('undefined_function');
    expect(result).toContain('another_undefined');
  });

  it('includes source code line and column pointer', function() {
    const code = 'int main() { return x }';
    const errorOutput = 'solution.cpp:1:24: error: expected \';\' after expression';
    const result = parseCompilerError(errorOutput, code);
    expect(result).toContain('int main() { return x }');
    expect(result).toContain('^');
  });
});
