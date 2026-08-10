const db = require('../config/db');

async function writeAuditLog(sectionId, actorId, action, meta = {}, queryFn = null) {
  const q = queryFn || db.query.bind(db);
  await q(
    `INSERT INTO section_audit_log (section_id, actor_id, action, meta) VALUES ($1, $2, $3, $4)`,
    [sectionId, actorId, action, JSON.stringify(meta)]
  );
}

function generateCode() {
  const chars = 'ABCDEFGHJKLMNPQRSTUVWXYZ23456789';
  let code = '';
  for (let i = 0; i < 6; i++) {
    if (i === 3) code += '-';
    code += chars[Math.floor(Math.random() * chars.length)];
  }
  return code;
}

exports.create = async (req, res, next) => {
  const { name, course_code, school_year, semester } = req.body;
  if (!name || !course_code)
    return res.status(400).json({ message: 'name and course_code required' });
  try {
    const r = await db.query(
      'INSERT INTO sections(name,course_code,school_year,semester,instructor_id,code,join_policy) VALUES($1,$2,$3,$4,$5,$6,$7) RETURNING *',
      [name, course_code, school_year || '', semester || 'Sem 1', req.user.id, generateCode(), 'code']
    );
    await writeAuditLog(r.rows[0].id, req.user.id, 'section_created', { name, course_code });
    res.status(201).json(r.rows[0]);
  } catch (err) { next(err); }
};

exports.list = async (req, res, next) => {
  try {
    let query, params;
    if (req.user.role === 'instructor') {
      query = `SELECT s.*,
        (SELECT COUNT(*) FROM enrollments e WHERE e.section_id=s.id) AS student_count,
        (SELECT COUNT(*) FROM exercises ex WHERE ex.section_id=s.id) AS exercise_count,
        (SELECT COUNT(DISTINCT concept_id) FROM exercises ex WHERE ex.section_id=s.id) AS concept_count,
        (SELECT COUNT(*) FROM alerts al WHERE al.section_id=s.id AND al.is_reviewed=false) AS alert_count,
        (SELECT COUNT(DISTINCT if2.student_id) FROM integrity_flags if2 WHERE if2.section_id=s.id AND if2.status='flagged') AS integrity_flags_count,
        (SELECT AVG(cs.cds) FROM cds_scores cs 
         WHERE cs.section_id=s.id) AS avg_cds
        FROM sections s WHERE s.instructor_id=$1 ORDER BY s.created_at DESC`;
      params = [req.user.id];
    } else {
      query = `SELECT s.*,
        (SELECT COUNT(*) FROM enrollments e WHERE e.section_id=s.id) AS student_count
        FROM sections s
        JOIN enrollments en ON en.section_id=s.id
        WHERE en.student_id=$1 AND en.dropped_at IS NULL ORDER BY s.created_at DESC`;
      params = [req.user.id];
    }
    const r = await db.query(query, params);
    
    // For instructors, enrich data with difficulty distribution (batched query)
    if (req.user.role === 'instructor') {
      const sectionIds = r.rows.map(s => s.id);
      if (sectionIds.length > 0) {
        const diffQuery = `
          SELECT 
            section_id,
            COUNT(CASE WHEN cs.cds <= 0.40 THEN 1 END) AS low_count,
            COUNT(CASE WHEN cs.cds > 0.40 AND cs.cds <= 0.80 THEN 1 END) AS elevated_count,
            COUNT(CASE WHEN cs.cds > 0.80 THEN 1 END) AS critical_count
          FROM cds_scores cs WHERE cs.section_id = ANY($1)
          GROUP BY cs.section_id
        `;
        const diffRes = await db.query(diffQuery, [sectionIds]);
        const diffMap = {};
        for (const row of diffRes.rows) {
          diffMap[row.section_id] = {
            low: parseInt(row.low_count),
            elevated: parseInt(row.elevated_count),
            critical: parseInt(row.critical_count)
          };
        }
        for (const section of r.rows) {
          section.difficulty_distribution = diffMap[section.id] || { low: 0, elevated: 0, critical: 0 };
        }
      }
    }
    res.json(r.rows);
  } catch (err) { next(err); }
};

exports.getOne = async (req, res, next) => {
  try {
    const sec = await db.query(
      `SELECT s.*, u.name AS instructor_name,
       (SELECT COUNT(*) FROM enrollments e WHERE e.section_id=s.id) AS student_count,
       (SELECT COUNT(*) FROM exercises ex WHERE ex.section_id=s.id) AS exercise_count,
       (SELECT COUNT(*) FROM (
           SELECT ex.id, (SELECT COUNT(DISTINCT student_id) FROM submissions sub WHERE sub.exercise_id=ex.id AND sub.student_id IN (SELECT student_id FROM enrollments WHERE section_id=s.id)) AS submitted_count,
           (SELECT COUNT(*) FROM enrollments WHERE section_id=s.id) AS total_students
         FROM exercises ex WHERE ex.section_id=s.id
         ) t WHERE t.submitted_count >= t.total_students) AS completed_exercises,
       (SELECT COUNT(DISTINCT student_id) FROM submissions sub 
        WHERE sub.exercise_id IN (SELECT id FROM exercises WHERE section_id=s.id)) AS total_submissions,
       (SELECT COUNT(*) FROM alerts al WHERE al.section_id=s.id AND al.is_reviewed=false) AS open_alert_count,
       (SELECT COUNT(DISTINCT if2.student_id) FROM integrity_flags if2 WHERE if2.section_id=s.id AND if2.status='flagged') AS integrity_flags_count,
       (SELECT COUNT(CASE WHEN cs.cds > 0.60 THEN 1 END)::INTEGER FROM cds_scores cs WHERE cs.section_id=s.id) AS at_risk_count,
       (SELECT AVG(cs.cds) FROM cds_scores cs WHERE cs.section_id=s.id) AS avg_cds
       FROM sections s JOIN users u ON u.id=s.instructor_id
       WHERE s.id=$1`, [req.params.id]
    );
    if (!sec.rows.length) return res.status(404).json({ message: 'Section not found' });
    res.json(sec.rows[0]);
  } catch (err) { next(err); }
};

exports.enroll = async (req, res, next) => {
  const { studentIds, emails } = req.body;
  const sectionId = req.params.id;
  try {
    let ids = studentIds || [];
    if (emails && emails.length) {
      const emailList = emails.map(e => e.trim().toLowerCase());
      const found = await db.query(
        `SELECT id FROM users WHERE LOWER(email) = ANY($1) AND role='student'`,
        [emailList]
      );
      ids = [...ids, ...found.rows.map(r => r.id)];
    }
    if (!ids.length) return res.status(400).json({ message: 'No valid students found' });
    let enrolled = 0;
    for (const sid of ids) {
      // Upsert so re-enrolling a previously left student reactivates the
      // enrollment instead of hitting the UNIQUE(student_id, section_id)
      // constraint. Clearing dropped_at marks the enrollment active again.
      await db.query(
        'INSERT INTO enrollments(student_id,section_id,dropped_at) VALUES($1,$2,NULL) ON CONFLICT (student_id, section_id) DO UPDATE SET dropped_at = NULL;',
        [sid, sectionId]
      );
      enrolled++;
    }
    res.json({ message: `${enrolled} student(s) enrolled` });
  } catch (err) { next(err); }
};

exports.unenroll = async (req, res, next) => {
  try {
    const { studentId, id } = req.params;
    // Soft drop: mark the enrollment as dropped instead of deleting it.
    // The row (and its join history) is preserved; student-facing queries
    // filter on dropped_at IS NULL. Historical analytics stay in place so
    // instructor reports don't silently lose data.
    await db.query(
      'UPDATE enrollments SET dropped_at = NOW() WHERE student_id=$1 AND section_id=$2',
      [studentId, id]
    );

    res.json({ message: 'Student removed from section' });
  } catch (err) { next(err); }
};

exports.getStudents = async (req, res, next) => {
  try {
    const r = await db.query(
      `SELECT u.id, u.name, u.email, e.enrolled_at
       FROM users u JOIN enrollments e ON e.student_id=u.id
       WHERE e.section_id=$1 ORDER BY u.name`,
      [req.params.id]
    );
    res.json(r.rows);
  } catch (err) { next(err); }
};

// Get students with their latest CDS scores and submission counts
exports.getStudentsWithScores = async (req, res, next) => {
  try {
    const { section_id } = req.params;
    if (!section_id || section_id === 'null' || section_id === 'undefined') {
      return res.json([]);
    }
    const r = await db.query(
      `SELECT
        u.id, u.name, u.email,
        (SELECT ROUND(AVG(cds)::numeric, 4) FROM cds_scores cs WHERE cs.student_id=u.id AND cs.section_id=$1) AS avg_cds,
        (SELECT cds FROM cds_scores cs WHERE cs.student_id=u.id AND cs.section_id=$1
         ORDER BY cs.computed_at ASC LIMIT 1) AS first_cds,
        (SELECT COUNT(*) FROM submissions sub WHERE sub.student_id=u.id
         AND sub.exercise_id IN (SELECT id FROM exercises WHERE section_id=$1)) AS submitted_count,
        (SELECT COUNT(*) FROM exercises WHERE section_id=$1) AS total_exercises,
        (SELECT COUNT(*)::INTEGER FROM integrity_flags if2 WHERE if2.student_id=u.id AND if2.section_id=$1 AND if2.status='flagged') AS integrity_flag_count,
        (SELECT MAX(submitted_at) FROM submissions sub WHERE sub.student_id=u.id
         AND sub.exercise_id IN (SELECT id FROM exercises WHERE section_id=$1)) AS last_active
       FROM users u JOIN enrollments e ON e.student_id=u.id
       WHERE e.section_id=$1 ORDER BY u.name`,
      [section_id]
    );
    res.json(r.rows);
  } catch (err) { next(err); }
};

/**
 * GET /api/sections/students-all
 * Aggregates students across ALL sections owned by the instructor.
 */
exports.getStudentsAcrossSections = async (req, res, next) => {
  try {
    const instructorId = req.user.id;
    const r = await db.query(
      `SELECT DISTINCT
        u.id, u.name, u.email,
        (SELECT ROUND(AVG(cds)::numeric, 4) FROM cds_scores cs WHERE cs.student_id=u.id AND cs.section_id IN (SELECT id FROM sections WHERE instructor_id=$1)) AS avg_cds,
        (SELECT COUNT(*) FROM submissions sub WHERE sub.student_id=u.id
         AND sub.exercise_id IN (SELECT id FROM exercises WHERE section_id IN (SELECT id FROM sections WHERE instructor_id=$1))) AS submitted_count,
        (SELECT COUNT(*) FROM exercises WHERE section_id IN (SELECT id FROM sections WHERE instructor_id=$1)) AS total_exercises,
        (SELECT COUNT(*)::INTEGER FROM integrity_flags if2 WHERE if2.student_id=u.id AND if2.section_id IN (SELECT id FROM sections WHERE instructor_id=$1) AND if2.status='flagged') AS integrity_flag_count
       FROM users u JOIN enrollments e ON e.student_id=u.id
       WHERE e.section_id IN (SELECT id FROM sections WHERE instructor_id=$1)
       ORDER BY u.name`,
      [instructorId]
    );
    res.json(r.rows);
  } catch (err) { next(err); }
};

// Get exercises for a section with stats
exports.getSectionExercises = async (req, res, next) => {
  try {
    const { section_id } = req.params;
    if (!section_id || section_id === 'null' || section_id === 'undefined') {
      return res.json([]);
    }
    const r = await db.query(
      `SELECT 
        ex.id, ex.title, ex.description, ex.concept_id, ex.section_id,
        ex.closed_at, ex.deadline, ex.created_at, c.name AS concept_name,
        (SELECT COUNT(*)::INTEGER FROM enrollments WHERE section_id=$1) AS total_students,
        (SELECT COUNT(DISTINCT student_id)::INTEGER FROM submissions 
         WHERE exercise_id=ex.id) AS submitted_count,
        (SELECT AVG(cs.cds) FROM cds_scores cs 
         WHERE cs.exercise_id=ex.id AND cs.section_id=$1) AS avg_cds,
        (SELECT COUNT(CASE WHEN cs.cds <= 0.40 THEN 1 END)::INTEGER FROM cds_scores cs 
         WHERE cs.exercise_id=ex.id AND cs.section_id=$1) AS low_count,
        (SELECT COUNT(CASE WHEN cs.cds > 0.40 AND cs.cds <= 0.80 THEN 1 END)::INTEGER FROM cds_scores cs 
         WHERE cs.exercise_id=ex.id AND cs.section_id=$1) AS elevated_count,
        (SELECT COUNT(CASE WHEN cs.cds > 0.80 THEN 1 END)::INTEGER FROM cds_scores cs 
         WHERE cs.exercise_id=ex.id AND cs.section_id=$1) AS critical_count
       FROM exercises ex
       JOIN concepts c ON c.id=ex.concept_id
       WHERE ex.section_id=$1
       ORDER BY ex.created_at DESC`,
      [section_id]
    );
    res.json(r.rows);
  } catch (err) { next(err); }
};

// ── New section management endpoints (spec §11.6) ─────────────────────────

exports.rotateCode = async (req, res, next) => {
  const { id } = req.params;
  try {
    const newCode = generateCode();
    const r = await db.query('UPDATE sections SET code=$1 WHERE id=$2 RETURNING *', [newCode, id]);
    if (!r.rows.length) return res.status(404).json({ error: 'Section not found' });
    await writeAuditLog(id, req.user.id, 'code_rotated', { code: newCode });
    res.json(r.rows[0]);
  } catch (err) { next(err); }
};

exports.joinSection = async (req, res, next) => {
  const { code } = req.body;
  if (!code) return res.status(400).json({ error: 'Code required' });
  try {
    // Spec §11.8: race conditions on capacity are resolved by SELECT ... FOR UPDATE
    // on the section row inside the join transaction. This serializes concurrent
    // joins at the max_size boundary; the first wins, the second sees the
    // post-increment count and is rejected with "Section is full."
    //
    // Uses withTransaction() to ensure all queries run on the same pool client
    // so the transaction (BEGIN / COMMIT / ROLLBACK) is coherent.
    const result = await db.withTransaction(async (client) => {
      const sec = await client.query(
        'SELECT * FROM sections WHERE code=$1 FOR UPDATE',
        [code.toUpperCase()]
      );
      if (!sec.rows.length) {
        throw Object.assign(new Error('Invalid code'), { status: 404 });
      }
      const section = sec.rows[0];
      if (section.join_policy === 'closed') {
        throw Object.assign(new Error('Section is closed to new join requests'), { status: 403 });
      }

      // Re-check max_size under the lock (defense: race-join at the cap).
      // Only active enrollments occupy a seat — a student who left frees one.
      if (section.max_size) {
        const cnt = await client.query(
          'SELECT COUNT(*)::int AS n FROM enrollments WHERE section_id=$1 AND dropped_at IS NULL',
          [section.id]
        );
        if (cnt.rows[0].n >= section.max_size) {
          throw Object.assign(new Error('Section is full'), { status: 403 });
        }
      }

      const existing = await client.query(
        'SELECT * FROM enrollments WHERE student_id=$1 AND section_id=$2 AND dropped_at IS NULL',
        [req.user.id, section.id]
      );
      if (existing.rows.length) {
        throw Object.assign(new Error('Already enrolled'), { status: 409 });
      }

      // Upsert so a student who left earlier can rejoin: the stale row's
      // dropped_at is cleared, reactivating the enrollment.
      const joinInsert = `
        INSERT INTO enrollments(student_id,section_id,dropped_at) VALUES($1,$2,NULL)
        ON CONFLICT (student_id, section_id) DO UPDATE SET dropped_at = NULL
      `;

      if (section.join_policy === 'code') {
        await client.query(joinInsert, [req.user.id, section.id]);
        await writeAuditLog(section.id, req.user.id, 'student_joined', { code }, client.query.bind(client));
        return { message: 'Joined section', section };
      }

      await client.query(joinInsert, [req.user.id, section.id]);
      await writeAuditLog(section.id, req.user.id, 'student_requested_to_join', { code }, client.query.bind(client));
      return { message: 'Join request submitted' };
    });
    res.json(result);
  } catch (err) {
    next(err);
  }
};

exports.addMembership = async (req, res, next) => {
  const { id } = req.params;
  const { userId, role } = req.body;
  try {
    const r = await db.query(
      'INSERT INTO enrollments(student_id,section_id) VALUES($1,$2) ON CONFLICT DO NOTHING RETURNING *',
      [userId, id]
    );
    await writeAuditLog(id, req.user.id, 'student_joined', { userId, role: role || 'student' });
    const status = r.rows.length ? 201 : 200;
    res.status(status).json(r.rows[0] || { message: 'Already enrolled' });
  } catch (err) { next(err); }
};

exports.updateMembership = async (req, res, next) => {
  const { id, mid } = req.params;
  const { status, dropReason } = req.body;
  try {
    if (status === 'dropped') {
      // Spec §11.4: "Reason required? Yes — short note (e.g., 'transferred to BSIT-1B
      // per registrar')." Defense artifact: the drop reason is written to the audit
      // log so the trail is intact.
      const reason = (dropReason || '').trim();
      if (!reason) {
        return res.status(400).json({ error: 'dropReason is required to drop a student' });
      }
      await db.query('DELETE FROM enrollments WHERE student_id=$1 AND section_id=$2', [mid, id]);
      await db.query('DELETE FROM cds_scores WHERE student_id=$1 AND section_id=$2', [mid, id]);
      await db.query('DELETE FROM integrity_flags WHERE student_id=$1 AND section_id=$2', [mid, id]);
      await db.query('DELETE FROM alerts WHERE student_id=$1 AND section_id=$2', [mid, id]);
      await db.query('DELETE FROM student_concept_metrics WHERE student_id=$1 AND section_id=$2', [mid, id]);
      await db.query('DELETE FROM analytics_alerts WHERE student_id=$1 AND section_id=$2', [mid, id]);
      await writeAuditLog(id, req.user.id, 'student_dropped', { studentId: mid, reason });
      return res.json({ message: 'Student dropped' });
    }
    res.json({ message: 'Membership updated' });
  } catch (err) { next(err); }
};

/**
 * POST /api/sections/:id/leave
 * Student-initiated soft leave: sets dropped_at = NOW() so the enrollment is
 * no longer active in student-facing queries, but the row and its analytics
 * history are preserved. Rejoining (POST /api/sections/join or an instructor
 * re-enroll) clears dropped_at and reactivates the enrollment.
 */
exports.leaveSection = async (req, res, next) => {
  const { id } = req.params;
  try {
    const r = await db.query(
      'UPDATE enrollments SET dropped_at = NOW() WHERE student_id=$1 AND section_id=$2 AND dropped_at IS NULL',
      [req.user.id, id]
    );
    if (r.rowCount === 0) return res.status(404).json({ error: 'Enrollment not found or already left' });
    await writeAuditLog(id, req.user.id, 'student_left', {});
    res.json({ message: 'Left section' });
  } catch (err) { next(err); }
};

exports.bulkImport = async (req, res, next) => {
  const { id } = req.params;
  const { emails } = req.body;
  if (!emails || !emails.length) return res.status(400).json({ error: 'Emails array required' });
  try {
    const found = await db.query(
      `SELECT id, email FROM users WHERE LOWER(email) = ANY($1) AND role='student'`,
      [emails.map(e => e.trim().toLowerCase())]
    );
    let enrolled = 0;
    for (const user of found.rows) {
      await db.query('INSERT INTO enrollments(student_id,section_id) VALUES($1,$2) ON CONFLICT DO NOTHING', [user.id, id]);
      enrolled++;
    }
    await writeAuditLog(id, req.user.id, 'bulk_import_run', { count: enrolled, total: emails.length });
    res.json({ message: `${enrolled} of ${emails.length} students enrolled` });
  } catch (err) { next(err); }
};

exports.getAuditLog = async (req, res, next) => {
  const { id } = req.params;
  try {
    const r = await db.query(
      `SELECT al.*, u.name AS actor_name FROM section_audit_log al
       LEFT JOIN users u ON u.id = al.actor_id
       WHERE al.section_id = $1 ORDER BY al.created_at DESC LIMIT 100`,
      [id]
    );
    res.json(r.rows);
  } catch (err) { next(err); }
};

exports.getDeptAudit = async (req, res, next) => {
  try {
    const r = await db.query(
      `SELECT al.*, u.name AS actor_name, s.name AS section_name FROM section_audit_log al
       LEFT JOIN users u ON u.id = al.actor_id
       JOIN sections s ON s.id = al.section_id
       ORDER BY al.created_at DESC LIMIT 200`
    );
    res.json(r.rows);
  } catch (err) { next(err); }
};

exports.updatePolicy = async (req, res, next) => {
  const { id } = req.params;
  const { join_policy } = req.body;
  if (!['code', 'request', 'closed'].includes(join_policy)) {
    return res.status(400).json({ error: 'Invalid policy. Use code, request, or closed.' });
  }
  try {
    const r = await db.query('UPDATE sections SET join_policy=$1 WHERE id=$2 RETURNING *', [join_policy, id]);
    await writeAuditLog(id, req.user.id, 'policy_changed', { from: r.rows[0].join_policy, to: join_policy });
    res.json(r.rows[0]);
  } catch (err) { next(err); }
};

exports.update = async (req, res, next) => {
  const { id } = req.params;
  const { name, course_code, school_year, semester } = req.body;
  try {
    const fields = [];
    const values = [];
    let idx = 1;
    if (name !== undefined) { fields.push(`name=$${idx++}`); values.push(name); }
    if (course_code !== undefined) { fields.push(`course_code=$${idx++}`); values.push(course_code); }
    if (school_year !== undefined) { fields.push(`school_year=$${idx++}`); values.push(school_year); }
    if (semester !== undefined) { fields.push(`semester=$${idx++}`); values.push(semester); }
    if (!fields.length) return res.status(400).json({ error: 'No fields to update' });
    values.push(id);
    const r = await db.query(
      `UPDATE sections SET ${fields.join(',')} WHERE id=$${idx} RETURNING *`,
      values
    );
    if (!r.rows.length) return res.status(404).json({ message: 'Section not found' });
    await writeAuditLog(id, req.user.id, 'section_updated', { fields: fields.map(f => f.split('=')[0]) });
    res.json(r.rows[0]);
  } catch (err) { next(err); }
};

exports.delete = async (req, res, next) => {
  const { id } = req.params;
  try {
    const sec = await db.query('SELECT * FROM sections WHERE id=$1', [id]);
    if (!sec.rows.length) return res.status(404).json({ error: 'Section not found' });
    if (sec.rows[0].instructor_id !== req.user.id) {
      return res.status(403).json({ error: 'Not authorized to delete this section' });
    }
    await writeAuditLog(id, req.user.id, 'section_deleted', { name: sec.rows[0].name });
    await db.query('DELETE FROM sections WHERE id=$1', [id]);
    res.json({ deleted: true, id: Number(id) });
  } catch (err) { next(err); }
};


