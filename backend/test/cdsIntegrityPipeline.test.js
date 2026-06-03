/**
 * CDS + integrity production loop (unit-level, mocked DB)
 * submit → flags → live CDS metadata → close → batch CDS + notifications
 */

jest.mock('../config/db', () => ({ query: jest.fn() }));
jest.mock('../services/cdsEngine', () => ({
  computeBatchCDS: jest.fn().mockResolvedValue(undefined),
  calculateLiveCDS: jest.fn().mockResolvedValue({
    ner: 0.2,
    nrs: 0.3,
    nts: 0.4,
    cds: 0.28,
    classification: 'Low',
    hasFlaggedAttempt: true,
    integrityFlagCount: 1
  })
}));

const db = require('../config/db');
const cdsEngine = require('../services/cdsEngine');
const cdsJobQueue = require('../services/cdsJobQueue');
const academicIntegrityEngine = require('../services/academicIntegrityEngine');
const integrityFlagEngine = require('../services/integrityFlagEngine');

describe('CDS + integrity production loop', () => {
  beforeEach(() => {
    jest.clearAllMocks();
  });

  test('evaluateIntegrity and createFlag wire submit-side integrity', async () => {
    db.query
      .mockResolvedValueOnce({ rows: [{ avg_cds: 0.5, stddev_cds: 0.2, exercise_count: 2 }] })
      .mockResolvedValueOnce({ rows: [] });

    const flags = await academicIntegrityEngine.evaluateIntegrity({
      code: '#include <iostream>\nusing namespace std;\nint main() { cout << 42; return 0; }',
      starterCode: '#include <iostream>\nusing namespace std;\n\nint main() {\n  return 0;\n}',
      studentId: 2,
      exerciseId: 10,
      submission: { time_spent_seconds: 120, is_correct: false },
      exercise: { id: 10, starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  return 0;\n}' },
      cdsEngine,
      behavioralData: {}
    });

    expect(flags.some(f => f.type === 'HARDCODING')).toBe(true);

    db.query.mockResolvedValueOnce({
      rows: [{
        id: 99,
        flag_type: 'HARDCODING',
        severity: 'MEDIUM',
        student_id: 2,
        exercise_id: 10
      }]
    });

    const saved = await integrityFlagEngine.createFlag({
      sectionId: 1,
      exerciseId: 10,
      studentId: 2,
      flagType: flags[0].type,
      severity: flags[0].severity,
      evidence: flags[0].evidence,
      contextBehaviors: [],
      status: 'flagged',
      submissionId: 501
    });

    expect(saved.flag_type).toBe('HARDCODING');
    expect(db.query).toHaveBeenCalledWith(
      expect.stringContaining('INSERT INTO integrity_flags'),
      expect.any(Array)
    );
  });

  test('calculateLiveCDS exposes integrity_flag_count for live persistence', async () => {
    const live = await cdsEngine.calculateLiveCDS(2, 10, db);
    expect(live.integrityFlagCount).toBe(1);
    expect(live.hasFlaggedAttempt).toBe(true);
  });

  test('enqueueCdsComputation runs batch CDS and stores notifications', async () => {
    db.query
      .mockResolvedValueOnce({ rows: [{ section_id: 1 }] })
      .mockResolvedValueOnce({
        rows: [
          { student_id: 2, email: 'maria@student.psu.edu', name: 'Maria' }
        ]
      })
      .mockResolvedValueOnce({ rows: [] });

    await cdsJobQueue.enqueueCdsComputation(10);

    expect(cdsEngine.computeBatchCDS).toHaveBeenCalledWith(10, db);
    expect(db.query).toHaveBeenCalledWith(
      expect.stringContaining('INSERT INTO notifications'),
      expect.arrayContaining([2, 1, 10, 'CDS computation completed', 'cds_computation'])
    );
  });
});
