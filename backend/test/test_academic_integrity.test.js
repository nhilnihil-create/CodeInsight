jest.mock('../config/db', () => ({ query: jest.fn() }));

const academicIntegrityEngine = require('../services/academicIntegrityEngine');
const db = require('../config/db');

const exercise = {
  id: 1,
  starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}',
  test_cases: []
};

describe('Academic Integrity Engine', () => {
  beforeEach(() => {
    jest.clearAllMocks();
  });

  describe('checkHardcoding', () => {
    it('should detect hardcoded numeric output', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { cout << 42; return 0; }';
      const submission = { time_spent_seconds: 30, is_correct: true };

      const flag = academicIntegrityEngine.checkHardcoding(code, exercise, submission);

      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
      expect(flag.severity).toBe('HIGH');
      expect(flag.evidence.summary).toContain('direct numeric output');
    });

    it('should not flag code with computation', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { int x = 5+3; cout << x; return 0; }';
      const submission = { time_spent_seconds: 30, is_correct: true };

      const flag = academicIntegrityEngine.checkHardcoding(code, exercise, submission);

      expect(flag).toBeNull();
    });
  });

  describe('checkBlankTemplate', () => {
    it('should flag exact match with starter code', () => {
      const code = '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}';
      const submission = { time_spent_seconds: 30, is_correct: true };

      const flag = academicIntegrityEngine.checkBlankTemplate(code, exercise.starter_code);

      expect(flag).not.toBeNull();
      expect(flag.type).toBe('BLANK_TEMPLATE');
      expect(flag.severity).toBe('HIGH');
    });

    it('should not flag whitespace-only differences', () => {
      const code = '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}\n';
      const submission = { time_spent_seconds: 30, is_correct: true };

      const flag = academicIntegrityEngine.checkBlankTemplate(code, exercise.starter_code);

      expect(flag).toBeNull();
    });
  });
});
