const { BAD_PATTERNS, getBadPatterns, getAllPatterns } = require('../services/badPatterns');

describe('badPatterns — structure', function() {
  it('exports BAD_PATTERNS as an object with concept keys', function() {
    expect(BAD_PATTERNS).toBeInstanceOf(Object);
    const concepts = Object.keys(BAD_PATTERNS);
    expect(concepts.length).toBeGreaterThan(0);
    expect(concepts).toContain('Datatypes');
    expect(concepts).toContain('Variables');
    expect(concepts).toContain('Conditionals');
    expect(concepts).toContain('Loops');
    expect(concepts).toContain('Functions');
    expect(concepts).toContain('Arrays');
    expect(concepts).toContain('OOP');
  });

  it('every pattern has required fields', function() {
    for (const [concept, patterns] of Object.entries(BAD_PATTERNS)) {
      for (const p of patterns) {
        expect(p.id).toBeTruthy();
        expect(p.description).toBeTruthy();
        expect(p.message).toBeTruthy();
        expect(typeof p.id).toBe('string');
        expect(typeof p.description).toBe('string');
        expect(typeof p.message).toBe('string');
      }
    }
  });

  it('every pattern has either a query or a handler', function() {
    for (const [concept, patterns] of Object.entries(BAD_PATTERNS)) {
      for (const p of patterns) {
        expect(p.query || p.handler).toBeTruthy();
      }
    }
  });

  it('pattern IDs are unique across all concepts', function() {
    const ids = [];
    for (const patterns of Object.values(BAD_PATTERNS)) {
      for (const p of patterns) {
        ids.push(p.id);
      }
    }
    expect(new Set(ids).size).toBe(ids.length);
  });
});

describe('badPatterns — getBadPatterns', function() {
  it('returns patterns for known concept', function() {
    const patterns = getBadPatterns('Variables');
    expect(Array.isArray(patterns)).toBe(true);
    expect(patterns.length).toBeGreaterThan(0);
  });

  it('returns empty array for unknown concept', function() {
    expect(getBadPatterns('UnknownConcept')).toEqual([]);
  });

  it('returns empty array for null', function() {
    expect(getBadPatterns(null)).toEqual([]);
  });

  it('returns empty array for undefined', function() {
    expect(getBadPatterns(undefined)).toEqual([]);
  });

  it('is case-sensitive', function() {
    expect(getBadPatterns('variables')).toEqual([]);
  });
});

describe('badPatterns — getAllPatterns', function() {
  it('returns a flat array of all patterns', function() {
    const all = getAllPatterns();
    expect(Array.isArray(all)).toBe(true);

    let total = 0;
    for (const patterns of Object.values(BAD_PATTERNS)) {
      total += patterns.length;
    }
    expect(all.length).toBe(total);
  });

  it('each pattern in all has a concept property', function() {
    const all = getAllPatterns();
    for (const p of all) {
      expect(p.concept).toBeTruthy();
      expect(typeof p.concept).toBe('string');
    }
  });

  it('does not mutate the original BAD_PATTERNS', function() {
    const original = Object.keys(BAD_PATTERNS).length;
    getAllPatterns();
    expect(Object.keys(BAD_PATTERNS).length).toBe(original);
  });
});
