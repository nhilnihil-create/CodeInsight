const db = require('../config/db');
const { AppError, codes } = require('../lib/AppError');
const cdsEngine = require('../services/cdsEngine');
const cdsJobQueue = require('../services/cdsJobQueue');
const conceptAnalytics = require('../services/conceptAnalytics');
const executor = require('../services/executor');
const { withTransaction } = require('../config/db');

/**
 * Helper: return an exercise row with all linked concepts (primary + secondary).
 */
async function getExerciseWithConcepts(id) {
  const [exRes, conceptsRes, tagsRes] = await Promise.all([
    db.query('SELECT * FROM exercises WHERE id = $1', [id]),
    db.query(
      `SELECT c.id, c.name FROM exercise_concepts ec
       JOIN concepts c ON c.id = ec.concept_id
       WHERE ec.exercise_id = $1`,
      [id]
    ),
    db.query(
      `SELECT ect.concept_id, c.name AS concept_name, ect.weight, ect.is_primary
       FROM exercise_concept_tags ect
       JOIN concepts c ON c.id = ect.concept_id
       WHERE ect.exercise_id = $1
       ORDER BY ect.is_primary DESC`,
      [id]
    ),
  ]);
  if (!exRes.rows.length) return null;
  const ex = exRes.rows[0];
  ex.concepts = conceptsRes.rows;
  ex.concept_names = conceptsRes.rows.map(c => c.name);
  // Edit-load tags (primary first). Legacy exercises without tags → [].
  ex.concept_tags = tagsRes.rows;
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
  const { title, description, concept_name, section_id,
          time_limit_minutes, test_cases, deadline, is_draft,
          track_ner, track_nrs, track_nts, auto_alert,
          starter_code, reference_solution, concept_ids, concept_tags } = req.body;

  try {
    const row = await withTransaction(async (client) => {
      const cRes = await client.query('SELECT id FROM concepts WHERE name=$1', [concept_name]);
      if (!cRes.rows.length) throw new AppError('Concept not found', 400, codes.VALIDATION, { field: 'concept_name' });
      const concept_id = cRes.rows[0].id;

      const r = await client.query(
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

      const exerciseId = r.rows[0].id;

      // Legacy secondary concepts (array of names) → junction table
      if (concept_ids && concept_ids.length > 0) {
        const conceptRows = await client.query('SELECT id, name FROM concepts WHERE name = ANY($1)', [concept_ids]);
        for (const c of conceptRows.rows) {
          if (c.id === concept_id) continue;
          await client.query(
            `INSERT INTO exercise_concepts (exercise_id, concept_id) VALUES ($1, $2) ON CONFLICT DO NOTHING`,
            [exerciseId, c.id]
          );
        }
      }

      // New multi-tag rows (weighted, primary flag). Primary = the new concept (Q2).
      if (Array.isArray(concept_tags)) {
        for (const tag of concept_tags) {
          const tagConceptId = tag.concept_id || tag.id;
          if (!tagConceptId) continue;
          await client.query(
            `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary)
             VALUES ($1, $2, $3, $4)
             ON CONFLICT (exercise_id, concept_id) DO UPDATE SET weight = $3, is_primary = $4`,
            [exerciseId, tagConceptId, tag.weight || 1.0, tag.is_primary || false]
          );
        }
      }

      // Always ensure primary concept is in the junction table and the tags table
      await client.query(
        `INSERT INTO exercise_concepts (exercise_id, concept_id) VALUES ($1, $2) ON CONFLICT DO NOTHING`,
        [exerciseId, concept_id]
      );
      await client.query(
        `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary)
         VALUES ($1, $2, 1.0, true)
         ON CONFLICT (exercise_id, concept_id) DO UPDATE SET is_primary = true`,
        [exerciseId, concept_id]
      );

      return r.rows[0];
    });

    res.status(201).json(row);
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

exports.listDrafts = async (req, res, next) => {
  try {
    if (req.user.role !== 'instructor') {
      throw new AppError('Instructor access required', 403, codes.FORBIDDEN);
    }

    const mainRes = await db.query(
      `SELECT ex.*,
              c.name AS concept_name,
              COALESCE(
                ARRAY_AGG(DISTINCT sc.name) FILTER (WHERE sc.name IS NOT NULL),
                ARRAY[]::TEXT[]
              ) AS secondary_concepts
       FROM exercises ex
       JOIN concepts c ON c.id = ex.concept_id
       LEFT JOIN exercise_concepts ec ON ec.exercise_id = ex.id
       LEFT JOIN concepts sc ON sc.id = ec.concept_id AND sc.id != ex.concept_id
       WHERE ex.created_by = $1
         AND ex.is_draft = true
       GROUP BY ex.id, c.id
       ORDER BY ex.created_at DESC`,
      [req.user.id]
    );

    const rows = mainRes.rows;

    if (rows.length === 0) {
      return res.json(rows);
    }

    const exerciseIds = rows.map(r => r.id);
    const tagsRes = await db.query(
      `SELECT ect.exercise_id, ect.concept_id, c.name AS concept_name, ect.weight, ect.is_primary
       FROM exercise_concept_tags ect
       JOIN concepts c ON c.id = ect.concept_id
       WHERE ect.exercise_id = ANY($1)`,
      [exerciseIds]
    );

    const tagsByExercise = {};
    for (const tag of tagsRes.rows) {
      if (!tagsByExercise[tag.exercise_id]) tagsByExercise[tag.exercise_id] = [];
      tagsByExercise[tag.exercise_id].push({
        concept_id: tag.concept_id,
        concept_name: tag.concept_name,
        weight: tag.weight,
        is_primary: tag.is_primary,
      });
    }

    for (const row of rows) {
      row.concept_tags = tagsByExercise[row.id] || [];
    }

    res.json(rows);
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
  const { title, description, concept_name, concept_tags, time_limit_minutes, test_cases, deadline,
          is_draft, track_ner, track_nrs, track_nts, auto_alert, starter_code } = req.body;

  try {
    const result = await withTransaction(async (client) => {
      // Read current row for auth + tag-change detection
      const cur = await client.query(
        'SELECT id, concept_id, section_id, created_by FROM exercises WHERE id = $1',
        [req.params.id]
      );
      if (!cur.rows.length) throw new AppError('Exercise not found', 404, codes.NOT_FOUND);
      const current = cur.rows[0];
      if (current.created_by !== req.user.id) {
        throw new AppError('Exercise not found or not authorized', 404, codes.NOT_FOUND);
      }
      const currentConceptId = current.concept_id;

      // Resolve the primary concept id when concept_name is provided (legacy clients).
      // Empty/absent concept_name leaves the primary untouched.
      let newPrimaryId = null;
      if (concept_name !== undefined && concept_name !== null && String(concept_name).trim() !== '') {
        const cRes = await client.query('SELECT id FROM concepts WHERE name = $1', [String(concept_name).trim()]);
        if (!cRes.rows.length) throw new AppError('Concept not found', 400, codes.VALIDATION, { field: 'concept_name' });
        newPrimaryId = cRes.rows[0].id;
      }

      let tagsChanged = false;
      let primaryToSet = null; // concept_id to write, only when it changes

      // Full replace when concept_tags is sent (including empty [] to clear secondaries)
      if (Array.isArray(concept_tags)) {
        for (const tag of concept_tags) {
          if (!tag || (tag.concept_id === undefined && tag.id === undefined)) {
            throw new AppError('Invalid concept tag: each tag requires a concept_id', 400, codes.VALIDATION);
          }
        }
        await client.query('DELETE FROM exercise_concept_tags WHERE exercise_id = $1', [req.params.id]);
        for (const tag of concept_tags) {
          const tagConceptId = tag.concept_id || tag.id;
          await client.query(
            `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary)
             VALUES ($1, $2, $3, $4)`,
            [req.params.id, tagConceptId, tag.weight || 1.0, tag.is_primary || false]
          );
        }
        // Effective primary: explicit concept_name wins, else the primary/first tag.
        const primaryTag = concept_tags.find(t => t.is_primary) || concept_tags[0];
        const primaryFromTags = primaryTag ? Number(primaryTag.concept_id || primaryTag.id) : currentConceptId;
        const primaryId = newPrimaryId !== null ? Number(newPrimaryId) : primaryFromTags;
        if (primaryId !== Number(currentConceptId)) primaryToSet = primaryId;
        // Upsert the primary so exactly one primary always exists
        await client.query(
          `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary)
           VALUES ($1, $2, 1.0, true)
           ON CONFLICT (exercise_id, concept_id) DO UPDATE SET weight = 1.0, is_primary = true`,
          [req.params.id, primaryId]
        );
        // Sync legacy junction (mirror create): primary + all tag concept ids
        await client.query('DELETE FROM exercise_concepts WHERE exercise_id = $1', [req.params.id]);
        await client.query(
          `INSERT INTO exercise_concepts (exercise_id, concept_id) VALUES ($1, $2) ON CONFLICT DO NOTHING`,
          [req.params.id, primaryId]
        );
        const tagIds = [...new Set(concept_tags.map(t => t.concept_id || t.id))];
        for (const tid of tagIds) {
          if (Number(tid) === Number(primaryId)) continue;
          await client.query(
            `INSERT INTO exercise_concepts (exercise_id, concept_id) VALUES ($1, $2) ON CONFLICT DO NOTHING`,
            [req.params.id, tid]
          );
        }
        tagsChanged = true;
      } else if (newPrimaryId !== null && newPrimaryId !== currentConceptId) {
        // Legacy primary swap (Q2 rule): replace the old primary tag with the new one
        await client.query(
          'DELETE FROM exercise_concept_tags WHERE exercise_id = $1 AND is_primary = true',
          [req.params.id]
        );
        await client.query(
          `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary)
           VALUES ($1, $2, 1.0, true)
           ON CONFLICT (exercise_id, concept_id) DO UPDATE SET weight = 1.0, is_primary = true`,
          [req.params.id, newPrimaryId]
        );
        await client.query(
          `INSERT INTO exercise_concepts (exercise_id, concept_id) VALUES ($1, $2) ON CONFLICT DO NOTHING`,
          [req.params.id, newPrimaryId]
        );
        primaryToSet = newPrimaryId;
        tagsChanged = true;
      }

      // Build dynamic update. NOTE: exercises has no concept_name column — the
      // legacy `concept_name` field maps to concept_id only (see above).
      const sets = [];
      const params = [];
      const addSet = (col, val) => {
        if (val === undefined) return;
        params.push(val);
        sets.push(`${col} = $${params.length}`);
      };
      addSet('title', title);
      addSet('description', description);
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
      if (primaryToSet !== null) {
        addSet('concept_id', primaryToSet);
      }
      if (sets.length === 0 && !tagsChanged) {
        throw new AppError('No fields to update', 400, codes.VALIDATION);
      }

      let row;
      if (sets.length === 0) {
        // Tags-only update: the tags were already replaced in-transaction above
        // and there are no column changes, so skip the UPDATE entirely (an empty
        // SET list would be a Postgres syntax error) and return the current row.
        const fullRes = await client.query(
          'SELECT * FROM exercises WHERE id = $1',
          [req.params.id]
        );
        row = fullRes.rows[0];
      } else {
        params.push(req.params.id);
        params.push(req.user.id);
        const r = await client.query(
          `UPDATE exercises SET ${sets.join(', ')}
           WHERE id=$${params.length - 1} AND created_by=$${params.length}
           RETURNING *`,
          params
        );
        if (!r.rows.length) throw new AppError('Exercise not found or not authorized', 404, codes.NOT_FOUND);
        row = r.rows[0];
      }

      return { row, tagsChanged };
    });

    // Fire-and-forget recompute after commit (D1): CDS queue job + aggregate metrics
    if (result.tagsChanged) {
      cdsJobQueue.enqueueCdsComputation(req.params.id).catch(err =>
        console.error('[ExerciseUpdate] Failed to enqueue CDS computation:', err.message)
      );
      conceptAnalytics.computeAllMetrics(result.row.section_id).catch(err =>
        console.error('[ExerciseUpdate] Failed to recompute concept metrics:', err.message)
      );
    }

    res.json(result.row);
  } catch (err) {
    // Map FK / unique constraint violations from tag inserts to a clean 400
    if (err && (err.code === '23503' || err.code === '23505')) {
      return next(new AppError('Invalid concept reference', 400, codes.VALIDATION));
    }
    next(err);
  }
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

        await client.query(
          `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary)
           VALUES ($1, $2, 1.0, true)
           ON CONFLICT (exercise_id, concept_id) DO UPDATE SET is_primary = true`,
          [r.rows[0].id, concept_id]
        );
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
