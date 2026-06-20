const db = require('../config/db');
const { AppError, codes } = require('../lib/AppError');

exports.listSettings = async (req, res, next) => {
  try {
    const r = await db.query(
      'SELECT key, value, description, updated_at FROM system_settings ORDER BY key'
    );
    res.json({ settings: r.rows });
  } catch (err) { next(err); }
};

exports.updateSettings = async (req, res, next) => {
  try {
    const { key, value } = req.body;
    if (!key) throw new AppError('key is required', 400, codes.VALIDATION);
    const r = await db.query(
      `UPDATE system_settings SET value=$1::jsonb, updated_at=NOW(), updated_by=$2
       WHERE key=$3 RETURNING key, value, updated_at`,
      [JSON.stringify(value), req.user.id, key]
    );
    if (!r.rows.length) throw new AppError('Setting not found: ' + key, 404, codes.NOT_FOUND);
    try {
      const db2 = require('../config/db');
      await db2.query(
        `INSERT INTO admin_audit_log (admin_id, action, target_type, details)
         VALUES ($1, 'update_setting', 'system_setting', $2::jsonb)`,
        [req.user.id, JSON.stringify({ key, value })]
      );
    } catch (_) {}
    res.json({ setting: r.rows[0] });
  } catch (err) { next(err); }
};
