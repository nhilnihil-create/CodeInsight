/**
 * Concept Analytics Engine — CMI, CRS, Learning Velocity, Difficulty Index
 *
 * Implements ADR-006: Pre-computed aggregate metrics for dashboard performance.
 *
 * Metrics:
 *   CMI  (Concept Mastery Index):  Per-student, per-concept 0-100%.
 *          Formula: 100 × (1 - (0.40×failRate + 0.35×normalizedAttempts + 0.25×normalizedTime))
 *          Rationale: Maps CDS components to concept-level mastery. failRate penalizes
 *          persistent errors, normalizedAttempts penalizes repetition, normalizedTime
 *          penalizes slow solutions. Weighting mirrors CDS (0.40/0.35/0.25).
 *
 *   CRS  (Concept Risk Score):     Per-section, per-concept risk classification.
 *          Formula: AVG(CDS) for all students on concept-tagged exercises.
 *          Rationale: Identifies concepts where the section as a whole struggles.
 *          Thresholds: critical (>0.70, ≥5 at-risk students), high (>0.50, ≥3),
 *          medium (>0.31), low (≤0.31). Maps to CDS thresholds for consistency.
 *
 *   Velocity (Learning Velocity):  Per-student, per-concept weekly CMI change.
 *          Formula: (CMI_recent - CMI_baseline) / weeks_between
 *          Rationale: Distinguishes "weak but improving" from "weak and stagnant".
 *          Positive = improving, negative = declining, near-zero = plateau.
 *          Requires ≥2 concept-tagged exercises per concept.
 *
 *   Difficulty Index:              Data-driven exercise difficulty (0-1).
 *          Formula: (1 - passRate) × 0.40 + normAvgAttempts × 0.35 + normAvgTime × 0.25
 *          Rationale: Self-correcting difficulty — an exercise marked "beginner"
 *          that students struggle with will show a higher difficulty index.
 *          Recalculated on exercise close alongside batch CDS.
 *
 * CDS COMPATIBILITY:
 *   - All functions read from cds_scores (read-only) and submissions
 *   - CMI/CRS write only to student_concept_metrics / section_concept_metrics
 *   - Difficulty Index writes only to exercises.difficulty_index
 *   - No modifications to cds_scores, cds_snapshots, or alerts tables
 *
 * Integration:
 *   - computeAllMetrics(sectionId) — batch recalculation on exercise close
 *   - updateMetricsForSubmission(studentId, exerciseId) — live approximation
 */

const db = require('../config/db');

// ─────────────────────────────────────────────────────────────────────────────
// CMI (Concept Mastery Index)
// ─────────────────────────────────────────────────────────────────────────────

/**
 * Compute Concept Mastery Index for all students in a section.
 *
 * For each student × concept pair:
 *   1. Gather all submissions for exercises tagged with that concept
 *   2. Compute failRate, normalizedAttempts, normalizedTime (class-relative)
 *   3. Apply CMI formula: 100 × (1 - (0.40×failRate + 0.35×normAttempts + 0.25×normTime))
 *
 * @param {number} sectionId - Section to compute metrics for
 * @param {Object} [dbClient] - Optional DB client for transaction
 * @returns {Promise<{updated: number}>}
 */
async function computeCMI(sectionId, dbClient) {
  const client = dbClient || db;

  // Get all concepts that have exercises in this section
  const conceptRes = await client.query(
    `SELECT DISTINCT c.id, c.name
     FROM concepts c
     JOIN exercise_concept_tags ect ON ect.concept_id = c.id
     JOIN exercises e ON e.id = ect.exercise_id
     WHERE e.section_id = $1 AND ect.is_primary = true`,
    [sectionId]
  );

  if (conceptRes.rows.length === 0) {
    return { updated: 0 };
  }

  // Get all students in this section
  const studentRes = await client.query(
    `SELECT DISTINCT u.id FROM users u
     JOIN enrollments e ON e.student_id = u.id
     WHERE e.section_id = $1`,
    [sectionId]
  );

  if (studentRes.rows.length === 0) {
    return { updated: 0 };
  }

  let updated = 0;

  for (const concept of conceptRes.rows) {
    // Get all exercises in this section tagged with this concept (primary)
    const exerciseRes = await client.query(
      `SELECT DISTINCT e.id, e.title
       FROM exercises e
       JOIN exercise_concept_tags ect ON ect.exercise_id = e.id
       WHERE e.section_id = $1 AND ect.concept_id = $2 AND ect.is_primary = true`,
      [sectionId, concept.id]
    );

    if (exerciseRes.rows.length === 0) continue;

    const exerciseIds = exerciseRes.rows.map(r => r.id);

    // For each student, compute per-concept metrics
    for (const student of studentRes.rows) {
      try {
        // Get this student's submissions for concept-tagged exercises
        const subRes = await client.query(
          `SELECT s.student_id, s.exercise_id,
                  s.attempt_number, s.is_correct, s.time_spent_seconds,
                  COUNT(*) OVER (PARTITION BY s.exercise_id) AS total_submissions_for_exercise,
                  SUM(CASE WHEN s.is_correct THEN 1 ELSE 0 END) OVER (PARTITION BY s.exercise_id) AS correct_count_for_exercise
           FROM submissions s
           WHERE s.student_id = $1
             AND s.exercise_id = ANY($2)
             AND s.is_practice IS NOT TRUE
           ORDER BY s.exercise_id, s.attempt_number ASC`,
          [student.id, exerciseIds]
        );

        if (subRes.rows.length === 0) continue;

        // Aggregate per-exercise metrics, then average across concept
        const exerciseMetrics = {};
        for (const row of subRes.rows) {
          const eid = row.exercise_id;
          if (!exerciseMetrics[eid]) {
            exerciseMetrics[eid] = {
              total_attempts: parseInt(row.total_submissions_for_exercise),
              failed_attempts: parseInt(row.total_submissions_for_exercise) - parseInt(row.correct_count_for_exercise),
              max_time: 0
            };
          }
          exerciseMetrics[eid].max_time = Math.max(
            exerciseMetrics[eid].max_time,
            row.time_spent_seconds || 0
          );
        }

        const metrics = Object.values(exerciseMetrics);
        const totalAttempts = metrics.reduce((s, m) => s + m.total_attempts, 0);
        const totalFailed = metrics.reduce((s, m) => s + m.failed_attempts, 0);
        const maxTime = metrics.reduce((s, m) => Math.max(s, m.max_time), 0);

        const failRate = totalAttempts > 0 ? totalFailed / totalAttempts : 0;

        // Get class-wide normalization factors (same exercise set)
        const classStats = await client.query(
          `SELECT s.student_id,
                  COUNT(*) AS total_attempts,
                  SUM(CASE WHEN s.is_correct = false THEN 1 ELSE 0 END) AS failed_attempts,
                  MAX(s.time_spent_seconds) AS max_time
           FROM submissions s
           WHERE s.exercise_id = ANY($1)
             AND s.is_practice IS NOT TRUE
           GROUP BY s.student_id`,
          [exerciseIds]
        );

        const allAttempts = classStats.rows.map(r => parseInt(r.total_attempts));
        const allFailed = classStats.rows.map(r => parseInt(r.failed_attempts));
        const allTimes = classStats.rows.map(r => parseInt(r.max_time) || 0);

        const normAttempts = _normalize(totalAttempts, allAttempts);
        const normTime = _normalize(maxTime, allTimes);

        // CMI formula
        const cmi = Math.round(
          100 * (1 - (0.40 * failRate + 0.35 * normAttempts + 0.25 * normTime))
        );
        const boundedCmi = Math.max(0, Math.min(100, cmi));

        await client.query(
          `INSERT INTO student_concept_metrics (student_id, concept_id, section_id, cmi, velocity, last_updated)
           VALUES ($1, $2, $3, $4, 0, NOW())
           ON CONFLICT (student_id, concept_id, section_id)
           DO UPDATE SET cmi = $4, last_updated = NOW()`,
          [student.id, concept.id, sectionId, boundedCmi]
        );

        updated++;
      } catch (err) {
        console.warn(`[CMI] Failed for student ${student.id}, concept ${concept.name}:`, err.message);
      }
    }
  }

  return { updated };
}

// ─────────────────────────────────────────────────────────────────────────────
// Learning Velocity
// ─────────────────────────────────────────────────────────────────────────────

/**
 * Compute learning velocity for all student-concept pairs in a section.
 *
 * Velocity = (CMI_recent - CMI_baseline) / weeks_between
 *   CMI_recent = average CMI from last 2 concept-tagged exercises
 *   CMI_baseline = average CMI from first 2 concept-tagged exercises
 *   weeks_between = time span between first and last exercise in weeks
 *
 * Requires ≥2 concept-tagged exercises per concept for meaningful velocity.
 *
 * @param {number} sectionId
 * @param {Object} [dbClient]
 * @returns {Promise<{updated: number}>}
 */
async function computeVelocity(sectionId, dbClient) {
  const client = dbClient || db;

  // Get concepts with ≥2 exercises in this section
  const conceptRes = await client.query(
    `SELECT c.id, c.name, COUNT(DISTINCT e.id) AS exercise_count
     FROM concepts c
     JOIN exercise_concept_tags ect ON ect.concept_id = c.id
     JOIN exercises e ON e.id = ect.exercise_id
     WHERE e.section_id = $1 AND ect.is_primary = true
     GROUP BY c.id, c.name
     HAVING COUNT(DISTINCT e.id) >= 2`,
    [sectionId]
  );

  if (conceptRes.rows.length === 0) {
    return { updated: 0 };
  }

  let updated = 0;

  for (const concept of conceptRes.rows) {
    // Get exercises tagged with this concept, ordered by time
    const exerciseRes = await client.query(
      `SELECT DISTINCT e.id, e.created_at
       FROM exercises e
       JOIN exercise_concept_tags ect ON ect.exercise_id = e.id
       WHERE e.section_id = $1 AND ect.concept_id = $2 AND ect.is_primary = true
       ORDER BY e.created_at ASC`,
      [sectionId, concept.id]
    );

    if (exerciseRes.rows.length < 2) continue;

    const exerciseIds = exerciseRes.rows.map(r => r.id);

    // For each student, compute velocity
    const studentRes = await client.query(
      `SELECT DISTINCT s.student_id FROM submissions s
       WHERE s.exercise_id = ANY($1) AND s.is_practice IS NOT TRUE`,
      [exerciseIds]
    );

    for (const student of studentRes.rows) {
      try {
        // Get per-exercise CMI proxy: 100 × (1 - failRate) for each exercise
        const exCmiRes = await client.query(
          `SELECT s.exercise_id,
                  COUNT(*) AS total,
                  SUM(CASE WHEN s.is_correct THEN 1 ELSE 0 END) AS correct,
                  MAX(s.submitted_at) AS last_submission
           FROM submissions s
           WHERE s.student_id = $1
             AND s.exercise_id = ANY($2)
             AND s.is_practice IS NOT TRUE
           GROUP BY s.exercise_id
           ORDER BY MAX(s.submitted_at) ASC`,
          [student.id, exerciseIds]
        );

        if (exCmiRes.rows.length < 2) continue;

        const exCmis = exCmiRes.rows.map(r => {
          const total = parseInt(r.total);
          const correct = parseInt(r.correct);
          return {
            exerciseId: r.exercise_id,
            cmi: total > 0 ? (correct / total) * 100 : 0,
            submittedAt: r.last_submission
          };
        });

        // Baseline: first 2 exercises, Recent: last 2
        const baselineCount = Math.min(2, Math.floor(exCmis.length / 2));
        const recentCount = Math.min(2, exCmis.length - baselineCount);

        if (baselineCount < 1 || recentCount < 1) continue;

        const baseline = exCmis.slice(0, baselineCount);
        const recent = exCmis.slice(-recentCount);

        const baselineAvg = baseline.reduce((s, e) => s + e.cmi, 0) / baseline.length;
        const recentAvg = recent.reduce((s, e) => s + e.cmi, 0) / recent.length;

        // Time span in weeks
        const firstDate = new Date(baseline[0].submittedAt);
        const lastDate = new Date(recent[recent.length - 1].submittedAt);
        const weeksBetween = Math.max(0.1, (lastDate - firstDate) / (7 * 24 * 60 * 60 * 1000));

        const velocity = (recentAvg - baselineAvg) / weeksBetween;
        const roundedVelocity = Math.round(velocity * 100) / 100;

        await client.query(
          `UPDATE student_concept_metrics
           SET velocity = $1, last_updated = NOW()
           WHERE student_id = $2 AND concept_id = $3 AND section_id = $4`,
          [roundedVelocity, student.id, concept.id, sectionId]
        );

        updated++;
      } catch (err) {
        console.warn(`[Velocity] Failed for student ${student.id}, concept ${concept.name}:`, err.message);
      }
    }
  }

  return { updated };
}

// ─────────────────────────────────────────────────────────────────────────────
// CRS (Concept Risk Score)
// ─────────────────────────────────────────────────────────────────────────────

/**
 * Compute Concept Risk Score for all concepts in a section.
 *
 * CRS_score = AVG(CDS) for all students on concept-tagged exercises
 * Classification: critical (>0.70, ≥5 at-risk), high (>0.50, ≥3), medium (>0.31), low (≤0.31)
 *
 * @param {number} sectionId
 * @param {Object} [dbClient]
 * @returns {Promise<{updated: number}>}
 */
async function computeCRS(sectionId, dbClient) {
  const client = dbClient || db;

  // Get all concepts with exercises in this section
  const conceptRes = await client.query(
    `SELECT c.id, c.name
     FROM concepts c
     JOIN exercise_concept_tags ect ON ect.concept_id = c.id
     JOIN exercises e ON e.id = ect.exercise_id
     WHERE e.section_id = $1 AND ect.is_primary = true`,
    [sectionId]
  );

  if (conceptRes.rows.length === 0) {
    return { updated: 0 };
  }

  let updated = 0;

  for (const concept of conceptRes.rows) {
    // Get exercises tagged with this concept
    const exerciseRes = await client.query(
      `SELECT DISTINCT e.id FROM exercises e
       JOIN exercise_concept_tags ect ON ect.exercise_id = e.id
       WHERE e.section_id = $1 AND ect.concept_id = $2 AND ect.is_primary = true`,
      [sectionId, concept.id]
    );

    if (exerciseRes.rows.length === 0) continue;

    const exerciseIds = exerciseRes.rows.map(r => r.id);

    // Get average CDS for students who attempted these exercises
    const cdsRes = await client.query(
      `SELECT COUNT(DISTINCT cs.student_id) AS student_count,
              AVG(cs.cds) AS avg_cds,
              COUNT(DISTINCT cs.student_id) FILTER (WHERE cs.cds > 0.31) AS at_risk_count
       FROM cds_scores cs
       WHERE cs.exercise_id = ANY($1)
         AND cs.cds IS NOT NULL`,
      [exerciseIds]
    );

    if (cdsRes.rows.length === 0) continue;

    const row = cdsRes.rows[0];
    const studentCount = parseInt(row.student_count);
    const crsScore = row.avg_cds ? parseFloat(row.avg_cds) : 0;
    const atRiskCount = parseInt(row.at_risk_count);

    // Classify risk level
    const crs = _classifyCRS(crsScore, atRiskCount);

    await client.query(
      `INSERT INTO section_concept_metrics
       (section_id, concept_id, crs, crs_score, difficulty_index, student_count, at_risk_count, last_updated)
       VALUES ($1, $2, $3, $4, 0, $5, $6, NOW())
       ON CONFLICT (section_id, concept_id)
       DO UPDATE SET crs = $3, crs_score = $4, student_count = $5, at_risk_count = $6, last_updated = NOW()`,
      [sectionId, concept.id, crs, crsScore, studentCount, atRiskCount]
    );

    updated++;
  }

  return { updated };
}

/**
 * Classify CRS risk level.
 * Thresholds align with CDS classification for consistency.
 *
 * @param {number} crsScore - Average CDS (0-1)
 * @param {number} atRiskCount - Students with CDS > 0.31
 * @returns {string} Risk classification
 */
function _classifyCRS(crsScore, atRiskCount) {
  if (crsScore > 0.70 && atRiskCount >= 5) return 'critical';
  if (crsScore > 0.50 && atRiskCount >= 3) return 'high';
  if (crsScore > 0.31) return 'medium';
  return 'low';
}

// ─────────────────────────────────────────────────────────────────────────────
// Difficulty Index
// ─────────────────────────────────────────────────────────────────────────────

/**
 * Compute data-driven difficulty index for exercises in a section.
 *
 * Formula: (1 - passRate) × 0.40 + normAvgAttempts × 0.35 + normAvgTime × 0.25
 *
 * passRate = students who solved / total students who attempted
 * normAvgAttempts = avg_attempts / max(all_exercises_avg_attempts)
 * normAvgTime = avg_time / max(all_exercises_avg_time)
 *
 * Recalculated on exercise close alongside batch CDS.
 *
 * @param {number} sectionId
 * @param {Object} [dbClient]
 * @returns {Promise<{updated: number}>}
 */
async function computeDifficultyIndex(sectionId, dbClient) {
  const client = dbClient || db;

  // Get all exercises in this section with submission data
  const exerciseRes = await client.query(
    `SELECT e.id,
            COUNT(DISTINCT s.student_id) AS students_attempted,
            COUNT(DISTINCT s.student_id) FILTER (WHERE s.is_correct = true) AS students_solved,
            AVG(s.attempt_number) AS avg_attempts,
            AVG(s.time_spent_seconds) AS avg_time
     FROM exercises e
     LEFT JOIN submissions s ON s.exercise_id = e.id AND s.is_practice IS NOT TRUE
     WHERE e.section_id = $1
     GROUP BY e.id
     HAVING COUNT(DISTINCT s.student_id) > 0`,
    [sectionId]
  );

  if (exerciseRes.rows.length === 0) {
    return { updated: 0 };
  }

  // Compute class-wide normalization factors
  const allAvgAttempts = exerciseRes.rows.map(r => parseFloat(r.avg_attempts) || 0);
  const allAvgTimes = exerciseRes.rows.map(r => parseFloat(r.avg_time) || 0);

  const maxAvgAttempts = Math.max(...allAvgAttempts, 1);
  const maxAvgTime = Math.max(...allAvgTimes, 1);

  let updated = 0;

  for (const ex of exerciseRes.rows) {
    const studentsAttempted = parseInt(ex.students_attempted);
    const studentsSolved = parseInt(ex.students_solved);
    const passRate = studentsAttempted > 0 ? studentsSolved / studentsAttempted : 0;

    const avgAttempts = parseFloat(ex.avg_attempts) || 0;
    const avgTime = parseFloat(ex.avg_time) || 0;

    const normAttempts = avgAttempts / maxAvgAttempts;
    const normTime = avgTime / maxAvgTime;

    const difficultyIndex = (1 - passRate) * 0.40 + normAttempts * 0.35 + normTime * 0.25;
    const boundedDifficulty = Math.max(0, Math.min(1, difficultyIndex));
    const roundedDifficulty = Math.round(boundedDifficulty * 10000) / 10000;

    await client.query(
      `UPDATE exercises SET difficulty_index = $1 WHERE id = $2`,
      [roundedDifficulty, ex.id]
    );

    updated++;
  }

  return { updated };
}

// ─────────────────────────────────────────────────────────────────────────────
// Batch Recalculation (triggered on exercise close)
// ─────────────────────────────────────────────────────────────────────────────

/**
 * Compute all analytics metrics for a section in a single transaction.
 *
 * Call order:
 *   1. computeBatchCDS (cdsEngine) — writes cds_scores
 *   2. computeAllMetrics — reads cds_scores, writes aggregate tables
 *   3. alertEngine.generateAlerts — reads cds_scores
 *
 * This ordering ensures CDS is computed first, analytics derive from it,
 * and alerts fire last.
 *
 * @param {number} sectionId - Section to recalculate
 * @returns {Promise<Object>} Metrics summary
 */
async function computeAllMetrics(sectionId) {
  const client = await db.connect();

  try {
    await client.query('BEGIN');

    const cmiResult = await computeCMI(sectionId, client);
    const velocityResult = await computeVelocity(sectionId, client);
    const crsResult = await computeCRS(sectionId, client);
    const difficultyResult = await computeDifficultyIndex(sectionId, client);

    await client.query('COMMIT');

    return {
      sectionId,
      cmiUpdated: cmiResult.updated,
      velocityUpdated: velocityResult.updated,
      crsUpdated: crsResult.updated,
      difficultyUpdated: difficultyResult.updated,
    };
  } catch (err) {
    await client.query('ROLLBACK');
    console.error('[ConceptAnalytics] computeAllMetrics failed:', err.message);
    throw err;
  } finally {
    client.release();
  }
}

// ─────────────────────────────────────────────────────────────────────────────
// Live Update (approximation, triggered on each submission)
// ─────────────────────────────────────────────────────────────────────────────

/**
 * Update metrics for a single student's submission (live approximation).
 *
 * This is O(1) — only updates the affected student-concept pairs.
 * Not as accurate as full batch recalculation, but provides near-real-time feedback.
 *
 * @param {number} studentId
 * @param {number} exerciseId
 * @returns {Promise<Object>} Updated metrics
 */
async function updateMetricsForSubmission(studentId, exerciseId) {
  try {
    // Get exercise section and concept tags
    const exRes = await db.query(
      `SELECT e.section_id FROM exercises e WHERE e.id = $1`,
      [exerciseId]
    );
    if (!exRes.rows.length) return { updated: false, reason: 'exercise_not_found' };

    const sectionId = exRes.rows[0].section_id;

    // Get concept tags for this exercise
    const tagRes = await db.query(
      `SELECT ect.concept_id, c.name, ect.is_primary
       FROM exercise_concept_tags ect
       JOIN concepts c ON c.id = ect.concept_id
       WHERE ect.exercise_id = $1`,
      [exerciseId]
    );

    if (!tagRes.rows.length) return { updated: false, reason: 'no_concept_tags' };

    // Update CMI for each tagged concept (approximate)
    for (const tag of tagRes.rows) {
      // Get student's submissions for this concept in this section
      const subRes = await db.query(
        `SELECT COUNT(*) AS total, SUM(CASE WHEN s.is_correct THEN 1 ELSE 0 END) AS correct,
                MAX(s.time_spent_seconds) AS max_time
         FROM submissions s
         JOIN exercise_concept_tags ect ON ect.exercise_id = s.exercise_id
         WHERE s.student_id = $1 AND ect.concept_id = $2
           AND s.is_practice IS NOT TRUE`,
        [studentId, tag.concept_id]
      );

      if (!subRes.rows.length) continue;

      const row = subRes.rows[0];
      const total = parseInt(row.total);
      const correct = parseInt(row.correct);
      const failRate = total > 0 ? (total - correct) / total : 0;
      const maxTime = parseInt(row.max_time) || 0;

      // Approximate: assume normalized values = raw values (no class-wide normalization)
      const normAttempts = Math.min(total / Math.max(total, 1), 1);
      const normTime = Math.min(maxTime / Math.max(maxTime, 1), 0.5);

      const cmi = Math.round(100 * (1 - (0.40 * failRate + 0.35 * normAttempts + 0.25 * normTime)));
      const boundedCmi = Math.max(0, Math.min(100, cmi));

      await db.query(
        `INSERT INTO student_concept_metrics (student_id, concept_id, section_id, cmi, velocity, last_updated)
         VALUES ($1, $2, $3, $4, 0, NOW())
         ON CONFLICT (student_id, concept_id, section_id)
         DO UPDATE SET cmi = $4, last_updated = NOW()`,
        [studentId, tag.concept_id, sectionId, boundedCmi]
      );
    }

    return { updated: true, conceptsUpdated: tagRes.rows.length };
  } catch (err) {
    console.warn('[ConceptAnalytics] Live update failed:', err.message);
    return { updated: false, error: err.message };
  }
}

// ─────────────────────────────────────────────────────────────────────────────
// Dashboard Query Helpers
// ─────────────────────────────────────────────────────────────────────────────

/**
 * Get CMI data for a student across all concepts in a section.
 *
 * @param {number} studentId
 * @param {number} sectionId
 * @returns {Promise<Array>} Array of concept CMI records
 */
async function getStudentCMI(studentId, sectionId) {
  const result = await db.query(
    `SELECT c.name AS concept_name, c.id AS concept_id,
            scm.cmi, scm.velocity, scm.last_updated,
            c.knowledge_area_code, c.slug, c.bloom_level
     FROM student_concept_metrics scm
     JOIN concepts c ON c.id = scm.concept_id
     WHERE scm.student_id = $1 AND scm.section_id = $2
     ORDER BY c.difficulty_tier, c.name`,
    [studentId, sectionId]
  );

  return result.rows.map(row => ({
    conceptId: parseInt(row.concept_id),
    conceptName: row.concept_name,
    cmi: parseFloat(row.cmi) || 0,
    velocity: parseFloat(row.velocity) || 0,
    knowledgeAreaCode: row.knowledge_area_code,
    slug: row.slug,
    bloomLevel: row.bloom_level,
    lastUpdated: row.last_updated,
  }));
}

/**
 * Get CRS data for a section across all concepts.
 *
 * @param {number} sectionId
 * @returns {Promise<Array>} Array of concept CRS records
 */
async function getSectionCRS(sectionId) {
  const result = await db.query(
    `SELECT c.name AS concept_name, c.id AS concept_id,
            scm.crs, scm.crs_score, scm.student_count, scm.at_risk_count,
            scm.difficulty_index, scm.last_updated,
            c.knowledge_area_code, c.slug
     FROM section_concept_metrics scm
     JOIN concepts c ON c.id = scm.concept_id
     WHERE scm.section_id = $1
     ORDER BY scm.crs_score DESC`,
    [sectionId]
  );

  return result.rows.map(row => ({
    conceptId: parseInt(row.concept_id),
    conceptName: row.concept_name,
    crs: row.crs,
    crsScore: parseFloat(row.crs_score) || 0,
    studentCount: parseInt(row.student_count) || 0,
    atRiskCount: parseInt(row.at_risk_count) || 0,
    difficultyIndex: parseFloat(row.difficulty_index) || 0,
    knowledgeAreaCode: row.knowledge_area_code,
    slug: row.slug,
    lastUpdated: row.last_updated,
  }));
}

/**
 * Get concept dependency path for diagnostic reasoning.
 * If a student struggles with a concept, trace prerequisites upward.
 *
 * @param {number} conceptId
 * @returns {Promise<Array>} Array of prerequisite concepts
 */
async function getConceptPrerequisites(conceptId) {
  // Recursive CTE for transitive closure of dependencies
  const result = await db.query(
    `WITH RECURSIVE deps AS (
       SELECT parent_concept_id, child_concept_id, weight, 1 AS depth
       FROM concept_dependencies
       WHERE child_concept_id = $1
       UNION ALL
       SELECT cd.parent_concept_id, cd.child_concept_id, cd.weight, d.depth + 1
       FROM concept_dependencies cd
       JOIN deps d ON cd.child_concept_id = d.parent_concept_id
       WHERE d.depth < 5  -- Limit depth to avoid cycles
     )
     SELECT DISTINCT c.id, c.name, c.knowledge_area_code, c.slug,
            d.weight, d.depth
     FROM deps d
     JOIN concepts c ON c.id = d.parent_concept_id
     ORDER BY d.depth DESC, c.name`,
    [conceptId]
  );

  return result.rows.map(row => ({
    conceptId: parseInt(row.id),
    conceptName: row.name,
    knowledgeAreaCode: row.knowledge_area_code,
    slug: row.slug,
    weight: parseFloat(row.weight) || 1.0,
    depth: parseInt(row.depth),
  }));
}

// ─────────────────────────────────────────────────────────────────────────────
// Utility
// ─────────────────────────────────────────────────────────────────────────────

/**
 * Normalize a value against an array of class-wide values.
 * Uses min-max normalization with floor at 0.
 *
 * @param {number} value
 * @param {number[]} allValues
 * @returns {number} Normalized value [0, 1]
 */
function _normalize(value, allValues) {
  if (allValues.length === 0) return 0;
  const max = Math.max(...allValues, 1);
  return Math.min(value / max, 1.0);
}

// ─────────────────────────────────────────────────────────────────────────────
// Exports
// ─────────────────────────────────────────────────────────────────────────────

module.exports = {
  // Batch computation
  computeAllMetrics,
  computeCMI,
  computeVelocity,
  computeCRS,
  computeDifficultyIndex,

  // Live update
  updateMetricsForSubmission,

  // Dashboard queries
  getStudentCMI,
  getSectionCRS,
  getConceptPrerequisites,
};
