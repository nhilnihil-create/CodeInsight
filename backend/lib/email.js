const logger = require('./logger');

let brevoClient = null;

async function getClient() {
  if (brevoClient) return brevoClient;
  const apiKey = process.env.BREVO_API_KEY;
  if (!apiKey) throw new Error('BREVO_API_KEY is not set');
  const { BrevoClient } = require('@getbrevo/brevo');
  brevoClient = new BrevoClient({ apiKey });
  return brevoClient;
}

async function sendEmail({ to, subject, html }) {
  if (process.env.EMAIL_ENABLED !== 'true') {
    logger.warn({ to, subject }, 'Email disabled — skipping send');
    throw new Error('Email is not enabled. Set EMAIL_ENABLED=true.');
  }
  const client = await getClient();
  const fromEmail = process.env.EMAIL_FROM_ADDRESS || 'codeinsight.noreply@gmail.com';
  const fromName = process.env.EMAIL_FROM_NAME || 'CodeInsight';
  logger.info({ to, subject }, 'Sending email via Brevo API...');
  try {
    await client.transactionalEmails.sendTransacEmail({
      sender: { email: fromEmail, name: fromName },
      to: [{ email: to }],
      subject,
      htmlContent: html,
    });
    logger.info({ to, subject }, 'Email sent via Brevo API');
  } catch (err) {
    logger.error({ err: err.message, to, subject }, 'Brevo API send failed');
    throw err;
  }
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
