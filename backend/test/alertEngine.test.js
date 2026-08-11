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
const { generateAlerts, reconcileAlerts } = require('../services/alertEngine');

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
         ON CONFLICT (student_id,exercise_id) DO UPDATE SET
           section_id     = EXCLUDED.section_id,
           cds_score      = EXCLUDED.cds_score,
           classification = EXCLUDED.classification,
           concept_name   = EXCLUDED.concept_name,
           computed_at    = NOW(),
           dismissed      = false,
           dismissed_at   = NULL
         WHERE alerts.classification IN ('High','Prelim-High')`,
        [1, 1, 1, 0.8, 'High', 'Conditionals']
      );
      expect(db.query).toHaveBeenNthCalledWith(3,
        `INSERT INTO alerts
         (student_id,exercise_id,section_id,cds_score,classification,concept_name)
         VALUES($1,$2,$3,$4,$5,$6)
         ON CONFLICT (student_id,exercise_id) DO UPDATE SET
           section_id     = EXCLUDED.section_id,
           cds_score      = EXCLUDED.cds_score,
           classification = EXCLUDED.classification,
           concept_name   = EXCLUDED.concept_name,
           computed_at    = NOW(),
           dismissed      = false,
           dismissed_at   = NULL
         WHERE alerts.classification IN ('High','Prelim-High')`,
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
         ON CONFLICT (student_id,exercise_id) DO UPDATE SET
           section_id     = EXCLUDED.section_id,
           cds_score      = EXCLUDED.cds_score,
           classification = EXCLUDED.classification,
           concept_name   = EXCLUDED.concept_name,
           computed_at    = NOW(),
           dismissed      = false,
           dismissed_at   = NULL
         WHERE alerts.classification IN ('High','Prelim-High')`,
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

    it('should upsert on conflict so existing alerts are re-anchored, not duplicated', async function() {
      // Mock database query to return 1 student with High CDS
      db.query.mockResolvedValueOnce({ rows: [
        { student_id: 1, section_id: 1, cds: 0.8, classification: 'High', concept_name: 'Loops' }
      ] });

      // Mock the insert query
      db.query.mockResolvedValueOnce({ rowCount: 1 });

      const result = await generateAlerts(1, db);

      // The upsert re-anchors the existing row (updates CDS data, clears
      // dismissal) via ON CONFLICT ... DO UPDATE, guarded by the WHERE clause
      // so micro-concept alerts are never overwritten by a CDS recompute.
      expect(db.query).toHaveBeenNthCalledWith(2,
        `INSERT INTO alerts
         (student_id,exercise_id,section_id,cds_score,classification,concept_name)
         VALUES($1,$2,$3,$4,$5,$6)
         ON CONFLICT (student_id,exercise_id) DO UPDATE SET
           section_id     = EXCLUDED.section_id,
           cds_score      = EXCLUDED.cds_score,
           classification = EXCLUDED.classification,
           concept_name   = EXCLUDED.concept_name,
           computed_at    = NOW(),
           dismissed      = false,
           dismissed_at   = NULL
         WHERE alerts.classification IN ('High','Prelim-High')`,
        [1, 1, 1, 0.8, 'High', 'Loops']
      );

      assert.strictEqual(result.alertsGenerated, 1);
    });
  });

  describe('reconcileAlerts', function() {
    it('should dismiss active High/Prelim-High alerts for students who no longer qualify', async function() {
      db.query.mockResolvedValueOnce({ rowCount: 2 });

      await reconcileAlerts(10, db);

      expect(db.query).toHaveBeenCalledTimes(1);
      expect(db.query).toHaveBeenNthCalledWith(1,
        `UPDATE alerts a
     SET dismissed = true, dismissed_at = NOW()
     WHERE a.exercise_id = $1
       AND a.dismissed = false
       AND a.classification IN ('High','Prelim-High')
       AND NOT EXISTS (
         SELECT 1 FROM cds_scores cs
         WHERE cs.exercise_id = a.exercise_id
           AND cs.student_id = a.student_id
           AND cs.classification IN ('High','Prelim-High')
       )`,
        [10]
      );
    });

    it('should leave alerts for students still classified High untouched', async function() {
      db.query.mockResolvedValueOnce({ rowCount: 0 });

      await reconcileAlerts(10, db);

      // Only the UPDATE runs; the NOT EXISTS guard means a student whose
      // latest cds_scores row is still High/Prelim-High is not dismissed.
      expect(db.query).toHaveBeenCalledTimes(1);
      const [sql, params] = db.query.mock.calls[0];
      expect(sql).toContain('NOT EXISTS');
      expect(sql).toContain("cs.classification IN ('High','Prelim-High')");
      expect(params).toEqual([10]);
    });

    it('should propagate database errors', async function() {
      db.query.mockRejectedValueOnce(new Error('Database connection failed'));

      await assert.rejects(
        reconcileAlerts(10, db),
        /Database connection failed/
      );
    });
  });
});

console.log('Alert Engine test suite created');
