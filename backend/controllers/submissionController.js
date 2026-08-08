const db       = require('../config/db');
const executor = require('../services/executor');
const astVerifier = require('../services/astVerifier');
const { gradeSubmission } = require('../services/streamMatcher');
const errorReporter = require('../services/errorReporter');
const analyticsEngine = require('../services/analyticsEngine');
const conceptAnalytics = require('../services/conceptAnalytics');
const submissionQueue = require('../queues/submissionQueue');
const logger = require('../lib/logger');
const { graduatedFlag, runAcademicIntegrityChecks, runBehavioralChecks, runPassiveBehaviorCheck } = require('../lib/submissionPipeline');

/**
 * Token counter for growth velocity monitoring.
 * Counts C++ identifiers, keywords, operators, literals.
 */
function countTokens(code) {
  if (!code) return 0;
  const cleaned = code
    .replace(/\/\/.*$/gm, '')
    .replace(/\/\*[\s\S]*?\*\//g, '')
    .replace(/"[^"]*"/g, '""')
    .replace(/'[^']*'/g, "''");
  const tokens = cleaned.match(/[a-zA-Z_]\w*|\d+|[+\-*/=<>!&|^~%]+/g) || [];
  return tokens.length;
}

/**
 * Log a behavioral event to the audit_log table.
 * Non-fatal: logging errors do not break the submission flow.
 */
async function logAuditEvent(studentId, exerciseId, eventType, metadata = {}) {
  try {
    await db.query(
      `INSERT INTO audit_log (student_id, exercise_id, event_type, metadata, occurred_at)
       VALUES ($1, $2, $3, $4, NOW())`,
      [studentId, exerciseId, eventType, JSON.stringify(metadata)]
    );
  } catch (err) {
    // Silently skip — audit logging is non-blocking
    if (err.code !== '42P01') { // Ignore "table not found" during dev setup
      console.warn('Failed to log audit event:', err.message);
    }
  }
}

/**
 * Log performance metrics for ISO 25010 Performance Efficiency evaluation
 * @param {Object} metrics - Performance metrics to log
 */
async function logPerformanceMetrics(metrics) {
  try {
    const { exerciseId, studentId, endpoint, responseLatencyMs, httpStatusCode, userAgent } = metrics;

    // For simplicity, we'll set time_to_interactive_ms to 0 for now
    // In a more sophisticated implementation, this would measure time to first byte
    const timeToInteractiveMs = 0;

    await db.query(
      `INSERT INTO performance_logs
       (submission_id, student_id, exercise_id, time_to_interactive_ms, response_latency_ms, endpoint, http_status_code, user_agent)
       VALUES ($1, $2, $3, $4, $5, $6, $7, $8)`,
      [null, studentId, exerciseId, timeToInteractiveMs, responseLatencyMs, endpoint, httpStatusCode, userAgent]
    );
  } catch (error) {
    // Don't let logging errors break the main functionality
    console.warn('Failed to log performance metrics:', error.message);
  }
}

// ▶ RUN — local test, does NOT save to database
exports.run = async (req, res) => {
  const startTime = Date.now();
  const { exerciseId, code } = req.body;
  if (!code || !code.trim())
    return res.json({ status: 'Error', error: 'No code provided' });
  try {
    const ex = await db.query(
      'SELECT * FROM exercises WHERE id=$1', [exerciseId]
    );
    if (!ex.rows.length)
      return res.status(404).json({ message: 'Exercise not found' });
    const exercise = ex.rows[0];

    // Log run attempt (audit trail)
    if (req.user?.id) {
      await logAuditEvent(req.user.id, exerciseId, 'run_clicked', { code_length: code.length });
    }

    // Run against first visible test case only
    const visibleTC = exercise.test_cases.filter(tc => !executor.isHiddenTestCase(tc));
    if (!visibleTC.length)
      return res.json({ status: 'No visible test cases', output: '' });
    const result = await executor.executeCode(
      code, visibleTC[0].input, exercise.time_limit_minutes * 60
    );
    const expectedOutput = visibleTC[0].expected || visibleTC[0].expected_output || '';
    const grade = gradeSubmission(result.output || '', expectedOutput);
    const passed = result.status === 'Success' && grade.passed;

    // Calculate response latency for performance logging
    const endTime = Date.now();
    const responseLatencyMs = endTime - startTime;

    // Log performance metrics (for /run endpoint, time_to_interactive is not applicable)
    await logPerformanceMetrics({
      exerciseId: parseInt(exerciseId),
      studentId: req.user ? req.user.id : null,
      endpoint: '/run',
      responseLatencyMs,
      httpStatusCode: 200,
      userAgent: req.get('User-Agent') || ''
    });

    // Store every run attempt for misconception analysis
    if (req.user?.id) {
      const compileError = result.status === 'Compile Error' ? result.error : null;
      const runTimeLimitHit = result.status === 'Time Limit Exceeded';
      const errorCount = compileError
        ? (compileError.match(/ERROR/g) || []).length
        : result.status === 'Runtime Error' ? 1 : 0;

      await db.query(
        `INSERT INTO run_attempts
         (student_id, exercise_id, code, compiler_log, error_count, time_limit_hit)
         VALUES($1, $2, $3, $4, $5, $6)`,
        [req.user.id, exerciseId, code, compileError, errorCount, runTimeLimitHit]
      );
    }

    res.json({ ...result, expected: expectedOutput, passed, divergence: grade.divergenceIndex });
  } catch (err) {
    // Calculate response latency for performance logging even on error
    const endTime = Date.now();
    const responseLatencyMs = endTime - startTime;

    // Log performance metrics for failed requests
    await logPerformanceMetrics({
      exerciseId: parseInt(exerciseId),
      studentId: req.user ? req.user.id : null,
      endpoint: '/run',
      responseLatencyMs,
      httpStatusCode: 500,
      userAgent: req.get('User-Agent') || ''
    });

    logger.error({ err }, 'Run failed');
    res.status(500).json({ message: 'Execution failed' });
  }
};

// Submit → — official submission, SAVES to database
exports.submit = async (req, res) => {
  const startTime = Date.now();
  const { exerciseId, code, timeSpentSeconds, tabSwitchCount = 0, pasteCount = 0, idleTimeSeconds = 0 } = req.body;

  const studentId = req.user.id;
  try {
    const ex = await db.query(
      'SELECT * FROM exercises WHERE id=$1', [exerciseId]
    );
    if (!ex.rows.length)
      return res.status(404).json({ message: 'Exercise not found' });
    const exercise = ex.rows[0];
    if (exercise.closed_at)
      return res.status(400).json({ message: 'Exercise is closed' });

    // Get next attempt number
    const attRes = await db.query(
      'SELECT COALESCE(MAX(attempt_number),0)+1 AS next FROM submissions WHERE student_id=$1 AND exercise_id=$2',
      [studentId, exerciseId]
    );
    const attemptNumber = attRes.rows[0].next;

    // ── Code Growth Delta: line-count change from previous attempt ──────
    let codeGrowthDelta = 0;
    let prevCode = null;
    if (attemptNumber > 1) {
      const prevRes = await db.query(
        'SELECT code FROM submissions WHERE student_id=$1 AND exercise_id=$2 AND attempt_number=$3',
        [studentId, exerciseId, attemptNumber - 1]
      );
      if (prevRes.rows.length > 0) {
        prevCode = prevRes.rows[0].code || '';
        const currentLines = (code || '').split('\n').length;
        const prevLines = prevCode.split('\n').length;
        codeGrowthDelta = currentLines - prevLines;
      }
    } else {
      // First attempt: delta from starter code
      const starterCode = exercise.starter_code || '';
      const currentLines = (code || '').split('\n').length;
      const starterLines = starterCode.split('\n').length;
      codeGrowthDelta = currentLines - starterLines;
    }

    // ── Code Growth Anomaly (paper flag #4) ─────────────────────────────
    // A growth spike between consecutive submissions can indicate bulk
    // code insertion (pasting) rather than incremental coding. Threshold
    // requires BOTH >50% growth AND >50 absolute lines to avoid false
    // positives from legitimate additions (comments, error handling, etc.)
    const CODE_GROWTH_PCT_THRESHOLD = 50;
    const CODE_GROWTH_ABS_THRESHOLD = 100;
    const currentLineCount = (code || '').split('\n').length;
    let codeGrowthAnomaly = null;

    if (attemptNumber > 1) {
      // Compare against PREVIOUS submission's line count
      const prevRes = await db.query(
        'SELECT code FROM submissions WHERE student_id=$1 AND exercise_id=$2 AND attempt_number=$3',
        [studentId, exerciseId, attemptNumber - 1]
      );
      if (prevRes.rows.length > 0) {
        const prevLineCount = (prevRes.rows[0].code || '').split('\n').length;
        if (prevLineCount > 0) {
          const growthPercent = ((currentLineCount - prevLineCount) / prevLineCount) * 100;
          codeGrowthAnomaly = {
            baselineLines: prevLineCount,
            studentLines: currentLineCount,
            growthPercent: Math.round(growthPercent),
            thresholdPct: CODE_GROWTH_PCT_THRESHOLD,
            thresholdAbs: CODE_GROWTH_ABS_THRESHOLD,
            flagged: growthPercent > CODE_GROWTH_PCT_THRESHOLD && currentLineCount > CODE_GROWTH_ABS_THRESHOLD,
          };
        }
      }
    }

    // Flag code growth anomaly if triggered (graduated: first is warning only)
    if (codeGrowthAnomaly?.flagged) {
      try {
        await graduatedFlag({
          sectionId: exercise.section_id,
          exerciseId,
          studentId,
          flagType: 'CODE_GROWTH_ANOMALY',
          severity: 'low',
          evidence: {
            summary: `Code grew ${codeGrowthAnomaly.growthPercent}% from ${codeGrowthAnomaly.baselineLines} to ${codeGrowthAnomaly.studentLines} lines in attempt #${attemptNumber}`,
            baseline_lines: codeGrowthAnomaly.baselineLines,
            student_lines: codeGrowthAnomaly.studentLines,
            growth_percent: codeGrowthAnomaly.growthPercent,
            threshold_pct: codeGrowthAnomaly.thresholdPct,
            threshold_abs: codeGrowthAnomaly.thresholdAbs,
            attempt_number: attemptNumber,
            confidence: 0.3,
            innocent_explanation: 'Student may have added error handling, comments, or a complete function body. Large line count changes between attempts are common when students consolidate partial work. 50%+ growth with 50+ lines absolute is still within normal range for many exercises.',
          },
          contextBehaviors: [
            `Code grew ${codeGrowthAnomaly.growthPercent}% in attempt #${attemptNumber} (${codeGrowthAnomaly.baselineLines} → ${codeGrowthAnomaly.studentLines} lines)`,
          ],
          submissionId,
        });
      } catch (flagErr) {
        // Non-fatal: don't break submission flow
        console.warn('Code growth anomaly flag creation failed:', flagErr.message);
      }
    }

    // Log submission attempt (audit trail)
    await logAuditEvent(studentId, exerciseId, 'submission_attempted', {
      attempt_number: attemptNumber,
      code_length: (code || '').length,
      time_spent_seconds: timeSpentSeconds || 0
    });

    // Handle blank submission (template-only or empty)
    const isBlank = !code || !code.trim() || code === exercise.starter_code;
    if (isBlank) {
      const verification_note = 'Blank or template-only submission';
      const ins = await db.query(
        `INSERT INTO submissions
         (student_id,exercise_id,code,is_correct,attempt_number,time_spent_seconds,is_verified,verification_note,code_growth_delta,cppcheck_warnings)
         VALUES($1,$2,$3,false,$4,$5,$6,$7,$8,$9) RETURNING id`,
        [studentId, exerciseId, code || '', attemptNumber, timeSpentSeconds || 0, false, verification_note, codeGrowthDelta, '[]']
      );

      // Log verification failure
      await db.query(
        `INSERT INTO verification_logs (submission_id, student_id, exercise_id, verification_type, reason)
         VALUES($1,$2,$3,$4,$5)`,
        [ins.rows[0].id, studentId, exerciseId, 'ast_verifier', verification_note]
      );

      // Calculate response latency for performance logging
      const endTime = Date.now();
      const responseLatencyMs = endTime - startTime;

      // Log performance metrics for blank submission
      await logPerformanceMetrics({
        exerciseId: parseInt(exerciseId),
        studentId: studentId,
        endpoint: '/submit',
        responseLatencyMs,
        httpStatusCode: 200,
        userAgent: req.get('User-Agent') || ''
      });

      return res.json({
        attemptNumber, allPassed: false,
        results: [], status: 'Blank submission',
        message: 'Blank submission recorded.',
        codeGrowthDelta
      });
    }

    // Run against ALL test cases
    const tcResults = await executor.runAgainstTestCases(
      code, exercise.test_cases, exercise.time_limit_minutes * 60, true
    );
    const allPassed = tcResults.every(r => r.passed);

    // Log pass/fail result
    if (allPassed) {
      await logAuditEvent(studentId, exerciseId, 'submission_passed', {
        attempt_number: attemptNumber,
        time_spent_seconds: timeSpentSeconds || 0
      });
    } else {
      const failedCount = tcResults.filter(r => !r.passed).length;
      await logAuditEvent(studentId, exerciseId, 'submission_failed', {
        attempt_number: attemptNumber,
        failed_count: failedCount,
        total_count: tcResults.length
      });
    }

    // Run cppcheck (advisory — stored in submission, shown to student)
    let cppcheckWarnings = [];
    try {
      cppcheckWarnings = await executor.runCppcheck(code);
    } catch (_) {
      logger.warn({ err: _.message }, 'cppcheck failed (advisory)');
    }

    // Resolve required AST nodes for structure verification. Per-exercise
    // requirements (exercise.ast_nodes) are strict — all must be present.
    // When the exercise declares none, fall back to the concept's ast_nodes,
    // which are alternatives ("any of").
    const exerciseNodes = Array.isArray(exercise.ast_nodes) ? exercise.ast_nodes : [];
    let requiredNodes = exerciseNodes;
    let anyOf = false;
    if (!requiredNodes.length) {
      const requiredNodesRes = await db.query(
        'SELECT ast_nodes FROM concepts WHERE id=$1',
        [exercise.concept_id]
      );
      const conceptNodes = requiredNodesRes.rows.length > 0 ? (requiredNodesRes.rows[0].ast_nodes || []) : [];
      requiredNodes = conceptNodes;
      anyOf = true; // concept lists are alternative ("any of") lists
    }
    const requiredPatterns = Array.isArray(exercise.required_patterns) ? exercise.required_patterns : [];

    // Get concept name from database (needed by AST verifier and micro-concept analysis)
    const conceptRes = await db.query(
      'SELECT c.name FROM concepts c JOIN exercises e ON c.id = e.concept_id WHERE e.id = $1',
      [exerciseId]
    );
    const conceptName = conceptRes.rows.length > 0 ? conceptRes.rows[0].name : 'Unknown';

    // Run AST verifier before saving submission
    const verifyRes = await astVerifier.verify(code, { required_nodes: requiredNodes, any_of: anyOf, required_patterns: requiredPatterns }, { starter_code: exercise.starter_code, concept_name: conceptName });
    const is_verified = !!verifyRes.is_verified;
    const verification_note = (verifyRes.reasons || []).map(r => r.message || JSON.stringify(r)).join('; ');

    // GAP #7: Extract compiler errors from test results for micro-concept analysis
    const compilerErrors = [];
    for (const tc of tcResults) {
      if (tc.error && (tc.status === 'Compile Error' || tc.status === 'Runtime Error')) {
        compilerErrors.push(tc.error);
      }
    }

    // Run micro-concept analysis for specific feedback
    const microConceptEngine = require('../services/microConceptEngine');
    const microContext = {
      ast: { node_types: [] }, // Will be populated from AST verifier if needed
      testResults: tcResults.map(r => ({
        input: r.input,
        expected: r.expected,
        actual: r.actual,
        passed: r.passed,
        error: r.error
      })),
      compilerErrors: compilerErrors, // GAP #7: populated from executor output
      code: code,
      timeLimitHit: tcResults.some(r => r.status === 'Time Limit Exceeded'),
      exercise: {
        concept_name: exercise.title, // Simplified - would need concept name from concepts table
        required_ast_nodes: exercise.ast_nodes || [],
        time_limit_minutes: exercise.time_limit_minutes
      }
    };

    // Update micro concept context with actual concept name and better AST data
    microContext.exercise.concept_name = conceptName;
    // Try to get AST node types from verifier if possible (simplified)
    try {
      const parser = require('tree-sitter');
      const CPP = require('tree-sitter-cpp');
      const astParser = new parser();
      astParser.setLanguage(CPP);
      const tree = astParser.parse(code);
      const nodeTypes = new Set();
      function traverse(node) {
        nodeTypes.add(node.type);
        for (let i = 0; i < node.childCount; i++) {
          traverse(node.child(i));
        }
      }
      traverse(tree.rootNode);
      const types = Array.from(nodeTypes);
      microContext.ast.node_types = types;
      microContext.ast.if_count = types.filter(t => t === 'if_statement').length;
      microContext.ast.else_count = types.filter(t => t === 'else_clause').length;
      microContext.ast.has_private = types.some(t => t === 'private_section' || t === 'protected_section');
    } catch (astError) {
      // Fallback to empty if AST parsing fails
      microContext.ast.node_types = [];
      microContext.ast.if_count = 0;
      microContext.ast.else_count = 0;
      microContext.ast.has_private = false;
    }

    const microConceptFeedback = await microConceptEngine.getMicroConceptFeedback(microContext, conceptName);

    // Build persisting compiler data from tcResults
    const compilerLog = compilerErrors.join('\n');
    const timeLimitHit = tcResults.some(r => r.status === 'Time Limit Exceeded');



    // Save submission (include verification fields, code growth delta, cppcheck warnings, compiler_log, behavioral tracking)
    const insRes = await db.query(
      `INSERT INTO submissions
       (student_id,exercise_id,code,is_correct,attempt_number,time_spent_seconds,is_verified,verification_note,code_growth_delta,cppcheck_warnings,compiler_log,time_limit_hit,tab_switch_count,paste_count,idle_time_seconds)
       VALUES($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15) RETURNING id`,
      [studentId, exerciseId, code, allPassed, attemptNumber, timeSpentSeconds || 0, is_verified, verification_note, codeGrowthDelta, JSON.stringify(cppcheckWarnings), compilerLog, timeLimitHit, tabSwitchCount, pasteCount, idleTimeSeconds]
    );

    const submissionId = insRes.rows[0].id;

    // Log exercise_completed on first correct submission (triggers Practice Mode in frontend)
    if (allPassed && attemptNumber === 1) {
      await logAuditEvent(studentId, exerciseId, 'exercise_completed', {
        attempt_number: attemptNumber,
        time_spent_seconds: timeSpentSeconds || 0,
        cppcheck_warning_count: cppcheckWarnings.length
      });
    }

    // If verification failed, record a verification_log row
    if (!is_verified) {
      await db.query(
        `INSERT INTO verification_logs (submission_id, student_id, exercise_id, verification_type, reason)
         VALUES($1,$2,$3,$4,$5)`,
        [submissionId, studentId, exerciseId, 'ast_verifier', verification_note || 'Verification failed']
      );
    }

    // ── Academic Integrity Checks (paper flags 1 & 2) ───────────────────
    // Uses shared pipeline — same graduated logic as async worker path.
    try {
      await runAcademicIntegrityChecks({
        code, starterCode: exercise.starter_code || '', studentId, exerciseId,
        submission: {
          ...(allPassed !== undefined && { is_correct: allPassed }),
          test_results: tcResults, time_spent_seconds: timeSpentSeconds || 0,
          submission_id: submissionId
        },
        exercise, submissionId,
      });
    } catch (integrityError) {
      console.warn('Academic integrity check failed:', integrityError.message);
    }

    // ── Behavioral Anomaly Detection (paper flag 3) ──────────────────────
    // Uses shared pipeline — same graduated logic as async worker path.
    try {
      await runBehavioralChecks({
        studentId, exerciseId,
        submissionId,
        is_correct: allPassed,
        time_spent_seconds: timeSpentSeconds || 0,
        attempt_number: attemptNumber,
        sectionId: exercise.section_id,
      });
    } catch (behavioralError) {
      console.warn('Behavioral anomaly detection failed:', behavioralError.message);
    }

    // ── Contextual Activity Flag ────────────────────────────────────────
    // Telemetry-only: tab switches, paste events. Always LOW severity
    // as these are contextual indicators, not evidence of misconduct.
    try {
      await runPassiveBehaviorCheck({
        studentId, exerciseId,
        sectionId: exercise.section_id,
        submissionId,
        tabSwitchCount, pasteCount,
        timeSpentSeconds,
        attemptNumber,
      });
    } catch (flagErr) {
      console.warn('Contextual activity flag creation failed:', flagErr.message);
    }

    // Split visible vs hidden results for response
    const visibleResults = tcResults.filter(r => !r.hidden).map(r => ({
      input: r.input,
      expected: r.expected,
      actual: r.actual,
      passed: r.passed,
      status: r.status,
      error: r.error
    }));
    const hiddenResults = tcResults.filter(r => r.hidden);
    const hiddenSummary = {
      count: hiddenResults.length,
      passed: hiddenResults.length ? hiddenResults.every(r => r.passed) : true
    };

    // Deterministic test-case failure report (errorReporter)
    const failureReport = errorReporter.processFailureReport(tcResults, exercise.test_cases);
    const formattedFailures = errorReporter.formatForResponse(failureReport);

    // Calculate live CDS for display and persistence
    const cdsEngine = require('../services/cdsEngine');
    let liveCDS = null;
    try {
      liveCDS = await cdsEngine.calculateLiveCDS(studentId, exerciseId, db);
      
      if (liveCDS && liveCDS.cds !== null) {
        await db.query(`
          INSERT INTO cds_scores (student_id, exercise_id, section_id, ner, nrs, nts, cds, classification, has_flagged_attempts, integrity_flag_count, source, visible, computed_at)
          VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, 'live', false, NOW())
          ON CONFLICT (student_id, exercise_id)
          DO UPDATE SET ner=$4, nrs=$5, nts=$6, cds=$7, classification=$8, has_flagged_attempts=$9, integrity_flag_count=$10, source='live', visible=false, computed_at=NOW()
        `, [
          studentId, exerciseId, exercise.section_id,
          liveCDS.ner || 0, liveCDS.nrs || 0, liveCDS.nts || 0,
          liveCDS.cds || 0, liveCDS.classification || 'Unscored',
          liveCDS.hasFlaggedAttempt || false, liveCDS.integrityFlagCount || 0
        ]);
      }
    } catch (liveErr) {
      console.warn('Error calculating or saving live CDS:', liveErr.message);
    }

    // Analytics: track submission for at-risk detection (RETRY_STORM, LEARNING_PLATEAU)
    analyticsEngine.trackSubmission({
      studentId,
      exerciseId,
      isCorrect: allPassed,
      sectionId: exercise.section_id,
      attemptNumber,
    }).catch(err => console.warn('[Analytics] Tracking failed:', err.message));

    // Concept Analytics: live update CMI for affected student-concept pairs
    conceptAnalytics.updateMetricsForSubmission(studentId, exerciseId)
      .then(result => {
        if (result.updated) {
          responseData.conceptAnalytics = {
            updated: true,
            conceptsUpdated: result.conceptsUpdated,
          };
        }
      })
      .catch(err => console.warn('[ConceptAnalytics] Live update failed:', err.message));

    // Compute growth velocity: token count delta per minute from previous attempt
    let growthVelocity = null;
    try {
      const currentTokens = countTokens(code || '');
      if (attemptNumber > 1) {
        const prevRes = await db.query(
          'SELECT code FROM submissions WHERE student_id=$1 AND exercise_id=$2 AND attempt_number=$3',
          [studentId, exerciseId, attemptNumber - 1]
        );
        if (prevRes.rows.length > 0) {
          const prevTokens = countTokens(prevRes.rows[0].code || '');
          const tokenDelta = currentTokens - prevTokens;
          const minutes = Math.max((timeSpentSeconds || 0) / 60, 0.0167);
          growthVelocity = Math.round(tokenDelta / minutes);
        }
      } else {
        const starterTokens = countTokens(exercise.starter_code || '');
        const tokenDelta = currentTokens - starterTokens;
        const minutes = Math.max((timeSpentSeconds || 0) / 60, 0.0167);
        growthVelocity = Math.round(tokenDelta / minutes);
      }
    } catch (velErr) {
      console.warn('Growth velocity computation failed:', velErr.message);
    }

    // Pre-submission integrity hints (educational, not punitive)
    const preSubmissionCheck = require('../services/preSubmissionCheck');
    const preCheckHints = preSubmissionCheck.runAllChecks(
      code,
      attemptNumber > 1 ? prevCode : null,
      exercise.starter_code || '',
      tabSwitchCount || 0,
      pasteCount || 0
    );

    // Prepare response with micro-concept feedback, cppcheck warnings, code growth delta, and growth velocity
    const responseData = {
      attemptNumber,
      allPassed,
      results: visibleResults,
      hidden: hiddenSummary,
      codeGrowthDelta,
      growthVelocity,
      cppcheckWarnings: cppcheckWarnings.length > 0 ? cppcheckWarnings : undefined,
      liveCDS,
      verification: {
        is_verified: is_verified,
        note: verification_note || (is_verified ? 'Code structure verified' : 'Verification failed')
      },
      // Deterministic failure report (hints + sanitized errors)
      failureReport: formattedFailures.length > 0 ? formattedFailures : undefined,
      preCheckHints: preCheckHints.length > 0 ? preCheckHints : undefined,
    };

    // Add micro-concept feedback if available
    if (microConceptFeedback.hasFeedback) {
      responseData.microConceptFeedback = microConceptFeedback;

      // GAP #10: Generate alerts from micro-concept findings
      try {
        const alertEngine = require('../services/alertEngine');
        await alertEngine.generateMicroConceptAlert({
          studentId,
          exerciseId,
          sectionId: exercise.section_id,
          conceptName,
          detectedIssues: microConceptFeedback.detected || []
        }, db);
      } catch (alertErr) {
        console.warn('Micro-concept alert generation failed:', alertErr.message);
      }
    }

    // Calculate response latency for performance logging
    const endTime = Date.now();
    const responseLatencyMs = endTime - startTime;

    // Log performance metrics
    await logPerformanceMetrics({
      exerciseId: parseInt(exerciseId),
      studentId: studentId,
      endpoint: '/submit',
      responseLatencyMs,
      httpStatusCode: 200,
      userAgent: req.get('User-Agent') || ''
    });

    res.json(responseData);
  } catch (err) {
    // Calculate response latency for performance logging even on error
    const endTime = Date.now();
    const responseLatencyMs = endTime - startTime;

    // Log performance metrics for failed requests
    await logPerformanceMetrics({
      exerciseId: parseInt(exerciseId),
      studentId: req.user ? req.user.id : null,
      endpoint: '/submit',
      responseLatencyMs,
      httpStatusCode: 500,
      userAgent: req.get('User-Agent') || ''
    });

    logger.error({ err }, 'Submit failed');
    res.status(500).json({ message: 'Submission failed' });
  }
};

// GET my submissions for an exercise
exports.mySubmissions = async (req, res) => {
  try {
    const r = await db.query(
      `SELECT id,attempt_number,is_correct,time_spent_seconds,submitted_at
       FROM submissions
       WHERE student_id=$1 AND exercise_id=$2
       ORDER BY attempt_number ASC`,
      [req.user.id, req.params.exerciseId]
    );
    res.json(r.rows);
  } catch (err) {
    logger.error({ err }, 'mySubmissions failed');
    res.status(500).json({ message: 'Failed to load submissions' });
  }
};

// GET instructor view: specific student's submissions for an exercise
exports.studentSubmissions = async (req, res) => {
  try {
    const { studentId, exerciseId } = req.params;
    const r = await db.query(
      `SELECT id,attempt_number,is_correct,time_spent_seconds,submitted_at
       FROM submissions
       WHERE student_id=$1 AND exercise_id=$2
       ORDER BY attempt_number ASC`,
      [studentId, exerciseId]
    );
    res.json(r.rows);
  } catch (err) {
    logger.error({ err }, 'studentSubmissions failed');
    res.status(500).json({ message: 'Failed to load submissions' });
  }
};

// ── Async Submission (Queue-Based) ─────────────────────────────────────────

/**
 * POST /api/submissions/submit-async
 * Decouples submission processing from HTTP request using BullMQ.
 * Returns 202 Accepted with jobId for polling.
 */
exports.submitAsync = async (req, res) => {
  const { exerciseId, code, timeSpentSeconds } = req.body;
  const studentId = req.user.id;

  if (!code || !code.trim()) {
    return res.status(400).json({ message: 'No code provided' });
  }

  // Ensure queue is initialized
  const queueReady = await submissionQueue.initQueue();

  if (!queueReady) {
    // Fallback: process synchronously
    console.warn('[AsyncSubmit] Redis unavailable, falling back to sync');
    return exports.submit(req, res);
  }

  // Pre-create submission record to get an ID (worker updates it)
  let submissionId;
  try {
    const attRes = await db.query(
      'SELECT COALESCE(MAX(attempt_number),0)+1 AS next FROM submissions WHERE student_id=$1 AND exercise_id=$2',
      [studentId, exerciseId]
    );
    const attemptNumber = attRes.rows[0].next;

    const insRes = await db.query(
      `INSERT INTO submissions
       (student_id, exercise_id, code, is_correct, attempt_number, time_spent_seconds,
        is_verified, verification_note)
       VALUES ($1,$2,$3,false,$4,$5,false,'queued') RETURNING id`,
      [studentId, exerciseId, code, attemptNumber, timeSpentSeconds || 0]
    );
    submissionId = insRes.rows[0].id;
  } catch (err) {
    logger.error({ err }, 'Failed to queue submission');
    return res.status(500).json({ message: 'Failed to queue submission' });
  }

  // Add job to queue
  try {
    const jobId = await submissionQueue.addSubmissionJob({
      exerciseId,
      code,
      studentId,
      timeSpentSeconds: timeSpentSeconds || 0,
      submissionId,
    });

    res.status(202).json({
      message: 'Submission queued for evaluation',
      jobId,
      submissionId,
      statusUrl: `/api/submissions/status/${jobId}`,
    });
  } catch (err) {
    // Queue failed — clean up placeholder submission and fallback to sync
    await db.query('DELETE FROM submissions WHERE id = $1', [submissionId]).catch(() => {});
    console.warn('[AsyncSubmit] Queue add failed, falling back to sync:', err.message);
    return exports.submit(req, res);
  }
};

/**
 * GET /api/submissions/status/:jobId
 * Monitor worker processing state.
 * Returns: { jobId, status, result, error, progress, createdAt, processedAt, finishedAt }
 */
exports.getJobStatus = async (req, res) => {
  const { jobId } = req.params;

  const status = await submissionQueue.getJobStatus(jobId);
  if (!status) {
    return res.status(404).json({ message: 'Job not found' });
  }

  res.json(status);
};
