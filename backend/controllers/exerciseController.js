const db = require('../config/db');
const { AppError, codes } = require('../lib/AppError');
const cdsEngine = require('../services/cdsEngine');
const cdsJobQueue = require('../services/cdsJobQueue');

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

exports.create = async (req, res, next) => {
  try {
    const { title, description, concept_name, section_id,
            time_limit_minutes, test_cases, deadline, is_draft,
            track_ner, track_nrs, track_nts, auto_alert,
            starter_code, reference_solution } = req.body;

    const cRes = await db.query('SELECT id FROM concepts WHERE name=$1', [concept_name]);
    if (!cRes.rows.length) throw new AppError('Concept not found', 400, codes.VALIDATION, { field: 'concept_name' });
    const concept_id = cRes.rows[0].id;

    const r = await db.query(
      `INSERT INTO exercises
       (title, description, concept_id, section_id, created_by, time_limit_minutes,
        test_cases, deadline, is_draft, track_ner, track_nrs, track_nts, auto_alert,
        starter_code, reference_solution)
       VALUES($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15) RETURNING *`,
      [title, description, concept_id, section_id, req.user.id,
       time_limit_minutes, JSON.stringify(test_cases), deadline || null,
       is_draft, track_ner, track_nrs, track_nts, auto_alert,
       starter_code || null, reference_solution || null]
    );
    res.status(201).json(r.rows[0]);
  } catch (err) { next(err); }
};

exports.list = async (req, res, next) => {
  try {
    let r;
    if (req.user.role === 'instructor') {
      r = await db.query(
        `SELECT ex.*, c.name AS concept_name
         FROM exercises ex JOIN concepts c ON c.id=ex.concept_id
         WHERE ex.created_by=$1 ORDER BY ex.created_at DESC`,
        [req.user.id]
      );
    } else {
      r = await db.query(
        `SELECT ex.*, c.name AS concept_name
         FROM exercises ex
         JOIN concepts c ON c.id=ex.concept_id
         JOIN enrollments en ON en.section_id=ex.section_id
         WHERE en.student_id=$1 AND ex.is_draft=false
         ORDER BY ex.created_at DESC`,
        [req.user.id]
      );
    }
    res.json(r.rows);
  } catch (err) { next(err); }
};

exports.getOne = async (req, res, next) => {
  try {
    const r = await db.query(
      `SELECT ex.*, c.name AS concept_name
       FROM exercises ex JOIN concepts c ON c.id=ex.concept_id
       WHERE ex.id=$1`,
      [req.params.id]
    );
    if (!r.rows.length) throw new AppError('Exercise not found', 404, codes.NOT_FOUND);
    const ex = r.rows[0];
    if (req.user.role === 'student') {
      ex.test_cases = (ex.test_cases || []).filter(tc => !tc.hidden);
    }
    res.json(ex);
  } catch (err) { next(err); }
};

exports.update = async (req, res, next) => {
  try {
    const { title, description, time_limit_minutes, test_cases, deadline,
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
