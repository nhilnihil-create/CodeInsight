const db = require('../config/db');
const cdsEngine = require('../services/cdsEngine');
const nodemailer = require('nodemailer');
const queue = [];
let isWorkerRunning = false;

// Background job handler for CDS computation
const processQueue = async () => {
  if (!isWorkerRunning && queue.length > 0) {
    isWorkerRunning = true;
    let currentJob = null;
    try {
      while (queue.length > 0) {
        currentJob = queue.shift();
        await cdsEngine.computeBatchCDS(currentJob.exerciseId, db);
        await notifyStudent(currentJob.exerciseId, 'CDS computation completed');
        currentJob.resolve();
      }
    } catch (error) {
      console.error('Background job failed:', error);
      if (currentJob) {
        currentJob.reject(error);
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