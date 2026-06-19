const { hasExistingRule } = require('../services/errorClusterer');

describe('hasExistingRule', () => {
  it('returns true for "expected parse" which matches cc_missing_semicolon', () => {
    expect(hasExistingRule('expected parse')).toBe(true);
  });

  it('returns false for a novel pattern', () => {
    expect(hasExistingRule('linker returned exit status')).toBe(false);
  });

  it('returns false for empty string', () => {
    expect(hasExistingRule('')).toBe(false);
  });
});
