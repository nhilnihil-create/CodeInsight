const alertEngine = require('./alertEngine');

function classify(cds) {
  if (cds === null || cds === undefined) return 'Unscored';
  if (cds <= 0.33) return 'Low';
  if (cds <= 0.66) return 'Moderate';
  return 'High';
}

async function computeBatchCDS(exerciseId, db) {
  const exRes = await db.query('SELECT * FROM exercises WHERE id=$1', [exerciseId]);
  if (!exRes.rows.length) throw new Error('Exercise not found');
  const exercise = exRes.rows[0];
  const timeLimitSeconds = exercise.time_limit_minutes * 60;

  const students = await db.query(
    `SELECT u.id, u.name FROM users u
     JOIN enrollments e ON e.student_id=u.id
     WHERE e.section_id=$1`,
    [exercise.section_id]
  );

  const allSubs = await db.query(
    `SELECT student_id,
            COUNT(*) AS total_attempts,
            COUNT(*) FILTER (WHERE is_correct=false) AS failed_attempts,
            MAX(time_spent_seconds) AS max_time
     FROM submissions
     WHERE exercise_id=$1
     GROUP BY student_id`,
    [exerciseId]
  );

  let maxFailed = 0, maxTotal = 0;
  for (const row of allSubs.rows) {
    if (parseInt(row.failed_attempts) > maxFailed) maxFailed = parseInt(row.failed_attempts);
    if (parseInt(row.total_attempts) > maxTotal) maxTotal = parseInt(row.total_attempts);
  }
  if (maxFailed === 0) maxFailed = 1;
  if (maxTotal === 0) maxTotal = 1;

  const subMap = {};
  for (const row of allSubs.rows) subMap[row.student_id] = row;

  const blankRes = await db.query(
    `SELECT DISTINCT student_id FROM submissions
     WHERE exercise_id=$1 AND code=''`,
    [exerciseId]
  );
  const blankStudents = new Set(blankRes.rows.map(r => r.student_id));

  for (const student of students.rows) {
    const sid = student.id;
    const subs = subMap[sid];

    let ner, nrs, nts, cds, classification;

    if (!subs) {
      ner = null; nrs = null; nts = null; cds = null;
      classification = 'Unscored';
    } else if (blankStudents.has(sid)) {
      ner = 1; nrs = 1; nts = 1; cds = 1.0;
      classification = 'High';
    } else {
      const failed = parseInt(subs.failed_attempts);
      const total = parseInt(subs.total_attempts);
      const timeSec = parseInt(subs.max_time) || 0;

      ner = Math.min(failed / maxFailed, 1.0);
      nrs = Math.min(total / maxTotal, 1.0);
      nts = Math.min(timeSec / timeLimitSeconds, 1.0);

      cds = (0.40 * ner) + (0.35 * nrs) + (0.25 * nts);
      cds = Math.round(cds * 10000) / 10000;
      classification = classify(cds);
    }

    await db.query(
      `INSERT INTO cds_scores
       (student_id,exercise_id,section_id,ner,nrs,nts,cds,classification,computed_at)
       VALUES($1,$2,$3,$4,$5,$6,$7,$8,NOW())
       ON CONFLICT (student_id,exercise_id)
       DO UPDATE SET ner=$4,nrs=$5,nts=$6,cds=$7,classification=$8,computed_at=NOW()`,
      [sid, exerciseId, exercise.section_id, ner, nrs, nts, cds, classification]
    );
  }

  await alertEngine.generateAlerts(exerciseId, db);
  return { message: 'CDS computed', studentsProcessed: students.rows.length };
}

async function getLivePeerRanking(exerciseId, db) {
  const subs = await db.query(
    `SELECT s.student_id, u.name,
            COUNT(*) AS total_attempts,
            COUNT(*) FILTER (WHERE s.is_correct=false) AS failed_attempts,
            MAX(s.time_spent_seconds) AS max_time
     FROM submissions s JOIN users u ON u.id=s.student_id
     WHERE s.exercise_id=$1
     GROUP BY s.student_id, u.name`,
    [exerciseId]
  );

  if (!subs.rows.length) return [];

  const rows = subs.rows.map(r => ({
    studentId:    r.student_id,
    name:         r.name,
    errors:       parseInt(r.failed_attempts),
    attempts:     parseInt(r.total_attempts),
    timeMinutes:  Math.round(parseInt(r.max_time || 0) / 60)
  }));

  const avgErrors = rows.reduce((a,r)=>a+r.errors, 0) / rows.length;
  const avgAttempts = rows.reduce((a,r)=>a+r.attempts, 0) / rows.length;

  return rows.map(r => {
    const ratio = ((r.errors/(avgErrors||1)) + (r.attempts/(avgAttempts||1))) / 2;
    const status = ratio > 1.5 ? 'above' : ratio < 0.7 ? 'below' : 'average';
    return { ...r, relativeStatus: status };
  });
}

// Calculate CDS score from test results
function calculateCDS(testResults, exercise) {
  if (!testResults || !Array.isArray(testResults)) {
    return { score: 0, ner: 0, nrs: 0, nts: 0, classification: 'Unscored' };
  }

  const totalTests = testResults.length;
  const passedTests = testResults.filter(r => r.passed).length;
  const failedTests = totalTests - passedTests;

  // NER: Normalized Error Rate (failed tests / total tests)
  const ner = failedTests / Math.max(totalTests, 1);

  // NRS: Normalized Retry Score (simple - 0 unless multiple runs)
  const nrs = 0;

  // NTS: Normalized Time on Task (0 - we don't track this in run)
  const nts = 0;

  // CDS: Composite Difficulty Score
  // If all tests pass, CDS = 0 (no difficulty)
  // If some fail, CDS scales from 0 to 1
  const cds = ner * 0.5; // NER weighted at 50%

  return {
    score: Math.min(cds, 1),
    ner: ner,
    nrs: nrs,
    nts: nts,
    classification: classify(Math.min(cds, 1))
  };
}

module.exports = { computeBatchCDS, getLivePeerRanking, calculateCDS };
