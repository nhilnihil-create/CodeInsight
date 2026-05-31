const db = require('../config/db');

/**
 * GET /api/sections/:sectionId/enrollments
 * Paginated list of enrollments with search.
 */
const getEnrollmentsBySection = async (req, res) => {
  const { sectionId } = req.params;
  const { page = 1, limit = 15, search = '' } = req.query;
  const offset = (page - 1) * limit;

  try {
    const query = db('enrollments')
      .join('users', 'enrollments.student_id', 'users.id')
      .where('enrollments.section_id', sectionId)
      .whereNull('enrollments.deleted_at')
      .where((builder) => {
        if (search) {
          builder.where('users.name', 'ilike', `%${search}%`)
                 .orWhere('users.email', 'ilike', `%${search}%`);
        }
      });

    const data = await query.clone().select('enrollments.*', 'users.name', 'users.email').limit(limit).offset(offset);
    const count = await query.clone().count('enrollments.id as count').first();

    return res.status(200).json({ data, total: parseInt(count.count) });
  } catch (error) {
    return res.status(500).json({ error: error.message });
  }
};

/**
 * DELETE /api/enrollments/:id
 * Soft-unenroll a student.
 */
const unenrollStudent = async (req, res) => {
  const { id } = req.params;

  try {
    const count = await db('enrollments')
      .where({ id })
      .update({
        status: 'unenrolled',
        unenrolled_at: db.fn.now(),
        deleted_at: db.fn.now() // Standard programmatic soft-delete
      });

    if (count === 0) return res.status(404).json({ error: 'Enrollment not found.' });
    return res.status(200).json({ message: 'Student successfully unenrolled.' });
  } catch (error) {
    return res.status(500).json({ error: error.message });
  }
};

module.exports = {
  getEnrollmentsBySection,
  unenrollStudent
};