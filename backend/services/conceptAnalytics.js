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
 *          Thresholds: critical (>0.80, ≥5 at-risk students), high (>0.60, ≥3),
 *          medium (>0.40), low (≤0.40). Maps to CDS thresholds for consistency.
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

  if (conceptRes.rows.length === 0 || studentRes.rows.length === 0) {
    return { updated: 0 };
  }

  // Pre-fetch all exercises tagged with concepts in this section
  const allExercisesRes = await client.query(
    `SELECT ect.concept_id, e.id AS exercise_id
     FROM exercises e
     JOIN exercise_concept_tags ect ON ect.exercise_id = e.id
     WHERE e.section_id = $1 AND ect.is_primary = true`,
    [sectionId]
  );

  const conceptExercises = {};
  for (const row of allExercisesRes.rows) {
    if (!conceptExercises[row.concept_id]) conceptExercises[row.concept_id] = [];
    conceptExercises[row.concept_id].push(row.exercise_id);
  }

  const allExerciseIds = [...new Set(allExercisesRes.rows.map(r => r.exercise_id))];
  if (allExerciseIds.length === 0) return { updated: 0 };

  const studentIds = studentRes.rows.map(r => r.id);

  // Batch-fetch ALL submissions for all students and exercises in this section
  const allSubsRes = await client.query(
    `SELECT s.student_id, s.exercise_id,
            s.attempt_number, s.is_correct, s.time_spent_seconds,
            COUNT(*) OVER (PARTITION BY s.exercise_id) AS total_submissions_for_exercise,
            SUM(CASE WHEN s.is_correct THEN 1 ELSE 0 END) OVER (PARTITION BY s.exercise_id) AS correct_count_for_exercise
     FROM submissions s
     WHERE s.student_id = ANY($1) AND s.exercise_id = ANY($2)
     ORDER BY s.exercise_id, s.attempt_number ASC`,
    [studentIds, allExerciseIds]
  );

  // Index submissions by (student_id, exercise_id)
  const subMap = {};
  for (const row of allSubsRes.rows) {
    const key = `${row.student_id}:${row.exercise_id}`;
    if (!subMap[key]) subMap[key] = [];
    subMap[key].push(row);
  }

  // Batch-fetch class-wide stats once per exercise set per concept
  const classStatsRes = await client.query(
    `SELECT s.exercise_id,
            COUNT(*) AS total_attempts,
            SUM(CASE WHEN s.is_correct = false THEN 1 ELSE 0 END) AS failed_attempts,
            MAX(s.time_spent_seconds) AS max_time
     FROM submissions s
     WHERE s.exercise_id = ANY($1)
     GROUP BY s.exercise_id`,
    [allExerciseIds]
  );

  const classStatsByEx = {};
  for (const row of classStatsRes.rows) {
    classStatsByEx[row.exercise_id] = {
      total_attempts: parseInt(row.total_attempts),
      failed_attempts: parseInt(row.failed_attempts),
      max_time: parseInt(row.max_time) || 0,
    };
  }

  const studentSet = new Set(studentIds);

  for (const concept of conceptRes.rows) {
    const exerciseIds = conceptExercises[concept.id];
    if (!exerciseIds || exerciseIds.length === 0) continue;

    for (const studentId of studentSet) {
      try {
        // Aggregate per-exercise metrics from pre-fetched data
        const exerciseMetrics = {};
        for (const eid of exerciseIds) {
          const key = `${studentId}:${eid}`;
          const subs = subMap[key];
          if (!subs || subs.length === 0) continue;

          const totalForExercise = parseInt(subs[0].total_submissions_for_exercise);
          const correctForExercise = parseInt(subs[0].correct_count_for_exercise);
          let maxTime = 0;
          for (const sub of subs) {
            maxTime = Math.max(maxTime, sub.time_spent_seconds || 0);
          }

          exerciseMetrics[eid] = {
            total_attempts: totalForExercise,
            failed_attempts: totalForExercise - correctForExercise,
            max_time: maxTime,
          };
        }

        const metrics = Object.values(exerciseMetrics);
        if (metrics.length === 0) continue;

        const totalAttempts = metrics.reduce((s, m) => s + m.total_attempts, 0);
        const totalFailed = metrics.reduce((s, m) => s + m.failed_attempts, 0);
        const maxTime = metrics.reduce((s, m) => Math.max(s, m.max_time), 0);

        const failRate = totalAttempts > 0 ? totalFailed / totalAttempts : 0;

        // Normalize using class-wide stats from pre-fetched data
        const allAttempts = exerciseIds.map(eid => classStatsByEx[eid]?.total_attempts || 0);
        const allFailed = exerciseIds.map(eid => classStatsByEx[eid]?.failed_attempts || 0);
        const allTimes = exerciseIds.map(eid => classStatsByEx[eid]?.max_time || 0);

        const normAttempts = _normalize(totalAttempts, allAttempts);
        const normTime = _normalize(maxTime, allTimes);

        const cmi = Math.round(
          100 * (1 - (0.40 * failRate + 0.35 * normAttempts + 0.25 * normTime))
        );
        const boundedCmi = Math.max(0, Math.min(100, cmi));

        await client.query(
          `INSERT INTO student_concept_metrics (student_id, concept_id, section_id, cmi, velocity, last_updated)
           VALUES ($1, $2, $3, $4, 0, NOW())
           ON CONFLICT (student_id, concept_id, section_id)
           DO UPDATE SET cmi = $4, last_updated = NOW()`,
          [studentId, concept.id, sectionId, boundedCmi]
        );

        updated++;
      } catch (err) {
        console.warn(`[CMI] Failed for student ${studentId}, concept ${concept.name}:`, err.message);
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

  if (conceptRes.rows.length === 0) {
    return { updated: 0 };
  }

  // Pre-fetch all exercises grouped by concept
  const allExercisesRes = await client.query(
    `SELECT ect.concept_id, e.id AS exercise_id, e.created_at
     FROM exercises e
     JOIN exercise_concept_tags ect ON ect.exercise_id = e.id
     WHERE e.section_id = $1 AND ect.is_primary = true
     ORDER BY e.created_at ASC`,
    [sectionId]
  );

  const conceptExercises = {};
  for (const row of allExercisesRes.rows) {
    if (!conceptExercises[row.concept_id]) conceptExercises[row.concept_id] = [];
    conceptExercises[row.concept_id].push({ id: row.exercise_id, created_at: row.created_at });
  }

  const allExerciseIds = [...new Set(allExercisesRes.rows.map(r => r.exercise_id))];
  if (allExerciseIds.length === 0) return { updated: 0 };

  // Pre-fetch ALL per-student per-exercise CMI proxies in one query
  const allStudentCmiRes = await client.query(
    `SELECT s.student_id, s.exercise_id,
            COUNT(*) AS total,
            SUM(CASE WHEN s.is_correct THEN 1 ELSE 0 END) AS correct,
            MAX(s.submitted_at) AS last_submission
     FROM submissions s
     WHERE s.exercise_id = ANY($1)
     GROUP BY s.student_id, s.exercise_id
     ORDER BY s.student_id, MAX(s.submitted_at) ASC`,
    [allExerciseIds]
  );

  // Index by student_id: { student_id: { exercise_id: { cmi, submittedAt } } }
  const studentCmiMap = {};
  for (const row of allStudentCmiRes.rows) {
    if (!studentCmiMap[row.student_id]) studentCmiMap[row.student_id] = [];
    const total = parseInt(row.total);
    const correct = parseInt(row.correct);
    studentCmiMap[row.student_id].push({
      exerciseId: row.exercise_id,
      cmi: total > 0 ? (correct / total) * 100 : 0,
      submittedAt: row.last_submission,
    });
  }

  for (const concept of conceptRes.rows) {
    const exercises = conceptExercises[concept.id];
    if (!exercises || exercises.length < 2) continue;

    const exerciseIdsForConcept = exercises.map(e => e.id);

    for (const [studentId, exCmis] of Object.entries(studentCmiMap)) {
      try {
        // Filter to only exercises for this concept
        const conceptExCmis = exCmis.filter(e => exerciseIdsForConcept.includes(e.exerciseId));
        if (conceptExCmis.length < 2) continue;

        const baselineCount = Math.min(2, Math.floor(conceptExCmis.length / 2));
        const recentCount = Math.min(2, conceptExCmis.length - baselineCount);

        if (baselineCount < 1 || recentCount < 1) continue;

        const baseline = conceptExCmis.slice(0, baselineCount);
        const recent = conceptExCmis.slice(-recentCount);

        const baselineAvg = baseline.reduce((s, e) => s + e.cmi, 0) / baseline.length;
        const recentAvg = recent.reduce((s, e) => s + e.cmi, 0) / recent.length;

        const firstDate = new Date(baseline[0].submittedAt);
        const lastDate = new Date(recent[recent.length - 1].submittedAt);
        const weeksBetween = Math.max(0.1, (lastDate - firstDate) / (7 * 24 * 60 * 60 * 1000));

        const velocity = (recentAvg - baselineAvg) / weeksBetween;
        const roundedVelocity = Math.round(velocity * 100) / 100;

        await client.query(
          `UPDATE student_concept_metrics
           SET velocity = $1, last_updated = NOW()
           WHERE student_id = $2 AND concept_id = $3 AND section_id = $4`,
          [roundedVelocity, parseInt(studentId), concept.id, sectionId]
        );

        updated++;
      } catch (err) {
        console.warn(`[Velocity] Failed for student ${studentId}, concept ${concept.name}:`, err.message);
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
              COUNT(DISTINCT cs.student_id) FILTER (WHERE cs.cds > 0.40) AS at_risk_count
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
       (section_id, concept_id, crs, crs_score, student_count, at_risk_count, last_updated)
       VALUES ($1, $2, $3, $4, $5, $6, NOW())
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
 * @param {number} atRiskCount - Students with CDS > 0.40
 * @returns {string} Risk classification
 */
function _classifyCRS(crsScore, atRiskCount) {
  if (crsScore > 0.80 && atRiskCount >= 5) return 'critical';
  if (crsScore > 0.60 && atRiskCount >= 3) return 'high';
  if (crsScore > 0.40) return 'medium';
  return 'low';
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

    await client.query('COMMIT');

    return {
      sectionId,
      cmiUpdated: cmiResult.updated,
      velocityUpdated: velocityResult.updated,
      crsUpdated: crsResult.updated,
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
         WHERE s.student_id = $1 AND ect.concept_id = $2`,
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
     ORDER BY c.name`,
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
            scm.last_updated,
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

  // Live update
  updateMetricsForSubmission,

  // Dashboard queries
  getStudentCMI,
  getSectionCRS,
  getConceptPrerequisites,
};
