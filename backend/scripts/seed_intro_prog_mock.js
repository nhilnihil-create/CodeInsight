/**
 * Seed script: Section 51 "Introduction to Programming I" — 15 mock personas
 *
 * Mirrors backend/scripts/seed_bsit4h_simulation.js structure but:
 *   - Targets the DEPLOYED production DB (Neon Postgres) via DB_* env vars
 *   - Uses the 15 personas from simulation/workflows/personas.js
 *   - Exercises: 12 (Sum of N Integers), 11 (Even and Odd Numbers),
 *                13 (Largest Number in a Sequence)
 *   - All mock users use @mock.example.com emails (never @psu.edu)
 *   - Idempotent: cleans up any previous mock-scoped rows first
 *   - Computes CDS with the production engine AFTER the insert transaction
 *
 * Safety: NEVER touches section 1, never deletes by section_id alone, and
 * never touches non-mock users. The DB password must come from the
 * environment (run_seed_intro_prog.sh fetches it from the Render API).
 *
 * Run: DB_HOST=... DB_PORT=5432 DB_NAME=codeinsight DB_USER=neondb_owner \
 *      DB_PASSWORD=... node backend/scripts/seed_intro_prog_mock.js
 */
require('dotenv').config({ path: __dirname + '/../.env', quiet: true });
const { Pool } = require('pg');
const bcrypt = require('bcryptjs');
const { PERSONAS, EXERCISE_SOLUTIONS } = require('../../simulation/workflows/personas');

const pool = new Pool({
  host: process.env.DB_HOST || 'localhost',
  port: process.env.DB_PORT || '5432',
  database: process.env.DB_NAME || 'codeinsight',
  user: process.env.DB_USER || 'codeuser',
  password: process.env.DB_PASSWORD || 'codepassword123',
  // Deployed Neon Postgres requires TLS (sslmode=require). Allow opting out
  // for local dev via DB_SSL=false.
  ssl: process.env.DB_SSL === 'false' ? false : { rejectUnauthorized: false },
});

const SECTION_ID = 51;       // Introduction to Programming I
const INSTRUCTOR_ID = 1;     // instructor@psu.edu
const PASSWORD = 'password123';
const MOCK_DOMAIN = 'mock.example.com';
const EXERCISE_MAP = { sumN: 12, evenOdd: 11, findMax: 13 };
const EXERCISE_IDS = [11, 12, 13];

// ── Formatting showcase ─────────────────────────────────────────────────────
// Ensure at least one submission has each of these exact time_spent_seconds
// values (90 / 3600 / 7200) so the deployed frontend time-formatting fix is
// exercised. Key = `${personaId}:${exerciseKey}` (applied to the last attempt).
const TIME_OVERRIDES = { '10:sumN': 3600, '12:findMax': 7200, '9:evenOdd': 90 };

// ── Integrity flag rules by persona archetype ───────────────────────────────
// hardcoder → exercises 12 + 11; blank → all 3; copier/copypaste → 12;
// rapid_fire → 12; bloomer → 12.
const FLAG_RULES = {
  hardcoder:   [{ flagType: 'HARDCODING',          severity: 'high',   exerciseIds: [12, 11] }],
  blank:       [{ flagType: 'BLANK_TEMPLATE',      severity: 'high',   exerciseIds: [12, 11, 13] }],
  copypaste:   [{ flagType: 'PASSIVE_BEHAVIOR_LOG', severity: 'medium', exerciseIds: [12] }],
  copier:      [{ flagType: 'PASSIVE_BEHAVIOR_LOG', severity: 'medium', exerciseIds: [12] }],
  rapid_fire:  [{ flagType: 'BEHAVIORAL_ANOMALY',  severity: 'medium', exerciseIds: [12] }],
  bloomer:     [{ flagType: 'CODE_GROWTH_ANOMALY', severity: 'medium', exerciseIds: [12] }],
};

const FLAG_EVIDENCE = {
  HARDCODING:           { pattern: 'hardcoded outputs for literal inputs', source: 'mock-seed' },
  BLANK_TEMPLATE:       { note: 'starter template submitted unchanged', source: 'mock-seed' },
  PASSIVE_BEHAVIOR_LOG: { behavior: 'paste-heavy session', source: 'mock-seed' },
  BEHAVIORAL_ANOMALY:   { behavior: 'rapid-fire failed attempts', source: 'mock-seed' },
  CODE_GROWTH_ANOMALY:  { note: 'unusual code growth delta between attempts', source: 'mock-seed' },
};

// ── Helpers ─────────────────────────────────────────────────────────────────

// "Perfect Maria" -> "maria.perfect" -> maria.perfect.mock@example.com
function slugifyPersonaName(name) {
  const parts = name.toLowerCase().replace(/[^a-z0-9]+/g, ' ').trim().split(/\s+/);
  return parts.reverse().join('.');
}
const mockEmail = (name) => `${slugifyPersonaName(name)}.mock@${MOCK_DOMAIN}`;

// Deterministic past timestamp: 1-13 days + 0-23 h + 0-59 min ago. Never future.
function submissionTime(personaId, attemptIdx) {
  const daysAgo = 1 + ((personaId * 13 + attemptIdx * 5) % 13);
  const hoursAgo = (personaId * 7 + attemptIdx * 11) % 24;
  const minsAgo = (personaId * 17 + attemptIdx * 3) % 60;
  return new Date(Date.now() - ((daysAgo * 86400 + hoursAgo * 3600 + minsAgo * 60) * 1000));
}

// ── Main ────────────────────────────────────────────────────────────────────

async function seed() {
  const hash = bcrypt.hashSync(PASSWORD, 10);
  const client = await pool.connect();
  let released = false;
  const counts = {
    users: 0, enrollments: 0, memberships: 0, submissions: 0,
    runAttempts: 0, behavioralEvents: 0, integrityFlags: 0,
  };
  const deleted = {};

  try {
    await client.query('BEGIN');

    // ── Sanity checks ──────────────────────────────────────────────────────
    const sec = await client.query('SELECT id, name FROM sections WHERE id=$1', [SECTION_ID]);
    if (!sec.rows.length) throw new Error(`Section ${SECTION_ID} not found`);
    const exRes = await client.query(
      'SELECT id, section_id, concept_id FROM exercises WHERE id = ANY($1::int[])',
      [EXERCISE_IDS]
    );
    if (exRes.rows.length !== EXERCISE_IDS.length) {
      throw new Error('One or more exercises 11/12/13 not found');
    }
    for (const row of exRes.rows) {
      if (row.section_id !== SECTION_ID) {
        throw new Error(`Exercise ${row.id} belongs to section ${row.section_id}, not ${SECTION_ID}`);
      }
    }

    // ── Step 2: idempotent cleanup (mock-scoped ONLY) ──────────────────────
    const mockRes = await client.query(
      'SELECT id FROM users WHERE email LIKE $1', [`%@${MOCK_DOMAIN}`]
    );
    const mockIds = mockRes.rows.map((r) => r.id);
    if (mockIds.length) {
      const del = async (table, col) =>
        (await client.query(`DELETE FROM ${table} WHERE ${col} = ANY($1)`, [mockIds])).rowCount;
      for (const [table, col] of [
        ['submissions', 'student_id'],
        ['run_attempts', 'student_id'],
        ['behavioral_events', 'student_id'],
        ['integrity_flags', 'student_id'],
        ['cds_scores', 'student_id'],
        ['cds_snapshots', 'student_id'],
        ['alerts', 'student_id'],
        ['enrollments', 'student_id'],
        ['section_memberships', 'user_id'],
      ]) {
        deleted[table] = await del(table, col);
      }
      deleted.users = await del('users', 'id');
      console.log(`[cleanup] removed previous mock rows: ${JSON.stringify(deleted)}`);
    }

    // ── Step 3: users + enrollments + memberships ──────────────────────────
    const personaMap = new Map(); // persona.id -> { persona, userId, email }
    for (const p of PERSONAS) {
      const email = mockEmail(p.name);
      const { rows: [u] } = await client.query(
        `INSERT INTO users (name, email, password_hash, role, email_verified)
         VALUES ($1, $2, $3, 'student', true)
         ON CONFLICT (email) DO UPDATE SET name = EXCLUDED.name
         RETURNING id`,
        [p.name, email, hash]
      );
      counts.users++;
      personaMap.set(p.id, { persona: p, userId: u.id, email });

      const en = await client.query(
        `INSERT INTO enrollments (student_id, section_id) VALUES ($1, $2) ON CONFLICT DO NOTHING`,
        [u.id, SECTION_ID]
      );
      counts.enrollments += en.rowCount;

      const sm = await client.query(
        `INSERT INTO section_memberships (section_id, user_id, role, status)
         VALUES ($1, $2, 'student', 'active') ON CONFLICT DO NOTHING`,
        [SECTION_ID, u.id]
      );
      counts.memberships += sm.rowCount;
    }

    // ── Step 4: submissions (+ run_attempts in the same pass) ──────────────
    const attemptCounter = new Map(); // personaId -> { exerciseKey: n }
    const globalAttemptIdx = new Map(); // personaId -> n (across all attempts)
    const firstSubId = new Map();   // `${studentId}_${exerciseId}` -> submission id
    const firstSubTime = new Map(); // `${studentId}_${exerciseId}` -> Date
    const subsByExercise = { 11: 0, 12: 0, 13: 0 };

    for (const p of PERSONAS) {
      const entry = personaMap.get(p.id);
      const studentId = entry.userId;
      const perEx = attemptCounter.get(p.id) || {};

      for (const attempt of p.attempts) {
        const exerciseId = EXERCISE_MAP[attempt.exercise];
        if (!exerciseId) throw new Error(`Unknown exercise key: ${attempt.exercise}`);
        // Attempt code must come from the canonical EXERCISE_SOLUTIONS library
        const canonical = new Set(Object.values(EXERCISE_SOLUTIONS[attempt.exercise] || {}));
        if (!canonical.has(attempt.code)) {
          throw new Error(`Persona ${p.name}: code for ${attempt.exercise} not found in EXERCISE_SOLUTIONS`);
        }
        perEx[attempt.exercise] = (perEx[attempt.exercise] || 0) + 1;
        const attemptNumber = perEx[attempt.exercise];
        const localIdx = attemptNumber - 1;
        const gIdx = globalAttemptIdx.get(p.id) || 0;
        globalAttemptIdx.set(p.id, gIdx + 1);

        // time_spent: behavioral baseline, slightly less for later attempts
        let timeSpent = Math.max(
          5,
          Math.round(p.behavioral.timeSpent * (localIdx === 0 ? 1.0 : Math.max(0.6, 0.9 - (localIdx - 1) * 0.1)))
        );
        const override = TIME_OVERRIDES[`${p.id}:${attempt.exercise}`];
        if (override) timeSpent = override;

        const submittedAt = submissionTime(p.id, gIdx);
        const { rows: [sub] } = await client.query(
          `INSERT INTO submissions
             (student_id, exercise_id, code, is_correct, attempt_number, time_spent_seconds,
              is_verified, submitted_at, tab_switch_count, paste_count, idle_time_seconds)
           VALUES ($1, $2, $3, $4, $5, $6, true, $7, $8, $9, $10)
           RETURNING id, submitted_at`,
          [studentId, exerciseId, attempt.code, attempt.correct, attemptNumber, timeSpent,
           submittedAt, p.behavioral.tabSwitches, p.behavioral.pasteCount, p.behavioral.idleTime]
        );
        counts.submissions++;
        subsByExercise[exerciseId]++;

        const key = `${studentId}_${exerciseId}`;
        if (!firstSubId.has(key)) {
          firstSubId.set(key, sub.id);
          firstSubTime.set(key, sub.submitted_at);
        }

        // ── Step 5a: run_attempt (one per submission) ──────────────────────
        const errorCount = attempt.correct ? 0 : 1 + ((p.id + gIdx) % 3); // 1-3 for wrong
        await client.query(
          `INSERT INTO run_attempts (student_id, exercise_id, code, error_count, run_at)
           VALUES ($1, $2, $3, $4, $5)`,
          [studentId, exerciseId, attempt.code, errorCount,
           new Date(submittedAt.getTime() - 2 * 60000)] // run_at = submitted_at - 2 min
        );
        counts.runAttempts++;
      }
      attemptCounter.set(p.id, perEx);
    }

    // ── Step 5b: behavioral_events (tab_switch / paste only) ───────────────
    for (const p of PERSONAS) {
      const entry = personaMap.get(p.id);
      const uniqueEx = [...new Set(p.attempts.map((a) => a.exercise))].map((k) => EXERCISE_MAP[k]);
      if (!uniqueEx.length) continue;

      const events = [];
      for (let i = 0; i < Math.min(p.behavioral.tabSwitches, 60); i++) events.push({ type: 'tab_switch' });
      for (let i = 0; i < Math.min(p.behavioral.pasteCount, 60); i++) events.push({ type: 'paste' });

      let k = 0;
      for (const ev of events) {
        const exerciseId = uniqueEx[k % uniqueEx.length];
        const base = firstSubTime.get(`${entry.userId}_${exerciseId}`);
        if (!base) continue;
        // Spread across the exercise time window (deterministic, always past)
        const occurredAt = new Date(base.getTime() - (Math.floor(k / uniqueEx.length) + 1) * 60000);
        await client.query(
          `INSERT INTO behavioral_events (student_id, exercise_id, event_type, occurred_at, payload)
           VALUES ($1, $2, $3, $4, '{"count":1}')`,
          [entry.userId, exerciseId, ev.type, occurredAt]
        );
        counts.behavioralEvents++;
        k++;
      }
    }

    // ── Step 6: integrity_flags ────────────────────────────────────────────
    for (const p of PERSONAS) {
      const rules = FLAG_RULES[p.archetype];
      if (!rules) continue;
      const entry = personaMap.get(p.id);
      for (const rule of rules) {
        for (const exerciseId of rule.exerciseIds) {
          const submissionId = firstSubId.get(`${entry.userId}_${exerciseId}`);
          if (!submissionId) continue;
          const r = await client.query(
            `INSERT INTO integrity_flags
               (section_id, exercise_id, student_id, submission_id, flag_type, severity, evidence, status)
             VALUES ($1, $2, $3, $4, $5, $6, $7, 'flagged')
             ON CONFLICT (exercise_id, student_id, flag_type) DO NOTHING`,
            [SECTION_ID, exerciseId, entry.userId, submissionId, rule.flagType, rule.severity,
             JSON.stringify(FLAG_EVIDENCE[rule.flagType] || {})]
          );
          counts.integrityFlags += r.rowCount;
        }
      }
    }

    // ── Step 8: concept tags (skip if exercise_concept_tags already covers) ─
    const tagRes = await client.query(
      'SELECT count(*)::int AS n FROM exercise_concept_tags WHERE exercise_id = ANY($1::int[])',
      [EXERCISE_IDS]
    );
    if (tagRes.rows[0].n === 0) {
      const loopsRes = await client.query("SELECT id FROM concepts WHERE slug = 'loops'");
      const loopsId = loopsRes.rows[0] && loopsRes.rows[0].id;
      for (const exId of EXERCISE_IDS) {
        const ex = exRes.rows.find((r) => r.id === exId);
        await client.query(
          `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary)
           VALUES ($1, $2, 1.00, true) ON CONFLICT DO NOTHING`,
          [exId, ex.concept_id]
        );
        if (loopsId) {
          await client.query(
            `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary)
             VALUES ($1, $2, 0.50, false) ON CONFLICT DO NOTHING`,
            [exId, loopsId]
          );
        }
      }
      console.log('[concept-tags] inserted primary + Loops secondary tags for 11/12/13');
    } else {
      console.log(`[concept-tags] exercise_concept_tags already present (${tagRes.rows[0].n} rows) - skipped`);
    }

    await client.query('COMMIT');
    client.release();
    released = true;

    // ── Step 7: compute CDS with the production engine (after COMMIT) ──────
    const cdsEngine = require('../services/cdsEngine');
    const cdsResults = {};
    for (const exId of [12, 11, 13]) {
      try {
        const result = await cdsEngine.computeBatchCDS(exId, pool);
        cdsResults[exId] = { ok: true, studentsProcessed: result.studentsProcessed };
        console.log(`[cds] computeBatchCDS(${exId}) OK - ${JSON.stringify(result)}`);
      } catch (err) {
        cdsResults[exId] = { ok: false, error: err.message };
        console.error(`[cds] computeBatchCDS(${exId}) FAILED: ${err.message}`);
      }
    }

    // ── Summary ────────────────────────────────────────────────────────────
    console.log('\n=== Section 51 mock seed complete ===');
    console.log(`Section: Introduction to Programming I (id=${SECTION_ID}, instructor_id=${INSTRUCTOR_ID})`);
    console.log(`Users created (mock domain): ${counts.users}`);
    console.log(`Enrollments inserted: ${counts.enrollments}`);
    console.log(`Section memberships inserted: ${counts.memberships}`);
    console.log(`Submissions inserted: ${counts.submissions}  (ex 12 sumN: ${subsByExercise[12]}, ex 11 evenOdd: ${subsByExercise[11]}, ex 13 findMax: ${subsByExercise[13]})`);
    console.log(`Run attempts inserted: ${counts.runAttempts}`);
    console.log(`Behavioral events inserted: ${counts.behavioralEvents}`);
    console.log(`Integrity flags inserted: ${counts.integrityFlags}`);
    console.log(`CDS results: ${JSON.stringify(cdsResults)}`);
    console.log(`All mock passwords: ${PASSWORD}`);
  } catch (err) {
    await client.query('ROLLBACK').catch(() => {});
    console.error('Seed failed:', err);
    process.exitCode = 1;
  } finally {
    if (!released) client.release();
    await pool.end();
  }
}

seed();
