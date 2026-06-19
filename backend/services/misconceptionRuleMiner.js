const db = require('../config/db');
const errorNormalizer = require('./errorNormalizer');
const errorClusterer = require('./errorClusterer');
const candidateValidator = require('./candidateValidator');
const fs = require('fs');
const path = require('path');

async function runFullPipeline({ exerciseId, minStudents = 3, minOccurrences = 5, outputPath } = {}) {
  const submissions = await db.query(
    `SELECT s.id, s.student_id, s.exercise_id, s.compiler_log, s.test_results,
            s.is_correct, e.concept_id, c.name AS concept_name
     FROM submissions s
     JOIN exercises e ON e.id = s.exercise_id
     JOIN concepts c ON c.id = e.concept_id
     WHERE s.exercise_id = $1 AND s.compiler_log IS NOT NULL`,
    [exerciseId]
  );

  const runAttempts = await db.query(
    `SELECT ra.id AS submission_id, ra.student_id, ra.exercise_id,
            ra.compiler_log, NULL AS test_results, false AS is_correct,
            e.concept_id, c.name AS concept_name
     FROM run_attempts ra
     JOIN exercises e ON e.id = ra.exercise_id
     JOIN concepts c ON c.id = e.concept_id
     WHERE ra.exercise_id = $1 AND ra.compiler_log IS NOT NULL`,
    [exerciseId]
  );

  const allSubmissions = [...submissions.rows, ...runAttempts.rows];

  if (allSubmissions.length === 0) {
    return {
      generated_at: new Date().toISOString(),
      exercise_id: exerciseId,
      total_submissions_analyzed: 0,
      total_students: 0,
      candidates: []
    };
  }

  const parsed = [];
  for (const sub of allSubmissions) {
    const errors = errorNormalizer.parseCompilerLog(
      sub.compiler_log,
      sub.id || sub.submission_id,
      sub.student_id,
      sub.exercise_id,
      sub.concept_id,
      sub.concept_name
    );
    for (const err of errors) {
      err.normalized = errorNormalizer.normalizeMessage(err.rawMessage);
      err.signature = errorNormalizer.extractSignature(err.normalized);
    }
    parsed.push(...errors);
  }

  const clusters = errorClusterer.clusterErrors(parsed);
  const ranked = errorClusterer.rankClusters(clusters, { minStudents, minOccurrences });

  const candidates = [];
  const allLogs = allSubmissions.map(s => ({
    id: s.id || s.submission_id,
    compiler_log: s.compiler_log,
    is_correct: s.is_correct
  }));

  for (const cluster of ranked) {
    const validation = candidateValidator.validateCluster(cluster, allLogs);
    if (validation.precision >= 0.85) {
      const candidate = candidateValidator.generateCandidate(cluster, validation);
      candidates.push(candidate);
    }
  }

  const totalStudents = new Set(allSubmissions.map(s => s.student_id)).size;
  const output = {
    generated_at: new Date().toISOString(),
    pipeline_version: '1.0.0',
    exercise_id: exerciseId,
    total_submissions_analyzed: allSubmissions.length,
    total_students: totalStudents,
    candidates
  };

  if (outputPath) {
    const dir = path.dirname(outputPath);
    if (!fs.existsSync(dir)) {
      fs.mkdirSync(dir, { recursive: true });
    }
    fs.writeFileSync(outputPath, JSON.stringify(output, null, 2));
  }

  return output;
}

module.exports = { runFullPipeline };
