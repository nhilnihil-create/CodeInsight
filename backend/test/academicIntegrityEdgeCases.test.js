const academicIntegrityEngine = require('../services/academicIntegrityEngine');

const exercise = {
  id: 1,
  starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}',
  test_cases: []
};

const exerciseWithExpected = {
  id: 1,
  starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}',
  test_cases: [
    { expected: '42' },
    { expected: 'Hello World' }
  ]
};

describe('Academic Integrity Engine — Extended Hardcoding Check', () => {
  beforeEach(() => {
    jest.clearAllMocks();
  });

  describe('checkHardcodingExtended — printf/puts literal', () => {
    it('should detect hardcoding via printf with literal matching expected output', () => {
      const code = '#include <stdio.h>\nint main() { printf("42"); return 0; }';
      const flag = academicIntegrityEngine.checkHardcodingExtended(code, exerciseWithExpected, {});
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
      expect(flag.severity).toBe('HIGH');
      expect(flag.evidence.summary).toContain('printf');
      expect(flag.evidence.pattern).toBe('printf_literal');
    });

    it('should detect hardcoding via puts with literal matching expected output', () => {
      const code = '#include <stdio.h>\nint main() { puts("Hello World"); return 0; }';
      const flag = academicIntegrityEngine.checkHardcodingExtended(code, exerciseWithExpected, {});
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
      expect(flag.evidence.pattern).toBe('printf_literal');
    });
  });

  describe('checkHardcodingExtended — putchar loop', () => {
    it('should detect hardcoding via putchar loop iterating over literal string', () => {
      const code = '#include <stdio.h>\nint main() { char s[] = "Hello World"; for(int i=0; s[i]; i++) putchar(s[i]); return 0; }';
      const flag = academicIntegrityEngine.checkHardcodingExtended(code, exerciseWithExpected, {});
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
      expect(flag.severity).toBe('HIGH');
      expect(flag.evidence.pattern).toBe('putchar_loop');
    });

    it('should detect hardcoding via fputc in loop with string literal', () => {
      const code = '#include <stdio.h>\nint main() { char s[] = "42"; for(int i=0; s[i]; i++) fputc(s[i], stdout); return 0; }';
      const flag = academicIntegrityEngine.checkHardcodingExtended(code, exerciseWithExpected, {});
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
      expect(flag.evidence.pattern).toBe('putchar_loop');
    });
  });

  describe('checkHardcodingExtended — return value evasion', () => {
    it('should detect hardcoding via return value matching expected output', () => {
      const code = '#include <iostream>\nint main() { return 42; }';
      const flag = academicIntegrityEngine.checkHardcodingExtended(code, exerciseWithExpected, {});
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
      expect(flag.evidence.pattern).toBe('return_value');
    });
  });

  describe('checkHardcodingExtended — ostringstream literal', () => {
    it('should detect hardcoding via ostringstream with literal matching expected', () => {
      const code = '#include <iostream>\n#include <sstream>\nint main() { std::ostringstream os; os << "42"; std::cout << os.str(); return 0; }';
      const flag = academicIntegrityEngine.checkHardcodingExtended(code, exerciseWithExpected, {});
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
      expect(flag.severity).toBe('HIGH');
      expect(flag.evidence.pattern).toBe('ostringstream_literal');
    });
  });

  describe('checkHardcodingExtended — string constructor from literal', () => {
    it('should detect hardcoding via std::string constructor from literal', () => {
      const code = '#include <iostream>\n#include <string>\nint main() { std::string s("Hello World"); std::cout << s; return 0; }';
      const flag = academicIntegrityEngine.checkHardcodingExtended(code, exerciseWithExpected, {});
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
      expect(flag.severity).toBe('HIGH');
      expect(flag.evidence.pattern).toBe('string_ctor_literal');
    });

    it('should detect hardcoding via std::string assignment from literal', () => {
      const code = '#include <iostream>\n#include <string>\nint main() { std::string s = "42"; std::cout << s; return 0; }';
      const flag = academicIntegrityEngine.checkHardcodingExtended(code, exerciseWithExpected, {});
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
      expect(flag.evidence.pattern).toBe('string_ctor_literal');
    });
  });

  describe('checkHardcodingExtended — no false positives', () => {
    it('should not flag printf with literal that does not match expected output', () => {
      const code = '#include <stdio.h>\nint main() { printf("unrelated"); return 0; }';
      const flag = academicIntegrityEngine.checkHardcodingExtended(code, exerciseWithExpected, {});
      expect(flag).toBeNull();
    });

    it('should not flag computed return value', () => {
      const code = '#include <iostream>\nint main() { int x = 20 + 22; return x; }';
      const flag = academicIntegrityEngine.checkHardcodingExtended(code, exerciseWithExpected, {});
      expect(flag).toBeNull();
    });
  });
});

describe('Academic Integrity Engine — Blank Template Edge Cases', () => {
  describe('checkBlankTemplate edge cases', () => {
    it('should not flag whitespace-only changes with one newline added', () => {
      const code = exercise.starter_code + '\n';
      const flag = academicIntegrityEngine.checkBlankTemplate(code, exercise.starter_code);
      expect(flag).toBeNull();
    });

    it('should not flag comment-only additions', () => {
      const code = exercise.starter_code + '\n// Student name: John Doe\n';
      const flag = academicIntegrityEngine.checkBlankTemplate(code, exercise.starter_code);
      expect(flag).toBeNull();
    });

    it('should not flag header include reordering', () => {
      const code = '#include <iostream>\n\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}';
      const flag = academicIntegrityEngine.checkBlankTemplate(code, exercise.starter_code);
      expect(flag).toBeNull();
    });

    it('should flag empty submission when starter is non-empty', () => {
      const flag = academicIntegrityEngine.checkBlankTemplate('', exercise.starter_code);
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('BLANK_TEMPLATE');
      expect(flag.severity).toBe('HIGH');
    });
  });
});

describe('Academic Integrity Engine — evaluateIntegrity integration', () => {
  it('should call checkHardcodingExtended from evaluateIntegrity', async () => {
    const code = '#include <stdio.h>\nint main() { printf("42"); return 0; }';
    const flags = await academicIntegrityEngine.evaluateIntegrity({
      code,
      starterCode: exerciseWithExpected.starter_code,
      studentId: 1,
      exerciseId: 1,
      submission: {},
      exercise: exerciseWithExpected,
    });
    const hardcodingFlags = flags.filter(f => f.type === 'HARDCODING');
    expect(hardcodingFlags.length).toBeGreaterThan(0);
  });
});

describe('Hardcoding Evasion — documented gaps', () => {
  it('does not catch cout << 42 << endl chains (basic regex requires literal followed by ; or >)', () => {
    const code = '#include <iostream>\nusing namespace std;\nint main() { cout << 42 << endl; return 0; }';
    const flag = academicIntegrityEngine.checkHardcoding(code, exerciseWithExpected, {});
    expect(flag).toBeNull();
  });

  it('does not catch constexpr literals via extended check', () => {
    const code = '#include <iostream>\nusing namespace std;\nint main() { constexpr int x = 42; cout << x; return 0; }';
    const flag = academicIntegrityEngine.checkHardcodingExtended(code, exerciseWithExpected, {});
    expect(flag).toBeNull();
  });

  it('does not catch macro literals via extended check', () => {
    const code = '#define ANSWER 42\n#include <iostream>\nusing namespace std;\nint main() { cout << ANSWER; return 0; }';
    const flag = academicIntegrityEngine.checkHardcodingExtended(code, exerciseWithExpected, {});
    expect(flag).toBeNull();
  });

  it('does not catch hex literals (basic regex requires decimal digits)', () => {
    const code = '#include <iostream>\nusing namespace std;\nint main() { cout << 0x2A; return 0; }';
    const flag = academicIntegrityEngine.checkHardcoding(code, exerciseWithExpected, {});
    expect(flag).toBeNull();
  });

  it('does not catch parenthesized literals (basic regex requires digit right after <<)', () => {
    const code = '#include <iostream>\nusing namespace std;\nint main() { cout << (42); return 0; }';
    const flag = academicIntegrityEngine.checkHardcoding(code, exerciseWithExpected, {});
    expect(flag).toBeNull();
  });
});

describe('Blank Template Bypass — checkBlankTemplateExtended', () => {
  it('flags comment-only-identical submissions (normalized_identical)', () => {
    const starter = '// Write code here\n#include <iostream>\nint main() { return 0; }';
    const code = '// Write code here\n#include <iostream>\n// Student name: John Doe\nint main() { return 0; }';
    const flag = academicIntegrityEngine.checkBlankTemplateExtended(code, starter);
    expect(flag).not.toBeNull();
    expect(flag.type).toBe('BLANK_TEMPLATE');
    expect(flag.severity).toBe('MEDIUM');
    expect(flag.evidence.pattern).toBe('normalized_identical');
  });

  it('flags include-reshuffle-identical submissions (normalized_identical)', () => {
    const starter = '#include <iostream>\n#include <vector>\n\nint main() { return 0; }';
    const code = '#include <vector>\n#include <iostream>\n\nint main() { return 0; }';
    const flag = academicIntegrityEngine.checkBlankTemplateExtended(code, starter);
    expect(flag).not.toBeNull();
    expect(flag.type).toBe('BLANK_TEMPLATE');
    expect(flag.evidence.pattern).toBe('normalized_identical');
  });

  it('does not flag whitespace-plus-single-char edits (documented gap)', () => {
    const starter = '// Write code here\n#include <iostream>\nint main() { return 0; }';
    const code = '// Write code here\n#include <iostream>\nint main() { return 1; }';
    const flag = academicIntegrityEngine.checkBlankTemplateExtended(code, starter);
    expect(flag).toBeNull();
  });

  it('does not flag a real edit (no false positive)', () => {
    const starter = '// Write code here\n#include <iostream>\nint main() { return 0; }';
    const code = '// Write code here\n#include <iostream>\nint main() { int x = 5; return x; }';
    const flag = academicIntegrityEngine.checkBlankTemplateExtended(code, starter);
    expect(flag).toBeNull();
  });
});


