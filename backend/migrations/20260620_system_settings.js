module.exports = {
  up: async (db) => {
    await db.query(`
      CREATE TABLE IF NOT EXISTS system_settings (
        key         VARCHAR(100) PRIMARY KEY,
        value       JSONB NOT NULL,
        description TEXT,
        updated_at  TIMESTAMP DEFAULT NOW(),
        updated_by  INT REFERENCES users(id) ON DELETE SET NULL
      )
    `);
    const defaults = [
      ['cds.ner_weight', 0.40, 'NER weight in CDS formula'],
      ['cds.nrs_weight', 0.35, 'NRS weight in CDS formula'],
      ['cds.nts_weight', 0.25, 'NTS weight in CDS formula'],
      ['cds.threshold_very_low', 0.20, 'Upper bound for Very Low CDS classification'],
      ['cds.threshold_low', 0.40, 'Upper bound for Low CDS classification'],
      ['cds.threshold_moderate', 0.60, 'Upper bound for Moderate CDS classification'],
      ['cds.threshold_elevated', 0.80, 'Upper bound for Elevated CDS classification'],
      ['sandbox.timeout_ms', 30000, 'Sandbox execution timeout (ms)'],
      ['sandbox.memory_mb', 256, 'Sandbox memory limit (MB)'],
    ];
    for (const [key, value, description] of defaults) {
      await db.query(
        `INSERT INTO system_settings (key, value, description)
         VALUES ($1, $2::jsonb, $3)
         ON CONFLICT (key) DO NOTHING`,
        [key, JSON.stringify(value), description]
      );
    }
  },
  down: async (db) => {
    await db.query('DROP TABLE IF EXISTS system_settings');
  },
};
