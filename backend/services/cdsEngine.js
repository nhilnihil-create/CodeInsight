const alertEngine = require('./alertEngine');

// ── Utility Functions ───────────────────────────────────────────────────────

/**
 * Descriptive statistics for an array of numbers.
 */
function mean(arr) {
return arr.reduce((a, b) => a + b, 0) / Math.max(arr.length, 1);
}

function stddev(arr) {
if (!arr.length) return 0;
const m = mean(arr);
const v = arr.reduce((a, b) => a + Math.pow(b - m, 2), 0) / arr.length;
return Math.sqrt(v);
}

/**
 * Outlier-capped normalization for CDS components.
 *
 * Computes the effective maximum for a class metric as:
 *   effectiveMax = min(rawMax, mean + capFactor * stddev)
 *
 * Then returns the normalized ratio:
 *   normalized = min(value / effectiveMax, 1.0)
 *
 * This ensures the formula NTS = min(1, T / min(T_max, T_mean + 2σ))
 * is applied consistently across batch and live calculations.
 *
 * @param {number} value        - The student's raw metric value
 * @param {number[]} allValues  - The class-wide array of raw metric values
 * @param {number} [capFactor=2]- The sigma multiplier for outlier capping
 * @returns {{ normalized: number, effectiveMax: number }}
 */
function getNormalizedValue(value, allValues, capFactor = 2) {
const rawMax = Math.max(...allValues, 0);
const m = mean(allValues);
const s = stddev(allValues);
const cappedMax = Math.max(1, Math.ceil(m + capFactor * s));
const effectiveMax = Math.max(1, Math.min(rawMax, cappedMax));
const normalized = Math.min(value / effectiveMax, 1.0);
return { normalized, effectiveMax };
}

function classify(cds, isPreliminary = false) {
if (cds === null || cds === undefined) return 'Unscored';
const prefix = isPreliminary ? 'Preliminary - ' : '';
if (cds <= 0.31) return 'Low';
if (cds <= 0.50) return 'Moderate';
return 'High';
}

// ── Batch CDS Computation ───────────────────────────────────────────────────

async function computeBatchCDS(exerciseId, db) {
const exRes = await db.query('SELECT * FROM exercises WHERE id=$1', [exerciseId]);
if (!exRes.rows.length) throw new Error('Exercise not found');
const exercise = exRes.rows[0];

const students = await db.query(
  `SELECT u.id, u.name FROM users u
    JOIN enrollments e ON e.student_id=u.id
    WHERE e.section_id=$1`,
  [exercise.section_id]
);

// Minimum class size check
const MIN_CLASS_SIZE = 3;
const isPreliminaryClass = students.rows.length < MIN_CLASS_SIZE;

// Fetch all submissions with integrity flag info
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

// Group by student, apply post-solution cutoff (first unflagged acceptance)
const perStudent = {};
for (const r of subsRes.rows) {
  const sid = r.student_id;
  if (!perStudent[sid]) perStudent[sid] = { attempts: [] };
  perStudent[sid].attempts.push({
    attempt_number: r.attempt_number,
    is_correct: r.is_correct,
    time_spent_seconds: r.time_spent_seconds,
    code: r.code,
    flag_id: r.flag_id
  });
}

const subMap = {};
for (const [sid, info] of Object.entries(perStudent)) {
  const attempts = info.attempts;
  const firstAccepted = attempts.find(a => a.is_correct === true && a.flag_id === null);
  const cutoff = firstAccepted ? firstAccepted.attempt_number : null;
  const counted = cutoff ? attempts.filter(a => a.attempt_number <= cutoff) : attempts;

  const total_attempts = counted.length;
  const failed_attempts = counted.filter(a => a.is_correct === false).length;
  const max_time = counted.reduce((m, a) => Math.max(m, a.time_spent_seconds || 0), 0);
  const flaggedAttempts = counted.filter(a => a.flag_id !== null);

  subMap[sid] = {
    total_attempts,
    failed_attempts,
    max_time,
    hasFlaggedAttempt: flaggedAttempts.length > 0,
    integrityFlagCount: flaggedAttempts.length
  };
}

// ── Outlier-capped normalization for class-wide metrics ───────────────────
const failedValues = Object.values(subMap).map(s => s.failed_attempts);
const totalValues = Object.values(subMap).map(s => s.total_attempts);
const timeValues = Object.values(subMap).map(s => s.max_time);

const { effectiveMax: maxFailed } = getNormalizedValue(
  Math.max(...failedValues, 0), failedValues
);
const { effectiveMax: maxTotal } = getNormalizedValue(
  Math.max(...totalValues, 0), totalValues
);
const { effectiveMax: effectiveMaxTime } = getNormalizedValue(
  Math.max(...timeValues, 0), timeValues
);

// ── Blank submission check (Pillar 1: Jadud 2006) ─────────────────────────
const starterCode = exercise.starter_code || '';
const blankRes = await db.query(
  `SELECT DISTINCT student_id FROM submissions
    WHERE exercise_id=$1
    AND (TRIM(code) = TRIM($2) OR TRIM(code) = '' OR code IS NULL)`,
  [exerciseId, starterCode]
);
const blankStudents = new Set(blankRes.rows.map(r => r.student_id));

// ── Write CDS scores + snapshots per student ──────────────────────────────
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

    // Apply getNormalizedValue for each component
    ner = getNormalizedValue(failed, failedValues).normalized;
    nrs = getNormalizedValue(total, totalValues).normalized;
    nts = getNormalizedValue(timeSec, timeValues).normalized;

    // NTS edge case: >=90% of effective max time with zero successes → force High
    const successCount = total - failed;
    if (nts >= 0.9 && successCount === 0) {
      ner = 1; nrs = 1; nts = 1; cds = 1.0;
      classification = 'High';
    } else {
      cds = (0.40 * ner) + (0.35 * nrs) + (0.25 * nts);
      cds = Math.round(cds * 10000) / 10000;
      classification = classify(cds, isPreliminaryClass);
    }
  }

  // Upsert current score (UI display)
  await db.query(
    `INSERT INTO cds_scores
      (student_id,exercise_id,section_id,ner,nrs,nts,cds,classification,has_flagged_attempts,integrity_flag_count,source,visible,computed_at)
      VALUES($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,'batch',true,NOW())
      ON CONFLICT (student_id,exercise_id)
      DO UPDATE SET ner=$4,nrs=$5,nts=$6,cds=$7,classification=$8,has_flagged_attempts=$9,integrity_flag_count=$10,source='batch',visible=true,computed_at=NOW()`,
    [sid, exerciseId, exercise.section_id, ner, nrs, nts, cds, classification, hasFlagged, flagCount]
  );

  // Append-only snapshot for CDS reproducibility (defense auditability)
  await db.query(
    `INSERT INTO cds_snapshots
      (student_id,exercise_id,ner,nrs,nts,cds,classification,class_max_errors,class_max_attempts,effective_max_time,calculated_at)
      VALUES($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,NOW())`,
    [sid, exerciseId, ner, nrs, nts, cds, classification, maxFailed, maxTotal, effectiveMaxTime]
  );
}

await alertEngine.generateAlerts(exerciseId, db);
return { message: 'CDS computed', studentsProcessed: students.rows.length };
}

// ── Live Peer Ranking ───────────────────────────────────────────────────────

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

const avgErrors = rows.reduce((a, r) => a + r.errors, 0) / rows.length;
const avgAttempts = rows.reduce((a, r) => a + r.attempts, 0) / rows.length;

return rows.map(r => {
  const ratio = ((r.errors / (avgErrors || 1)) + (r.attempts / (avgAttempts || 1))) / 2;
  const status = ratio > 1.5 ? 'above' : ratio < 0.7 ? 'below' : 'average';
  return { ...r, relativeStatus: status };
});
}

// ── Instant CDS (single-run feedback) ───────────────────────────────────────

function calculateCDS(testResults, exercise) {
if (!testResults || !Array.isArray(testResults)) {
  return { score: 0, ner: 0, nrs: 0, nts: 0, classification: 'Unscored' };
}

const totalTests = testResults.length;
const failedTests = totalTests - testResults.filter(r => r.passed).length;

const ner = failedTests / Math.max(totalTests, 1);
const nrs = 0;
const nts = 0;

let cds = (0.40 * ner) + (0.35 * nrs) + (0.25 * nts);
cds = Math.round(cds * 10000) / 10000;

return {
  score: Math.min(cds, 1),
  ner, nrs, nts,
  classification: classify(Math.min(cds, 1))
};
}

// ── Live CDS (per-submission, class-relative) ───────────────────────────────

async function calculateLiveCDS(studentId, exerciseId, db) {
try {
  const exRes = await db.query('SELECT * FROM exercises WHERE id=$1', [exerciseId]);
  if (!exRes.rows.length) return null;

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

  // Group by student, apply post-solution cutoff
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

  const metricsMap = {};
  for (const [sid, info] of Object.entries(perStudent)) {
    const attempts = info.attempts;
    const firstAcceptedIdx = attempts.findIndex(a => a.is_correct === true && a.flag_id === null);
    const counted = firstAcceptedIdx !== -1
      ? attempts.slice(0, firstAcceptedIdx + 1)
      : attempts;

    const total = counted.length;
    const failed = counted.filter(a => a.is_correct === false).length;
    const maxTime = counted.reduce((m, a) => Math.max(m, a.time_spent_seconds || 0), 0);
    const flaggedAttempts = counted.filter(a => a.flag_id !== null);

    metricsMap[sid] = {
      total,
      failed,
      maxTime,
      hasFlaggedAttempt: flaggedAttempts.length > 0,
      integrityFlagCount: flaggedAttempts.length
    };
  }

  // ── Outlier-capped normalization (same helper as batch) ─────────────────
  const failedValues = Object.values(metricsMap).map(s => s.failed);
  const totalValues = Object.values(metricsMap).map(s => s.total);
  const timeValues = Object.values(metricsMap).map(s => s.maxTime);

  const studentData = metricsMap[studentId];
  if (!studentData) {
    return { ner: 0, nrs: 0, nts: 0, cds: 0, classification: 'Unscored', hasFlaggedAttempt: false, integrityFlagCount: 0 };
  }

  const ner = getNormalizedValue(studentData.failed, failedValues).normalized;
  const nrs = getNormalizedValue(studentData.total, totalValues).normalized;
  const nts = getNormalizedValue(studentData.maxTime, timeValues).normalized;

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
