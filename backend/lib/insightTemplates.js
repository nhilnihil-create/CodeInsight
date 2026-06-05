/**
 * Rule-of-week template library (spec §8.0 Row 0).
 * Each rule evaluates a pattern and returns an insight sentence + action.
 */
const RULES = {
  'concept-difficulty-rising': {
    name: 'Concept Difficulty Rising',
    evaluate: ({ conceptData, totalStudents }) => {
      const hardest = [...conceptData].sort((a, b) => b.cds - a.cds)[0];
      if (!hardest || hardest.cds < 0.50) return null;
      const atRisk = conceptData.reduce((sum, c) => sum + (c.atRiskCount || 0), 0);
      return {
        message: `${hardest.name} is the hardest concept this week, with ${hardest.atRiskCount} of ${totalStudents} students in High difficulty.`,
        action: `Focus ${hardest.concept}-targeted exercises for the at-risk group.`,
        citation: `Rule: concept-difficulty-rising | n=${totalStudents}`,
      };
    },
  },
  'integrity-spike': {
    name: 'Integrity Flag Spike',
    evaluate: ({ currentFlags, priorWeekFlags }) => {
      if (currentFlags > priorWeekFlags * 1.5 && currentFlags >= 3) {
        return {
          message: `Integrity flags increased ${Math.round((currentFlags / priorWeekFlags - 1) * 100)}% this week (${currentFlags} flags vs ${priorWeekFlags} last week).`,
          action: 'Review the integrity queue for emerging patterns.',
          citation: `Rule: integrity-spike | current=${currentFlags} | prior=${priorWeekFlags}`,
        };
      }
      return null;
    },
  },
};

function evaluateRules({ conceptData, totalStudents, currentFlags, priorWeekFlags }) {
  const results = [];
  for (const [key, rule] of Object.entries(RULES)) {
    const result = rule.evaluate({ conceptData, totalStudents, currentFlags, priorWeekFlags });
    if (result) results.push({ key, ...result });
  }
  return results;
}

module.exports = { RULES, evaluateRules };
