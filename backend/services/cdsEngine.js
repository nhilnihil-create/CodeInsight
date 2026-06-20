const alertEngine = require('./alertEngine');

// ── CDS v3 Normalized: Min-Max + p95 Outlier-Capped Normalization ─────────
//
// Normalizes a student's raw metric against the class using:
//   normalized = (cappedValue - min) / (p95 - min)
//
// where:
//   - cappedValue = min(value, p95)  ← Outlier Capping Guard
//   - p95         = 95th percentile of class values
//   - min         = class minimum
//
// ⚠️ ZERO-VARIANCE ROADBLOCK: if (p95 - min) === 0, returns 0.00
// ⚠️ TYPE CASTING: all inputs wrapped in Number() for DB safety

function computeClassStats(rawValues) {
  const safeValues = (rawValues || []).map(v => Number(v)).filter(v => !isNaN(v));
  if (safeValues.length === 0) return { min: 0, p95: 0, denominator: 0, hasVariance: false };
  const sorted = [...safeValues].sort((a, b) => a - b);
  const p95Index = Math.ceil(sorted.length * 0.95) - 1;
  const p95 = sorted[Math.max(0, Math.min(p95Index, sorted.length - 1))];
  const min = safeValues.length > 0 ? Math.min(...safeValues) : 0;
  const denominator = p95 - min;
  return { min, p95, denominator, hasVariance: denominator !== 0 };
}

function normalizeWithStats(value, stats) {
  if (!stats.hasVariance) return 0.00;
  const numValue = Number(value);
  if (isNaN(numValue)) return 0.00;
  const cappedValue = Math.min(numValue, stats.p95);
  const raw = Math.max(0, Math.min((cappedValue - stats.min) / stats.denominator, 1.0));
  return Number(parseFloat(raw).toFixed(2));
}

function getNormalizedValue(value, allValues) {
  const stats = computeClassStats(allValues);
  const normalized = normalizeWithStats(value, stats);
  return { normalized, min: stats.min, p95: stats.p95 };
}

// ── Authoritative CDS Classification Thresholds (5‑tier) ────────────────────
// Single source of truth — all callers MUST use these, not hardcode.
// Rationale: ≤0.20 = Very Low (struggling), ≤0.40 = Low (below average),
// ≤0.60 = Moderate (average), ≤0.80 = Elevated (above average),
// >0.80 = High (mastering). Aligned with frontend mastery-bar.jsx.
const CDS_THRESHOLDS = { VERY_LOW: 0.20, LOW: 0.40, MODERATE: 0.60, ELEVATED: 0.80 };

function classify(cds, isPreliminary = false) {
  if (cds === null || cds === undefined) return 'Unscored';
  const prefix = isPreliminary ? 'Prelim-' : '';
  if (cds <= CDS_THRESHOLDS.VERY_LOW) return `${prefix}Very Low`;
  if (cds <= CDS_THRESHOLDS.LOW) return `${prefix}Low`;
  if (cds <= CDS_THRESHOLDS.MODERATE) return `${prefix}Moderate`;
  if (cds <= CDS_THRESHOLDS.ELEVATED) return `${prefix}Elevated`;
  return `${prefix}High`;
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

// GAP #8: Fetch students with integrity flags that exclude from normalization
// HARDCODING and BLANK_TEMPLATE submissions should not affect class statistics
const excludedRes = await db.query(
  `SELECT DISTINCT student_id FROM integrity_flags
   WHERE exercise_id=$1
   AND flag_type IN ('HARDCODING', 'BLANK_TEMPLATE')
   AND status = 'flagged'`,
  [exerciseId]
);
const excludedStudents = new Set(excludedRes.rows.map(r => r.student_id));

    // Paper: exclude unverified submissions from CDS normalization.
    // Submissions that fail AST verification (is_verified = false) indicate
    // structurally invalid code and should not affect class difficulty scores.
    const subsRes = await db.query(
      `SELECT s.student_id, s.attempt_number, s.is_correct, s.time_spent_seconds, s.code,
              s.is_verified,
              (SELECT id FROM integrity_flags i
                WHERE i.student_id = s.student_id
                AND i.exercise_id = s.exercise_id
                AND i.status = 'flagged'
                LIMIT 1) AS flag_id
        FROM submissions s
        JOIN exercises e ON e.id = s.exercise_id
        WHERE s.exercise_id=$1
          AND s.is_practice IS NOT TRUE
          AND s.is_verified = true
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

// ── Outlier-capped normalization + integrity-flagged exclusion ────────────
// GAP #8: Exclude flagged students (HARDCODING/BLANK_TEMPLATE) from
// normalization AND give them special scoring treatment (CDS=1, High).
const filteredSubMap = {};
for (const [sid, data] of Object.entries(subMap)) {
  if (!excludedStudents.has(Number(sid))) {
    filteredSubMap[sid] = data;
  }
}

// Guard: empty filteredSubMap means all submitters are integrity-flagged.
// Skip class stats computation (would be meaningless zero-variance).
const hasFilteredStudents = Object.keys(filteredSubMap).length > 0;

const failedValues = hasFilteredStudents ? Object.values(filteredSubMap).map(s => Number(s.failed_attempts)) : [];
const totalValues = hasFilteredStudents ? Object.values(filteredSubMap).map(s => Number(s.total_attempts)) : [];
const timeValues = hasFilteredStudents ? Object.values(filteredSubMap).map(s => Number(s.max_time)) : [];

// Pre-compute class stats ONCE per metric — avoids redundant sorting in student loop
const failedStats = computeClassStats(failedValues);
const totalStats = computeClassStats(totalValues);
const timeStats = computeClassStats(timeValues);
const minFailed = failedStats.min, p95Failed = failedStats.p95;
const minTotal = totalStats.min, p95Total = totalStats.p95;
const minTime = timeStats.min, p95Time = timeStats.p95;

// ── Write CDS scores + snapshots (bulk INSERT ... ON CONFLICT) ──────────────
const scoreRows = [];
const snapshotRows = [];
for (const student of students.rows) {
  const sid = student.id;
  const subs = subMap[sid];

  let ner, nrs, nts, cds, classification;
  let hasFlagged = false;
  let flagCount = 0;

  if (!subs) {
    ner = null; nrs = null; nts = null; cds = null;
    classification = 'Unscored';
  } else if (excludedStudents.has(sid)) {
    ner = null; nrs = null; nts = null; cds = null;
    classification = 'Flagged-Pending';
    hasFlagged = subs.hasFlaggedAttempt;
    flagCount = subs.integrityFlagCount;
  } else {
    const failed = Number(subs.failed_attempts);
    const total = Number(subs.total_attempts);
    const timeSec = Number(subs.max_time) || 0;
    hasFlagged = subs.hasFlaggedAttempt;
    flagCount = subs.integrityFlagCount;

    // Apply normalization using pre-computed class stats (1 sort per metric, not per student)
    ner = normalizeWithStats(failed, failedStats);
    nrs = normalizeWithStats(total, totalStats);
    nts = normalizeWithStats(timeSec, timeStats);

    cds = Math.min(1, (0.40 * ner) + (0.35 * nrs) + (0.25 * nts));
    cds = Number(parseFloat(cds).toFixed(2));
    classification = classify(cds, isPreliminaryClass);
  }

  scoreRows.push([sid, exerciseId, exercise.section_id, ner, nrs, nts, cds, classification, hasFlagged, flagCount]);
  snapshotRows.push([sid, exerciseId, ner, nrs, nts, cds, classification, minFailed, p95Failed, minTotal, p95Total, minTime, p95Time]);
}

// Bulk upsert cds_scores
if (scoreRows.length > 0) {
  const scoreParams = [];
  const scoreValues = scoreRows.map((row, i) => {
    const offset = i * 10;
    row.forEach((v, j) => { scoreParams.push(v); });
    return `($${offset + 1},$${offset + 2},$${offset + 3},$${offset + 4},$${offset + 5},$${offset + 6},$${offset + 7},$${offset + 8},$${offset + 9},$${offset + 10},'batch',true,NOW())`;
  }).join(',');

  await db.query(
    `INSERT INTO cds_scores
      (student_id,exercise_id,section_id,ner,nrs,nts,cds,classification,has_flagged_attempts,integrity_flag_count,source,visible,computed_at)
      VALUES ${scoreValues}
      ON CONFLICT (student_id,exercise_id)
      DO UPDATE SET ner=EXCLUDED.ner,nrs=EXCLUDED.nrs,nts=EXCLUDED.nts,cds=EXCLUDED.cds,
        classification=EXCLUDED.classification,has_flagged_attempts=EXCLUDED.has_flagged_attempts,
        integrity_flag_count=EXCLUDED.integrity_flag_count,source='batch',visible=true,computed_at=NOW()`,
    scoreParams
  );
}

// Bulk insert snapshots
if (snapshotRows.length > 0) {
  const snapParams = [];
  const snapValues = snapshotRows.map((row, i) => {
    const offset = i * 13;
    row.forEach((v, j) => { snapParams.push(v); });
    return `($${offset + 1},$${offset + 2},$${offset + 3},$${offset + 4},$${offset + 5},$${offset + 6},$${offset + 7},$${offset + 8},$${offset + 9},$${offset + 10},$${offset + 11},$${offset + 12},$${offset + 13},NOW())`;
  }).join(',');

  await db.query(
    `INSERT INTO cds_snapshots
      (student_id,exercise_id,ner,nrs,nts,cds,classification,
       class_min_errors,class_p95_errors,class_min_attempts,class_p95_attempts,class_min_time,class_p95_time,
       calculated_at)
      VALUES ${snapValues}`,
    snapParams
  );
}

await alertEngine.generateAlerts(exerciseId, db);
return { message: 'CDS computed', studentsProcessed: students.rows.length };
}

// ── Live Peer Ranking (CDS-based, single source of truth) ───────────────────

async function getLivePeerRanking(exerciseId, db) {
const res = await db.query(
  `SELECT cs.student_id, u.name, cs.cds, cs.classification
   FROM cds_scores cs
   JOIN users u ON u.id = cs.student_id
   WHERE cs.exercise_id = $1 AND cs.visible = true
   ORDER BY cs.cds DESC NULLS LAST`,
  [exerciseId]
);

if (!res.rows.length) return [];

return res.rows.map((r, idx) => ({
  studentId: r.student_id,
  name: r.name,
  cds: r.cds,
  classification: r.classification,
  rank: idx + 1
}));
}

// ── Live CDS (per-submission, class-relative) ───────────────────────────────

async function calculateLiveCDS(studentId, exerciseId, db) {
try {
  const exRes = await db.query('SELECT * FROM exercises WHERE id=$1', [exerciseId]);
  if (!exRes.rows.length) return null;

  // Paper: exclude unverified submissions from live CDS
  const subsRes = await db.query(
    `SELECT s.student_id, s.attempt_number, s.is_correct, s.time_spent_seconds,
            s.is_verified,
            (SELECT id FROM integrity_flags i
              WHERE i.student_id = s.student_id
              AND i.exercise_id = s.exercise_id
              AND i.status = 'flagged'
              LIMIT 1) AS flag_id
      FROM submissions s
      JOIN exercises e ON e.id = s.exercise_id
      WHERE s.exercise_id=$1
        AND s.is_practice IS NOT TRUE
        AND s.is_verified = true
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

  // ── GAP #8: Exclude integrity-flagged students (HARDCODING/BLANK_TEMPLATE) ─
  const liveExcludedRes = await db.query(
    `SELECT DISTINCT student_id FROM integrity_flags
     WHERE exercise_id=$1
     AND flag_type IN ('HARDCODING', 'BLANK_TEMPLATE')
     AND status = 'flagged'`,
    [exerciseId]
  );
  const liveExcludedStudents = new Set(liveExcludedRes.rows.map(r => r.student_id));

  // ── p95 min-max normalization (exclude integrity-flagged from class stats) ─
  const metricsEntries = Object.entries(metricsMap);
  const cleanMetrics = metricsEntries.filter(([sid]) => !liveExcludedStudents.has(Number(sid)));
  const failedValues = cleanMetrics.map(([, d]) => Number(d.failed));
  const totalValues = cleanMetrics.map(([, d]) => Number(d.total));
  const timeValues = cleanMetrics.map(([, d]) => Number(d.maxTime));

  const studentData = metricsMap[studentId];
  if (!studentData) {
    return { ner: 0, nrs: 0, nts: 0, cds: 0, classification: 'Unscored', hasFlaggedAttempt: false, integrityFlagCount: 0 };
  }

  // Integrity-flagged students get special classification (pending review)
  if (liveExcludedStudents.has(studentId)) {
    return {
      ner: null, nrs: null, nts: null, cds: null,
      classification: 'Flagged-Pending',
      hasFlaggedAttempt: studentData.hasFlaggedAttempt,
      integrityFlagCount: studentData.integrityFlagCount
    };
  }

  const ner = getNormalizedValue(Number(studentData.failed), failedValues).normalized;
  const nrs = getNormalizedValue(Number(studentData.total), totalValues).normalized;
  const nts = getNormalizedValue(Number(studentData.maxTime), timeValues).normalized;

  const cds = Math.min(1, (0.40 * ner) + (0.35 * nrs) + (0.25 * nts));

  return {
    ner: Number(parseFloat(ner).toFixed(2)),
    nrs: Number(parseFloat(nrs).toFixed(2)),
    nts: Number(parseFloat(nts).toFixed(2)),
    cds: Number(parseFloat(cds).toFixed(2)),
    classification: classify(cds),
    hasFlaggedAttempt: studentData.hasFlaggedAttempt,
    integrityFlagCount: studentData.integrityFlagCount
  };
} catch (err) {
  console.error('Error calculating live CDS:', err);
  return { ner: 0, nrs: 0, nts: 0, cds: 0, classification: 'Unscored', hasFlaggedAttempt: false, integrityFlagCount: 0 };
}
}

module.exports = { computeBatchCDS, getLivePeerRanking, calculateLiveCDS, classify, CDS_THRESHOLDS, computeClassStats, normalizeWithStats };
