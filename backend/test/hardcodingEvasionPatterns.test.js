const academicIntegrityEngine = require('../services/academicIntegrityEngine');

const exerciseNoExpected = {
  id: 1,
  starter_code: '#include <iostream>\nusing namespace std;\nint main() {\n  return 0;\n}',
  test_cases: []
};

const exerciseWithExpected = {
  id: 1,
  starter_code: '#include <iostream>\nusing namespace std;\nint main() {\n  return 0;\n}',
  test_cases: [
    { expected: '55' },
    { expected: 'Hello' }
  ]
};

describe('Hardcoding Evasion Patterns — checkHardcoding', () => {
  beforeEach(() => {
    jest.clearAllMocks();
  });

  // Pattern 1: Exact match direct literal output matching expected answer
  describe('Pattern 1 — Exact match (cout << literal)', () => {
    it('detects direct numeric output matching expected answer with no computation', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { cout << 55; return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exerciseWithExpected, {});
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
      expect(flag.severity).toBe('HIGH');
      expect(flag.evidence.computationScore).toBeLessThan(2);
    });

    it('detects direct numeric output even without expected test cases', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { cout << 42; return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exerciseNoExpected, {});
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
      expect(flag.severity).toBe('HIGH');
    });

    it('detects multiple literal outputs', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { cout << 55; cout << 10; return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exerciseWithExpected, {});
      expect(flag).not.toBeNull();
      expect(flag.evidence.literalOutputCount).toBeGreaterThanOrEqual(2);
    });

    it('does not flag code with proper computation (variables + operations)', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { int sum = 0; for(int i=1; i<=10; i++) sum += i; cout << sum; return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exerciseWithExpected, {});
      expect(flag).toBeNull();
    });
  });

  // Pattern 2: Whitespace/formatting variation around the literal
  describe('Pattern 2 — Whitespace variation', () => {
    it('detects cout with extra whitespace around << operator', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { cout   <<   55   ; return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exerciseWithExpected, {});
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
    });

    it('detects cout with literal on separate line', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { cout\n<<\n55\n; return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exerciseWithExpected, {});
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
    });

    it('detects cout with literal followed by semicolon then another cout', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { cout << 55; cout << endl; return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exerciseWithExpected, {});
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
    });
  });

  // Pattern 3: Comment-only additions around hardcoded output
  describe('Pattern 3 — Comment-only additions', () => {
    it('detects cout with literal and trailing comment', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { cout << 55; // sum of 1 to 10\n return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exerciseWithExpected, {});
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
    });

    it('detects cout with literal and leading comment line', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { // compute sum\n cout << 55; return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exerciseWithExpected, {});
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
    });
  });

  // Pattern 4: Variable renaming while still hardcoding
  // NOTE: The current implementation checks for `cout << literal` directly.
  // Variable-based output (int x = 55; cout << x) is NOT flagged because
  // the regex requires a numeric literal after `<<`. This is a known blind spot.
  describe('Pattern 4 — Rename-only evasion (blind spot)', () => {
    it('does not flag variable-initialized output (regex blind spot)', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { int x = 55; cout << x; return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exerciseWithExpected, {});
      expect(flag).toBeNull();
    });
  });

  // Pattern 5: Computation with literal (ambiguous: loops but no variables)
  describe('Pattern 5 — Computation-like with literal output', () => {
    it('detects ambiguous hardcoding with loop but no variables', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { for(;;) cout << 55; return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exerciseWithExpected, {});
      expect(flag).not.toBeNull();
      expect(flag.severity).toBe('MEDIUM');
    });

    it('returns null for code with both variables and loops (legitimate)', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { int n = 10; int sum = 0; for(int i=1; i<=n; i++) sum += i; cout << sum; return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exerciseWithExpected, {});
      expect(flag).toBeNull();
    });

    it('returns null for arithmetic expression output', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { cout << 1+2+3+4+5+6+7+8+9+10; return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exerciseWithExpected, {});
      expect(flag).toBeNull();
    });

    it('returns null for computation with multiple variables', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { int a = 10, b = 20; int c = a + b; cout << c; return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exerciseNoExpected, {});
      expect(flag).toBeNull();
    });
  });

  describe('Edge cases', () => {
    it('does not crash on empty code', () => {
      const flag = academicIntegrityEngine.checkHardcoding('', exerciseNoExpected, {});
      expect(flag).toBeNull();
    });

    it('does not crash on malformed code', () => {
      const flag = academicIntegrityEngine.checkHardcoding('{{{', exerciseNoExpected, {});
      expect(flag).toBeNull();
    });

    it('does not flag code with no numeric output', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { cout << "hello"; return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exerciseNoExpected, {});
      expect(flag).toBeNull();
    });
  });
});
