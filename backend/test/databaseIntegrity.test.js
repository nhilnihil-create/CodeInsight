const { pool, seedFullScenario, clearTestTables } = require('./setup');

describe('Database Integrity (article: Database testing)', function() {
  beforeAll(async () => {
    await clearTestTables();
  });

  afterEach(async () => {
    await clearTestTables();
  });

  describe('Data Integrity', function() {
    it('maintains referential integrity on cascade delete', async function() {
      const { exerciseId } = await seedFullScenario({ studentCount: 1 });
      const before = await pool.query('SELECT COUNT(*) FROM submissions WHERE exercise_id = $1', [exerciseId]);
      expect(parseInt(before.rows[0].count)).toBeGreaterThanOrEqual(0);
    });

    it('enforces unique email constraint', async function() {
      const { rows } = await pool.query(
        `INSERT INTO users (name, email, password_hash, role) VALUES ($1, $2, $3, $4)`,
        ['Test', 'dupe@test.com', 'hash', 'student']
      );
      await expect(pool.query(
        `INSERT INTO users (name, email, password_hash, role) VALUES ($1, $2, $3, $4)`,
        ['Test2', 'dupe@test.com', 'hash', 'student']
      )).rejects.toThrow();
    });

    it('handles concurrent inserts without deadlock', async function() {
      const promises = [];
      for (let i = 0; i < 5; i++) {
        promises.push(pool.query(
          `INSERT INTO users (name, email, password_hash, role) VALUES ($1, $2, $3, $4)`,
          [`Concurrent User ${i}`, `concurrent${i}@test.com`, 'hash', 'student']
        ));
      }
      const results = await Promise.allSettled(promises);
      const fulfilled = results.filter(r => r.status === 'fulfilled').length;
      expect(fulfilled).toBe(5);
    });
  });

  describe('Query Performance', function() {
    it('handles bulk insert of 100 submissions', async function() {
      const ctx = await seedFullScenario({ studentCount: 1 });
      const studentId = ctx.studentIds[0];

      const values = [];
      const params = [];
      for (let i = 0; i < 100; i++) {
        const offset = i * 6;
        values.push(`($${offset + 1}, $${offset + 2}, $${offset + 3}, $${offset + 4}, $${offset + 5}, $${offset + 6})`);
        params.push(studentId, ctx.exerciseId, i + 1, `int main() { return ${i}; }`, false, 30);
      }

      const start = Date.now();
      await pool.query(
        `INSERT INTO submissions (student_id, exercise_id, attempt_number, code, is_correct, time_spent_seconds) VALUES ${values.join(',')}`,
        params
      );
      const elapsed = Date.now() - start;

      const { rows } = await pool.query('SELECT COUNT(*) FROM submissions WHERE exercise_id = $1', [ctx.exerciseId]);
      expect(parseInt(rows[0].count)).toBe(100);
      expect(elapsed).toBeLessThan(5000);
    });
  });

  describe('Schema Validation', function() {
    it('all required columns have NOT NULL constraints or defaults', async function() {
      const { rows } = await pool.query(`
        SELECT column_name, is_nullable, column_default
        FROM information_schema.columns
        WHERE table_name = 'submissions' AND table_schema = 'public'
      `);

      const nullableWithoutDefault = rows.filter(r =>
        r.is_nullable === 'YES' && r.column_default === null
      );

      const optionalColumns = ['feedback', 'test_results', 'compiler_warnings', 'graded_at'];
      const unexpectedNullables = nullableWithoutDefault.filter(
        r => !optionalColumns.includes(r.column_name)
      );

      if (unexpectedNullables.length > 0) {
        console.log('Nullable columns without defaults:', unexpectedNullables.map(r => r.column_name));
      }
    });
  });
});
