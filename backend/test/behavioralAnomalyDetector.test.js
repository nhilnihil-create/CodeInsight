jest.mock('../config/db', () => ({ query: jest.fn() }));

const db = require('../config/db');
const {
  detectInstantSuccess,
  detectExtremeSpeed,
  detectBehavioralAnomalies,
} = require('../services/behavioralAnomalyDetector');

describe('behavioralAnomalyDetector — detectInstantSuccess', function() {
  beforeEach(() => { jest.clearAllMocks(); });

  it('returns null when current submission is not correct', async function() {
    const result = await detectInstantSuccess({
      studentId: 1, exerciseId: 1, is_correct: false, attempt_number: 5,
    });
    expect(result).toBeNull();
  });

  it('returns null when there are fewer than 8 prior attempts', async function() {
    db.query.mockResolvedValue({ rows: [
      { attempt_number: 1, is_correct: false },
      { attempt_number: 2, is_correct: false },
      { attempt_number: 3, is_correct: false },
      { attempt_number: 4, is_correct: false },
    ]});
    const result = await detectInstantSuccess({
      studentId: 1, exerciseId: 1, is_correct: true, attempt_number: 5,
    });
    expect(result).toBeNull();
  });

  it('returns null when student already had prior successes', async function() {
    db.query.mockResolvedValue({ rows: [
      { attempt_number: 1, is_correct: true },
      { attempt_number: 2, is_correct: false },
      { attempt_number: 3, is_correct: false },
      { attempt_number: 4, is_correct: false },
      { attempt_number: 5, is_correct: false },
      { attempt_number: 6, is_correct: false },
      { attempt_number: 7, is_correct: false },
      { attempt_number: 8, is_correct: false },
    ]});
    const result = await detectInstantSuccess({
      studentId: 1, exerciseId: 1, is_correct: true, attempt_number: 9,
    });
    expect(result).toBeNull();
  });

  it('returns flag when 8+ consecutive failures followed by first success', async function() {
    db.query.mockResolvedValue({ rows: [
      { attempt_number: 1, is_correct: false },
      { attempt_number: 2, is_correct: false },
      { attempt_number: 3, is_correct: false },
      { attempt_number: 4, is_correct: false },
      { attempt_number: 5, is_correct: false },
      { attempt_number: 6, is_correct: false },
      { attempt_number: 7, is_correct: false },
      { attempt_number: 8, is_correct: false },
    ]});
    const result = await detectInstantSuccess({
      studentId: 1, exerciseId: 1, is_correct: true, attempt_number: 9,
    });
    expect(result).not.toBeNull();
    expect(result.type).toBe('BEHAVIORAL_ANOMALY');
    expect(result.severity).toBe('LOW');
    expect(result.evidence.subtype).toBe('INSTANT_SUCCESS');
    expect(result.evidence.priorFailureCount).toBe(8);
  });

  it('throws on database error', async function() {
    db.query.mockRejectedValue(new Error('DB down'));
    await expect(detectInstantSuccess({
      studentId: 1, exerciseId: 1, is_correct: true, attempt_number: 3,
    })).rejects.toThrow('DB down');
  });
});

describe('behavioralAnomalyDetector — detectExtremeSpeed', function() {
  beforeEach(() => { jest.clearAllMocks(); });

  it('returns null when submission is not correct', async function() {
    const result = await detectExtremeSpeed({
      studentId: 1, exerciseId: 1, is_correct: false, time_spent_seconds: 10,
    });
    expect(result).toBeNull();
  });

  it('returns null when time_spent_seconds is 0', async function() {
    const result = await detectExtremeSpeed({
      studentId: 1, exerciseId: 1, is_correct: true, time_spent_seconds: 0,
    });
    expect(result).toBeNull();
  });

  it('returns null when time_spent_seconds is null', async function() {
    const result = await detectExtremeSpeed({
      studentId: 1, exerciseId: 1, is_correct: true, time_spent_seconds: null,
    });
    expect(result).toBeNull();
  });

  it('returns null when fewer than 5 students have submitted', async function() {
    db.query.mockResolvedValue({ rows: [
      { student_id: 1, fastest_time: '100' },
      { student_id: 2, fastest_time: '120' },
      { student_id: 3, fastest_time: '90' },
    ]});
    const result = await detectExtremeSpeed({
      studentId: 4, exerciseId: 1, is_correct: true, time_spent_seconds: 10,
    });
    expect(result).toBeNull();
  });

  it('returns null when student is not an extreme outlier', async function() {
    db.query.mockResolvedValue({ rows: [
      { student_id: 1, fastest_time: '100' },
      { student_id: 2, fastest_time: '110' },
      { student_id: 3, fastest_time: '95' },
      { student_id: 4, fastest_time: '105' },
      { student_id: 5, fastest_time: '90' },
    ]});
    const result = await detectExtremeSpeed({
      studentId: 6, exerciseId: 1, is_correct: true, time_spent_seconds: 96,
    });
    expect(result).toBeNull();
  });

  it('flags student who is >2.5 robust std devs faster than class median', async function() {
    db.query.mockResolvedValue({ rows: [
      { student_id: 1, fastest_time: '200' },
      { student_id: 2, fastest_time: '220' },
      { student_id: 3, fastest_time: '190' },
      { student_id: 4, fastest_time: '210' },
      { student_id: 5, fastest_time: '195' },
      { student_id: 6, fastest_time: '205' },
      { student_id: 7, fastest_time: '215' },
    ]});

    const result = await detectExtremeSpeed({
      studentId: 8, exerciseId: 1, is_correct: true, time_spent_seconds: 30,
    });
    expect(result).not.toBeNull();
    expect(result.type).toBe('BEHAVIORAL_ANOMALY');
    expect(result.severity).toBe('LOW');
    expect(result.evidence.subtype).toBe('EXTREME_SPEED');
    expect(result.evidence.robustZscore).toBeLessThan(-2.5);
  });

  it('returns null when stddev is 0 (all same time)', async function() {
    db.query.mockResolvedValue({ rows: [
      { student_id: 1, fastest_time: '100' },
      { student_id: 2, fastest_time: '100' },
      { student_id: 3, fastest_time: '100' },
      { student_id: 4, fastest_time: '100' },
      { student_id: 5, fastest_time: '100' },
    ]});
    const result = await detectExtremeSpeed({
      studentId: 6, exerciseId: 1, is_correct: true, time_spent_seconds: 50,
    });
    expect(result).toBeNull();
  });

  it('throws on database error', async function() {
    db.query.mockRejectedValue(new Error('DB down'));
    await expect(detectExtremeSpeed({
      studentId: 1, exerciseId: 1, is_correct: true, time_spent_seconds: 10,
    })).rejects.toThrow('DB down');
  });
});

describe('behavioralAnomalyDetector — detectBehavioralAnomalies', function() {
  beforeEach(() => { jest.clearAllMocks(); });

  it('returns empty array when no anomalies detected', async function() {
    db.query.mockResolvedValue({ rows: [] });
    const result = await detectBehavioralAnomalies({
      studentId: 1, exerciseId: 1, is_correct: false, attempt_number: 1, time_spent_seconds: 100,
    });
    expect(result).toEqual([]);
  });

  it('returns flags from both detectors when triggered', async function() {
    db.query
      .mockResolvedValueOnce({ rows: [
        { attempt_number: 1, is_correct: false },
        { attempt_number: 2, is_correct: false },
        { attempt_number: 3, is_correct: false },
        { attempt_number: 4, is_correct: false },
        { attempt_number: 5, is_correct: false },
        { attempt_number: 6, is_correct: false },
        { attempt_number: 7, is_correct: false },
        { attempt_number: 8, is_correct: false },
      ]})
      .mockResolvedValueOnce({ rows: [
        { student_id: 1, fastest_time: '200' },
        { student_id: 2, fastest_time: '210' },
        { student_id: 3, fastest_time: '190' },
        { student_id: 4, fastest_time: '205' },
        { student_id: 5, fastest_time: '195' },
      ]});

    const result = await detectBehavioralAnomalies({
      studentId: 6, exerciseId: 1, is_correct: true, attempt_number: 9, time_spent_seconds: 30,
    });
    expect(result.length).toBe(2);
    expect(result[0].type).toBe('BEHAVIORAL_ANOMALY');
    expect(result[1].type).toBe('BEHAVIORAL_ANOMALY');
  });

  it('continues if one detector throws', async function() {
    db.query
      .mockRejectedValueOnce(new Error('DB error'))
      .mockResolvedValueOnce({ rows: [
        { student_id: 1, fastest_time: '200' },
        { student_id: 2, fastest_time: '210' },
        { student_id: 3, fastest_time: '190' },
        { student_id: 4, fastest_time: '205' },
        { student_id: 5, fastest_time: '195' },
      ]});

    const result = await detectBehavioralAnomalies({
      studentId: 6, exerciseId: 1, is_correct: true, attempt_number: 4, time_spent_seconds: 30,
    });
    expect(result.length).toBe(1);
    expect(result[0].evidence.subtype).toBe('EXTREME_SPEED');
  });
});
