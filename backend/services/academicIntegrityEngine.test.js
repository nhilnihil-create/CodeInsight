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

    test('should return null when historical CDS is low', async () => {
      mockDb.query.mockResolvedValueOnce({ rows: [{ avg_cds: 0.3, stddev_cds: 0.1, exercise_count: 5 }] });

      const flag = await academicIntegrityEngine.checkBehavioralAnomaly(
        studentId, exerciseId, submission, mockCdsEngine
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
      mockDb.query.mockResolvedValueOnce({ rows: [{ avg_cds: 0.5, stddev_cds: 0.15, exercise_count: 4 }] }); // z-score = (0.9-0.5)/0.15 = 2.67

      const flag = await academicIntegrityEngine.checkBehavioralAnomaly(
        studentId, exerciseId, submission, mockCdsEngine
      );

      expect(flag).not.toBeNull();
      expect(flag.type).toBe('BEHAVIORAL_ANOMALY');
      expect(flag.severity).toBe('MEDIUM');
      expect(flag.evidence).toContain('Solved in 20s on first attempt');
      expect(flag.evidence).toContain('z-score: 2.67');
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
      mockDb.query.mockResolvedValueOnce({ rows: [{ code: firstSubmissionCode } ] }); // First submission: 4 non-empty lines

      // Second submission: 9 non-empty lines (125% increase)
      const excessiveCode = '#include <iostream>\nusing namespace std;\n\nint main() {\n  int x = 5;\n  int y = 10;\n  cout << \"Hello World\";\n  cout << x;\n  cout << y;\n  cout << x + y;\n  cout << x * y;\n  return 0;\n}';

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
      // Mock the async functions to return specific flags for testing
      jest.spyOn(academicIntegrityEngine, 'checkBehavioralAnomaly').mockResolvedValue(null);
      jest.spyOn(academicIntegrityEngine, 'checkCodeGrowthAnomaly').mockResolvedValue(null);

      try {
        const flags = await academicIntegrityEngine.evaluateIntegrity(params);

        // Should have called async functions
        expect(academicIntegrityEngine.checkBehavioralAnomaly).toHaveBeenCalled();
        expect(academicIntegrityEngine.checkCodeGrowthAnomaly).toHaveBeenCalled();

        // Should return array (potentially empty if no flags)
        expect(Array.isArray(flags)).toBe(true);
      } finally {
        // Restore spies
        jest.restoreAllMocks();
      }
    });

    test('should include flags from all check types when triggered', async () => {
      // Mock checkHardcoding to return a flag
      const hardcodingFlag = {
        type: 'HARDCODING',
        severity: 'MEDIUM',
        evidence: 'Test evidence',
        context: {}
      };

      // Mock checkBlankTemplate to return a flag
      const blankFlag = {
        type: 'BLANK_TEMPLATE',
        severity: 'HIGH',
        evidence: 'Test evidence',
        context: {}
      };

      // Mock async functions to return flags
      const behavioralFlag = {
        type: 'BEHAVIORAL_ANOMALY',
        severity: 'MEDIUM',
        evidence: 'Test evidence',
        context: {}
      };

      const growthFlag = {
        type: 'CODE_GROWTH_ANOMALY',
        severity: 'LOW',
        evidence: 'Test evidence',
        context: {}
      };

      // Spy on the actual functions
      jest.spyOn(academicIntegrityEngine, 'checkHardcoding').mockReturnValue(hardcodingFlag);
      jest.spyOn(academicIntegrityEngine, 'checkBlankTemplate').mockReturnValue(blankFlag);
      jest.spyOn(academicIntegrityEngine, 'checkBehavioralAnomaly').mockResolvedValue(behavioralFlag);
      jest.spyOn(academicIntegrityEngine, 'checkCodeGrowthAnomaly').mockResolvedValue(growthFlag);

      try {
        const flags = await academicIntegrityEngine.evaluateIntegrity(params);

        // Should have flags from all check types
        expect(flags.length).toBe(4);

        // Check that each flag type is present
        const flagTypes = flags.map(f => f.type);
        expect(flagTypes).toContain('HARDCODING');
        expect(flagTypes).toContain('BLANK_TEMPLATE');
        expect(flagTypes).toContain('BEHAVIORAL_ANOMALY');
        expect(flagTypes).toContain('CODE_GROWTH_ANOMALY');

        // Check that studentId and exerciseId are added to each flag
        flags.forEach(flag => {
          expect(flag.studentId).toBe(params.studentId);
          expect(flag.exerciseId).toBe(params.exerciseId);
        });
      } finally {
        // Restore spies
        jest.restoreAllMocks();
      }
    });

    test('should handle errors in async checks gracefully', async () => {
      // Make checkBehavioralAnomaly throw an error
      jest.spyOn(academicIntegrityEngine, 'checkBehavioralAnomaly').mockRejectedValue(new Error('Test error'));

      // Make checkCodeGrowthAnomaly return normally
      jest.spyOn(academicIntegrityEngine, 'checkCodeGrowthAnomaly').mockResolvedValue(null);

      try {
        const flags = await academicIntegrityEngine.evaluateIntegrity(params);

        // Should still return flags from synchronous checks
        expect(Array.isArray(flags)).toBe(true);

        // The async check that threw should not prevent function from completing
        expect(academicIntegrityEngine.checkBehavioralAnomaly).toHaveBeenCalled();
        expect(academicIntegrityEngine.checkCodeGrowthAnomaly).toHaveBeenCalled();
      } finally {
        // Restore spies
        jest.restoreAllMocks();
      }
    });
  });
});
