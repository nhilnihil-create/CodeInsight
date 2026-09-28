/**
 * backend/lib/rateLimitControl.js
 *
 * Runtime kill-switch for the auth rate limiters (see routes/auth.js).
 *
 * Source of truth: system_settings key 'auth.rate_limit_disabled' (boolean),
 * toggleable from the admin Settings page (audit-logged). Reads are cached
 * for 15s so login attempts don't each cost a DB query. Fail-safe default:
 * on any error the limiters STAY ON (returns false).
 *
 * Escape hatch: DISABLE_AUTH_RATE_LIMIT=true env var forces limits off
 * without touching the database.
 */

const db = require('../config/db');

const KEY = 'auth.rate_limit_disabled';
const TTL_MS = 15000;

let cache = { value: false, expiresAt: 0 };

async function isAuthRateLimitDisabled() {
  if (process.env.DISABLE_AUTH_RATE_LIMIT === 'true') return true;
  if (Date.now() < cache.expiresAt) return cache.value;
  try {
    const r = await db.query(
      'SELECT value FROM system_settings WHERE key = $1',
      [KEY]
    );
    const disabled = r.rows[0]?.value === true;
    cache = { value: disabled, expiresAt: Date.now() + TTL_MS };
    return disabled;
  } catch {
    return false;
  }
}

function clearRateLimitCache() {
  cache = { value: false, expiresAt: 0 };
}

module.exports = { isAuthRateLimitDisabled, clearRateLimitCache, KEY };
