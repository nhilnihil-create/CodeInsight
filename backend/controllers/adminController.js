const bcrypt = require('bcryptjs');
const db     = require('../config/db');
const { AppError, codes } = require('../lib/AppError');

// =============================================================================
// USERS
// =============================================================================

exports.listUsers = async (req, res, next) => {
  try {
    const { role, search, limit = 100, offset = 0 } = req.query;
    const where = [];
    const params = [];
    if (role) { params.push(role); where.push(`role = $${params.length}`); }
    if (search) { params.push(`%${search.toLowerCase()}%`); where.push(`(LOWER(name) LIKE $${params.length} OR LOWER(email) LIKE $${params.length})`); }
    const whereSql = where.length ? `WHERE ${where.join(' AND ')}` : '';
    params.push(Math.min(Number(limit), 500)); const lIdx = params.length;
    params.push(Math.max(Number(offset), 0)); const oIdx = params.length;
    const r = await db.query(
      `SELECT id, name, email, role, created_at FROM users ${whereSql} ORDER BY created_at DESC LIMIT $${lIdx} OFFSET $${oIdx}`,
      params
    );
    const c = await db.query(`SELECT COUNT(*)::int AS total FROM users ${whereSql}`, params.slice(0, params.length - 2));
    res.json({ users: r.rows, total: c.rows[0].total });
  } catch (err) { next(err); }
};

exports.createUser = async (req, res, next) => {
  try {
    const { name, email, password, role } = req.body;
    const exists = await db.query('SELECT 1 FROM users WHERE email=$1', [email]);
    if (exists.rows.length) throw new AppError('Email already registered', 409, codes.CONFLICT);
    const hash = await bcrypt.hash(password, 10);
    const r = await db.query(
      'INSERT INTO users (name,email,password_hash,role) VALUES ($1,$2,$3,$4) RETURNING id,name,email,role,created_at',
      [name, email, hash, role]
    );
    res.status(201).json({ user: r.rows[0] });
  } catch (err) { next(err); }
};

exports.updateUser = async (req, res, next) => {
  try {
    const { id } = req.params;
    const { name, email, role } = req.body;
    const r = await db.query(
      `UPDATE users SET
         name   = COALESCE($1, name),
         email  = COALESCE($2, email),
         role   = COALESCE($3, role)
       WHERE id = $4
       RETURNING id, name, email, role, created_at`,
      [name ?? null, email ?? null, role ?? null, id]
    );
    if (!r.rows.length) throw new AppError('User not found', 404, codes.NOT_FOUND);
    res.json({ user: r.rows[0] });
  } catch (err) { next(err); }
};

exports.deleteUser = async (req, res, next) => {
  try {
    const { id } = req.params;
    if (Number(id) === req.user.id) {
      throw new AppError('Cannot delete the currently logged-in user', 400, codes.VALIDATION);
    }
    const r = await db.query('DELETE FROM users WHERE id=$1 RETURNING id', [id]);
    if (!r.rows.length) throw new AppError('User not found', 404, codes.NOT_FOUND);
    res.json({ deleted: true, id: Number(id) });
  } catch (err) { next(err); }
};

exports.resetPassword = async (req, res, next) => {
  try {
    const { id } = req.params;
    const { password } = req.body;
    const hash = await bcrypt.hash(password, 10);
    const r = await db.query(
      'UPDATE users SET password_hash = $1 WHERE id = $2 RETURNING id, name, email',
      [hash, id]
    );
    if (!r.rows.length) throw new AppError('User not found', 404, codes.NOT_FOUND);
    res.json({ message: 'Password updated', user: { id: r.rows[0].id, name: r.rows[0].name } });
  } catch (err) { next(err); }
};

// =============================================================================
// SECTIONS
// =============================================================================

exports.listSections = async (req, res, next) => {
  try {
    const r = await db.query(`
      SELECT s.id, s.name, s.course_code, s.school_year, s.term, s.semester,
             s.code, s.join_policy, s.max_size, s.created_at,
             u.id AS instructor_id, u.name AS instructor_name, u.email AS instructor_email,
             (SELECT COUNT(*)::int FROM enrollments e WHERE e.section_id = s.id) AS student_count,
             (SELECT COUNT(*)::int FROM exercises ex WHERE ex.section_id = s.id) AS exercise_count
        FROM sections s
        JOIN users u ON u.id = s.instructor_id
       ORDER BY s.created_at DESC
    `);
    res.json({ sections: r.rows });
  } catch (err) { next(err); }
};

exports.updateSection = async (req, res, next) => {
  try {
    const { id } = req.params;
    const { name, course_code, school_year, term, join_policy, max_size } = req.body;
    const r = await db.query(
      `UPDATE sections SET
         name         = COALESCE($1, name),
         course_code  = COALESCE($2, course_code),
         school_year  = COALESCE($3, school_year),
         term         = COALESCE($4, term),
         join_policy  = COALESCE($5, join_policy),
         max_size     = COALESCE($6, max_size)
       WHERE id = $7
       RETURNING *`,
      [name ?? null, course_code ?? null, school_year ?? null, term ?? null, join_policy ?? null, max_size ?? null, id]
    );
    if (!r.rows.length) throw new AppError('Section not found', 404, codes.NOT_FOUND);
    res.json({ section: r.rows[0] });
  } catch (err) { next(err); }
};

exports.deleteSection = async (req, res, next) => {
  try {
    const { id } = req.params;
    const r = await db.query('DELETE FROM sections WHERE id=$1 RETURNING id', [id]);
    if (!r.rows.length) throw new AppError('Section not found', 404, codes.NOT_FOUND);
    res.json({ deleted: true, id: Number(id) });
  } catch (err) { next(err); }
};

// =============================================================================
// CONCEPTS
// =============================================================================

exports.listConcepts = async (req, res, next) => {
  try {
    const r = await db.query(`
      SELECT c.id, c.name, c.ast_nodes,
             (SELECT COUNT(*)::int FROM exercises ex WHERE ex.concept_id = c.id) AS exercise_count
        FROM concepts c ORDER BY c.id
    `);
    res.json({ concepts: r.rows });
  } catch (err) { next(err); }
};

exports.createConcept = async (req, res, next) => {
  try {
    const { name, ast_nodes = [], knowledge_area_code, bloom_level, slug } = req.body;
    const r = await db.query(
      `INSERT INTO concepts (name, ast_nodes, knowledge_area_code, bloom_level, slug)
       VALUES ($1, $2, $3, $4, $5) RETURNING *`,
      [name, ast_nodes, knowledge_area_code || null, bloom_level || 'apply', slug || null]
    );
    res.status(201).json({ concept: r.rows[0] });
  } catch (err) { next(err); }
};

exports.deleteConcept = async (req, res, next) => {
  try {
    const { id } = req.params;
    const r = await db.query('DELETE FROM concepts WHERE id=$1 RETURNING id', [id]);
    if (!r.rows.length) throw new AppError('Concept not found', 404, codes.NOT_FOUND);
    res.json({ deleted: true, id: Number(id) });
  } catch (err) { next(err); }
};

exports.updateConcept = async (req, res, next) => {
  try {
    const { id } = req.params;
    const { name, ast_nodes, knowledge_area_code, bloom_level } = req.body;
    const r = await db.query(
      `UPDATE concepts SET name=COALESCE($1,name), ast_nodes=COALESCE($2,ast_nodes),
       knowledge_area_code=COALESCE($3,knowledge_area_code), bloom_level=COALESCE($4,bloom_level)
       WHERE id=$5 RETURNING *`,
      [name??null, ast_nodes??null, knowledge_area_code??null, bloom_level??null, id]
    );
    if (!r.rows.length) throw new AppError('Concept not found', 404, codes.NOT_FOUND);
    res.json({ concept: r.rows[0] });
  } catch (err) { next(err); }
};

// =============================================================================
// EXERCISES (admin read-only view across all instructors)
// =============================================================================

exports.listExercises = async (req, res, next) => {
  try {
    const r = await db.query(`
      SELECT ex.id, ex.title, ex.concept_id, c.name AS concept_name,
             ex.section_id, s.name AS section_name,
             ex.created_by, u.name AS creator_name, u.email AS creator_email,
             ex.is_draft, ex.closed_at, ex.deadline, ex.time_limit_minutes,
             ex.created_at,
             (SELECT COUNT(*)::int FROM submissions sub WHERE sub.exercise_id = ex.id) AS submission_count
        FROM exercises ex
        JOIN concepts c ON c.id = ex.concept_id
        LEFT JOIN sections s ON s.id = ex.section_id
        JOIN users u ON u.id = ex.created_by
       ORDER BY ex.created_at DESC
    `);
    res.json({ exercises: r.rows });
  } catch (err) { next(err); }
};

exports.toggleExercise = async (req, res, next) => {
  try {
    const { id } = req.params;
    const { closed } = req.body;
    const r = await db.query(
      `UPDATE exercises SET closed_at = $1 WHERE id = $2 RETURNING id, title, closed_at`,
      [closed ? new Date().toISOString() : null, id]
    );
    if (!r.rows.length) throw new AppError('Exercise not found', 404, codes.NOT_FOUND);
    res.json({ exercise: r.rows[0] });
  } catch (err) { next(err); }
};

// =============================================================================
// EVALUATION
// =============================================================================

exports.listEvaluation = async (req, res, next) => {
  try {
    const r = await db.query(`
      SELECT id, respondent_id, role,
             fs_1, fs_2, fs_3, fs_4,
             us_1, us_2, us_3, us_4, us_5,
             pe_1, pe_2, pe_3,
             feedback_text, created_at
        FROM evaluation_responses
       ORDER BY created_at DESC
    `);
    res.json({ responses: r.rows, total: r.rows.length });
  } catch (err) { next(err); }
};

// =============================================================================
// OVERVIEW / DASHBOARD
// =============================================================================

exports.overview = async (req, res, next) => {
  try {
    const users = await db.query(`
      SELECT role, COUNT(*)::int AS count
        FROM users GROUP BY role
    `);
    const totals = { students: 0, instructors: 0, admins: 0 };
    for (const row of users.rows) totals[row.role + 's'] = row.count;

    const sectionCount = (await db.query('SELECT COUNT(*)::int AS c FROM sections')).rows[0].c;
    const exerciseCount = (await db.query('SELECT COUNT(*)::int AS c FROM exercises')).rows[0].c;
    const submissionCount = (await db.query('SELECT COUNT(*)::int AS c FROM submissions')).rows[0].c;
    const flagCount = (await db.query(`SELECT COUNT(*)::int AS c FROM integrity_flags WHERE status='flagged'`)).rows[0].c;
    // Defensive: evaluation_responses may be absent on legacy DBs.
    // If the table is missing (42P01), default to 0 so the page still renders.
    let evalCount = 0;
    try {
      evalCount = (await db.query('SELECT COUNT(*)::int AS c FROM evaluation_responses')).rows[0].c;
    } catch (e) {
      if (e.code !== '42P01') throw e;
    }

    const flaggedCds = (await db.query(`
      SELECT classification, COUNT(*)::int AS count
        FROM cds_scores WHERE classification IN ('Moderate','High') GROUP BY classification
    `)).rows;

    res.json({
      totals,
      counts: { sections: sectionCount, exercises: exerciseCount, submissions: submissionCount, openFlags: flagCount, evaluations: evalCount },
      flagged: flaggedCds,
    });
  } catch (err) { next(err); }
};
