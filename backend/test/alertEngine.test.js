/**
 * Alert Engine Test Suite
 * Tests for the alertEngine.js service
 */

const assert = require('assert');

// We need to mock the db module before requiring the service
jest.mock('../config/db', () => ({
  query: jest.fn()
}));

const db = require('../config/db');
const { generateAlerts } = require('../services/alertEngine');

describe('Alert Engine Test Suite', function() {
  // Reset mocks before each test
  beforeEach(() => {
    jest.clearAllMocks();
  });

  describe('generateAlerts', function() {
    it('should generate alerts for students with High CDS classification', async function() {
      // Mock database query to return 2 students with High CDS
      db.query.mockResolvedValueOnce({ rows: [
        { student_id: 1, section_id: 1, cds: 0.8, classification: 'High', concept_name: 'Conditionals' },
        { student_id: 2, section_id: 1, cds: 0.75, classification: 'High', concept_name: 'Conditionals' }
      ] });

      // Mock the insert queries (1 for each student)
      db.query.mockResolvedValueOnce({ rowCount: 1 });
      db.query.mockResolvedValueOnce({ rowCount: 1 });

      const result = await generateAlerts(1, db);

      // Should have called the select query once followed by 2 inserts
      expect(db.query).toHaveBeenCalledTimes(3);
      expect(db.query).toHaveBeenNthCalledWith(1,
        `SELECT cs.student_id, cs.section_id, cs.cds, cs.classification,
            c.name AS concept_name
     FROM cds_scores cs
     JOIN exercises ex ON ex.id=cs.exercise_id
     JOIN concepts c ON c.id=ex.concept_id
     WHERE cs.exercise_id=$1 AND cs.classification = ANY($2::text[])`,
        [1, ['High', 'Prelim-High']]
      );
      expect(db.query).toHaveBeenNthCalledWith(2,
        `INSERT INTO alerts
       (student_id,exercise_id,section_id,cds_score,classification,concept_name)
       VALUES($1,$2,$3,$4,$5,$6)
       ON CONFLICT (student_id,exercise_id) DO NOTHING`,
        [1, 1, 1, 0.8, 'High', 'Conditionals']
      );
      expect(db.query).toHaveBeenNthCalledWith(3,
        `INSERT INTO alerts
       (student_id,exercise_id,section_id,cds_score,classification,concept_name)
       VALUES($1,$2,$3,$4,$5,$6)
       ON CONFLICT (student_id,exercise_id) DO NOTHING`,
        [2, 1, 1, 0.75, 'High', 'Conditionals']
      );

      assert.strictEqual(result.alertsGenerated, 2);
    });

    it('should not generate alerts when no students have High CDS', async function() {
      // Mock database query to return empty array
      db.query.mockResolvedValueOnce({ rows: [] });

      const result = await generateAlerts(1, db);

      // Should have called only the select query
      expect(db.query).toHaveBeenCalledTimes(1);
      expect(db.query).toHaveBeenNthCalledWith(1,
        `SELECT cs.student_id, cs.section_id, cs.cds, cs.classification,
            c.name AS concept_name
     FROM cds_scores cs
     JOIN exercises ex ON ex.id=cs.exercise_id
     JOIN concepts c ON c.id=ex.concept_id
     WHERE cs.exercise_id=$1 AND cs.classification = ANY($2::text[])`,
        [1, ['High', 'Prelim-High']]
      );

      // Should return 0 alerts generated
      assert.strictEqual(result.alertsGenerated, 0);
    });

    it('should also generate alerts for students with Prelim-High classification', async function() {
      // PRELIM-tier classes use Prelim-High; they are lower-trust but still flagged
      db.query.mockResolvedValueOnce({ rows: [
        { student_id: 5, section_id: 2, cds: 0.9, classification: 'Prelim-High', concept_name: 'Loops' }
      ] });

      db.query.mockResolvedValueOnce({ rowCount: 1 });

      const result = await generateAlerts(2, db);

      expect(db.query).toHaveBeenNthCalledWith(1,
        `SELECT cs.student_id, cs.section_id, cs.cds, cs.classification,
            c.name AS concept_name
     FROM cds_scores cs
     JOIN exercises ex ON ex.id=cs.exercise_id
     JOIN concepts c ON c.id=ex.concept_id
     WHERE cs.exercise_id=$1 AND cs.classification = ANY($2::text[])`,
        [2, ['High', 'Prelim-High']]
      );
      expect(db.query).toHaveBeenNthCalledWith(2,
        `INSERT INTO alerts
       (student_id,exercise_id,section_id,cds_score,classification,concept_name)
       VALUES($1,$2,$3,$4,$5,$6)
       ON CONFLICT (student_id,exercise_id) DO NOTHING`,
        [5, 2, 2, 0.9, 'Prelim-High', 'Loops']
      );

      assert.strictEqual(result.alertsGenerated, 1);
    });

    it('should handle database errors gracefully', async function() {
      // Mock database query to throw an error
      db.query.mockRejectedValueOnce(new Error('Database connection failed'));

      // The function should throw the error (not catch it internally)
      await assert.rejects(
        generateAlerts(1, db),
        /Database connection failed/
      );
    });

    it('should use INSERT ... ON CONFLICT DO NOTHING to avoid duplicates', async function() {
      // Mock database query to return 1 student with High CDS
      db.query.mockResolvedValueOnce({ rows: [
        { student_id: 1, section_id: 1, cds: 0.8, classification: 'High', concept_name: 'Loops' }
      ] });

      // Mock the insert query
      db.query.mockResolvedValueOnce({ rowCount: 1 });

      const result = await generateAlerts(1, db);

      // Check that the insert query uses ON CONFLICT clause
      expect(db.query).toHaveBeenNthCalledWith(2,
        `INSERT INTO alerts
       (student_id,exercise_id,section_id,cds_score,classification,concept_name)
       VALUES($1,$2,$3,$4,$5,$6)
       ON CONFLICT (student_id,exercise_id) DO NOTHING`,
        [1, 1, 1, 0.8, 'High', 'Loops']
      );

      assert.strictEqual(result.alertsGenerated, 1);
    });
  });
});

console.log('Alert Engine test suite created');
