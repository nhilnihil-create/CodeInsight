const crypto = require('crypto');
const db = require('../config/db');
const logger = require('./logger');

const OTP_TTL_MS = 5 * 60 * 1000;

function generateOtp() {
  return crypto.randomInt(100000, 999999).toString();
}

async function storeOtp(email, otp) {
  const key = email.toLowerCase().trim();
  const expiresAt = new Date(Date.now() + OTP_TTL_MS);
  await db.query(
    `INSERT INTO otp_codes (email, otp, expires_at, attempts)
     VALUES ($1, $2, $3, 0)
     ON CONFLICT (email) DO UPDATE SET otp = $2, expires_at = $3, attempts = 0`,
    [key, otp, expiresAt]
  );
  logger.info({ email: key }, 'OTP stored in database');
}

async function verifyOtp(email, otp) {
  const key = email.toLowerCase().trim();
  const result = await db.query(
    'SELECT otp, expires_at, attempts FROM otp_codes WHERE email = $1',
    [key]
  );
  const entry = result.rows[0];
  if (!entry) {
    return { valid: false, reason: 'No OTP requested for this email' };
  }
  if (Date.now() > new Date(entry.expires_at).getTime()) {
    await db.query('DELETE FROM otp_codes WHERE email = $1', [key]);
    return { valid: false, reason: 'OTP has expired. Request a new one.' };
  }
  if (entry.attempts >= 5) {
    await db.query('DELETE FROM otp_codes WHERE email = $1', [key]);
    return { valid: false, reason: 'Too many failed attempts. Request a new OTP.' };
  }
  await db.query('UPDATE otp_codes SET attempts = attempts + 1 WHERE email = $1', [key]);
  if (entry.otp !== otp) {
    return { valid: false, reason: 'Invalid OTP code' };
  }
  await db.query('DELETE FROM otp_codes WHERE email = $1', [key]);
  return { valid: true };
}

module.exports = { generateOtp, storeOtp, verifyOtp };
