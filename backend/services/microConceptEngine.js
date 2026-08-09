/**
 * Micro-Concept Engine Service
 * Implements deterministic rule-based feedback using the micro concept taxonomy
 * Provides specific, actionable feedback for beginner programming mistakes
 */

const { MICRO_CONCEPT_RULES } = require('./microConceptTaxonomy.js');

/**
 * Cross-cutting rules that apply to ANY submission regardless of concept.
 * Defined at module scope so errorClusterer can check existing rule coverage.
 */
const crossCuttingRules = [
  {
    id: 'cc_missing_semicolon',
    name: 'Missing Semicolon',
    description: 'Syntax error: missing semicolon at end of statement',
    detector: ({compilerErrors}) => compilerErrors.some(err =>
      err.includes('expected') || err.includes('parse error')
    ),
    instructorMessage: 'Missing semicolon — every statement in C++ ends with ;',
    studentMessage: 'Every statement in C++ must end with a semicolon (;).',
    evidenceExtractor: ({compilerErrors}) => {
      const err = compilerErrors.find(e => e.includes('expected'));
      return err ? err.trim() : 'Syntax error: missing ;';
    }
  },
  {
    id: 'cc_unused_variable',
    name: 'Variable Declared But Not Used',
    description: 'Variable declared but never read or written to',
    detector: ({compilerErrors}) => compilerErrors.some(err =>
      err.includes('unused variable') ||
      err.includes('set but not used')
    ),
    instructorMessage: 'Declared variable is never used. Remove unused variables to keep code clean.',
    studentMessage: 'You declared a variable but never used it. Either use it or remove it.',
    evidenceExtractor: ({compilerErrors}) => {
      const err = compilerErrors.find(e => e.includes('unused'));
      return err ? err.trim() : 'Unused variable';
    }
  },
  {
    id: 'cc_missing_return_main',
    name: 'main() Falls Off the End Without Return',
    description: 'main() has no return statement, no exit-family call, and no infinite loop — it falls off the end',
    detector: ({code}) => {
      const hasMain = /\bmain\s*\(/.test(code);
      if (!hasMain) return false;
      const hasAnyReturn = /\breturn\b[^;]*;/.test(code);
      const hasExitLike = /\b(?:exit|_Exit|abort|quick_exit)\s*\(/.test(code);
      const hasInfiniteLoop = /for\s*\(\s*;;\s*\)|while\s*\(\s*(?:true|1)\s*\)/.test(code);
      return !hasAnyReturn && !hasExitLike && !hasInfiniteLoop;
    },
    instructorMessage: 'main() should return 0 to indicate successful program completion to the operating system. If the program never returns (exit-family call or infinite loop), a return is not required.',
    studentMessage: 'Add "return 0;" at the end of main() to indicate the program ran successfully.',
    evidenceExtractor: () => 'main() missing return statement'
  },
  {
    id: 'cc_using_namespace_std',
    name: 'Using namespace std in Global Scope',
    description: 'using namespace std; at file scope — considered bad practice in larger programs',
    detector: ({code}) => {
      const hasGlobalUsing = /^using\s+namespace\s+std\s*;/m.test(code);
      return hasGlobalUsing;
    },
    instructorMessage: 'using namespace std; at file scope can cause naming collisions in larger programs. Use std:: prefix instead.',
    studentMessage: 'For now it works, but in larger programs, use std::cout instead of cout to avoid naming conflicts.',
    evidenceExtractor: () => 'using namespace std in global scope'
  },
  {
    id: 'cc_comma_in_conditional',
    name: 'Comma Operator in Conditional',
    description: 'Using comma operator inside if or while condition — left operand value is discarded',
    detector: ({code, compilerErrors}) => {
      const commaInCondition = /(?:if|while|for)\s*\([^)]*,[^)]*\)/.test(code);
      const commaWarning = compilerErrors.some(err =>
        err.includes('comma') || (err.includes('left operand') && err.includes(','))
      );
      return commaInCondition || commaWarning;
    },
    instructorMessage: 'Comma operator in a conditional discards the left operand truth value. Only the rightmost expression determines the condition.',
    studentMessage: 'In "if (x, y)", only y matters for the condition. Use && or || if you want to test both values.',
    evidenceExtractor: ({code}) => {
      const match = code.match(/(?:if|while|for)\s*\([^)]*,[^)]*\)/);
      return match ? `Comma operator in: ${match[0].trim()}` : 'Comma operator in conditional';
    }
  },
  {
    id: 'cc_short_circuit_if',
    name: 'Short-Circuit as If-Replacement',
    description: 'Using logical && or || as control flow at statement level instead of if',
    detector: ({code}) => {
      const stmtLevelAnd = /(?:^|;)\s*\w+\s*[^;]*\&\&\s*\w+\s*\(/.test(code);
      const stmtLevelOr = /(?:^|;)\s*\w+\s*[^;]*\|\|\s*\w+\s*\(/.test(code);
      return stmtLevelAnd || stmtLevelOr;
    },
    instructorMessage: 'Using && or || as a control flow mechanism instead of if statements. This makes C++ code harder to read and debug.',
    studentMessage: 'Replace "condition && action()" with "if (condition) { action(); }" for clarity.',
    evidenceExtractor: ({code}) => {
      const match = code.match(/(?:^|;)\s*\w+\s*[^;]*\&\&\s*\w+\s*\(/);
      return match ? `Found: ${match[0].trim()}` : 'Short-circuit control flow';
    }
  },
  {
    id: 'cc_empty_loop_body',
    name: 'Empty Loop Body',
    description: 'Loop with empty or semicolon-only body — likely unintentional',
    detector: ({code, compilerErrors}) => {
      const emptyFor = /for\s*\([^)]*\)\s*;/.test(code);
      const emptyWhile = /while\s*\([^)]*\)\s*;/.test(code);
      const emptyDo = /do\s*;\s*while/.test(code);
      const emptyWarning = compilerErrors.some(err =>
        err.includes('empty body') || err.includes('-Wempty-body')
      );
      return emptyFor || emptyWhile || emptyDo || emptyWarning;
    },
    instructorMessage: 'Loop has an empty body (semicolon right after the loop header). The loop does nothing.',
    studentMessage: 'Your loop body is empty. Keep the opening brace { on the same line as for/while to avoid accidental semicolons.',
    evidenceExtractor: ({code}) => {
      const match = code.match(/(?:for|while)\s*\([^)]*\)\s*;/);
      return match ? `Empty loop: ${match[0].trim()}` : 'Empty loop body detected';
    }
  },
  {
    id: 'cc_macro_heavy',
    name: 'Macro-Obfuscated Computation',
    description: 'Heavy use of #define macros (> 5) without regular function definitions — logic hidden in macros',
    detector: ({code}) => {
      const defineCount = (code.match(/#define\s/g) || []).length;
      const hasFuncDefs = /\w+\s+\([^)]*\)\s*\{/.test(code);
      return defineCount > 5 && !hasFuncDefs;
    },
    instructorMessage: 'Excessive macros (#define) without regular function definitions. Macros obscure logic and bypass type checking.',
    studentMessage: 'Replace #define macros with regular functions — they are type-safe and easier to debug.',
    evidenceExtractor: ({code}) => {
      const macros = (code.match(/#define\s/g) || []).length;
      return `${macros} #define directives found, no function definitions`;
    }
  },
  {
    id: 'cc_over_nested',
    name: 'Suspiciously Over-Nested Structure',
    description: 'Control-flow keyword nested at brace depth of 5 or more — logic buried too deep to follow',
    detector: ({code}) => {
      if (typeof code !== 'string' || code.length === 0) return false;
      const OVER_NESTED_THRESHOLD = 5;
      // Strip comments (// and /* */) and string/char literals so braces and
      // keywords inside them do not affect depth tracking. Pure char scan.
      const cleaned = code
        .replace(/\/\*[\s\S]*?\*\//g, ' ')
        .replace(/\/\/[^\n]*/g, ' ')
        .replace(/"(?:[^"\\]|\\.)*"/g, ' ')
        .replace(/'(?:[^'\\]|\\.)*'/g, ' ');
      let depth = 0;
      for (let i = 0; i < cleaned.length; i++) {
        const ch = cleaned[i];
        if (ch === '{') {
          depth++;
        } else if (ch === '}') {
          depth = depth > 0 ? depth - 1 : 0;
        } else if (depth >= OVER_NESTED_THRESHOLD && /^(?:for|while|do|if|switch)\b/.test(cleaned.slice(i))) {
          return true;
        }
      }
      return false;
    },
    instructorMessage: 'Logic nested 5+ levels deep is very hard to read and debug. Refactor into smaller helper functions.',
    studentMessage: 'Your code is nested very deeply. Break it into smaller functions so each piece stays readable.',
    evidenceExtractor: ({code}) => {
      const kw = (code.match(/\b(?:for|while|do|if|switch)\b/) || [])[0];
      return kw ? `Control-flow keyword "${kw}" appears at brace depth >= 5` : 'Deeply nested control flow detected';
    }
  },
  {
    id: 'cc_implicit_fallthrough',
    name: 'Implicit Fallthrough in Switch',
    description: 'A switch case block runs into the next case without break/return — execution falls through',
    detector: ({code}) => {
      if (typeof code !== 'string' || code.length === 0) return false;
      const switchRe = /\bswitch\s*\(/g;
      let swMatch;
      while ((swMatch = switchRe.exec(code)) !== null) {
        const openIdx = code.indexOf('{', swMatch.index + swMatch[0].length);
        if (openIdx === -1) continue;
        // Extract the switch body via brace counting
        let depth = 0;
        let closeIdx = -1;
        for (let i = openIdx; i < code.length; i++) {
          if (code[i] === '{') depth++;
          else if (code[i] === '}') {
            depth--;
            if (depth === 0) { closeIdx = i; break; }
          }
        }
        if (closeIdx === -1) continue;
        const body = code.slice(openIdx + 1, closeIdx);
        // Split the body into blocks by case/default labels
        const labelRe = /\b(?:case\b[^:]*|default)\s*:/g;
        const labelMatches = [];
        let labelMatch;
        while ((labelMatch = labelRe.exec(body)) !== null) labelMatches.push(labelMatch);
        if (labelMatches.length === 0) continue;
        // Every block except the last must end with a terminator if non-empty.
        // Stacked labels (case 1: case 2:) produce an empty block and do not fire.
        for (let b = 0; b < labelMatches.length - 1; b++) {
          const blockStart = labelMatches[b].index + labelMatches[b][0].length;
          const blockEnd = labelMatches[b + 1].index;
          const block = body.slice(blockStart, blockEnd);
          if (!/\S/.test(block)) continue;
          if (/\bbreak\s*;|\breturn\b|\bgoto\b|\bthrow\b|\bcontinue\s*;|\bexit\s*\(/.test(block)) continue;
          return true;
        }
      }
      return false;
    },
    instructorMessage: 'A case block falls through into the next case without break or return. Add a terminator to every non-empty case.',
    studentMessage: 'Every case in a switch should end with break; (or return/continue) unless you intentionally want fallthrough.',
    evidenceExtractor: ({code}) => {
      const match = code.match(/\bswitch\s*\([^)]*\)\s*\{/);
      return match ? `Fallthrough risk in: ${match[0].trim()}...` : 'Implicit fallthrough in switch';
    }
  },
  {
    id: 'cc_macro_obfuscation',
    name: 'Macro-Obfuscated Logic',
    description: 'Function-like macro whose body hides control flow or statements — logic buried in a single macro',
    // NOTE: distinct from cc_macro_heavy (which is count-based, > 5 #define directives);
    // this rule is content-based and catches a single macro hiding real logic.
    detector: ({code}) => {
      if (typeof code !== 'string' || code.length === 0) return false;
      const macroRe = /#define\s+[A-Za-z_]\w*\s*\([^)]*\)\s*(.*)$/gm;
      let m;
      while ((m = macroRe.exec(code)) !== null) {
        const body = m[1] || '';
        const hidesLogic = /\b(?:for|while|do|switch|if|else|return|goto|break|continue)\b/.test(body) || body.includes(';');
        if (hidesLogic) return true;
      }
      return false;
    },
    instructorMessage: 'A #define macro hides control-flow logic. Macros bypass type checking and make debugging harder — use a function instead.',
    studentMessage: 'Your macro contains real control flow (loops, conditionals, return). Replace it with a regular function — it is easier to read and debug.',
    evidenceExtractor: ({code}) => {
      const match = code.match(/#define\s+[A-Za-z_]\w*\s*\([^)]*\)[^\n]*/);
      return match ? `Macro with hidden logic: ${match[0].trim()}` : 'Function-like macro hides control flow';
    }
  }
];

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

  // Guard against null context — provide safe defaults for all detectors
  if (!context) context = {};
  if (!context.ast) context.ast = {};
  if (!context.testResults) context.testResults = [];
  if (!context.compilerErrors) context.compilerErrors = [];
  if (!context.code) context.code = '';
  if (context.timeLimitHit === undefined) context.timeLimitHit = false;
  if (!context.ast.node_types) context.ast.node_types = [];
  if (context.ast.if_count === undefined) context.ast.if_count = 0;
  if (context.ast.else_count === undefined) context.ast.else_count = 0;
  if (context.ast.has_private === undefined) context.ast.has_private = false;
  if (!context.required_ast_nodes) context.required_ast_nodes = [];
  if (!context.exercise) context.exercise = {};

  // Get rules for the specific concept
  const conceptRules = MICRO_CONCEPT_RULES[conceptName] || [];

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

  // Provide concept-specific guidance (all 25 concepts)
  const conceptSpecificActions = {
    'Datatypes': 'Review data types and ensure proper use of integers vs. floating-point numbers.',
    'Variables': 'Check variable declarations and scope. Ensure all variables are declared before use.',
    'Conditionals': 'Review if-else logic and boolean expressions. Check boundary conditions.',
    'Loops': 'Verify loop initialization, condition, and increment/decrement parts.',
    'Functions': 'Ensure functions have proper return statements and correct parameter types.',
    'Arrays': 'Check array indexing and bounds. Use loop variables for iteration.',
    'OOP': 'Review class design, encapsulation, and access modifiers.',
    'Pointers': 'Understand pointer initialization, dereferencing (*p), and memory management.',
    'Strings': 'Review std::string operations: concatenation, indexing, and the <string> header.',
    'Input/Output': 'Check your stream operators (>> and << directions) and include <iostream>.',
    'Switch/Case': 'Verify each case has a break; and consider adding a default: branch.',
    'Nested Loops': 'Use different loop variables for inner vs outer loops. Reset accumulators each iteration.',
    'Recursion': 'Verify your base case stops recursion. Trace execution for small inputs first.',
    'File I/O': 'Check file open success with .is_open() and include <fstream>.',
    'Scope': 'Variables are local to their { } block. Declare variables at the scope level you need.',
    'Enums': 'Use enum class for type-safe enums. Initialize enum variables before use.',
    'Structs': 'Initialize all struct fields. Pass large structs by const reference.',
    'Dynamic Memory': 'Every new needs a matching delete. Every new[] needs a matching delete[].',
    'Linked Lists': 'Check for nullptr during traversal. Update next pointers correctly when inserting.',
    'Error Handling': 'Catch exceptions by const reference. Never leave catch blocks empty.',
    'Type Casting': 'Prefer static_cast<Type>(value) over C-style casts. Watch for precision loss.',
    'Preprocessor': 'Use #pragma once in headers. Wrap macro arguments and body in parentheses.',
    'Namespaces': 'Use std:: prefix or add using namespace std;. Avoid ambiguous namespace references.',
    'Inheritance': 'Base class destructors should be virtual. Call base constructors in initializer lists.',
    'Polymorphism': 'Mark overriding functions with override keyword. Ensure base functions are virtual.'
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
  formatFeedback,
  crossCuttingRules
};