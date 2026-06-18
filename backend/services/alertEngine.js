/**
 * Alert Engine — generates early warning alerts for instructors.
 *
 * GAP #10: Extended to support micro-concept-based alerts in addition to
 * high CDS alerts.
 */

async function generateAlerts(exerciseId, db) {
  const high = await db.query(
    `SELECT cs.student_id, cs.section_id, cs.cds, cs.classification,
            c.name AS concept_name
     FROM cds_scores cs
     JOIN exercises ex ON ex.id=cs.exercise_id
     JOIN concepts c ON c.id=ex.concept_id
     WHERE cs.exercise_id=$1 AND cs.classification='High'`,
    [exerciseId]
  );

  for (const row of high.rows) {
    await db.query(
      `INSERT INTO alerts
       (student_id,exercise_id,section_id,cds_score,classification,concept_name)
       VALUES($1,$2,$3,$4,$5,$6)
       ON CONFLICT (student_id,exercise_id) DO NOTHING`,
      [row.student_id, exerciseId, row.section_id,
       row.cds, row.classification, row.concept_name]
    );
  }
  return { alertsGenerated: high.rows.length };
}

/**
 * GAP #10: Generate micro-concept-based alerts.
 * Called after micro-concept analysis finds specific issues for a student.
 *
 * @param {Object} params
 * @param {number} params.studentId
 * @param {number} params.exerciseId
 * @param {number} params.sectionId
 * @param {string} params.conceptName
 * @param {Array} params.detectedIssues - From microConceptEngine.detectMicroConcepts()
 * @param {Object} db
 */
async function generateMicroConceptAlert(params, db) {
  const { studentId, exerciseId, sectionId, conceptName, detectedIssues } = params;

  if (!detectedIssues || detectedIssues.length === 0) return;

  // All detected micro-concept issues are treated as significant
  const issueSummary = detectedIssues.map(i => `${i.name}: ${i.recommendation || i.description}`).join('; ');

  // Check if alert already exists for this student/exercise
  const existing = await db.query(
    `SELECT id FROM alerts WHERE student_id=$1 AND exercise_id=$2`,
    [studentId, exerciseId]
  );

  if (existing.rows.length === 0) {
    // Create new alert with micro-concept details
    await db.query(
      `INSERT INTO alerts
       (student_id,exercise_id,section_id,cds_score,classification,concept_name)
       VALUES($1,$2,$3,$4,$5,$6)
       ON CONFLICT (student_id,exercise_id) DO NOTHING`,
      [studentId, exerciseId, sectionId, null, 'Micro-Concept Alert', conceptName]
    );
  }

  // Store micro-concept findings in verification_logs for instructor review
  await db.query(
    `INSERT INTO verification_logs
     (student_id, exercise_id, verification_type, reason)
     VALUES($1,$2,$3,$4)`,
    [studentId, exerciseId, 'micro_concept', issueSummary]
  );
}

module.exports = { generateAlerts, generateMicroConceptAlert };
