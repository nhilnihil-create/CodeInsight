jest.mock('../config/db');

const db = require('../config/db');

describe('verificationRulesService — getPatternsForConcept', function() {
  beforeEach(() => { jest.clearAllMocks(); });

  it('falls back to badPatterns.js when DB is unavailable', async function() {
    db.query = jest.fn().mockRejectedValue(new Error('DB down'));
    const { getPatternsForConcept } = require('../services/verificationRulesService');

    const patterns = await getPatternsForConcept('Variables');
    expect(Array.isArray(patterns)).toBe(true);
    expect(patterns.length).toBeGreaterThan(0);
  });

  it('falls back to badPatterns.js when concept not found', async function() {
    db.query.mockResolvedValueOnce({ rows: [] });
    const { getPatternsForConcept } = require('../services/verificationRulesService');

    const patterns = await getPatternsForConcept('Variables');
    expect(Array.isArray(patterns)).toBe(true);
    expect(patterns.length).toBeGreaterThan(0);
  });

  it('falls back to badPatterns.js when no DB rules found', async function() {
    db.query
      .mockResolvedValueOnce({ rows: [{ id: 1 }] })
      .mockResolvedValueOnce({ rows: [] });
    const { getPatternsForConcept } = require('../services/verificationRulesService');

    const patterns = await getPatternsForConcept('Variables');
    expect(Array.isArray(patterns)).toBe(true);
    expect(patterns.length).toBeGreaterThan(0);
  });

  it('returns mapped rules from DB when available', async function() {
    const dbRules = [
      { pattern_id: 'uninitialized_variable', tree_sitter_query: '(query here)',
        severity: 'error', student_message: 'Variable not initialized', handler: 'checkUninit' },
    ];
    db.query
      .mockResolvedValueOnce({ rows: [{ id: 1 }] })
      .mockResolvedValueOnce({ rows: dbRules });
    const { getPatternsForConcept } = require('../services/verificationRulesService');

    const patterns = await getPatternsForConcept('Variables');
    expect(patterns.length).toBe(1);
    expect(patterns[0].id).toBe('uninitialized_variable');
    expect(patterns[0].message).toBe('Variable not initialized');
    expect(patterns[0].handler).toBe('checkUninit');
  });
});

describe('verificationRulesService — getVariableUsageRule', function() {
  beforeEach(() => { jest.clearAllMocks(); });

  it('returns null when DB is unavailable', async function() {
    db.query = jest.fn().mockRejectedValue(new Error('DB down'));
    const { getVariableUsageRule } = require('../services/verificationRulesService');

    expect(await getVariableUsageRule('Variables')).toBeNull();
  });

  it('returns null when no rule found', async function() {
    db.query.mockResolvedValue({ rows: [] });
    const { getVariableUsageRule } = require('../services/verificationRulesService');

    expect(await getVariableUsageRule('Unknown')).toBeNull();
  });

  it('returns the rule when found', async function() {
    const mockRule = { student_message: 'Use variables properly', config: '{}', ast_nodes: '[]' };
    db.query.mockResolvedValue({ rows: [mockRule] });
    const { getVariableUsageRule } = require('../services/verificationRulesService');

    const result = await getVariableUsageRule('Variables');
    expect(result).toEqual(mockRule);
  });
});
