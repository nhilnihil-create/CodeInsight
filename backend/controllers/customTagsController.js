const db = require('../config/db');
const { AppError, codes } = require('../lib/AppError');

/**
 * GET /api/custom-tags?sectionId=X
 * List the instructor's custom tags with mapped exercise info for a section.
 */
exports.list = async (req, res, next) => {
  try {
    const instructorId = req.user.id;
    const { sectionId } = req.query;

    const result = await db.query(
      `SELECT
         t.id, t.tag_name, t.color_theme, t.is_active_column, t.knowledge_area, t.created_at,
         COALESCE(m.exercise_count, 0)::INTEGER AS exercise_count
       FROM instructor_custom_tags t
       LEFT JOIN (
         SELECT m.custom_tag_id, COUNT(*) AS exercise_count
         FROM custom_tag_exercise_mappings m
         JOIN exercises e ON e.id = m.exercise_id
         WHERE e.section_id = $2
         GROUP BY m.custom_tag_id
       ) m ON m.custom_tag_id = t.id
       WHERE t.instructor_id = $1
       ORDER BY t.created_at ASC`,
      [instructorId, sectionId]
    );

    res.json(result.rows);
  } catch (err) {
    next(err);
  }
};

/**
 * POST /api/custom-tags
 * Create a new custom tag.
 * Body: { tag_name, color_theme? }
 */
exports.create = async (req, res, next) => {
  try {
    const instructorId = req.user.id;
    const { tag_name, color_theme, knowledge_area } = req.body;

    if (!tag_name || !tag_name.trim()) {
      throw new AppError('Tag name is required', 400, codes.VALIDATION);
    }

    const result = await db.query(
      `INSERT INTO instructor_custom_tags (instructor_id, tag_name, color_theme, knowledge_area)
       VALUES ($1, $2, $3, $4)
       ON CONFLICT (instructor_id, tag_name) DO UPDATE SET tag_name = EXCLUDED.tag_name
       RETURNING *`,
      [instructorId, tag_name.trim(), color_theme || 'slate', knowledge_area || null]
    );

    res.status(201).json(result.rows[0]);
  } catch (err) {
    if (err.code === '23505') {
      return next(new AppError('A tag with this name already exists', 409, codes.CONFLICT));
    }
    next(err);
  }
};

/**
 * PUT /api/custom-tags/:tagId
 * Update tag name, color_theme, or active status.
 */
exports.update = async (req, res, next) => {
  try {
    const instructorId = req.user.id;
    const { tagId } = req.params;
    const { tag_name, color_theme, is_active_column } = req.body;

    const sets = [];
    const params = [];
    let idx = 1;

    if (tag_name !== undefined) {
      sets.push(`tag_name = $${idx++}`);
      params.push(tag_name.trim());
    }
    if (color_theme !== undefined) {
      sets.push(`color_theme = $${idx++}`);
      params.push(color_theme);
    }
    if (is_active_column !== undefined) {
      sets.push(`is_active_column = $${idx++}`);
      params.push(is_active_column);
    }

    if (!sets.length) {
      return res.status(400).json({ error: 'No fields to update' });
    }

    params.push(tagId, instructorId);
    const result = await db.query(
      `UPDATE instructor_custom_tags
       SET ${sets.join(', ')}
       WHERE id = $${idx++} AND instructor_id = $${idx}
       RETURNING *`,
      params
    );

    if (!result.rows.length) {
      return res.status(404).json({ error: 'Tag not found' });
    }

    res.json(result.rows[0]);
  } catch (err) {
    if (err.code === '23505') {
      return next(new AppError('A tag with this name already exists', 409, codes.CONFLICT));
    }
    next(err);
  }
};

/**
 * DELETE /api/custom-tags/:tagId
 * Delete a custom tag (cascades to mappings).
 */
exports.remove = async (req, res, next) => {
  try {
    const instructorId = req.user.id;
    const { tagId } = req.params;

    const result = await db.query(
      `DELETE FROM instructor_custom_tags
       WHERE id = $1 AND instructor_id = $2
       RETURNING id`,
      [tagId, instructorId]
    );

    if (!result.rows.length) {
      return res.status(404).json({ error: 'Tag not found' });
    }

    res.json({ message: 'Tag deleted' });
  } catch (err) {
    next(err);
  }
};

/**
 * POST /api/custom-tags/:tagId/exercises
 * Map exercises to a tag.
 * Body: { exercise_ids: number[] }
 */
exports.mapExercises = async (req, res, next) => {
  try {
    const instructorId = req.user.id;
    const { tagId } = req.params;
    const { exercise_ids } = req.body;

    if (!Array.isArray(exercise_ids) || !exercise_ids.length) {
      throw new AppError('exercise_ids array is required', 400, codes.VALIDATION);
    }

    // Verify tag ownership
    const tagRes = await db.query(
      `SELECT id FROM instructor_custom_tags WHERE id = $1 AND instructor_id = $2`,
      [tagId, instructorId]
    );
    if (!tagRes.rows.length) {
      return res.status(404).json({ error: 'Tag not found' });
    }

    // Bulk insert mappings, ignoring duplicates
    const values = exercise_ids.map((_, i) => `($1, $${i + 2})`).join(', ');
    const params = [tagId, ...exercise_ids];

    await db.query(
      `INSERT INTO custom_tag_exercise_mappings (custom_tag_id, exercise_id)
       ${values}
       ON CONFLICT (custom_tag_id, exercise_id) DO NOTHING`,
      params
    );

    res.json({ mapped: exercise_ids.length });
  } catch (err) {
    next(err);
  }
};

/**
 * DELETE /api/custom-tags/:tagId/exercises/:exerciseId
 * Unmap a single exercise from a tag.
 */
exports.unmapExercise = async (req, res, next) => {
  try {
    const instructorId = req.user.id;
    const { tagId, exerciseId } = req.params;

    // Verify tag ownership
    const tagRes = await db.query(
      `SELECT id FROM instructor_custom_tags WHERE id = $1 AND instructor_id = $2`,
      [tagId, instructorId]
    );
    if (!tagRes.rows.length) {
      return res.status(404).json({ error: 'Tag not found' });
    }

    const result = await db.query(
      `DELETE FROM custom_tag_exercise_mappings
       WHERE custom_tag_id = $1 AND exercise_id = $2
       RETURNING id`,
      [tagId, exerciseId]
    );

    if (!result.rows.length) {
      return res.status(404).json({ error: 'Mapping not found' });
    }

    res.json({ message: 'Exercise unmapped' });
  } catch (err) {
    next(err);
  }
};

/**
 * GET /api/custom-tags/exercise-mappings?sectionId=X
 * Returns all exercise→tag mappings for a section (lightweight, for exercise list badges).
 */
exports.getExerciseMappings = async (req, res, next) => {
  try {
    const instructorId = req.user.id;
    const { sectionId } = req.query;

    const result = await db.query(
      `SELECT m.exercise_id, t.id AS tag_id, t.tag_name, t.color_theme, t.knowledge_area
       FROM custom_tag_exercise_mappings m
       JOIN instructor_custom_tags t ON t.id = m.custom_tag_id
       JOIN exercises e ON e.id = m.exercise_id
       WHERE t.instructor_id = $1 AND e.section_id = $2
       ORDER BY t.tag_name`,
      [instructorId, sectionId]
    );

    // Group by exercise_id
    const map = {};
    for (const row of result.rows) {
      if (!map[row.exercise_id]) map[row.exercise_id] = [];
      map[row.exercise_id].push({
        tagId: row.tag_id,
        tagName: row.tag_name,
        colorTheme: row.color_theme,
        knowledgeArea: row.knowledge_area,
      });
    }

    res.json(map);
  } catch (err) {
    next(err);
  }
};

/**
 * POST /api/custom-tags/map-to-exercise
 * Creates custom tags by name (if they don't exist) and maps them to an exercise.
 * Body: { exercise_id, tag_names: string[], section_id }
 *   OR: { exercise_id, tags: [{ tag_name: string, knowledge_area?: string }], section_id }
 */
exports.mapTagsToExercise = async (req, res, next) => {
  try {
    const instructorId = req.user.id;
    const { exercise_id, tag_names, tags, section_id } = req.body;

    // Normalise both formats into [{ name, knowledge_area }]
    const tagEntries = [];
    if (Array.isArray(tags) && tags.length) {
      for (const t of tags) {
        const name = (t.tag_name || t.name || '').trim();
        if (name) tagEntries.push({ name, knowledge_area: t.knowledge_area || null });
      }
    } else if (Array.isArray(tag_names) && tag_names.length) {
      for (const n of tag_names) {
        const name = (typeof n === 'string' ? n : '').trim();
        if (name) tagEntries.push({ name, knowledge_area: null });
      }
    }

    if (!exercise_id || !tagEntries.length) {
      throw new AppError('exercise_id and tags[] (or tag_names[]) are required', 400, codes.VALIDATION);
    }

    const results = [];

    for (const { name, knowledge_area } of tagEntries) {
      // Upsert tag — update knowledge_area when provided
      const tagRes = await db.query(
        `INSERT INTO instructor_custom_tags (instructor_id, tag_name, knowledge_area)
         VALUES ($1, $2, $3)
         ON CONFLICT (instructor_id, tag_name) DO UPDATE
           SET knowledge_area = COALESCE(EXCLUDED.knowledge_area, instructor_custom_tags.knowledge_area)
         RETURNING id`,
        [instructorId, name, knowledge_area]
      );
      const tagId = tagRes.rows[0].id;

      // Map exercise to tag
      await db.query(
        `INSERT INTO custom_tag_exercise_mappings (custom_tag_id, exercise_id)
         VALUES ($1, $2)
         ON CONFLICT (custom_tag_id, exercise_id) DO NOTHING`,
        [tagId, exercise_id]
      );

      results.push({ tagId, tagName: name, knowledge_area });
    }

    res.json({ mapped: results });
  } catch (err) {
    next(err);
  }
};

/**
 * GET /api/custom-tags/:tagId/exercises?sectionId=X
 * List exercises mapped to a tag within a section.
 */
exports.listMappedExercises = async (req, res, next) => {
  try {
    const instructorId = req.user.id;
    const { tagId } = req.params;
    const { sectionId } = req.query;

    // Verify tag ownership
    const tagRes = await db.query(
      `SELECT id FROM instructor_custom_tags WHERE id = $1 AND instructor_id = $2`,
      [tagId, instructorId]
    );
    if (!tagRes.rows.length) {
      return res.status(404).json({ error: 'Tag not found' });
    }

    const result = await db.query(
      `SELECT e.id, e.title, e.created_at,
              m.created_at AS mapped_at
       FROM exercises e
       JOIN custom_tag_exercise_mappings m ON m.exercise_id = e.id AND m.custom_tag_id = $1
       WHERE e.section_id = $2
       ORDER BY e.title ASC`,
      [tagId, sectionId]
    );

    res.json(result.rows);
  } catch (err) {
    next(err);
  }
};
