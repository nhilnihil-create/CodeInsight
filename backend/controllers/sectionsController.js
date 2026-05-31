const db = require('../config/db');

/**
 * Fetch all active sections where 'deleted_at' IS NULL.
 * GET /api/sections
 */
const getSections = async (req, res) => {
  try {
    const sections = await db('sections')
      .whereNull('deleted_at')
      .select('*')
      .orderBy('created_at', 'desc');

    return res.status(200).json(sections);
  } catch (error) {
    console.error('Error fetching sections:', error);
    return res.status(500).json({ error: 'Internal server error while fetching sections.' });
  }
};

/**
 * Fetch a single section by ID.
 * GET /api/sections/:id
 */
const getOne = async (req, res) => {
  const { id } = req.params;
  try {
    const section = await db('sections')
      .where({ id })
      .whereNull('deleted_at')
      .first();

    if (!section) {
      return res.status(404).json({ error: 'Section not found.' });
    }

    return res.status(200).json(section);
  } catch (error) {
    console.error('Error fetching section:', error);
    return res.status(500).json({ error: 'Internal server error while fetching section.' });
  }
};

/**
 * Update section parameters (name, course_code, school_year, semester).
 * PUT /api/sections/:id
 */
const updateSection = async (req, res) => {
  const { id } = req.params;
  const { name, course_code, school_year, semester } = req.body;

  try {
    const updatedCount = await db('sections')
      .where({ id })
      .whereNull('deleted_at')
      .update({
        name,
        course_code,
        school_year,
        semester
      });

    if (updatedCount === 0) {
      return res.status(404).json({ error: 'Section not found or already deleted.' });
    }

    const updatedSection = await db('sections').where({ id }).first();
    return res.status(200).json(updatedSection);
  } catch (error) {
    console.error('Error updating section:', error);
    return res.status(500).json({ error: 'Internal server error while updating section.' });
  }
};

/**
 * Programmatic cascading soft-delete using a transaction.
 * Sets 'deleted_at' for the section, and related exercises and enrollments.
 * DELETE /api/sections/:id
 */
const deleteSection = async (req, res) => {
  const { id } = req.params;

  try {
    await db.transaction(async (trx) => {
      const now = db.fn.now();

      // 1. Soft-delete the target section
      const sectionUpdate = await trx('sections')
        .where({ id })
        .whereNull('deleted_at')
        .update({ deleted_at: now });

      if (sectionUpdate === 0) {
        throw new Error('SECTION_NOT_FOUND');
      }

      // 2. Soft-delete related exercises
      await trx('exercises')
        .where({ section_id: id })
        .whereNull('deleted_at')
        .update({ deleted_at: now });

      // 3. Soft-delete related enrollments
      await trx('enrollments')
        .where({ section_id: id })
        .whereNull('deleted_at')
        .update({ deleted_at: now });
    });

    return res.status(200).json({ 
      message: 'Section and all related exercises and enrollments have been soft-deleted.' 
    });
  } catch (error) {
    console.error('Error during cascading soft-delete:', error);
    if (error.message === 'SECTION_NOT_FOUND') {
      return res.status(404).json({ error: 'Section not found or already deleted.' });
    }
    return res.status(500).json({ error: 'Internal server error during cascading soft-delete.' });
  }
};

/**
 * Fetch all archived (soft-deleted) sections.
 * GET /api/sections/archived
 */
const getArchivedSections = async (req, res) => {
  try {
    const archived = await db('sections')
      .whereNotNull('deleted_at')
      .select('*')
      .orderBy('deleted_at', 'desc');

    return res.status(200).json(archived);
  } catch (error) {
    console.error('Error fetching archived sections:', error);
    return res.status(500).json({ error: 'Internal server error while fetching archived sections.' });
  }
};

/**
 * Fetch paginated students for a specific section.
 * GET /api/sections/:id/students
 */
const getSectionStudents = async (req, res) => {
  const { id } = req.params;
  const { page = 1, limit = 10, search = '' } = req.query;
  const offset = (page - 1) * limit;

  try {
    const query = db('enrollments')
      .join('users', 'enrollments.student_id', 'users.id')
      .where('enrollments.section_id', id)
      .whereNull('enrollments.deleted_at')
      .where((builder) => {
        if (search) {
          builder.where('users.name', 'ilike', `%${search}%`)
                 .orWhere('users.email', 'ilike', `%${search}%`);
        }
      });

    const students = await query.clone().select('users.*', 'enrollments.status', 'enrollments.created_at as enrolled_at').limit(limit).offset(offset);
    const total = await query.clone().count('users.id as count').first();

    return res.status(200).json({ students, total: parseInt(total.count), page: parseInt(page), limit: parseInt(limit) });
  } catch (error) {
    console.error('Error fetching section students:', error);
    return res.status(500).json({ error: 'Internal server error while fetching students.' });
  }
};

/**
 * Enroll students into a section.
 * POST /api/sections/:id/enroll
 */
const enroll = async (req, res) => {
  const { id: section_id } = req.params;
  const { studentIds, emails } = req.body;

  try {
    const enrollments = [];
    
    // Enroll by student IDs
    if (studentIds && Array.isArray(studentIds)) {
      for (const student_id of studentIds) {
        enrollments.push({ student_id, section_id, status: 'active' });
      }
    }

    // Enroll by emails
    if (emails && Array.isArray(emails)) {
      const users = await db('users').whereIn('email', emails).select('id');
      for (const user of users) {
        enrollments.push({ student_id: user.id, section_id, status: 'active' });
      }
    }

    if (enrollments.length === 0) {
      return res.status(400).json({ error: 'No students provided for enrollment.' });
    }

    // Use onConflict to avoid duplicate enrollments
    await db('enrollments')
      .insert(enrollments)
      .onConflict(['student_id', 'section_id'])
      .merge({ 
        deleted_at: null, 
        status: 'active'
      });

    return res.status(200).json({ message: `Successfully enrolled ${enrollments.length} student(s).` });
  } catch (error) {
    console.error('Error enrolling students:', error);
    return res.status(500).json({ error: 'Internal server error during enrollment.' });
  }
};

module.exports = {
  getSections,
  getOne,
  updateSection,
  deleteSection,
  getArchivedSections,
  getSectionStudents,
  enroll
};