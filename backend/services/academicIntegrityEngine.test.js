// Test file for academicIntegrityEngine.js
// Enhanced test suite covering all integrity checks

// Mock database for testing async functions
const mockDb = {
  query: jest.fn()
};

// Mock cdsEngine for behavioral anomaly check
const mockCdsEngine = {};

// Properly mock the db pool object from ../config/db
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

  test('should have checkBehavioralAnomaly function', () => {
    expect(typeof academicIntegrityEngine.checkBehavioralAnomaly).toBe('function');
  });

  test('should have checkCodeGrowthAnomaly function', () => {
    expect(typeof academicIntegrityEngine.checkCodeGrowthAnomaly).toBe('function');
  });

  test('should have logPassiveBehavior function', () => {
    expect(typeof academicIntegrityEngine.logPassiveBehavior).toBe('function');
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
      expect(flag).toBeNull(); // Should not flag as blank
    });

    test('should not flag code with only whitespace differences', () => {
      const code = '  #include <iostream>\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}  ';
      const flag = academicIntegrityEngine.checkBlankTemplate(code, starter);
      expect(flag).toBeNull(); // Should not flag as blank (whitespace only)
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
      expect(flag.severity).toBe('MEDIUM');
      expect(flag.evidence).toContain('Found 1 direct numeric output');
    });

    test('should not flag code with sufficient computation logic', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() {\n  int a = 20;\n  int b = 22;\n  int sum = a + b;\n  cout << sum;\n  return 0;\n}';
      const flag = academicIntegrityEngine.checkHardcoding(code, exercise, submission);
      expect(flag).toBeNull(); // Should not flag (has operations and variables)
    });

    test('should not flag code without numeric literals in cout', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5;\n  cout << x;\n  return 0;\n}';
      const flag = academicIntegrityEngine.checkHardcoding(code, exercise, submission);
      expect(flag).toBeNull(); // Should not flag (no direct numeric output)
    });

    test('should flag multiple hardcoded outputs with minimal computation', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() {\n  cout << 10;\n  cout << 20;\n  return 0;\n}';
      const flag = academicIntegrityEngine.checkHardcoding(code, exercise, submission);
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
      expect(flag.evidence).toContain('Found 2 direct numeric output');
    });

    test('should handle edge case with no computation elements', () => {
      const code = '#include <iostream>\nusing namespace std;\nint main() { cout << 99; return 0; }';
      const flag = academicIntegrityEngine.checkHardcoding(code, exercise, submission);
      expect(flag).not.toBeNull();
      expect(flag.type).toBe('HARDCODING');
    });
  });

  describe('checkBehavioralAnomaly', () => {
    const studentId = 1;
    const exerciseId = 101;
    const submission = {
      time_spent_seconds: 20,
      is_correct: true,
      test_results: [{ passed: true }],
      cds: 0.9 // High CDS score indicating unusually good performance
    };

    test('should return null when not enough historical data', async () => {
      mockDb.query.mockResolvedValueOnce({ rows: [{ avg_cds: null, stddev_cds: null, exercise_count: 2 }] });

      const flag = await academicIntegrityEngine.checkBehavioralAnomaly(
        studentId, exerciseId, submission, mockCdsEngine
      );

      expect(flag).toBeNull();
      expect(mockDb.query).toHaveBeenCalledWith(
        `SELECT
         AVG(cds) as avg_cds,
         STDDEV_POP(cds) as stddev_cds,
         COUNT(*) as exercise_count
       FROM cds_scores
       WHERE student_id = $1 AND exercise_id != $2`,
        [studentId, exerciseId]
      );
    });

    test('should return null when current CDS is in line with historical average', async () => {
      mockDb.query.mockResolvedValueOnce({ rows: [{ avg_cds: 0.3, stddev_cds: 0.1, exercise_count: 5 }] });

      const typicalSubmission = { ...submission, cds: 0.32 };
      const flag = await academicIntegrityEngine.checkBehavioralAnomaly(
        studentId, exerciseId, typicalSubmission, mockCdsEngine
      );

      expect(flag).toBeNull();
    });

    test('should return null when submission is not fast enough', async () => {
      mockDb.query.mockResolvedValueOnce({ rows: [{ avg_cds: 0.5, stddev_cds: 0.2, exercise_count: 3 }] });

      const slowSubmission = { ...submission, time_spent_seconds: 45 };
      const flag = await academicIntegrityEngine.checkBehavioralAnomaly(
        studentId, exerciseId, slowSubmission, mockCdsEngine
      );

      expect(flag).toBeNull();
    });

    test('should return null when submission is not correct', async () => {
      mockDb.query.mockResolvedValueOnce({ rows: [{ avg_cds: 0.5, stddev_cds: 0.2, exercise_count: 3 }] });

      const incorrectSubmission = { ...submission, is_correct: false };
      const flag = await academicIntegrityEngine.checkBehavioralAnomaly(
        studentId, exerciseId, incorrectSubmission, mockCdsEngine
      );

      expect(flag).toBeNull();
    });

    test('should return null when z-score is not significant enough', async () => {
      mockDb.query.mockResolvedValueOnce({ rows: [{ avg_cds: 0.5, stddev_cds: 0.2, exercise_count: 4 }] }); // z-score = (0.9-0.5)/0.2 = 2.0 (exactly at threshold)

      const flag = await academicIntegrityEngine.checkBehavioralAnomaly(
        studentId, exerciseId, submission, mockCdsEngine
      );

      expect(flag).toBeNull(); // Should not flag as z-score is not > 2.0
    });

    test('should flag behavioral anomaly when all conditions met', async () => {
      // V2 FIX: zScore < -2.0 flags sudden improvement (cheating shows as better performance)
      // avg_cds = 0.7 (usually struggles), current cds = 0.1 (suddenly perfect)
      // zScore = (0.1 - 0.7) / 0.15 = -4.0 < -2.0 → FLAGGED
      mockDb.query.mockResolvedValueOnce({ rows: [{ avg_cds: 0.7, stddev_cds: 0.15, exercise_count: 4 }] });
      submission.cds = 0.1; // Much better than usual

      const flag = await academicIntegrityEngine.checkBehavioralAnomaly(
        studentId, exerciseId, submission, mockCdsEngine
      );

      expect(flag).not.toBeNull();
      expect(flag.type).toBe('BEHAVIORAL_ANOMALY');
      expect(flag.severity).toBe('MEDIUM');
      expect(flag.evidence).toContain('Solved in 20s on first attempt');
      expect(flag.evidence).toContain('z-score: -4.00');
      expect(flag.evidence).toContain('4 prior exercises');
    });

    test('should handle database error gracefully', async () => {
      mockDb.query.mockRejectedValueOnce(new Error('DB connection failed'));

      const flag = await academicIntegrityEngine.checkBehavioralAnomaly(
        studentId, exerciseId, submission, mockCdsEngine
      );

      expect(flag).toBeNull(); // Should return null on error
    });
  });

  describe('checkCodeGrowthAnomaly', () => {
    const studentId = 1;
    const exerciseId = 202;
    const firstSubmissionCode = '#include <iostream>\nusing namespace std;\n\nint main() {\n  int x = 5;\n  int y = 10;\n  cout << x + y;\n  return 0;\n}';

    test('should return null when not enough submission data (no first submission)', async () => {
      mockDb.query.mockResolvedValueOnce({ rows: [] }); // No first submission found

      const flag = await academicIntegrityEngine.checkCodeGrowthAnomaly(
        studentId, exerciseId, '#include <iostream>\nusing namespace std;\n\nint main() {\n  int x = 5;\n  int y = 10;\n  int z = x * y;\n  cout << z;\n  return 0;\n}'
      );

      expect(flag).toBeNull();
    });

    test('should return null when line count growth is minimal', async () => {
      mockDb.query.mockResolvedValueOnce({ rows: [{ code: firstSubmissionCode } ] }); // First submission

      const flag = await academicIntegrityEngine.checkCodeGrowthAnomaly(
        studentId, exerciseId, '#include <iostream>\nusing namespace std;\n\nint main() {\n  int x = 5;\n  int y = 10;\n  cout << x + y;\n  return 0;\n}' // Same line count
      );

      expect(flag).toBeNull();
    });

    test('should flag code growth anomaly when line count doubled (>100% increase)', async () => {
      const compactFirst = 'line1\nline2\nline3\nline4\nline5';
      mockDb.query.mockResolvedValueOnce({ rows: [{ code: compactFirst }] });

      // >100% growth and >10 new non-empty lines vs first submission
      const excessiveCode = Array.from({ length: 18 }, (_, i) => `stmt${i + 1};`).join('\n');

      const flag = await academicIntegrityEngine.checkCodeGrowthAnomaly(
        studentId, exerciseId, excessiveCode
      );

      expect(flag).not.toBeNull();
      expect(flag.type).toBe('CODE_GROWTH_ANOMALY');
      expect(flag.severity).toBe('LOW');
      expect(flag.evidence).toContain('Submission has');
      expect(flag.evidence).toContain('non-empty lines vs');
      expect(flag.evidence).toContain('% increase');
    });

    test('should handle database error gracefully', async () => {
      mockDb.query.mockRejectedValueOnce(new Error('DB query failed'));

      const flag = await academicIntegrityEngine.checkCodeGrowthAnomaly(
        studentId, exerciseId, '#include <iostream>\nusing namespace std;\n\nint main() {\n  int x = 5;\n  int y = 10;\n  cout << x + y;\n  return 0;\n}'
      );

      expect(flag).toBeNull(); // Should return null on error
    });
  });

  describe('logPassiveBehavior', () => {
    test('should merge behavioral data with submission', () => {
      const submission = { studentId: 1, exerciseId: 101 };
      const behavioralData = { tabSwitchCount: 5, pausedTimeSeconds: 30 };

      const result = academicIntegrityEngine.logPassiveBehavior(submission, behavioralData);

      expect(result).toEqual({
        studentId: 1,
        exerciseId: 101,
        tabSwitchCount: 5,
        pausedTimeSeconds: 30
      });
    });

    test('should handle empty behavioral data', () => {
      const submission = { studentId: 1, exerciseId: 101, is_correct: true };
      const behavioralData = {};

      const result = academicIntegrityEngine.logPassiveBehavior(submission, behavioralData);

      expect(result).toEqual({
        studentId: 1,
        exerciseId: 101,
        is_correct: true
      });
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
      cdsEngine: mockCdsEngine,
      behavioralData: { tabSwitchCount: 2 }
    };

    test('should run all checks and return flags array', async () => {
      mockDb.query
        .mockResolvedValueOnce({ rows: [{ avg_cds: 0.5, stddev_cds: 0.2, exercise_count: 2 }] })
        .mockResolvedValueOnce({ rows: [] })
        .mockResolvedValueOnce({ rows: [] });

      const flags = await academicIntegrityEngine.evaluateIntegrity(params);

      expect(mockDb.query).toHaveBeenCalledTimes(3);
      expect(Array.isArray(flags)).toBe(true);
    });

    test('should include flags from all check types when triggered', async () => {
      const starterCode = params.starterCode;
      const hardcodingCode = '#include <iostream>\nusing namespace std;\nint main() { cout << 42; return 0; }';
      const growthCode = Array.from({ length: 18 }, (_, i) => `stmt${i + 1};`).join('\n');

      mockDb.query
        .mockResolvedValueOnce({ rows: [{ avg_cds: 0.5, stddev_cds: 0.2, exercise_count: 2 }] })
        .mockResolvedValueOnce({ rows: [] })
        .mockResolvedValueOnce({ rows: [] });
      const blankFlags = await academicIntegrityEngine.evaluateIntegrity({
        ...params,
        code: starterCode,
        starterCode
      });
      jest.clearAllMocks();

      mockDb.query
        .mockResolvedValueOnce({ rows: [{ avg_cds: 0.5, stddev_cds: 0.2, exercise_count: 2 }] })
        .mockResolvedValueOnce({ rows: [] })
        .mockResolvedValueOnce({ rows: [] });
      const hardcodingFlags = await academicIntegrityEngine.evaluateIntegrity({
        ...params,
        code: hardcodingCode
      });
      jest.clearAllMocks();

      mockDb.query
        .mockResolvedValueOnce({ rows: [{ avg_cds: 0.7, stddev_cds: 0.15, exercise_count: 4 }] })
        .mockResolvedValueOnce({ rows: [] })
        .mockResolvedValueOnce({ rows: [] });
      const behavioralFlags = await academicIntegrityEngine.evaluateIntegrity({
        ...params,
        code: hardcodingCode,
        behavioralData: { pasteCount: 1, tabSwitchCount: 2 },
        submission: {
          ...params.submission,
          time_spent_seconds: 20,
          is_correct: true,
          cds: 0.1 // Much better than usual → zScore < -2.0
        }
      });
      jest.clearAllMocks();

      mockDb.query
        .mockResolvedValueOnce({ rows: [{ avg_cds: 0.5, stddev_cds: 0.2, exercise_count: 2 }] })
        .mockResolvedValueOnce({ rows: [{ code: 'line1\nline2\nline3\nline4\nline5' }] })
        .mockResolvedValueOnce({ rows: [] });
      const growthFlags = await academicIntegrityEngine.evaluateIntegrity({
        ...params,
        code: growthCode
      });

      const flagTypes = new Set([
        ...blankFlags.map(f => f.type),
        ...hardcodingFlags.map(f => f.type),
        ...behavioralFlags.map(f => f.type),
        ...growthFlags.map(f => f.type)
      ]);

      expect(flagTypes).toContain('BLANK_TEMPLATE');
      expect(flagTypes).toContain('HARDCODING');
      expect(flagTypes).toContain('PASTE_ON_CORRECT_SUBMISSION');
      expect(flagTypes).toContain('CODE_GROWTH_ANOMALY');

      [...blankFlags, ...hardcodingFlags, ...behavioralFlags, ...growthFlags].forEach(flag => {
        expect(flag.studentId).toBe(params.studentId);
        expect(flag.exerciseId).toBe(params.exerciseId);
      });
    });

    test('should handle errors in async checks gracefully', async () => {
      mockDb.query
        .mockRejectedValueOnce(new Error('Test error'))
        .mockResolvedValueOnce({ rows: [] })
        .mockResolvedValueOnce({ rows: [] });

      const flags = await academicIntegrityEngine.evaluateIntegrity(params);

      expect(mockDb.query).toHaveBeenCalledTimes(3);
      expect(Array.isArray(flags)).toBe(true);
    });
  });
});
