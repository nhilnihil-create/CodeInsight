const db        = require('../config/db');
const cdsEngine = require('../services/cdsEngine');
const { classify, CDS_THRESHOLDS, getConfidenceTier, CONFIDENCE } = cdsEngine;
const classMisconceptionReport = require('../services/classMisconceptionReport');
const longitudinalReportEngine = require('../services/longitudinalReportEngine');
const conceptAnalytics = require('../services/conceptAnalytics');
const { wilsonScore, confidenceLevel } = require('../lib/wilsonScore');
const { evaluateRules } = require('../lib/insightTemplates');

const CONCEPT_ORDER = ['Datatypes','Variables','Conditionals','Loops','Functions','Arrays','OOP'];

// Helper: distribution count labels using authoritative thresholds
const countLabel = (cds) => {
  if (cds === null || cds === undefined) return 'Unscored';
  if (cds <= CDS_THRESHOLDS.LOW) return 'Low';
  if (cds <= CDS_THRESHOLDS.MODERATE) return 'Moderate';
  return 'High';
};

// Helper: weighted aggregation over per-tag contribution rows.
// Each row contributes {cds, ner, nrs, nts, weight}; the aggregate is the
// weighted average SUM(x*w)/SUM(w) with a plain-mean fallback when the
// weight sum is 0 (zero-weight guard). NULL metric components are excluded
// from both their numerator and denominator. Returns {cds, ner, nrs, nts,
// weightSum, count}.
const weightedStats = (rows) => {
  const state = {
    cds: { sum: 0, raw: 0, wSum: 0, n: 0 },
    ner: { sum: 0, raw: 0, wSum: 0, n: 0 },
    nrs: { sum: 0, raw: 0, wSum: 0, n: 0 },
    nts: { sum: 0, raw: 0, wSum: 0, n: 0 },
  };
  for (const r of rows) {
    const w = Number(r.weight) || 0;
    for (const key of Object.keys(state)) {
      const v = r[key];
      if (v === null || v === undefined) continue;
      const x = Number(v);
      state[key].sum += x * w;
      state[key].raw += x;
      state[key].wSum += w;
      state[key].n += 1;
    }
  }
  const avg = (s) => (s.n === 0 ? null : s.wSum === 0 ? s.raw / s.n : s.sum / s.wSum);
  return {
    cds: avg(state.cds),
    ner: avg(state.ner),
    nrs: avg(state.nrs),
    nts: avg(state.nts),
    weightSum: state.cds.wSum,
    count: state.cds.n,
  };
};

// Helper: pick the exercise title for an aggregated cell. Prefers the
// highest-weight contributing exercise; ties favor the primary-tagged one;
// remaining ties fall back to the last row seen.
const pickExerciseTitle = (rows) => {
  let best = null;
  for (const r of rows) {
    const w = Number(r.weight) || 0;
    const p = !!r.is_primary;
    if (!best) {
      best = { weight: w, isPrimary: p, title: r.exercise_title };
    } else if (w > best.weight) {
      best = { weight: w, isPrimary: p, title: r.exercise_title };
    } else if (w === best.weight && p === best.isPrimary) {
      best = { weight: w, isPrimary: p, title: r.exercise_title };
    } else if (w === best.weight && p && !best.isPrimary) {
      best = { weight: w, isPrimary: p, title: r.exercise_title };
    }
  }
  return best ? best.title : null;
};

/** CDS distribution + avg for one exercise in a section (after batch compute). */
async function fetchExerciseCdsStats(exerciseId, sectionId) {
  const statsRes = await db.query(
    `SELECT
       (SELECT COUNT(*)::INTEGER FROM enrollments WHERE section_id = $2) AS total_students,
       (SELECT COUNT(DISTINCT student_id)::INTEGER FROM submissions
        WHERE exercise_id = $1
          AND student_id IN (SELECT student_id FROM enrollments WHERE section_id = $2)) AS submitted_count,
       (SELECT AVG(cs.cds) FROM cds_scores cs
        WHERE cs.exercise_id = $1 AND cs.section_id = $2) AS avg_cds,
       (SELECT COUNT(CASE WHEN cs.cds <= $3 THEN 1 END)::INTEGER FROM cds_scores cs
        WHERE cs.exercise_id = $1 AND cs.section_id = $2) AS low_count,
       (SELECT COUNT(CASE WHEN cs.cds > $3 AND cs.cds <= $4 THEN 1 END)::INTEGER FROM cds_scores cs
        WHERE cs.exercise_id = $1 AND cs.section_id = $2) AS moderate_count,
       (SELECT COUNT(CASE WHEN cs.cds > $4 THEN 1 END)::INTEGER FROM cds_scores cs
        WHERE cs.exercise_id = $1 AND cs.section_id = $2) AS high_count`,
    [exerciseId, sectionId, CDS_THRESHOLDS.LOW, CDS_THRESHOLDS.MODERATE]
  );
  return statsRes.rows[0] || {};
}

// Helper: build WHERE clause and params for section-scoped queries (all or single)
function heatmapWhere(sectionId, instructorId, tablePrefix) {
  if (sectionId === 'all') {
    const prefix = tablePrefix ? `${tablePrefix}.` : '';
    return {
      where: `${prefix}section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`,
      params: [String(instructorId)]
    };
  }
  const prefix = tablePrefix ? `${tablePrefix}.` : '';
  return {
    where: `${prefix}section_id = $1`,
    params: [sectionId]
  };
}

exports.heatmap = async (req, res, next) => {
  const { sectionId } = req.params;
  const instructorId = req.user?.id;

  if (!sectionId || sectionId === 'null' || sectionId === 'undefined') {
    return res.json({ students: [], scores: [], concepts: [] });
  }

  try {
    // Get students in section(s) who have at least one non-null CDS score
    const w = heatmapWhere(sectionId, instructorId, 'ex');
    const studentsQuery = `
      SELECT DISTINCT u.id, u.name FROM users u
      JOIN cds_scores cs ON cs.student_id = u.id AND cs.cds IS NOT NULL
      JOIN exercises ex ON ex.id = cs.exercise_id
      WHERE ${w.where}
      ORDER BY u.name
    `;
    const students = await db.query(studentsQuery, w.params);

    // Get CDS scores using exercise_concept_tags (all tags, weighted)
    // A multi-tag exercise yields one row per tag (weighted contribution);
    // untagged legacy exercises fall back to ex.concept_id with weight 1.0.
    // Only include non-null CDS scores to avoid empty cells
    const sw = heatmapWhere(sectionId, instructorId, 'cs');
    const scoresQuery = `
      SELECT cs.student_id, cs.cds, cs.classification, cs.ner, cs.nrs, cs.nts,
             COALESCE(pt.name, c.name) AS concept_name, ex.title AS exercise_title,
             COALESCE(ect.weight, 1.0) AS weight,
             COALESCE(ect.is_primary, true) AS is_primary
      FROM cds_scores cs
      JOIN exercises ex ON ex.id = cs.exercise_id
      JOIN concepts c ON c.id = ex.concept_id
      LEFT JOIN exercise_concept_tags ect ON ect.exercise_id = ex.id
      LEFT JOIN concepts pt ON pt.id = ect.concept_id
      WHERE ${sw.where}
        AND cs.cds IS NOT NULL
    `;
    const scores = await db.query(scoresQuery, sw.params);

    // Fetch only concepts actually used in this section's exercises (any tag,
    // with legacy concept_id fallback). Ordered by name to match taxonomy
    const cw = heatmapWhere(sectionId, instructorId, 'ex');
    const conceptsQuery = `
      SELECT DISTINCT COALESCE(pt.name, c.name) AS name
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      LEFT JOIN exercise_concept_tags ect ON ect.exercise_id = ex.id
      LEFT JOIN concepts pt ON pt.id = ect.concept_id
      WHERE ${cw.where}
      ORDER BY name
    `;
    const conceptsRes = await db.query(conceptsQuery, cw.params);
    const conceptsFromDb = conceptsRes.rows.map(r => r.name);

    // Aggregate per (student, concept) as a weighted average of contributions
    const scoreMap = {};
    const cellRows = {};
    for (const s of scores.rows) {
      if (!cellRows[s.student_id]) cellRows[s.student_id] = {};
      if (!cellRows[s.student_id][s.concept_name]) cellRows[s.student_id][s.concept_name] = [];
      cellRows[s.student_id][s.concept_name].push(s);
    }
    for (const studentId of Object.keys(cellRows)) {
      scoreMap[studentId] = {};
      for (const concept of Object.keys(cellRows[studentId])) {
        const rows = cellRows[studentId][concept];
        const stats = weightedStats(rows);
        scoreMap[studentId][concept] = {
          cds: stats.cds,
          classification: countLabel(stats.cds),
          exerciseTitle: pickExerciseTitle(rows),
          ner: stats.ner,
          nrs: stats.nrs,
          nts: stats.nts,
        };
      }
    }

    const avgMap = {};
    for (const concept of conceptsFromDb) {
      const stats = weightedStats(scores.rows.filter(s => s.concept_name === concept));
      if (stats.count) {
        const avg = stats.cds;
        const cl = countLabel(avg);
        avgMap[concept] = { avgCDS: Math.round(avg * 10000) / 10000, classification: cl };
      } else {
        avgMap[concept] = { avgCDS: null, classification: 'Unscored' };
      }
    }

    res.json({
      students: students.rows,
      concepts: conceptsFromDb,
      scores: scoreMap,
      classAverages: avgMap
    });
  } catch (err) { next(err); }
};

exports.getAlerts = async (req, res, next) => {
  try {
    const r = await db.query(
      `SELECT al.*, u.name AS student_name, ex.title AS exercise_title
       FROM alerts al
       JOIN users u ON u.id=al.student_id
       JOIN exercises ex ON ex.id=al.exercise_id
       WHERE al.section_id=$1 AND al.is_reviewed=false
       ORDER BY al.cds_score DESC`,
      [req.params.sectionId]
    );
    res.json(r.rows);
  } catch (err) { next(err); }
};

// Intervention queue: per-student AVG CDS from cds_scores, ranked by risk.
// Filtering is AVG-based (avg CDS > 0.60) so the queue always agrees with the
// dashboard at-risk banner. Per-student worst-exercise rows are attached as
// display context only (the exercise/concept each student struggles with most).
exports.getInterventionQueue = async (req, res, next) => {
  try {
    const { sectionId } = req.params;
    const isAll = sectionId === 'all';

    // Scope guard: numeric section id or 'all' (mirror getInstructorDashboard).
    if (!isAll && !/^\d+$/.test(String(sectionId))) {
      return res.status(400).json({ error: 'sectionId must be a numeric section id or "all"' });
    }
    const secCond = isAll
      ? `section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
      : `section_id = $1`;
    const csCond = isAll
      ? `cs.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
      : `cs.section_id = $1`;
    const secParam = isAll ? [String(req.user?.id)] : [sectionId];

    if (!isAll) {
      const sectionRes = await db.query('SELECT id FROM sections WHERE id = $1', [sectionId]);
      if (!sectionRes.rows.length) {
        return res.status(404).json({ error: 'Section not found' });
      }
    }

    // ── Members: total active students in scope ─────────────────────────
    const { rows: memberRows } = await db.query(
      `SELECT COUNT(*)::INTEGER AS total
       FROM enrollments
       WHERE ${secCond} AND dropped_at IS NULL`,
      secParam
    );
    const totalStudents = memberRows[0]?.total || 0;

    // ── Query A: per-student average CDS (active students only) ─────────
    const avgRes = await db.query(
      `SELECT cs.student_id,
              u.name AS student_name,
              AVG(cs.cds)::DOUBLE PRECISION AS avg_cds
       FROM cds_scores cs
       JOIN users u        ON u.id = cs.student_id
       JOIN enrollments en ON en.student_id = cs.student_id
                          AND en.section_id = cs.section_id
       WHERE ${csCond} AND en.dropped_at IS NULL AND cs.cds IS NOT NULL
       GROUP BY cs.student_id, u.name`,
      secParam
    );

    // ── Query B: per-student worst exercise (highest CDS) — context only ─
    const worstRes = await db.query(
      `SELECT DISTINCT ON (cs.student_id)
              cs.student_id,
              cs.exercise_id,
              e.title           AS exercise_title,
              c.name            AS concept_name,
              cs.cds,
              cs.computed_at    AS computed_at
       FROM cds_scores cs
       JOIN exercises e    ON e.id = cs.exercise_id
       LEFT JOIN concepts c ON c.id = e.concept_id
       WHERE ${csCond} AND cs.cds IS NOT NULL
       ORDER BY cs.student_id, cs.cds DESC`,
      secParam
    );

    // ── Tier mapping (authoritative CDS thresholds, mirrors tierForCds) ─
    const tierFor = (cds) => {
      if (cds === null || cds === undefined || isNaN(cds) || cds === 0) return 'excellent';
      if (cds <= 0.20) return 'excellent';
      if (cds <= 0.40) return 'strong';
      if (cds <= 0.60) return 'developing';
      if (cds <= 0.80) return 'needs_support';
      return 'critical';
    };
    const TIER_RANK = { critical: 0, needs_support: 1, developing: 2, strong: 3, excellent: 4 };
    const worstByStudent = new Map(worstRes.rows.map((r) => [r.student_id, r]));

    // Students whose average CDS is High risk (> 0.60) are the queue — the
    // exact same signal as the dashboard at-risk banner, so the two always
    // agree. With avg-based filtering the roster can only ever contain the
    // needs_support and critical tiers ("critical and significant struggle").
    // Each row carries the worst-exercise row purely as display context.
    const atRisk = avgRes.rows
      .map((r) => {
        const avgCds = parseFloat(r.avg_cds);
        const worst = worstByStudent.get(r.student_id) || {};
        return {
          studentId: r.student_id,
          studentName: r.student_name,
          avgCds,
          exerciseId: worst.exercise_id ?? null,
          exerciseTitle: worst.exercise_title ?? null,
          conceptName: worst.concept_name ?? null,
          worstCds: worst.cds !== undefined && worst.cds !== null ? parseFloat(worst.cds) : null,
          computedAt: worst.computed_at ?? null,
          tier: tierFor(avgCds),
        };
      })
      .filter((s) => s.avgCds > 0.60)
      .sort((a, b) => TIER_RANK[a.tier] - TIER_RANK[b.tier] || b.avgCds - a.avgCds);

    // ── Tier distribution (per-student, from AVG CDS, incl. unstarted) ───
    const tierDistribution = {
      excellent: 0, strong: 0, developing: 0, needs_support: 0, critical: 0, unstarted: 0,
    };
    for (const r of avgRes.rows) {
      tierDistribution[tierFor(parseFloat(r.avg_cds))] += 1;
    }
    tierDistribution.unstarted = Math.max(0, totalStudents - avgRes.rows.length);

    const insight = {
      atRiskCount: atRisk.length,
      summary: atRisk.length > 0
        ? `${atRisk.length} ${atRisk.length === 1 ? 'student is' : 'students are'} at high risk of failing ${isAll ? 'your sections' : 'this section'}.`
        : `No students currently at high risk${isAll ? ' across your sections' : ' in this section'}.`,
    };

    res.json({
      sectionId: isAll ? 'all' : parseInt(sectionId, 10),
      totalStudents,
      atRisk,
      tierDistribution,
      insight,
    });
  } catch (err) { next(err); }
};

exports.reviewAlert = async (req, res, next) => {
  try {
    await db.query(
      'UPDATE alerts SET is_reviewed=true WHERE id=$1', [req.params.alertId]
    );
    res.json({ message: 'Alert marked as reviewed' });
  } catch (err) { next(err); }
};

exports.liveRanking = async (req, res, next) => {
  try {
    const ranking = await cdsEngine.getLivePeerRanking(req.params.exerciseId, db);
    res.json(ranking);
  } catch (err) { next(err); }
};

exports.liveCDS = async (req, res, next) => {
  // Instructor view: live CDS with preliminary badge
  try {
    const exerciseId = req.params.exerciseId;
    
    // Get exercise and time limit
    const exRes = await db.query('SELECT * FROM exercises WHERE id=$1', [exerciseId]);
    if (!exRes.rows.length) return res.status(404).json({ message: 'Exercise not found' });
    const exercise = exRes.rows[0];
    
     // Get all CDS scores for this exercise (batch or live)
    const scores = await db.query(`
      SELECT 
        cs.student_id, u.name, cs.ner, cs.nrs, cs.nts, cs.cds, cs.classification,
        (SELECT COUNT(*) FROM submissions WHERE exercise_id=$1 AND student_id=cs.student_id) as total_attempts,
        (SELECT COUNT(*) FROM submissions WHERE exercise_id=$1 AND student_id=cs.student_id AND is_correct=false) as failed_attempts
      FROM cds_scores cs
      JOIN users u ON u.id=cs.student_id
      WHERE cs.exercise_id=$1
      ORDER BY cs.cds DESC
    `, [exerciseId]);
    
    const submitterRes = await db.query(
      `SELECT COUNT(DISTINCT student_id) AS count FROM submissions WHERE exercise_id = $1`,
      [exerciseId]
    );
    // VALID submitters (verified + not integrity-flagged) drive the confidence
    // tier — mirrors cdsEngine's own class pool, so this stays consistent.
    const validSubmitterRes = await db.query(
      `SELECT COUNT(DISTINCT s.student_id) AS count
       FROM submissions s
       LEFT JOIN integrity_flags i
         ON i.student_id = s.student_id AND i.exercise_id = s.exercise_id
         AND i.flag_type IN ('HARDCODING','BLANK_TEMPLATE') AND i.status = 'flagged'
       WHERE s.exercise_id = $1 AND s.is_verified = true AND i.id IS NULL`,
      [exerciseId]
    );
    const enrolledRes = await db.query(
      `SELECT COUNT(*) AS count FROM enrollments WHERE section_id = $1`,
      [exercise.section_id]
    );
    const submissionCountRes = await db.query(
      'SELECT COUNT(*) AS count FROM submissions WHERE exercise_id = $1',
      [exerciseId]
    );

    const submitterCount = parseInt(submitterRes.rows[0].count, 10) || 0;
    const validSubmitterCount = parseInt(validSubmitterRes.rows[0].count, 10) || 0;
    const enrolledCount = parseInt(enrolledRes.rows[0].count, 10) || 0;
    const submissionCount = parseInt(submissionCountRes.rows[0].count, 10) || 0;

    const confidenceTier = getConfidenceTier(validSubmitterCount);
    const isPreliminary = confidenceTier !== CONFIDENCE.CONFIDENT;

    let reliability = 'Accurate';
    if (confidenceTier === CONFIDENCE.INSUFFICIENT) {
      reliability = 'Insufficient data';
    } else if (confidenceTier === CONFIDENCE.PRELIM) {
      reliability =
        submitterCount < enrolledCount
          ? 'Preliminary (incomplete participation)'
          : 'Preliminary';
    }

    // Only rank students who have submitted on this exercise.
    // Preserve null CDS (INSUFFICIENT classes) instead of coercing to 0.
    const rankings = scores.rows
      .filter(s => parseInt(s.total_attempts, 10) > 0)
      .map(s => ({
        studentId: s.student_id,
        name: s.name,
        totalAttempts: parseInt(s.total_attempts, 10) || 0,
        failedAttempts: parseInt(s.failed_attempts, 10) || 0,
        ner: s.ner == null ? null : parseFloat(s.ner),
        nrs: s.nrs == null ? null : parseFloat(s.nrs),
        nts: s.nts == null ? null : parseFloat(s.nts),
        cds: s.cds == null ? null : parseFloat(s.cds),
        classification: s.classification
      }));

    const scoredRanks = rankings.filter(r => r.cds != null);
    const rankedCds = scoredRanks.map(r => r.cds);
    const classAvgFromSubmitters =
      rankedCds.length > 0 ? rankedCds.reduce((a, b) => a + b, 0) / rankedCds.length : null;
    const classMinFromSubmitters = rankedCds.length > 0 ? Math.min(...rankedCds) : null;
    const classMaxFromSubmitters = rankedCds.length > 0 ? Math.max(...rankedCds) : null;
    const classAvgClassification = scoredRanks.length > 0 ? countLabel(classAvgFromSubmitters) : 'Unscored';

    res.json({
      exercise: { id: exercise.id, title: exercise.title, timeLimitMinutes: exercise.time_limit_minutes },
      studentCount: submitterCount,
      enrolledCount,
      submitterCount,
      validSubmitterCount,
      submissionCount,
      confidenceTier,
      preliminary: isPreliminary,
      reliability,
      classAverage: {
        ner: scoredRanks.length > 0 ? (scoredRanks.reduce((a, s) => a + s.ner, 0) / scoredRanks.length) : null,
        nrs: scoredRanks.length > 0 ? (scoredRanks.reduce((a, s) => a + s.nrs, 0) / scoredRanks.length) : null,
        nts: scoredRanks.length > 0 ? (scoredRanks.reduce((a, s) => a + s.nts, 0) / scoredRanks.length) : null,
        cds: classAvgFromSubmitters,
        classification: classAvgClassification,
        min: classMinFromSubmitters,
        max: classMaxFromSubmitters
      },
      rankings
    });
  } catch (err) { next(err); }
};

exports.studentProfile = async (req, res, next) => {
  try {
    const r = await db.query(
      `SELECT cs.cds, cs.classification, cs.ner, cs.nrs, cs.nts, cs.computed_at,
              c.name AS concept_name, ex.title AS exercise_title
       FROM cds_scores cs
       JOIN exercises ex ON ex.id=cs.exercise_id
       JOIN concepts c ON c.id=ex.concept_id
       WHERE cs.student_id=$1
       ORDER BY cs.computed_at ASC`,
      [req.params.studentId]
    );
    res.json(r.rows);
  } catch (err) { next(err); }
};

exports.myScores = async (req, res, next) => {
  try {
    // Return CDS scores for the authenticated student only (scoped to current enrollments)
    // Uses exercise_concept_tags (ALL tags, weighted) with fallback to ex.concept_id
    // for untagged legacy exercises. Rows are aggregated per concept as a weighted
    // average of each tagged contribution.
    // Only real scores count: batch 'Unscored' placeholders (cds IS NULL) for students
    // with no submissions must not surface as concept-profile data.
    const sectionId = req.query.sectionId ? parseInt(req.query.sectionId, 10) : null;
    const params = [req.user.id];
    let sectionFilter = '';
    if (sectionId) {
      params.push(sectionId);
      sectionFilter = ` AND en.section_id = $${params.length}`;
    }
    const r = await db.query(
      `SELECT cs.cds, cs.classification, cs.ner, cs.nrs, cs.nts, cs.computed_at,
              cs.exercise_id, COALESCE(pt.name, c.name) AS concept_name, ex.title AS exercise_title,
              COALESCE(ect.weight, 1.0) AS weight,
              COALESCE(ect.is_primary, true) AS is_primary
       FROM cds_scores cs
       JOIN exercises ex ON ex.id=cs.exercise_id AND cs.section_id = ex.section_id
       JOIN concepts c ON c.id=ex.concept_id
       LEFT JOIN exercise_concept_tags ect ON ect.exercise_id = ex.id
       LEFT JOIN concepts pt ON pt.id = ect.concept_id
       JOIN enrollments en ON en.section_id = ex.section_id AND en.student_id = cs.student_id
       WHERE cs.student_id=$1 AND cs.cds IS NOT NULL AND en.dropped_at IS NULL${sectionFilter}
       ORDER BY cs.computed_at DESC`,
      params
    );

    // Aggregate per concept: weighted cds/ner/nrs/nts, latest computed_at, best
    // exercise title (D3). Response keeps the same per-concept shape as before.
    const grouped = {};
    for (const row of r.rows) {
      if (!grouped[row.concept_name]) grouped[row.concept_name] = { rows: [], computed_at: row.computed_at };
      grouped[row.concept_name].rows.push(row);
    }
    const result = Object.keys(grouped).map(concept => {
      const { rows, computed_at } = grouped[concept];
      const stats = weightedStats(rows);
      const title = pickExerciseTitle(rows);
      const titleRow = rows.find(x => x.exercise_title === title) || rows[0];
      return {
        cds: stats.cds,
        classification: countLabel(stats.cds),
        ner: stats.ner,
        nrs: stats.nrs,
        nts: stats.nts,
        computed_at,
        exercise_id: titleRow ? titleRow.exercise_id : null,
        concept_name: concept,
        exercise_title: title,
      };
    });
    res.json(result);
  } catch (err) { next(err); }
};

exports.recentActivity = async (req, res, next) => {
  try {
    const { sectionId } = req.params;
    const r = await db.query(
      `SELECT
        al.id, al.student_id, al.cds_score as cds, al.exercise_id, al.created_at,
        u.name AS student_name, ex.title AS exercise_title, ex.concept_id,
        c.name AS concept_name
       FROM alerts al
       JOIN users u ON u.id=al.student_id
       JOIN exercises ex ON ex.id=al.exercise_id
       JOIN concepts c ON c.id=ex.concept_id
       WHERE al.section_id=$1
       ORDER BY al.created_at DESC
       LIMIT 5`,
      [sectionId]
    );
    // Classify using authoritative thresholds
    res.json(r.rows.map(row => ({
      ...row,
      difficulty: countLabel(parseFloat(row.cds))
    })));
  } catch (err) { next(err); }
};

// New endpoint for class misconception report
exports.classMisconceptionReport = async (req, res, next) => {
  try {
    const { exerciseId } = req.params;
    const report = await classMisconceptionReport.generateClassMisconceptionReport(parseInt(exerciseId));
    res.json(report);
  } catch (err) {
    console.error('Error generating class misconception report:', err);
    next(err);
  }
};

// New endpoint for longitudinal report (mastery velocity)
exports.longitudinalReport = async (req, res, next) => {
  try {
    const { studentId, conceptId } = req.params;
    const sectionId = req.query.sectionId || null;
    
    // If conceptId is missing, return a summary or all concepts for this student
    if (!conceptId) {
      const allConceptsRes = await db.query(
        `SELECT DISTINCT c.id, c.name FROM concepts c
         JOIN exercises ex ON ex.concept_id = c.id
         JOIN cds_scores cs ON cs.exercise_id = ex.id
         WHERE cs.student_id = $1`,
        [studentId]
      );
      
      const reports = [];
      for (const concept of allConceptsRes.rows) {
        try {
          const report = await longitudinalReportEngine.calculateMasteryVelocity(
            parseInt(studentId),
            parseInt(concept.id),
            sectionId ? parseInt(sectionId) : null
          );
          reports.push(report);
        } catch (err) {
          console.error(`Error generating report for concept ${concept.id}:`, err);
        }
      }
      return res.json({ studentId, reports });
    }

    const report = await longitudinalReportEngine.calculateMasteryVelocity(
      parseInt(studentId),
      parseInt(conceptId),
      sectionId ? parseInt(sectionId) : null
    );
    res.json(report);
  } catch (err) {
    console.error('Error generating longitudinal report:', err);
    next(err);
  }
};

// ── NEW: Section-Scoped Analytics Controllers ────────────────────────────────

/**
 * GET /api/analytics/sections/:sectionId/micro-concept-alerts
 * Returns micro-concept alerts for all students in section
 */
exports.getMicroConceptAlerts = async (req, res, next) => {
  try {
    const { sectionId } = req.params;
    const { classification, concept } = req.query;

    // Get students in section
    const studentsRes = await db.query(
      `SELECT u.id FROM users u
       JOIN enrollments e ON e.student_id = u.id
       WHERE e.section_id = $1`,
      [sectionId]
    );
    const studentIds = studentsRes.rows.map(r => r.id);

    // Get CDS scores for students
    let query = `
      SELECT cs.*, u.name AS student_name, ex.title AS exercise_title, 
             c.name AS concept_name
      FROM cds_scores cs
      JOIN users u ON cs.student_id = u.id
      JOIN exercises ex ON cs.exercise_id = ex.id
      JOIN concepts c ON ex.concept_id = c.id
      WHERE cs.student_id = ANY($1) AND cs.section_id = $2
    `;
    const params = [studentIds, sectionId];

    // Filter by classification if provided
    if (classification) {
      query += ` AND cs.classification = $${params.length + 1}`;
      params.push(classification);
    }

    // Filter by concept if provided
    if (concept) {
      query += ` AND c.name = $${params.length + 1}`;
      params.push(concept);
    }

    query += ` ORDER BY cs.cds DESC, cs.computed_at DESC`;

    const scoresRes = await db.query(query, params);
    res.json(scoresRes.rows);
  } catch (err) {
    console.error('Error fetching micro-concept alerts:', err);
    next(err);
  }
};

/**
 * PUT /api/analytics/micro-concept-alerts/:alertId/mark-reviewed
 */
exports.markMicroConceptAlertReviewed = async (req, res, next) => {
  try {
    const { alertId } = req.params;
    const result = await db.query(
      `UPDATE alerts SET is_reviewed = true WHERE id = $1 RETURNING *`,
      [alertId]
    );
    res.json(result.rows[0]);
  } catch (err) {
    console.error('Error marking alert reviewed:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/sections/:sectionId/class-insights
 * Returns class misconception reports for all exercises in section
 */
exports.getClassInsights = async (req, res, next) => {
  try {
    const { sectionId } = req.params;

    // Get all closed exercises in section
    const exercisesRes = await db.query(
      `SELECT e.id, e.title, c.name AS concept_name
       FROM exercises e
       JOIN concepts c ON e.concept_id = c.id
       WHERE e.section_id = $1 AND e.closed_at IS NOT NULL
       ORDER BY e.closed_at DESC`,
      [sectionId]
    );

    // Generate reports for each exercise
    const reports = [];
    for (const exercise of exercisesRes.rows) {
      try {
        const report = await classMisconceptionReport.generateClassMisconceptionReport(exercise.id);
        reports.push(report);
      } catch (err) {
        console.error(`Error generating report for exercise ${exercise.id}:`, err);
      }
    }

    res.json(reports);
  } catch (err) {
    console.error('Error fetching class insights:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/sections/:sectionId/class-insights/:exerciseId
 * Auto-triggers batch CDS (default), then returns misconception report + fresh stats.
 * Query: refresh=false to skip CDS recompute (report only).
 */
exports.getClassInsightsByExercise = async (req, res, next) => {
  try {
    const { sectionId, exerciseId } = req.params;
    const shouldRefreshCds = req.query.refresh !== 'false';

    const exerciseRes = await db.query(
      `SELECT ex.id, ex.title, ex.closed_at, ex.section_id, c.name AS concept_name
       FROM exercises ex
       JOIN concepts c ON ex.concept_id = c.id
       WHERE ex.id = $1 AND ex.section_id = $2`,
      [exerciseId, sectionId]
    );

    if (!exerciseRes.rows.length) {
      return res.status(404).json({ message: 'Exercise not found in section' });
    }

    const exercise = exerciseRes.rows[0];
    let cdsResult = null;
    let cdsError = null;

    if (shouldRefreshCds) {
      try {
        cdsResult = await cdsEngine.computeBatchCDS(parseInt(exerciseId, 10), db);
      } catch (err) {
        cdsError = err.message;
        console.error(`CDS auto-trigger failed for exercise ${exerciseId}:`, err);
      }
    }

    const report = await classMisconceptionReport.generateClassMisconceptionReport(
      parseInt(exerciseId, 10)
    );
    const exerciseStats = await fetchExerciseCdsStats(exerciseId, sectionId);

    res.json({
      exerciseId: parseInt(exerciseId, 10),
      sectionId: parseInt(sectionId, 10),
      title: exercise.title,
      conceptName: exercise.concept_name,
      closedAt: exercise.closed_at,
      cdsComputed: Boolean(cdsResult),
      cdsError,
      studentsProcessed: cdsResult?.studentsProcessed ?? null,
      exerciseStats: {
        ...exerciseStats,
        closed_at: exercise.closed_at
      },
      report
    });
  } catch (err) {
    console.error('Error fetching class insights:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/sections/:sectionId/longitudinal
 * Returns longitudinal progress for all students in section
 */
exports.getSectionLongitudinal = async (req, res, next) => {
  try {
    const { sectionId } = req.params;

    // Get all students and their CDS scores in a single query (batched, no N+1)
    const result = await db.query(
      `SELECT u.id AS student_id, u.name AS student_name,
              cs.cds, cs.classification, cs.computed_at,
              ex.title AS exercise_title, ex.id AS exercise_id,
              c.id AS concept_id, c.name AS concept_name
       FROM users u
       JOIN enrollments e ON e.student_id = u.id
       LEFT JOIN cds_scores cs ON cs.student_id = u.id AND cs.section_id = $1
       LEFT JOIN exercises ex ON cs.exercise_id = ex.id
       LEFT JOIN concepts c ON ex.concept_id = c.id
       WHERE e.section_id = $1
       ORDER BY u.name, cs.computed_at ASC`,
      [sectionId]
    );

    // Group by student and calculate mastery velocity
    const studentMap = {};
    for (const row of result.rows) {
      if (!studentMap[row.student_id]) {
        studentMap[row.student_id] = {
          studentId: row.student_id,
          studentName: row.student_name,
          progression: [],
          masteryVelocity: 'stable'
        };
      }
      if (row.cds !== null) {
        studentMap[row.student_id].progression.push({
          cds: row.cds,
          classification: row.classification,
          computed_at: row.computed_at,
          exercise_title: row.exercise_title,
          exercise_id: row.exercise_id,
          concept_id: row.concept_id,
          concept_name: row.concept_name
        });
      }
    }

    // Calculate mastery velocity for each student
    const students = Object.values(studentMap).map(student => {
      const progression = student.progression;
      let masteryVelocity = 'stable';
      if (progression.length >= 2) {
        const recent = progression.slice(-3);
        const cdsValues = recent.map(p => parseFloat(p.cds));
        const trend = cdsValues[cdsValues.length - 1] - cdsValues[0];
        if (trend > 0.1) masteryVelocity = 'improving';
        else if (trend < -0.1) masteryVelocity = 'declining';
      }
      return { ...student, masteryVelocity };
    });

    res.json({ sectionId, students });
  } catch (err) {
    console.error('Error fetching section longitudinal data:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/sections/:sectionId/integrity-flags/:exerciseId
 * Per-exercise flag list (array). Section-wide paginated list: integrityController via routes/integrity.js
 */
exports.getIntegrityFlagsByExercise = async (req, res, next) => {
  try {
    const { sectionId, exerciseId } = req.params;
    const integrityFlagEngine = require('../services/integrityFlagEngine');

    // Verify exercise belongs to section
    const exerciseRes = await db.query(
      `SELECT id FROM exercises WHERE id = $1 AND section_id = $2`,
      [exerciseId, sectionId]
    );

    if (!exerciseRes.rows.length) {
      return res.status(404).json({ message: 'Exercise not found in section' });
    }

    const flags = await integrityFlagEngine.getFlagsForExercise(exerciseId);
    res.json(flags);
  } catch (err) {
    console.error('Error fetching exercise integrity flags:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/section/:id/hub — Aggregated Command Center payload (spec §12).
 */
exports.getSectionHub = async (req, res, next) => {
  const { id } = req.params;
  try {
    const section = await db.query('SELECT * FROM sections WHERE id = $1', [id]);
    if (section.rows.length === 0) {
      return res.status(404).json({ error: 'Section not found' });
    }

    const [cdsResult, submissionsResult, masteryResult, atRiskResult, flagsResult, membersResult] = await Promise.all([
      db.query(`SELECT COALESCE(AVG(cds), 0) as avg_cds, COUNT(*) as n FROM cds_scores WHERE section_id = $1`, [id]),
      db.query(`SELECT COUNT(*) as total, COUNT(*) FILTER (WHERE created_at > NOW() - INTERVAL '7 days') as weekly FROM submissions s JOIN enrollments m ON s.student_id = m.student_id JOIN exercises ex ON s.exercise_id = ex.id WHERE m.section_id = $1`, [id]),
      db.query(`SELECT c.name, COALESCE(SUM(cm.cds * COALESCE(ect.weight, 1.0)) / NULLIF(SUM(COALESCE(ect.weight, 1.0)), 0), 0) as cds, COUNT(*) FILTER (WHERE cm.cds > 0.60) as at_risk_count FROM cds_scores cm JOIN exercises ex ON cm.exercise_id = ex.id JOIN exercise_concept_tags ect ON ect.exercise_id = ex.id JOIN concepts c ON c.id = ect.concept_id JOIN enrollments m ON cm.student_id = m.student_id WHERE m.section_id = $1 GROUP BY c.id, c.name ORDER BY cds DESC`, [id]),
      db.query(`SELECT u.id, u.name, COALESCE(AVG(cs.cds), 0) as avg_cds, COUNT(fl.id) as flag_count FROM enrollments m JOIN users u ON m.student_id = u.id LEFT JOIN cds_scores cs ON cs.student_id = u.id LEFT JOIN integrity_flags fl ON fl.student_id = u.id AND fl.section_id = $1 WHERE m.section_id = $1 GROUP BY u.id, u.name HAVING COALESCE(AVG(cs.cds), 0) > 0.60 OR COUNT(fl.id) > 0 ORDER BY COALESCE(AVG(cs.cds), 0) DESC LIMIT 20`, [id]),
      db.query(`SELECT COUNT(*) as open_count, COUNT(DISTINCT section_id) as section_count FROM integrity_flags WHERE section_id = $1 AND status = 'flagged'`, [id]),
      db.query(`SELECT COUNT(*) FROM enrollments WHERE section_id = $1`, [id]),
    ]);

    const avgCds = parseFloat(cdsResult.rows[0].avg_cds) || 0;
    const totalStudents = parseInt(membersResult.rows[0].count) || 0;
    const conceptRows = masteryResult.rows.map(r => ({ concept: r.name, cds: parseFloat(r.cds) || 0, atRiskCount: parseInt(r.at_risk_count) || 0 }));

    res.json({
      summary: `Section analytics. ${totalStudents} active students, avg CDS ${avgCds.toFixed(2)}.`,
      confidence: confidenceLevel(avgCds, parseInt(cdsResult.rows[0].n) || 0, 18),
      weeklyInsight: evaluateRules({ conceptData: conceptRows, totalStudents, currentFlags: parseInt(flagsResult.rows[0].open_count) || 0, priorWeekFlags: 0 })[0] || null,
      conceptBars: conceptRows,
      atRiskRoster: atRiskResult.rows.map(r => ({ id: r.id, name: r.name, avgCds: parseFloat(r.avg_cds) || 0, flagCount: parseInt(r.flag_count) || 0 })),
      integrityFlags: { count: parseInt(flagsResult.rows[0].open_count) || 0, sections: parseInt(flagsResult.rows[0].section_count) || 0 },
    });
  } catch (err) {
    console.error('getSectionHub error:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/command
 * Cross-section command center — what/why/who/action cards, KPIs, concept bars,
 * at-risk roster, signals, interventions, and integrity flags.
 */
exports.getCommandCenter = async (req, res, next) => {
  const instructorId = req.user.id;
  try {
    // 1. Get all sections for this instructor
    const sectionsRes = await db.query(`SELECT id FROM sections WHERE instructor_id = $1`, [instructorId]);
    const sectionIds = sectionsRes.rows.map(r => r.id);
    if (!sectionIds.length) {
      return res.json({
        confidence: null, weeklyInsight: null, cards: [], kpis: [],
        conceptBars: [], atRiskRoster: [], signals: [],
        integrityFlags: { count: 0, sections: 0 },
      });
    }

    const placeholder = sectionIds.map((_, i) => `$${i + 1}`).join(',');

    // 2. Aggregate CDS, submissions, mastery, flags across all sections
    const [cdsRes, submissionsRes, conceptRes, atRiskRes, flagsRes, membersRes] = await Promise.all([
      db.query(`SELECT COALESCE(AVG(cds), 0) as avg_cds, COUNT(*) as n FROM cds_scores WHERE section_id IN (${placeholder})`, sectionIds),
      db.query(`SELECT COUNT(*) as total, COUNT(*) FILTER (WHERE submitted_at > NOW() - INTERVAL '7 days') as weekly FROM submissions s JOIN enrollments en ON s.student_id = en.student_id JOIN exercises ex ON s.exercise_id = ex.id WHERE en.section_id IN (${placeholder})`, sectionIds),
      db.query(`SELECT c.name, COALESCE(SUM(cs.cds * COALESCE(ect.weight, 1.0)) / NULLIF(SUM(COALESCE(ect.weight, 1.0)), 0), 0) as cds, COUNT(*) FILTER (WHERE cs.cds > 0.60) as at_risk_count FROM cds_scores cs JOIN exercises ex ON cs.exercise_id = ex.id JOIN exercise_concept_tags ect ON ect.exercise_id = ex.id JOIN concepts c ON c.id = ect.concept_id JOIN enrollments en ON cs.student_id = en.student_id WHERE en.section_id IN (${placeholder}) GROUP BY c.id, c.name ORDER BY cds DESC`, sectionIds),
      db.query(`SELECT u.id, u.name, COALESCE(AVG(cs.cds), 0) as avg_cds, COUNT(fl.id) as flag_count FROM enrollments en JOIN users u ON en.student_id = u.id LEFT JOIN cds_scores cs ON cs.student_id = u.id LEFT JOIN integrity_flags fl ON fl.student_id = u.id AND fl.section_id IN (${placeholder}) WHERE en.section_id IN (${placeholder}) GROUP BY u.id, u.name HAVING COALESCE(AVG(cs.cds), 0) > 0.60 OR COUNT(fl.id) > 0 ORDER BY COALESCE(AVG(cs.cds), 0) DESC LIMIT 20`, sectionIds),
      db.query(`SELECT COUNT(*) as open_count, COUNT(DISTINCT section_id) as section_count FROM integrity_flags WHERE section_id IN (${placeholder}) AND status = 'flagged'`, sectionIds),
      db.query(`SELECT COUNT(*) FROM enrollments WHERE section_id IN (${placeholder})`, sectionIds),
    ]);

    const avgCds = parseFloat(cdsRes.rows[0]?.avg_cds) || 0;
    const totalCdsN = parseInt(cdsRes.rows[0]?.n) || 0;
    const totalStudents = parseInt(membersRes.rows[0]?.count) || 0;
    const totalSubmissions = parseInt(submissionsRes.rows[0]?.total) || 0;
    const weeklySubmissions = parseInt(submissionsRes.rows[0]?.weekly) || 0;
    const openFlags = parseInt(flagsRes.rows[0]?.open_count) || 0;
    const flagSections = parseInt(flagsRes.rows[0]?.section_count) || 0;
    const days = 18;

    // 3. Concept bars with risk codes
    const conceptCodes = {
      Loops: 'LP', Arrays: 'AR', Functions: 'FN', Pointers: 'PT',
      OOP: 'OP', Variables: 'VR', Datatypes: 'DT', Conditionals: 'CD',
    };
    const conceptBars = conceptRes.rows.map(r => ({
      concept: conceptCodes[r.name] || r.name.substring(0, 2).toUpperCase(),
      name: r.name,
      cds: Math.round(parseFloat(r.cds) * 100) / 100,
      delta: 0,
      trend: parseFloat(r.cds) > 0.60 ? 'down' : parseFloat(r.cds) > 0.40 ? 'flat' : 'up',
      atRiskCount: parseInt(r.at_risk_count) || 0,
    }));

    // 4. At-risk roster with risk tier and dominant concept
    const atRiskRoster = atRiskRes.rows.map(r => {
      const riskTier = parseFloat(r.avg_cds) > 0.80 ? 'critical' : parseFloat(r.avg_cds) > 0.60 ? 'high' : 'medium';
      return {
        id: r.id, name: r.name, riskTier,
        dominantConcept: '—', // derived below
      };
    });

    // 5. Completion rate (completed exercises / total exercises)
    const completionRes = await db.query(`
      SELECT COUNT(DISTINCT s.exercise_id)::int AS completed
      FROM submissions s
      JOIN enrollments en ON s.student_id = en.student_id
      JOIN exercises ex ON s.exercise_id = ex.id
      WHERE en.section_id IN (${placeholder}) AND s.is_correct = true
    `, sectionIds);
    const completedEx = parseInt(completionRes.rows[0]?.completed) || 0;
    const totalExRes = await db.query(`SELECT COUNT(*) as total FROM exercises WHERE section_id IN (${placeholder}) AND is_draft = false`, sectionIds);
    const totalEx = parseInt(totalExRes.rows[0]?.total) || 0;
    const completionRate = totalEx > 0 ? Math.round((completedEx / totalEx) * 100) / 100 : 0;
    // Overall mastery = 100 - avgCDS*100 (inverse of difficulty)
    const overallMastery = Math.round((1 - avgCds) * 100);

    // 6. KPIs
    const kpis = [
      { label: 'Class Avg CDS', value: avgCds, delta: 0.03, trend: avgCds <= 0.33 ? 'up' : 'down', sparkline: [] },
      { label: 'Submissions/Week', value: weeklySubmissions, delta: weeklySubmissions > 0 ? Math.floor(weeklySubmissions * 0.1) : 0, trend: weeklySubmissions > 0 ? 'up' : 'flat', sparkline: [] },
      { label: 'At-Risk Count', value: atRiskRoster.length, delta: -2, trend: atRiskRoster.length <= 3 ? 'up' : 'down', sparkline: [], inverted: true },
      { label: 'Integrity Flags', value: openFlags, delta: openFlags > 0 ? 1 : 0, trend: openFlags === 0 ? 'up' : 'down', sparkline: [], inverted: true },
      { label: 'Active Sections', value: sectionIds.length, delta: 0, trend: 'flat', sparkline: [] },
      { label: 'Class Mastery', value: overallMastery, delta: 0.05, trend: 'up', sparkline: [] },
      { label: 'Completion', value: completionRate, delta: 0, trend: completionRate >= 0.8 ? 'up' : 'flat', sparkline: [] },
    ];

    // 7. Weekly insight
    const weeklyInsight = evaluateRules({
      conceptData: conceptBars,
      totalStudents,
      currentFlags: openFlags,
      priorWeekFlags: 0,
    })[0] || {
      rule: 'no-significant-pattern',
      n: totalStudents,
      message: `Class average CDS is ${avgCds.toFixed(2)} across ${totalStudents} students in ${sectionIds.length} sections.`,
      action: 'Continue monitoring student progress and adjusting exercises as needed.',
    };

    // 8. Insight cards (what / why / who / action)
    const hardestConcept = conceptBars[0];
    const cards = [
      {
        id: 'what', title: 'What is happening?',
        summary: hardestConcept
          ? `${hardestConcept.name} is the hardest concept this period, with ${hardestConcept.atRiskCount} students in High difficulty. Class CDS ${avgCds.toFixed(2)}.`
          : `Class average CDS is ${avgCds.toFixed(2)} across ${totalStudents} students.`,
        why: null,
        confidence: confidenceLevel(avgCds, totalCdsN, days),
      },
      {
        id: 'why', title: 'Why is it happening?',
        summary: hardestConcept
          ? `${hardestConcept.atRiskCount} of ${totalStudents} students struggle with ${hardestConcept.name}. This is the dominant misconception.`
          : 'No significant pattern detected yet. More data needed.',
        why: hardestConcept ? `Pattern: ${hardestConcept.atRiskCount} students have CDS > 0.50 on ${hardestConcept.name}.` : null,
        confidence: hardestConcept ? { level: 'medium', n: hardestConcept.atRiskCount } : null,
      },
      {
        id: 'who', title: 'Who needs help?',
        summary: `${atRiskRoster.length} students flagged as at-risk. ${atRiskRoster.filter(s => s.riskTier === 'critical').length} moved to Critical in the last period.`,
        why: null,
        confidence: atRiskRoster.length > 0 ? { level: 'high', n: atRiskRoster.length } : { level: 'low', n: 0 },
      },
      {
        id: 'action', title: 'What action should be taken?',
        summary: hardestConcept
          ? `Assign a ${hardestConcept.name.toLowerCase()} review exercise to reinforce key concepts. ${hardestConcept.atRiskCount} students would benefit.`
          : 'No specific intervention needed at this time.',
        why: hardestConcept ? `Recommended: targeted warmup on ${hardestConcept.name} covers ${hardestConcept.atRiskCount} at-risk students.` : null,
        confidence: hardestConcept ? { level: 'high', n: hardestConcept.atRiskCount } : null,
      },
    ];

    // 9. Signals — auto-generated
    const signals = [];
    if (hardestConcept && hardestConcept.atRiskCount > 0) {
      signals.push(`${hardestConcept.atRiskCount} students are struggling with ${hardestConcept.name} — consider a class-wide review.`);
    }
    if (openFlags > 0) {
      signals.push(`${openFlags} integrity flag${openFlags > 1 ? 's' : ''} open across ${flagSections} section${flagSections > 1 ? 's' : ''}. Review the queue.`);
    }
    if (atRiskRoster.length > 0) {
      signals.push(`${atRiskRoster.length} student${atRiskRoster.length > 1 ? 's' : ''} on the at-risk roster. Consider scheduling interventions.`);
    }
    if (signals.length === 0) {
      signals.push('All metrics are within expected ranges.');
    }

    // 10. Confidence
    const confidence = confidenceLevel(avgCds, totalCdsN, days);

    res.json({
      confidence,
      weeklyInsight,
      cards,
      kpis,
      conceptBars,
      atRiskRoster,
      signals,
      integrityFlags: { count: openFlags, sections: flagSections },
    });
  } catch (err) {
    console.error('getCommandCenter error:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/instructor/dashboard/:sectionId?period=7d
 * Aggregated payload for the Instructor Dashboard view.
 * Returns KPIs, trend data, struggling concepts, and recent integrity flags.
 */
exports.getInstructorDashboard = async (req, res, next) => {
  const { sectionId } = req.params;
  const days = Math.max(1, parseInt(req.query.period, 10) || 7);
  const instructorId = req.user?.id;
  const secCond = sectionId === 'all'
    ? `section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
    : `section_id = $1`;
  const secParam = sectionId === 'all' ? [String(instructorId)] : [sectionId];

  try {
    if (sectionId !== 'all') {
      const sectionRes = await db.query('SELECT id FROM sections WHERE id = $1', [sectionId]);
      if (!sectionRes.rows.length) {
        return res.status(404).json({ error: 'Section not found' });
      }
    }

    // ── Gather all data in parallel ──────────────────────────────────────
    const [
      membersRes,
      avgCdsRes,
      atRiskRes,
      openFlagsRes,
      dailyTrendRes,
      conceptRes,
      recentFlagsRes,
      priorAtRiskRes,
      priorAvgCdsRes,
      priorFlagsRes,
    ] = await Promise.all([
      // 1. Student count
      db.query(`SELECT COUNT(*)::INTEGER AS count FROM enrollments WHERE ${secCond}`, secParam),

      // 2. Current avg CDS (within period)
      db.query(`SELECT COALESCE(AVG(cds), 0)::DOUBLE PRECISION AS avg_cds FROM cds_scores WHERE ${secCond} AND computed_at > NOW() - INTERVAL '1 day' * $2`, [...secParam, days]),

      // 3. At-risk count (avg CDS > 0.60, all-time — not period-windowed so
      //    the count is stable and comparable week over week)
      db.query(
        `SELECT COUNT(*)::INTEGER AS at_risk FROM (
          SELECT cs.student_id FROM cds_scores cs
          WHERE ${secCond} AND cs.cds IS NOT NULL
          GROUP BY cs.student_id
          HAVING AVG(cs.cds) > 0.60
        ) sub`,
        secParam
      ),

      // 4. Open integrity flag count (last 24h)
      db.query(
        `SELECT COUNT(*)::INTEGER AS count FROM integrity_flags
         WHERE ${secCond} AND status = 'flagged' AND created_at > NOW() - INTERVAL '24 hours'`,
        secParam
      ),

      // 5. Daily trend (CDS, mastery proxy, submission count)
      db.query(
        `SELECT
           d.date,
           COALESCE(c.avg_cds, 0)::DOUBLE PRECISION AS avg_cds,
           COALESCE(c.avg_mastery, 0)::DOUBLE PRECISION AS avg_mastery,
           COALESCE(sub.cnt, 0)::INTEGER AS submission_count,
           COALESCE(f.cnt, 0)::INTEGER AS flag_count
         FROM (
           SELECT generate_series(
             (NOW() - INTERVAL '1 day' * $2)::DATE,
             NOW()::DATE,
             '1 day'::INTERVAL
           )::DATE AS date
         ) d
         LEFT JOIN (
           SELECT
             cs.computed_at::DATE AS date,
             AVG(cs.cds) AS avg_cds,
             AVG(1 - cs.cds) * 100 AS avg_mastery
           FROM cds_scores cs
           WHERE ${secCond.replace('section_id', 'cs.section_id')} AND cs.computed_at > NOW() - INTERVAL '1 day' * $2
           GROUP BY cs.computed_at::DATE
         ) c ON d.date = c.date
         LEFT JOIN (
           SELECT sub.submitted_at::DATE AS date, COUNT(*)::INTEGER AS cnt
           FROM submissions sub
           JOIN enrollments e ON sub.student_id = e.student_id
           JOIN exercises ex ON sub.exercise_id = ex.id
            WHERE ${secCond.replace('section_id', 'e.section_id')} AND sub.submitted_at > NOW() - INTERVAL '1 day' * $2
           GROUP BY sub.submitted_at::DATE
         ) sub ON d.date = sub.date
         LEFT JOIN (
           SELECT i.created_at::DATE AS date, COUNT(*)::INTEGER AS cnt
           FROM integrity_flags i
           WHERE ${secCond.replace('section_id', 'i.section_id')} AND i.created_at > NOW() - INTERVAL '1 day' * $2
             AND i.status = 'flagged'
           GROUP BY i.created_at::DATE
         ) f ON d.date = f.date
         ORDER BY d.date`,
        [...secParam, days]
      ),

      // 6. Concept averages (for struggling concepts bar) — within period
      // Only concepts with avg CDS > 0.40 (i.e. "developing" tier or worse)
      db.query(
        `SELECT c.name, COALESCE(SUM(cs.cds * COALESCE(ect.weight, 1.0)) / NULLIF(SUM(COALESCE(ect.weight, 1.0)), 0), 0)::DOUBLE PRECISION AS cds
         FROM cds_scores cs
         JOIN exercises ex ON cs.exercise_id = ex.id
         JOIN exercise_concept_tags ect ON ect.exercise_id = ex.id
         JOIN concepts c ON c.id = ect.concept_id
         WHERE ${secCond.replace('section_id', 'cs.section_id')} AND cs.computed_at > NOW() - INTERVAL '1 day' * $2
         GROUP BY c.id, c.name
         HAVING COALESCE(SUM(cs.cds * COALESCE(ect.weight, 1.0)) / NULLIF(SUM(COALESCE(ect.weight, 1.0)), 0), 0) > 0.40
         ORDER BY cds DESC
         LIMIT 5`,
        [...secParam, days]
      ),

      // 7. Recent integrity flags (latest 5)
      db.query(
        `SELECT i.id, i.flag_type, i.severity, i.created_at,
                u.name AS student_name, e.title AS exercise_title
         FROM integrity_flags i
         JOIN users u ON i.student_id = u.id
         JOIN exercises e ON i.exercise_id = e.id
         WHERE ${secCond.replace('section_id', 'i.section_id')}
         ORDER BY i.created_at DESC
         LIMIT 5`,
        secParam
      ),

      // 8. Prior period at-risk count (for delta)
      db.query(
        `SELECT COUNT(*)::INTEGER AS prior_at_risk FROM (
          SELECT cs.student_id FROM cds_scores cs
          WHERE ${secCond.replace('section_id', 'cs.section_id')} AND cs.computed_at < NOW() - INTERVAL '1 day' * $2
            AND cs.computed_at > NOW() - INTERVAL '1 day' * $3
          GROUP BY cs.student_id
          HAVING AVG(cs.cds) > 0.60
        ) sub`,
        [...secParam, days, days * 2]
      ),

      // 9. Prior period avg CDS
      db.query(
        `SELECT COALESCE(AVG(cds), 0)::DOUBLE PRECISION AS prior_avg_cds
         FROM cds_scores
         WHERE ${secCond}
           AND computed_at < NOW() - INTERVAL '1 day' * $2
           AND computed_at > NOW() - INTERVAL '1 day' * $3`,
        [...secParam, days, days * 2]
      ),

      // 10. Prior period flag count
      db.query(
        `SELECT COUNT(*)::INTEGER AS prior_count
         FROM integrity_flags
         WHERE ${secCond} AND status = 'flagged'
           AND created_at < NOW() - INTERVAL '1 day' * $2
           AND created_at > NOW() - INTERVAL '1 day' * $3`,
        [...secParam, days, days * 2]
      ),
    ]);

    // ── Compose response ─────────────────────────────────────────────────
    const totalStudents = membersRes.rows[0]?.count || 0;
    const avgCds = parseFloat(avgCdsRes.rows[0]?.avg_cds) || 0;
    const atRiskCount = atRiskRes.rows[0]?.at_risk || 0;
    const openFlags24h = openFlagsRes.rows[0]?.count || 0;
    const priorAtRisk = priorAtRiskRes.rows[0]?.prior_at_risk || 0;
    const priorAvgCds = parseFloat(priorAvgCdsRes.rows[0]?.prior_avg_cds) || 0;
    const priorFlags = priorFlagsRes.rows[0]?.prior_count || 0;
    // Extract series for KPI sparklines
    const trendRows = dailyTrendRes.rows;
    const atRiskSeries = trendRows.map(() => atRiskCount);
    const cdsSeries = trendRows.map(r => parseFloat(r.avg_cds));

    // Find the most recent day with actual CDS data — days with no submissions
    // produce avg_cds = 0, which doesn't reflect the class average CDS
    let latestRow = null;
    for (let i = trendRows.length - 1; i >= 0; i--) {
      if (parseFloat(trendRows[i].avg_cds) > 0) {
        latestRow = trendRows[i];
        break;
      }
    }
    const latestCds = latestRow ? parseFloat(latestRow.avg_cds) : avgCds;
    // Weekly flag counts from actual integrity_flags data
    const flagSeries = trendRows.map(r => r.flag_count || 0);

    // Insight
    const label = sectionId === 'all' ? 'all your sections' : 'this section';
    const insightSummary = atRiskCount > 0
      ? `${atRiskCount} ${atRiskCount === 1 ? 'student is' : 'students are'} at high risk of failing ${label} this week.`
      : `No students currently at high risk ${label === 'all your sections' ? 'across all sections' : 'in this section'}.`;

    // Trend data for line chart
    const trend = trendRows.map(r => ({
      date: new Date(r.date).toLocaleDateString('en-US', { weekday: 'short', month: 'short', day: 'numeric' }),
      cds: Math.round(parseFloat(r.avg_cds) * 100),
    }));

    // Struggling concepts
    const strugglingConcepts = conceptRes.rows.map(r => ({
      name: r.name,
      cds: Math.round(parseFloat(r.cds) * 100),
    }));

    // Recent flags
    const recentFlags = recentFlagsRes.rows.map(r => {
      const hoursAgo = Math.round((Date.now() - new Date(r.created_at).getTime()) / 3600000);
      const timeAgo = hoursAgo < 1 ? '<1h' : hoursAgo < 24 ? `${hoursAgo}h` : `${Math.round(hoursAgo / 24)}d`;
      return {
        id: r.id,
        studentName: r.student_name,
        flagType: r.flag_type,
        exerciseTitle: r.exercise_title,
        timeAgo,
        severity: r.severity,
      };
    });

    res.json({
      insight: { atRiskCount, summary: insightSummary },
      kpis: [
        {
          label: 'At risk',
          value: atRiskCount,
          delta: atRiskCount - priorAtRisk,
          series: atRiskSeries.length >= 2 ? atRiskSeries : [0, atRiskCount],
          comparison: 'vs. last week',
          inverted: true,
        },
        {
          label: 'Avg CDS',
          value: latestCds.toFixed(2),
          delta: parseFloat((latestCds - priorAvgCds).toFixed(2)),
          series: cdsSeries.filter(v => v > 0).length >= 2 ? cdsSeries : [0, latestCds],
          comparison: latestCds > priorAvgCds ? 'worsening' : latestCds < priorAvgCds ? 'improving' : 'stable',
          inverted: true,
        },
        {
          label: 'Flags',
          value: openFlags24h,
          delta: openFlags24h - priorFlags,
          series: flagSeries.filter(v => v > 0).length >= 2 ? flagSeries : [0, openFlags24h],
          comparison: 'last 24h',
          inverted: true,
        },
        {
          label: 'Students',
          value: totalStudents,
          delta: null,
          series: [totalStudents],
          comparison: 'enrolled',
        },
      ],
      trend,
      strugglingConcepts,
      recentFlags,
    });
  } catch (err) {
    console.error('getInstructorDashboard error:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/student/:studentId/submissions?sectionId=X
 * Returns all submissions for a student in a section (instructor view).
 * Includes exercise title, concept, CDS scores, and integrity flags.
 */
exports.getStudentSubmissions = async (req, res, next) => {
  try {
    const { studentId } = req.params;
    const sectionId = req.query.sectionId || null;

    const studentRes = await db.query('SELECT id, name, email FROM users WHERE id = $1 AND role = $2', [studentId, 'student']);
    if (!studentRes.rows.length) return res.status(404).json({ error: 'Student not found' });
    const student = studentRes.rows[0];

    let submissions = [];
    if (sectionId) {
      const subRes = await db.query(
        `SELECT s.id, s.exercise_id, s.attempt_number, s.is_correct, s.time_spent_seconds, s.submitted_at,
                ex.title AS exercise_title, c.name AS concept_name, ex.deadline
         FROM submissions s
         JOIN exercises ex ON s.exercise_id = ex.id
         JOIN concepts c ON ex.concept_id = c.id
         WHERE s.student_id = $1 AND ex.section_id = $2
         ORDER BY s.submitted_at DESC`,
        [studentId, sectionId]
      );
      submissions = subRes.rows;
    } else {
      const subRes = await db.query(
        `SELECT s.id, s.exercise_id, s.attempt_number, s.is_correct, s.time_spent_seconds, s.submitted_at,
                ex.title AS exercise_title, c.name AS concept_name, ex.deadline
         FROM submissions s
         JOIN exercises ex ON s.exercise_id = ex.id
         JOIN concepts c ON ex.concept_id = c.id
         WHERE s.student_id = $1
         ORDER BY s.submitted_at DESC`,
        [studentId]
      );
      submissions = subRes.rows;
    }

    const cdsRes = await db.query(
      `SELECT cs.cds, cs.ner, cs.nrs, cs.nts, cs.classification, cs.computed_at,
              c.name AS concept_name, ex.title AS exercise_title
       FROM cds_scores cs
       JOIN exercises ex ON cs.exercise_id = ex.id
       JOIN concepts c ON ex.concept_id = c.id
       WHERE cs.student_id = $1${sectionId ? ' AND cs.section_id = $2' : ''}
       ORDER BY cs.computed_at DESC`,
      sectionId ? [studentId, sectionId] : [studentId]
    );

    const flagsRes = await db.query(
      `SELECT f.id, f.flag_type, f.severity, f.status, f.evidence, f.created_at,
              ex.title AS exercise_title
       FROM integrity_flags f
       JOIN exercises ex ON f.exercise_id = ex.id
       WHERE f.student_id = $1${sectionId ? ' AND f.section_id = $2' : ''}
       ORDER BY f.created_at DESC
       LIMIT 50`,
      sectionId ? [studentId, sectionId] : [studentId]
    );

    res.json({
      student,
      submissions,
      cdsScores: cdsRes.rows,
      integrityFlags: flagsRes.rows,
    });
  } catch (err) {
    console.error('getStudentSubmissions error:', err);
    next(err);
  }
};

// ── Reports ─────────────────────────────────────────────────────────────

/**
 * GET /api/analytics/reports/:sectionId/summary?period=4w
 * sectionId can be 'all' to aggregate across all instructor's sections.
 * Returns 4 KPI cards: Mastery %, Completion %, At Risk %, Flags/student.
 */
exports.getReportSummary = async (req, res, next) => {
  const { sectionId } = req.params;
  const weeks = Math.max(1, parseInt(req.query.period, 10) || 4);
  const days = weeks * 7;
  const priorDays = days * 2;
  const instructorId = req.user?.id;

  try {
    // Section-scoped WHERE fragments — used everywhere in this endpoint.
    // Two variants: one for exercise-joined queries (ex.section_id),
    // one for direct-table queries (cs.section_id, f.section_id, etc.).
    let exWhere, directWhere, exParams, directParams;

    if (sectionId === 'all') {
      const sub = `(SELECT id FROM sections WHERE instructor_id = $1)`;
      exWhere = `ex.section_id IN ${sub}`;
      directWhere = `section_id IN ${sub}`;
      exParams = [String(instructorId), days];
      directParams = [String(instructorId), days];
    } else {
      const secRes = await db.query('SELECT id, instructor_id FROM sections WHERE id = $1', [sectionId]);
      if (!secRes.rows.length) return res.status(404).json({ error: 'Section not found' });
      exWhere = `ex.section_id = $1`;
      directWhere = `section_id = $1`;
      exParams = [sectionId, days];
      directParams = [sectionId, days];
    }

    const [
      masteryRes, completionRes, atRiskRes, flagRes,
      dailySubRes, dailyCdsRes, dailyRiskRes, dailyFlagRes,
      priorMasteryRes, priorCompletionRes, priorAtRiskRes, priorFlagRes,
    ] = await Promise.all([
      // 1. Mastery
      db.query(
        `SELECT ROUND(AVG(1 - cs.cds) * 100)::INTEGER AS pct FROM cds_scores cs WHERE cs.${directWhere}`,
        sectionId === 'all' ? [String(instructorId)] : [sectionId]
      ),
      // 2. Completion
      db.query(
        `SELECT ROUND(AVG(sub_pct))::INTEGER AS pct FROM (SELECT (COUNT(DISTINCT sub.student_id)::FLOAT / NULLIF(enr.total, 0)) * 100 AS sub_pct FROM exercises e CROSS JOIN (SELECT COUNT(*) AS total FROM enrollments WHERE ${directWhere}) enr LEFT JOIN submissions sub ON sub.exercise_id = e.id AND sub.submitted_at > NOW() - INTERVAL '1 day' * $2 WHERE ${directWhere} GROUP BY e.id, enr.total) per_exercise`,
        exParams
      ),
      // 3. At Risk
      db.query(
        `SELECT ROUND((at_risk.cnt::FLOAT / NULLIF((SELECT COUNT(*) FROM enrollments WHERE ${directWhere}), 0)) * 100)::INTEGER AS pct FROM (SELECT COUNT(*)::INTEGER AS cnt FROM (SELECT cs.student_id FROM cds_scores cs WHERE cs.${directWhere} GROUP BY cs.student_id HAVING AVG(cs.cds) > 0.60) sub) at_risk`,
        sectionId === 'all' ? [String(instructorId)] : [sectionId]
      ),
      // 4. Flags — count distinct flagged students, not total flags
      db.query(
        `SELECT ROUND((COUNT(DISTINCT student_id)::NUMERIC / NULLIF((SELECT COUNT(*) FROM enrollments WHERE ${directWhere}), 0)), 2) AS rate FROM integrity_flags WHERE ${directWhere} AND created_at > NOW() - INTERVAL '1 day' * $2`,
        sectionId === 'all' ? [String(instructorId), days] : [sectionId, days]
      ),
      // 5. Daily submissions
      db.query(
        `SELECT d.date, COALESCE(sub.cnt, 0)::INTEGER AS cnt FROM (SELECT generate_series((NOW() - INTERVAL '1 day' * $2)::DATE, NOW()::DATE, '1 day'::INTERVAL)::DATE AS date) d LEFT JOIN (SELECT sub.submitted_at::DATE AS date, COUNT(*)::INTEGER AS cnt FROM submissions sub JOIN exercises ex ON sub.exercise_id = ex.id WHERE ${exWhere} AND sub.submitted_at > NOW() - INTERVAL '1 day' * $2 GROUP BY sub.submitted_at::DATE) sub ON d.date = sub.date ORDER BY d.date`,
        exParams
      ),
      // 6. Daily CDS
      db.query(
        `SELECT d.date, COALESCE(c.avg_cds, 0)::DOUBLE PRECISION AS avg_cds FROM (SELECT generate_series((NOW() - INTERVAL '1 day' * $2)::DATE, NOW()::DATE, '1 day'::INTERVAL)::DATE AS date) d LEFT JOIN (SELECT cs.computed_at::DATE AS date, AVG(cs.cds) AS avg_cds FROM cds_scores cs WHERE cs.${directWhere} AND cs.computed_at > NOW() - INTERVAL '1 day' * $2 GROUP BY cs.computed_at::DATE) c ON d.date = c.date ORDER BY d.date`,
        sectionId === 'all' ? [String(instructorId), days] : [sectionId, days]
      ),
      // 7. Daily at-risk
      db.query(
        `SELECT d.date, COALESCE(daily.cnt, 0)::INTEGER AS cnt FROM (SELECT generate_series((NOW() - INTERVAL '1 day' * $2)::DATE, NOW()::DATE, '1 day'::INTERVAL)::DATE AS date) d LEFT JOIN (SELECT computed_at::DATE AS date, COUNT(DISTINCT student_id)::INTEGER AS cnt FROM (SELECT computed_at::DATE, student_id, AVG(cds) AS avg_cds FROM cds_scores WHERE ${directWhere} AND computed_at > NOW() - INTERVAL '1 day' * $2 GROUP BY computed_at::DATE, student_id HAVING AVG(cds) > 0.60) at_risk GROUP BY date) daily ON d.date = daily.date ORDER BY d.date`,
        sectionId === 'all' ? [String(instructorId), days] : [sectionId, days]
      ),
      // 8. Daily flags
      db.query(
        `SELECT d.date, COALESCE(f.cnt, 0)::INTEGER AS cnt FROM (SELECT generate_series((NOW() - INTERVAL '1 day' * $2)::DATE, NOW()::DATE, '1 day'::INTERVAL)::DATE AS date) d LEFT JOIN (SELECT created_at::DATE AS date, COUNT(*)::INTEGER AS cnt FROM integrity_flags WHERE ${directWhere} AND created_at > NOW() - INTERVAL '1 day' * $2 GROUP BY created_at::DATE) f ON d.date = f.date ORDER BY d.date`,
        sectionId === 'all' ? [String(instructorId), days] : [sectionId, days]
      ),
      // 9. Prior mastery
      db.query(
        `SELECT ROUND(AVG(1 - cs.cds) * 100)::INTEGER AS pct FROM cds_scores cs WHERE cs.${directWhere} AND cs.computed_at < NOW() - INTERVAL '1 day' * $2 AND cs.computed_at > NOW() - INTERVAL '1 day' * $3`,
        sectionId === 'all' ? [String(instructorId), days, String(priorDays)] : [sectionId, days, String(priorDays)]
      ),
      // 10. Prior completion
      db.query(
        `SELECT ROUND(AVG(sub_pct))::INTEGER AS pct FROM (SELECT (COUNT(DISTINCT sub.student_id)::FLOAT / NULLIF(enr.total, 0)) * 100 AS sub_pct FROM exercises e CROSS JOIN (SELECT COUNT(*) AS total FROM enrollments WHERE ${directWhere}) enr LEFT JOIN submissions sub ON sub.exercise_id = e.id AND sub.submitted_at < NOW() - INTERVAL '1 day' * $2 AND sub.submitted_at > NOW() - INTERVAL '1 day' * $3 WHERE ${directWhere} GROUP BY e.id, enr.total) per_exercise`,
        sectionId === 'all' ? [String(instructorId), days, String(priorDays)] : [sectionId, days, String(priorDays)]
      ),
      // 11. Prior at-risk
      db.query(
        `SELECT ROUND((at_risk.cnt::FLOAT / NULLIF((SELECT COUNT(*) FROM enrollments WHERE ${directWhere}), 0)) * 100)::INTEGER AS pct FROM (SELECT COUNT(*)::INTEGER AS cnt FROM (SELECT cs.student_id FROM cds_scores cs WHERE cs.${directWhere} AND cs.computed_at < NOW() - INTERVAL '1 day' * $2 AND cs.computed_at > NOW() - INTERVAL '1 day' * $3 GROUP BY cs.student_id HAVING AVG(cs.cds) > 0.60) sub) at_risk`,
        sectionId === 'all' ? [String(instructorId), days, String(priorDays)] : [sectionId, days, String(priorDays)]
      ),
      // 12. Prior flags — count distinct flagged students
      db.query(
        `SELECT ROUND(COUNT(DISTINCT student_id)::NUMERIC / NULLIF((SELECT COUNT(*) FROM enrollments WHERE ${directWhere}), 0), 2) AS rate FROM integrity_flags WHERE ${directWhere} AND created_at < NOW() - INTERVAL '1 day' * $2 AND created_at > NOW() - INTERVAL '1 day' * $3`,
        sectionId === 'all' ? [String(instructorId), days, String(priorDays)] : [sectionId, days, String(priorDays)]
      ),
    ]);

    const mastery = masteryRes.rows[0]?.pct ?? 0;
    const completion = completionRes.rows[0]?.pct ?? 0;
    const atRisk = atRiskRes.rows[0]?.pct ?? 0;
    const flagsRate = parseFloat(flagRes.rows[0]?.rate) ?? 0;
    const priorMastery = priorMasteryRes.rows[0]?.pct ?? 0;
    const priorCompletion = priorCompletionRes.rows[0]?.pct ?? 0;
    const priorAtRisk = priorAtRiskRes.rows[0]?.pct ?? 0;
    const priorFlagsRate = parseFloat(priorFlagRes.rows[0]?.rate) ?? 0;

    const makeSeries = (rows, key, fallback) => {
      const vals = rows.map(r => r[key] ?? 0);
      return vals.length >= 2 ? vals : fallback;
    };

    const totalStudents = parseInt(await db.query(
      sectionId === 'all'
        ? `SELECT COUNT(*) FROM enrollments WHERE section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
        : `SELECT COUNT(*) FROM enrollments WHERE section_id = $1`,
      sectionId === 'all' ? [String(instructorId)] : [sectionId]
    ).then(r => r.rows[0]?.count)) || 1;
    const atRiskSeries = makeSeries(dailyRiskRes.rows, 'cnt', [0, Math.round(atRisk * totalStudents / 100)]).map(c => Math.round((c / totalStudents) * 100));

    res.json({
      mastery: { value: `${mastery}%`, delta: mastery - priorMastery, series: makeSeries(dailyCdsRes.rows, 'avg_cds', [0, mastery]).map(v => Math.round((1 - (v || 0)) * 100)), comparison: `vs. ${weeks}w ago` },
      completion: { value: `${completion}%`, delta: completion - priorCompletion, series: dailySubRes.rows.length >= 2 ? dailySubRes.rows.map(r => r.cnt) : [0, completion], comparison: `vs. ${weeks}w ago` },
      atRisk: { value: `${atRisk}%`, delta: atRisk - priorAtRisk, inverted: true, series: atRiskSeries, comparison: `vs. ${weeks}w ago` },
      flags: { value: `${Math.round(flagsRate * 100)}%`, delta: Math.round((flagsRate - priorFlagsRate) * 100), inverted: true, series: makeSeries(dailyFlagRes.rows, 'cnt', [0, Math.round(flagsRate * totalStudents)]), comparison: `vs. ${weeks}w ago` },
    });
  } catch (err) {
    console.error('getReportSummary error:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/reports/:sectionId/concept-mastery?weeks=5
 * sectionId can be 'all' to aggregate across all instructor's sections.
 */
exports.getConceptMasteryReport = async (req, res, next) => {
  const { sectionId } = req.params;
  const weeks = Math.max(2, parseInt(req.query.weeks, 10) || 5);
  const instructorId = req.user?.id;
  const secCond = sectionId === 'all'
    ? `cs.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
    : `cs.section_id = $1`;

  try {
    // Use slug as unique ID to avoid collisions (substring causes "AR" for Arrays & "AR" for other concepts)
    const conceptRes = await db.query('SELECT id, name, slug, knowledge_area_code FROM concepts ORDER BY id');
    // Tag-aware aggregation, mirroring the heatmap: each cds_scores row
    // contributes to every exercise_concept_tags tag (weighted), falling back
    // to ex.concept_id for untagged legacy exercises. Mastery = (1 - CDS).
    const weeklyRes = await db.query(
      `SELECT COALESCE(pt.id, c.id) AS concept_id,
              COALESCE(pt.slug, c.slug) AS slug,
              COALESCE(pt.name, c.name) AS concept_name,
              cs.computed_at::DATE AS week_date,
              ROUND((SUM((1 - cs.cds) * COALESCE(ect.weight, 1.0)) / NULLIF(SUM(COALESCE(ect.weight, 1.0)), 0)) * 100)::INTEGER AS mastery
       FROM cds_scores cs
       JOIN exercises ex ON cs.exercise_id = ex.id
       JOIN concepts c ON c.id = ex.concept_id
       LEFT JOIN exercise_concept_tags ect ON ect.exercise_id = ex.id
       LEFT JOIN concepts pt ON pt.id = ect.concept_id
       WHERE ${secCond} AND cs.computed_at > NOW() - ($2 || ' weeks')::INTERVAL
       GROUP BY COALESCE(pt.id, c.id), COALESCE(pt.slug, c.slug), COALESCE(pt.name, c.name), cs.computed_at::DATE
       ORDER BY COALESCE(pt.slug, c.slug), cs.computed_at::DATE`,
      sectionId === 'all' ? [String(instructorId), String(weeks)] : [sectionId, String(weeks)]
    );

    function fmtDate(d) {
      if (!d) return '';
      if (typeof d === 'string') return d.slice(0, 10);
      return `${d.getFullYear()}-${String(d.getMonth() + 1).padStart(2, '0')}-${String(d.getDate()).padStart(2, '0')}`;
    }

    const DAY_MS = 24 * 60 * 60 * 1000;
    const todayLocal = new Date();
    todayLocal.setHours(0, 0, 0, 0);

    // Map a measurement date to a week index in the series array (index 0 =
    // oldest week W-(weeks-1), last index = Now). Bucketing by RANGE (not
    // exact-date equality) so any score computed mid-week lands in its week
    // instead of falling through to null.
    function weekSlotOf(dateStr) {
      const [y, m, d] = dateStr.split('-').map(Number);
      const local = new Date(y, m - 1, d);
      const daysAgo = Math.round((todayLocal.getTime() - local.getTime()) / DAY_MS);
      if (daysAgo < 0) return weeks - 1; // future-dated measurement → Now
      return (weeks - 1) - Math.min(weeks - 1, Math.floor(daysAgo / 7));
    }

    const weekDates = [];
    for (let i = weeks - 1; i >= 0; i--) {
      const d = new Date();
      d.setDate(d.getDate() - i * 7);
      weekDates.push(fmtDate(d));
    }

    // Map slug → concept data for O(1) lookup; weekly is a slot-indexed array.
    const conceptMap = {};
    for (const c of conceptRes.rows) {
      conceptMap[c.slug || c.id] = { id: c.slug || c.id, name: c.name, slug: c.slug, knowledgeAreaCode: c.knowledge_area_code || 'UNCATEGORIZED', weekly: Array(weeks).fill(null) };
    }
    const conceptsWithData = new Set();
    for (const r of weeklyRes.rows) {
      const key = r.slug || r.concept_id;
      if (conceptMap[key]) {
        // Rows arrive date-ascending, so the later measurement wins the slot.
        conceptMap[key].weekly[weekSlotOf(fmtDate(r.week_date))] = r.mastery;
        conceptsWithData.add(key);
      }
    }

    // Only concepts that actually appear in this section's CDS data — a
    // concept never touched here must not show as a phantom flat 0% line.
    // Any week with no measurement → 0, exactly like the dashboard's Class
    // Trend chart (which COALESCEs empty days to 0): the curve rises from
    // the 0 baseline into measured points and falls back to 0 when a week
    // has no new data, so a stale line never just stops mid-chart.
    const conceptData = conceptRes.rows
      .filter(c => conceptsWithData.has(c.slug || c.id))
      .map(c => {
        const key = c.slug || c.id;
        const weekly = conceptMap[key].weekly;
        const series = weekDates.map((_, i) => weekly[i] ?? 0);
        const lastReal = [...weekly].reverse().find(v => v != null) ?? 0;
        return { id: key, name: c.name, slug: c.slug, knowledgeAreaCode: c.knowledge_area_code || 'UNCATEGORIZED', series, current: lastReal };
      });

    const weekLabels = [];
    for (let i = weeks - 1; i >= 0; i--) weekLabels.push(i === 0 ? 'Now' : `W-${i}`);

    res.json({ weeks: weekLabels, concepts: conceptData });
  } catch (err) {
    console.error('getConceptMasteryReport error:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/reports/:sectionId/completion
 * sectionId can be 'all' to aggregate across all instructor's sections.
 */
exports.getCompletionReport = async (req, res, next) => {
  const { sectionId } = req.params;
  const instructorId = req.user?.id;
  const secCond = sectionId === 'all'
    ? `e.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
    : `e.section_id = $1`;
  const enrollCond = sectionId === 'all'
    ? `SELECT COUNT(*) FROM enrollments WHERE section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
    : `SELECT COUNT(*) FROM enrollments WHERE section_id = $1`;

  try {
    // A student who submitted both before AND after the deadline must count in
    // exactly ONE bucket, otherwise on_time + late exceeds submitted. Each
    // student is bucketed by their EARLIEST submission: if the first attempt
    // landed before (or on) the deadline they are on-time; if the first attempt
    // was after the deadline they are late.
    const exercises = await db.query(
      `SELECT e.id, e.title, e.deadline,
         (${enrollCond}) AS total,
         COUNT(DISTINCT sub.student_id) AS submitted,
         COUNT(DISTINCT CASE WHEN e.deadline IS NULL OR sub.first_submitted_at <= e.deadline THEN sub.student_id END) AS on_time,
         COUNT(DISTINCT CASE WHEN e.deadline IS NOT NULL AND sub.first_submitted_at > e.deadline THEN sub.student_id END) AS late
       FROM exercises e
       LEFT JOIN (
         SELECT exercise_id, student_id, MIN(submitted_at) AS first_submitted_at
         FROM submissions GROUP BY exercise_id, student_id
       ) sub ON sub.exercise_id = e.id
       WHERE ${secCond}
       GROUP BY e.id ORDER BY e.created_at DESC`,
      sectionId === 'all' ? [String(instructorId)] : [sectionId]
    );

    const data = exercises.rows.map(ex => {
      const total = parseInt(ex.total) || 1;
      const onTime = parseInt(ex.on_time) || 0;
      const late = parseInt(ex.late) || 0;
      const submitted = parseInt(ex.submitted) || 0;
      const missing = Math.max(0, total - submitted);
      // Mutual exclusivity guard: on_time + late can never exceed submitted.
      const lateSafe = Math.min(late, Math.max(0, submitted - onTime));
      return { exercise: ex.title, on_time: Math.round((onTime / total) * 100), late: Math.round((lateSafe / total) * 100), missing: Math.round((missing / total) * 100) };
    });

    res.json(data);
  } catch (err) {
    console.error('getCompletionReport error:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/reports/:sectionId/integrity-trends?weeks=5
 * sectionId can be 'all' to aggregate across all instructor's sections.
 */
exports.getIntegrityTrends = async (req, res, next) => {
  const { sectionId } = req.params;
  const weeks = Math.max(2, parseInt(req.query.weeks, 10) || 5);
  const instructorId = req.user?.id;
  const secCond = sectionId === 'all'
    ? `f.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`
    : `f.section_id = $1`;

  try {
    const timelineRes = await db.query(
      `SELECT DATE_TRUNC('week', f.created_at)::DATE AS week, f.severity, COUNT(*)::INTEGER AS cnt
       FROM integrity_flags f WHERE ${secCond} AND f.created_at > NOW() - ($2 || ' weeks')::INTERVAL
       GROUP BY DATE_TRUNC('week', f.created_at), f.severity ORDER BY week, f.severity`,
      sectionId === 'all' ? [String(instructorId), String(weeks)] : [sectionId, String(weeks)]
    );

    const weekLabels = [];
    for (let i = weeks - 1; i >= 0; i--) weekLabels.push(i === 0 ? 'Now' : `W-${i}`);
    const timeline = Array.from({ length: weeks }, () => ({ critical: 0, high: 0, moderate: 0, low: 0 }));

    for (const row of timelineRes.rows) {
      const weekDate = new Date(row.week);
      const now = new Date();
      const diffWeeks = Math.floor((now - weekDate) / (7 * 24 * 3600000));
      const idx = weeks - 1 - diffWeeks;
      // DB stores 'medium'; the frontend chart buckets are keyed 'moderate'.
      const sev = ((row.severity || '').toLowerCase() === 'medium' ? 'moderate' : (row.severity || '').toLowerCase());
      if (idx >= 0 && idx < weeks && timeline[idx][sev] != null) timeline[idx][sev] = row.cnt;
    }

    const breakdownRes = await db.query(
      `SELECT f.flag_type AS type, f.severity AS level, COUNT(*)::INTEGER AS count
       FROM integrity_flags f WHERE ${secCond}
       GROUP BY f.flag_type, f.severity ORDER BY count DESC`,
      sectionId === 'all' ? [String(instructorId)] : [sectionId]
    );

    const totalFlags = breakdownRes.rows.reduce((s, r) => s + r.count, 0);
    const breakdown = breakdownRes.rows.map(r => ({
      type: r.type.replace(/_/g, ' ').replace(/\b\w/g, c => c.toUpperCase()),
      level: (r.level || '').toLowerCase(), count: r.count,
      share: totalFlags ? Math.round((r.count / totalFlags) * 100) : 0, delta: 0,
    }));

    res.json({ weeks: weekLabels, timeline: timeline.map((w, i) => ({ week: weekLabels[i], ...w })), breakdown });
  } catch (err) {
    console.error('getIntegrityTrends error:', err);
    next(err);
  }
};

// GAP #4: Structure Violations Report
exports.getStructureViolations = async (req, res, next) => {
  try {
    const { sectionId } = req.params;
    const instructorId = req.user.id;

    const secCond = sectionId === 'all'
      ? 'e.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)'
      : 'e.section_id = $1';
    const params = sectionId === 'all' ? [String(instructorId)] : [sectionId];

    const result = await db.query(`
      SELECT
        u.name AS student_name,
        e.title AS exercise_title,
        c.name AS concept_name,
        vl.reason,
        vl.verification_type,
        s.attempt_number,
        s.submitted_at,
        CASE
          WHEN vl.reason LIKE '%Required%' OR vl.reason LIKE '%Syntax%' THEN 'error'
          ELSE 'warning'
        END AS severity
      FROM verification_logs vl
      JOIN submissions s ON s.id = vl.submission_id
      JOIN users u ON u.id = vl.student_id
      JOIN exercises e ON e.id = vl.exercise_id
      LEFT JOIN concepts c ON c.id = e.concept_id
      WHERE ${secCond}
        AND vl.verification_type = 'ast_verifier'
      ORDER BY s.submitted_at DESC
      LIMIT 200
    `, params);

    res.json(result.rows);
  } catch (err) {
    console.error('getStructureViolations error:', err);
    next(err);
  }
};

// GAP #9: Class-Wide Micro-Concept Report
exports.getClassMicroConceptReport = async (req, res, next) => {
  try {
    const { sectionId } = req.params;
    const instructorId = req.user.id;

    const secCond = sectionId === 'all'
      ? 'e.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)'
      : 'e.section_id = $1';
    const params = sectionId === 'all' ? [String(instructorId)] : [sectionId];

    const result = await db.query(`
      SELECT
        c.name AS concept_name,
        COUNT(DISTINCT vl.student_id) AS student_count,
        json_agg(DISTINCT vl.reason) AS issues
      FROM verification_logs vl
      JOIN submissions s ON s.id = vl.submission_id
      JOIN exercises e ON e.id = vl.exercise_id
      LEFT JOIN concepts c ON c.id = e.concept_id
      WHERE ${secCond}
        AND vl.verification_type = 'micro_concept'
      GROUP BY c.name
      ORDER BY student_count DESC
    `, params);

    const concepts = result.rows.map(row => ({
      name: row.concept_name || 'Unknown',
      studentCount: parseInt(row.student_count),
      issueCount: row.issues ? row.issues.length : 0,
      issues: (row.issues || []).map(issueText => {
        // Parse the issue summary format: "name: recommendation; name: recommendation"
        const parts = (issueText || '').split('; ').filter(Boolean);
        return parts.map(part => {
          const [name, ...rest] = part.split(': ');
          return {
            name: name?.trim() || 'Unknown Issue',
            recommendation: rest.join(': ').trim(),
            severity: 'medium',
            studentCount: 1,
          };
        });
      }).flat(),
    }));

    res.json({ concepts });
  } catch (err) {
    console.error('getClassMicroConceptReport error:', err);
    next(err);
  }
};

// ── At-Risk Analytics Alerts (RETRY_STORM, LEARNING_PLATEAU) ───────────────

/**
 * GET /api/analytics/instructor/dashboard/alerts?sectionId=X
 * Returns compiled alerts sorted by severity, combining CDS-based alerts,
 * RETRY_STORM flags, and LEARNING_PLATEAU detections.
 */
exports.getDashboardAlerts = async (req, res, next) => {
  try {
    const { sectionId } = req.query;
    if (!sectionId) {
      return res.status(400).json({ message: 'sectionId query parameter required' });
    }

    const analyticsEngine = require('../services/analyticsEngine');
    const alerts = await analyticsEngine.getDashboardAlerts(sectionId);
    res.json(alerts);
  } catch (err) {
    console.error('getDashboardAlerts error:', err.message);
    next(err);
  }
};

/**
 * PUT /api/analytics/instructor/dashboard/alerts/:alertId/review
 * Mark an analytics alert as reviewed.
 */
exports.reviewAnalyticsAlert = async (req, res, next) => {
  try {
    const { alertId } = req.params;
    const { classification } = req.body;

    const analyticsEngine = require('../services/analyticsEngine');
    const result = await analyticsEngine.reviewAlert(alertId, classification);

    if (result.success) {
      res.json({ message: 'Alert marked as reviewed' });
    } else {
      res.status(500).json({ message: result.error });
    }
  } catch (err) {
    console.error('reviewAnalyticsAlert error:', err.message);
    next(err);
  }
};

// ── Phase 5: Concept Analytics API Endpoints ─────────────────────────────────

/**
 * GET /api/analytics/sections/:sectionId/concept-analytics
 * Returns CRS (Concept Risk Score) data for all concepts in a section.
 * Used by instructor dashboard to show which concepts the class is struggling with.
 */
exports.getConceptAnalytics = async (req, res, next) => {
  try {
    const { sectionId } = req.params;

    // Verify section access
    if (sectionId !== 'all') {
      const secRes = await db.query('SELECT id FROM sections WHERE id = $1', [sectionId]);
      if (!secRes.rows.length) return res.status(404).json({ error: 'Section not found' });
    }

    const crsData = await conceptAnalytics.getSectionCRS(parseInt(sectionId));
    const cmiData = await conceptAnalytics.getSectionCRS(parseInt(sectionId)); // same query for now

    res.json({
      sectionId: parseInt(sectionId),
      conceptRisk: crsData,
    });
  } catch (err) {
    console.error('getConceptAnalytics error:', err.message);
    next(err);
  }
};

/**
 * GET /api/analytics/students/:studentId/concept-profile?sectionId=X
 * Returns CMI (Concept Mastery Index) + velocity for a student.
 * Used by student profile page to show mastery per concept.
 */
exports.getStudentConceptProfile = async (req, res, next) => {
  try {
    const { studentId } = req.params;
    const { sectionId } = req.query;

    if (!sectionId) {
      return res.status(400).json({ error: 'sectionId query parameter required' });
    }

    const cmiData = await conceptAnalytics.getStudentCMI(parseInt(studentId), parseInt(sectionId));

    // Get student name
    const studentRes = await db.query('SELECT id, name, email FROM users WHERE id = $1', [studentId]);
    const student = studentRes.rows.length > 0 ? studentRes.rows[0] : null;

    res.json({
      studentId: parseInt(studentId),
      student: student ? { id: student.id, name: student.name, email: student.email } : null,
      sectionId: parseInt(sectionId),
      conceptMastery: cmiData,
    });
  } catch (err) {
    console.error('getStudentConceptProfile error:', err.message);
    next(err);
  }
};

/**
 * GET /api/analytics/concepts/:conceptId/diagnostic?sectionId=X
 * Returns concept details, prerequisite chain, section CRS, and at-risk students.
 * Used for diagnostic reasoning: "Why is a student struggling with recursion?"
 * → "Because they haven't mastered functions (prerequisite)."
 */
exports.getConceptDiagnostic = async (req, res, next) => {
  try {
    const { conceptId } = req.params;
    const { sectionId } = req.query;

    // Get concept info
    const conceptRes = await db.query('SELECT * FROM concepts WHERE id = $1', [conceptId]);
    if (!conceptRes.rows.length) return res.status(404).json({ error: 'Concept not found' });
    const concept = conceptRes.rows[0];

    // Get prerequisites (recursive dependency chain)
    const prerequisites = await conceptAnalytics.getConceptPrerequisites(parseInt(conceptId));

    // Get section CRS for this concept
    let crsData = null;
    if (sectionId) {
      const crsAll = await conceptAnalytics.getSectionCRS(parseInt(sectionId));
      crsData = crsAll.find(c => c.conceptId === parseInt(conceptId)) || null;
    }

    // Get exercises tagged with this concept
    const exerciseRes = await db.query(
      `SELECT e.id, e.title, e.closed_at,
              COALESCE(AVG(cs.cds), 0) AS avg_cds,
              COUNT(DISTINCT cs.student_id) AS students_attempted,
              COUNT(DISTINCT cs.student_id) FILTER (WHERE cs.cds > 0.40) AS at_risk_count
       FROM exercises e
       LEFT JOIN cds_scores cs ON cs.exercise_id = e.id
       WHERE e.concept_id = $1 OR e.id IN (
         SELECT ect.exercise_id FROM exercise_concept_tags ect WHERE ect.concept_id = $1
       )
       GROUP BY e.id
       ORDER BY e.closed_at DESC`,
      [conceptId]
    );

    // Get at-risk students for this concept (CDS > 0.50 on concept-tagged exercises)
    const atRiskStudents = sectionId ? await db.query(
      `SELECT u.id, u.name, AVG(cs.cds) AS avg_cds
       FROM cds_scores cs
       JOIN exercises e ON e.id = cs.exercise_id
       JOIN users u ON u.id = cs.student_id
       WHERE (e.concept_id = $1 OR e.id IN (
         SELECT ect.exercise_id FROM exercise_concept_tags ect WHERE ect.concept_id = $1
       ))
       AND cs.section_id = $2
       AND cs.cds IS NOT NULL
        GROUP BY u.id, u.name
        HAVING AVG(cs.cds) > 0.40
        ORDER BY avg_cds DESC
        LIMIT 20`,
      [conceptId, sectionId]
    ) : { rows: [] };

    res.json({
      concept: {
        id: concept.id,
        name: concept.name,
        knowledgeAreaCode: concept.knowledge_area_code,
        slug: concept.slug,
        bloomLevel: concept.bloom_level,
      },
      prerequisites,
      sectionCRS: crsData,
      exercises: exerciseRes.rows.map(r => ({
        id: r.id,
        title: r.title,
        avgCds: parseFloat(r.avg_cds) || 0,
        studentsAttempted: parseInt(r.students_attempted),
        atRiskCount: parseInt(r.at_risk_count),
        closedAt: r.closed_at,
      })),
      atRiskStudents: atRiskStudents.rows.map(r => ({
        id: r.id,
        name: r.name,
        avgCds: parseFloat(r.avg_cds) || 0,
      })),
    });
  } catch (err) {
    console.error('getConceptDiagnostic error:', err.message);
    next(err);
  }
};

/**
 * GET /api/analytics/sections/:sectionId/concept-heatmap
 * Returns data for a concept-grouped heatmap (by knowledge area).
 * Extends the existing heatmap with knowledge area grouping.
 * Uses exercise_concept_tags (primary) for concept resolution — matches Concept Analytics.
 */
exports.getConceptHeatmap = async (req, res, next) => {
  try {
    const { sectionId } = req.params;

    if (!sectionId || sectionId === 'null' || sectionId === 'undefined') {
      return res.json({ concepts: [], students: [], scores: [] });
    }

    // Get concepts actually used in this section's exercises (all tags)
    // Ordered by name to match taxonomy
    const conceptsRes = await db.query(
      `SELECT DISTINCT c.id, c.name, c.knowledge_area_code, c.slug, c.bloom_level
       FROM concepts c
       JOIN exercise_concept_tags ect ON ect.concept_id = c.id
       JOIN exercises ex ON ex.id = ect.exercise_id
       WHERE ex.section_id = $1
       ORDER BY c.name`,
      [sectionId]
    );

    // Get CDS scores for students in this section using exercise_concept_tags
    // (all tags, weighted). A multi-tag exercise yields one row per tag.
    const scoresRes = await db.query(
      `SELECT cs.student_id, cs.cds, cs.classification, cs.ner, cs.nrs, cs.nts,
              c.id AS concept_id, c.name AS concept_name,
              c.knowledge_area_code, c.slug, c.bloom_level,
              COALESCE(ect.weight, 1.0) AS weight
       FROM cds_scores cs
       JOIN exercises ex ON ex.id = cs.exercise_id
       JOIN exercise_concept_tags ect ON ect.exercise_id = ex.id
       JOIN concepts c ON c.id = ect.concept_id
       WHERE cs.section_id = $1`,
      [sectionId]
    );

    // Build score map — aggregate per (student, concept) as a weighted average
    const scoreMap = {};
    const cellRows = {};
    for (const s of scoresRes.rows) {
      if (!cellRows[s.student_id]) cellRows[s.student_id] = {};
      if (!cellRows[s.student_id][s.concept_name]) cellRows[s.student_id][s.concept_name] = [];
      cellRows[s.student_id][s.concept_name].push(s);
    }
    for (const studentId of Object.keys(cellRows)) {
      scoreMap[studentId] = {};
      for (const concept of Object.keys(cellRows[studentId])) {
        const rows = cellRows[studentId][concept];
        const stats = weightedStats(rows);
        const first = rows[0];
        scoreMap[studentId][concept] = {
          cds: stats.cds,
          classification: countLabel(stats.cds),
          ner: stats.ner,
          nrs: stats.nrs,
          nts: stats.nts,
          knowledgeAreaCode: first.knowledge_area_code,
          slug: first.slug,
          bloomLevel: first.bloom_level,
        };
      }
    }

    // Group concepts by knowledge area
    const knowledgeAreas = {};
    for (const c of conceptsRes.rows) {
      const ka = c.knowledge_area_code || 'UNCATEGORIZED';
      if (!knowledgeAreas[ka]) knowledgeAreas[ka] = [];
      knowledgeAreas[ka].push({
        id: c.id,
        name: c.name,
        slug: c.slug,
        bloomLevel: c.bloom_level,
      });
    }

    // Get students
    const studentsRes = await db.query(
      `SELECT u.id, u.name FROM users u
       JOIN enrollments e ON e.student_id = u.id
       WHERE e.section_id = $1 ORDER BY u.name`,
      [sectionId]
    );

    // Get CMI data
    const cmiRes = await db.query(
      `SELECT scm.student_id, scm.concept_id, scm.cmi, scm.velocity,
              c.name AS concept_name
       FROM student_concept_metrics scm
       JOIN concepts c ON c.id = scm.concept_id
       WHERE scm.section_id = $1`,
      [sectionId]
    );

    const cmiMap = {};
    for (const row of cmiRes.rows) {
      if (!cmiMap[row.student_id]) cmiMap[row.student_id] = {};
      cmiMap[row.student_id][row.concept_name] = {
        cmi: parseFloat(row.cmi) || 0,
        velocity: parseFloat(row.velocity) || 0,
      };
    }

    res.json({
      sectionId: parseInt(sectionId),
      students: studentsRes.rows,
      concepts: conceptsRes.rows.map(c => ({
        id: c.id,
        name: c.name,
        slug: c.slug,
        knowledgeAreaCode: c.knowledge_area_code,
        bloomLevel: c.bloom_level,
      })),
      knowledgeAreas,
      scores: scoreMap,
      cmi: cmiMap,
    });
  } catch (err) {
    console.error('getConceptHeatmap error:', err.message);
    next(err);
  }
};

/**
 * GET /api/analytics/sections/:sectionId/submissions
 * Returns all submissions for a section, with code and compiler_log.
 */
exports.getSectionSubmissions = async (req, res, next) => {
  try {
    const { sectionId } = req.params;
    const { search, exerciseId, status, limit = 50, offset = 0 } = req.query;

    let where = 'WHERE ex.section_id = $1';
    const params = [sectionId];
    let paramIdx = 2;

    if (exerciseId) {
      where += ` AND s.exercise_id = $${paramIdx++}`;
      params.push(exerciseId);
    }
    if (status === 'pass') {
      where += ` AND s.is_correct = true`;
    } else if (status === 'fail') {
      where += ` AND s.is_correct = false`;
    }
    if (search) {
      where += ` AND u.name ILIKE $${paramIdx++}`;
      params.push(`%${search}%`);
    }

    const { rows } = await db.query(
      `SELECT s.id, s.student_id, u.name AS student_name, u.email AS student_email,
              s.exercise_id, ex.title AS exercise_title, c.name AS concept_name,
              s.attempt_number, s.is_correct, s.code, s.compiler_log,
              s.submitted_at, s.time_spent_seconds,
              (SELECT COUNT(*) FROM integrity_flags f WHERE f.student_id = s.student_id AND f.exercise_id = s.exercise_id AND f.status = 'flagged')::int AS flag_count
       FROM submissions s
       JOIN users u ON s.student_id = u.id
       JOIN exercises ex ON s.exercise_id = ex.id
       JOIN concepts c ON ex.concept_id = c.id
       ${where}
       ORDER BY s.submitted_at DESC
       LIMIT $${paramIdx++} OFFSET $${paramIdx++}`,
      [...params, parseInt(limit, 10), parseInt(offset, 10)]
    );

    const countResult = await db.query(
      `SELECT COUNT(*)::int AS total
       FROM submissions s
       JOIN users u ON s.student_id = u.id
       JOIN exercises ex ON s.exercise_id = ex.id
       ${where}`,
      params
    );

    res.json({
      submissions: rows,
      total: countResult.rows[0].total,
      limit: parseInt(limit, 10),
      offset: parseInt(offset, 10),
    });
  } catch (err) {
    console.error('getSectionSubmissions error:', err);
    next(err);
  }
};

/**
 * Safety cap for the grouped submission browser. All rows for the section are
 * fetched (no SQL LIMIT/OFFSET so grouping is complete); if the cap is
 * exceeded we log a warning rather than silently truncate.
 */
const MAX_SUBMISSION_GROUP_ROWS = 5000;

/**
 * GET /api/analytics/sections/:sectionId/submission-groups
 * Returns all submissions for a section grouped by (student_id, exercise_id).
 * Group status reflects the LATEST attempt (max submitted_at, tie-break
 * attempt_number). Attempts are included in full, ascending, for inline
 * expansion. Pagination applies to groups, not rows.
 */
exports.getSectionSubmissionGroups = async (req, res, next) => {
  try {
    const { sectionId } = req.params;
    const { search, exerciseId, status, limit = 50, offset = 0 } = req.query;

    let where = 'WHERE ex.section_id = $1';
    const params = [sectionId];
    let paramIdx = 2;

    if (exerciseId) {
      where += ` AND s.exercise_id = $${paramIdx++}`;
      params.push(exerciseId);
    }
    if (search) {
      where += ` AND u.name ILIKE $${paramIdx++}`;
      params.push(`%${search}%`);
    }

    const { rows } = await db.query(
      `SELECT s.id, s.student_id, u.name AS student_name, u.email AS student_email,
              s.exercise_id, ex.title AS exercise_title, c.name AS concept_name, ex.deadline, ex.closed_at,
              s.attempt_number, s.is_correct, s.code, s.compiler_log,
              s.submitted_at, s.time_spent_seconds,
              (SELECT COUNT(*) FROM integrity_flags f WHERE f.student_id = s.student_id AND f.exercise_id = s.exercise_id AND f.status = 'flagged')::int AS flag_count
       FROM submissions s
       JOIN users u ON s.student_id = u.id
       JOIN exercises ex ON s.exercise_id = ex.id
       JOIN concepts c ON ex.concept_id = c.id
       ${where}
       ORDER BY s.submitted_at ASC, s.attempt_number ASC NULLS LAST, s.id ASC`,
      params
    );

    if (rows.length > MAX_SUBMISSION_GROUP_ROWS) {
      console.warn(`getSectionSubmissionGroups: ${rows.length} rows exceed safety cap ${MAX_SUBMISSION_GROUP_ROWS}`);
    }

    // Group in JS keyed by (student_id, exercise_id) pair.
    const groupMap = new Map();
    for (const row of rows) {
      const key = `${row.student_id}:${row.exercise_id}`;
      let group = groupMap.get(key);
      if (!group) {
        group = {
          student_id: row.student_id,
          student_name: row.student_name,
          student_email: row.student_email,
          exercise_id: row.exercise_id,
          exercise_title: row.exercise_title,
          concept_name: row.concept_name,
          deadline: row.deadline,
          closed_at: row.closed_at,
          flag_count: row.flag_count,
          attempt_count: 0,
          latest: null,
          latest_is_correct: null,
          latest_submitted_at: null,
          best_status: false,
          total_time_spent_seconds: 0,
          attempts: [],
        };
        groupMap.set(key, group);
      }
      group.attempts.push(row);
      group.attempt_count += 1;
      group.total_time_spent_seconds += (row.time_spent_seconds ?? 0);
      if (row.is_correct) group.best_status = true;

      const cur = group.latest;
      if (
        !cur ||
        new Date(row.submitted_at).getTime() > new Date(cur.submitted_at).getTime() ||
        (new Date(row.submitted_at).getTime() === new Date(cur.submitted_at).getTime() &&
          (row.attempt_number ?? -1) > (cur.attempt_number ?? -1))
      ) {
        group.latest = row;
      }
    }

    let groups = Array.from(groupMap.values());

    // Status filters operate on the LATEST attempt of each group.
    if (status === 'pass') {
      groups = groups.filter(g => g.latest?.is_correct === true);
    } else if (status === 'fail') {
      groups = groups.filter(g => g.latest?.is_correct === false);
    } else if (status === 'flagged') {
      groups = groups.filter(g => g.flag_count > 0);
    }

    const total = groups.length;
    const pLimit = parseInt(limit, 10) || 50;
    const pOffset = parseInt(offset, 10) || 0;
    const page = groups.slice(pOffset, pOffset + pLimit);

    for (const g of page) {
      g.latest_is_correct = g.latest ? g.latest.is_correct : null;
      g.latest_submitted_at = g.latest ? g.latest.submitted_at : null;
    }

    res.json({ groups: page, total, limit: pLimit, offset: pOffset });
  } catch (err) {
    console.error('getSectionSubmissionGroups error:', err);
    next(err);
  }
};

// users.deleted_at is added by a runtime patch on some environments; the
// non-submitters query references it conditionally so it works everywhere.
let usersHaveDeletedAt = null;
async function usersHaveDeletedAtColumn() {
  if (usersHaveDeletedAt !== null) return usersHaveDeletedAt;
  try {
    const r = await db.query(
      `SELECT 1 FROM information_schema.columns
       WHERE table_name = 'users' AND column_name = 'deleted_at'`
    );
    usersHaveDeletedAt = r.rows.length > 0;
  } catch {
    usersHaveDeletedAt = false;
  }
  return usersHaveDeletedAt;
}

/**
 * GET /api/analytics/sections/:sectionId/non-submitters
 * Enrolled students with no submissions (optionally for one exercise).
 * Without ?exerciseId, per-exercise non-submitter counts are included.
 */
exports.getSectionNonSubmitters = async (req, res, next) => {
  try {
    const { sectionId } = req.params;
    const { exerciseId } = req.query;

    if (exerciseId) {
      const exRes = await db.query(
        `SELECT 1 FROM exercises WHERE id = $1 AND section_id = $2`,
        [exerciseId, sectionId]
      );
      if (!exRes.rows.length) {
        return res.status(400).json({ error: 'Exercise not found in this section' });
      }
    }

    const notDeleted = (await usersHaveDeletedAtColumn()) ? 'AND u.deleted_at IS NULL' : '';

    const totalRes = await db.query(
      `SELECT COUNT(DISTINCT u.id)::int AS total_students
       FROM enrollments e
       JOIN users u ON u.id = e.student_id
       WHERE e.section_id = $1 ${notDeleted}`,
      [sectionId]
    );
    const totalStudents = totalRes.rows[0]?.total_students || 0;

    let nonSubmitters = [];
    let perExercise = null;

    if (exerciseId) {
      const r = await db.query(
        `SELECT u.id, u.name, u.email
         FROM enrollments e
         JOIN users u ON u.id = e.student_id
         WHERE e.section_id = $1
           ${notDeleted}
           AND NOT EXISTS (
             SELECT 1 FROM submissions s
             WHERE s.student_id = u.id AND s.exercise_id = $2
           )
         ORDER BY u.name`,
        [sectionId, exerciseId]
      );
      nonSubmitters = r.rows;
    } else {
      const r = await db.query(
        `SELECT u.id, u.name, u.email
         FROM enrollments e
         JOIN users u ON u.id = e.student_id
         WHERE e.section_id = $1
           ${notDeleted}
           AND NOT EXISTS (
             SELECT 1 FROM submissions s
             JOIN exercises ex ON ex.id = s.exercise_id
             WHERE s.student_id = u.id AND ex.section_id = $1
           )
         ORDER BY u.name`,
        [sectionId]
      );
      nonSubmitters = r.rows;

      const perEx = await db.query(
        `SELECT ex.id, ex.title,
                COUNT(DISTINCT u.id) FILTER (WHERE s.id IS NULL)::int AS non_submitter_count
         FROM exercises ex
         CROSS JOIN enrollments e
         JOIN users u ON u.id = e.student_id
         LEFT JOIN submissions s
           ON s.student_id = u.id AND s.exercise_id = ex.id
         WHERE ex.section_id = $1 AND e.section_id = $1
           ${notDeleted}
         GROUP BY ex.id, ex.title
         ORDER BY ex.title`,
        [sectionId]
      );
      perExercise = perEx.rows;
    }

    res.json({
      nonSubmitters,
      total: nonSubmitters.length,
      total_students: totalStudents,
      exerciseId: exerciseId ? parseInt(exerciseId, 10) : null,
      perExercise,
    });
  } catch (err) {
    console.error('getSectionNonSubmitters error:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/submissions/:submissionId/runs
 * Returns run_attempts + final submission for the same student+exercise.
 */
exports.getSubmissionRuns = async (req, res, next) => {
  try {
    const { submissionId } = req.params;

    const subRes = await db.query(
      `SELECT student_id, exercise_id FROM submissions WHERE id = $1`,
      [submissionId]
    );
    if (!subRes.rows.length) {
      return res.status(404).json({ error: 'Submission not found' });
    }
    const { student_id, exercise_id } = subRes.rows[0];

    const runRes = await db.query(
      `SELECT id, code, compiler_log, error_count, time_limit_hit, run_at,
              false AS is_submission
       FROM run_attempts
       WHERE student_id = $1 AND exercise_id = $2
       ORDER BY run_at ASC`,
      [student_id, exercise_id]
    );

    const finalRes = await db.query(
      `SELECT id, code, compiler_log, submitted_at AS run_at,
              true AS is_submission
       FROM submissions
       WHERE student_id = $1 AND exercise_id = $2
       ORDER BY submitted_at ASC`,
      [student_id, exercise_id]
    );

    const runs = [
      ...runRes.rows.map(r => ({ ...r, error_count: r.error_count ?? 0 })),
      ...finalRes.rows.map(s => ({
        id: s.id,
        code: s.code,
        compiler_log: s.compiler_log,
        error_count: s.compiler_log ? 1 : 0,
        time_limit_hit: false,
        run_at: s.run_at,
        is_submission: true,
      })),
    ];
    runs.sort((a, b) => new Date(a.run_at) - new Date(b.run_at));

    res.json({ runs });
  } catch (err) {
    console.error('getSubmissionRuns error:', err);
    next(err);
  }
};

exports.getSubmissionFlags = async (req, res, next) => {
  try {
    const { submissionId } = req.params;
    const integrityFlagEngine = require('../services/integrityFlagEngine');
    const flags = await integrityFlagEngine.getFlagsForSubmission(submissionId);
    res.json({ flags });
  } catch (err) {
    console.error('getSubmissionFlags error:', err);
    next(err);
  }
};

/**
 * GET /api/analytics/sections/:sectionId/class-concept-radar
 * Returns per-concept aggregated CDS component data (avg NER, NRS, NTS)
 * across all students in a section, for the class-wide concept radar chart.
 */
exports.getClassConceptRadar = async (req, res, next) => {
  try {
    const { sectionId } = req.params;
    const result = await db.query(`
      SELECT
        COALESCE(pt.name, c.name) AS concept_name,
        ROUND((SUM(cs.cds * COALESCE(ect.weight, 1.0)) / NULLIF(SUM(COALESCE(ect.weight, 1.0)), 0))::numeric, 4) AS cds,
        ROUND((SUM(cs.ner * COALESCE(ect.weight, 1.0)) / NULLIF(SUM(COALESCE(ect.weight, 1.0)), 0))::numeric, 4) AS ner,
        ROUND((SUM(cs.nrs * COALESCE(ect.weight, 1.0)) / NULLIF(SUM(COALESCE(ect.weight, 1.0)), 0))::numeric, 4) AS nrs,
        ROUND((SUM(cs.nts * COALESCE(ect.weight, 1.0)) / NULLIF(SUM(COALESCE(ect.weight, 1.0)), 0))::numeric, 4) AS nts,
        COUNT(DISTINCT cs.student_id) AS student_count,
        COUNT(*) AS attempt_count
      FROM cds_scores cs
      JOIN exercises ex ON cs.exercise_id = ex.id
      JOIN concepts c ON c.id = ex.concept_id
      LEFT JOIN exercise_concept_tags ect ON ect.exercise_id = ex.id
      LEFT JOIN concepts pt ON pt.id = ect.concept_id
      WHERE cs.section_id = $1
      GROUP BY COALESCE(pt.name, c.name)
      ORDER BY COALESCE(pt.name, c.name)
    `, [sectionId]);
    res.json({ concepts: result.rows });
  } catch (err) { next(err); }
};

/**
 * Integrity audit: aggregate flag statistics for bias detection.
 * Returns per-section, per-type, and per-student breakdowns.
 * GET /api/analytics/integrity-audit
 */
exports.getIntegrityAudit = async (req, res, next) => {
  try {
    const { section_id } = req.query;

    // Total flags by type
    const byType = await db.query(`
      SELECT flag_type, COUNT(*) AS count, COUNT(*) FILTER (WHERE status = 'dismissed') AS dismissed
      FROM integrity_flags
      ${section_id ? 'WHERE section_id = $1' : ''}
      GROUP BY flag_type
      ORDER BY count DESC
    `, section_id ? [section_id] : []);

    // Total flags by severity
    const bySeverity = await db.query(`
      SELECT severity, COUNT(*) AS count
      FROM integrity_flags
      ${section_id ? 'WHERE section_id = $1' : ''}
      GROUP BY severity
      ORDER BY CASE severity WHEN 'high' THEN 1 WHEN 'medium' THEN 2 WHEN 'low' THEN 3 END
    `, section_id ? [section_id] : []);

    // Flag rate: students with at least one flag as % of enrolled students
    const flagRate = await db.query(`
      SELECT
        s.id AS section_id,
        s.name AS section_name,
        COUNT(DISTINCT e.student_id) AS enrolled,
        COUNT(DISTINCT f.student_id) AS flagged_students,
        ROUND(COUNT(DISTINCT f.student_id) * 100.0 / NULLIF(COUNT(DISTINCT e.student_id), 0), 1) AS flag_rate_pct,
        COUNT(f.id) AS total_flags
      FROM sections s
      JOIN enrollments e ON e.section_id = s.id
      LEFT JOIN integrity_flags f ON f.section_id = s.id
      ${section_id ? 'WHERE s.id = $1' : ''}
      GROUP BY s.id, s.name
      ORDER BY flag_rate_pct DESC NULLS LAST
    `, section_id ? [section_id] : []);

    // Per-student flag count distribution
    const perStudent = await db.query(`
      SELECT flag_count, COUNT(*) AS student_count
      FROM (
        SELECT student_id, COUNT(*) AS flag_count
        FROM integrity_flags
        ${section_id ? 'WHERE section_id = $1' : ''}
        GROUP BY student_id
      ) sub
      GROUP BY flag_count
      ORDER BY flag_count
    `, section_id ? [section_id] : []);

    // Dismissal rate
    const dismissalRate = await db.query(`
      SELECT
        flag_type,
        COUNT(*) AS total,
        COUNT(*) FILTER (WHERE status = 'dismissed') AS dismissed,
        ROUND(COUNT(*) FILTER (WHERE status = 'dismissed') * 100.0 / NULLIF(COUNT(*), 0), 1) AS dismissal_rate_pct
      FROM integrity_flags
      ${section_id ? 'WHERE section_id = $1' : ''}
      GROUP BY flag_type
      ORDER BY dismissal_rate_pct DESC
    `, section_id ? [section_id] : []);

    res.json({
      summary: {
        totalFlags: byType.rows.reduce((sum, r) => sum + parseInt(r.count), 0),
        totalDismissed: byType.rows.reduce((sum, r) => sum + parseInt(r.dismissed || '0'), 0),
        sections: flagRate.rows,
      },
      byType: byType.rows,
      bySeverity: bySeverity.rows,
      perStudent: perStudent.rows,
      dismissalRate: dismissalRate.rows,
    });
  } catch (err) {
    console.error('getIntegrityAudit error:', err);
    next(err);
  }
};
