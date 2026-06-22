const db = require('../config/db');
const cdsEngine = require('../services/cdsEngine');
const nodemailer = require('nodemailer');
const logger = require('../lib/logger');

let isWorkerRunning = false;
let pollingInterval = null;
let cleanupInterval = null;
const POLL_INTERVAL_MS = 1000;

// In-memory dedup: tracks exercise_id -> last notification timestamp.
// Prevents spamming students when N submissions trigger N CDS recomputations
// for the same exercise in quick succession.
const lastNotifiedAt = new Map();
const NOTIFICATION_COOLDOWN_MS = 5 * 60 * 1000; // 5 minutes
const MAP_CLEANUP_INTERVAL_MS = 30 * 60 * 1000; // Clean stale entries every 30min

// Start background polling for pending jobs
function startPolling() {
  if (pollingInterval) return;
  pollingInterval = setInterval(processQueue, POLL_INTERVAL_MS);
  // Periodic cleanup of stale notification entries
  cleanupInterval = setInterval(() => {
    const cutoff = Date.now() - NOTIFICATION_COOLDOWN_MS * 2;
    let removed = 0;
    for (const [key, ts] of lastNotifiedAt) {
      if (ts < cutoff) {
        lastNotifiedAt.delete(key);
        removed++;
      }
    }
    if (removed > 0) logger.trace({ removed }, 'Cleaned stale notification entries');
  }, MAP_CLEANUP_INTERVAL_MS);
}

function stopPolling() {
  if (pollingInterval) {
    clearInterval(pollingInterval);
    pollingInterval = null;
  }
  if (cleanupInterval) {
    clearInterval(cleanupInterval);
    cleanupInterval = null;
  }
}

const processQueue = async () => {
  if (isWorkerRunning) return;
  isWorkerRunning = true;

  try {
    while (true) {
      // Atomically claim the next pending job
      const jobRes = await db.query(
        `UPDATE cds_job_queue
         SET status = 'processing', started_at = NOW()
         WHERE id = (
           SELECT id FROM cds_job_queue
           WHERE status = 'pending'
           ORDER BY created_at ASC
           LIMIT 1
           FOR UPDATE SKIP LOCKED
         )
         RETURNING *`
      );

      if (jobRes.rows.length === 0) break;

      const job = jobRes.rows[0];
      try {
        await cdsEngine.computeBatchCDS(job.exercise_id, db);
        await notifyStudent(job.exercise_id, 'CDS computation completed');
        await db.query(
          `UPDATE cds_job_queue SET status = 'done', finished_at = NOW() WHERE id = $1`,
          [job.id]
        );
      } catch (error) {
        logger.error({ err: error, exerciseId: job.exercise_id }, 'CDS background job failed');
        await db.query(
          `UPDATE cds_job_queue SET status = 'failed', finished_at = NOW(), error = $1 WHERE id = $2`,
          [error.message, job.id]
        );
      }
    }
  } catch (error) {
    logger.error({ err: error }, 'Queue processing error');
  } finally {
    isWorkerRunning = false;
  }
};

exports.enqueueCdsComputation = (exerciseId) => {
  return db.query(
    `INSERT INTO cds_job_queue (exercise_id) VALUES ($1) RETURNING *`,
    [exerciseId]
  ).then(() => {
    if (!pollingInterval) startPolling();
  });
};

/**
 * Notify students about CDS computation via email.
 * Deduplicates: skips notification if one was already sent within NOTIFICATION_COOLDOWN_MS
 * for the same exercise. Set force=true to bypass dedup.
 */
const notifyStudent = async (exerciseId, message, force = false) => {
  if (!force) {
    const lastTime = lastNotifiedAt.get(exerciseId);
    if (lastTime && Date.now() - lastTime < NOTIFICATION_COOLDOWN_MS) return;
  }

  try {
    const exerciseRes = await db.query(
      `SELECT section_id FROM exercises WHERE id = $1`,
      [exerciseId]
    );

    if (!exerciseRes.rows.length) {
      console.warn(`Exercise ${exerciseId} not found for notification`);
      return;
    }

    const sectionId = exerciseRes.rows[0].section_id;

    const studentsRes = await db.query(
      `SELECT DISTINCT e.student_id, u.email, u.name
       FROM enrollments e
       JOIN users u ON e.student_id = u.id
       WHERE e.section_id = $1`,
      [sectionId]
    );

    lastNotifiedAt.set(exerciseId, Date.now());
    logger.info({ exerciseId, sectionId, recipientCount: studentsRes.rows.length }, `Notification: ${message}`);

    // Send emails if enabled and configured
    const emailEnabled = process.env.EMAIL_ENABLED &&
      ['true', 'True', 'TRUE', 'yes', 'Yes', 'YES', '1', 'on'].includes(process.env.EMAIL_ENABLED);

    if (emailEnabled) {
      if (!process.env.EMAIL_HOST || !process.env.EMAIL_PORT || !process.env.EMAIL_USER || !process.env.EMAIL_PASS) {
        logger.warn('Email credentials incomplete - skipping email notifications');
      } else {
        logger.info('Attempting to send email notifications...');
        await sendEmailNotifications(studentsRes.rows, message, exerciseId);
        logger.info('Email notifications processed');
      }
    } else {
      logger.info('Email notifications disabled (EMAIL_ENABLED not set to true value)');
    }
  } catch (err) {
    logger.error({ err }, 'Error in notifyStudent');
  }
};

/**
 * Send email notifications to students about CDS computation
 * @param {Array} students - Array of student objects with email and name
 * @param {string} message - Notification message
 * @param {number} exerciseId - Exercise ID for context
 */
async function sendEmailNotifications(students, message, exerciseId) {
  try {
    // Create transporter
    const transporter = nodemailer.createTransport({
      host: process.env.EMAIL_HOST,
      port: parseInt(process.env.EMAIL_PORT),
      secure: false,
      auth: {
        user: process.env.EMAIL_USER,
        pass: process.env.EMAIL_PASS,
      },
    });

    // Get exercise details for context
    const exerciseRes = await db.query(
      `SELECT title FROM exercises WHERE id = $1`,
      [exerciseId]
    );
    const exerciseTitle = exerciseRes.rows.length ? exerciseRes.rows[0].title : 'Exercise';

    // Send email to each student with error isolation
    const results = await Promise.allSettled(students.map(student => {
      const mailOptions = {
        from: process.env.EMAIL_FROM || 'noreply@codeinsight.psu.edu',
        to: student.email,
        subject: `CodeInsight: CDS Computation Complete for ${exerciseTitle}`,
        text: `
Hello ${student.name},

${message}

Exercise: ${exerciseTitle}
You can now view your Concept Difficulty Score (CDS) in the CodeInsight platform.

Best regards,
CodeInsight Team
        `.trim(),
      };

      return transporter.sendMail(mailOptions);
    }));

    for (const [i, result] of results.entries()) {
      if (result.status === 'fulfilled') {
        logger.info({ email: students[i].email }, 'Email sent');
      } else {
        logger.error({ err: result.reason, email: students[i].email }, 'Failed to send email');
      }
    }
  } catch (err) {
    logger.error({ err }, 'Error sending email notifications');
  }
}

exports.processQueue = processQueue;
exports.stopPolling = stopPolling;
exports.notifyStudent = notifyStudent;
exports.lastNotifiedAt = lastNotifiedAt;
exports.NOTIFICATION_COOLDOWN_MS = NOTIFICATION_COOLDOWN_MS;

// Polling is started lazily when the first job is enqueued
