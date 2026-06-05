/**
 * Wilson 95% confidence interval for a proportion.
 * Used to gate insights (spec §8.4): High confidence requires
 * n ≥ 10 AND ≥ 14 days AND Wilson CI half-width ≤ 0.10.
 */
function wilsonScore(p, n, z = 1.96) {
  if (n === 0) return { lower: 0, upper: 0, halfWidth: 0 };
  const denominator = 1 + z * z / n;
  const centre = (p + z * z / (2 * n)) / denominator;
  const margin = z * Math.sqrt((p * (1 - p) / n) + (z * z / (4 * n * n))) / denominator;
  return {
    lower: Math.max(0, centre - margin),
    upper: Math.min(1, centre + margin),
    halfWidth: margin,
  };
}

function confidenceLevel(p, n, days, minN = 10, minDays = 14, maxHalfWidth = 0.10) {
  const ci = wilsonScore(p, n);
  if (n < minN || days < minDays || ci.halfWidth > maxHalfWidth) {
    return { level: 'low', ci, reason: `n=${n} (need ≥${minN}), days=${days} (need ≥${minDays}), half-width=${ci.halfWidth.toFixed(2)} (need ≤${maxHalfWidth})` };
  }
  if (ci.halfWidth <= 0.05) return { level: 'high', ci };
  return { level: 'medium', ci };
}

module.exports = { wilsonScore, confidenceLevel };
