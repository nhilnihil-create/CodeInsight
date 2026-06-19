function jaccardSimilarity(a, b) {
  const tokensA = new Set(a.split(/\s+/));
  const tokensB = new Set(b.split(/\s+/));
  if (tokensA.size === 0 && tokensB.size === 0) return 1;
  const intersection = new Set([...tokensA].filter(t => tokensB.has(t)));
  const union = new Set([...tokensA, ...tokensB]);
  return intersection.size / union.size;
}

function clusterErrors(parsedErrors) {
  const clusters = new Map();

  for (const err of parsedErrors) {
    const key = `${err.errorType}:${err.signature}`;
    if (!clusters.has(key)) {
      clusters.set(key, {
        signature: err.signature,
        normalizedPattern: err.normalized,
        errorType: err.errorType,
        rawExamples: [],
        occurrences: 0,
        uniqueStudents: new Set(),
        uniqueExercises: new Set(),
        concepts: new Set(),
        submissions: []
      });
    }
    const c = clusters.get(key);

    if (c.rawExamples.length < 5 && err.rawMessage) {
      if (!c.rawExamples.includes(err.rawMessage)) {
        c.rawExamples.push(err.rawMessage);
      }
    }
    c.occurrences++;
    c.uniqueStudents.add(err.studentId);
    c.uniqueExercises.add(err.exerciseId);
    c.concepts.add(err.conceptName);
    c.submissions.push(err.submissionId);
  }

  const clusterList = [...clusters.values()];
  const merged = [];
  const used = new Set();

  for (let i = 0; i < clusterList.length; i++) {
    if (used.has(i)) continue;

    let primary = clusterList[i];
    used.add(i);

    for (let j = i + 1; j < clusterList.length; j++) {
      if (used.has(j)) continue;
      const sim = jaccardSimilarity(primary.normalizedPattern, clusterList[j].normalizedPattern);
      if (sim > 0.60 && primary.occurrences < 5) {
        const other = clusterList[j];
        primary.occurrences += other.occurrences;
        for (const s of other.uniqueStudents) primary.uniqueStudents.add(s);
        for (const e of other.uniqueExercises) primary.uniqueExercises.add(e);
        for (const c of other.concepts) primary.concepts.add(c);
        primary.submissions.push(...other.submissions);
        if (primary.rawExamples.length < 5 && other.rawExamples.length > 0) {
          primary.rawExamples.push(...other.rawExamples.slice(0, 5 - primary.rawExamples.length));
        }
        used.add(j);
      }
    }
    merged.push(primary);
  }

  return merged;
}

function rankClusters(clusters, { minStudents = 3, minOccurrences = 5 } = {}) {
  const filtered = clusters.filter(c =>
    c.uniqueStudents.size >= minStudents && c.occurrences >= minOccurrences
  );

  filtered.sort((a, b) => {
    const scoreA = a.uniqueStudents.size * a.occurrences;
    const scoreB = b.uniqueStudents.size * b.occurrences;
    return scoreB - scoreA;
  });

  return filtered;
}

module.exports = {
  jaccardSimilarity,
  clusterErrors,
  rankClusters
};
