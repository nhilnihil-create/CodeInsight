const db = require('../config/db');
const { AppError, codes } = require('../lib/AppError');
const cdsEngine = require('../services/cdsEngine');
const cdsJobQueue = require('../services/cdsJobQueue');
const executor = require('../services/executor');
const { withTransaction } = require('../config/db');

/**
 * Helper: return an exercise row with all linked concepts (primary + secondary).
 */
async function getExerciseWithConcepts(id) {
  const [exRes, conceptsRes] = await Promise.all([
    db.query('SELECT * FROM exercises WHERE id = $1', [id]),
    db.query(
      `SELECT c.id, c.name FROM exercise_concepts ec
       JOIN concepts c ON c.id = ec.concept_id
       WHERE ec.exercise_id = $1`,
      [id]
    ),
  ]);
  if (!exRes.rows.length) return null;
  const ex = exRes.rows[0];
  ex.concepts = conceptsRes.rows;
  ex.concept_names = conceptsRes.rows.map(c => c.name);
  return ex;
}

const getExerciseDetails = async (id) => {
  try {
    const result = await db.query('SELECT closed_at FROM exercises WHERE id = $1', [id]);
    return result.rows[0];
  } catch (err) {
    return null;
  }
};

exports.getConcepts = async (_req, res, next) => {
  try {
    const r = await db.query('SELECT * FROM concepts ORDER BY id');
    res.json(r.rows);
  } catch (err) { next(err); }
};

/**
 * POST /api/exercises/validate
 * Dry-run a reference solution against all test cases in Docker.
 * Returns per-test-case pass/fail with deterministic comparison.
 */
exports.validate = async (req, res, next) => {
  try {
    const { reference_solution, test_cases, time_limit_minutes } = req.body;
    const effectiveTime = time_limit_minutes || 45;

    // Execute reference solution against all test cases (maskHidden=false for full instructor visibility)
    const results = await executor.runAgainstTestCases(
      reference_solution,
      test_cases,
      effectiveTime,
      false
    );

    const validated = results.every(r => r.passed);

    res.json({
      validated,
      results: results.map(r => ({
        passed: r.passed,
        status: r.status,
        validationType: r.validationType,
        actual: r.actual,
        expected: r.expected,
        error: r.error,
      })),
    });
  } catch (err) { next(err); }
};

exports.create = async (req, res, next) => {
  try {
    const { title, description, concept_name, section_id,
            time_limit_minutes, test_cases, deadline, is_draft,
            track_ner, track_nrs, track_nts, auto_alert,
            starter_code, reference_solution, concept_ids } = req.body;

    const cRes = await db.query('SELECT id FROM concepts WHERE name=$1', [concept_name]);
    if (!cRes.rows.length) throw new AppError('Concept not found', 400, codes.VALIDATION, { field: 'concept_name' });
    const concept_id = cRes.rows[0].id;

    const r = await db.query(
      `INSERT INTO exercises
       (title, description, concept_id, section_id, created_by, time_limit_minutes,
        test_cases, deadline, is_draft, track_ner, track_nrs, track_nts, auto_alert,
        starter_code, reference_solution, is_validated)
       VALUES($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15, $16) RETURNING *`,
      [title, description, concept_id, section_id, req.user.id,
       time_limit_minutes || 45, JSON.stringify(test_cases), deadline || null,
       is_draft, track_ner, track_nrs, track_nts, auto_alert,
       starter_code || null, reference_solution || null,
       false]
    );

    // Insert secondary concepts into exercise_concepts junction table
    const exerciseId = r.rows[0].id;

    // Support both legacy concept_ids (array of names) and new concept_tags (array of {id, weight, is_primary})
    if (concept_ids && concept_ids.length > 0) {
      const conceptRows = await db.query('SELECT id, name FROM concepts WHERE name = ANY($1)', [concept_ids]);
      const values = conceptRows.rows.map((c, i) => `($1, ${concept_id !== c.id ? `$${i + 2}` : 'NULL'})`).filter(v => !v.includes('NULL'));
      const params = [exerciseId, ...conceptRows.rows.map(c => c.id)];
      if (params.length > 1) {
        await db.query(
          `INSERT INTO exercise_concepts (exercise_id, concept_id)
           SELECT $1, unnest(ARRAY[${params.slice(1).map((_, i) => `$${i + 2}`).join(',')}])
           ON CONFLICT DO NOTHING`,
          params
        );
      }
    }

    // NEW: Support concept_tags for multi-tag with weights
    const { concept_tags } = req.body;
    if (concept_tags && Array.isArray(concept_tags) && concept_tags.length > 0) {
      for (const tag of concept_tags) {
        const tagConceptId = tag.concept_id || tag.id;
        if (tagConceptId) {
          await db.query(
            `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary)
             VALUES ($1, $2, $3, $4) ON CONFLICT (exercise_id, concept_id) DO UPDATE SET weight = $3, is_primary = $4`,
            [exerciseId, tagConceptId, tag.weight || 1.0, tag.is_primary || false]
          );
        }
      }
    }

    // Always ensure primary concept is in the junction table
    await db.query(
      `INSERT INTO exercise_concepts (exercise_id, concept_id) VALUES ($1, $2) ON CONFLICT DO NOTHING`,
      [exerciseId, concept_id]
    );
    // And in exercise_concept_tags
    await db.query(
      `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary)
       VALUES ($1, $2, 1.0, true) ON CONFLICT (exercise_id, concept_id) DO UPDATE SET is_primary = true`,
      [exerciseId, concept_id]
    );

    res.status(201).json(r.rows[0]);
  } catch (err) { next(err); }
};

exports.list = async (req, res, next) => {
  try {
    let r;
    if (req.user.role === 'instructor') {
      r = await db.query(
        `SELECT ex.*, c.name AS concept_name,
                COALESCE(ARRAY_AGG(DISTINCT sc.name) FILTER (WHERE sc.name IS NOT NULL), ARRAY[]::TEXT[]) AS secondary_concepts
         FROM exercises ex JOIN concepts c ON c.id=ex.concept_id
         LEFT JOIN exercise_concepts ec ON ec.exercise_id=ex.id
         LEFT JOIN concepts sc ON sc.id=ec.concept_id AND sc.id != ex.concept_id
         WHERE ex.created_by=$1 GROUP BY ex.id, c.id ORDER BY ex.created_at DESC`,
        [req.user.id]
      );
    } else {
      r = await db.query(
        `SELECT ex.*, c.name AS concept_name,
                COALESCE(ARRAY_AGG(DISTINCT sc.name) FILTER (WHERE sc.name IS NOT NULL), ARRAY[]::TEXT[]) AS secondary_concepts
         FROM exercises ex
         JOIN concepts c ON c.id=ex.concept_id
         JOIN enrollments en ON en.section_id=ex.section_id
         LEFT JOIN exercise_concepts ec ON ec.exercise_id=ex.id
         LEFT JOIN concepts sc ON sc.id=ec.concept_id AND sc.id != ex.concept_id
         WHERE en.student_id=$1 AND ex.is_draft=false
         GROUP BY ex.id, c.id ORDER BY ex.created_at DESC`,
        [req.user.id]
      );
      // Filter hidden test cases for students
      r.rows = r.rows.map(ex => ({
        ...ex,
        test_cases: (ex.test_cases || []).filter(tc => !executor.isHiddenTestCase(tc)),
      }));
    }
    res.json(r.rows);
  } catch (err) { next(err); }
};

exports.getOne = async (req, res, next) => {
  try {
    const exercise = await getExerciseWithConcepts(req.params.id);
    if (!exercise) {
      throw new AppError('Exercise not found', 404, codes.NOT_FOUND);
    }
    if (req.user.role === 'student') {
      exercise.test_cases = (exercise.test_cases || []).filter(tc =>
        !executor.isHiddenTestCase(tc)
      );
    }
    res.json(exercise);
  } catch (err) { next(err); }
};

exports.update = async (req, res, next) => {
  try {
    const { title, description, concept_name, time_limit_minutes, test_cases, deadline,
            is_draft, track_ner, track_nrs, track_nts, auto_alert, starter_code } = req.body;

    // Build dynamic update
    const sets = [];
    const params = [];
    const addSet = (col, val) => {
      if (val === undefined) return;
      params.push(val);
      sets.push(`${col} = $${params.length}`);
    };
    addSet('title', title);
    addSet('description', description);
    addSet('concept_name', concept_name);
    addSet('time_limit_minutes', time_limit_minutes);
    if (test_cases !== undefined) {
      params.push(JSON.stringify(test_cases));
      sets.push(`test_cases = $${params.length}`);
    }
    addSet('deadline', deadline);
    addSet('is_draft', is_draft);
    addSet('track_ner', track_ner);
    addSet('track_nrs', track_nrs);
    addSet('track_nts', track_nts);
    addSet('auto_alert', auto_alert);
    addSet('starter_code', starter_code);
    if (sets.length === 0) {
      throw new AppError('No fields to update', 400, codes.VALIDATION);
    }
    params.push(req.params.id);
    params.push(req.user.id);
    const r = await db.query(
      `UPDATE exercises SET ${sets.join(', ')}
       WHERE id=$${params.length - 1} AND created_by=$${params.length}
       RETURNING *`,
      params
    );
    if (!r.rows.length) throw new AppError('Exercise not found or not authorized', 404, codes.NOT_FOUND);
    res.json(r.rows[0]);
  } catch (err) { next(err); }
};

exports.close = async (req, res, next) => {
  try {
    const exercise = await getExerciseDetails(req.params.id);
    if (!exercise) throw new AppError('Exercise not found', 404, codes.NOT_FOUND);
    if (exercise.closed_at) {
      throw new AppError('Exercise already closed', 400, codes.VALIDATION);
    }
    const r = await db.query(
      'UPDATE exercises SET closed_at=NOW() WHERE id=$1 AND created_by=$2 RETURNING *',
      [req.params.id, req.user.id]
    );
    if (!r.rows.length) throw new AppError('Exercise not found or not authorized', 404, codes.NOT_FOUND);
    // Trigger batch CDS computation
    await cdsJobQueue.enqueueCdsComputation(req.params.id);
    res.json({ message: 'Exercise closed. CDS computed for all students.', exercise: r.rows[0] });
  } catch (err) { next(err); }
};

exports.reopen = async (req, res, next) => {
  try {
    const r = await db.query(
      'UPDATE exercises SET closed_at=NULL WHERE id=$1 AND created_by=$2 RETURNING *',
      [req.params.id, req.user.id]
    );
    if (!r.rows.length) throw new AppError('Exercise not found or not authorized', 404, codes.NOT_FOUND);
    res.json({ message: 'Exercise reopened.', exercise: r.rows[0] });
  } catch (err) { next(err); }
};

// ── Exercise Bank (read-only catalog) ──────────────────────────────────────

exports.getBank = async (req, res, next) => {
  try {
    const { concept, difficulty } = req.query;
    let sql = 'SELECT * FROM exercise_bank WHERE 1=1';
    const params = [];

    if (concept) {
      params.push(concept);
      sql += ` AND concept = $${params.length}`;
    }
    if (difficulty) {
      params.push(difficulty);
      sql += ` AND difficulty = $${params.length}`;
    }
    sql += ' ORDER BY concept, sequence_order';

    const r = params.length > 0
      ? await db.query(sql, params)
      : await db.query(sql);
    res.json(r.rows);
  } catch (err) { next(err); }
};

exports.getBankOne = async (req, res, next) => {
  try {
    const r = await db.query(
      'SELECT * FROM exercise_bank WHERE id = $1',
      [req.params.id]
    );
    if (!r.rows.length) {
      throw new AppError('Bank entry not found', 404, codes.NOT_FOUND);
    }
    res.json(r.rows[0]);
  } catch (err) { next(err); }
};

// ── Bulk Publish from exercise_bank ─────────────────────────────────────────

exports.bulkPublish = async (req, res, next) => {
  try {
    const { section_id, bank_ids, deadline, time_limit_overrides } = req.body;

    // Fetch all bank entries in one query
    const bankRes = await db.query(
      'SELECT * FROM exercise_bank WHERE id = ANY($1)',
      [bank_ids]
    );

    if (bankRes.rows.length !== bank_ids.length) {
      const foundIds = new Set(bankRes.rows.map(r => r.id));
      const missing = bank_ids.filter(id => !foundIds.has(id));
      throw new AppError(
        `Bank entries not found for ${missing.length} ID(s)`,
        400,
        codes.VALIDATION,
        { missing_ids: missing }
      );
    }

    // Resolve concept names to IDs in one query
    const conceptNames = [...new Set(bankRes.rows.map(r => r.concept))];
    const conceptRows = await db.query(
      'SELECT id, name FROM concepts WHERE name = ANY($1)',
      [conceptNames]
    );
    const conceptMap = {};
    conceptRows.rows.forEach(r => { conceptMap[r.name] = r.id; });

    // Verify all concepts exist
    for (const name of conceptNames) {
      if (!conceptMap[name]) {
        throw new AppError(
          `Concept "${name}" not found in concepts table`,
          400,
          codes.VALIDATION,
          { concept_name: name }
        );
      }
    }

    // Insert all exercises in a single transaction — any failure rolls back everything
    const created = await withTransaction(async (client) => {
      const inserted = [];
      for (const bank of bankRes.rows) {
        const concept_id = conceptMap[bank.concept];
        // time_limit_overrides may be in seconds (>600) or minutes (≤600).
        // Convert seconds → minutes for storage in time_limit_minutes column.
        const rawLimit = time_limit_overrides?.[bank.id];
        const timeLimit = rawLimit
          ? (rawLimit > 600 ? Math.round(rawLimit / 60) : rawLimit)
          : bank.sequence_order === 1 ? 30
          : bank.sequence_order === 2 ? 45
          : 60;

        const r = await client.query(
          `INSERT INTO exercises
            (title, description, concept_id, section_id, created_by, time_limit_minutes,
             test_cases, deadline, is_draft, track_ner, track_nrs, track_nts, auto_alert,
             starter_code, reference_solution)
           VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15)
           RETURNING id, title, concept_id, section_id`,
          [
            bank.title,
            bank.description,
            concept_id,
            section_id,
            req.user.id,
            timeLimit,
            JSON.stringify(bank.test_cases),
            deadline || null,
            false,  // is_draft
            true,   // track_ner
            true,   // track_nrs
            true,   // track_nts
            true,   // auto_alert
            bank.starter_code || null,
            bank.sample_solution || null,
          ]
        );
        inserted.push(r.rows[0]);
      }
      return inserted;
    });

    res.status(201).json({
      message: `${created.length} exercise(s) published`,
      exercises: created,
    });
  } catch (err) { next(err); }
};

exports.remove = async (req, res, next) => {
  try {
    const r = await db.query(
      'DELETE FROM exercises WHERE id=$1 AND created_by=$2 RETURNING *',
      [req.params.id, req.user.id]
    );
    if (!r.rows.length) throw new AppError('Exercise not found or not authorized', 404, codes.NOT_FOUND);
    res.json({ message: 'Exercise deleted successfully', exercise: r.rows[0] });
  } catch (err) { next(err); }
};

// ── Databank: Combined Bank + Seeded Exercises ──────────────────────────────

/**
 * GET /api/exercises/databank
 * Returns both exercise_bank templates AND seeded exercises from ITP1 section.
 * Used by ExerciseWorkspace databank browser.
 */
exports.getDatabank = async (req, res, next) => {
  try {
    // Get exercise_bank items
    const bankRes = await db.query(
      `SELECT id, title, description, concept, sequence_order,
              test_cases, starter_code, sample_solution,
              'bank' AS source
       FROM exercise_bank
       ORDER BY sequence_order, title`
    );

    // Get seeded ITP1 exercises (section 51)
    const itpiRes = await db.query(
      `SELECT e.id, e.title, e.description, c.name AS concept,
              e.reference_solution AS sample_solution,
              e.starter_code, e.test_cases,
              'seeded' AS source
       FROM exercises e
       JOIN concepts c ON c.id = e.concept_id
       WHERE e.section_id = 51
         AND e.is_draft = false
       ORDER BY e.created_at DESC`
    );

    // Merge and format
    const bankItems = bankRes.rows.map(r => ({
      id: String(r.id),
      title: r.title,
      description: r.description,
      concept: r.concept,
      test_cases: r.test_cases,
      starter_code: r.starter_code,
      sample_solution: r.sample_solution,
      source: 'bank',
      sequence_order: r.sequence_order,
    }));

    const seededItems = itpiRes.rows.map(r => ({
      id: String(r.id),
      title: r.title,
      description: r.description,
      concept: r.concept,
      test_cases: r.test_cases,
      starter_code: r.starter_code,
      sample_solution: r.sample_solution,
      source: 'seeded',
      sequence_order: 0,
    }));

    res.json([...bankItems, ...seededItems]);
  } catch (err) { next(err); }
};
