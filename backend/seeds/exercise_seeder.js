/**
 * exercise_seeder.js
 *
 * Reads the static curriculum bank and UPSERTs each entry into the
 * exercise_bank table. Safe to run repeatedly — ON CONFLICT (id) DO UPDATE
 * overwrites existing rows so the catalog stays in sync with the JSON file.
 *
 * Usage: node backend/seeds/exercise_seeder.js
 */

require('dotenv').config();
const db   = require('../config/db');
const path = require('path');
const fs   = require('fs');

const BANK_PATH = path.join(__dirname, '..', 'data', 'cpp_curriculum_bank.json');

async function seed() {
  let bank;
  try {
    const raw = fs.readFileSync(BANK_PATH, 'utf-8');
    bank = JSON.parse(raw);
  } catch (err) {
    console.error('❌ Failed to read or parse curriculum bank:', err.message);
    process.exit(1);
  }

  if (!Array.isArray(bank)) {
    console.error('❌ Curriculum bank must be a JSON array.');
    process.exit(1);
  }

  let upserted = 0;
  let skipped  = 0;

  for (const entry of bank) {
    const { id, concept, difficulty, sequence_order, title,
            description, starter_code, sample_solution, test_cases } = entry;

    // Validate required keys
    const missing = ['id','concept','difficulty','sequence_order','title','description','test_cases']
      .filter(k => entry[k] === undefined || entry[k] === null);

    if (missing.length > 0) {
      console.error(`⚠️  Skipping entry "${entry.id || '?'}" — missing keys: ${missing.join(', ')}`);
      skipped++;
      continue;
    }

    try {
      await db.query(
        `INSERT INTO exercise_bank
           (id, concept, difficulty, sequence_order, title, description,
            starter_code, sample_solution, test_cases)
         VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9)
         ON CONFLICT (id) DO UPDATE SET
           concept         = EXCLUDED.concept,
           difficulty      = EXCLUDED.difficulty,
           sequence_order  = EXCLUDED.sequence_order,
           title           = EXCLUDED.title,
           description     = EXCLUDED.description,
           starter_code    = EXCLUDED.starter_code,
           sample_solution = EXCLUDED.sample_solution,
           test_cases      = EXCLUDED.test_cases`,
        [
          id,
          concept,
          difficulty,
          sequence_order,
          title,
          description,
          starter_code || null,
          sample_solution || null,
          JSON.stringify(test_cases),
        ]
      );
      console.log(`✓ ${concept} · ${difficulty} · ${title}`);
      upserted++;
    } catch (err) {
      console.error(`❌ Failed to upsert "${entry.id}": ${err.message}`);
      skipped++;
    }
  }

  console.log(`\n✅ Seed complete — ${upserted} upserted, ${skipped} skipped.`);
  process.exit(0);
}

seed();
