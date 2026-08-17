const express = require('express');
const router  = express.Router();
const db = require('../config/db');
const { runAgainstTestCases, isHiddenTestCase } = require('../services/executor');
const cdsEngine = require('../services/cdsEngine');
const academicIntegrityEngine = require('../services/academicIntegrityEngine');
const integrityFlagEngine = require('../services/integrityFlagEngine');
const { evaluateCodeGrowthAnomaly, CODE_GROWTH_ANOMALY_CONFIG } = require('../services/codeGrowthAnomaly');
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
    // Optional ?sectionId=<id> narrows results to a single active enrollment.
    const sectionId = req.query.sectionId ? parseInt(req.query.sectionId, 10) : null;
    const params = [req.user.id];
    let sectionFilter = '';
    if (sectionId) {
      params.push(sectionId);
      sectionFilter = ` AND ex.section_id = $${params.length}`;
    }
    // Completion status is derived from a correct submission, not from CDS
    // (CDS rows exist even for students with no accepted solution).
    const r = await db.query(`
      SELECT ex.id, ex.title, ex.description, c.name AS concept_name,
             ex.time_limit_minutes, ex.deadline, ex.closed_at, ex.test_cases,
             CASE WHEN s.submitted_at IS NOT NULL THEN 'completed' ELSE 'pending' END AS status,
             (s.submitted_at IS NOT NULL) AS "isCompleted",
             CASE
               WHEN s.submitted_at IS NOT NULL AND (ex.deadline IS NULL OR s.submitted_at <= ex.deadline) THEN 'done'
               WHEN s.submitted_at IS NOT NULL AND ex.deadline IS NOT NULL AND s.submitted_at > ex.deadline THEN 'late'
               WHEN s.submitted_at IS NULL AND ex.deadline IS NOT NULL AND ex.deadline < NOW() THEN 'missing'
               ELSE 'todo'
             END AS work_status,
             (ex.closed_at IS NOT NULL) AS "isClosed",
             cs.cds
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id
      LEFT JOIN LATERAL (
        SELECT MIN(submitted_at) AS submitted_at
        FROM submissions
        WHERE exercise_id = ex.id AND student_id = $1 AND is_correct = true
      ) s ON true
      LEFT JOIN cds_scores cs ON cs.exercise_id = ex.id AND cs.student_id = $1 AND cs.section_id = ex.section_id
      WHERE en.student_id = $1 AND en.dropped_at IS NULL AND ex.is_draft = false${sectionFilter}
      ORDER BY ex.created_at DESC
    `, params);
    res.json(r.rows);
  } catch (err) { next(err); }
});

// Get single exercise details
router.get('/exercises/:id', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const sectionId = req.query.sectionId ? parseInt(req.query.sectionId, 10) : null;

    const exRes = await db.query(`
      SELECT ex.*, c.name AS concept_name
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      WHERE ex.id = $1
    `, [req.params.id]);
    if (!exRes.rows.length) throw new AppError('Exercise not found', 404, codes.NOT_FOUND);

    // Optional sectionId must match the exercise's section; otherwise the
    // request is for a section the student is not (actively) in.
    if (sectionId && sectionId !== exRes.rows[0].section_id) {
      throw new AppError('You are not enrolled in this section', 403, codes.FORBIDDEN);
    }

    const enrollRes = await db.query(
      'SELECT 1 FROM enrollments WHERE student_id=$1 AND section_id=$2 AND dropped_at IS NULL',
      [req.user.id, exRes.rows[0].section_id]
    );
    if (!enrollRes.rows.length) {
      throw new AppError('You are not enrolled in this section', 403, codes.FORBIDDEN);
    }

    const ex = exRes.rows[0];
    if (ex.test_cases) {
      let testCases = typeof ex.test_cases === 'string' ? JSON.parse(ex.test_cases) : ex.test_cases;
      ex.test_cases = testCases.filter(tc => !isHiddenTestCase(tc));
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

    // Per-run behavioral snapshot (sent by the client along with the code)
    const tabSwitchCount   = Math.max(0, parseInt(req.body.tabSwitchCount, 10) || 0);
    const pasteCount       = Math.max(0, parseInt(req.body.pasteCount, 10) || 0);
    const timeSpentSeconds = Math.max(0, parseInt(req.body.timeSpentSeconds, 10) || 0);
    const lineCount        = Math.max(0, parseInt(req.body.lineCount, 10) || code.split('\n').length);

    const exRes = await db.query(`
      SELECT ex.*, c.name AS concept_name
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      WHERE ex.id = $1
    `, [req.params.id]);
    if (!exRes.rows.length) throw new AppError('Exercise not found', 404, codes.NOT_FOUND);

    const exercise = exRes.rows[0];

    // Gate: only actively enrolled students may run an exercise. A student
    // who left the section (dropped_at set) is rejected with 403.
    const sectionId = req.query.sectionId ? parseInt(req.query.sectionId, 10) : null;
    if (sectionId && sectionId !== exercise.section_id) {
      throw new AppError('You are not enrolled in this section', 403, codes.FORBIDDEN);
    }
    const enrollRes = await db.query(
      'SELECT 1 FROM enrollments WHERE student_id=$1 AND section_id=$2 AND dropped_at IS NULL',
      [req.user.id, exercise.section_id]
    );
    if (!enrollRes.rows.length) {
      throw new AppError('You are not enrolled in this section', 403, codes.FORBIDDEN);
    }

    const testCases = typeof exercise.test_cases === 'string'
      ? JSON.parse(exercise.test_cases) : (exercise.test_cases || []);
    const visibleTC = testCases.filter(tc => !isHiddenTestCase(tc));

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
      failed: hiddenResults.filter(r => !r.passed).length,
    };

    // ── Run snapshot (run_attempts) ──────────────────────────────────────
    // Persist a per-run record with behavioral + growth metadata so the
    // submit-time aggregation and integrity checks have run-level data.
    const errorCount = results.filter(r =>
      r.status === 'Compile Error' || r.status === 'Runtime Error' || r.status === 'Execution Error'
    ).length;
    const timeLimitHit = results.some(r => r.status === 'Time Limit Exceeded');

    const prevRunRes = await db.query(
      `SELECT line_count FROM run_attempts
       WHERE student_id = $1 AND exercise_id = $2
       ORDER BY run_at DESC, id DESC
       LIMIT 1`,
      [req.user.id, exercise.id]
    );
    const prevLineCount = prevRunRes.rows[0]?.line_count || 0;
    const codeGrowthDelta = prevRunRes.rows.length > 0 ? lineCount - prevLineCount : 0;

    const runInsert = await db.query(
      `INSERT INTO run_attempts
       (student_id, exercise_id, code, compiler_log, error_count, time_limit_hit, run_at,
        tab_switch_count, paste_count, time_spent_seconds, line_count, code_growth_delta)
       VALUES ($1, $2, $3, $4, $5, $6, NOW(), $7, $8, $9, $10, $11)
       RETURNING id`,
      [req.user.id, exercise.id, code, compilerError, errorCount, timeLimitHit,
       tabSwitchCount, pasteCount, timeSpentSeconds, lineCount, codeGrowthDelta]
    );
    const runId = runInsert.rows[0].id;

    // Background per-run integrity checkpoint (paste/tab, hardcoding, blank)
    defer(async () => {
      try {
        const { evaluateRunCheckpoint } = require('../services/runCheckpoint');
        await evaluateRunCheckpoint({
          runId,
          studentId: req.user.id,
          exerciseId: exercise.id,
          sectionId: exercise.section_id,
          code,
          starterCode: exercise.starter_code || '',
          exercise,
          tabSwitchCount,
          pasteCount,
          timeSpentSeconds,
        });
      } catch (checkErr) {
        logger.warn({ err: checkErr }, 'Run checkpoint evaluation failed');
      }
    });

    res.json({
      passed: results.every(r => r.passed),
      testResults: visibleResults,
      hidden: hiddenSummary,
      compilerError,
      microConceptFeedback: null,
      runId,
      integrityFlags: [],
    });
  } catch (err) { next(err); }
});

// Submit code (all tests, save submission, persist behavioral events)
router.post('/exercises/:id/submit', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const { code, timeSpentSeconds, tabSwitchCount = 0, pasteCount = 0 } = req.body;
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

    // Gate: only actively enrolled students may submit. A student who left
    // the section (dropped_at set) is rejected with 403.
    const sectionId = req.query.sectionId ? parseInt(req.query.sectionId, 10) : null;
    if (sectionId && sectionId !== exercise.section_id) {
      throw new AppError('You are not enrolled in this section', 403, codes.FORBIDDEN);
    }

    // Gate: closed exercises are frozen. CDS was computed at close time and
    // must not be mutated by post-close submissions — matches the instructor
    // submit paths (submissionController / submissionWorker).
    if (exercise.closed_at) {
      throw new AppError(
        'This exercise is closed — submissions are no longer accepted. If you need an extension, please contact your instructor.',
        403,
        codes.FORBIDDEN
      );
    }
    const enrollRes = await db.query(
      'SELECT 1 FROM enrollments WHERE student_id=$1 AND section_id=$2 AND dropped_at IS NULL',
      [req.user.id, exercise.section_id]
    );
    if (!enrollRes.rows.length) {
      throw new AppError('You are not enrolled in this section', 403, codes.FORBIDDEN);
    }

    // Resolve required AST nodes for structure verification.
    // Per-exercise requirements (exercise.ast_nodes) are strict — all must be
    // present. When the exercise declares none, fall back to the concept's
    // ast_nodes, which are alternatives ("any of").
    const exerciseNodes = Array.isArray(exercise.ast_nodes) ? exercise.ast_nodes : [];
    let requiredNodes = exerciseNodes;
    let anyOf = false;
    if (!requiredNodes.length) {
      const conceptRes = await db.query('SELECT ast_nodes FROM concepts WHERE id = $1', [exercise.concept_id]);
      const conceptNodes = conceptRes.rows[0]?.ast_nodes || [];
      requiredNodes = conceptNodes;
      anyOf = true; // concept lists are alternative ("any of") lists
    }
    const requiredPatterns = Array.isArray(exercise.required_patterns) ? exercise.required_patterns : [];

    const allTestCases = typeof exercise.test_cases === 'string'
      ? JSON.parse(exercise.test_cases) : (exercise.test_cases || []);
    // Support both new isVisible and legacy hidden/is_hidden fields
    const visibleTestCases = allTestCases.filter(tc => !isHiddenTestCase(tc));

    let allResults = [];
    let visibleResults = [];
    let passed = false;
    let allTestsPassed = false;
    let compilerError = null;

    try {
      allResults = await runWithLimit(() => runAgainstTestCases(code, allTestCases, exercise.time_limit_minutes * 60, false), 'compile');
      const compileErrorResult = allResults.find(r => r.status === 'Compile Error');
      if (compileErrorResult) compilerError = compileErrorResult.error;
      allTestsPassed = allResults.every(r => r.passed);
      visibleResults = allResults.filter(r => !r.hidden);
    } catch (execErr) {
      compilerError = execErr.message;
      visibleResults = [{
        input: 'N/A', expected: 'N/A', actual: '', passed: false,
        status: 'Execution Error', error: execErr.message, hidden: false,
      }];
    }

    const hiddenResults = allResults.filter(r => r.hidden);
    const hiddenSummary = {
      count: hiddenResults.length,
      passed: hiddenResults.length ? hiddenResults.every(r => r.passed) : true,
      failed: hiddenResults.filter(r => !r.passed).length,
    };

    // ── AST Structure Verification ──────────────────────────────────────
    const astVerifier = require('../services/astVerifier');
    const verifyRes = await astVerifier.verify(
      code,
      { required_nodes: requiredNodes, any_of: anyOf, required_patterns: requiredPatterns },
      { starter_code: exercise.starter_code, concept_name: exercise.concept_name }
    );
    const is_verified = !!verifyRes.is_verified;
    const verificationNote = (verifyRes.reasons || []).map(r => r.message).join('; ');

    // A submission must both pass all tests AND satisfy the required
    // structure. Verification failures still save the attempt (recorded as
    // is_correct = false, is_verified = false) but do not complete the
    // exercise and are excluded from CDS.
    passed = allTestsPassed && is_verified;

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
        required_ast_nodes: exerciseNodes,
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
      'SELECT COALESCE(MAX(attempt_number), 0) + 1 AS next FROM submissions WHERE exercise_id = $1 AND student_id = $2',
      [req.params.id, req.user.id]
    );
    const attempt_number = attemptRes.rows[0].next;

    // Session totals: aggregate per-run behavioral snapshots captured at /run
    // time since the previous submission (or all runs for the first attempt).
    // These feed the submission's tab_switch_count / paste_count.
    const sessionTotalsRes = await db.query(
      `WITH prev_sub AS (
         SELECT COALESCE(MAX(submitted_at), '1970-01-01') AS cutoff
         FROM submissions
         WHERE student_id = $1 AND exercise_id = $2
       )
       SELECT COALESCE(SUM(ra.tab_switch_count), 0)::int   AS tab_switches,
              COALESCE(SUM(ra.paste_count), 0)::int        AS pastes,
              COALESCE(SUM(ra.time_spent_seconds), 0)::int AS run_time_seconds
       FROM run_attempts ra
       CROSS JOIN prev_sub ps
       WHERE ra.student_id = $1 AND ra.exercise_id = $2 AND ra.run_at > ps.cutoff`,
      [req.user.id, exercise.id]
    );
    const sessionTabSwitches = sessionTotalsRes.rows[0]?.tab_switches || 0;
    const sessionPastes      = sessionTotalsRes.rows[0]?.pastes || 0;

    const subRes = await db.query(`
      INSERT INTO submissions
        (exercise_id, student_id, code, test_results, is_correct, is_verified, verification_note,
         attempt_number, time_spent_seconds, tab_switch_count, paste_count, submitted_at)
      VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, NOW())
      RETURNING id, exercise_id, student_id, is_correct, attempt_number, submitted_at, time_spent_seconds
    `, [exercise.id, req.user.id, code, JSON.stringify(allResults), passed, is_verified, verificationNote,
        attempt_number, timeSpentSeconds || 0, sessionTabSwitches, sessionPastes]);

    // Log verification failures into verification_logs for instructor review
    if (!is_verified) {
      await db.query(
        `INSERT INTO verification_logs (submission_id, student_id, exercise_id, verification_type, reason)
         VALUES ($1, $2, $3, $4, $5)`,
        [subRes.rows[0].id, req.user.id, exercise.id, 'ast_verifier', verificationNote || 'Verification failed']
      );
    }

    // Send response immediately — student sees test results right away
    res.status(201).json({
      ...subRes.rows[0],
      passed: subRes.rows[0].is_correct,
      testResults: visibleResults,
      compilerError,
      hidden: hiddenSummary,
      hiddenTestCount: hiddenSummary.count,
      liveCDS: null,
      isCompleted: subRes.rows[0].is_correct,
      verification: { passed: is_verified, reasons: verifyRes.reasons || [] },
      microConceptFeedback,
      message: 'Submission saved successfully',
    });

    // ── Deferred post-processing (CDS, flags, checks run in background) ─
    defer(async () => {

      // Frozen-CDS protection: if the exercise was closed between the request
      // and this deferred run (e.g. auto-close fired mid-flight), do NOT write
      // a live CDS row — the frozen batch score must stay authoritative.
      const frozenCheck = await db.query('SELECT closed_at FROM exercises WHERE id=$1', [exercise.id]);
      if (frozenCheck.rows.length && frozenCheck.rows[0].closed_at) return;

      let liveCDS = null;
      try {
        liveCDS = await cdsEngine.calculateLiveCDS(req.user.id, exercise.id, db);
        if (liveCDS && liveCDS.cds !== null) {
          await db.query(`
            INSERT INTO cds_scores (student_id, exercise_id, section_id, ner, nrs, nts, cds, classification, has_flagged_attempts, integrity_flag_count, source, visible, computed_at)
            VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, 'live', false, NOW())
            ON CONFLICT (student_id, exercise_id)
            DO UPDATE SET ner=$4, nrs=$5, nts=$6, cds=$7, classification=$8, has_flagged_attempts=$9, integrity_flag_count=$10, source='live', visible=false, computed_at=cds_scores.computed_at
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

      // ── Contextual Activity Flag ───────────────────────────────────────
      const BEHAVIORAL_THRESHOLDS = {
        TAB_SWITCH_HIGH: 5,
        PASTE_HIGH: 3,
      };
      const totalTime = timeSpentSeconds || 1;
      const behavioralSignals = [];
      // Use the session totals aggregated from per-run snapshots so the flag
      // evidence matches the submission's stored tab_switch_count / paste_count.
      if (sessionTabSwitches >= BEHAVIORAL_THRESHOLDS.TAB_SWITCH_HIGH) {
        behavioralSignals.push(`${sessionTabSwitches} tab switches`);
      }
      if (sessionPastes >= BEHAVIORAL_THRESHOLDS.PASTE_HIGH) {
        behavioralSignals.push(`${sessionPastes} paste events`);
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
              tab_switch_count: sessionTabSwitches,
              paste_count: sessionPastes,
              total_time_seconds: totalTime,
            }),
            [
              behavioralSignals.join('; '),
              `Attempt #${attempt_number}, time: ${totalTime}s`,
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
            const growthResult = evaluateCodeGrowthAnomaly({
              baselineLines: prevLineCount,
              studentLines: currentLineCount,
              attemptNumber: attempt_number,
            });
            if (growthResult.flagged) {
              await integrityFlagEngine.createFlag({
                sectionId: exercise.section_id,
                exerciseId: exercise.id,
                studentId: req.user.id,
                flagType: 'CODE_GROWTH_ANOMALY',
                severity: growthResult.severity,
                evidence: {
                  baseline_lines: prevLineCount,
                  student_lines: currentLineCount,
                  growth_percent: growthResult.growthPercent,
                  threshold: CODE_GROWTH_ANOMALY_CONFIG.PCT_THRESHOLD,
                  attempt_number,
                  lines_added: growthResult.linesAdded,
                  min_lines_added: CODE_GROWTH_ANOMALY_CONFIG.MIN_LINES_ADDED,
                  floor_met: growthResult.floorMet,
                  severity_basis: growthResult.severityBasis,
                  baseline_source: growthResult.baselineSource,
                },
                contextBehaviors: [
                  `Code grew ${growthResult.growthPercent}% in attempt #${attempt_number} (${prevLineCount} → ${currentLineCount} lines)`,
                ],
                status: 'flagged',
                submissionId: subRes.rows[0].id,
              });
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

      // ── Finalize run-checkpoint flags with this submission ──────────────
      // Flags captured at /run time have run_id set but submission_id NULL;
      // back-fill them now that the submission exists.
      try {
        await db.query(
          `UPDATE integrity_flags
           SET submission_id = $1
           WHERE exercise_id = $2 AND student_id = $3
             AND run_id IS NOT NULL AND submission_id IS NULL`,
          [subRes.rows[0].id, exercise.id, req.user.id]
        );
      } catch (finalizeErr) {
        logger.warn({ err: finalizeErr }, 'Finalize run flags failed');
      }

      // ── Self-heal: backfill flags for runs without any checkpoint flag ──
      try {
        const { evaluateRunCheckpoint } = require('../services/runCheckpoint');
        const orphanRuns = await db.query(
          `SELECT ra.id AS run_id, ra.code,
                  ra.tab_switch_count, ra.paste_count, ra.time_spent_seconds
           FROM run_attempts ra
           WHERE ra.student_id = $1 AND ra.exercise_id = $2
             AND NOT EXISTS (
               SELECT 1 FROM integrity_flags if2 WHERE if2.run_id = ra.id
             )
           ORDER BY ra.run_at ASC`,
          [req.user.id, exercise.id]
        );
        for (const run of orphanRuns.rows) {
          await evaluateRunCheckpoint({
            runId: run.run_id,
            studentId: req.user.id,
            exerciseId: exercise.id,
            sectionId: exercise.section_id,
            code: run.code,
            starterCode: exercise.starter_code || '',
            exercise,
            tabSwitchCount: run.tab_switch_count || 0,
            pasteCount: run.paste_count || 0,
            timeSpentSeconds: run.time_spent_seconds || 0,
          });
        }
      } catch (healErr) {
        logger.warn({ err: healErr }, 'Run flag self-heal failed');
      }

    });
  } catch (err) { next(err); }
});

// ▶ PRACTICE — save attempt without impacting CDS analytics (post-completion)


router.get('/exercises/:id/attempts', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const sectionId = req.query.sectionId ? parseInt(req.query.sectionId, 10) : null;
    const params = [req.params.id, req.user.id];
    let sectionFilter = '';
    if (sectionId) {
      params.push(sectionId);
      sectionFilter = ` AND ex.section_id = $${params.length}`;
    }
    // Only return attempts for exercises the student is actively enrolled in.
    const r = await db.query(`
      SELECT sub.id, sub.exercise_id, sub.is_correct AS passed, sub.attempt_number, sub.submitted_at, sub.test_results
      FROM submissions sub
      JOIN exercises ex ON ex.id = sub.exercise_id
      JOIN enrollments en ON en.section_id = ex.section_id AND en.student_id = sub.student_id
      WHERE sub.exercise_id = $1 AND sub.student_id = $2 AND en.dropped_at IS NULL${sectionFilter}
      ORDER BY sub.submitted_at DESC LIMIT 10
    `, params);
    const rows = (r.rows || []).map(row => {
      let results = row.test_results;
      try {
        results = typeof results === 'string' ? JSON.parse(results) : results;
      } catch (_) { results = null; }
      return {
        ...row,
        passed_count: Array.isArray(results) ? results.filter(t => t && t.passed === true).length : null,
        total_count: Array.isArray(results) ? results.length : null,
      };
    });
    res.json(rows);
  } catch (err) { next(err); }
});

router.get('/dashboard', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const studentId = req.user.id;
    const sectionId = req.query.sectionId ? parseInt(req.query.sectionId, 10) : null;
    const params = [studentId];
    let sectionFilter = '';
    if (sectionId) {
      params.push(sectionId);
      sectionFilter = ` AND ex.section_id = $${params.length}`;
    }

    // 1. Exercises — find due-soon count, nearest deadline, and all for recommendations
    // Completion status derives from a correct submission (not CDS rows).
    const exercisesRes = await db.query(`
      SELECT ex.id, ex.title, ex.description, c.name AS concept_name,
             ex.time_limit_minutes, ex.deadline,
             CASE WHEN s.id IS NOT NULL THEN 'completed' ELSE 'pending' END AS status,
             (s.id IS NOT NULL) AS "isCompleted",
             cs.cds, cs.classification
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id
      LEFT JOIN LATERAL (
        SELECT id FROM submissions
        WHERE exercise_id = ex.id AND student_id = $1 AND is_correct = true
        LIMIT 1
      ) s ON true
      LEFT JOIN cds_scores cs ON cs.exercise_id = ex.id AND cs.student_id = $1 AND cs.section_id = ex.section_id
      WHERE en.student_id = $1 AND en.dropped_at IS NULL AND ex.is_draft = false${sectionFilter}
      ORDER BY ex.deadline ASC NULLS LAST
    `, params);

    const allExercises = exercisesRes.rows || [];
    const pendingExercises = allExercises.filter(ex => ex.status === 'pending');
    const dueSoonThreshold = new Date(Date.now() + 7 * 24 * 60 * 60 * 1000); // 7 days
    const dueCount = pendingExercises.filter(ex => ex.deadline && new Date(ex.deadline) <= dueSoonThreshold).length;
    const overdueCount = pendingExercises.filter(ex => ex.deadline && new Date(ex.deadline) < new Date()).length;

    // Nearest deadline exercise
    const nearestDeadline = pendingExercises
      .filter(ex => ex.deadline)
      .sort((a, b) => new Date(a.deadline) - new Date(b.deadline))[0] || null;

    // 2. CDS scores — avg + per-concept breakdown (only from current enrollments)
    // Only real scores count: batch 'Unscored' placeholders (cds IS NULL) are
    // created for students with no submissions and must not appear as mastery.
    const cdsParams = [studentId];
    let cdsSectionFilter = '';
    if (sectionId) {
      cdsParams.push(sectionId);
      cdsSectionFilter = ` AND en.section_id = $${cdsParams.length}`;
    }
    const cdsRes = await db.query(`
      SELECT cs.cds, cs.classification, cs.exercise_id, c.name AS concept_name, ex.title AS exercise_title
      FROM cds_scores cs
      JOIN exercises ex ON ex.id = cs.exercise_id
      JOIN concepts c ON c.id = ex.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id
      WHERE cs.student_id = $1 AND en.student_id = $1 AND cs.cds IS NOT NULL AND en.dropped_at IS NULL${cdsSectionFilter}
      ORDER BY cs.computed_at DESC
    `, cdsParams);
    const scores = cdsRes.rows || [];
    const avgCds = scores.length > 0
      ? scores.reduce((sum, s) => sum + parseFloat(s.cds || 0), 0) / scores.length
      : 0;

    // 3. Stats — exercise completion (activity metric, not mastery)
    const statsParams = [studentId];
    let statsSectionFilter = '';
    if (sectionId) {
      statsParams.push(sectionId);
      statsSectionFilter = ` AND ex.section_id = $${statsParams.length}`;
    }
    const statsRes = await db.query(`
      SELECT
        COUNT(DISTINCT ex.id)::int AS total,
        (SELECT COUNT(DISTINCT s.exercise_id)::int
         FROM submissions s
         JOIN exercises ex2 ON s.exercise_id = ex2.id
         JOIN enrollments en2 ON en2.section_id = ex2.section_id
          WHERE s.student_id = $1 AND s.is_correct = true
            AND en2.student_id = $1 AND en2.dropped_at IS NULL
        ) AS completed
      FROM exercises ex
      JOIN enrollments en ON en.section_id = ex.section_id
      WHERE en.student_id = $1 AND en.dropped_at IS NULL AND ex.is_draft = false${statsSectionFilter}
    `, statsParams);
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
        overdueCount,
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
    const sectionId = req.query.sectionId ? parseInt(req.query.sectionId, 10) : null;

    // Scope: flags count only when the student is actively enrolled in the
    // exercise's section (optional ?sectionId narrows to one section).
    const scopeFrom = `
      FROM integrity_flags i
      JOIN exercises ex ON ex.id = i.exercise_id
      JOIN enrollments en ON en.section_id = ex.section_id AND en.student_id = i.student_id
    `;
    const scopeWhere = (offset) => {
      let clause = `WHERE i.student_id = $${offset} AND en.dropped_at IS NULL`;
      if (sectionId) clause += ` AND en.section_id = $${offset + 1}`;
      return clause;
    };
    const statsParams = sectionId ? [studentId, sectionId] : [studentId];

    // Stats
    const statsRes = await db.query(`
      SELECT
        COUNT(*) AS total,
        COUNT(*) FILTER (WHERE i.status = 'flagged') AS flagged,
        COUNT(*) FILTER (WHERE i.status IN ('reviewed', 'dismissed')) AS reviewed
      ${scopeFrom}
      ${scopeWhere(1)}
    `, statsParams);

    const byTypeRes = await db.query(`
      SELECT i.flag_type, COUNT(*) AS count
      ${scopeFrom}
      ${scopeWhere(1)}
      GROUP BY i.flag_type
    `, statsParams);

    const cdsParams = [studentId];
    let cdsSectionFilter = '';
    if (sectionId) {
      cdsParams.push(sectionId);
      cdsSectionFilter = ` AND cs.section_id = $${cdsParams.length}`;
    }
    const cdsRes = await db.query(`
      SELECT
        ROUND(AVG(cds)::numeric, 2) AS avg_cds,
        MAX(cds) AS max_cds
      FROM cds_scores cs
      JOIN enrollments en ON en.section_id = cs.section_id AND en.student_id = cs.student_id
      WHERE cs.student_id = $1 AND cs.cds IS NOT NULL AND cs.visible = true
        AND en.dropped_at IS NULL${cdsSectionFilter}
    `, cdsParams);

    const latestCdsRes = await db.query(`
      SELECT cs.classification FROM cds_scores cs
      JOIN enrollments en ON en.section_id = cs.section_id AND en.student_id = cs.student_id
      WHERE cs.student_id = $1 AND cs.cds IS NOT NULL AND cs.visible = true
        AND en.dropped_at IS NULL${cdsSectionFilter}
      ORDER BY cs.computed_at DESC LIMIT 1
    `, cdsParams);

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
             ex.title AS exercise_title
      ${scopeFrom}
      ${scopeWhere(1)}
      ORDER BY i.created_at DESC
    `, statsParams);
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

// ── Contextual Activity Logging (paper flag #5) ────────────────────────────
// Receives browser-side telemetry: tab switches and paste events.
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
      if (!type || !['tab_switch', 'paste'].includes(type)) continue;

      await db.query(
        `INSERT INTO behavioral_events (student_id, exercise_id, event_type, occurred_at, payload)
         VALUES ($1, $2, $3, $4, $5)`,
        [studentId, exerciseId, type, timestamp || new Date(), JSON.stringify(payload || {})]
      );
    }

    // Note: behavioral events are logged here (passive behavior log) but no
    // longer mutate submissions — tab_switch_count/paste_count on a submission
    // are aggregated from per-run snapshots (run_attempts) at submit time.
    res.json({ received: toInsert.length });
  } catch (err) { next(err); }
});

// ── Code Snapshot Storage ────────────────────────────────────────────────────
// Receives editor telemetry samples (token count + active elapsed seconds).
// Stores in code_snapshots table, deduped per (session_id, active_elapsed_seconds).

router.post('/code-snapshots', behavioralLimiter, verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const studentId = req.user.id;
    const { exerciseId, sessionId, samples } = req.body;

    if (!exerciseId || !sessionId || !Array.isArray(samples) || samples.length === 0) {
      return res.status(400).json({ error: 'exerciseId, sessionId, and samples array required' });
    }

    // Batch insert samples (max 200 per request)
    const toInsert = samples.slice(0, 200);
    for (const s of toInsert) {
      const { tokenCount, activeElapsedSeconds, autocomplete } = s;
      if (typeof tokenCount !== 'number' || typeof activeElapsedSeconds !== 'number') continue;

      await db.query(
        `INSERT INTO code_snapshots (student_id, exercise_id, session_id, token_count, active_elapsed_seconds, autocomplete)
         VALUES ($1, $2, $3, $4, $5, $6)
         ON CONFLICT (session_id, active_elapsed_seconds) DO NOTHING`,
        [studentId, exerciseId, sessionId, tokenCount, Math.round(activeElapsedSeconds), Boolean(autocomplete)]
      );
    }

    res.json({ received: toInsert.length });
  } catch (err) { next(err); }
});

// Get today's personalized study plan
router.get('/today', verifyToken, requireRole('student'), async (req, res, next) => {
  try {
    const studentId = req.user.id;
    const sectionId = req.query.sectionId ? parseInt(req.query.sectionId, 10) : null;
    const params = [studentId];
    let sectionFilter = '';
    if (sectionId) {
      params.push(sectionId);
      sectionFilter = ` AND ex.section_id = $${params.length}`;
    }

    // 1. Exercises with concept CDS
    // Completion status derives from a correct submission (not CDS rows).
    const exercisesRes = await db.query(`
      SELECT ex.id, ex.title, ex.description, c.name AS concept_name,
             ex.time_limit_minutes, ex.deadline,
             CASE WHEN s.id IS NOT NULL THEN 'completed' ELSE 'pending' END AS status,
             (s.id IS NOT NULL) AS "isCompleted",
             cs.cds
      FROM exercises ex
      JOIN concepts c ON c.id = ex.concept_id
      JOIN enrollments en ON en.section_id = ex.section_id
      LEFT JOIN LATERAL (
        SELECT id FROM submissions
        WHERE exercise_id = ex.id AND student_id = $1 AND is_correct = true
        LIMIT 1
      ) s ON true
      LEFT JOIN cds_scores cs ON cs.exercise_id = ex.id AND cs.student_id = $1 AND cs.section_id = ex.section_id
      WHERE en.student_id = $1 AND en.dropped_at IS NULL AND ex.is_draft = false${sectionFilter}
      ORDER BY ex.deadline ASC NULLS LAST
    `, params);

    const allExercises = exercisesRes.rows || [];
    const pending = allExercises.filter(ex => ex.status === 'pending');

    // 2. Concept-level CDS (avg across all exercises per concept)
    // Uses exercise_concept_tags (primary) with fallback to ex.concept_id for missing tags
    const conceptParams = [studentId];
    let conceptSectionFilter = '';
    if (sectionId) {
      conceptParams.push(sectionId);
      conceptSectionFilter = ` AND en.section_id = $${conceptParams.length}`;
    }
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
      WHERE cs.student_id = $1 AND cs.cds IS NOT NULL AND en.dropped_at IS NULL${conceptSectionFilter}
      GROUP BY COALESCE(pt.name, c.name)
      ORDER BY avg_cds DESC
    `, conceptParams);

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
      const classParams = [focusEx.concept_name];
      let classSectionFilter = '';
      if (sectionId) {
        classParams.push(sectionId);
        classSectionFilter = ` AND en.section_id = $${classParams.length}`;
      }
      const classRes = await db.query(`
        SELECT AVG(cs.cds)::float AS class_avg
        FROM cds_scores cs
        JOIN exercises ex ON ex.id = cs.exercise_id
        JOIN concepts c ON c.id = ex.concept_id
        LEFT JOIN exercise_concept_tags ect ON ect.exercise_id = ex.id AND ect.is_primary = true
        LEFT JOIN concepts pt ON pt.id = ect.concept_id
        JOIN enrollments en ON en.section_id = ex.section_id
        WHERE COALESCE(pt.name, c.name) = $1 AND en.student_id = cs.student_id AND en.dropped_at IS NULL${classSectionFilter}
      `, classParams);
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
      signals.push(conceptCds.length > 0
        ? `Focus on ${focusEx.concept_name} — it's the concept with the highest remaining CDS.`
        : `Start with ${focusEx.concept_name} to get your first concept assessment.`);
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
      ? (conceptCds.length > 0
          ? `${focusEx.concept_name} is the concept with the highest CDS for your pending exercises. Working on it now will have the biggest impact on your overall mastery.`
          : `You haven't attempted any exercises yet. Start with ${focusEx.concept_name} to get your first concept assessment.`)
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
    const sectionId = req.query.sectionId ? parseInt(req.query.sectionId, 10) : null;
    const totalParams = [req.user.id];
    let totalSectionFilter = '';
    if (sectionId) {
      totalParams.push(sectionId);
      totalSectionFilter = ` AND ex.section_id = $${totalParams.length}`;
    }
    const totalRes = await db.query(`
      SELECT COUNT(DISTINCT ex.id)::int AS total
      FROM exercises ex
      JOIN enrollments en ON en.section_id = ex.section_id
      WHERE en.student_id = $1 AND en.dropped_at IS NULL AND ex.is_draft = false${totalSectionFilter}
    `, totalParams);
    const completedParams = [req.user.id];
    let completedSectionFilter = '';
    if (sectionId) {
      completedParams.push(sectionId);
      completedSectionFilter = ` AND en.section_id = $${completedParams.length}`;
    }
    const completedRes = await db.query(`
      SELECT COUNT(DISTINCT s.exercise_id)::int AS completed
      FROM submissions s
      JOIN exercises ex ON s.exercise_id = ex.id
      JOIN enrollments en ON en.section_id = ex.section_id
      WHERE s.student_id = $1 AND s.is_correct = true
        AND en.student_id = $1 AND en.dropped_at IS NULL${completedSectionFilter}
    `, completedParams);
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
    const sectionId = req.query.sectionId ? parseInt(req.query.sectionId, 10) : null;

    // 1. Concept mastery — CDS aggregated by concept (scoped to current enrollments)
    // Uses exercise_concept_tags (primary) with fallback to ex.concept_id for missing tags
    const conceptParams = [studentId];
    let conceptSectionFilter = '';
    if (sectionId) {
      conceptParams.push(sectionId);
      conceptSectionFilter = ` AND en.section_id = $${conceptParams.length}`;
    }
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
      WHERE cs.student_id = $1 AND cs.cds IS NOT NULL AND en.dropped_at IS NULL${conceptSectionFilter}
      GROUP BY COALESCE(pt.name, c.name)
      ORDER BY avg_cds ASC
    `, conceptParams);

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

    // 3. Overall mastery — average of per-concept mastery (100 - CDS)
    // Mastery is the inverse of difficulty: high CDS = low mastery.
    // Computed before trajectory so its messaging can reference it.
    const overallMastery = masteryConcepts.length > 0
      ? Math.round(masteryConcepts.reduce((sum, c) => sum + c.mastery, 0) / masteryConcepts.length)
      : 0;

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
      let actionTo;
      let detailBase;

      if (isNearlyMastered) {
        message = `Strong overall progress. ${weakest.concept_name} is your lowest at ${weakest.mastery}% — slight room to grow.`;
        tone = 'positive';
        actionLabel = `Practice ${weakest.concept_name}`;
        actionTo = '/student/exercises';
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
        actionTo = '/student/exercises';
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
    const completionParams = [studentId];
    let completionSectionFilter = '';
    if (sectionId) {
      completionParams.push(sectionId);
      completionSectionFilter = ` AND ex.section_id = $${completionParams.length}`;
    }
    const completionRes = await db.query(`
      SELECT COUNT(DISTINCT ex.id)::int AS total,
             (SELECT COUNT(DISTINCT s.exercise_id)::int
              FROM submissions s
              JOIN exercises ex2 ON s.exercise_id = ex2.id
              JOIN enrollments en2 ON en2.section_id = ex2.section_id
              WHERE s.student_id = $1 AND s.is_correct = true
                 AND en2.student_id = $1 AND en2.dropped_at IS NULL
             ) AS completed
      FROM exercises ex
      JOIN enrollments en ON en.section_id = ex.section_id
      WHERE en.student_id = $1 AND en.dropped_at IS NULL AND ex.is_draft = false${completionSectionFilter}
    `, completionParams);
    const total = completionRes.rows[0]?.total || 0;
    const completed = completionRes.rows[0]?.completed || 0;
    const completionPct = total > 0 ? Math.round((completed / total) * 100) : 0;

    // 4. Avg attempts per exercise (scoped to active enrollments in the section)
    const avgParams = [studentId];
    let avgSectionFilter = '';
    if (sectionId) {
      avgParams.push(sectionId);
      avgSectionFilter = ` AND ex.section_id = $${avgParams.length}`;
    }
    const avgAttemptsRes = await db.query(`
      SELECT AVG(attempt_count)::float AS avg_attempts
      FROM (SELECT ex.section_id, MAX(sub.attempt_number) AS attempt_count
            FROM submissions sub
            JOIN exercises ex ON ex.id = sub.exercise_id
            JOIN enrollments en ON en.section_id = ex.section_id AND en.student_id = sub.student_id
            WHERE sub.student_id = $1 AND en.dropped_at IS NULL${avgSectionFilter}
            GROUP BY ex.section_id, sub.exercise_id) s
    `, avgParams);
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
    const sectionId = req.query.sectionId ? parseInt(req.query.sectionId, 10) : null;

    const params = [studentId];
    let sectionFilter = '';
    if (sectionId) {
      params.push(sectionId);
      sectionFilter = ` AND en.section_id = $${params.length}`;
    }
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
      WHERE cs.student_id = $1 AND cs.cds IS NOT NULL AND en.dropped_at IS NULL${sectionFilter}
      GROUP BY COALESCE(pt.name, c.name)
      ORDER BY avg_cds ASC
    `, params);

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
