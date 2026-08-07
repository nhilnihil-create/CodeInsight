const nodemailer = require('nodemailer');
const logger = require('./logger');

function createTransporter() {
  if (process.env.EMAIL_ENABLED !== 'true') return null;
  return nodemailer.createTransport({
    host: 'smtp-relay.brevo.com',
    port: 587,
    secure: false,
    auth: {
      user: process.env.EMAIL_USER,
      pass: process.env.BREVO_SMTP_KEY,
    },
  });
}

async function sendEmail({ to, subject, html }) {
  if (process.env.EMAIL_ENABLED !== 'true') {
    logger.warn({ to, subject }, 'Email disabled — skipping send');
    throw new Error('Email is not enabled. Set EMAIL_ENABLED=true.');
  }
  const transporter = createTransporter();
  if (!transporter) {
    throw new Error('Email transporter failed to initialize');
  }
  const from = process.env.EMAIL_FROM || 'CodeInsight <noreply@codeinsight.psu.edu>';
  await transporter.sendMail({ from, to, subject, html });
  logger.info({ to, subject }, 'Email sent via Brevo SMTP');
}

async function sendOtpEmail({ to, name, otp }) {
  const subject = 'Your CodeInsight verification code';
  const html = `
    <h1>CodeInsight</h1>
    <p>Hello ${name},</p>
    <p>Your verification code is:</p>
    <p style="font-size: 32px; font-weight: bold; letter-spacing: 8px; text-align: center; padding: 16px; background: #f0f0f0; border-radius: 8px;">${otp}</p>
    <p>This code expires in 5 minutes.</p>
    <p>If you did not request this code, please ignore this email.</p>
    <p>— Pampanga State University · CCS · CodeInsight</p>
  `;
  await sendEmail({ to, subject, html });
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

module.exports = { sendEmail, sendVerificationEmail, sendOtpEmail };
