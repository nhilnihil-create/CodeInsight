const { clusterErrors, jaccardSimilarity, rankClusters } = require('../services/errorClusterer');

function makeError(signature, normalized, studentId, exerciseId, conceptName, submissionId) {
  return {
    submissionId: submissionId || 1,
    studentId: studentId || 1,
    exerciseId: exerciseId || 42,
    conceptId: 7,
    conceptName: conceptName || 'Arrays',
    errorType: 'ERROR',
    rawMessage: 'some error',
    line: 1, column: 1,
    normalized: normalized || signature,
    signature
  };
}

describe('clusterErrors', () => {
  it('groups errors with the same signature into one cluster', () => {
    const errors = [
      makeError('was not declared in this scope', "'<id>' was not declared", 1, 42, 'Arrays', 1),
      makeError('was not declared in this scope', "'<id>' was not declared", 2, 42, 'Arrays', 2),
      makeError('expected', "expected '<id>' before '<id>'", 1, 42, 'Arrays', 3)
    ];
    const clusters = clusterErrors(errors);
    expect(clusters).toHaveLength(2);
    const declCluster = clusters.find(c => c.signature === 'was not declared in this scope');
    expect(declCluster.occurrences).toBe(2);
    expect(declCluster.uniqueStudents.size).toBe(2);
  });

  it('handles empty input', () => {
    expect(clusterErrors([])).toEqual([]);
  });

  it('does not merge clusters with low Jaccard similarity', () => {
    const errors = [
      makeError('expected identifier', "expected '<id>'", 1, 42, 'Arrays', 1),
      makeError('expected before', "call to '<id>' is ambiguous", 2, 42, 'Variables', 2)
    ];
    const clusters = clusterErrors(errors);
    expect(clusters).toHaveLength(2);
  });
});

describe('rankClusters', () => {
  function makeCluster(signature, occurrences, uniqueStudents) {
    const us = new Set();
    for (let i = 0; i < uniqueStudents; i++) us.add(i + 1);
    const ue = new Set([42]);
    const concepts = new Set(['Arrays']);
    return { signature, normalizedPattern: signature, errorType: 'ERROR', rawExamples: [], occurrences, uniqueStudents: us, uniqueExercises: ue, concepts, submissions: [] };
  }

  it('sorts clusters by uniqueStudents * occurrences descending', () => {
    const clusters = [
      makeCluster('error A', 5, 2),
      makeCluster('error B', 10, 5),
      makeCluster('error C', 3, 3)
    ];
    const ranked = rankClusters(clusters, { minStudents: 1, minOccurrences: 1 });
    expect(ranked[0].signature).toBe('error B');
    expect(ranked[1].signature).toBe('error A');
    expect(ranked[2].signature).toBe('error C');
  });

  it('filters out clusters below minStudents threshold', () => {
    const clusters = [
      makeCluster('error A', 10, 2),
      makeCluster('error B', 10, 5)
    ];
    const ranked = rankClusters(clusters, { minStudents: 3, minOccurrences: 1 });
    expect(ranked).toHaveLength(1);
    expect(ranked[0].signature).toBe('error B');
  });

  it('filters out clusters below minOccurrences threshold', () => {
    const clusters = [
      makeCluster('error A', 2, 3),
      makeCluster('error B', 10, 3)
    ];
    const ranked = rankClusters(clusters, { minStudents: 1, minOccurrences: 5 });
    expect(ranked).toHaveLength(1);
    expect(ranked[0].signature).toBe('error B');
  });

  it('returns empty array when all clusters filtered out', () => {
    expect(rankClusters([makeCluster('error', 1, 1)], { minStudents: 5, minOccurrences: 5 })).toEqual([]);
  });

  it('handles empty input', () => {
    expect(rankClusters([], { minStudents: 3, minOccurrences: 5 })).toEqual([]);
  });
});
