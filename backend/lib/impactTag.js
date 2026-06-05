/**
 * K-tier ImpactTag reporting (spec §8.5).
 * K ≥ 5 points + 80% CI → full effect-size estimate.
 * K = 2-4 → widened range, labeled "directional".
 * K < 2 → render "—", never a number.
 */
function impactTag(k, effectSize) {
  if (k < 2) return { display: '—', label: 'insufficient data', actionable: false };
  if (k >= 5) {
    return {
      display: `${effectSize.toFixed(2)}`,
      label: 'measurable impact',
      ci: '80%',
      actionable: true,
    };
  }
  const widened = effectSize * 1.5;
  return {
    display: `${widened.toFixed(1)} (directional)`,
    label: 'directional — widened range',
    ci: 'widened 80%',
    actionable: true,
  };
}

module.exports = { impactTag };
