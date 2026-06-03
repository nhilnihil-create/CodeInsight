const alertEngine = require('./alertEngine');

function classify(cds, isPreliminary = false) {
  if (cds === null || cds === undefined) return 'Unscored';
  // Even if preliminary, we should provide a hint to the UI for color
  // We append it to the classification string
  const prefix = isPreliminary ? 'Preliminary - ' : '';
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

  // Minimum class size check: if fewer than 3 students, mark as Preliminary
  const MIN_CLASS_SIZE = 3;
  const isPreliminaryClass = students.rows.length < MIN_CLASS_SIZE;

  // Fetch all submissions for the exercise and compute per-student counts
  // Include flag information to track integrity flags separately
  // Join on student_id and exercise_id to ensure ANY flag for the exercise 
  // correctly disqualifies submissions from being cutoffs.
  const subsRes = await db.query(
    `SELECT s.student_id, s.attempt_number, s.is_correct, s.time_spent_seconds, s.code,
            (SELECT id FROM integrity_flags i 
             WHERE i.student_id = s.student_id 
             AND i.exercise_id = s.exercise_id 
             AND i.status = 'flagged' 
             LIMIT 1) AS flag_id
     FROM submissions s
     WHERE s.exercise_id=$1
     ORDER BY s.student_id, s.attempt_number ASC`,
    [exerciseId]
  );

  // Group by student and apply post-solution cutoff: only count attempts up to first UNFLAGGED accepted
  const perStudent = {};
  for (const r of subsRes.rows) {
    const sid = r.student_id;
    if (!perStudent[sid]) perStudent[sid] = { attempts: [], max_time: 0 };
    perStudent[sid].attempts.push({
      attempt_number: r.attempt_number,
      is_correct: r.is_correct,
      time_spent_seconds: r.time_spent_seconds,
      code: r.code,
      flag_id: r.flag_id // null if not flagged, otherwise flag id
    });
  }

  const subMap = {};
  let maxFailed = 0, maxTotal = 0;
  for (const [sid, info] of Object.entries(perStudent)) {
    const attempts = info.attempts;
    // find first UNFLAGGED accepted attempt number
    // Integrity flags do not allow students to remove attempts from scoring via fraudulent success
    const firstAccepted = attempts.find(a => a.is_correct === true && a.flag_id === null);
    const cutoff = firstAccepted ? firstAccepted.attempt_number : null;

    const counted = cutoff ? attempts.filter(a => a.attempt_number <= cutoff) : attempts;
    const total_attempts = counted.length;
    const failed_attempts = counted.filter(a => a.is_correct === false).length;
    const max_time = counted.reduce((m, a) => Math.max(m, a.time_spent_seconds || 0), 0);

    // Check if any counted attempt has an integrity flag and count them
    const flaggedAttempts = counted.filter(a => a.flag_id !== null);
    const hasFlaggedAttempt = flaggedAttempts.length > 0;
    const integrityFlagCount = flaggedAttempts.length;

    subMap[sid] = {
      total_attempts,
      failed_attempts,
      max_time,
      hasFlaggedAttempt,
      integrityFlagCount
    };

    if (failed_attempts > maxFailed) maxFailed = failed_attempts;
    if (total_attempts > maxTotal) maxTotal = total_attempts;
  }

    // Outlier capping: cap maxima at mean + 2*stddev to avoid extreme skew
    const failedValues = Object.values(subMap).map(s => s.failed_attempts);
    const totalValues = Object.values(subMap).map(s => s.total_attempts);

    function mean(arr) { return arr.reduce((a,b)=>a+b,0) / Math.max(arr.length,1); }
    function stddev(arr) {
      if (!arr.length) return 0;
      const m = mean(arr);
      const v = arr.reduce((a,b)=>a + Math.pow(b-m,2),0) / arr.length;
      return Math.sqrt(v);
    }

    const failedMean = mean(failedValues);
    const failedStd = stddev(failedValues);
    const failedCap = Math.max(1, Math.ceil(failedMean + 2 * failedStd));
    maxFailed = Math.max(1, Math.min(maxFailed, failedCap));

    const totalMean = mean(totalValues);
    const totalStd = stddev(totalValues);
    const totalCap = Math.max(1, Math.ceil(totalMean + 2 * totalStd));
    maxTotal = Math.max(1, Math.min(maxTotal, totalCap));

  const starterCode = exercise.starter_code || '';

  // Blank check using starter_code comparison (Pillar 1: Jadud 2006)
  // We consider a submission blank if it matches the starter code exactly (trimmed)
  // or if it's empty.
  const blankRes = await db.query(
    `SELECT DISTINCT student_id FROM submissions
     WHERE exercise_id=$1
     AND (TRIM(code) = TRIM($2) OR TRIM(code) = '' OR code IS NULL)`,
    [exerciseId, starterCode]
  );
  const blankStudents = new Set(blankRes.rows.map(r => r.student_id));

  for (const student of students.rows) {
    const sid = student.id;
    const subs = subMap[sid];

    let ner, nrs, nts, cds, classification;
    let hasFlagged = false;
    let flagCount = 0;

    if (!subs) {
      ner = null; nrs = null; nts = null; cds = null;
      classification = 'Unscored';
    } else if (blankStudents.has(sid)) {
      ner = 1; nrs = 1; nts = 1; cds = 1.0;
      classification = 'High';
      hasFlagged = subs.hasFlaggedAttempt;
      flagCount = subs.integrityFlagCount;
    } else {
      const failed = parseInt(subs.failed_attempts);
      const total = parseInt(subs.total_attempts);
      const timeSec = parseInt(subs.max_time) || 0;
      hasFlagged = subs.hasFlaggedAttempt;
      flagCount = subs.integrityFlagCount;

      ner = Math.min(failed / maxFailed, 1.0);
      nrs = Math.min(total / maxTotal, 1.0);
      nts = Math.min(timeSec / timeLimitSeconds, 1.0);

      // NTS edge case: if student used >=90% time but had zero successes, force High
      const successCount = total - failed;
      const ntsRatio = timeSec / timeLimitSeconds;
      if (ntsRatio >= 0.9 && successCount === 0) {
        ner = 1; nrs = 1; nts = 1; cds = 1.0;
        classification = 'High';
      } else {
        cds = (0.40 * ner) + (0.35 * nrs) + (0.25 * nts);
        cds = Math.round(cds * 10000) / 10000;
        classification = classify(cds, isPreliminaryClass);
      }
    }

    await db.query(
      `INSERT INTO cds_scores
       (student_id,exercise_id,section_id,ner,nrs,nts,cds,classification,has_flagged_attempts,integrity_flag_count,source,visible,computed_at)
       VALUES($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,'batch',true,NOW())
       ON CONFLICT (student_id,exercise_id)
       DO UPDATE SET ner=$4,nrs=$5,nts=$6,cds=$7,classification=$8,has_flagged_attempts=$9,integrity_flag_count=$10,source='batch',visible=true,computed_at=NOW()`,
      [sid, exerciseId, exercise.section_id, ner, nrs, nts, cds, classification, hasFlagged, flagCount]
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

  // NRS/NTS are 0 for a single run, but we should use the official weights
  // to keep the UI feedback consistent with the final batch calculation.
  const nrs = 0;
  const nts = 0;

  // Use the 40/35/25 weighting even for instant feedback
  // This prevents the "Score Jump" when the exercise closes.
  let cds = (0.40 * ner) + (0.35 * nrs) + (0.25 * nts);
  cds = Math.round(cds * 10000) / 10000;

  return {
    score: Math.min(cds, 1),
    ner: ner,
    nrs: nrs,
    nts: nts,
    classification: classify(Math.min(cds, 1))
  };
}

// Calculate live CDS for a student after a submission
// Uses current peer data to give preliminary CDS score
async function calculateLiveCDS(studentId, exerciseId, db) {
  try {
    // Get exercise
    const exRes = await db.query('SELECT * FROM exercises WHERE id=$1', [exerciseId]);
    if (!exRes.rows.length) return null;
    const exercise = exRes.rows[0];
    const timeLimitSeconds = exercise.time_limit_minutes * 60;

    // Get all submissions for this exercise and include flag information
    // Join on student_id and exercise_id to ensure ANY flag for the exercise 
    // correctly disqualifies submissions from being cutoffs.
    const subsRes = await db.query(
      `SELECT s.student_id, s.attempt_number, s.is_correct, s.time_spent_seconds,
              (SELECT id FROM integrity_flags i 
               WHERE i.student_id = s.student_id 
               AND i.exercise_id = s.exercise_id 
               AND i.status = 'flagged' 
               LIMIT 1) AS flag_id
       FROM submissions s
       WHERE s.exercise_id=$1 
       ORDER BY s.student_id, s.attempt_number ASC`,
      [exerciseId]
    );

    // Group by student and apply post-solution cutoff (unflagged success only)
    const perStudent = {};
    for (const r of subsRes.rows) {
      const sid = r.student_id;
      if (!perStudent[sid]) perStudent[sid] = { attempts: [] };
      perStudent[sid].attempts.push({
        is_correct: r.is_correct,
        time_spent_seconds: r.time_spent_seconds,
        flag_id: r.flag_id
      });
    }

    // Process each student to find their metrics with the cutoff
    const metricsMap = {};
    let maxFailed = 1, maxTotal = 1;

    for (const [sid, info] of Object.entries(perStudent)) {
      const attempts = info.attempts;
      // find first UNFLAGGED accepted attempt
      const firstAcceptedIdx = attempts.findIndex(a => a.is_correct === true && a.flag_id === null);
      
      const counted = firstAcceptedIdx !== -1 
        ? attempts.slice(0, firstAcceptedIdx + 1) 
        : attempts;

      const total = counted.length;
      const failed = counted.filter(a => a.is_correct === false).length;
      const maxTime = counted.reduce((m, a) => Math.max(m, a.time_spent_seconds || 0), 0);
      
      const flaggedAttempts = counted.filter(a => a.flag_id !== null);
      const hasFlaggedAttempt = flaggedAttempts.length > 0;
      const integrityFlagCount = flaggedAttempts.length;

      metricsMap[sid] = {
        total,
        failed,
        maxTime,
        hasFlaggedAttempt,
        integrityFlagCount
      };

      maxFailed = Math.max(maxFailed, failed);
      maxTotal = Math.max(maxTotal, total);
    }

    // Calculate student's CDS components
    const studentData = metricsMap[studentId];
    if (!studentData) {
      // Student hasn't submitted yet, no live CDS
      return { ner: 0, nrs: 0, nts: 0, cds: 0, classification: 'Unscored', hasFlaggedAttempt: false, integrityFlagCount: 0 };
    }

    const ner = studentData.failed / Math.max(maxFailed, 1);
    const nrs = studentData.total / Math.max(maxTotal, 1);
    const nts = studentData.maxTime / Math.max(timeLimitSeconds, 1);
    const cds = Math.min(1, (0.40 * ner) + (0.35 * nrs) + (0.25 * nts));

    return {
      ner: Math.round(ner * 10000) / 10000,
      nrs: Math.round(nrs * 10000) / 10000,
      nts: Math.round(nts * 10000) / 10000,
      cds: Math.round(cds * 10000) / 10000,
      classification: classify(cds),
      hasFlaggedAttempt: studentData.hasFlaggedAttempt,
      integrityFlagCount: studentData.integrityFlagCount
    };
  } catch (err) {
    console.error('Error calculating live CDS:', err);
    return { ner: 0, nrs: 0, nts: 0, cds: 0, classification: 'Unscored', hasFlaggedAttempt: false, integrityFlagCount: 0 };
  }
}

module.exports = { computeBatchCDS, getLivePeerRanking, calculateCDS, calculateLiveCDS };