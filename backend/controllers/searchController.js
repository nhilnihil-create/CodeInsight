const db = require('../config/db');
const { AppError, codes } = require('../lib/AppError');

/**
 * SearchController — Exercise Explorer API.
 *
 * Full-text search + concept filtering on exercises.
 * Uses the search_vector tsvector column for PostgreSQL full-text search.
 * Queries the exercise_concepts junction table for secondary concept tags.
 *
 * Primary concept = exercises.concept_id (used by CDS/analytics)
 * Secondary concepts = exercise_concepts (used for search/filter)
 */

/**
 * GET /api/search/exercises?q=&concept=&section_id=
 * Full-text search across exercise titles/descriptions,
 * filterable by concept name and section.
 */
exports.searchExercises = async (req, res, next) => {
  try {
    const { q, concept, section_id } = req.query;

    const params = [];
    let whereClauses = ['ex.is_draft = false'];

    // Full-text search on title + description
    if (q && q.trim()) {
      params.push(q.trim());
      whereClauses.push(`ex.search_vector @@ plainto_tsquery('english', $${params.length})`);
    }

    // Filter by concept name (matches primary OR secondary concepts)
    if (concept && concept.trim()) {
      params.push(concept.trim());
      whereClauses.push(`(c.name = $${params.length} OR sc.name = $${params.length})`);
    }

    // Filter by section
    if (section_id && section_id !== 'all') {
      params.push(section_id);
      whereClauses.push(`ex.section_id = $${params.length}`);
    }

    // Instructor-only: scope to their sections if section_id is 'all'
    if (section_id === 'all' && req.user?.role === 'instructor') {
      whereClauses.push(`ex.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)`);
    }

    const whereSql = whereClauses.join(' AND ');

    const sql = `
      SELECT DISTINCT ex.*, c.name AS concept_name,
             (SELECT COUNT(*) FROM submissions s
              WHERE s.exercise_id = ex.id AND s.is_correct = true) AS completion_count
      FROM exercises ex
      LEFT JOIN concepts c ON c.id = ex.concept_id
      LEFT JOIN exercise_concepts ec ON ec.exercise_id = ex.id
      LEFT JOIN concepts sc ON sc.id = ec.concept_id
      WHERE ${whereSql}
      ORDER BY ex.created_at DESC
    `;

    const result = await db.query(sql, params);
    res.json(result.rows);
  } catch (err) {
    next(err);
  }
};

/**
 * GET /api/search/exercises/:id
 * Get single exercise with all linked concepts (primary + secondary).
 */
exports.getExercise = async (req, res, next) => {
  try {
    const [exRes, conceptsRes] = await Promise.all([
      db.query(
        `SELECT ex.*, c.name AS concept_name
         FROM exercises ex
         LEFT JOIN concepts c ON c.id = ex.concept_id
         WHERE ex.id = $1`,
        [req.params.id]
      ),
      db.query(
        `SELECT c.id, c.name
         FROM exercise_concepts ec
         JOIN concepts c ON c.id = ec.concept_id
         WHERE ec.exercise_id = $1`,
        [req.params.id]
      )
    ]);

    if (!exRes.rows.length) {
      throw new AppError('Exercise not found', 404, codes.NOT_FOUND);
    }

    const exercise = exRes.rows[0];
    exercise.concepts = conceptsRes.rows;

    // Filter hidden test cases for students
    if (req.user?.role === 'student') {
      exercise.test_cases = (exercise.test_cases || []).filter(tc => !tc.hidden);
    }

    res.json(exercise);
  } catch (err) {
    next(err);
  }
};

/**
 * GET /api/search/concepts
 * List all available concepts (reuses the concepts table).
 */
exports.listConcepts = async (_req, res, next) => {
  try {
    const result = await db.query('SELECT id, name, ast_nodes FROM concepts ORDER BY name');
    res.json(result.rows);
  } catch (err) {
    next(err);
  }
};

/**
 * GET /api/search/concepts/:conceptId/exercises
 * Get all exercises tagged with a specific concept.
 */
exports.getExercisesByConcept = async (req, res, next) => {
  try {
    const result = await db.query(
      `SELECT ex.*, c.name AS concept_name
       FROM exercises ex
       JOIN concepts c ON c.id = ex.concept_id
       WHERE (ex.concept_id = $1 OR ex.id IN (SELECT exercise_id FROM exercise_concepts WHERE concept_id = $1))
       AND ex.is_draft = false
       ORDER BY ex.created_at DESC`,
      [req.params.conceptId]
    );
    res.json(result.rows);
  } catch (err) {
    next(err);
  }
};
