const { runFullPipeline } = require('../services/misconceptionRuleMiner');

jest.mock('../config/db', () => ({ query: jest.fn() }));
jest.mock('../services/errorNormalizer');
jest.mock('../services/errorClusterer');
jest.mock('../services/candidateValidator');

const db = require('../config/db');
const errorNormalizer = require('../services/errorNormalizer');
const errorClusterer = require('../services/errorClusterer');
const candidateValidator = require('../services/candidateValidator');

describe('runFullPipeline', () => {
  beforeEach(() => {
    jest.clearAllMocks();

    errorNormalizer.parseCompilerLog.mockReturnValue([
      { submissionId: 1, studentId: 1, exerciseId: 42, conceptId: 7, conceptName: 'Arrays', errorType: 'ERROR', rawMessage: 'test error', line: 1, column: 1 }
    ]);

    errorClusterer.clusterErrors.mockReturnValue([
      { signature: 'test signature', normalizedPattern: 'test normalized', occurrences: 10, uniqueStudents: new Set([1,2,3]), uniqueExercises: new Set([42]), concepts: new Set(['Arrays']), submissions: [1,2,3] }
    ]);
    errorClusterer.rankClusters.mockReturnValue([
      { signature: 'test signature', normalizedPattern: 'test normalized', occurrences: 10, uniqueStudents: new Set([1,2,3]), uniqueExercises: new Set([42]), concepts: new Set(['Arrays']), submissions: [1,2,3] }
    ]);

    candidateValidator.validateCluster.mockReturnValue({ precision: 0.95, recall: 0.90, truePositives: 9, falsePositives: 1, falseNegatives: 1 });
    candidateValidator.generateCandidate.mockReturnValue({ id: '__candidate_test', name: 'Test Rule', confidence: 95, validation: { precision: 0.95 } });
  });

  it('returns candidate array from the full pipeline', async () => {
    db.query
      .mockResolvedValueOnce({ rows: [{ id: 1, student_id: 1, exercise_id: 42, compiler_log: '[Line 1:1] ERROR: test error', test_results: null, is_correct: false, concept_id: 7, concept_name: 'Arrays' }] })
      .mockResolvedValueOnce({ rows: [] });

    const result = await runFullPipeline({ exerciseId: 42, outputPath: '/tmp/test_candidates.json' });
    expect(result.candidates).toHaveLength(1);
    expect(result.candidates[0].id).toBe('__candidate_test');
    expect(result.total_submissions_analyzed).toBe(1);
    expect(result.total_students).toBe(1);
  });

  it('returns empty candidates when no submissions exist', async () => {
    db.query
      .mockResolvedValueOnce({ rows: [] })
      .mockResolvedValueOnce({ rows: [] });

    const result = await runFullPipeline({ exerciseId: 99 });
    expect(result.candidates).toHaveLength(0);
    expect(result.total_submissions_analyzed).toBe(0);
    expect(result.total_students).toBe(0);
  });

  it('writes output file when outputPath is provided', async () => {
    const fs = require('fs');
    db.query
      .mockResolvedValueOnce({ rows: [{ id: 1, student_id: 1, exercise_id: 42, compiler_log: '[Line 1:1] ERROR: test error', test_results: null, is_correct: false, concept_id: 7, concept_name: 'Arrays' }] })
      .mockResolvedValueOnce({ rows: [] });

    const testPath = '/tmp/test_candidates_output.json';
    await runFullPipeline({ exerciseId: 42, outputPath: testPath });
    expect(fs.existsSync(testPath)).toBe(true);
    const content = JSON.parse(fs.readFileSync(testPath, 'utf8'));
    expect(content.candidates).toHaveLength(1);
    expect(content.pipeline_version).toBe('1.0.0');
    fs.unlinkSync(testPath);
  });

  it('uses default threshold values when not provided', async () => {
    db.query
      .mockResolvedValueOnce({ rows: [{ id: 1, student_id: 1, exercise_id: 42, compiler_log: '[Line 1:1] ERROR: test error', test_results: null, is_correct: false, concept_id: 7, concept_name: 'Arrays' }] })
      .mockResolvedValueOnce({ rows: [] });

    await runFullPipeline({ exerciseId: 42 });
    expect(errorClusterer.rankClusters).toHaveBeenCalledWith(
      expect.any(Array),
      { minStudents: 3, minOccurrences: 5 }
    );
  });
});
