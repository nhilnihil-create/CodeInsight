jest.mock('../config/db', () => ({ query: jest.fn() }));

const db = require('../config/db');
const { createFlag, getFlagsForExercise, getFlagsForSection, markFlagReviewed } = require('../services/integrityFlagEngine');

describe('integrityFlagEngine — createFlag', function() {
  beforeEach(() => { jest.clearAllMocks(); });

  it('creates a flag and returns the row', async function() {
    const mockRow = {
      id: 1, section_id: 1, exercise_id: 1, student_id: 1,
      flag_type: 'HARDCODING', severity: 'HIGH',
      evidence: '{"type":"hardcoding"}',
      context_behaviors: ['Hardcoded output'],
      status: 'flagged', created_at: new Date(),
      submission_id: null,
    };
    db.query.mockResolvedValue({ rows: [mockRow] });

    const result = await createFlag({
      sectionId: 1, exerciseId: 1, studentId: 1,
      flagType: 'HARDCODING', severity: 'HIGH',
      evidence: { type: 'hardcoding' },
      contextBehaviors: ['Hardcoded output'],
      status: 'flagged',
    });

    expect(result).toEqual(mockRow);
    expect(db.query).toHaveBeenCalledTimes(1);
  });

  it('upserts on conflict (exercise_id, student_id, flag_type)', async function() {
    const mockRow = { id: 1, severity: 'MEDIUM' };
    db.query.mockResolvedValue({ rows: [mockRow] });

    await createFlag({
      sectionId: 1, exerciseId: 1, studentId: 1,
      flagType: 'BEHAVIORAL_ANOMALY', severity: 'MEDIUM',
      evidence: {}, contextBehaviors: [], status: 'flagged',
    });

    const queryText = db.query.mock.calls[0][0];
    expect(queryText).toContain('ON CONFLICT');
    expect(queryText).toContain('exercise_id, student_id, flag_type');
  });

  it('includes submission_id when provided', async function() {
    db.query.mockResolvedValue({ rows: [{ id: 1 }] });

    await createFlag({
      sectionId: 1, exerciseId: 1, studentId: 1,
      flagType: 'CODE_PASTE', severity: 'LOW',
      evidence: {}, contextBehaviors: [], status: 'flagged',
      submissionId: 42,
    });

    expect(db.query.mock.calls[0][1][8]).toBe(42);
  });

  it('throws on database error', async function() {
    db.query.mockRejectedValue(new Error('DB error'));
    await expect(createFlag({
      sectionId: 1, exerciseId: 1, studentId: 1,
      flagType: 'TEST', severity: 'LOW', evidence: {}, contextBehaviors: [], status: 'flagged',
    })).rejects.toThrow('DB error');
  });
});

describe('integrityFlagEngine — getFlagsForExercise', function() {
  beforeEach(() => { jest.clearAllMocks(); });

  it('returns flags with parsed evidence and student name', async function() {
    db.query.mockResolvedValue({ rows: [
      { id: 1, student_id: 1, student_name: 'Alice', flag_type: 'HARDCODING',
        severity: 'HIGH', evidence: '{"type":"hardcoding"}', context_behaviors: [],
        status: 'flagged', created_at: new Date(), submission_id: null,
        exercise_id: 1, section_id: 1, reviewed_at: null, instructor_note: null },
    ]});

    const result = await getFlagsForExercise(1);
    expect(result.length).toBe(1);
    expect(result[0].student_name).toBe('Alice');
    expect(result[0].evidence).toEqual({ type: 'hardcoding' });
  });

  it('returns empty array when no flags exist', async function() {
    db.query.mockResolvedValue({ rows: [] });
    const result = await getFlagsForExercise(99);
    expect(result).toEqual([]);
  });

  it('throws on database error', async function() {
    db.query.mockRejectedValue(new Error('DB error'));
    await expect(getFlagsForExercise(1)).rejects.toThrow('DB error');
  });
});

describe('integrityFlagEngine — getFlagsForSection', function() {
  beforeEach(() => { jest.clearAllMocks(); });

  it('groups flags by exercise', async function() {
    db.query.mockResolvedValue({ rows: [
      { exercise_id: 1, exercise_title: 'Exercise 1', id: 1, student_id: 1,
        student_name: 'Alice', flag_type: 'HARDCODING', severity: 'HIGH',
        evidence: '{}', context_behaviors: [], status: 'flagged',
        created_at: new Date(), section_id: 1, reviewed_at: null, instructor_note: null, submission_id: null },
      { exercise_id: 1, exercise_title: 'Exercise 1', id: 2, student_id: 2,
        student_name: 'Bob', flag_type: 'BEHAVIORAL_ANOMALY', severity: 'MEDIUM',
        evidence: '{}', context_behaviors: [], status: 'flagged',
        created_at: new Date(), section_id: 1, reviewed_at: null, instructor_note: null, submission_id: null },
      { exercise_id: 2, exercise_title: 'Exercise 2', id: 3, student_id: 3,
        student_name: 'Charlie', flag_type: 'CODE_PASTE', severity: 'LOW',
        evidence: '{}', context_behaviors: [], status: 'flagged',
        created_at: new Date(), section_id: 1, reviewed_at: null, instructor_note: null, submission_id: null },
    ]});

    const result = await getFlagsForSection(1);
    expect(result.length).toBe(2);
    expect(result[0].exerciseId).toBe(1);
    expect(result[0].flags.length).toBe(2);
    expect(result[1].exerciseId).toBe(2);
    expect(result[0].exerciseTitle).toBe('Exercise 1');
  });

  it('returns empty array when no flags exist', async function() {
    db.query.mockResolvedValue({ rows: [] });
    const result = await getFlagsForSection(99);
    expect(result).toEqual([]);
  });
});

describe('integrityFlagEngine — markFlagReviewed', function() {
  beforeEach(() => { jest.clearAllMocks(); });

  it('marks a flag as reviewed with optional note', async function() {
    const mockRow = { id: 1, status: 'reviewed', instructor_note: 'False positive' };
    db.query.mockResolvedValue({ rows: [mockRow] });

    const result = await markFlagReviewed(1, 'False positive');
    expect(result.status).toBe('reviewed');
    expect(result.instructor_note).toBe('False positive');
  });

  it('works without an instructor note', async function() {
    const mockRow = { id: 1, status: 'reviewed', instructor_note: null };
    db.query.mockResolvedValue({ rows: [mockRow] });

    const result = await markFlagReviewed(1);
    expect(result.status).toBe('reviewed');
  });

  it('queries by flag id', async function() {
    db.query.mockResolvedValue({ rows: [{ id: 42 }] });
    await markFlagReviewed(42);
    expect(db.query.mock.calls[0][1][0]).toBe(42);
  });
});
