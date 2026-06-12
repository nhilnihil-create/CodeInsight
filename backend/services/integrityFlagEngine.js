/**
 * backend/services/integrityFlagEngine.js
 *
 * Multi-vector plagiarism detection engine.
 *
 * Vectors:
 *   1. PEER_PLAGIARISM        — sliding-window AST hash intersection between
 *                                students' submissions on the same exercise
 *   2. EXTERNAL_SOURCE_LEAK   — match against codenet_benchmarks table
 *   3. INSTRUCTOR_COPY_PASTE  — structural match with exercise reference_solution
 *      gated by client-side telemetry (timeSpentSeconds, pasteCount)
 *
 * Legacy detections preserved:
 *   - detectCodeGrowthAnomaly  (0% code growth from starter)
 *   - detectRetryStorm         (>20 submissions in rapid succession)
 */

const db = require('../config/db');
const { normalizeAST, windowIntersection, matchDensity } = require('./astHasher');

// ── Thresholds ──────────────────────────────────────────────────────────────

const PEER_PLAGIARISM_THRESHOLD = 0.40;   // >40% window overlap = HIGH
const CODENET_EXACT_MATCH = true;          // exact structural hash match
const REFERENCE_MATCH_THRESHOLD = 0.85;    // >85% match with reference solution
const TRIVIAL_TELEMETRY_TIME_SEC = 5;      // below this = suspicious

// ── VECTOR 1: Peer-to-Peer Sliding Window Intersect ─────────────────────────

/**
 * Compare a submission's AST window hashes against all existing submissions
 * for the same exercise. If the intersection density exceeds the threshold,
 * flag as PEER_PLAGIARISM.
 *
 * @param {string[]} currentWindows — K-mer hashes of the current submission
 * @param {number} exerciseId
 * @param {number} studentId — exclude this student's own prior submissions
 * @param {string} currentFullHash
 * @returns {{ detected: boolean, flags: Array }}
 */
async function detectPeerPlagiarism(currentWindows, exerciseId, studentId, currentFullHash) {
  const result = { detected: false, flags: [] };

  if (!currentWindows || currentWindows.length === 0) return result;

  // Fetch all AST hashes for this exercise (excluding current student)
  const existingRes = await db.query(
    `SELECT h.id AS hash_id, h.student_id, h.full_structural_hash, h.ast_window_hashes,
            u.name AS student_name
     FROM submission_ast_hashes h
     JOIN users u ON u.id = h.student_id
     WHERE h.exercise_id = $1 AND h.student_id != $2`,
    [exerciseId, studentId]
  );

  if (existingRes.rows.length === 0) return result;

  // Group matching peers by structural hash (exact match first)
  const exactMatches = existingRes.rows.filter(r => r.full_structural_hash === currentFullHash);
  if (exactMatches.length > 0) {
    result.flags.push({
      type: 'PEER_PLAGIARISM',
      severity: 'HIGH',
      evidence: `Identical AST structure with ${exactMatches.length} other submission(s)`,
      context: {
        matchType: 'exact_structural_hash',
        matchedStudents: exactMatches.map(r => ({ id: r.student_id, name: r.student_name })),
        currentFullHash,
      },
    });
    result.detected = true;
    return result;
  }

  // Sliding-window partial overlap check
  let bestOverlap = 0;
  let bestMatch = null;

  for (const row of existingRes.rows) {
    const peerWindows = typeof row.ast_window_hashes === 'string'
      ? JSON.parse(row.ast_window_hashes)
      : row.ast_window_hashes;

    if (!Array.isArray(peerWindows) || peerWindows.length === 0) continue;

    const density = matchDensity(currentWindows, peerWindows);
    if (density > bestOverlap) {
      bestOverlap = density;
      bestMatch = { studentId: row.student_id, studentName: row.student_name };
    }
  }

  if (bestOverlap > PEER_PLAGIARISM_THRESHOLD && bestMatch) {
    result.flags.push({
      type: 'PEER_PLAGIARISM',
      severity: 'HIGH',
      evidence: `${Math.round(bestOverlap * 100)}% structural window overlap with another student`,
      context: {
        matchType: 'sliding_window_partial',
        overlapPercent: Math.round(bestOverlap * 100),
        threshold: PEER_PLAGIARISM_THRESHOLD,
        matchedStudent: bestMatch,
        currentWindowsCount: currentWindows.length,
      },
    });
    result.detected = true;
  }

  return result;
}

// ── VECTOR 2: CodeNet Archival Benchmark Check ──────────────────────────────

/**
 * Compare the submission's structural hash and window hashes against the
 * codenet_benchmarks table.
 *
 * @param {string} fullHash
 * @param {string[]} windows
 * @returns {{ detected: boolean, flags: Array }}
 */
async function detectCodeNetMatch(fullHash, windows) {
  const result = { detected: false, flags: [] };

  if (!fullHash) return result;

  // Exact structural hash match against benchmarks
  const exactRes = await db.query(
    `SELECT problem_code, concept_tag
     FROM codenet_benchmarks
     WHERE structural_hash = $1`,
    [fullHash]
  );

  if (exactRes.rows.length > 0) {
    const matches = exactRes.rows.map(r => `${r.problem_code} (${r.concept_tag})`);
    result.flags.push({
      type: 'EXTERNAL_SOURCE_LEAK',
      severity: 'HIGH',
      evidence: `Exact structural match with CodeNet benchmark: ${matches.join(', ')}`,
      context: {
        matchType: 'exact_codenet_hash',
        benchmarks: exactRes.rows,
        fullHash,
      },
    });
    result.detected = true;
    return result;
  }

  // Partial window match against benchmarks (any benchmark with >50% window overlap)
  if (windows && windows.length > 0) {
    const benchRes = await db.query(
      `SELECT id, problem_code, concept_tag, structural_hash, window_hashes
       FROM codenet_benchmarks`
    );

    let bestOverlap = 0;
    let bestMatch = null;

    for (const bench of benchRes.rows) {
      const benchWindows = typeof bench.window_hashes === 'string'
        ? JSON.parse(bench.window_hashes)
        : bench.window_hashes;

      if (!Array.isArray(benchWindows) || benchWindows.length === 0) continue;

      const density = matchDensity(windows, benchWindows);
      if (density > bestOverlap) {
        bestOverlap = density;
        bestMatch = bench;
      }
    }

    if (bestOverlap > 0.50 && bestMatch) {
      result.flags.push({
        type: 'EXTERNAL_SOURCE_LEAK',
        severity: 'MEDIUM',
        evidence: `${Math.round(bestOverlap * 100)}% structural overlap with CodeNet benchmark ${bestMatch.problem_code}`,
        context: {
          matchType: 'partial_codenet_windows',
          overlapPercent: Math.round(bestOverlap * 100),
          benchmark: { problemCode: bestMatch.problem_code, conceptTag: bestMatch.concept_tag },
        },
      });
      result.detected = true;
    }
  }

  return result;
}

// ── VECTOR 3: Instructor Reference Conformance & Telemetry Gate ─────────────

/**
 * Compare submission's structural hash against the exercise's reference_solution.
 * Gate the flag by client-side telemetry:
 *   - HIGH complexity + time < 5s + no keystrokes → INSTRUCTOR_COPY_PASTE
 *   - HIGH complexity + time >= 5s → benign EXERCISE_CONFORMANCE
 *   - LOW complexity match → suppress flag
 *
 * @param {string} studentCode
 * @param {string} referenceSolution
 * @param {object} telemetry — { timeSpentSeconds, pasteCount, tabSwitchCount }
 * @returns {{ detected: boolean, flags: Array }}
 */
function detectReferenceConformance(studentCode, referenceSolution, telemetry) {
  const result = { detected: false, flags: [] };

  if (!referenceSolution || !studentCode) return result;

  const studentHash = normalizeAST(studentCode, 'cpp');
  const refHash = normalizeAST(referenceSolution, 'cpp');

  const similarity = matchDensity(studentHash.windows, refHash.windows);

  // Suppress trivial matches (e.g., both are just `#include <iostream>`)
  if (studentHash.structuralTokens.length < 3 || refHash.structuralTokens.length < 3) {
    return result; // too few structural tokens to be meaningful
  }

  if (similarity < REFERENCE_MATCH_THRESHOLD) return result;

  const timeSec = (telemetry && telemetry.timeSpentSeconds) || 0;
  const pasteCount = (telemetry && telemetry.pasteCount) || 0;
  const complexity = studentHash.structuralTokens.length;

  // Low-complexity match → suppress (trivial template setup)
  if (complexity < 8) {
    return result;
  }

  // High complexity + zero time / paste → flag
  if (timeSec < TRIVIAL_TELEMETRY_TIME_SEC && pasteCount > 0) {
    result.flags.push({
      type: 'INSTRUCTOR_COPY_PASTE',
      severity: 'HIGH',
      evidence: `${Math.round(similarity * 100)}% match with reference solution, submitted in ${timeSec}s with pasteCount=${pasteCount}`,
      context: {
        matchType: 'reference_conformance',
        similarityPercent: Math.round(similarity * 100),
        timeSpentSeconds: timeSec,
        pasteCount,
        structuralComplexity: complexity,
        studentFullHash: studentHash.fullHash,
        referenceFullHash: refHash.fullHash,
      },
    });
    result.detected = true;
    return result;
  }

  // Honest "Clean Room" — log but don't flag
  if (timeSec >= TRIVIAL_TELEMETRY_TIME_SEC) {
    // Store as benign conformance record (not a flag)
    result.benignConformance = {
      type: 'EXERCISE_CONFORMANCE',
      evidence: `Structural match with reference (${Math.round(similarity * 100)}%) in ${timeSec}s`,
      similarityPercent: Math.round(similarity * 100),
    };
  }

  return result;
}

// ── AST Hash Persistence ────────────────────────────────────────────────────

/**
 * Save the submission's AST hashes to the database for future peer comparisons.
 * Uses ON CONFLICT DO UPDATE to keep the latest window hashes.
 */
async function persistASTHashes(submissionId, exerciseId, studentId, astResult) {
  try {
    await db.query(
      `INSERT INTO submission_ast_hashes
        (submission_id, exercise_id, student_id, ast_window_hashes, full_structural_hash, language)
       VALUES ($1, $2, $3, $4, $5, $6)
       ON CONFLICT ON CONSTRAINT uq_exercise_student
       DO UPDATE SET
         ast_window_hashes = EXCLUDED.ast_window_hashes,
         full_structural_hash = EXCLUDED.full_structural_hash,
         submission_id = EXCLUDED.submission_id`,
      [
        submissionId,
        exerciseId,
        studentId,
        JSON.stringify(astResult.windows),
        astResult.fullHash,
        'cpp',
      ]
    );
  } catch (err) {
    console.warn('Failed to persist AST hashes:', err.message);
  }
}

// ── PARSER BYPASS Flag ─────────────────────────────────────────────────────

/**
 * Create a high-severity audit flag when the AST parser fell back to regex
 * tokenization due to complex or adversarial code.
 */
function createParserBypassFlag(parseError) {
  return {
    type: 'PARSER_BYPASS_ATTEMPT',
    severity: 'HIGH',
    evidence: `Tree-Sitter parser failed: ${parseError}. Submission analyzed via regex fallback.`,
    context: { parseError, analyzerUsed: 'regex_fallback' },
  };
}

// ── Legacy Detections (preserved) ───────────────────────────────────────────

function detectCodeGrowthAnomaly(code, starterCode) {
  const normalize = (str) => str.replace(/\s+/g, ' ').trim();
  const normalizedCode = normalize(code);
  const normalizedStarter = normalize(starterCode);
  const codeDelta = normalizedCode.length - normalizedStarter.length;
  const growthPercent = starterCode.length > 0
    ? (codeDelta / starterCode.length) * 100
    : 0;
  const detected = codeDelta === 0 && normalizedCode === normalizedStarter;

  return {
    detected,
    growthDelta: growthPercent,
    lineCountDelta: code.split('\n').length - starterCode.split('\n').length,
    details: detected
      ? 'Submitted starter code without modification'
      : `Code growth: ${growthPercent > 0 ? '+' : ''}${Math.round(growthPercent)}%`
  };
}

function detectRetryStorm(submissions) {
  if (submissions.length < 5) {
    return { detected: false, totalRetries: submissions.length, avgTimeBetween: null };
  }

  const timedeltas = [];
  for (let i = 1; i < submissions.length; i++) {
    const prev = new Date(submissions[i - 1].submitted_at).getTime();
    const curr = new Date(submissions[i].submitted_at).getTime();
    timedeltas.push((curr - prev) / 1000 / 60);
  }

  const avgTime = timedeltas.reduce((a, b) => a + b, 0) / timedeltas.length;
  const detected = submissions.length > 20 && avgTime < 3;

  return {
    detected,
    totalRetries: submissions.length,
    avgTimeBetween: Math.round(avgTime * 10) / 10,
  };
}

function generateContextBehaviors(submission, allSubmissions) {
  const behaviors = [];

  const codeLength = (submission.code || '').length;
  if (codeLength > 200) {
    const estimatedTypingTime = codeLength / 40;
    if (submission.time_spent_seconds && submission.time_spent_seconds < estimatedTypingTime * 60 * 0.3) {
      behaviors.push('Code appeared fully-formed in single paste (no incremental edits)');
    }
  }

  if (submission.time_spent_seconds && submission.time_spent_seconds < 20) {
    behaviors.push(`Time to completion: ${submission.time_spent_seconds} seconds (typical: 5+ minutes)`);
  }

  if (allSubmissions.length > 5) {
    const recentSubmissions = allSubmissions.slice(-5);
    const timedeltas = [];
    for (let i = 1; i < recentSubmissions.length; i++) {
      const prev = new Date(recentSubmissions[i - 1].submitted_at).getTime();
      const curr = new Date(recentSubmissions[i].submitted_at).getTime();
      timedeltas.push((curr - prev) / 1000 / 60);
    }
    const avgTime = timedeltas.reduce((a, b) => a + b, 0) / timedeltas.length;
    if (avgTime < 2) {
      behaviors.push(`Rapid consecutive submissions (avg ${avgTime.toFixed(1)}min apart)`);
    }
  }

  return behaviors;
}

// ── createFlag (unchanged) ──────────────────────────────────────────────────

async function createFlag(flagData) {
  const { sectionId, exerciseId, studentId, flagType, severity, evidence, contextBehaviors, status, submissionId } = flagData;

  try {
    const result = await db.query(
      `INSERT INTO integrity_flags
       (section_id, exercise_id, student_id, flag_type, severity, evidence, context_behaviors, status, created_at, submission_id)
       VALUES ($1, $2, $3, $4, $5, $6, $7, $8, NOW(), $9)
       ON CONFLICT (exercise_id, student_id, flag_type)
       DO UPDATE SET
         severity = EXCLUDED.severity,
         evidence = EXCLUDED.evidence,
         context_behaviors = EXCLUDED.context_behaviors,
         submission_id = EXCLUDED.submission_id
       RETURNING *`,
      [sectionId, exerciseId, studentId, flagType, severity,
       JSON.stringify(evidence), contextBehaviors, status || 'flagged', submissionId || null]
    );

    return result.rows[0];
  } catch (err) {
    console.error('Error creating integrity flag:', err);
    throw err;
  }
}

// ── Query helpers (unchanged) ───────────────────────────────────────────────

async function getFlagsForExercise(exerciseId) {
  try {
    const result = await db.query(
      `SELECT f.*, u.name AS student_name
       FROM integrity_flags f
       JOIN users u ON f.student_id = u.id
       WHERE f.exercise_id = $1
       ORDER BY f.severity DESC, f.created_at DESC`,
      [exerciseId]
    );

    return result.rows.map(row => ({
      ...row,
      evidence: typeof row.evidence === 'string' ? JSON.parse(row.evidence) : row.evidence,
    }));
  } catch (err) {
    console.error('Error fetching integrity flags:', err);
    throw err;
  }
}

async function getFlagsForSection(sectionId) {
  try {
    const result = await db.query(
      `SELECT f.*, u.name AS student_name, e.title AS exercise_title
       FROM integrity_flags f
       JOIN users u ON f.student_id = u.id
       JOIN exercises e ON f.exercise_id = e.id
       WHERE f.section_id = $1
       ORDER BY e.id, f.severity DESC, f.created_at DESC`,
      [sectionId]
    );

    const grouped = {};
    result.rows.forEach(row => {
      if (!grouped[row.exercise_id]) {
        grouped[row.exercise_id] = {
          exerciseId: row.exercise_id,
          exerciseTitle: row.exercise_title,
          flags: []
        };
      }
      grouped[row.exercise_id].flags.push({
        ...row,
        evidence: typeof row.evidence === 'string' ? JSON.parse(row.evidence) : row.evidence,
      });
    });

    return Object.values(grouped);
  } catch (err) {
    console.error('Error fetching section flags:', err);
    throw err;
  }
}

async function markFlagReviewed(flagId, instructorNote = null) {
  try {
    const result = await db.query(
      `UPDATE integrity_flags
       SET status = 'reviewed', reviewed_at = NOW(), instructor_note = $2
       WHERE id = $1
       RETURNING *`,
      [flagId, instructorNote]
    );
    return result.rows[0];
  } catch (err) {
    console.error('Error marking flag reviewed:', err);
    throw err;
  }
}

// ── Public API ──────────────────────────────────────────────────────────────

module.exports = {
  // New multi-vector API
  detectPeerPlagiarism,
  detectCodeNetMatch,
  detectReferenceConformance,
  persistASTHashes,
  createParserBypassFlag,

  // Legacy API
  detectCodeGrowthAnomaly,
  detectRetryStorm,
  generateContextBehaviors,
  createFlag,
  getFlagsForExercise,
  getFlagsForSection,
  markFlagReviewed,
};
