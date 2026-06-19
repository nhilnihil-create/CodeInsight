const mockDb = {
  query: jest.fn()
};

jest.mock('../config/db', () => ({
  query: mockDb.query
}));

const academicIntegrityEngine = require('./academicIntegrityEngine');

describe('Academic Integrity Engine', () => {
  beforeEach(() => {
    jest.clearAllMocks();
  });

  test('should exist', () => {
    expect(academicIntegrityEngine).toBeDefined();
  });

  test('should have evaluateIntegrity function', () => {
    expect(typeof academicIntegrityEngine.evaluateIntegrity).toBe('function');
  });

  test('should have checkHardcoding function', () => {
    expect(typeof academicIntegrityEngine.checkHardcoding).toBe('function');
  });

  test('should have checkBlankTemplate function', () => {
    expect(typeof academicIntegrityEngine.checkBlankTemplate).toBe('function');
  });

  describe('checkBlankTemplate', () => {
    const starter = '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}';

    test('should flag empty code', () => {
      const flag = academicIntegrityEngine.checkBlankTemplate('', starter);
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('BLANK_TEMPLATE');
    });

    test('should flag code matching starter code', () => {
      const flag = academicIntegrityEngine.checkBlankTemplate(starter, starter);
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('BLANK_TEMPLATE');
    });

    test('should not flag different code', () => {
      const code = '#include <iostream>\nusing namespace std;\n\nint main() {\n  int x = 5;\n  return x;\n}';
      const flag = academicIntegrityEngine.checkBlankTemplate(code, starter);
      expect(flag).toBeNull();
    });

    test('should not flag code with only whitespace differences', () => {
      const code = '  #include <iostream>\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}  ';
      const flag = academicIntegrityEngine.checkBlankTemplate(code, starter);
      expect(flag).toBeNull();
    });
  });

  describe('checkHardcoding', () => {
    const exercise = {
      starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}',
      test_cases: [],
      title: 'Test Exercise'
    };

    const submission = {
      time_spent_seconds: 5,
      is_correct: true,
      test_results: []
    };

    test('should detect hardcoded output with minimal computation', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { cout << 42; return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exercise, submission);
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
      expect(flag.severity).toBe('HIGH');
      expect(flag.evidence.summary).toContain('Found 1 direct numeric output');
    });

    test('should not flag code with sufficient computation logic', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() {\n  int a = 20;\n  int b = 22;\n  int sum = a + b;\n  cout << sum;\n  return 0;\n}';
      const flag = academicIntegrityEngine.checkHardcoding(code, exercise, submission);
      expect(flag).toBeNull();
    });

    test('should not flag code without numeric literals in cout', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5;\n  cout << x;\n  return 0;\n}';
      const flag = academicIntegrityEngine.checkHardcoding(code, exercise, submission);
      expect(flag).toBeNull();
    });

    test('should flag multiple hardcoded outputs with minimal computation', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() {\n  cout << 10;\n  cout << 20;\n  return 0;\n}';
      const flag = academicIntegrityEngine.checkHardcoding(code, exercise, submission);
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
      expect(flag.evidence.summary).toContain('Found 2 direct numeric output');
    });

    test('should handle edge case with no computation elements', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { cout << 99; return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exercise, submission);
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
    });

    test('should flag with HIGH severity when literal matches expected test output', () => {
      const exerciseWithTests = {
        ...exercise,
        test_cases: [{ input: '', expected: '42' }]
      };
      const code = '#include <iostream>\nusing namespace std;\nint main() { cout << 42; return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exerciseWithTests, submission);
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
      expect(flag.severity).toBe('HIGH');
      expect(flag.evidence.matchesExpectedOutput).toBe(true);
    });
  });

  describe('evaluateIntegrity', () => {
    const params = {
      code: '#include <iostream>\nusing namespace std;\nint main() { return 0; }',
      starterCode: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}',
      studentId: 1,
      exerciseId: 1,
      submission: {
        time_spent_seconds: 10,
        is_correct: true,
        test_results: [{ passed: true }]
      },
      exercise: {
        id: 1,
        title: 'Test Exercise',
        starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}'
      },
    };

    test('should run all checks and return flags array', async () => {
      const flags = await academicIntegrityEngine.evaluateIntegrity(params);
      expect(Array.isArray(flags)).toBe(true);
    });

    test('should include BLANK_TEMPLATE and HARDCODING flags when triggered', async () => {
      const starterCode = params.starterCode;
      const hardcodingCode = '#include <iostream>\nusing namespace std;\nint main() { cout << 42; return 0; }';

      const blankFlags = await academicIntegrityEngine.evaluateIntegrity({
        ...params,
        code: starterCode,
        starterCode
      });

      const hardcodingFlags = await academicIntegrityEngine.evaluateIntegrity({
        ...params,
        code: hardcodingCode
      });

      const flagTypes = new Set([
        ...blankFlags.map(f => f.type),
        ...hardcodingFlags.map(f => f.type)
      ]);

      expect(flagTypes).toContain('BLANK_TEMPLATE');
      expect(flagTypes).toContain('HARDCODING');

      [...blankFlags, ...hardcodingFlags].forEach(flag => {
        expect(flag.studentId).toBe(params.studentId);
        expect(flag.exerciseId).toBe(params.exerciseId);
      });
    });

    test('should handle errors in async checks gracefully', async () => {
      const flags = await academicIntegrityEngine.evaluateIntegrity(params);
      expect(Array.isArray(flags)).toBe(true);
    });
  });
});
