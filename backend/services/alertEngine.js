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

module.exports = { generateAlerts };
