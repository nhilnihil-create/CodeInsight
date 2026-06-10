const express = require('express');
const router  = express.Router();
const db = require('../config/db');
const { runAgainstTestCases } = require('../services/executor');
const cdsEngine = require('../services/cdsEngine');
const { verifyToken, requireRole } = require('../middleware/auth');
const { AppError, codes } = require('../lib/AppError');

// Get all exercises for enrolled sections
router.get('/exercises', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const r = await db.query(`
      SELECT
        ex.id, ex.title, ex.description, c.name AS concept_name,
        ex.time_limit_minutes, ex.deadline, ex.test_cases,
        CASE WHEN cs.cds IS NOT NULL THEN 'completed' ELSE 'pending' END AS status,
        cs.cds
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id
      LEFT JOIN cds_scores cs ON cs.exercise_id = ex.id AND cs.student_id = $1
      WHERE en.student_id = $1 AND ex.is_draft = false
      ORDER BY ex.created_at DESC
    `, [req.user.id]);
    res.json(r.rows);
  } catch (err) { next(err); }
});

// Get single exercise details
router.get('/exercises/:id', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const r = await db.query(`
      SELECT ex.*, c.name AS concept_name
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id
      WHERE ex.id = $1 AND en.student_id = $2
    `, [req.params.id, req.user.id]);

    if (!r.rows.length) throw new AppError('Exercise not found', 404, codes.NOT_FOUND);

    const ex = r.rows[0];
    if (ex.test_cases) {
      let testCases = typeof ex.test_cases === 'string' ? JSON.parse(ex.test_cases) : ex.test_cases;
      ex.test_cases = testCases.filter(tc => !tc.hidden);
    }

    const completedRes = await db.query(`
      SELECT id, submitted_at FROM submissions
      WHERE exercise_id = $1 AND student_id = $2 AND is_correct = true
      LIMIT 1
    `, [req.params.id, req.user.id]);
    ex.isCompleted = completedRes.rows.length > 0;
    ex.completedAt = ex.isCompleted ? completedRes.rows[0].submitted_at : null;
    res.json(ex);
  } catch (err) { next(err); }
});

// Run code (visible tests only)
router.post('/exercises/:id/run', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const { code } = req.body;
    if (!code) throw new AppError('Code required', 400, codes.VALIDATION);

    const exRes = await db.query('SELECT * FROM exercises WHERE id = $1', [req.params.id]);
    if (!exRes.rows.length) throw new AppError('Exercise not found', 404, codes.NOT_FOUND);

    const exercise = exRes.rows[0];
    const testCases = typeof exercise.test_cases === 'string'
      ? JSON.parse(exercise.test_cases) : (exercise.test_cases || []);
    const visibleTC = testCases.filter(tc => !tc.hidden);

    if (!visibleTC.length) {
      return res.json({
        passed: true, testResults: [], compilerError: null, microConceptFeedback: null,
        message: 'No visible test cases',
      });
    }

    // Log run_clicked (audit trail)
    await db.query(
      `INSERT INTO audit_log (student_id, exercise_id, event_type, metadata, occurred_at)
       VALUES ($1, $2, 'run_clicked', $3, NOW())`,
      [req.user.id, req.params.id, JSON.stringify({ code_length: code.length })]
    );

    let results = [];
    let compilerError = null;
    try {
      results = await runAgainstTestCases(code, visibleTC, exercise.time_limit_minutes * 60, true);
      const compileErrorResult = results.find(r => r.status === 'Compile Error');
      if (compileErrorResult) compilerError = compileErrorResult.error;
    } catch (execErr) {
      compilerError = execErr.message;
      results = [{
        input: 'N/A', expected: 'N/A', actual: '', passed: false,
        status: 'Execution Error', error: execErr.message, hidden: false,
      }];
    }

    res.json({
      passed: results.every(r => r.passed),
      testResults: results,
      compilerError,
      microConceptFeedback: null,
    });
  } catch (err) { next(err); }
});

// Submit code (all tests, save submission, persist behavioral events)
router.post('/exercises/:id/submit', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const { code, timeSpentSeconds, behavioralEvents = [] } = req.body;
    if (!code) throw new AppError('Code required', 400, codes.VALIDATION);

    const exRes = await db.query('SELECT * FROM exercises WHERE id = $1', [req.params.id]);
    if (!exRes.rows.length) throw new AppError('Exercise not found', 404, codes.NOT_FOUND);

    const exercise = exRes.rows[0];
    const allTestCases = typeof exercise.test_cases === 'string'
      ? JSON.parse(exercise.test_cases) : (exercise.test_cases || []);
    // Support both new isVisible and legacy hidden fields
    const visibleTestCases = allTestCases.filter(tc => {
      if (tc.isVisible !== undefined) return tc.isVisible;
      if (tc.hidden !== undefined) return !tc.hidden;
      return true;
    });

    let allResults = [];
    let visibleResults = [];
    let passed = false;
    let compilerError = null;

    try {
      allResults = await runAgainstTestCases(code, allTestCases, exercise.time_limit_minutes * 60, false);
      const compileErrorResult = allResults.find(r => r.status === 'Compile Error');
      if (compileErrorResult) compilerError = compileErrorResult.error;
      passed = allResults.every(r => r.passed);
      visibleResults = allResults.filter(r => !r.hidden);
    } catch (execErr) {
      compilerError = execErr.message;
      visibleResults = [{
        input: 'N/A', expected: 'N/A', actual: '', passed: false,
        status: 'Execution Error', error: execErr.message, hidden: false,
      }];
    }

    const attemptRes = await db.query(
      'SELECT COUNT(*)::int AS count FROM submissions WHERE exercise_id = $1 AND student_id = $2',
      [req.params.id, req.user.id]
    );
    const attempt_number = (attemptRes.rows[0].count || 0) + 1;

    const subRes = await db.query(`
      INSERT INTO submissions
        (exercise_id, student_id, code, is_correct, attempt_number, time_spent_seconds, submitted_at)
      VALUES ($1, $2, $3, $4, $5, $6, NOW())
      RETURNING id, exercise_id, student_id, is_correct, attempt_number, submitted_at, time_spent_seconds
    `, [exercise.id, req.user.id, code, passed, attempt_number, timeSpentSeconds || 0]);

    // Persist behavioral events (passive logging — HIGH #1)
    if (Array.isArray(behavioralEvents) && behavioralEvents.length) {
      try {
        const values = [];
        const placeholders = [];
        behavioralEvents.forEach((ev, i) => {
          const base = i * 5;
          placeholders.push(`($${base + 1}, $${base + 2}, $${base + 3}, $${base + 4}, $${base + 5})`);
          values.push(
            req.user.id,
            exercise.id,
            ev.type || 'unknown',
            ev.timestamp || new Date().toISOString(),
            JSON.stringify(ev.payload || {})
          );
        });
        await db.query(
          `INSERT INTO behavioral_events
             (student_id, exercise_id, event_type, occurred_at, payload)
           VALUES ${placeholders.join(',')}`,
          values
        );
      } catch (evErr) {
        // Non-fatal: behavioural events are observational
        // eslint-disable-next-line no-console
        console.warn('Failed to persist behavioral events:', evErr.message);
      }
    }

    // Live CDS for student-facing display
    let liveCDS = null;
    try {
      liveCDS = await cdsEngine.calculateLiveCDS(req.user.id, exercise.id, db);
      if (liveCDS && liveCDS.cds !== null) {
        await db.query(`
          INSERT INTO cds_scores (student_id, exercise_id, section_id, ner, nrs, nts, cds, classification, has_flagged_attempts, integrity_flag_count, source, visible, computed_at)
          VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, 'live', false, NOW())
          ON CONFLICT (student_id, exercise_id)
          DO UPDATE SET ner=$4, nrs=$5, nts=$6, cds=$7, classification=$8, has_flagged_attempts=$9, integrity_flag_count=$10, source='live', visible=false, computed_at=NOW()
        `, [
          req.user.id, exercise.id, exercise.section_id,
          liveCDS.ner || 0, liveCDS.nrs || 0, liveCDS.nts || 0,
          liveCDS.cds || 0, liveCDS.classification || 'Unscored',
          liveCDS.hasFlaggedAttempt || false, liveCDS.integrityFlagCount || 0,
        ]);
      }
    } catch (liveErr) {
      // eslint-disable-next-line no-console
      console.warn('Live CDS calculation failed:', liveErr.message);
    }

    res.status(201).json({
      ...subRes.rows[0],
      passed: subRes.rows[0].is_correct,
      testResults: visibleResults,
      compilerError,
      hiddenTestCount: allTestCases.filter(tc => tc.hidden).length,
      liveCDS,
      isCompleted: subRes.rows[0].is_correct,
      message: 'Submission saved successfully',
    });
  } catch (err) { next(err); }
});

// ▶ PRACTICE — save attempt without impacting CDS analytics (post-completion mode)
router.post('/exercises/:id/practice', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const { code, timeSpentSeconds } = req.body;
    if (!code) throw new AppError('Code required', 400, codes.VALIDATION);

    const exRes = await db.query('SELECT * FROM exercises WHERE id = $1', [req.params.id]);
    if (!exRes.rows.length) throw new AppError('Exercise not found', 404, codes.NOT_FOUND);
    const exercise = exRes.rows[0];
    if (exercise.closed_at) throw new AppError('Exercise is closed', 400, codes.VALIDATION);

    // Verify the student has already completed this exercise (practice = post-completion)
    const completedRes = await db.query(
      `SELECT id FROM submissions
       WHERE student_id = $1 AND exercise_id = $2 AND is_correct = true
       LIMIT 1`,
      [req.user.id, req.params.id]
    );
    if (!completedRes.rows.length) {
      throw new AppError('Exercise must be completed before practice mode', 403, codes.VALIDATION);
    }

    const allTestCases = typeof exercise.test_cases === 'string'
      ? JSON.parse(exercise.test_cases) : (exercise.test_cases || []);

    let allResults = [];
    let visibleResults = [];
    let passed = false;
    let compilerError = null;

    try {
      allResults = await runAgainstTestCases(code, allTestCases, exercise.time_limit_minutes * 60, false);
      const compileErrorResult = allResults.find(r => r.status === 'Compile Error');
      if (compileErrorResult) compilerError = compileErrorResult.error;
      passed = allResults.every(r => r.passed);
      visibleResults = allResults.filter(r => !r.hidden);
    } catch (execErr) {
      compilerError = execErr.message;
    }

    const attemptRes = await db.query(
      'SELECT COUNT(*)::int AS count FROM submissions WHERE exercise_id = $1 AND student_id = $2',
      [req.params.id, req.user.id]
    );
    const attempt_number = (attemptRes.rows[0].count || 0) + 1;

    // Save with is_practice = true (no CDS impact)
    const subRes = await db.query(`
      INSERT INTO submissions
        (exercise_id, student_id, code, is_correct, attempt_number, time_spent_seconds, is_practice, submitted_at)
      VALUES ($1, $2, $3, $4, $5, $6, true, NOW())
      RETURNING id, exercise_id, student_id, is_correct, attempt_number, submitted_at, time_spent_seconds
    `, [exercise.id, req.user.id, code, passed, attempt_number, timeSpentSeconds || 0]);

    // Log practice attempt in audit trail
    await db.query(
      `INSERT INTO audit_log (student_id, exercise_id, event_type, metadata, occurred_at)
       VALUES ($1, $2, 'submission_attempted', $3, NOW())`,
      [req.user.id, req.params.id, JSON.stringify({
        attempt_number, is_practice: true,
        code_length: code.length, time_spent_seconds: timeSpentSeconds || 0
      })]
    );

    res.status(201).json({
      ...subRes.rows[0],
      passed: subRes.rows[0].is_correct,
      testResults: visibleResults,
      compilerError,
      hiddenTestCount: allTestCases.filter(tc => tc.hidden).length,
      isPractice: true,
      message: 'Practice attempt saved (does not affect CDS)',
    });
  } catch (err) { next(err); }
});

router.get('/exercises/:id/attempts', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const r = await db.query(`
      SELECT id, exercise_id, is_correct AS passed, attempt_number, submitted_at
      FROM submissions WHERE exercise_id = $1 AND student_id = $2
      ORDER BY submitted_at DESC LIMIT 10
    `, [req.params.id, req.user.id]);
    res.json(r.rows || []);
  } catch (err) { next(err); }
});

router.get('/dashboard', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const studentId = req.user.id;

    // 1. Exercises — find due-soon count, nearest deadline, and all for recommendations
    const exercisesRes = await db.query(`
      SELECT ex.id, ex.title, ex.description, c.name AS concept_name,
             ex.time_limit_minutes, ex.deadline,
             CASE WHEN cs.cds IS NOT NULL THEN 'completed' ELSE 'pending' END AS status,
             cs.cds, cs.classification
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id
      LEFT JOIN cds_scores cs ON cs.exercise_id = ex.id AND cs.student_id = $1
      WHERE en.student_id = $1 AND ex.is_draft = false
      ORDER BY ex.deadline ASC NULLS LAST
    `, [studentId]);

    const allExercises = exercisesRes.rows || [];
    const pendingExercises = allExercises.filter(ex => ex.status === 'pending');
    const dueSoonThreshold = new Date(Date.now() + 7 * 24 * 60 * 60 * 1000); // 7 days
    const dueCount = pendingExercises.filter(ex => ex.deadline && new Date(ex.deadline) <= dueSoonThreshold).length;

    // Nearest deadline exercise
    const nearestDeadline = pendingExercises
      .filter(ex => ex.deadline)
      .sort((a, b) => new Date(a.deadline) - new Date(b.deadline))[0] || null;

    // 2. CDS scores — avg + per-concept breakdown
    const cdsRes = await db.query(`
      SELECT cs.cds, cs.classification, cs.exercise_id, c.name AS concept_name, ex.title AS exercise_title
      FROM cds_scores cs
      JOIN exercises ex ON ex.id = cs.exercise_id
      JOIN concepts c ON c.id = ex.concept_id
      WHERE cs.student_id = $1
      ORDER BY cs.computed_at DESC
    `, [studentId]);
    const scores = cdsRes.rows || [];
    const avgCds = scores.length > 0
      ? scores.reduce((sum, s) => sum + parseFloat(s.cds || 0), 0) / scores.length
      : 0;

    // 3. Stats — exercise completion (activity metric, not mastery, learning mode only)
    const statsRes = await db.query(`
      SELECT
        COUNT(DISTINCT ex.id)::int AS total,
        (SELECT COUNT(DISTINCT s.exercise_id)::int FROM submissions s JOIN exercises ex2 ON s.exercise_id = ex2.id WHERE s.student_id = $1 AND s.is_correct = true AND ex2.mode = 'learning' AND s.is_practice IS NOT TRUE) AS completed
      FROM exercises ex
      JOIN enrollments en ON en.section_id = ex.section_id
      WHERE en.student_id = $1 AND ex.is_draft = false
    `, [studentId]);
    const total = statsRes.rows[0]?.total || 0;
    const completed = statsRes.rows[0]?.completed || 0;
    const completionPct = total > 0 ? Math.round((completed / total) * 100) : 0;
    // Mastery = 100 - avgCDS (inverse of difficulty)
    const masteryPct = Math.round((1 - avgCds) * 100);

    // 4. Streak — consecutive days with submissions (learning mode only)
    const streakRes = await db.query(`
      SELECT DISTINCT DATE(s.submitted_at) AS active_date
      FROM submissions s JOIN exercises ex ON s.exercise_id = ex.id
      WHERE s.student_id = $1 AND s.submitted_at IS NOT NULL
        AND ex.mode = 'learning' AND s.is_practice IS NOT TRUE
      ORDER BY active_date DESC
    `, [studentId]);
    const activeDays = (streakRes.rows || []).map(r => r.active_date);
    let currentStreak = 0;
    const today = new Date();
    today.setHours(0, 0, 0, 0);
    for (let i = 0; i < activeDays.length; i++) {
      const expected = new Date(today);
      expected.setDate(expected.getDate() - i);
      const actual = new Date(activeDays[i]);
      actual.setHours(0, 0, 0, 0);
      if (actual.getTime() === expected.getTime()) {
        currentStreak++;
      } else {
        break;
      }
    }
    // Best streak (simple: longest consecutive in the data)
    let bestStreak = currentStreak;
    let run = 1;
    for (let i = 1; i < activeDays.length; i++) {
      const prev = new Date(activeDays[i - 1]);
      const curr = new Date(activeDays[i]);
      prev.setHours(0, 0, 0, 0);
      curr.setHours(0, 0, 0, 0);
      const diff = (prev.getTime() - curr.getTime()) / (1000 * 60 * 60 * 24);
      if (diff === 1) {
        run++;
        bestStreak = Math.max(bestStreak, run);
      } else {
        run = 1;
      }
    }

    // Weakest concepts: group by concept, take 3 lowest avg CDS
    const conceptMap = {};
    for (const s of scores) {
      if (!conceptMap[s.concept_name]) conceptMap[s.concept_name] = { scores: [], count: 0 };
      conceptMap[s.concept_name].scores.push(parseFloat(s.cds || 0));
      conceptMap[s.concept_name].count++;
    }
    const weakestConcepts = Object.entries(conceptMap)
      .map(([name, data]) => ({
        name,
        avgCds: data.scores.reduce((a, b) => a + b, 0) / data.scores.length,
        exerciseCount: data.count,
      }))
      .sort((a, b) => a.avgCds - b.avgCds)
      .slice(0, 3)
      .map(c => ({
        ...c,
        level: c.avgCds <= 0.33 ? 'low' : c.avgCds <= 0.66 ? 'moderate' : 'high',
        hint: `${c.exerciseCount} exercise${c.exerciseCount !== 1 ? 's' : ''} completed`,
      }));

    // 5. Notifications as "recent feedback"
    const notifRes = await db.query(`
      SELECT n.id, n.message, n.created_at, n.notification_type,
             COALESCE(u.name, 'System') AS author_name
      FROM notifications n
      LEFT JOIN sections s ON s.id = n.section_id
      LEFT JOIN users u ON u.id = s.instructor_id
      WHERE n.student_id = $1
      ORDER BY n.created_at DESC
      LIMIT 5
    `, [studentId]);
    let recentFeedback = (notifRes.rows || []).map(n => ({
      id: n.id,
      author: n.author_name,
      initials: n.author_name.split(' ').map(w => w[0]).filter(Boolean).join('').substring(0, 2).toUpperCase(),
      when: formatRelativeTime(n.created_at),
      body: n.message,
    }));

    // If no notifications, fall back to enrolled section instructor info
    if (recentFeedback.length === 0) {
      const instructorRes = await db.query(`
        SELECT u.name, u.id
        FROM enrollments en
        JOIN sections s ON s.id = en.section_id
        JOIN users u ON u.id = s.instructor_id
        WHERE en.student_id = $1
        LIMIT 1
      `, [studentId]);
      if (instructorRes.rows.length) {
        recentFeedback.push({
          id: 'welcome',
          author: instructorRes.rows[0].name,
          initials: instructorRes.rows[0].name.split(' ').map(w => w[0]).filter(Boolean).join('').substring(0, 2).toUpperCase(),
          when: 'just now',
          body: 'Welcome! Complete your first exercise to get personalized feedback here.',
        });
      }
    }

    // 6. Recommended exercises — pending ones sorted by CDS (lowest first)
    const recommended = pendingExercises
      .map(ex => ({
        id: ex.id,
        title: ex.title,
        concept: ex.concept_name?.substring(0, 2).toUpperCase() || '??',
        conceptName: ex.concept_name || 'Unknown',
        blurb: ex.description?.substring(0, 80) || '',
        minutes: ex.time_limit_minutes || 30,
        status: ex.status,
      }))
      .slice(0, 3);

    res.json({
      dueExercises: {
        count: dueCount,
        nearestDeadline: nearestDeadline ? {
          id: nearestDeadline.id,
          title: nearestDeadline.title,
          deadline: nearestDeadline.deadline,
          minutesUntilDue: nearestDeadline.deadline
            ? Math.round((new Date(nearestDeadline.deadline) - Date.now()) / 60000)
            : null,
          concept: nearestDeadline.concept_name,
          status: nearestDeadline.status,
        } : null,
      },
      mastery: {
        percentage: masteryPct,
        series: activeDays.slice(0, 5).reverse().map((_, i) => masteryPct),
      },
      completion: {
        percentage: completionPct,
        completed,
        total,
      },
      streak: {
        current: currentStreak,
        best: bestStreak,
        series: activeDays.slice(0, 5).reverse().map((_, i) => Math.min(currentStreak, i + 1)),
      },
      avgCds: Math.round(avgCds * 100) / 100,
      weakestConcepts,
      recentFeedback,
      recommended,
    });
  } catch (err) { next(err); }
});

// Get student's own integrity flags
router.get('/integrity-flags', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const studentId = req.user.id;
    const r = await db.query(`
      SELECT i.id, i.flag_type AS rule, i.evidence, i.status, i.created_at,
             e.title AS exercise_title
      FROM integrity_flags i
      JOIN exercises e ON e.id = i.exercise_id
      WHERE i.student_id = $1
      ORDER BY i.created_at DESC
    `, [studentId]);
    const flags = r.rows.map(row => {
      let evidence = row.evidence;
      if (typeof evidence === 'string') {
        try { evidence = JSON.parse(evidence); } catch { /* leave as string */ }
      }
      return {
        id: row.id,
        rule: row.rule,
        exercise: row.exercise_title,
        description: `${row.rule} detected on ${row.exercise_title}.`,
        evidence: Array.isArray(evidence) ? evidence.join('. ') : String(evidence || ''),
        date: row.created_at,
      };
    });
    res.json({ flags });
  } catch (err) { next(err); }
});

// Get today's personalized study plan
router.get('/today', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const studentId = req.user.id;

    // 1. Exercises with concept CDS
    const exercisesRes = await db.query(`
      SELECT ex.id, ex.title, ex.description, c.name AS concept_name,
             ex.time_limit_minutes, ex.deadline,
             CASE WHEN cs.cds IS NOT NULL THEN 'completed' ELSE 'pending' END AS status,
             cs.cds
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id
      LEFT JOIN cds_scores cs ON cs.exercise_id = ex.id AND cs.student_id = $1
      WHERE en.student_id = $1 AND ex.is_draft = false
      ORDER BY ex.deadline ASC NULLS LAST
    `, [studentId]);

    const allExercises = exercisesRes.rows || [];
    const pending = allExercises.filter(ex => ex.status === 'pending');

    // 2. Concept-level CDS (avg across all exercises per concept)
    const conceptCdsRes = await db.query(`
      SELECT c.name AS concept_name,
             AVG(cs.cds)::float AS avg_cds,
             COUNT(cs.cds)::int AS completed_count
      FROM cds_scores cs
      JOIN exercises ex ON ex.id = cs.exercise_id
      JOIN concepts c ON c.id = ex.concept_id
      WHERE cs.student_id = $1
      GROUP BY c.name
      ORDER BY avg_cds DESC
    `, [studentId]);

    const conceptCds = conceptCdsRes.rows || [];
    const conceptMap = {};
    for (const row of conceptCds) {
      conceptMap[row.concept_name] = {
        avgCds: parseFloat(row.avg_cds) || 0,
        completedCount: row.completed_count,
      };
    }

    // 3. Build concept list with CDS codes
    const conceptCodes = {
      Loops: 'LP', Arrays: 'AR', Functions: 'FN', Pointers: 'PT',
      OOP: 'OP', Variables: 'VR', Datatypes: 'DT', Conditionals: 'CD',
    };

    const concepts = conceptCds.map(c => ({
      concept: conceptCodes[c.concept_name] || c.concept_name.substring(0, 2).toUpperCase(),
      name: c.concept_name,
      cds: c.avgCds,
      delta: 0, // no historical delta yet
      trend: c.avgCds <= 0.33 ? 'up' : c.avgCds <= 0.66 ? 'flat' : 'down',
    }));

    // 4. Focus: pick the pending exercise with the highest concept CDS (hardest next)
    const focusEx = pending
      .map(ex => ({
        ...ex,
        conceptCds: conceptMap[ex.concept_name]?.avgCds ?? 0,
      }))
      .sort((a, b) => b.conceptCds - a.conceptCds)[0] || null;

    // 5. Class avg on the focus concept
    let classAvg = 0.5; // default
    if (focusEx) {
      const classRes = await db.query(`
        SELECT AVG(cs.cds)::float AS class_avg
        FROM cds_scores cs
        JOIN exercises ex ON ex.id = cs.exercise_id
        JOIN concepts c ON c.id = ex.concept_id
        JOIN enrollments en ON en.section_id = ex.section_id
        WHERE c.name = $1 AND en.student_id = cs.student_id
      `, [focusEx.concept_name]);
      if (classRes.rows[0]?.class_avg != null) {
        classAvg = parseFloat(classRes.rows[0].class_avg);
      }
    }

    // 6. Signals — auto-generated from student data
    const signals = [];
    if (conceptCds.length > 0) {
      const strongest = conceptCds[conceptCds.length - 1];
      const weakest = conceptCds[0];
      if (strongest.avgCds <= 0.33) {
        signals.push(`You have strong performance on ${strongest.concept_name} — consider advancing to harder exercises.`);
      }
      if (weakest.avgCds >= 0.66) {
        signals.push(`${weakest.concept_name} exercises take you longer than average — practice will help.`);
      }
    }
    if (focusEx) {
      signals.push(`Focus on ${focusEx.concept_name} — it's the concept with the highest remaining CDS.`);
    }

    // 7. Next moves
    const nextMoves = [];
    if (focusEx) {
      nextMoves.push({
        label: `Start ${focusEx.title}`,
        to: `/student/exercises/${focusEx.id}`,
        primary: true,
      });
    }
    // Add 1-2 more moves from other pending exercises
    for (const ex of pending.slice(1, 3)) {
      nextMoves.push({
        label: `Review ${ex.concept_name}`,
        to: `/student/exercises/${ex.id}`,
        primary: false,
      });
    }

    // 8. Why explanation
    const why = focusEx
      ? `${focusEx.concept_name} is the concept with the highest CDS for your pending exercises. Working on it now will have the biggest impact on your overall mastery.`
      : "You're all caught up! Explore more exercises or review previous concepts to strengthen your mastery.";

    res.json({
      focus: {
        title: focusEx ? focusEx.title : 'All caught up!',
        estimatedMinutes: focusEx ? `${focusEx.time_limit_minutes || 15} min` : '—',
        concept: focusEx ? (conceptCodes[focusEx.concept_name] || '??') : '—',
      },
      why,
      classAvg: Math.round(classAvg * 100) / 100,
      concepts,
      signals,
      nextMoves,
    });
  } catch (err) { next(err); }
});

router.get('/stats', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const totalRes = await db.query(`
      SELECT COUNT(DISTINCT ex.id)::int AS total
      FROM exercises ex
      JOIN enrollments en ON en.section_id = ex.section_id
      WHERE en.student_id = $1 AND ex.is_draft = false
    `, [req.user.id]);
    const completedRes = await db.query(`
      SELECT COUNT(DISTINCT s.exercise_id)::int AS completed
      FROM submissions s JOIN exercises ex ON s.exercise_id = ex.id
      WHERE s.student_id = $1 AND s.is_correct = true
        AND ex.mode = 'learning' AND s.is_practice IS NOT TRUE
    `, [req.user.id]);
    const total = totalRes.rows[0].total || 0;
    const completed = completedRes.rows[0].completed || 0;
    res.json({
      total_exercises: total,
      completed_exercises: completed,
      pending_exercises: total - completed,
      average_cds: 0,
    });
  } catch (err) { next(err); }
});

// Get student's progress overview: mastery, activity, submissions
router.get('/progress', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const studentId = req.user.id;
    const daysParam = Math.max(1, parseInt(req.query.days, 10) || 30);
    const interval = `${daysParam} days`;

    // 1. Concept mastery — CDS aggregated by concept
    const conceptCdsRes = await db.query(`
      SELECT c.name AS concept_name,
             AVG(cs.cds)::float AS avg_cds,
             COUNT(cs.cds)::int AS exercise_count
      FROM cds_scores cs
      JOIN exercises ex ON ex.id = cs.exercise_id
      JOIN concepts c ON ex.concept_id = c.id
      WHERE cs.student_id = $1 AND cs.computed_at > NOW() - INTERVAL '${interval}'
      GROUP BY c.name
      ORDER BY avg_cds ASC
    `, [studentId]);

    const conceptCodes = {
      Loops: 'LP', Arrays: 'AR', Functions: 'FN', Pointers: 'PT',
      OOP: 'OP', Variables: 'VR', Datatypes: 'DT', Conditionals: 'CD',
    };
    const masteryConcepts = conceptCdsRes.rows.map(r => {
      const masteryPct = Math.round((1 - parseFloat(r.avg_cds)) * 100);
      // Level reflects MASTERY (not difficulty). Higher mastery = better.
      // "strong" = student grasps the concept well; "developing" = moderate;
      // "needs_support" = struggling. Avoids "high/low" ambiguity where
      // "high CDS" is bad but "high mastery" is good.
      const level = masteryPct >= 75 ? 'strong' : masteryPct >= 50 ? 'developing' : 'needs_support';
      const code = conceptCodes[r.concept_name] || r.concept_name.substring(0, 2).toUpperCase();
      return {
        concept_code: code,
        concept_name: r.concept_name,
        mastery: masteryPct,
        cds: Math.round(parseFloat(r.avg_cds) * 100) / 100,
        exerciseCount: r.exercise_count,
        level,
        delta: 0,
      };
    });

    // 2. Exercise completion percentage (activity, not mastery)
    const completionRes = await db.query(`
      SELECT COUNT(DISTINCT ex.id)::int AS total,
             (SELECT COUNT(DISTINCT exercise_id)::int FROM submissions WHERE student_id = $1 AND is_correct = true) AS completed
      FROM exercises ex
      JOIN enrollments en ON en.section_id = ex.section_id
      WHERE en.student_id = $1 AND ex.is_draft = false
    `, [studentId]);
    const total = completionRes.rows[0]?.total || 0;
    const completed = completionRes.rows[0]?.completed || 0;
    const completionPct = total > 0 ? Math.round((completed / total) * 100) : 0;

    // 3. Overall mastery — average of per-concept mastery (100 - CDS)
    // Mastery is the inverse of difficulty: high CDS = low mastery.
    const overallMastery = masteryConcepts.length > 0
      ? Math.round(masteryConcepts.reduce((sum, c) => sum + c.mastery, 0) / masteryConcepts.length)
      : 0;

    // 3b. Streak (learning mode only, exclude practice)
    const streakRes = await db.query(`
      SELECT DISTINCT DATE(s.submitted_at) AS active_date
      FROM submissions s JOIN exercises ex ON s.exercise_id = ex.id
      WHERE s.student_id = $1 AND s.submitted_at IS NOT NULL
        AND ex.mode = 'learning' AND s.is_practice IS NOT TRUE
      ORDER BY active_date DESC
    `, [studentId]);
    const activeDays = (streakRes.rows || []).map(r => r.active_date);
    let currentStreak = 0;
    const today = new Date();
    today.setHours(0, 0, 0, 0);
    for (let i = 0; i < activeDays.length; i++) {
      const expected = new Date(today);
      expected.setDate(expected.getDate() - i);
      const actual = new Date(activeDays[i]);
      actual.setHours(0, 0, 0, 0);
      if (actual.getTime() === expected.getTime()) {
        currentStreak++;
      } else {
        break;
      }
    }

    // 4. Activity heatmap data — last 12 weeks, daily submission counts (learning mode only)
    const activityRes = await db.query(`
      SELECT DATE_TRUNC('day', s.submitted_at) AS day, COUNT(*)::int AS count
      FROM submissions s JOIN exercises ex ON s.exercise_id = ex.id
      WHERE s.student_id = $1 AND s.submitted_at > NOW() - INTERVAL '84 days'
        AND ex.mode = 'learning' AND s.is_practice IS NOT TRUE
      GROUP BY DATE_TRUNC('day', s.submitted_at)
      ORDER BY day ASC
    `, [studentId]);
    const activityMap = {};
    for (const row of activityRes.rows) {
      const dayStr = row.day.toISOString().substring(0, 10);
      activityMap[dayStr] = parseInt(row.count);
    }
    // Build 12-week array [week][dayOfWeek] = count
    const heatWeeks = 12;
    const heatData = Array.from({ length: heatWeeks }, () => Array(7).fill(0));
    const now = new Date();
    now.setHours(0, 0, 0, 0);
    for (let w = heatWeeks - 1; w >= 0; w--) {
      for (let d = 0; d < 7; d++) {
        const date = new Date(now);
        date.setDate(now.getDate() - ((heatWeeks - 1 - w) * 7 + (6 - d)));
        const key = date.toISOString().substring(0, 10);
        if (activityMap[key]) {
          heatData[w][d] = activityMap[key];
        }
      }
    }

    // 5. Recent submissions
    const submissionsRes = await db.query(`
      SELECT s.id, s.exercise_id, e.title AS exercise_title, c.name AS concept_name,
             s.is_correct, s.attempt_number, s.submitted_at,
             s.time_spent_seconds, s.code_growth_delta
      FROM submissions s
      JOIN exercises e ON e.id = s.exercise_id
      JOIN concepts c ON e.concept_id = c.id
      WHERE s.student_id = $1
      ORDER BY s.submitted_at DESC
      LIMIT 50
    `, [studentId]);

    const submissions = submissionsRes.rows.map(row => ({
      id: row.id,
      exerciseId: row.exercise_id,
      exercise: row.exercise_title,
      concept: row.concept_name,
      isCorrect: row.is_correct,
      attempts: row.attempt_number,
      submittedAt: row.submitted_at,
      timeSpent: row.time_spent_seconds,
      codeGrowth: row.code_growth_delta,
      score: row.is_correct ? 1 : 0,
    }));

    // 6. Avg attempts per exercise
    const avgAttemptsRes = await db.query(`
      SELECT AVG(attempt_count)::float AS avg_attempts
      FROM (SELECT exercise_id, MAX(attempt_number) AS attempt_count
            FROM submissions WHERE student_id = $1 GROUP BY exercise_id) sub
    `, [studentId]);
    const avgAttempts = parseFloat(avgAttemptsRes.rows[0]?.avg_attempts) || 0;

    res.json({
      overallMastery: overallMastery,
      completion: {
        percentage: completionPct,
        completed,
        total,
      },
      streak: {
        current: currentStreak,
      },
      avgAttempts: Math.round(avgAttempts * 10) / 10,
      concepts: masteryConcepts,
      activity: {
        weeks: heatWeeks,
        data: heatData,
      },
      submissions,
    });
  } catch (err) { next(err); }
});

function formatRelativeTime(dateStr) {
  if (!dateStr) return 'recently';
  const now = Date.now();
  const then = new Date(dateStr).getTime();
  const diffSec = Math.round((now - then) / 1000);
  if (diffSec < 60) return 'just now';
  const diffMin = Math.round(diffSec / 60);
  if (diffMin < 60) return `${diffMin} min ago`;
  const diffHour = Math.round(diffMin / 60);
  if (diffHour < 24) return `${diffHour}h ago`;
  const diffDay = Math.round(diffHour / 24);
  if (diffDay === 1) return 'yesterday';
  if (diffDay < 30) return `${diffDay} days ago`;
  return 'long ago';
}

module.exports = router;
