/**
 * Integrity Flag Engine
 * Detects and tracks per-exercise behavioral anomalies
 * Implements academic integrity monitoring (Pillar 4 from research objectives)
 */

const db = require('../config/db');
const executorService = require('./executor');

/**
 * Flag Types:
 * 1. code_paste_detected - High similarity with reference/CodeNet solutions
 * 2. code_growth_anomaly - 0% code growth from starter template
 * 3. retry_storm - Excessive retries in short time span
 */

/**
 * Detect code paste from CodeNet or reference solutions
 * @param {string} code - Student submission code
 * @param {number} exerciseId - Exercise ID
 * @returns {Object} { detected: boolean, matchPercent: number, details: string }
 */
async function detectCodePaste(code, exerciseId) {
  try {
    // Get reference solution from exercise (if stored)
    const exerciseRes = await db.query(
      `SELECT reference_solution FROM exercises WHERE id = $1`,
      [exerciseId]
    );

    if (!exerciseRes.rows.length || !exerciseRes.rows[0].reference_solution) {
      return { detected: false, matchPercent: 0, details: 'No reference solution available' };
    }

    const refCode = exerciseRes.rows[0].reference_solution;
    const similarity = calculateSimilarity(code, refCode);

    return {
      detected: similarity > 0.70, // >70% match = paste
      matchPercent: Math.round(similarity * 100),
      details: `${Math.round(similarity * 100)}% code match with reference solution`
    };
  } catch (err) {
    console.error('Error in detectCodePaste:', err);
    return { detected: false, matchPercent: 0, details: 'Error checking code similarity' };
  }
}

/**
 * Detect code growth anomaly (zero code delta from starter template)
 * @param {string} code - Current submission code
 * @param {string} starterCode - Original starter template
 * @returns {Object} { detected: boolean, growthDelta: number, details: string }
 */
function detectCodeGrowthAnomaly(code, starterCode) {
  // Normalize code for comparison (remove whitespace differences)
  const normalize = (str) => str.replace(/\s+/g, ' ').trim();
  const normalizedCode = normalize(code);
  const normalizedStarter = normalize(starterCode);

  // Calculate code growth delta
  const codeDelta = normalizedCode.length - normalizedStarter.length;
  const growthPercent = starterCode.length > 0 
    ? (codeDelta / starterCode.length) * 100 
    : 0;

  // Anomaly: submitted starter code unchanged (0% growth)
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

/**
 * Detect retry storm (excessive submissions in short timespan)
 * @param {Array} submissions - Array of submission records ordered by date
 * @returns {Object} { detected: boolean, totalRetries: number, avgTimeBetween: number }
 */
function detectRetryStorm(submissions) {
  if (submissions.length < 5) {
    return { detected: false, totalRetries: submissions.length, avgTimeBetween: null };
  }

  // Calculate time deltas between consecutive submissions
  const timedeltas = [];
  for (let i = 1; i < submissions.length; i++) {
    const prev = new Date(submissions[i - 1].submitted_at).getTime();
    const curr = new Date(submissions[i].submitted_at).getTime();
    timedeltas.push((curr - prev) / 1000 / 60); // Convert to minutes
  }

  // Average time between submissions
  const avgTime = timedeltas.reduce((a, b) => a + b, 0) / timedeltas.length;

  // Detect storm: >20 retries AND avg time <3 minutes apart
  const detected = submissions.length > 20 && avgTime < 3;

  return {
    detected,
    totalRetries: submissions.length,
    avgTimeBetween: Math.round(avgTime * 10) / 10, // 1 decimal place
    firstSubmittedAt: submissions[0].submitted_at,
    lastSubmittedAt: submissions[submissions.length - 1].submitted_at
  };
}

/**
 * Generate context behaviors for a student's exercise interaction
 * @param {Object} submission - Single submission record
 * @param {Array} allSubmissions - All submissions by student for this exercise
 * @returns {Array} Array of behavior strings
 */
function generateContextBehaviors(submission, allSubmissions) {
  const behaviors = [];

  // Check if code appeared fully-formed (single large paste)
  const codeLength = (submission.code || '').length;
  if (codeLength > 200) {
    const estimatedTypingTime = codeLength / 40; // 40 chars per minute typing speed
    if (submission.time_spent_seconds && submission.time_spent_seconds < estimatedTypingTime * 60 * 0.3) {
      behaviors.push('Code appeared fully-formed in single paste (no incremental edits)');
    }
  }

  // Time to completion unusually fast
  if (submission.time_spent_seconds && submission.time_spent_seconds < 20) {
    behaviors.push(`Time to completion: ${submission.time_spent_seconds} seconds (typical: 5+ minutes)`);
  }

  // No compilation attempts before submission
  const compErrors = (submission.compilation_errors || []).length;
  if (compErrors === 0 && submission.is_correct) {
    behaviors.push('No compilation attempts before submission');
  }

  // Rapid consecutive submissions
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

/**
 * Create or update an integrity flag for a student's submission
 * @param {Object} flagData - Flag details
 * @returns {Object} Created/updated flag record
 */
async function createFlag(flagData) {
  const { sectionId, exerciseId, studentId, flagType, severity, evidence, contextBehaviors, status } = flagData;

  try {
    const result = await db.query(
      `INSERT INTO integrity_flags 
       (section_id, exercise_id, student_id, flag_type, severity, evidence, context_behaviors, status, created_at)
       VALUES ($1, $2, $3, $4, $5, $6, $7, $8, NOW())
       ON CONFLICT (exercise_id, student_id, flag_type)
       DO UPDATE SET
         severity = EXCLUDED.severity,
         evidence = EXCLUDED.evidence,
         context_behaviors = EXCLUDED.context_behaviors,
         status = CASE WHEN status = 'reviewed' THEN 'reviewed' ELSE EXCLUDED.status END
       RETURNING *`,
      [sectionId, exerciseId, studentId, flagType, severity, 
       JSON.stringify(evidence), contextBehaviors, status || 'flagged']
    );

    return result.rows[0];
  } catch (err) {
    console.error('Error creating integrity flag:', err);
    throw err;
  }
}

/**
 * Get all flags for an exercise
 * @param {number} exerciseId - Exercise ID
 * @returns {Array} Array of flag records
 */
async function getFlagsForExercise(exerciseId) {
  try {
    const result = await db.query(
      `SELECT 
         f.*,
         u.name AS student_name
       FROM integrity_flags f
       JOIN users u ON f.student_id = u.id
       WHERE f.exercise_id = $1
       ORDER BY f.severity DESC, f.created_at DESC`,
      [exerciseId]
    );

    return result.rows.map(row => ({
      ...row,
      evidence: typeof row.evidence === 'string' ? JSON.parse(row.evidence) : row.evidence
    }));
  } catch (err) {
    console.error('Error fetching integrity flags:', err);
    throw err;
  }
}

/**
 * Get all flags for a section
 * @param {number} sectionId - Section ID
 * @returns {Object} Flags grouped by exercise
 */
async function getFlagsForSection(sectionId) {
  try {
    const result = await db.query(
      `SELECT 
         f.*,
         u.name AS student_name,
         e.title AS exercise_title
       FROM integrity_flags f
       JOIN users u ON f.student_id = u.id
       JOIN exercises e ON f.exercise_id = e.id
       WHERE f.section_id = $1
       ORDER BY e.id, f.severity DESC, f.created_at DESC`,
      [sectionId]
    );

    // Group by exercise_id
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
        evidence: typeof row.evidence === 'string' ? JSON.parse(row.evidence) : row.evidence
      });
    });

    return Object.values(grouped);
  } catch (err) {
    console.error('Error fetching section flags:', err);
    throw err;
  }
}

/**
 * Mark a flag as reviewed
 * @param {number} flagId - Flag ID
 * @param {string} instructorNote - Optional note from instructor
 * @returns {Object} Updated flag record
 */
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

/**
 * Simple string similarity calculation (Levenshtein-inspired)
 * Returns 0-1 similarity score
 */
function calculateSimilarity(str1, str2) {
  const normalize = (s) => s.replace(/\s+/g, '').toLowerCase();
  const s1 = normalize(str1);
  const s2 = normalize(str2);

  // If both empty, they're identical
  if (s1.length === 0 && s2.length === 0) return 1;

  // Use simple character overlap as similarity metric
  const longer = s1.length > s2.length ? s1 : s2;
  const shorter = s1.length > s2.length ? s2 : s1;

  let matches = 0;
  let idx = 0;
  for (const char of shorter) {
    const foundIdx = longer.indexOf(char, idx);
    if (foundIdx !== -1) {
      matches++;
      idx = foundIdx + 1;
    }
  }

  return matches / longer.length;
}

module.exports = {
  detectCodePaste,
  detectCodeGrowthAnomaly,
  detectRetryStorm,
  generateContextBehaviors,
  createFlag,
  getFlagsForExercise,
  getFlagsForSection,
  markFlagReviewed
};
