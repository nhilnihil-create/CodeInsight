const crypto = require('crypto');
const logger = require('./logger');

const store = new Map();
const OTP_TTL_MS = 5 * 60 * 1000;
const CLEANUP_INTERVAL_MS = 60 * 1000;

function generateOtp() {
  return crypto.randomInt(100000, 999999).toString();
}

function storeOtp(email, otp) {
  const key = email.toLowerCase().trim();
  store.set(key, { otp, expiresAt: Date.now() + OTP_TTL_MS, attempts: 0 });
  logger.info({ email: key }, 'OTP stored');
}

function verifyOtp(email, otp) {
  const key = email.toLowerCase().trim();
  const entry = store.get(key);
  if (!entry) {
    return { valid: false, reason: 'No OTP requested for this email' };
  }
  if (Date.now() > entry.expiresAt) {
    store.delete(key);
    return { valid: false, reason: 'OTP has expired. Request a new one.' };
  }
  entry.attempts += 1;
  if (entry.attempts > 5) {
    store.delete(key);
    return { valid: false, reason: 'Too many failed attempts. Request a new OTP.' };
  }
  if (entry.otp !== otp) {
    return { valid: false, reason: 'Invalid OTP code' };
  }
  store.delete(key);
  return { valid: true };
}

function cleanup() {
  const now = Date.now();
  let removed = 0;
  for (const [key, entry] of store) {
    if (now > entry.expiresAt) {
      store.delete(key);
      removed++;
    }
  }
  if (removed > 0) logger.debug({ removed }, 'Expired OTPs cleaned up');
}

if (process.env.NODE_ENV !== 'test' && process.env.PLAYWRIGHT !== '1') {
  setInterval(cleanup, CLEANUP_INTERVAL_MS);
}

module.exports = { generateOtp, storeOtp, verifyOtp };
