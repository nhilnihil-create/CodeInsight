// Renumber duplicate submission attempt numbers deterministically.
//
// Older code assigned attempt_number as COUNT(*)+1, which collided when two
// submits landed in the same (student_id, exercise_id) window. This migration
// renumbers every (student_id, exercise_id) group by (submitted_at, id) and is
// idempotent: once numbers are unique, the UPDATE touches zero rows. No
// UNIQUE constraint is added by design — the app computes the next number via
// MAX(attempt_number)+1.
module.exports = {
  up: async (db) => {
    await db.query(`
      WITH ranked AS (
        SELECT id,
               ROW_NUMBER() OVER (PARTITION BY student_id, exercise_id ORDER BY submitted_at, id) AS new_attempt
        FROM submissions
      )
      UPDATE submissions s
      SET attempt_number = r.new_attempt
      FROM ranked r
      WHERE r.id = s.id
        AND s.attempt_number IS DISTINCT FROM r.new_attempt
    `);
  },
  down: async () => {
    // Renumbering cannot be reversed — original duplicate numbering is lost.
  },
};
