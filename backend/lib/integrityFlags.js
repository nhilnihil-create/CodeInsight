// Integrity flag type constants — single source of truth
// Every file MUST import from here; never use magic strings.

const FLAG_TYPES = {
  CODE_GROWTH_ANOMALY: 'CODE_GROWTH_ANOMALY',
  HARDCODING: 'HARDCODING',
  BLANK_TEMPLATE: 'BLANK_TEMPLATE',
  PASSIVE_BEHAVIOR_LOG: 'PASSIVE_BEHAVIOR_LOG',
  BEHAVIORAL_ANOMALY: 'BEHAVIORAL_ANOMALY',
  RETRY_STORM: 'RETRY_STORM',
};

const SEVERITY = {
  LOW: 'low',
  MEDIUM: 'medium',
  HIGH: 'high',
  CRITICAL: 'critical',
};

const FLAG_STATUS = {
  FLAGGED: 'flagged',
  REVIEWED: 'reviewed',
  OPEN: 'open',
};

module.exports = { FLAG_TYPES, SEVERITY, FLAG_STATUS };
