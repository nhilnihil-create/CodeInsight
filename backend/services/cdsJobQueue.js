const db = require('../config/db');
const cdsEngine = require('../services/cdsEngine');
const nodemailer = require('nodemailer');

let isWorkerRunning = false;
let pollingInterval = null;
const POLL_INTERVAL_MS = 1000;

// Start background polling for pending jobs
function startPolling() {
  if (pollingInterval) return;
  pollingInterval = setInterval(processQueue, POLL_INTERVAL_MS);
}

function stopPolling() {
  if (pollingInterval) {
    clearInterval(pollingInterval);
    pollingInterval = null;
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
        console.error('Background job failed:', error);
        await db.query(
          `UPDATE cds_job_queue SET status = 'failed', finished_at = NOW(), error = $1 WHERE id = $2`,
          [error.message, job.id]
        );
      }
    }
  } catch (error) {
    console.error('Queue processing error:', error);
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
 * Notify students about CDS computation via email
 */
const notifyStudent = async (exerciseId, message) => {
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

    console.log(`[Notification] Exercise ${exerciseId}: ${message}`);
    console.log(`  Recipients: ${studentsRes.rows.length} students in section ${sectionId}`);

    // Send emails if enabled and configured
    const emailEnabled = process.env.EMAIL_ENABLED &&
      ['true', 'True', 'TRUE', 'yes', 'Yes', 'YES', '1', 'on'].includes(process.env.EMAIL_ENABLED);

    if (emailEnabled) {
      if (!process.env.EMAIL_HOST || !process.env.EMAIL_PORT || !process.env.EMAIL_USER || !process.env.EMAIL_PASS) {
        console.warn('[Notification] Email credentials incomplete - skipping email notifications');
      } else {
        console.log('[Notification] Attempting to send email notifications...');
        await sendEmailNotifications(studentsRes.rows, message, exerciseId);
        console.log('[Notification] Email notifications processed');
      }
    } else {
      console.log('[Notification] Email notifications disabled (EMAIL_ENABLED not set to true value)');
    }
  } catch (err) {
    console.error('Error in notifyStudent:', err);
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
        console.log(`Email sent to ${students[i].email} (${students[i].name})`);
      } else {
        console.error(`Failed to send email to ${students[i].email}:`, result.reason);
      }
    }
  } catch (err) {
    console.error('Error sending email notifications:', err);
  }
}

exports.processQueue = processQueue;
exports.stopPolling = stopPolling;

// Polling is started lazily when the first job is enqueued
