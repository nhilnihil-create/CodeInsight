const { extractKeywords, validateCluster, generateCandidate } = require('../services/candidateValidator');

describe('extractKeywords', () => {
  it('extracts meaningful keywords from signature', () => {
    const result = extractKeywords('was not declared in this scope');
    expect(result).toContain('was not declared');
    expect(result).toContain('in this scope');
  });

  it('handles short signature', () => {
    expect(extractKeywords('expected')).toEqual(['expected']);
  });

  it('handles empty string', () => {
    expect(extractKeywords('')).toEqual([]);
  });
});

describe('validateCluster', () => {
  function makeSub(id, log, correct) {
    return { id, compiler_log: log, is_correct: correct };
  }

  it('counts true positives correctly', () => {
    const cluster = {
      signature: 'was not declared in this scope',
      normalizedPattern: "'<id>' was not declared in this scope"
    };
    const submissions = [
      makeSub(1, '[Line 5:5] ERROR: x was not declared in this scope', false),
      makeSub(2, '[Line 3:5] ERROR: y was not declared in this scope', false),
      makeSub(3, '[Line 1:1] ERROR: expected ;', false)
    ];
    const result = validateCluster(cluster, submissions);
    expect(result.truePositives).toBe(2);
    expect(result.falsePositives).toBe(0);
    expect(result.falseNegatives).toBe(1);
  });

  it('counts false positives when keyword matches but no real error', () => {
    const cluster = {
      signature: 'was not declared',
      normalizedPattern: "'<id>' was not declared"
    };
    const submissions = [
      makeSub(1, '[Line 5:5] ERROR: x was not declared', false),
      makeSub(2, '[Line 3:5] INFO: was not declared issue', true)
    ];
    const result = validateCluster(cluster, submissions);
    expect(result.truePositives).toBe(1);
    expect(result.falsePositives).toBe(1);
    expect(result.falseNegatives).toBe(0);
  });

  it('computes precision correctly', () => {
    const cluster = {
      signature: 'was not declared',
      normalizedPattern: "'<id>' was not declared in this scope"
    };
    const submissions = [
      makeSub(1, '[Line 5:5] ERROR: x was not declared', false),
      makeSub(2, '[Line 3:5] ERROR: y was not declared', false),
      makeSub(3, '[Line 1:1] ERROR: was not declared', true)
    ];
    const result = validateCluster(cluster, submissions);
    expect(result.truePositives).toBe(2);
    expect(result.falsePositives).toBe(1);
    expect(result.precision).toBeCloseTo(2 / 3, 2);
  });

  it('handles empty submissions array', () => {
    const cluster = { signature: 'test', normalizedPattern: 'test' };
    const result = validateCluster(cluster, []);
    expect(result.precision).toBe(0);
    expect(result.recall).toBe(0);
  });
});

describe('generateCandidate', () => {
  it('generates a valid candidate object from cluster and validation', () => {
    const cluster = {
      signature: 'was not declared in this scope',
      normalizedPattern: "'<id>' was not declared in this scope",
      errorType: 'ERROR',
      rawExamples: ["'x' was not declared", "'y' was not declared"],
      occurrences: 47,
      uniqueStudents: new Set([1, 2, 3]),
      uniqueExercises: new Set([42]),
      concepts: new Set(['Arrays'])
    };
    const validation = {
      precision: 0.95,
      recall: 0.90,
      truePositives: 45,
      falsePositives: 2,
      falseNegatives: 5
    };
    const candidate = generateCandidate(cluster, validation);
    expect(candidate.id).toMatch(/^__candidate_/);
    expect(candidate.name).toBeTruthy();
    expect(candidate.match_keywords).toContain('was not declared');
    expect(candidate.confidence).toBe(95);
    expect(candidate.validation.precision).toBe(0.95);
  });
});
