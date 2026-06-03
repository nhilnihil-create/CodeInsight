const db       = require('../config/db');
const executor = require('../services/executor');
const astVerifier = require('../services/astVerifier');
const academicIntegrityEngine = require('../services/academicIntegrityEngine');
const integrityFlagEngine = require('../services/integrityFlagEngine');

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
    // Run against first visible test case only
    const visibleTC = exercise.test_cases.filter(tc => !tc.hidden);
    if (!visibleTC.length)
      return res.json({ status: 'No visible test cases', output: '' });
    const result = await executor.executeCode(
      code, visibleTC[0].input, exercise.time_limit_minutes * 60
    );
    const expectedOutput = visibleTC[0].expected || visibleTC[0].expected_output || '';
    const passed = result.status === 'Success' &&
                   result.output.trim() === expectedOutput.trim();

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

    res.json({ ...result, expected: expectedOutput, passed });
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
  const { exerciseId, code, timeSpentSeconds } = req.body;
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

    // Calculate Code Growth Delta (Pillar 4: Jadud 2006)
    // Calculate line-count delta from the previous attempt
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
      // For first attempt, delta is from starter code
      const starterCode = exercise.starter_code || '';
      const currentLines = (code || '').split('\n').length;
      const starterLines = starterCode.split('\n').length;
      codeGrowthDelta = currentLines - starterLines;
    }

    // Handle blank submission (template-only or empty)
    const isBlank = !code || !code.trim() || code === exercise.starter_code;
    if (isBlank) {
      const verification_note = 'Blank or template-only submission';
      const ins = await db.query(
        `INSERT INTO submissions
         (student_id,exercise_id,code,is_correct,attempt_number,time_spent_seconds,is_verified,verification_note,code_growth_delta)
         VALUES($1,$2,$3,false,$4,$5,$6,$7,$8) RETURNING id`,
        [studentId, exerciseId, code || '', attemptNumber, timeSpentSeconds || 0, false, verification_note, codeGrowthDelta]
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

    // Get required nodes from the exercise's concept
    const requiredNodesRes = await db.query(
      'SELECT ast_nodes FROM concepts WHERE id=$1',
      [exercise.concept_id]
    );
    const requiredNodes = requiredNodesRes.rows.length > 0 ? (requiredNodesRes.rows[0].ast_nodes || []) : [];

    // Run AST verifier before saving submission
    const verifyRes = await astVerifier.verify(code, { required_nodes: requiredNodes }, { starter_code: exercise.starter_code });
    const is_verified = !!verifyRes.is_verified;
    const verification_note = (verifyRes.reasons || []).map(r => r.message || JSON.stringify(r)).join('; ');

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
      compilerErrors: [], // Would need to extract from executor output
      code: code,
      timeLimitHit: false, // Would need to check if execution timed out
      exercise: {
        concept_name: exercise.title, // Simplified - would need concept name from concepts table
        required_ast_nodes: exercise.ast_nodes || [],
        time_limit_minutes: exercise.time_limit_minutes
      }
    };

    // Get concept name from database
    const conceptRes = await db.query(
      'SELECT c.name FROM concepts c JOIN exercises e ON c.id = e.concept_id WHERE e.id = $1',
      [exerciseId]
    );
    const conceptName = conceptRes.rows.length > 0 ? conceptRes.rows[0].name : 'Unknown';

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

    // Save submission (include verification fields and code growth delta)
    const insRes = await db.query(
      `INSERT INTO submissions
       (student_id,exercise_id,code,is_correct,attempt_number,time_spent_seconds,is_verified,verification_note,code_growth_delta)
       VALUES($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING id`,
      [studentId, exerciseId, code, allPassed, attemptNumber, timeSpentSeconds || 0, is_verified, verification_note, codeGrowthDelta]
    );

    const submissionId = insRes.rows[0].id;

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
        behavioralData: {} // Frontend would send this data - for now empty
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

    // Prepare response with micro-concept feedback and code growth delta
    const responseData = {
      attemptNumber,
      allPassed,
      results: visibleResults,
      hidden: hiddenSummary,
      codeGrowthDelta,
      liveCDS,
      verification: {
        is_verified: is_verified,
        note: verification_note || (is_verified ? 'Code structure verified' : 'Verification failed')
      }
    };

    // Add micro-concept feedback if available
    if (microConceptFeedback.hasFeedback) {
      responseData.microConceptFeedback = microConceptFeedback;
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
