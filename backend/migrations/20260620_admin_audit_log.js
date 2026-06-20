module.exports = {
  up: async (db) => {
    await db.query(`
      CREATE TABLE IF NOT EXISTS admin_audit_log (
        id          SERIAL PRIMARY KEY,
        admin_id    INT NOT NULL REFERENCES users(id) ON DELETE CASCADE,
        action      VARCHAR(100) NOT NULL,
        target_type VARCHAR(50) NOT NULL,
        target_id   INT,
        details     JSONB DEFAULT '{}',
        created_at  TIMESTAMP DEFAULT NOW()
      )
    `);
    await db.query('CREATE INDEX IF NOT EXISTS idx_admin_audit_log_admin ON admin_audit_log(admin_id)');
    await db.query('CREATE INDEX IF NOT EXISTS idx_admin_audit_log_created ON admin_audit_log(created_at)');
  },
  down: async (db) => {
    await db.query('DROP TABLE IF EXISTS admin_audit_log');
  },
};
