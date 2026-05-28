/**
 * Micro-Concept Engine Service
 * Implements deterministic rule-based feedback using the micro concept taxonomy
 * Provides specific, actionable feedback for beginner programming mistakes
 */

const { MICRO_CONCEPT_RULES } = require('./microConceptTaxonomy.js');

/**
 * Run micro-concept detection for a submission
 * @param {Object} context - Submission context for analysis
 * @param {string} conceptName - Name of the exercise concept (e.g., 'Conditionals')
 * @returns {Object} Feedback results with detected issues and messages
 */
async function detectMicroConcepts(context, conceptName) {
  const results = {
    detected: [],
    instructorNotes: [],
    studentMessages: [],
    evidence: []
  };

  // Get rules for the specific concept
  const conceptRules = MICRO_CONCEPT_RULES[conceptName] || [];

  // Also run cross-cutting rules that might apply to any concept
  const crossCuttingRules = [];
  // Add any rules that apply across concepts here if needed

  // Combine concept-specific and cross-cutting rules
  const allRules = [...conceptRules, ...crossCuttingRules];

  // Run each detector
  for (const rule of allRules) {
    try {
      const detected = rule.detector(context);
      if (detected) {
        results.detected.push({
          id: rule.id,
          name: rule.name,
          description: rule.description
        });

        if (rule.instructorMessage) {
          results.instructorNotes.push(rule.instructorMessage);
        }

        if (rule.studentMessage) {
          results.studentMessages.push(rule.studentMessage);
        }

        if (rule.evidenceExtractor) {
          try {
            const evidence = rule.evidenceExtractor(context);
            results.evidence.push({
              ruleId: rule.id,
              evidence: evidence
            });
          } catch (evError) {
            console.warn(`Evidence extractor failed for rule ${rule.id}:`, evError.message);
            results.evidence.push({
              ruleId: rule.id,
              evidence: 'Evidence extraction failed'
            });
          }
        }
      }
    } catch (detError) {
      console.warn(`Detector failed for rule ${rule.id}:`, detError.message);
      // Continue with other rules
    }
  }

  return results;
}

/**
 * Generate comprehensive micro-concept feedback for display
 * @param {Object} detectionResults - Results from detectMicroConcepts
 * @returns {Object} Formatted feedback for frontend consumption
 */
function formatFeedback(detectionResults) {
  if (detectionResults.detected.length === 0) {
    return {
      hasFeedback: false,
      detectedCount: 0,
      message: 'No specific micro-concept issues detected'
    };
  }

  // Prioritize feedback - show most relevant first
  const prioritized = [...detectionResults.detected].sort((a, b) => {
    // Prioritize certain types of errors (you could implement a priority system)
    return 0; // For now, keep original order
  });

  return {
    hasFeedback: true,
    detectedCount: prioritized.length,
    issues: prioritized.map(issue => ({
      id: issue.id,
      name: issue.name,
      description: issue.description
    })),
    instructorNotes: detectionResults.instructorNotes,
    studentMessages: detectionResults.studentMessages,
    evidence: detectionResults.evidence,
    summary: generateSummary(prioritized),
    suggestedAction: generateSuggestedAction(prioritized)
  };
}

/**
 * Generate a human-readable summary of detected issues
 * @param {Array} detectedIssues - Array of detected issue objects
 * @returns {string} Summary text
 */
function generateSummary(detectedIssues) {
  if (detectedIssues.length === 0) return 'No issues detected';

  const issueNames = detectedIssues.map(issue => issue.name);

  if (detectedIssues.length === 1) {
    return `Detected issue: ${issueNames[0]}`;
  } else if (detectedIssues.length === 2) {
    return `Detected issues: ${issueNames[0]} and ${issueNames[1]}`;
  } else {
    return `Detected ${detectedIssues.length} issues: ${issueNames.slice(0, -1).join(', ')}, and ${issueNames[detectedIssues.length - 1]}`;
  }
}

/**
 * Generate suggested action based on detected issues
 * @param {Array} detectedIssues - Array of detected issue objects
 * @returns {string} Suggested next steps
 */
function generateSuggestedAction(detectedIssues) {
  if (detectedIssues.length === 0) return 'Continue practicing!';

  // Provide concept-specific guidance
  const conceptSpecificActions = {
    'Datatypes': 'Review data types and ensure proper use of integers vs. floating-point numbers.',
    'Variables': 'Check variable declarations and scope. Ensure all variables are declared before use.',
    'Conditionals': 'Review if-else logic and boolean expressions. Check boundary conditions.',
    'Loops': 'Verify loop initialization, condition, and increment/decrement parts.',
    'Functions': 'Ensure functions have proper return statements and correct parameter types.',
    'Arrays': 'Check array indexing and bounds. Use loop variables for iteration.',
    'OOP': 'Review class design, encapsulation, and access modifiers.'
  };

  // For multiple issues, provide general advice
  if (detectedIssues.length > 2) {
    return 'Review your code carefully. Consider breaking down the problem into smaller parts and testing each component.';
  }

  // For single or double issues, give specific advice
  const firstIssue = detectedIssues[0];
  const conceptMatch = Object.keys(conceptSpecificActions).find(key =>
    firstIssue.name.toLowerCase().includes(key.toLowerCase()) ||
    key.toLowerCase().includes(firstIssue.name.toLowerCase())
  );

  if (conceptMatch) {
    return conceptSpecificActions[conceptMatch];
  }

  return 'Review the feedback above and consider how to address the identified issues.';
}

/**
 * Main function to get micro-concept feedback for a submission
 * @param {Object} context - Submission context (AST, test results, etc.)
 * @param {string} conceptName - Exercise concept name
 * @returns {Object} Formatted micro-concept feedback
 */
async function getMicroConceptFeedback(context, conceptName) {
  try {
    // Detect issues using the rule engine
    const detectionResults = await detectMicroConcepts(context, conceptName);

    // Format for frontend consumption
    const formattedFeedback = formatFeedback(detectionResults);

    return formattedFeedback;
  } catch (error) {
    console.error('Error in micro-concept engine:', error);
    return {
      hasFeedback: false,
      message: 'Micro-concept analysis temporarily unavailable',
      error: error.message
    };
  }
}

module.exports = {
  getMicroConceptFeedback,
  detectMicroConcepts,
  formatFeedback
};