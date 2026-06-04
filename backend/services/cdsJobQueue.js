const db = require('../config/db');
const cdsEngine = require('../services/cdsEngine');
const nodemailer = require('nodemailer');
const queue = [];
let isWorkerRunning = false;

// Background job handler for CDS computation
const processQueue = async () => {
  if (!isWorkerRunning && queue.length > 0) {
    isWorkerRunning = true;
    try {
      while (queue.length > 0) {
        const job = queue.shift();
        await cdsEngine.computeBatchCDS(job.exerciseId, db);
        await notifyStudent(job.exerciseId, 'CDS computation completed');
        job.resolve();
      }
    } catch (error) {
      console.error('Background job failed:', error);
      if (queue.length > 0) {
        queue[0].reject(error);
      }
    } finally {
      isWorkerRunning = false;
    }
  }
};

exports.enqueueCdsComputation = (exerciseId) => {
  return new Promise((resolve, reject) => {
    queue.push({ exerciseId, resolve, reject });
    processQueue();
  });
};

/**
 * Send notification to students about CDS computation
 * Supports database storage for UI retrieval and email integration
 */
const notifyStudent = async (exerciseId, message) => {
  try {
    // Get exercise details
    const exerciseRes = await db.query(
      `SELECT section_id FROM exercises WHERE id = $1`,
      [exerciseId]
    );

    if (!exerciseRes.rows.length) {
      console.warn(`Exercise ${exerciseId} not found for notification`);
      return;
    }

    const sectionId = exerciseRes.rows[0].section_id;

    // Get all students in section
    const studentsRes = await db.query(
      `SELECT DISTINCT e.student_id, u.email, u.name
       FROM enrollments e
       JOIN users u ON e.student_id = u.id
       WHERE e.section_id = $1`,
      [sectionId]
    );

    // Log notifications (development)
    console.log(`[Notification] Exercise ${exerciseId}: ${message}`);
    console.log(`  Recipients: ${studentsRes.rows.length} students in section ${sectionId}`);

    // Store notification records for each student (for UI retrieval)
    for (const student of studentsRes.rows) {
      try {
        await db.query(
          `INSERT INTO notifications (student_id, section_id, exercise_id, message, notification_type, created_at)
           VALUES ($1, $2, $3, $4, $5, NOW())
           ON CONFLICT (student_id, exercise_id, notification_type) DO NOTHING`,
          [student.student_id, sectionId, exerciseId, message, 'cds_computation']
        );
      } catch (err) {
        // Table might not exist in development - gracefully handle
        if (err.code === '42P01') {
          console.log('[Dev] Notifications table not yet created - skipping storage');
        } else {
          console.warn(`Failed to store notification for student ${student.student_id}:`, err.message);
        }
      }
    }

    // Send emails if enabled and configured
    const emailEnabled = process.env.EMAIL_ENABLED &&
      ['true', 'True', 'TRUE', 'yes', 'Yes', 'YES', '1', 'on'].includes(process.env.EMAIL_ENABLED);

    if (emailEnabled) {
      // Check if email credentials are configured
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
    // Don't throw - notification failure shouldn't break the main job
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
      secure: false, // true for 465, false for other ports
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

    // Send email to each student
    for (const student of students) {
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

      await transporter.sendMail(mailOptions);
      console.log(`Email sent to ${student.email} (${student.name})`);
    }
  } catch (err) {
    console.error('Error sending email notifications:', err);
    // Don't throw - email failure shouldn't break the notification system
  }
}