// Intervention queue tests: getInterventionQueue
// Verifies the cds_scores-based queue contract where risk is AVG-CDS based:
// a student enters the queue only when their AVERAGE CDS > 0.60 (the same
// signal as the dashboard at-risk banner). Worst-exercise CDS is display
// context only and must NOT pull students into the queue.

jest.mock('../config/db', () => ({ query: jest.fn() }));

const db = require('../config/db');
const controller = require('../controllers/analyticsController');

function mockRes() {
  return {
    status: jest.fn().mockReturnThis(),
    json: jest.fn().mockReturnThis(),
  };
}

describe('getInterventionQueue', () => {
  beforeEach(() => {
    jest.clearAllMocks();
  });

  it('returns 400 for a non-numeric, non-"all" sectionId without querying', async () => {
    const req = { params: { sectionId: 'abc' }, user: { id: 7 } };
    const res = mockRes();
    const next = jest.fn();

    await controller.getInterventionQueue(req, res, next);

    expect(db.query).not.toHaveBeenCalled();
    expect(res.status).toHaveBeenCalledWith(400);
    expect(res.json).toHaveBeenCalledWith(expect.objectContaining({ error: expect.any(String) }));
    expect(next).not.toHaveBeenCalled();
  });

  it('returns 404 when the section does not exist', async () => {
    db.query.mockResolvedValueOnce({ rows: [] });

    const req = { params: { sectionId: '99' }, user: { id: 7 } };
    const res = mockRes();
    const next = jest.fn();

    await controller.getInterventionQueue(req, res, next);

    expect(db.query).toHaveBeenCalledWith('SELECT id FROM sections WHERE id = $1', ['99']);
    expect(res.status).toHaveBeenCalledWith(404);
    expect(res.json).toHaveBeenCalledWith(expect.objectContaining({ error: 'Section not found' }));
  });

  it('keeps a student with a healthy average OUT of the queue even with one bad exercise', async () => {
    // Carol averages 0.35 (strong) but has a single exercise at 0.85 (critical).
    // The queue must NOT include her: filtering is avg-based, not worst-exercise.
    db.query.mockResolvedValueOnce({ rows: [{ id: 1 }] }); // section exists
    db.query.mockResolvedValueOnce({ rows: [{ total: 5 }] }); // 5 enrolled, 4 scored
    db.query.mockResolvedValueOnce({
      // Query A: per-student average CDS
      rows: [
        { student_id: 1, student_name: 'Alice', avg_cds: 0.90 },
        { student_id: 2, student_name: 'Bob', avg_cds: 0.70 },
        { student_id: 3, student_name: 'Carol', avg_cds: 0.35 },
        { student_id: 4, student_name: 'Dan', avg_cds: 0.10 },
      ],
    });
    db.query.mockResolvedValueOnce({
      // Query B: worst-exercise context (display only)
      rows: [
        { student_id: 1, exercise_id: 10, exercise_title: 'Loops Lab', concept_name: 'Loops', cds: 0.95, computed_at: '2026-08-10T10:00:00.000Z' },
        { student_id: 2, exercise_id: 11, exercise_title: 'Arrays Quiz', concept_name: 'Arrays', cds: 0.72, computed_at: '2026-08-10T10:00:00.000Z' },
        { student_id: 3, exercise_id: 12, exercise_title: 'Functions HW', concept_name: 'Functions', cds: 0.85, computed_at: '2026-08-10T10:00:00.000Z' },
        { student_id: 4, exercise_id: 13, exercise_title: 'OOP Lab', concept_name: 'OOP', cds: 0.10, computed_at: '2026-08-10T10:00:00.000Z' },
      ],
    });

    const req = { params: { sectionId: '1' }, user: { id: 7 } };
    const res = mockRes();
    const next = jest.fn();

    await controller.getInterventionQueue(req, res, next);

    expect(next).not.toHaveBeenCalled();
    expect(res.status).not.toHaveBeenCalled();

    // Query A averages cds_scores per student (active enrollments only)
    const avgSql = db.query.mock.calls[2][0];
    expect(avgSql).toContain('AVG(cs.cds)');
    expect(avgSql).toContain('GROUP BY cs.student_id');
    expect(avgSql).toContain('en.dropped_at IS NULL');

    // Query B still grabs worst-exercise rows for context
    const worstSql = db.query.mock.calls[3][0];
    expect(worstSql).toContain('DISTINCT ON (cs.student_id)');
    expect(worstSql).toContain('ORDER BY cs.student_id, cs.cds DESC');

    const payload = res.json.mock.calls[0][0];
    expect(payload.sectionId).toBe(1);
    expect(payload.totalStudents).toBe(5);

    // Only avg-CDS > 0.60 students qualify — Carol (worst 0.85) is excluded.
    expect(payload.atRisk.map((s) => s.studentName)).toEqual(['Alice', 'Bob']);

    // Row shape: avgCds drives tier and sort; worstCds is context only.
    expect(payload.atRisk[0]).toEqual(
      expect.objectContaining({
        studentId: 1,
        studentName: 'Alice',
        avgCds: 0.9,
        exerciseId: 10,
        exerciseTitle: 'Loops Lab',
        conceptName: 'Loops',
        worstCds: 0.95,
        computedAt: '2026-08-10T10:00:00.000Z',
        tier: 'critical',
      })
    );
    // Bob: avg 0.70 -> needs_support (not critical, despite worst 0.72 mapping
    // to needs_support too — the assertion is that tier derives from AVG).
    expect(payload.atRisk[1].tier).toBe('needs_support');
    expect(payload.atRisk[1].avgCds).toBe(0.7);

    // 6-tier distribution counted per-student from AVG CDS:
    // Alice critical, Bob needs_support, Carol strong, Dan excellent.
    expect(payload.tierDistribution).toEqual({
      excellent: 1,
      strong: 1,
      developing: 0,
      needs_support: 1,
      critical: 1,
      unstarted: 1, // 5 enrolled - 4 scored
    });

    expect(payload.insight).toEqual(
      expect.objectContaining({
        atRiskCount: 2,
        summary: expect.stringContaining('2 students are at high risk'),
      })
    );
  });

  it('supports the "all" scope using the instructor id and skips the section check', async () => {
    db.query.mockResolvedValueOnce({ rows: [{ total: 2 }] }); // enrollments across sections
    db.query.mockResolvedValueOnce({
      rows: [
        { student_id: 5, student_name: 'Eve', avg_cds: 0.85 },
        { student_id: 6, student_name: 'Frank', avg_cds: 0.25 },
      ],
    });
    db.query.mockResolvedValueOnce({
      rows: [
        { student_id: 5, exercise_id: 20, exercise_title: 'Conditionals Lab', concept_name: 'Conditionals', cds: 0.88, computed_at: '2026-08-10T10:00:00.000Z' },
        { student_id: 6, exercise_id: 21, exercise_title: 'Variables HW', concept_name: 'Variables', cds: 0.30, computed_at: '2026-08-10T10:00:00.000Z' },
      ],
    });

    const req = { params: { sectionId: 'all' }, user: { id: 7 } };
    const res = mockRes();
    const next = jest.fn();

    await controller.getInterventionQueue(req, res, next);

    // Only 3 queries: enrollment count + per-student avg + worst-exercise context
    expect(db.query).toHaveBeenCalledTimes(3);

    const enrollSql = db.query.mock.calls[0][0];
    expect(enrollSql).toContain('section_id IN (SELECT id FROM sections WHERE instructor_id = $1)');
    expect(db.query.mock.calls[0][1]).toEqual(['7']);

    const avgSql = db.query.mock.calls[1][0];
    expect(avgSql).toContain('cs.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)');
    expect(db.query.mock.calls[1][1]).toEqual(['7']);

    const worstSql = db.query.mock.calls[2][0];
    expect(worstSql).toContain('cs.section_id IN (SELECT id FROM sections WHERE instructor_id = $1)');

    const payload = res.json.mock.calls[0][0];
    expect(payload.sectionId).toBe('all');
    expect(payload.totalStudents).toBe(2);
    expect(payload.atRisk).toHaveLength(1);
    expect(payload.atRisk[0].studentName).toBe('Eve');
    expect(payload.atRisk[0].worstCds).toBe(0.88);
    expect(payload.insight.summary).toContain('your sections');
  });
});
