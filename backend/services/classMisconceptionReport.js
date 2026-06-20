/**
 * Class Misconception Report Service
 * Generates class-wide misconception reports after exercise closes
 * Aggregates patterns from student submissions to identify common issues
 */

const db = require('../config/db');
const microConceptEngine = require('./microConceptEngine.js');
const errorNormalizer = require('./errorNormalizer');

const STD_IDS = new Set([
  'cout', 'cin', 'cerr', 'clog', 'endl', 'ws', 'ends', 'flush',
  'string', 'vector', 'list', 'map', 'set', 'pair', 'queue', 'stack',
  'ifstream', 'ofstream', 'fstream', 'fstream',
  'istream', 'ostream', 'iostream', 'stringstream',
  'max', 'min', 'swap', 'sort', 'find', 'reverse',
  'size_t', 'nullptr'
]);

const ERROR_FRIENDLY_MAP = [
  { pattern: /^expected ';'/, friendly: 'Missing semicolon \u2014 check if you forgot a ; at the end of a statement' },
  { pattern: /^expected ',' or/, friendly: 'Missing comma or semicolon in a list \u2014 check parameter or expression lists' },
  { pattern: /^expected '\)'/, friendly: 'Missing closing parenthesis \u2014 check that parentheses are balanced' },
  { pattern: /^expected '\{'/, friendly: 'Missing opening brace \u2014 a code block needs a \u007b to begin' },
  { pattern: /^expected '\}'/, friendly: 'Missing closing brace \u2014 a code block needs a \u007d to close' },
  { pattern: /^expected primary-expression/, friendly: 'Missing operand or expression \u2014 check that all operators have operands' },
  { pattern: /^expected type-specifier/, friendly: 'Variable or return type missing \u2014 declare types before using identifiers' },
  { pattern: /^expected unqualified-id/, friendly: 'Name expected \u2014 check for a missing function or variable name in a declaration' },
  { pattern: /^'<id>' was not declared/, friendly: 'Using an undeclared identifier \u2014 check the spelling or add a declaration before use' },
  { pattern: /^'<id>' does not name a type/, friendly: 'Type name not recognized \u2014 you may need to include the right header file' },
  { pattern: /^'<id>' is not a type/, friendly: 'Name used as a type but is not one \u2014 check your declaration syntax' },
  { pattern: /^'<id>' cannot be used as a function/, friendly: 'Called a name that is not a function \u2014 check for missing parentheses or wrong name' },
  { pattern: /^redefinition of/, friendly: 'Name declared twice \u2014 remove or rename the duplicate declaration' },
  { pattern: /^'<id>' defined but not used/, friendly: 'Variable declared but never used \u2014 remove it or add code that uses it' },
  { pattern: /^'<id>' is private/, friendly: 'Accessing a private member outside the class \u2014 use a public getter method' },
  { pattern: /^'<id>' is protected/, friendly: 'Accessing a protected member from outside the class hierarchy' },
  { pattern: /^no match for 'operator/, friendly: 'No matching operator for the given types \u2014 check operand types' },
  { pattern: /^invalid conversion from/, friendly: 'Type mismatch in assignment \u2014 incompatible types cannot be converted automatically' },
  { pattern: /^cannot convert/, friendly: 'Cannot convert between types \u2014 use an explicit cast or fix the types' },
  { pattern: /^invalid operands/, friendly: 'Operator used with incompatible operand types \u2014 check both sides of the operator' },
  { pattern: /^return-statement with no value/, friendly: 'Function declared to return a value but has a bare return with nothing' },
  { pattern: /^return-statement with a value/, friendly: 'Void function should not return a value \u2014 remove the return value' },
  { pattern: /^taking address of temporary/, friendly: 'Taking address of a temporary value \u2014 store it in a variable first' },
  { pattern: /^invalid use of incomplete type/, friendly: 'Using a type before its full definition \u2014 reorder code or include the missing definition' },
  { pattern: /^control reaches end of non-void function/, friendly: 'Function missing a return statement at the end \u2014 add a return value' },
  { pattern: /^comparison between signed and unsigned/, friendly: 'Comparing signed and unsigned numbers \u2014 use matching types' },
  { pattern: /^ISO C\+\+ forbids comparison between pointer and integer/, friendly: 'Comparing a pointer to an integer \u2014 check if you meant to dereference the pointer' },
  { pattern: /^'<id>' in class '<id>' does not name a type/, friendly: 'Member type not found in class \u2014 check the member name or add the type definition' },
  { pattern: /^no matching function for call/, friendly: 'No matching function for the given arguments \u2014 check parameter types and count' },
  { pattern: /^call to '<id>' is ambiguous/, friendly: 'Ambiguous function call \u2014 multiple functions match the arguments' },
  { pattern: /^reference to '<id>' is ambiguous/, friendly: 'Ambiguous reference \u2014 multiple declarations with the same name exist' },
  { pattern: /^cannot bind/, friendly: 'Cannot bind a value to a reference \u2014 check that types match exactly' },
  { pattern: /^array bound is not an integer constant/, friendly: 'Array size must be a compile-time constant \u2014 use a literal or constexpr value' },
  { pattern: /^size of array.*negative/, friendly: 'Array size cannot be negative \u2014 check the size value' },
  { pattern: /^zero-size array/, friendly: 'Array cannot have zero size \u2014 use a positive size or a dynamic container' },
  { pattern: /^statement has no effect/, friendly: 'Statement has no effect on the program \u2014 check your logic' },
  { pattern: /^suggest parentheses around assignment/, friendly: 'Assignment used as a condition \u2014 use == for comparison instead of =' },
  { pattern: /^unknown type name/, friendly: 'Type name not recognized \u2014 check for missing #include or a typo' },
  { pattern: /^use of undeclared identifier/, friendly: 'Identifier used without being declared \u2014 declare it first or fix the spelling' },
  { pattern: /^expected ',' or '\.\.\.'/, friendly: 'Missing comma or ellipsis in a parameter list' },
  { pattern: /^expected '\)' before ','/, friendly: 'Extra comma or missing parenthesis before a comma' },
];

function isStdNamespaceError(rawMessage) {
  const match = rawMessage.match(/'([a-zA-Z_]\w*)'/);
  if (match && STD_IDS.has(match[1])) {
    if (/(?:was not declared|does not name a type|is not a type)/.test(rawMessage)) {
      return true;
    }
  }
  return false;
}

function toFriendlyText(normalized) {
  for (const { pattern, friendly } of ERROR_FRIENDLY_MAP) {
    if (pattern.test(normalized)) {
      return friendly;
    }
  }
  return `\u26a0\ufe0f ${normalized.replace(/<[^>]+>/g, '\u2026').substring(0, 60)}`;
}

/**
 * Generate class misconception report for a closed exercise
 * @param {number} exerciseId - ID of the closed exercise
 * @returns {Object} Class-wide misconception report
 */
async function generateClassMisconceptionReport(exerciseId) {
  try {
    // Get exercise details
    const exerciseRes = await db.query(
      `SELECT e.*, c.name AS concept_name
       FROM exercises e
       JOIN concepts c ON e.concept_id = c.id
       WHERE e.id = $1`,
      [exerciseId]
    );

    if (!exerciseRes.rows.length) {
      throw new Error(`Exercise ${exerciseId} not found`);
    }

    const exercise = exerciseRes.rows[0];
    const conceptName = exercise.concept_name;

    // Get all submissions for this exercise
    const submissionsRes = await db.query(
      `SELECT s.*, u.name AS student_name
       FROM submissions s
       JOIN users u ON s.student_id = u.id
       WHERE s.exercise_id = $1
       ORDER BY s.student_id, s.attempt_number`,
      [exerciseId]
    );

    const submissions = submissionsRes.rows;

    if (submissions.length === 0) {
      return {
        exerciseId,
        exerciseTitle: exercise.title,
        conceptName,
        totalStudents: 0,
        mostCommonIssue: null,
        affectedCount: 0,
        affectedPercent: 0,
        secondIssue: null,
        secondCount: 0,
        classSummary: 'No submissions found for this exercise.',
        commonErrors: [],
        recommendedAction: 'Wait for more student submissions.'
      };
    }

    // Group submissions by student (take latest attempt per student)
    const studentSubmissions = {};
    submissions.forEach(sub => {
      if (!studentSubmissions[sub.student_id] ||
          sub.attempt_number > studentSubmissions[sub.student_id].attempt_number) {
        studentSubmissions[sub.student_id] = sub;
      }
    });

    const studentList = Object.values(studentSubmissions);
    const totalStudents = studentList.length;

    if (totalStudents === 0) {
      return {
        exerciseId,
        exerciseTitle: exercise.title,
        conceptName,
        totalStudents: 0,
        mostCommonIssue: null,
        affectedCount: 0,
        affectedPercent: 0,
        secondIssue: null,
        secondCount: 0,
        classSummary: 'No valid student submissions found.',
        commonErrors: [],
        recommendedAction: 'Wait for more student submissions.'
      };
    }

    // Analyze each student's latest submission for micro-concept issues
    const issueFrequency = {};
    const issueDetails = {};
    const rawErrorFrequency = {};

    function extractErrorMessage(logLine) {
      let m = logLine.match(/\[Line \d+:\d+\] \w+:\s*(.+)/);
      if (m) return m[1].trim();
      m = logLine.match(/\berror:\s*(.+)/i);
      if (m) return m[1].trim();
      return logLine.trim();
    }

    for (const submission of studentList) {
      // Read persisted test_results and compiler_log
      const testResults = submission.test_results
        ? (Array.isArray(submission.test_results) ? submission.test_results : JSON.parse(submission.test_results))
        : [];

      const submissionErrors = submission.compiler_log
        ? submission.compiler_log.split('\n').filter(l => l.includes('ERROR'))
        : [];

      // Also merge in compiler errors from run_attempts (pre-submit runs)
      const runRes = await db.query(
        `SELECT compiler_log FROM run_attempts
         WHERE student_id = $1 AND exercise_id = $2
           AND compiler_log IS NOT NULL
         ORDER BY run_at ASC`,
        [submission.student_id, exerciseId]
      );
      const runErrors = [];
      for (const row of runRes.rows) {
        const lines = row.compiler_log.split('\n').filter(l => l.includes('ERROR'));
        runErrors.push(...lines);
      }
      const allErrors = [...new Set([...submissionErrors, ...runErrors])];

      // Aggregate raw compiler errors for common-error display
      for (const raw of allErrors) {
        const msg = extractErrorMessage(raw);
        if (!msg) continue;
        if (isStdNamespaceError(msg)) continue;
        const normalized = errorNormalizer.normalizeMessage(msg);
        if (!normalized) continue;
        if (!rawErrorFrequency[normalized]) rawErrorFrequency[normalized] = new Set();
        rawErrorFrequency[normalized].add(submission.student_id);
      }

      // Build context for micro-concept analysis
      const context = {
        ast: { node_types: [] },
        testResults,
        compilerErrors: allErrors,
        code: submission.code,
        timeLimitHit: submission.time_limit_hit || false,
        exercise: {
          concept_name: conceptName,
          required_ast_nodes: exercise.ast_nodes || [],
          time_limit_minutes: exercise.time_limit_minutes
        }
      };

      // Try to extract AST node types from code (simplified)
      try {
        const treeSitter = require('tree-sitter');
        const CPP = require('tree-sitter-cpp');
        const parser = new treeSitter();
        parser.setLanguage(CPP);
        const tree = parser.parse(submission.code);
        const nodeTypes = new Set();
        function traverse(node) {
          nodeTypes.add(node.type);
          for (let i = 0; i < node.childCount; i++) {
            traverse(node.child(i));
          }
        }
        traverse(tree.rootNode);
        const types = Array.from(nodeTypes);
        context.ast.node_types = types;
        context.ast.if_count = types.filter(t => t === 'if_statement').length;
        context.ast.else_count = types.filter(t => t === 'else_clause').length;
        context.ast.has_private = types.some(t => t === 'private_section' || t === 'protected_section');
      } catch (astError) {
        context.ast.node_types = [];
        context.ast.if_count = 0;
        context.ast.else_count = 0;
        context.ast.has_private = false;
      }

      // Get micro-concept feedback for this submission
      const feedback = await microConceptEngine.getMicroConceptFeedback(context, conceptName);

      // Count each issue type
      if (feedback.hasFeedback && feedback.issues && feedback.issues.length > 0) {
        feedback.issues.forEach(issue => {
          const issueId = issue.id;
          if (!issueFrequency[issueId]) {
            issueFrequency[issueId] = 0;
            issueDetails[issueId] = issue;
          }
          issueFrequency[issueId]++;
        });
      }
    }

    // Aggregate most common raw compiler errors (across students)
    const topRawErrors = Object.entries(rawErrorFrequency)
      .map(([normalized, students]) => ({
        normalized,
        friendly: toFriendlyText(normalized),
        count: students.size,
        affectedPercent: totalStudents > 0 ? Math.round((students.size / totalStudents) * 1000) / 10 : 0
      }))
      .sort((a, b) => b.count - a.count)
      .slice(0, 3)
      .filter(e => e.count > 0);

    // Find most common and second most common issues
    const sortedIssues = Object.entries(issueFrequency)
      .map(([issueId, count]) => ({ issueId, count, details: issueDetails[issueId] }))
      .sort((a, b) => b.count - a.count);

    const mostCommon = sortedIssues[0];
    const secondMostCommon = sortedIssues[1];

    // Generate report
    const mostCommonIssue = mostCommon ? mostCommon.details : null;
    const secondIssue = secondMostCommon ? secondMostCommon.details : null;
    const affectedCount = mostCommon ? mostCommon.count : 0;
    const affectedPercent = totalStudents > 0 ? Math.round((affectedCount / totalStudents) * 100) : 0;
    const secondCount = secondMostCommon ? secondMostCommon.count : 0;

    // Generate data-driven narratives from actual compiler error patterns
    let classSummary = '';
    let recommendedAction = '';

    if (topRawErrors.length > 0) {
      const e1 = topRawErrors[0];
      const e2 = topRawErrors[1];

      classSummary = `${e1.count} of ${totalStudents} students (${e1.affectedPercent}%) encountered: "${e1.friendly}".`;

      const details = topRawErrors.map(e =>
        `"${e.friendly}" (${e.count} student${e.count > 1 ? 's' : ''}, ${e.affectedPercent}%)`
      ).join('; ');

      recommendedAction = `Most frequent: ${details}. Practice resolving these errors before advancing.`;

    } else if (mostCommonIssue) {
      classSummary = `${affectedCount} of ${totalStudents} students (${affectedPercent}%) showed "${mostCommonIssue.name}".`;
      recommendedAction = `${mostCommonIssue.name} \u2014 ${mostCommonIssue.description}. Review with targeted examples before advancing.`;

    } else {
      classSummary = `No significant issues detected among ${totalStudents} students.`;
      recommendedAction = 'No issues found. Proceed to next concept or provide enrichment activities.';
    }

    return {
      exerciseId,
      exerciseTitle: exercise.title,
      conceptName,
      totalStudents,
      mostCommonIssue: mostCommonIssue ? {
        id: mostCommonIssue.id,
        name: mostCommonIssue.name,
        description: mostCommonIssue.description
      } : null,
      affectedCount,
      affectedPercent,
      secondIssue: secondIssue ? {
        id: secondIssue.id,
        name: secondIssue.name,
        description: secondIssue.description
      } : null,
      secondCount,
      classSummary,
      recommendedAction,
      generatedAt: new Date().toISOString(),
      commonErrors: topRawErrors
    };

  } catch (error) {
    console.error('Error generating class misconception report:', error);
    return {
      exerciseId,
      error: 'Failed to generate report',
      message: error.message
    };
  }
}

module.exports = { generateClassMisconceptionReport };