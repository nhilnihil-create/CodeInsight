/**
 * Pre-submission integrity self-check.
 * Gives students a gentle nudge BEFORE submitting code that might trigger a flag.
 * These are educational hints, not accusations.
 */

function checkCodeGrowth(code, previousCode, starterCode) {
  const currentLines = (code || '').split('\n').length;
  const baseline = previousCode
    ? (previousCode || '').split('\n').length
    : (starterCode || '').split('\n').length;
  if (baseline <= 0) return null;
  const growthPct = ((currentLines - baseline) / baseline) * 100;
  if (growthPct > 50 && currentLines > 100) {
    return {
      level: 'hint',
      message: `Your code grew ${Math.round(growthPct)}% since your last submission. Make sure you wrote this incrementally.`,
    };
  }
  return null;
}

function checkHardcodingHint(code) {
  const coutPattern = /cout\s*<<\s*(\d+)\s*[;>]/g;
  const matches = Array.from(code.matchAll(coutPattern));
  if (matches.length === 0) return null;
  const hasVariables = /\b(int|float|double|long|short)\s+\w+\s*=/g.test(code);
  const hasLoops = /(for|while|do)\s*[\({]/g.test(code);
  if (!hasVariables && !hasLoops && matches.length > 0) {
    return {
      level: 'hint',
      message: `Found ${matches.length} numeric output(s) without calculation logic. Did you compute these values or just output them directly?`,
    };
  }
  return null;
}

function checkPasteWarning(tabSwitchCount, pasteCount) {
  const hints = [];
  if (pasteCount >= 5) hints.push(`${pasteCount} paste events`);
  if (tabSwitchCount >= 10) hints.push(`${tabSwitchCount} tab switches`);
  if (hints.length > 0) {
    return {
      level: 'info',
      message: `Your editor session shows: ${hints.join(', ')}. If you referenced external sources, make sure your code represents your own understanding.`,
    };
  }
  return null;
}

/**
 * Run all pre-submission checks and return any hints.
 */
function runAllChecks(code, previousCode, starterCode, tabSwitchCount, pasteCount) {
  return [
    checkCodeGrowth(code, previousCode, starterCode),
    checkHardcodingHint(code),
    checkPasteWarning(tabSwitchCount, pasteCount),
  ].filter(Boolean);
}

module.exports = { runAllChecks };
