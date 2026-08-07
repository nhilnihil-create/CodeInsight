const express = require('express');
const router  = express.Router();
const db = require('../config/db');
const { runAgainstTestCases } = require('../services/executor');
const cdsEngine = require('../services/cdsEngine');
const academicIntegrityEngine = require('../services/academicIntegrityEngine');
const integrityFlagEngine = require('../services/integrityFlagEngine');
const { verifyToken, requireRole } = require('../middleware/auth');
const { AppError, codes } = require('../lib/AppError');
const { rateLimit } = require('express-rate-limit');
const { defer } = require('../lib/background');
const { runWithLimit } = require('../lib/concurrency');
const { parseAST } = require('../lib/treeSitter');
const cache = require('../lib/cache');
const logger = require('../lib/logger');

const behavioralLimiter = rateLimit({
  windowMs: 60 * 1000,
  max: 60,
  standardHeaders: true,
  legacyHeaders: false,
  message: { message: 'Too many requests. Please slow down.' },
});

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
      ex.test_cases = testCases.filter(tc => !tc.hidden && !tc.is_hidden);
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

    const exRes = await db.query(`
      SELECT ex.*, c.name AS concept_name
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      WHERE ex.id = $1
    `, [req.params.id]);
    if (!exRes.rows.length) throw new AppError('Exercise not found', 404, codes.NOT_FOUND);

    const exercise = exRes.rows[0];
    const testCases = typeof exercise.test_cases === 'string'
      ? JSON.parse(exercise.test_cases) : (exercise.test_cases || []);
    const visibleTC = testCases.filter(tc => !tc.hidden && !tc.is_hidden);

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
      // Pass ALL test cases to runAgainstTestCases so hidden tests are executed and masked
      results = await runAgainstTestCases(code, testCases, exercise.time_limit_minutes * 60, true);
      const compileErrorResult = results.find(r => r.status === 'Compile Error');
      if (compileErrorResult) compilerError = compileErrorResult.error;
    } catch (execErr) {
      compilerError = execErr.message;
      results = [{
        input: 'N/A', expected: 'N/A', actual: '', passed: false,
        status: 'Execution Error', error: execErr.message, hidden: false,
      }];
    }

    const visibleResults = results.filter(r => !r.hidden);
    const hiddenResults = results.filter(r => r.hidden);
    const hiddenSummary = {
      count: hiddenResults.length,
      passed: hiddenResults.length ? hiddenResults.every(r => r.passed) : true,
    };

    res.json({
      passed: results.every(r => r.passed),
      testResults: visibleResults,
      hidden: hiddenSummary,
      compilerError,
      microConceptFeedback: null,
    });
  } catch (err) { next(err); }
});

// Submit code (all tests, save submission, persist behavioral events)
router.post('/exercises/:id/submit', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const { code, timeSpentSeconds, tabSwitchCount = 0, pasteCount = 0, idleTimeSeconds = 0 } = req.body;
    if (!code) throw new AppError('Code required', 400, codes.VALIDATION);

    const cacheKey = `exercise:${req.params.id}`;
    let exercise = cache.get(cacheKey);
    if (!exercise) {
      const exRes = await db.query(`
        SELECT ex.*, c.name AS concept_name
        FROM exercises ex
        JOIN concepts c ON c.id = ex.concept_id
        WHERE ex.id = $1
      `, [req.params.id]);
      if (!exRes.rows.length) throw new AppError('Exercise not found', 404, codes.NOT_FOUND);
      exercise = exRes.rows[0];
      cache.set(cacheKey, exercise);
    }

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
      allResults = await runWithLimit(() => runAgainstTestCases(code, allTestCases, exercise.time_limit_minutes * 60, false), 'compile');
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

    // ── Micro-Concept Analysis ─────────────────────────────────────────
    const microConceptEngine = require('../services/microConceptEngine');
    const compilerErrorsForMicro = allResults
      .filter(r => r.error && (r.status === 'Compile Error' || r.status === 'Runtime Error'))
      .map(r => r.error);

    const microContext = {
      ast: { node_types: [], if_count: 0, else_count: 0, has_private: false },
      testResults: allResults.map(r => ({
        input: r.input, expected: r.expected, actual: r.actual,
        passed: r.passed, error: r.error
      })),
      compilerErrors: compilerErrorsForMicro,
      code: code,
      timeLimitHit: allResults.some(r => r.status === 'Time Limit Exceeded'),
      exercise: {
        concept_name: exercise.concept_name || '',
        required_ast_nodes: [],
        time_limit_minutes: exercise.time_limit_minutes,
      }
    };

    microContext.ast = parseAST(code);

    let microConceptFeedback = null;
    try {
      microConceptFeedback = await microConceptEngine.getMicroConceptFeedback(microContext, exercise.concept_name || '');
    } catch (mcError) {
      console.warn('Micro-concept analysis failed:', mcError.message);
    }

    const attemptRes = await db.query(
      'SELECT COUNT(*)::int AS count FROM submissions WHERE exercise_id = $1 AND student_id = $2',
      [req.params.id, req.user.id]
    );
    const attempt_number = (attemptRes.rows[0].count || 0) + 1;

    const subRes = await db.query(`
      INSERT INTO submissions
        (exercise_id, student_id, code, is_correct, attempt_number, time_spent_seconds,
         tab_switch_count, paste_count, idle_time_seconds, submitted_at)
      VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, NOW())
      RETURNING id, exercise_id, student_id, is_correct, attempt_number, submitted_at, time_spent_seconds
    `, [exercise.id, req.user.id, code, passed, attempt_number, timeSpentSeconds || 0,
        tabSwitchCount, pasteCount, idleTimeSeconds]);

    // Send response immediately — student sees test results right away
    res.status(201).json({
      ...subRes.rows[0],
      passed: subRes.rows[0].is_correct,
      testResults: visibleResults,
      compilerError,
      hiddenTestCount: allTestCases.filter(tc => tc.hidden).length,
      liveCDS: null,
      isCompleted: subRes.rows[0].is_correct,
      microConceptFeedback,
      message: 'Submission saved successfully',
    });

    // ── Deferred post-processing (CDS, flags, checks run in background) ─
    defer(async () => {

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
        logger.warn({ err: liveErr }, 'Live CDS calculation failed');
      }

      // ── Passive Behavior Logging Flag ──────────────────────────────────
      const BEHAVIORAL_THRESHOLDS = {
        TAB_SWITCH_HIGH: 5,
        PASTE_HIGH: 3,
        IDLE_RATIO_HIGH: 0.5,
      };
      const totalTime = timeSpentSeconds || 1;
      const idleRatio = idleTimeSeconds / totalTime;
      const behavioralSignals = [];
      if (tabSwitchCount >= BEHAVIORAL_THRESHOLDS.TAB_SWITCH_HIGH) {
        behavioralSignals.push(`${tabSwitchCount} tab switches`);
      }
      if (pasteCount >= BEHAVIORAL_THRESHOLDS.PASTE_HIGH) {
        behavioralSignals.push(`${pasteCount} paste events`);
      }
      if (idleRatio >= BEHAVIORAL_THRESHOLDS.IDLE_RATIO_HIGH) {
        behavioralSignals.push(`${Math.round(idleRatio * 100)}% idle`);
      }

      if (behavioralSignals.length > 0) {
        const behavioralSeverity = behavioralSignals.length >= 2 ? 'high' : 'medium';
        try {
          await db.query(`
            INSERT INTO integrity_flags
              (section_id, exercise_id, student_id, submission_id, flag_type, severity,
               evidence, context_behaviors, status, created_at)
            VALUES ($1, $2, $3, $4, 'PASSIVE_BEHAVIOR_LOG', $5, $6, $7, 'flagged', NOW())
            ON CONFLICT (exercise_id, student_id, flag_type)
            DO UPDATE SET
              severity = EXCLUDED.severity,
              evidence = EXCLUDED.evidence,
              context_behaviors = EXCLUDED.context_behaviors,
              submission_id = EXCLUDED.submission_id
          `, [
            exercise.section_id, exercise.id, req.user.id, subRes.rows[0].id,
            behavioralSeverity,
            JSON.stringify({
              tab_switch_count: tabSwitchCount,
              paste_count: pasteCount,
              idle_time_seconds: idleTimeSeconds,
              total_time_seconds: totalTime,
              idle_ratio: Math.round(idleRatio * 100) / 100,
            }),
            [
              behavioralSignals.join('; '),
              `Attempt #${attempt_number}, time: ${totalTime}s, idle: ${idleTimeSeconds}s`,
            ],
          ]);
        } catch (flagErr) {
          logger.warn({ err: flagErr }, 'Behavioral flag creation failed');
        }
      }

      // ── Code Growth Anomaly ───────────────────────────────────────────
      try {
        const currentLineCount = (code || '').split('\n').length;
        if (attempt_number > 1) {
          const prevRes = await db.query(
            'SELECT code FROM submissions WHERE student_id=$1 AND exercise_id=$2 AND attempt_number=$3',
            [req.user.id, exercise.id, attempt_number - 1]
          );
          if (prevRes.rows.length > 0) {
            const prevLineCount = (prevRes.rows[0].code || '').split('\n').length;
            if (prevLineCount > 0) {
              const growthPercent = ((currentLineCount - prevLineCount) / prevLineCount) * 100;
              if (growthPercent > 30) {
                await integrityFlagEngine.createFlag({
                  sectionId: exercise.section_id,
                  exerciseId: exercise.id,
                  studentId: req.user.id,
                  flagType: 'CODE_GROWTH_ANOMALY',
                  severity: 'high',
                  evidence: {
                    baseline_lines: prevLineCount,
                    student_lines: currentLineCount,
                    growth_percent: Math.round(growthPercent),
                    threshold: 30,
                    attempt_number,
                  },
                  contextBehaviors: [
                    `Code grew ${Math.round(growthPercent)}% in attempt #${attempt_number} (${prevLineCount} → ${currentLineCount} lines)`,
                  ],
                  status: 'flagged',
                });
              }
            }
          }
        }
      } catch (growthErr) {
        logger.warn({ err: growthErr }, 'Code growth anomaly check failed');
      }

      // ── Academic Integrity Checks ──────────────────────────────────────
      try {
        const academicFlags = await academicIntegrityEngine.evaluateIntegrity({
          code,
          starterCode: exercise.starter_code || '',
          studentId: req.user.id,
          exerciseId: exercise.id,
          submission: {
            is_correct: passed,
            test_results: allResults,
            time_spent_seconds: timeSpentSeconds || 0,
            submission_id: subRes.rows[0].id,
          },
          exercise,
        });
        for (const flag of academicFlags) {
          await integrityFlagEngine.createFlag({
            sectionId: exercise.section_id,
            exerciseId: exercise.id,
            studentId: req.user.id,
            flagType: flag.type,
            severity: flag.severity,
            evidence: flag.evidence || {},
            contextBehaviors: flag.context_behaviors || [],
            status: 'flagged',
            submissionId: subRes.rows[0].id,
          });
        }
      } catch (integrityError) {
        logger.warn({ err: integrityError }, 'Academic integrity check failed');
      }

      // ── Behavioral Anomaly Detection ──────────────────────────────────
      try {
        const behavioralDetector = require('../services/behavioralAnomalyDetector');
        const behavioralFlags = await behavioralDetector.detectBehavioralAnomalies({
          studentId: req.user.id,
          exerciseId: exercise.id,
          submissionId: subRes.rows[0].id,
          is_correct: passed,
          time_spent_seconds: timeSpentSeconds || 0,
          attempt_number: attempt_number,
          sectionId: exercise.section_id,
        });
        for (const flag of behavioralFlags) {
          await integrityFlagEngine.createFlag({
            sectionId: exercise.section_id,
            exerciseId: exercise.id,
            studentId: req.user.id,
            flagType: flag.type,
            severity: flag.severity,
            evidence: flag.evidence || {},
            contextBehaviors: flag.context_behaviors || [],
            status: 'flagged',
            submissionId: subRes.rows[0].id,
          });
        }
      } catch (behavioralError) {
        logger.warn({ err: behavioralError }, 'Behavioral anomaly detection failed');
      }

    });
  } catch (err) { next(err); }
});

// ▶ PRACTICE — save attempt without impacting CDS analytics (post-completion)


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

    // 2. CDS scores — avg + per-concept breakdown (only from current enrollments)
    // Only real scores count: batch 'Unscored' placeholders (cds IS NULL) are
    // created for students with no submissions and must not appear as mastery.
    const cdsRes = await db.query(`
      SELECT cs.cds, cs.classification, cs.exercise_id, c.name AS concept_name, ex.title AS exercise_title
      FROM cds_scores cs
      JOIN exercises ex ON ex.id = cs.exercise_id
      JOIN concepts c ON c.id = ex.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id
      WHERE cs.student_id = $1 AND en.student_id = $1 AND cs.cds IS NOT NULL
      ORDER BY cs.computed_at DESC
    `, [studentId]);
    const scores = cdsRes.rows || [];
    const avgCds = scores.length > 0
      ? scores.reduce((sum, s) => sum + parseFloat(s.cds || 0), 0) / scores.length
      : 0;

    // 3. Stats — exercise completion (activity metric, not mastery)
    const statsRes = await db.query(`
      SELECT
        COUNT(DISTINCT ex.id)::int AS total,
        (SELECT COUNT(DISTINCT s.exercise_id)::int
         FROM submissions s
         JOIN exercises ex2 ON s.exercise_id = ex2.id
         JOIN enrollments en2 ON en2.section_id = ex2.section_id
          WHERE s.student_id = $1 AND s.is_correct = true
            AND en2.student_id = $1
        ) AS completed
      FROM exercises ex
      JOIN enrollments en ON en.section_id = ex.section_id
      WHERE en.student_id = $1 AND ex.is_draft = false
    `, [studentId]);
    const total = statsRes.rows[0]?.total || 0;
    const completed = statsRes.rows[0]?.completed || 0;
    const completionPct = total > 0 ? Math.round((completed / total) * 100) : 0;
    // Mastery = 100 - avgCDS (inverse of difficulty)
    const masteryPct = scores.length > 0 ? Math.round((1 - avgCds) * 100) : 0;

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
      .sort((a, b) => b.avgCds - a.avgCds)
      .slice(0, 3)
      .map(c => ({
        ...c,
        level: c.avgCds <= 0.40 ? 'low' : c.avgCds <= 0.60 ? 'moderate' : 'high',
        hint: `${c.exerciseCount} exercise${c.exerciseCount !== 1 ? 's' : ''} completed`,
      }));

    // 5. Recommended exercises — pending ones sorted by CDS (lowest first)
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
      },
      completion: {
        percentage: completionPct,
        completed,
        total,
      },
      avgCds: Math.round(avgCds * 100) / 100,
      weakestConcepts,
      recommended,
    });
  } catch (err) { next(err); }
});

/**
 * Student submits context/explanation for an integrity flag.
 * POST /api/student/integrity-flags/:id/respond
 */
router.post('/integrity-flags/:id/respond', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const { id } = req.params;
    const { response } = req.body;
    const studentId = req.user.id;

    if (!response || typeof response !== 'string' || response.trim().length === 0) {
      return res.status(400).json({ error: 'Response text is required' });
    }
    if (response.length > 2000) {
      return res.status(400).json({ error: 'Response must be under 2000 characters' });
    }

    const flagRes = await db.query(
      'SELECT id, student_id, status FROM integrity_flags WHERE id = $1',
      [id]
    );
    if (flagRes.rows.length === 0) {
      return res.status(404).json({ error: 'Flag not found' });
    }
    const flag = flagRes.rows[0];
    if (flag.student_id !== studentId) {
      return res.status(403).json({ error: 'Not your flag' });
    }
    if (flag.status !== 'flagged') {
      return res.status(400).json({ error: 'Flag has already been reviewed' });
    }

    await db.query(
      `UPDATE integrity_flags
       SET student_response = $1, student_responded_at = NOW()
       WHERE id = $2`,
      [response.trim(), id]
    );

    res.json({ message: 'Response submitted successfully' });
  } catch (err) {
    console.error('Error submitting flag response:', err);
    res.status(500).json({ error: 'Failed to submit response' });
  }
});

// Get student's own integrity flags
router.get('/integrity-flags', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const studentId = req.user.id;

    // Stats
    const statsRes = await db.query(`
      SELECT
        COUNT(*) AS total,
        COUNT(*) FILTER (WHERE status = 'flagged') AS flagged,
        COUNT(*) FILTER (WHERE status IN ('reviewed', 'dismissed')) AS reviewed
      FROM integrity_flags WHERE student_id = $1
    `, [studentId]);

    const byTypeRes = await db.query(`
      SELECT flag_type, COUNT(*) AS count
      FROM integrity_flags WHERE student_id = $1
      GROUP BY flag_type
    `, [studentId]);

    const cdsRes = await db.query(`
      SELECT
        ROUND(AVG(cds)::numeric, 2) AS avg_cds,
        MAX(cds) AS max_cds
      FROM cds_scores WHERE student_id = $1 AND cds IS NOT NULL AND visible = true
    `, [studentId]);

    const latestCdsRes = await db.query(`
      SELECT classification FROM cds_scores
      WHERE student_id = $1 AND cds IS NOT NULL AND visible = true
      ORDER BY computed_at DESC LIMIT 1
    `, [studentId]);

    const totalCount = parseInt(statsRes.rows[0]?.total || 0, 10);
    const flaggedCount = parseInt(statsRes.rows[0]?.flagged || 0, 10);
    const reviewedCount = parseInt(statsRes.rows[0]?.reviewed || 0, 10);

    const byType = {};
    for (const row of byTypeRes.rows) {
      byType[row.flag_type] = parseInt(row.count, 10);
    }

    const avgCds = cdsRes.rows[0]?.avg_cds ? parseFloat(cdsRes.rows[0].avg_cds) : null;
    const maxCds = cdsRes.rows[0]?.max_cds ? parseFloat(cdsRes.rows[0].max_cds) : null;
    const latestClassification = latestCdsRes.rows[0]?.classification || null;

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
        evidence: evidence !== null && typeof evidence === 'object' && !Array.isArray(evidence) ? JSON.stringify(evidence) : Array.isArray(evidence) ? evidence.join('. ') : String(evidence || ''),
        date: row.created_at,
      };
    });
    res.json({
      flags,
      stats: {
        totalFlags: totalCount,
        flaggedCount,
        reviewedCount,
        byType,
      },
      cdsSummary: {
        averageCds: avgCds,
        highestCds: maxCds,
        recentClassification: latestClassification,
      },
    });
  } catch (err) { next(err); }
});

// ── Passive Behavioral Logging (paper flag #5) ──────────────────────────────
// Receives browser-side telemetry: tab switches, paste events, idle time.
// Stores in behavioral_events table for instructor context.

router.post('/behavioral-events', behavioralLimiter, verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const studentId = req.user.id;
    const { exerciseId, events } = req.body;

    if (!exerciseId || !Array.isArray(events) || events.length === 0) {
      return res.status(400).json({ error: 'exerciseId and events array required' });
    }

    // Batch insert events (max 50 per request to prevent abuse)
    const toInsert = events.slice(0, 50);
    for (const event of toInsert) {
      const { type, timestamp, payload } = event;
      if (!type || !['tab_switch', 'paste', 'idle_start', 'idle_end'].includes(type)) continue;

      await db.query(
        `INSERT INTO behavioral_events (student_id, exercise_id, event_type, occurred_at, payload)
         VALUES ($1, $2, $3, $4, $5)`,
        [studentId, exerciseId, type, timestamp || new Date(), JSON.stringify(payload || {})]
      );
    }

    // Also update the submission's tab_switch_count and paste_count
    // Find the latest submission for this student+exercise
    const latestSub = await db.query(
      `SELECT id FROM submissions
       WHERE student_id = $1 AND exercise_id = $2
       ORDER BY attempt_number DESC LIMIT 1`,
      [studentId, exerciseId]
    );

    if (latestSub.rows.length > 0) {
      const subId = latestSub.rows[0].id;
      const tabSwitches = toInsert.filter(e => e.type === 'tab_switch').length;
      const pastes = toInsert.filter(e => e.type === 'paste').length;

      if (tabSwitches > 0 || pastes > 0) {
        await db.query(
          `UPDATE submissions
           SET tab_switch_count = tab_switch_count + $1,
               paste_count = paste_count + $2
           WHERE id = $3`,
          [tabSwitches, pastes, subId]
        );
      }
    }

    res.json({ received: toInsert.length });
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
    // Uses exercise_concept_tags (primary) with fallback to ex.concept_id for missing tags
    const conceptCdsRes = await db.query(`
      SELECT COALESCE(pt.name, c.name) AS concept_name,
             AVG(cs.cds)::float AS avg_cds,
             COUNT(cs.cds)::int AS completed_count
      FROM cds_scores cs
      JOIN exercises ex ON ex.id = cs.exercise_id
      JOIN concepts c ON c.id = ex.concept_id
      LEFT JOIN exercise_concept_tags ect ON ect.exercise_id = ex.id AND ect.is_primary = true
      LEFT JOIN concepts pt ON pt.id = ect.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id AND en.student_id = cs.student_id
      WHERE cs.student_id = $1 AND cs.cds IS NOT NULL
      GROUP BY COALESCE(pt.name, c.name)
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
      trend: c.avgCds <= 0.40 ? 'up' : c.avgCds <= 0.60 ? 'flat' : 'down',
    }));

    // 4. Focus: pick the pending exercise with the highest concept CDS (hardest next)
    const focusEx = pending
      .map(ex => ({
        ...ex,
        conceptCds: conceptMap[ex.concept_name]?.avgCds ?? 0,
      }))
      .sort((a, b) => b.conceptCds - a.conceptCds)[0] || null;

    // 5. Class avg on the focus concept
    // Uses exercise_concept_tags (primary) with fallback to ex.concept_id for missing tags
    let classAvg = 0.5; // default
    if (focusEx) {
      const classRes = await db.query(`
        SELECT AVG(cs.cds)::float AS class_avg
        FROM cds_scores cs
        JOIN exercises ex ON ex.id = cs.exercise_id
        JOIN concepts c ON c.id = ex.concept_id
        LEFT JOIN exercise_concept_tags ect ON ect.exercise_id = ex.id AND ect.is_primary = true
        LEFT JOIN concepts pt ON pt.id = ect.concept_id
        JOIN enrollments en ON en.section_id = ex.section_id
        WHERE COALESCE(pt.name, c.name) = $1 AND en.student_id = cs.student_id
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
      if (strongest.avgCds <= 0.40) {
        signals.push(`You have strong performance on ${strongest.concept_name} — consider advancing to harder exercises.`);
      }
      if (weakest.avgCds >= 0.60) {
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
      FROM submissions s
      JOIN exercises ex ON s.exercise_id = ex.id
      JOIN enrollments en ON en.section_id = ex.section_id
      WHERE s.student_id = $1 AND s.is_correct = true
        AND en.student_id = $1
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

    // 1. Concept mastery — CDS aggregated by concept (scoped to current enrollments)
    // Uses exercise_concept_tags (primary) with fallback to ex.concept_id for missing tags
    const conceptCdsRes = await db.query(`
      SELECT COALESCE(pt.name, c.name) AS concept_name,
             AVG(cs.cds)::float AS avg_cds,
             COUNT(cs.cds)::int AS exercise_count
      FROM cds_scores cs
      JOIN exercises ex ON ex.id = cs.exercise_id
      JOIN concepts c ON c.id = ex.concept_id
      LEFT JOIN exercise_concept_tags ect ON ect.exercise_id = ex.id AND ect.is_primary = true
      LEFT JOIN concepts pt ON pt.id = ect.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id AND en.student_id = cs.student_id
      WHERE cs.student_id = $1 AND cs.cds IS NOT NULL
      GROUP BY COALESCE(pt.name, c.name)
      ORDER BY avg_cds ASC
    `, [studentId]);

    const conceptCodes = {
      Loops: 'LP', Arrays: 'AR', Functions: 'FN', Pointers: 'PT',
      OOP: 'OP', Variables: 'VR', Datatypes: 'DT', Conditionals: 'CD',
    };
    const masteryConcepts = conceptCdsRes.rows.map(r => {
      // Default to 1 when no CDS scores exist (conservative: unknown = needs practice)
      const avgCds = r.avg_cds != null ? parseFloat(r.avg_cds) : 1;
      const masteryPct = Math.round((1 - avgCds) * 100);
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
        cds: Math.round(avgCds * 100) / 100,
        exerciseCount: r.exercise_count,
        level,
        delta: 0,
      };
    });

    // 2a. Trajectory analysis — smart, deterministic, handles edge cases
    const trajectory = (() => {
      // ── Empty state (no concepts at all) ────────────────────────
      if (masteryConcepts.length === 0) {
        return {
          message: 'Complete an exercise to get your first concept assessment.',
          tone: 'neutral',
          actionLabel: 'Start exercising',
          actionTo: '/student/exercises',
          detail: null,
        };
      }

      // ── Group: all concepts at 100% mastery ─────────────────────
      const allAtMax = masteryConcepts.every(c => c.mastery >= 100);
      if (allAtMax) {
        return {
          message: 'You have mastered every concept! Outstanding work.',
          tone: 'celebratory',
          actionLabel: 'Review exercises',
          actionTo: '/student/exercises',
          detail: `Difficulty scores: ${masteryConcepts.map(c => `${c.concept_name} ${c.cds.toFixed(2)}`).join(' · ')}`,
        };
      }

      // ── Sort: weakest first, stable sort ────────────────────────
      const sorted = [...masteryConcepts].sort((a, b) => a.mastery - b.mastery);
      const weakest = sorted[0];
      const secondWeakest = sorted[1] || null;
      const gap = secondWeakest ? secondWeakest.mastery - weakest.mastery : 0;

      // ── Single concept only ─────────────────────────────────────
      if (masteryConcepts.length === 1) {
        const msg = weakest.mastery >= 85
          ? `Your progress on ${weakest.concept_name} is strong at ${weakest.mastery}%.`
          : `Keep practicing ${weakest.concept_name} — you're at ${weakest.mastery}% mastery.`;
        return {
          message: msg,
          tone: weakest.mastery >= 85 ? 'positive' : 'constructive',
          actionLabel: `Practice ${weakest.concept_name}`,
          actionTo: '/student/exercises',
          detail: `Difficulty score: ${weakest.cds.toFixed(2)} · ${weakest.exerciseCount} exercise${weakest.exerciseCount !== 1 ? 's' : ''}`,
        };
      }

      // ── Multiple concepts: tier the message by gap + mastery ────
      const isTightRace = gap < 5;
      const isNearlyMastered = weakest.mastery >= 85;

      let message;
      let tone;
      let actionLabel;
      let detailBase;

      if (isNearlyMastered) {
        message = `Strong overall progress. ${weakest.concept_name} is your lowest at ${weakest.mastery}% — slight room to grow.`;
        tone = 'positive';
        actionLabel = `Practice ${weakest.concept_name}`;
        detailBase = `Difficulty score: ${weakest.cds.toFixed(2)}`;
      } else if (isTightRace) {
        const focusAreas = sorted.filter(c => c.mastery <= sorted[0].mastery + 4).map(c => c.concept_name);
        message = `Focus areas: ${focusAreas.join(', ')}. Strongest concept: ${sorted[sorted.length - 1].concept_name} at ${sorted[sorted.length - 1].mastery}%.`;
        tone = 'constructive';
        actionLabel = 'Practice focus area';
        actionTo = '/student/exercises';
        detailBase = `${weakest.concept_name} difficulty: ${weakest.cds.toFixed(2)} · gap to next: ${gap.toFixed(0)}pp`;
      } else {
        message = `${weakest.concept_name} needs attention at ${weakest.mastery}% mastery. Your overall mastery is ${overallMastery}%.`;
        tone = 'constructive';
        actionLabel = `Practice ${weakest.concept_name}`;
        detailBase = `Difficulty score: ${weakest.cds.toFixed(2)} · gap to next: ${gap.toFixed(0)}pp`;
      }

      return {
        message,
        tone,
        actionLabel: actionLabel || `Practice ${weakest.concept_name}`,
        actionTo: actionTo || '/student/exercises',
        detail: `${detailBase} · Trends: ${sorted.filter(c => (c.delta ?? 0) > 0).length} improving, ${sorted.filter(c => (c.delta ?? 0) < 0).length} declining`,
      };
    })();

    // 2b. Exercise completion percentage (activity, not mastery)
    const completionRes = await db.query(`
      SELECT COUNT(DISTINCT ex.id)::int AS total,
             (SELECT COUNT(DISTINCT s.exercise_id)::int
              FROM submissions s
              JOIN exercises ex2 ON s.exercise_id = ex2.id
              JOIN enrollments en2 ON en2.section_id = ex2.section_id
              WHERE s.student_id = $1 AND s.is_correct = true
                 AND en2.student_id = $1
             ) AS completed
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

    // 4. Avg attempts per exercise
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
      avgAttempts: Math.round(avgAttempts * 10) / 10,
      concepts: masteryConcepts,
      trajectory,
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

// Student-facing concept mastery endpoint for mobile UI
// Returns concepts in format: [{ code, name, mastery: 0..1 }]
router.get('/concepts/all', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const studentId = req.user.id;

    const conceptCdsRes = await db.query(`
      SELECT COALESCE(pt.name, c.name) AS concept_name,
             AVG(cs.cds)::float AS avg_cds,
             COUNT(cs.cds)::int AS exercise_count
      FROM cds_scores cs
      JOIN exercises ex ON ex.id = cs.exercise_id
      JOIN concepts c ON c.id = ex.concept_id
      LEFT JOIN exercise_concept_tags ect ON ect.exercise_id = ex.id AND ect.is_primary = true
      LEFT JOIN concepts pt ON pt.id = ect.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id AND en.student_id = cs.student_id
      WHERE cs.student_id = $1 AND cs.cds IS NOT NULL
      GROUP BY COALESCE(pt.name, c.name)
      ORDER BY avg_cds ASC
    `, [studentId]);

    const conceptCodes = {
      Loops: 'LP', Arrays: 'AR', Functions: 'FN', Pointers: 'PT',
      OOP: 'OP', Variables: 'VR', Datatypes: 'DT', Conditionals: 'CD',
      Strings: 'ST', 'Input/Output': 'IO',
    };

    const concepts = conceptCdsRes.rows.map(r => {
      // Default to 1 when no CDS scores exist (conservative: unknown = needs practice)
      const avgCds = r.avg_cds != null ? parseFloat(r.avg_cds) : 1;
      const masteryPct = Math.round((1 - avgCds) * 100);
      const mastery = masteryPct / 100;
      const code = conceptCodes[r.concept_name] || r.concept_name.substring(0, 2).toUpperCase();
      return {
        code,
        name: r.concept_name,
        mastery,
      };
    });

    res.json(concepts);
  } catch (err) { next(err); }
});

module.exports = router;
