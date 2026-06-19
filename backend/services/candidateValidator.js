function extractKeywords(signature) {
  if (!signature) return [];
  const words = signature.split(/\s+/).filter(w => w.length > 1);
  const phrases = [];
  phrases.push(signature);
  for (let i = 0; i < words.length - 1; i++) {
    phrases.push(words.slice(i, i + 2).join(' '));
    if (i + 2 < words.length) {
      phrases.push(words.slice(i, i + 3).join(' '));
    }
  }
  return [...new Set(phrases)];
}

function validateCluster(cluster, allSubmissions) {
  if (!allSubmissions || allSubmissions.length === 0) {
    return { precision: 0, recall: 0, truePositives: 0, falsePositives: 0, falseNegatives: 0 };
  }

  const keywords = extractKeywords(cluster.signature);
  let tp = 0, fp = 0, fn = 0;

  for (const sub of allSubmissions) {
    const log = (sub.compiler_log || '').toLowerCase();
    const hasKeyword = keywords.some(k => log.includes(k.toLowerCase()));
    const hasRealErrors = log.includes('error:') && !sub.is_correct;

    if (hasKeyword && hasRealErrors) tp++;
    else if (hasKeyword && !hasRealErrors) fp++;
    else if (!hasKeyword && hasRealErrors) fn++;
  }

  const total = tp + fp + fn;
  return {
    precision: total > 0 ? tp / (tp + fp) : 0,
    recall: total > 0 ? tp / (tp + fn) : 0,
    truePositives: tp,
    falsePositives: fp,
    falseNegatives: fn
  };
}

function generateCandidate(cluster, validation) {
  const id = `__candidate_${Date.now()}_${Math.random().toString(36).slice(2, 6)}`;

  const nameMap = {
    'was not declared': 'Undeclared Identifier',
    'expected': 'Syntax Error — Expected Token',
    'cannot convert': 'Type Conversion Mismatch',
    'no match for': 'Missing Operator',
    'unused variable': 'Unused Variable',
    'invalid conversion': 'Invalid Type Conversion',
    'not declared': 'Undeclared Identifier',
    'std::': 'Missing Namespace Prefix',
    'out of bounds': 'Array Index Out of Bounds',
    'segmentation fault': 'Segmentation Fault',
    'does not name a type': 'Unknown Type Name'
  };

  let name = 'Compiler Error';
  for (const [key, value] of Object.entries(nameMap)) {
    if (cluster.signature.toLowerCase().includes(key)) {
      name = value;
      break;
    }
  }

  const concepts = [...cluster.concepts];
  const concept = concepts[0] || 'General';

  const instructorMsg = `Detected "${cluster.signature}" in student code. ${cluster.occurrences} occurrences across ${cluster.uniqueStudents.size} students.`;
  const studentMsg = cluster.rawExamples[0] || 'Check your code for this compiler error.';

  return {
    id,
    name,
    description: cluster.rawExamples[0] || cluster.signature,
    concept,
    detector_type: 'compiler_error_keyword',
    match_keywords: extractKeywords(cluster.signature),
    confidence: Math.round(validation.precision * 100),
    coverage: {
      total_occurrences: cluster.occurrences,
      unique_students: cluster.uniqueStudents.size,
      exercises_affected: [...cluster.uniqueExercises],
      concepts_affected: concepts
    },
    suggested_instructor_message: instructorMsg,
    suggested_student_message: studentMsg,
    validation: {
      true_positives: validation.truePositives,
      false_positives: validation.falsePositives,
      precision: validation.precision,
      recall: validation.recall,
      validated_at: new Date().toISOString()
    }
  };
}

module.exports = {
  extractKeywords,
  validateCluster,
  generateCandidate
};
