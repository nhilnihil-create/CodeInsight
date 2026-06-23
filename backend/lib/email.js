const nodemailer = require('nodemailer');
const logger = require('./logger');

function createTransporter() {
  if (process.env.EMAIL_ENABLED !== 'true') return null;
  return nodemailer.createTransport({
    host: process.env.EMAIL_HOST || 'smtp.ethereal.email',
    port: parseInt(process.env.EMAIL_PORT, 10) || 587,
    secure: parseInt(process.env.EMAIL_PORT, 10) === 465,
    auth: {
      user: process.env.EMAIL_USER,
      pass: process.env.EMAIL_PASS,
    },
  });
}

async function sendEmail({ to, subject, html }) {
  if (process.env.EMAIL_ENABLED !== 'true') {
    logger.info({ to, subject }, 'Email disabled — skipping send');
    return;
  }
  const transporter = createTransporter();
  if (!transporter) {
    logger.warn('Email transporter not configured');
    return;
  }
  const from = process.env.EMAIL_FROM || 'noreply@codeinsight.psu.edu';
  await transporter.sendMail({ from, to, subject, html });
  logger.info({ to, subject }, 'Email sent');
}

async function sendVerificationEmail({ to, name, token }) {
  const appUrl = process.env.APP_URL || 'http://localhost:5000';
  const link = `${appUrl}/api/auth/verify-email/${token}`;
  const subject = 'Verify your CodeInsight account';
  const html = `
    <h1>Welcome to CodeInsight, ${name}!</h1>
    <p>Please verify your email address by clicking the link below:</p>
    <p><a href="${link}">Verify Email</a></p>
    <p>This link expires in 24 hours.</p>
    <p>If you did not create this account, please ignore this email.</p>
  `;
  await sendEmail({ to, subject, html });
}

module.exports = { sendEmail, sendVerificationEmail };
