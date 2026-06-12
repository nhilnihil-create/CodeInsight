const db       = require('../config/db');
const executor = require('../services/executor');
const astVerifier = require('../services/astVerifier');
const academicIntegrityEngine = require('../services/academicIntegrityEngine');
const integrityFlagEngine = require('../services/integrityFlagEngine');
const { gradeSubmission } = require('../services/streamMatcher');

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
    const visibleTC = exercise.test_cases.filter(tc => !tc.hidden);
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

    res.status(500).json({ message: err.message });
  }
};

// Submit → — official submission, SAVES to database
exports.submit = async (req, res) => {
  const startTime = Date.now();
  const { exerciseId, code, timeSpentSeconds, behavioralData, behavioralEvents } = req.body;

  // GAP #3: Normalize behavioral data from both sources
  // frontend sends behavioralEvents array; extract summary counts
  const behavioralSummary = {
    tabSwitchCount: 0,
    pasteCount: 0,
    idleTimeSeconds: 0,
  };
  if (behavioralData) {
    Object.assign(behavioralSummary, behavioralData);
  }
  if (Array.isArray(behavioralEvents)) {
    for (const ev of behavioralEvents) {
      if (ev.type === 'tab_blur' || ev.type === 'tab_focus') behavioralSummary.tabSwitchCount++;
      if (ev.type === 'paste') behavioralSummary.pasteCount++;
      if (ev.type === 'idle_start') behavioralSummary.idleTimeSeconds += 30; // approximate
    }
  }
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
    if (attemptNumber > 1) {
      const prevRes = await db.query(
        'SELECT code FROM submissions WHERE student_id=$1 AND exercise_id=$2 AND attempt_number=$3',
        [studentId, exerciseId, attemptNumber - 1]
      );
      if (prevRes.rows.length > 0) {
        const prevCode = prevRes.rows[0].code || '';
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

    // ── Growth Velocity: token-based integrity check ────────────────────
    // Compares student's token count against the exercise baseline (starter code).
    // Triggers integrity flag if growth exceeds 200% in a single attempt.
    // This is dynamic (not static solution comparison) — monitors how much
    // the student's code grew relative to what they were given.
    const starterTokens = countTokens(exercise.starter_code || '');
    const studentTokens = countTokens(code || '');
    let growthVelocity = null;

    if (starterTokens > 0 && attemptNumber === 1) {
      // First attempt: compare against starter code baseline
      const growthPercent = ((studentTokens - starterTokens) / starterTokens) * 100;
      growthVelocity = {
        baselineTokens: starterTokens,
        studentTokens,
        growthPercent: Math.round(growthPercent),
        threshold: 200,
        flagged: growthPercent > 200,
      };
    } else if (attemptNumber > 1) {
      // Subsequent attempts: compare against PREVIOUS submission (not starter)
      const prevRes = await db.query(
        'SELECT code FROM submissions WHERE student_id=$1 AND exercise_id=$2 AND attempt_number=$3',
        [studentId, exerciseId, attemptNumber - 1]
      );
      if (prevRes.rows.length > 0) {
        const prevTokens = countTokens(prevRes.rows[0].code || '');
        if (prevTokens > 0) {
          const growthPercent = ((studentTokens - prevTokens) / prevTokens) * 100;
          growthVelocity = {
            baselineTokens: prevTokens,
            studentTokens,
            growthPercent: Math.round(growthPercent),
            threshold: 200,
            flagged: growthPercent > 200,
          };
        }
      }
    }

    // Flag growth velocity anomaly if triggered
    if (growthVelocity?.flagged) {
      try {
        await integrityFlagEngine.createFlag({
          sectionId: exercise.section_id,
          exerciseId,
          studentId,
          flagType: 'growth_velocity_anomaly',
          severity: 'high',
          evidence: {
            baseline_tokens: growthVelocity.baselineTokens,
            student_tokens: growthVelocity.studentTokens,
            growth_percent: growthVelocity.growthPercent,
            threshold: growthVelocity.threshold,
            attempt_number: attemptNumber,
          },
          contextBehaviors: [
            `Code grew ${growthVelocity.growthPercent}% in attempt #${attemptNumber} (${growthVelocity.baselineTokens} → ${growthVelocity.studentTokens} tokens)`,
          ],
          status: 'flagged',
        });
      } catch (flagErr) {
        // Non-fatal: don't break submission flow
        console.warn('Growth velocity flag creation failed:', flagErr.message);
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
         (student_id,exercise_id,code,is_correct,attempt_number,time_spent_seconds,is_verified,verification_note,code_growth_delta,cppcheck_warnings,tab_switch_count,paste_count,idle_time_seconds)
         VALUES($1,$2,$3,false,$4,$5,$6,$7,$8,$9,$10,$11,$12) RETURNING id`,
        [studentId, exerciseId, code || '', attemptNumber, timeSpentSeconds || 0, false, verification_note, codeGrowthDelta, '[]', behavioralSummary.tabSwitchCount, behavioralSummary.pasteCount, behavioralSummary.idleTimeSeconds]
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
      // Non-fatal: cppcheck is advisory
    }

    // Get required nodes from the exercise's concept
    const requiredNodesRes = await db.query(
      'SELECT ast_nodes FROM concepts WHERE id=$1',
      [exercise.concept_id]
    );
    const requiredNodes = requiredNodesRes.rows.length > 0 ? (requiredNodesRes.rows[0].ast_nodes || []) : [];

    // Get concept name from database (needed by AST verifier and micro-concept analysis)
    const conceptRes = await db.query(
      'SELECT c.name FROM concepts c JOIN exercises e ON c.id = e.concept_id WHERE e.id = $1',
      [exerciseId]
    );
    const conceptName = conceptRes.rows.length > 0 ? conceptRes.rows[0].name : 'Unknown';

    // Run AST verifier before saving submission
    const verifyRes = await astVerifier.verify(code, { required_nodes: requiredNodes }, { starter_code: exercise.starter_code, concept_name: conceptName });
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
      microContext.ast.node_types = Array.from(nodeTypes);
    } catch (astError) {
      // Fallback to empty if AST parsing fails
      microContext.ast.node_types = [];
    }

    const microConceptFeedback = await microConceptEngine.getMicroConceptFeedback(microContext, conceptName);

    // Save submission (include verification fields, code growth delta, cppcheck warnings, behavioral data)
    const bd = behavioralData || {};
    const insRes = await db.query(
      `INSERT INTO submissions
       (student_id,exercise_id,code,is_correct,attempt_number,time_spent_seconds,is_verified,verification_note,code_growth_delta,cppcheck_warnings,tab_switch_count,paste_count,idle_time_seconds)
       VALUES($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING id`,
      [studentId, exerciseId, code, allPassed, attemptNumber, timeSpentSeconds || 0, is_verified, verification_note, codeGrowthDelta, JSON.stringify(cppcheckWarnings), behavioralSummary.tabSwitchCount, behavioralSummary.pasteCount, behavioralSummary.idleTimeSeconds]
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

    // Run academic integrity checks
    try {
      const academicIntegrityFlags = await academicIntegrityEngine.evaluateIntegrity({
        code,
        starterCode: exercise.starter_code || '',
        studentId,
        exerciseId,
        submission: {
          ...(allPassed !== undefined && { is_correct: allPassed }),
          test_results: tcResults,
          time_spent_seconds: timeSpentSeconds || 0,
          submission_id: submissionId
        },
        exercise,
        cdsEngine: require('../services/cdsEngine'), // Pass reference for historical data if needed
        behavioralData: behavioralSummary, // Tab switches, paste count, idle time from telemetry
      });

      // Insert any integrity flags into the database
      for (const flag of academicIntegrityFlags) {
        await integrityFlagEngine.createFlag({
          sectionId: exercise.section_id,
          exerciseId: exerciseId,
          studentId: studentId,
          flagType: flag.type,
          severity: flag.severity,
          evidence: flag.evidence || {},
          contextBehaviors: flag.context_behaviors || [],
          status: 'flagged',
          instructorNote: flag.instructor_note || '',
          submissionId: submissionId
        });
      }

      // Run code paste detection (requires reference solution on the exercise)
      try {
        if (exercise.reference_solution) {
          const pasteResult = await integrityFlagEngine.detectCodePaste(code, exerciseId);
          if (pasteResult.detected) {
            await integrityFlagEngine.createFlag({
              sectionId: exercise.section_id,
              exerciseId: exerciseId,
              studentId: studentId,
              flagType: 'code_paste_detected',
              severity: 'high',
              evidence: { matchPercent: pasteResult.matchPercent, details: pasteResult.details },
              contextBehaviors: [],
              status: 'flagged',
              submissionId: submissionId
            });
          }
        }
      } catch (pasteErr) {
        console.warn('Code paste detection failed:', pasteErr.message);
      }
    } catch (integrityError) {
      // Don't let integrity check errors break the submission flow
      console.warn('Academic integrity check failed:', integrityError.message);
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
      }
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

    // If assessment mode, compute rubric score
    if (exercise.mode === 'assessment') {
      const rubricScorer = require('../services/rubricScorer');
      responseData.rubricScore = await rubricScorer.scoreSubmission(
        submissionId, exerciseId, exercise.rubric_config
      );
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

    console.error(err);
    res.status(500).json({ message: err.message });
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
    res.status(500).json({ message: err.message });
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
    res.status(500).json({ message: err.message });
  }
};
