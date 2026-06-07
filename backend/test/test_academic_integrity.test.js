jest.mock('../config/db', () => ({ query: jest.fn() }));

const academicIntegrityEngine = require('../services/academicIntegrityEngine');
const db = require('../config/db');

// Mock exercise
const exercise = {
  id: 1,
  starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}',
  test_cases: []
};

// Mock cdsEngine
const cdsEngine = {
  calculateLiveCDS: jest.fn().mockResolvedValue({
    cds: 0.5,
    classification: 'Moderate'
  })
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
      expect(flag.severity).toBe('MEDIUM');
      expect(flag.evidence).toContain('direct numeric output');
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

  describe('checkBehavioralAnomaly', () => {
    it('should detect behavioral anomaly for fast first attempt', async () => {
      // Mock historical data
      db.query.mockResolvedValueOnce({
        rows: [{ avg_cds: 0.3, stddev_cds: 0.1, exercise_count: 5 }]
      });

      const studentId = 1;
      const exerciseId = 1;
      const submission = {
        time_spent_seconds: 15,  // Very fast
        is_correct: true,
        cds: 0.8  // High CDS
      };

      const flag = await academicIntegrityEngine.checkBehavioralAnomaly(
        studentId, exerciseId, submission, cdsEngine
      );

      expect(flag).not.toBeNull();
      expect(flag.type).toBe('BEHAVIORAL_ANOMALY');
      expect(flag.severity).toBe('MEDIUM');
      expect(flag.evidence).toContain('Solved in 15s on first attempt with CDS 0.80');
    });

    it('should not flag when insufficient history', async () => {
      // Mock insufficient historical data
      db.query.mockResolvedValueOnce({
        rows: [{ avg_cds: 0.3, stddev_cds: 0.1, exercise_count: 2 }]
      });

      const studentId = 1;
      const exerciseId = 1;
      const submission = {
        time_spent_seconds: 15,
        is_correct: true,
        cds: 0.8
      };

      const flag = await academicIntegrityEngine.checkBehavioralAnomaly(
        studentId, exerciseId, submission, cdsEngine
      );

      expect(flag).toBeNull();
    });
  });

  describe('checkCodeGrowthAnomaly', () => {
    it('should detect significant code growth', async () => {
      // Mock first submission
      db.query.mockResolvedValueOnce({
        rows: [{ code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  return 0;\n}' }]
      });

      const studentId = 1;
      const exerciseId = 1;
      const code = '#include <iostream>\nusing namespace std;\n\nint main() {\n  int x = 5;\n  int y = 10;\n  int z = x + y;\n  int a = 1;\n  int b = 2;\n  int c = 3;\n  int d = 4;\n  int e = 5;\n  int f = 6;\n  int g = 7;\n  int h = 8;\n  int i = 9;\n  int j = 10;\n  cout << "Result: " << z << endl;\n  cout << "Extra: " << (a+b+c+d+e+f+g+h+i+j) << endl;\n  return 0;\n}';  // Much larger

      const flag = await academicIntegrityEngine.checkCodeGrowthAnomaly(
        studentId, exerciseId, code
      );

      expect(flag).not.toBeNull();
      expect(flag.type).toBe('CODE_GROWTH_ANOMALY');
      expect(flag.severity).toBe('LOW');
      expect(flag.evidence).toContain('increase');
    });

    it('should not flag first submission', async () => {
      // Mock no first submission found
      db.query.mockResolvedValueOnce({
        rows: []
      });

      const studentId = 1;
      const exerciseId = 1;
      const code = '#include <iostream>\nusing namespace std;\n\nint main() {\n  return 0;\n}';

      const flag = await academicIntegrityEngine.checkCodeGrowthAnomaly(
        studentId, exerciseId, code
      );

      expect(flag).toBeNull();
    });
  });
});

// NOTE: Removed top-level `exec('npx jest ' + __filename)` block.
// Jest auto-discovers *.test.js files; the previous code spawned a
// recursive child Jest process on every module load, leaking
// PROCESSWRAP + PIPEWRAP handles and causing memory fork-bomb on
// concurrent runs. See MEMORY STABILITY AUDIT (Task 3, leak L1).