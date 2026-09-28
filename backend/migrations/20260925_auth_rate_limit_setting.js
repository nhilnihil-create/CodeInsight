/**
 * Adds the auth rate-limit kill-switch setting.
 *
 * Key: auth.rate_limit_disabled (boolean, default false)
 * When true, the auth rate limiters (login, Google, register, OTP verify,
 * password reset) are skipped — intended for demo/defense windows with
 * frequent sign-ins. Toggle it from the admin Settings page; every change
 * is audit-logged. Idempotent: safe to re-run (insert-if-missing).
 */
module.exports = {
  up: async (db) => {
    await db.query(
      `INSERT INTO system_settings (key, value, description)
       VALUES (
         'auth.rate_limit_disabled',
         'false'::jsonb,
         'Kill-switch: when true, auth rate limiters (login, Google, register, password reset) are skipped. Enable only for demo/defense windows, then turn back off.'
       )
       ON CONFLICT (key) DO NOTHING`
    );
  },
  down: async (db) => {
    await db.query(
      `DELETE FROM system_settings WHERE key = 'auth.rate_limit_disabled'`
    );
  },
};
