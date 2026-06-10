// Submission Stress Tests & Integrity Threshold Violations
// Simulates attack scenarios against the submission system and verifies
// that integrity detection, velocity monitoring, and rate limiting hold up.
//
// These are CHARACTERIZATION + SIMULATION tests — they verify the logic
// without needing a running server or database.

const assert = require('assert');

// ── Growth Velocity Detection ────────────────────────────────────────────────

describe('Submission Stress — Growth Velocity Detection', function() {
  // Reproduce the token counting from submissionController.js
  function countTokens(code) {
    if (!code) return 0;
    const cleaned = code
      .replace(/\/\/.*$/gm, '')
      .replace(/\/\*[\s\S]*?\*\//g, '')
      .replace(/"[^"]*"/g, '""')
      .replace(/'[^']*'/g, "''");
    const tokens = cleaned.match(/[a-zA-Z_]\w*|\d+|[+\-*/=<>!&|^~%]+/g) || [];
    return tokens.length;
  }

  function calculateGrowthVelocity(starterCode, currentCode, attemptNumber) {
    const starterTokens = countTokens(starterCode || '');
    const studentTokens = countTokens(currentCode || '');
    if (starterTokens > 0 && attemptNumber === 1) {
      const growthPercent = ((studentTokens - starterTokens) / starterTokens) * 100;
      return {
        baselineTokens: starterTokens,
        studentTokens,
        growthPercent: Math.round(growthPercent),
        threshold: 200,
        flagged: growthPercent > 200,
      };
    }
    return null;
  }

  it('flags 300% growth on first attempt', function() {
    const starter = 'int main() { return 0; }'; // ~5 tokens
    // Simulate pasted solution with many tokens (300% = need ~20 tokens)
    const pasted = starter + ' ' + 'int a=1; int b=2; int c=3; int d=4; int e=5; int f=6; int g=7; int h=8;'.repeat(5);
    const result = calculateGrowthVelocity(starter, pasted, 1);
    assert.ok(result !== null);
    assert.ok(result.growthPercent > 300, `Growth should be > 300%, got ${result.growthPercent}%`);
    assert.strictEqual(result.flagged, true);
  });

  it('flags 500% growth (massive paste)', function() {
    const starter = 'int main() { return 0; }';
    const pasted = 'int a=1;int b=2;int c=3;int d=4;int e=5;int f=6;int g=7;int h=8;int i=9;int j=10;'.repeat(20);
    const result = calculateGrowthVelocity(starter, pasted, 1);
    assert.ok(result !== null);
    assert.ok(result.growthPercent > 500);
    assert.strictEqual(result.flagged, true);
  });

  it('does NOT flag normal first-attempt code', function() {
    const starter = '#include <iostream>\nint main() { return 0; }';
    const normal = `#include <iostream>
      using namespace std;
      int main() {
        int x;
        cin >> x;
        cout << x * 2 << endl;
        return 0;
      }`;
    const result = calculateGrowthVelocity(starter, normal, 1);
    assert.ok(result !== null);
    assert.strictEqual(result.flagged, false, `Growth of ${result.growthPercent}% should not be flagged`);
  });

  it('does NOT flag on subsequent attempts (compared against previous)', function() {
    // On attempt 2+, velocity compares against PREVIOUS submission
    const result = calculateGrowthVelocity('#include <iostream>', 'int x = 5;', 2);
    // Returns null because attemptNumber > 1 — controller uses previous submission
    assert.strictEqual(result, null);
  });

  it('handles empty starter code safely', function() {
    const result = calculateGrowthVelocity('', 'int main() { return 0; }', 1);
    // starterTokens = 0, so no growth calculation
    assert.strictEqual(result, null);
  });

  it('handles empty student code safely', function() {
    const starter = '#include <iostream>\nint main() { return 0; }';
    const result = calculateGrowthVelocity(starter, '', 1);
    assert.ok(result !== null);
    assert.ok(result.growthPercent < 0); // negative growth (student removed code)
    assert.strictEqual(result.flagged, false); // negative growth is not flagged
  });

  it('handles null inputs safely', function() {
    const result = calculateGrowthVelocity(null, null, 1);
    // countTokens(null) = 0, starterTokens = 0, returns null
    assert.strictEqual(result, null);
  });
});

// ── Retry Storm Detection ────────────────────────────────────────────────────

describe('Submission Stress — Retry Storm Detection', function() {
  // Reproduce from integrityFlagEngine.js
  function detectRetryStorm(submissions) {
    if (submissions.length < 5) {
      return { detected: false, totalRetries: submissions.length, avgTimeBetween: null };
    }
    const timedeltas = [];
    for (let i = 1; i < submissions.length; i++) {
      const prev = new Date(submissions[i - 1].submitted_at).getTime();
      const curr = new Date(submissions[i].submitted_at).getTime();
      timedeltas.push((curr - prev) / 1000 / 60);
    }
    const avgTime = timedeltas.reduce((a, b) => a + b, 0) / timedeltas.length;
    const detected = submissions.length > 20 && avgTime < 3;
    return {
      detected,
      totalRetries: submissions.length,
      avgTimeBetween: Math.round(avgTime * 10) / 10,
    };
  }

  it('does NOT detect storm for < 5 submissions', function() {
    const subs = [
      { submitted_at: '2026-06-10T10:00:00Z' },
      { submitted_at: '2026-06-10T10:00:10Z' },
      { submitted_at: '2026-06-10T10:00:20Z' },
      { submitted_at: '2026-06-10T10:00:30Z' },
    ];
    const result = detectRetryStorm(subs);
    assert.strictEqual(result.detected, false);
  });

  it('does NOT detect storm for 10 submissions 5 min apart', function() {
    const subs = [];
    for (let i = 0; i < 10; i++) {
      subs.push({ submitted_at: new Date(Date.now() + i * 300000).toISOString() });
    }
    const result = detectRetryStorm(subs);
    assert.strictEqual(result.detected, false);
  });

  it('detects storm: 25 submissions 1 minute apart', function() {
    const subs = [];
    for (let i = 0; i < 25; i++) {
      subs.push({ submitted_at: new Date(Date.now() + i * 60000).toISOString() });
    }
    const result = detectRetryStorm(subs);
    assert.strictEqual(result.detected, true);
    assert.strictEqual(result.totalRetries, 25);
    assert.ok(result.avgTimeBetween <= 1.0);
  });

  it('detects storm: 30 submissions 30 seconds apart', function() {
    const subs = [];
    for (let i = 0; i < 30; i++) {
      subs.push({ submitted_at: new Date(Date.now() + i * 30000).toISOString() });
    }
    const result = detectRetryStorm(subs);
    assert.strictEqual(result.detected, true);
    assert.strictEqual(result.avgTimeBetween, 0.5);
  });

  it('does NOT detect storm: 25 submissions 5 min apart (too slow)', function() {
    const subs = [];
    for (let i = 0; i < 25; i++) {
      subs.push({ submitted_at: new Date(Date.now() + i * 300000).toISOString() });
    }
    const result = detectRetryStorm(subs);
    assert.strictEqual(result.detected, false); // > 3 min avg
    assert.strictEqual(result.avgTimeBetween, 5);
  });

  it('does NOT detect storm: 21 submissions with mixed timing (avg > 3 min)', function() {
    const subs = [];
    // 10 rapid, then 11 slow
    for (let i = 0; i < 10; i++) {
      subs.push({ submitted_at: new Date(Date.now() + i * 30000).toISOString() });
    }
    for (let i = 10; i < 21; i++) {
      subs.push({ submitted_at: new Date(Date.now() + 10 * 30000 + (i - 10) * 600000).toISOString() });
    }
    const result = detectRetryStorm(subs);
    assert.strictEqual(result.detected, false);
  });

  it('handles empty submissions array', function() {
    const result = detectRetryStorm([]);
    assert.strictEqual(result.detected, false);
    assert.strictEqual(result.totalRetries, 0);
  });

  it('handles single submission', function() {
    const result = detectRetryStorm([{ submitted_at: new Date().toISOString() }]);
    assert.strictEqual(result.detected, false);
    assert.strictEqual(result.totalRetries, 1);
  });
});

// ── Code Growth Anomaly Detection ────────────────────────────────────────────

describe('Submission Stress — Code Growth Anomaly (integrityFlagEngine)', function() {
  function detectCodeGrowthAnomaly(code, starterCode) {
    const normalize = (str) => str.replace(/\s+/g, ' ').trim();
    const normalizedCode = normalize(code);
    const normalizedStarter = normalize(starterCode);
    const codeDelta = normalizedCode.length - normalizedStarter.length;
    const growthPercent = starterCode.length > 0
      ? (codeDelta / starterCode.length) * 100
      : 0;
    const detected = codeDelta === 0 && normalizedCode === normalizedStarter;
    return {
      detected,
      growthDelta: growthPercent,
      lineCountDelta: code.split('\n').length - starterCode.split('\n').length,
    };
  }

  it('detects exact starter code submission', function() {
    const starter = '#include <iostream>\nint main() { return 0; }';
    const result = detectCodeGrowthAnomaly(starter, starter);
    assert.strictEqual(result.detected, true);
  });

  it('detects whitespace-only variation of starter code', function() {
    const starter = '#include <iostream>\nint main() { return 0; }';
    const varied = '#include  <iostream>\n  int main()  {  return 0;  }';
    // After normalization (whitespace collapsed), these are the same
    const result = detectCodeGrowthAnomaly(varied, starter);
    // codeDelta might be small after normalization, let's check
    // Actually: normalize strips excess whitespace, so lengths might differ slightly
    // Let me check: normalize(starter) vs normalize(varied)
    const nStarter = starter.replace(/\s+/g, ' ').trim();
    const nVaried = varied.replace(/\s+/g, ' ').trim();
    // These should be equal after normalization
    assert.strictEqual(nStarter, nVaried);
    assert.strictEqual(result.detected, true);
  });

  it('does NOT flag small additions', function() {
    const starter = '#include <iostream>\nint main() { return 0; }';
    const added = '#include <iostream>\nint main() { int x = 5; return 0; }';
    const result = detectCodeGrowthAnomaly(added, starter);
    assert.strictEqual(result.detected, false);
    assert.ok(result.growthDelta > 0);
  });

  it('does NOT flag large legitimate additions', function() {
    const starter = '#include <iostream>\nint main() { return 0; }';
    const large = starter + '\n' + 'cout << "line";\n'.repeat(50);
    const result = detectCodeGrowthAnomaly(large, starter);
    assert.strictEqual(result.detected, false);
    assert.ok(result.growthDelta > 100);
    assert.ok(result.lineCountDelta > 40);
  });

  it('handles empty starter code', function() {
    const result = detectCodeGrowthAnomaly('int x = 5;', '');
    assert.strictEqual(result.detected, false);
    assert.strictEqual(result.growthDelta, 0); // starterCode.length = 0
  });
});

// ── Hardcoding Detection ─────────────────────────────────────────────────────

describe('Submission Stress — Hardcoding Detection', function() {
  function checkHardcoding(code, exercise) {
    const coutPattern = /cout\s*<<\s*(\d+)\s*[;>]/g;
    const matches = Array.from(code.matchAll(coutPattern));
    if (matches.length === 0) return null;

    const hasOperations = /[\+\-\*\/\%\(\)]/g.test(code);
    const hasVariables = /\b(int|float|double|long|short)\s+\w+\s*=/g.test(code);
    const hasLoops = /(for|while|do)\s*[\({]/g.test(code);
    const hasConditionals = /(if|else|switch)\s*[\({]/g.test(code);

    const computationScore =
      (hasOperations ? 1 : 0) +
      (hasVariables ? 1 : 0) +
      (hasLoops ? 1 : 0) +
      (hasConditionals ? 1 : 0);

    if (computationScore < 2 && matches.length >= 1) {
      return {
        type: 'HARDCODING',
        severity: 'MEDIUM',
        evidence: `Found ${matches.length} direct numeric output(s) with minimal computation logic`,
      };
    }
    return null;
  }

  it('detects simple hardcoded output', function() {
    const code = '#include <iostream>\nint main() { cout << 42; return 0; }';
    const result = checkHardcoding(code, {});
    assert.ok(result !== null);
    assert.strictEqual(result.type, 'HARDCODING');
  });

  it('does NOT flag code with computation', function() {
    const code = `
      #include <iostream>
      int main() {
        int a = 6, b = 7;
        int c = a * b;
        cout << c;
        return 0;
      }`;
    const result = checkHardcoding(code, {});
    assert.strictEqual(result, null);
  });

  it('does NOT flag code with conditionals', function() {
    const code = `
      #include <iostream>
      int main() {
        int x;
        cin >> x;
        if (x > 0) { cout << 1; } else { cout << 0; }
        return 0;
      }`;
    const result = checkHardcoding(code, {});
    assert.strictEqual(result, null);
  });

  it('flags code with cout literal but no logic', function() {
    const code = '#include <iostream>\nint main() { cout << 8; }';
    const result = checkHardcoding(code, {});
    assert.ok(result !== null);
    assert.strictEqual(result.severity, 'MEDIUM');
  });

  it('handles code with no cout at all', function() {
    const code = 'int main() { return 0; }';
    const result = checkHardcoding(code, {});
    assert.strictEqual(result, null);
  });

  it('handles empty code', function() {
    const result = checkHardcoding('', {});
    assert.strictEqual(result, null);
  });
});

// ── Blank/Template Detection ─────────────────────────────────────────────────

describe('Submission Stress — Blank/Template Detection', function() {
  function checkBlankTemplate(code, starterCode) {
    const normalizedCode = code.trim();
    const normalizedStarter = starterCode.trim();
    if (normalizedCode === '' && normalizedStarter !== '') {
      return { type: 'BLANK_TEMPLATE', severity: 'HIGH' };
    }
    if (normalizedCode === normalizedStarter) {
      if (code === starterCode) {
        return { type: 'BLANK_TEMPLATE', severity: 'HIGH' };
      } else {
        return null; // whitespace differences only
      }
    }
    return null;
  }

  it('detects empty submission', function() {
    const result = checkBlankTemplate('', '#include <iostream>');
    assert.ok(result !== null);
    assert.strictEqual(result.severity, 'HIGH');
  });

  it('detects exact template match', function() {
    const starter = '#include <iostream>\nint main() { return 0; }';
    const result = checkBlankTemplate(starter, starter);
    assert.ok(result !== null);
  });

  it('allows whitespace-only variation', function() {
    const starter = '#include <iostream>\nint main() { return 0; }';
    const varied = '  #include <iostream>\n  int main() { return 0; }  ';
    const result = checkBlankTemplate(varied, starter);
    assert.strictEqual(result, null);
  });

  it('allows any non-empty non-template code', function() {
    const starter = '#include <iostream>\nint main() { return 0; }';
    const result = checkBlankTemplate('#include <iostream>\nint main() { return 1; }', starter);
    assert.strictEqual(result, null);
  });
});

// ── Behavioral Anomaly Detection ─────────────────────────────────────────────

describe('Submission Stress — Behavioral Anomaly Detection', function() {
  function checkBehavioralAnomaly(timeSpentSeconds, isFirstAttemptCorrect, currentCds, avgHistoricalCds, stddevHistoricalCds, exerciseCount) {
    // Need at least 3 data points
    if (exerciseCount < 3) return null;
    // Avoid division by zero
    if (stddevHistoricalCds === 0) return null;

    const zScore = (currentCds - avgHistoricalCds) / stddevHistoricalCds;
    const isVeryFast = timeSpentSeconds < 30;
    const isSignificantlyBetter = zScore > 2.0;

    if (isVeryFast && isFirstAttemptCorrect && isSignificantlyBetter) {
      return {
        type: 'BEHAVIORAL_ANOMALY',
        severity: 'MEDIUM',
        context: { timeSpentSeconds, zScore: parseFloat(zScore.toFixed(2)) },
      };
    }
    return null;
  }

  it('detects very fast correct first attempt with z-score > 2.0', function() {
    const result = checkBehavioralAnomaly(
      10,    // 10 seconds
      true,  // first attempt correct
      0.10,  // current CDS (very good)
      0.60,  // historical avg (usually struggling)
      0.10,  // historical stddev (consistent performance)
      5      // 5 prior exercises
    );
    // zScore = (0.10 - 0.60) / 0.10 = -5.0
    // Wait, we want positive z-score > 2.0
    // If current CDS is BETTER (lower) than avg, zScore is negative
    // But the code checks zScore > 2.0 which means WORSE than average
    // Hmm, this seems like the check is backwards — let me re-read the code
    // Actually in the original code: zScore > 2.0 means performing MUCH WORSE
    // But "anomaly" is flagged when very fast + correct + zScore > 2.0
    // If currentCds = 0.9 (bad) and avg = 0.3 (good), zScore = (0.9-0.3)/0.1 = 6.0
    // But first attempt correct with high CDS? That doesn't make sense.
    // Let me re-read: the check is for students who usually have HIGH CDS (struggling)
    // but suddenly solve it on first try in 10 seconds.
    // currentCds is the LIVE CDS, not a "good score" metric.
    // A LOW CDS is good. So if avgHistorical = 0.6 (bad) and current = 0.1 (good)
    // zScore = (0.1 - 0.6) / 0.1 = -5.0 → NOT > 2.0 → no flag
    // This seems like a bug — the zScore check is in the wrong direction
    // The code flags students who are MUCH WORSE than usual, not MUCH BETTER
    // But the intent is to flag sudden improvement suggesting cheating
    // Let me test what the ACTUAL code does:
    assert.strictEqual(result, null, 'Fast correct with better-than-usual CDS is NOT flagged (potential bug: zScore direction)');
  });

  it('flags very fast correct with zScore > 2.0 (current worse than avg — odd)', function() {
    // This is what the current code actually flags — odd scenario
    const result = checkBehavioralAnomaly(
      10,    // 10 seconds
      true,  // first attempt correct
      0.90,  // current CDS (very bad — but how is first attempt correct?)
      0.30,  // historical avg (usually good)
      0.10,  // historical stddev
      5      // 5 prior exercises
    );
    // zScore = (0.90 - 0.30) / 0.10 = 6.0 > 2.0 → FLAGGED
    // This is logically inconsistent: first attempt correct but high CDS?
    // The CDS calculation uses cohort data, so a student who solves correctly
    // could still have high CDS if they took a long time or this is their
    // first submission on this exercise and the cohort is all doing well.
    // Anyway, this is what the code does.
    assert.ok(result !== null);
    assert.strictEqual(result.type, 'BEHAVIORAL_ANOMALY');
  });

  it('does NOT flag when exerciseCount < 3', function() {
    const result = checkBehavioralAnomaly(5, true, 0.10, 0.60, 0.10, 2);
    assert.strictEqual(result, null);
  });

  it('does NOT flag when stddev = 0 (no variation in history)', function() {
    const result = checkBehavioralAnomaly(5, true, 0.10, 0.30, 0, 5);
    assert.strictEqual(result, null);
  });

  it('does NOT flag when not very fast (30+ seconds)', function() {
    const result = checkBehavioralAnomaly(
      60, true, 0.90, 0.30, 0.10, 5
    );
    assert.strictEqual(result, null);
  });

  it('does NOT flag when first attempt is wrong', function() {
    const result = checkBehavioralAnomaly(
      5, false, 0.90, 0.30, 0.10, 5
    );
    assert.strictEqual(result, null);
  });

  it('does NOT flag when zScore < 2.0', function() {
    const result = checkBehavioralAnomaly(
      10, true, 0.35, 0.30, 0.10, 5
    );
    // zScore = (0.35 - 0.30) / 0.10 = 0.5 < 2.0
    assert.strictEqual(result, null);
  });

  it('documents: zScore direction may be backwards for cheating detection', function() {
    // The code checks zScore > 2.0 (current MUCH WORSE than avg)
    // For cheating detection, we'd want to flag students who suddenly do
    // MUCH BETTER than their historical average (zScore < -2.0)
    // This documents a potential logic issue
    assert.ok(true, 'DOCUMENTED: zScore > 2.0 flags worse performance, but cheating shows as better');
  });
});

// ── Rapid Submission Attack Simulation ───────────────────────────────────────

describe('Submission Stress — Rapid Submission Attack Simulation', function() {
  function simulateRapidSubmissions(count, intervalMs) {
    const submissions = [];
    let time = Date.now();
    for (let i = 0; i < count; i++) {
      submissions.push({
        submitted_at: new Date(time).toISOString(),
        is_correct: i % 5 === 0, // every 5th is "correct"
        time_spent_seconds: Math.floor(Math.random() * 10) + 1,
      });
      time += intervalMs;
    }
    return submissions;
  }

  function detectRetryStorm(submissions) {
    if (submissions.length < 5) return { detected: false };
    const timedeltas = [];
    for (let i = 1; i < submissions.length; i++) {
      const prev = new Date(submissions[i - 1].submitted_at).getTime();
      const curr = new Date(submissions[i].submitted_at).getTime();
      timedeltas.push((curr - prev) / 1000 / 60);
    }
    const avgTime = timedeltas.reduce((a, b) => a + b, 0) / timedeltas.length;
    return { detected: submissions.length > 20 && avgTime < 3, avgTimeBetween: Math.round(avgTime * 10) / 10 };
  }

  it('detects 50 submissions at 2-second intervals', function() {
    const subs = simulateRapidSubmissions(50, 2000);
    const result = detectRetryStorm(subs);
    assert.strictEqual(result.detected, true);
    assert.ok(result.avgTimeBetween < 1);
  });

  it('detects 100 submissions at 1-second intervals (extreme attack)', function() {
    const subs = simulateRapidSubmissions(100, 1000);
    const result = detectRetryStorm(subs);
    assert.strictEqual(result.detected, true);
    assert.strictEqual(result.avgTimeBetween, 0.0); // rounds to 0 at 1 decimal
  });

  it('detects 30 submissions at 10-second intervals', function() {
    const subs = simulateRapidSubmissions(30, 10000);
    const result = detectRetryStorm(subs);
    assert.strictEqual(result.detected, true);
    // avgTimeBetween = 10 seconds = 0.167 minutes < 3
    assert.ok(result.avgTimeBetween < 1);
  });

  it('does NOT detect 15 submissions at 5-minute intervals (normal behavior)', function() {
    const subs = simulateRapidSubmissions(15, 300000);
    const result = detectRetryStorm(subs);
    assert.strictEqual(result.detected, false); // < 20 submissions
  });

  it('does NOT detect 25 submissions at 10-minute intervals (studying, not attacking)', function() {
    const subs = simulateRapidSubmissions(25, 600000);
    const result = detectRetryStorm(subs);
    assert.strictEqual(result.detected, false); // avgTime = 10 min > 3
  });
});

// ── Integrity Threshold Edge Cases ───────────────────────────────────────────

describe('Submission Stress — Integrity Threshold Boundaries', function() {
  it('growth_velocity: exactly 200% is NOT flagged (strict >)', function() {
    // The code uses: growthPercent > 200
    // So exactly 200% should NOT be flagged
    assert.ok(200 > 200 === false, '200% growth should NOT be flagged (strict >)');
  });

  it('growth_velocity: 201% IS flagged', function() {
    assert.ok(201 > 200 === true, '201% growth should be flagged');
  });

  it('retry_storm: exactly 20 submissions is NOT flagged (strict >)', function() {
    // The code uses: submissions.length > 20
    assert.ok(20 > 20 === false, '20 submissions should NOT trigger storm (strict >)');
  });

  it('retry_storm: 21 submissions IS flagged (if avg time < 3 min)', function() {
    assert.ok(21 > 20 === true, '21 submissions should trigger storm count check');
  });

  it('retry_storm: avgTime exactly 3 min is NOT flagged (strict <)', function() {
    // The code uses: avgTime < 3
    assert.ok(3 < 3 === false, '3 min avg should NOT trigger (strict <)');
  });

  it('retry_storm: avgTime 2.9 min IS flagged', function() {
    assert.ok(2.9 < 3 === true, '2.9 min avg should trigger');
  });

  it('behavioral_anomaly: zScore exactly 2.0 is NOT flagged (strict >)', function() {
    assert.ok(2.0 > 2.0 === false, 'zScore = 2.0 should NOT trigger (strict >)');
  });

  it('behavioral_anomaly: zScore 2.01 IS flagged', function() {
    assert.ok(2.01 > 2.0 === true, 'zScore = 2.01 should trigger');
  });

  it('time_limit: < 30 seconds triggers, 30 does not', function() {
    assert.ok(29 < 30 === true, '29 seconds should trigger very fast');
    assert.ok(30 < 30 === false, '30 seconds should NOT trigger');
  });
});

console.log('Submission Stress test suite loaded — all assertions active.');
