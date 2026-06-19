#!/usr/bin/env node
/**
 * backend/queues/submissionWorker.js
 *
 * BullMQ worker that processes queued submission evaluation jobs.
 * Runs code compilation, test-case execution, AST verification, and
 * integrity checks — then stores results in the database.
 *
 * Start: node backend/queues/submissionWorker.js
 * Or via PM2: pm2 start backend/queues/submissionWorker.js --name submission-worker
 */

const { Worker } = require('bullmq');
const IORedis = require('ioredis');
const executor = require('../services/executor');
const astVerifier = require('../services/astVerifier');
const academicIntegrityEngine = require('../services/academicIntegrityEngine');
const integrityFlagEngine = require('../services/integrityFlagEngine');
const conceptAnalytics = require('../services/conceptAnalytics');
const { gradeSubmission } = require('../services/streamMatcher');

const db = require('../config/db');

function countTokens(code) {
  if (!code) return 0;
  const cleaned = code.replace(/\/\/.*$/gm, '').replace(/\/\*[\s\S]*?\*\//g, '').replace(/"[^"]*"/g, '""').replace(/'[^']*'/g, "''");
  const tokens = cleaned.match(/[a-zA-Z_]\w*|\d+|[+\-*/=<>!&|^~%]+/g) || [];
  return tokens.length;
}

async function createWorker() {
  const redisConnection = new IORedis({
    host: process.env.REDIS_HOST || 'localhost',
    port: parseInt(process.env.REDIS_PORT || '6379'),
    password: process.env.REDIS_PASSWORD || undefined,
    maxRetriesPerRequest: null, // Worker needs persistent connection
  });

  const worker = new Worker(
    'submissions',
    async (job) => {
      const { exerciseId, code, studentId, timeSpentSeconds, submissionId } = job.data;

      // Update progress
      await job.updateProgress(10);

      // Fetch exercise
      const ex = await db.query('SELECT * FROM exercises WHERE id = $1', [exerciseId]);
      if (!ex.rows.length) {
        throw new Error('Exercise not found');
      }
      const exercise = ex.rows[0];

      // Check if exercise is closed
      if (exercise.closed_at) {
        return { status: 'rejected', message: 'Exercise is closed', allPassed: false };
      }

      await job.updateProgress(25);

      // Run against test cases
      const tcResults = await executor.runAgainstTestCases(
        code, exercise.test_cases, exercise.time_limit_minutes * 60, true
      );
      const allPassed = tcResults.every(r => r.passed);

      await job.updateProgress(50);

      // AST verification
      const requiredNodesRes = await db.query('SELECT ast_nodes FROM concepts WHERE id = $1', [exercise.concept_id]);
      const requiredNodes = requiredNodesRes.rows.length > 0 ? (requiredNodesRes.rows[0].ast_nodes || []) : [];

      const conceptRes = await db.query('SELECT c.name FROM concepts c JOIN exercises e ON c.id = e.concept_id WHERE e.id = $1', [exerciseId]);
      const conceptName = conceptRes.rows.length > 0 ? conceptRes.rows[0].name : 'Unknown';

      const verifyRes = await astVerifier.verify(code, { required_nodes: requiredNodes }, { concept_name: conceptName });

      await job.updateProgress(65);

      // If a submissionId was pre-created (by the controller), update it.
      // Otherwise create a new submission record.
      let savedSubmissionId = submissionId;
      if (!savedSubmissionId) {
        // Get attempt number
        const attRes = await db.query(
          'SELECT COALESCE(MAX(attempt_number),0)+1 AS next FROM submissions WHERE student_id=$1 AND exercise_id=$2',
          [studentId, exerciseId]
        );
        const attemptNumber = attRes.rows[0].next;

        const insRes = await db.query(
          `INSERT INTO submissions
           (student_id, exercise_id, code, is_correct, attempt_number, time_spent_seconds,
            is_verified, verification_note)
           VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING id`,
          [
            studentId, exerciseId, code, allPassed, attemptNumber, timeSpentSeconds || 0,
            !!verifyRes.is_verified, verifyRes.reasons?.join('; ') || '',
          ]
        );
        savedSubmissionId = insRes.rows[0].id;
      }

      // Log verification failures into verification_logs for instructor review
      if (!verifyRes.is_verified && verifyRes.reasons && verifyRes.reasons.length > 0) {
        try {
          await db.query(
            `INSERT INTO verification_logs (submission_id, student_id, exercise_id, verification_type, reason)
             VALUES ($1, $2, $3, 'bad_pattern', $4)`,
            [savedSubmissionId, studentId, exerciseId, verifyRes.reasons.join('; ') || 'Unknown']
          );
        } catch (vlErr) {
          console.warn('Failed to log verification result:', vlErr.message);
        }
      }

      await job.updateProgress(80);

      // Academic integrity checks (paper flags 1 & 2: hardcoding, blank template)
      try {
        const flags = await academicIntegrityEngine.evaluateIntegrity({
          code, starterCode: exercise.starter_code || '', studentId, exerciseId,
          submission: { is_correct: allPassed, test_results: tcResults, time_spent_seconds: timeSpentSeconds || 0, submission_id: savedSubmissionId },
          exercise,
        });

        for (const flag of flags) {
          await integrityFlagEngine.createFlag({
            sectionId: exercise.section_id, exerciseId, studentId,
            flagType: flag.type, severity: flag.severity,
            evidence: flag.evidence || {}, contextBehaviors: flag.context_behaviors || [],
            status: 'flagged', submissionId: savedSubmissionId,
          });
        }
      } catch (err) {
        console.warn('[Worker] Academic integrity check failed:', err.message);
      }

      await job.updateProgress(90);

      // Behavioral anomaly detection (paper flag 3: instant success, extreme speed)
      try {
        const behavioralDetector = require('../services/behavioralAnomalyDetector');
        const behavioralFlags = await behavioralDetector.detectBehavioralAnomalies({
          studentId,
          exerciseId,
          submissionId: savedSubmissionId,
          is_correct: allPassed,
          time_spent_seconds: timeSpentSeconds || 0,
          attempt_number: 0, // worker doesn't have attempt_number readily; detector will query
          sectionId: exercise.section_id,
        });

        for (const flag of behavioralFlags) {
          await integrityFlagEngine.createFlag({
            sectionId: exercise.section_id, exerciseId, studentId,
            flagType: flag.type, severity: flag.severity,
            evidence: flag.evidence || {},
            contextBehaviors: flag.context_behaviors || [],
            status: 'flagged', submissionId: savedSubmissionId,
          });
        }
      } catch (err) {
        console.warn('[Worker] Behavioral anomaly detection failed:', err.message);
      }

      await job.updateProgress(100);

      // Concept Analytics: live update CMI for affected student-concept pairs
      try {
        await conceptAnalytics.updateMetricsForSubmission(studentId, exerciseId);
      } catch (err) {
        console.warn('[Worker] Concept analytics update failed:', err.message);
      }

      // Build visible results
      const visibleResults = tcResults.filter(r => !r.hidden).map(r => ({
        input: r.input, expected: r.expected, actual: r.actual,
        passed: r.passed, status: r.status, error: r.error,
      }));

      return {
        submissionId: savedSubmissionId,
        allPassed,
        results: visibleResults,
        hidden: {
          count: tcResults.filter(r => r.hidden).length,
          passed: tcResults.filter(r => r.hidden).every(r => r.passed),
        },
        verification: {
          is_verified: !!verifyRes.is_verified,
          note: verifyRes.reasons?.join('; ') || '',
        },
      };
    },
    {
      connection: redisConnection,
      concurrency: 3, // Process 3 submissions in parallel (same as simulation BATCH_SIZE)
    }
  );

  worker.on('completed', (job) => {
    console.log(`[Worker] Job ${job.id} completed: allPassed=${job.returnvalue?.allPassed}`);
  });

  worker.on('failed', (job, err) => {
    console.error(`[Worker] Job ${job?.id} failed:`, err.message);
  });

  worker.on('error', (err) => {
    console.error('[Worker] Worker error:', err.message);
  });

  console.log('[Worker] Submission worker started (concurrency: 3)');

  return worker;
}

// Start worker if run directly
if (require.main === module) {
  createWorker().catch((err) => {
    console.error('[Worker] Failed to start:', err.message);
    process.exit(1);
  });
}

module.exports = { createWorker };
