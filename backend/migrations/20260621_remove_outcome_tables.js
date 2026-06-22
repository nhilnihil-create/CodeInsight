module.exports = {
  up: async (db) => {
    await db.query('DROP TABLE IF EXISTS section_active_outcomes CASCADE');
    await db.query('DROP TABLE IF EXISTS outcome_concept_map CASCADE');
    await db.query('DROP TABLE IF EXISTS learning_outcomes CASCADE');
  },
  down: async (db) => {
    await db.query(`
      CREATE TABLE learning_outcomes (
        id SERIAL PRIMARY KEY,
        name VARCHAR(200) NOT NULL,
        description TEXT,
        bloom_level VARCHAR(20) DEFAULT 'apply',
        created_by INT REFERENCES users(id),
        created_at TIMESTAMPTZ DEFAULT NOW()
      )
    `);
    await db.query(`
      CREATE TABLE outcome_concept_map (
        outcome_id INT NOT NULL REFERENCES learning_outcomes(id) ON DELETE CASCADE,
        concept_id INT NOT NULL REFERENCES concepts(id) ON DELETE CASCADE,
        weight DECIMAL(3,2) DEFAULT 1.0,
        PRIMARY KEY (outcome_id, concept_id)
      )
    `);
    await db.query(`
      CREATE TABLE section_active_outcomes (
        section_id INT NOT NULL REFERENCES sections(id) ON DELETE CASCADE,
        outcome_id INT NOT NULL REFERENCES learning_outcomes(id) ON DELETE CASCADE,
        PRIMARY KEY (section_id, outcome_id)
      )
    `);
  },
};
