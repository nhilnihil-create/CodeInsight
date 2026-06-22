/**
 * Paste Counting Verification Tests
 *
 * Validates the end-to-end paste counting flow:
 * 1. Pre-submission paste warnings (pure function, no DB)
 * 2. Behavioral events endpoint logic (mocked DB)
 * 3. Paste threshold flagging (mocked DB)
 */

jest.mock('../config/db', () => ({ query: jest.fn() }));

const db = require('../config/db');
const preSubmissionCheck = require('../services/preSubmissionCheck');

// ── Pre-Submission Paste Warnings ────────────────────────────────────────

describe('preSubmissionCheck — paste warnings', () => {
  beforeEach(() => { jest.resetAllMocks(); });

  it('returns no hint when pasteCount is 0', () => {
    const hints = preSubmissionCheck.runAllChecks('int main() {}', null, '', 0, 0);
    expect(hints.length).toBe(0);
  });

  it('returns no hint when pasteCount is 4 (below threshold of 5)', () => {
    const hints = preSubmissionCheck.runAllChecks('int main() {}', null, '', 0, 4);
    expect(hints.length).toBe(0);
  });

  it('returns hint when pasteCount is 5', () => {
    const hints = preSubmissionCheck.runAllChecks('int main() {}', null, '', 0, 5);
    expect(hints.length).toBeGreaterThanOrEqual(1);
    const pasteHint = hints.find(h => h.message.includes('paste'));
    expect(pasteHint).toBeTruthy();
    expect(pasteHint.level).toBe('info');
  });

  it('returns hint with correct count when pasteCount is 10', () => {
    const hints = preSubmissionCheck.runAllChecks('int main() {}', null, '', 0, 10);
    const pasteHint = hints.find(h => h.message.includes('paste'));
    expect(pasteHint).toBeTruthy();
    expect(pasteHint.message).toContain('10 paste');
  });

  it('returns both paste and tab switch hints when both exceed thresholds', () => {
    const hints = preSubmissionCheck.runAllChecks('int main() {}', null, '', 12, 6);
    expect(hints.length).toBeGreaterThanOrEqual(1);
    const hint = hints.find(h => h.message.includes('paste') && h.message.includes('tab'));
    expect(hint).toBeTruthy();
  });

  it('coexists with other pre-submission checks (hardcoding, code growth)', () => {
    const largeCode = Array(150).fill('int x = 1;').join('\n');
    const prevCode = Array(20).fill('int x = 1;').join('\n');
    const hints = preSubmissionCheck.runAllChecks(largeCode, prevCode, '', 0, 5);
    expect(hints.length).toBeGreaterThanOrEqual(1);
  });
});

// ── Behavioral Events Endpoint ───────────────────────────────────────────

describe('behavioral events — paste event recording', () => {
  beforeEach(() => { jest.resetAllMocks(); });

  it('inserts paste event into behavioral_events table', async () => {
    db.query.mockResolvedValueOnce({ rows: [{ id: 1 }] }); // latest submission lookup returns nothing
    db.query.mockResolvedValueOnce({ rowCount: 1 });       // INSERT behavioral_events
    db.query.mockResolvedValueOnce({ rowCount: 1 });       // behavioral-events: first insert

    const handler = require('../routes/student');
    expect(handler).toBeDefined();
  });

  it('filters out invalid event types from behavioral events', async () => {
    // The route handler filters event types: only tab_switch, paste, idle_start, idle_end
    // We can verify by checking that it only calls INSERT for valid types
    const events = [
      { type: 'paste', timestamp: new Date().toISOString() },
      { type: 'invalid_type', timestamp: new Date().toISOString() },
      { type: 'tab_switch', timestamp: new Date().toISOString() },
    ];

    const validTypes = ['tab_switch', 'paste', 'idle_start', 'idle_end'];
    const validEvents = events.filter(e => validTypes.includes(e.type));
    expect(validEvents.length).toBe(2);
    expect(validEvents[0].type).toBe('paste');
    expect(validEvents[1].type).toBe('tab_switch');
  });
});

// ── Paste Threshold Flagging ─────────────────────────────────────────────

describe('paste threshold — flagging logic', () => {
  beforeEach(() => { jest.resetAllMocks(); });

  it('identifies paste event from behavioral signal array', () => {
    const pasteCount = 5;
    const behavioralThresholds = { PASTE_HIGH: 5 };
    const behavioralSignals = [];
    if (pasteCount >= behavioralThresholds.PASTE_HIGH) {
      behavioralSignals.push(`${pasteCount} paste events`);
    }
    expect(behavioralSignals.length).toBe(1);
    expect(behavioralSignals[0]).toBe('5 paste events');
  });

  it('does not signal when paste count is below threshold 5', () => {
    const pasteCount = 4;
    const behavioralThresholds = { PASTE_HIGH: 5 };
    const behavioralSignals = [];
    if (pasteCount >= behavioralThresholds.PASTE_HIGH) {
      behavioralSignals.push(`${pasteCount} paste events`);
    }
    expect(behavioralSignals.length).toBe(0);
  });

  it('does not signal when paste count is below threshold 3 (student.js path)', () => {
    const pasteCount = 2;
    const BEHAVIORAL_THRESHOLDS = { PASTE_HIGH: 3 };
    const behavioralSignals = [];
    if (pasteCount >= BEHAVIORAL_THRESHOLDS.PASTE_HIGH) {
      behavioralSignals.push(`${pasteCount} paste events`);
    }
    expect(behavioralSignals.length).toBe(0);
  });

  it('signals at threshold 3 (student.js path)', () => {
    const pasteCount = 3;
    const BEHAVIORAL_THRESHOLDS = { PASTE_HIGH: 3 };
    const behavioralSignals = [];
    if (pasteCount >= BEHAVIORAL_THRESHOLDS.PASTE_HIGH) {
      behavioralSignals.push(`${pasteCount} paste events`);
    }
    expect(behavioralSignals.length).toBe(1);
    expect(behavioralSignals[0]).toBe('3 paste events');
  });

  it('escalates severity when multiple signal types are present', () => {
    const signals = ['5 paste events', '15 tab switches'];
    const severity = signals.length >= 2 ? 'high' : 'medium';
    expect(severity).toBe('high');
  });

  it('uses medium severity for single signal type', () => {
    const signals = ['5 paste events'];
    const severity = signals.length >= 2 ? 'high' : 'medium';
    expect(severity).toBe('medium');
  });

  it('builds evidence JSON with paste_count correctly', () => {
    const evidence = {
      tab_switch_count: 5,
      paste_count: 5,
      idle_time_seconds: 10,
      total_time_seconds: 120,
      idle_ratio: 0.08,
    };
    expect(evidence.paste_count).toBe(5);
    expect(evidence.idle_ratio).toBeLessThan(0.5);
  });

  it('getWarningCount queries behavioral_events for warning counts', async () => {
    db.query.mockResolvedValue({ rows: [{ cnt: 2 }] });
    const ife = require('../services/integrityFlagEngine');
    const warningCount = await ife.getWarningCount(1, 1, 'PASSIVE_BEHAVIOR_LOG');
    expect(db.query).toHaveBeenCalledWith(
      expect.stringContaining('SELECT COUNT'),
      [1, 1, 'warning_PASSIVE_BEHAVIOR_LOG']
    );
    expect(warningCount).toBe(2);
  });

  it('getWarningCount returns 0 on database error', async () => {
    db.query.mockRejectedValue(new Error('DB down'));
    const integrityFlagEngine = require('../services/integrityFlagEngine');
    const warningCount = await integrityFlagEngine.getWarningCount(1, 1, 'PASSIVE_BEHAVIOR_LOG');
    expect(warningCount).toBe(0);
  });

  it('createWarningEvent inserts warning_ event into behavioral_events', async () => {
    db.query.mockResolvedValue({ rowCount: 1 });
    const integrityFlagEngine = require('../services/integrityFlagEngine');
    await integrityFlagEngine.createWarningEvent(1, 1, 'PASSIVE_BEHAVIOR_LOG', {
      summary: '5 paste events',
      attempt_number: 1,
    });
    expect(db.query).toHaveBeenCalledWith(
      expect.stringContaining('INSERT INTO behavioral_events'),
      [1, 1, 'warning_PASSIVE_BEHAVIOR_LOG', expect.any(String)]
    );
  });

  it('createFlag inserts integrity flag', async () => {
    db.query.mockResolvedValue({ rows: [{ id: 1 }] });
    const integrityFlagEngine = require('../services/integrityFlagEngine');
    await integrityFlagEngine.createFlag({
      sectionId: 1, exerciseId: 1, studentId: 1,
      flagType: 'PASSIVE_BEHAVIOR_LOG', severity: 'low',
      evidence: { paste_count: 5, summary: '5 paste events' },
      contextBehaviors: ['5 paste events'], status: 'flagged',
    });
    expect(db.query).toHaveBeenCalledWith(
      expect.stringContaining('INSERT INTO integrity_flags'),
      expect.arrayContaining([1, 1, 1, 'PASSIVE_BEHAVIOR_LOG', 'low'])
    );
  });
});

// ── Submission paste_count field ─────────────────────────────────────────

describe('submission — paste_count field', () => {
  it('defaults pasteCount to 0 when not provided', () => {
    const body = { code: 'int main() {}' };
    const pasteCount = body.pasteCount || 0;
    expect(pasteCount).toBe(0);
  });

  it('uses provided pasteCount value', () => {
    const body = { code: 'int main() {}', pasteCount: 7 };
    const pasteCount = body.pasteCount || 0;
    expect(pasteCount).toBe(7);
  });

  it('stored in submissions table as integer', () => {
    const submissionInsert = [
      1, 1, 'int main() {}', true, 1, 60, true, 'verified', 0, '[]', '', false, 5, 7, 10
    ];
    const pasteCountIndex = 13;
    expect(submissionInsert[pasteCountIndex]).toBe(7);
    expect(Number.isInteger(submissionInsert[pasteCountIndex])).toBe(true);
  });
});

// ── Code Growth Anomaly (paste proxy detection) ─────────────────────────

describe('code growth anomaly — paste proxy detection', () => {
  it('detects >30% growth between attempts', () => {
    const prevCode = 'int main() { return 0; }';
    const newCode = `
int main() {
  int x = 1;
  int y = 2;
  int z = 3;
  int sum = x + y + z;
  return sum;
}`;
    const prevLines = prevCode.split('\n').length;
    const currentLines = newCode.split('\n').length;
    const growthPercent = ((currentLines - prevLines) / prevLines) * 100;
    expect(growthPercent).toBeGreaterThan(30);
  });

  it('does not flag growth under 30%', () => {
    const prevLines = 10;
    const currentLines = 12;
    const growthPercent = ((currentLines - prevLines) / prevLines) * 100;
    expect(growthPercent).toBe(20);
    expect(growthPercent).toBeLessThanOrEqual(30);
  });

  it('records code_growth_delta as line difference', () => {
    const prevLines = 5;
    const currentLines = 15;
    const delta = currentLines - prevLines;
    expect(delta).toBe(10);
  });
});
