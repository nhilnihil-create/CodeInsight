/**
 * Class Misconception Report Service
 * Generates class-wide misconception reports after exercise closes
 * Aggregates patterns from student submissions to identify common issues
 */

const db = require('../config/db');
const microConceptEngine = require('./microConceptEngine.js');

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
        rootCause: 'Insufficient data',
        recommendedAction: 'Wait for more student submissions.',
        beforeAdvancing: 'Ensure students have attempted the exercise.'
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
        rootCause: 'Insufficient data',
        recommendedAction: 'Wait for more student submissions.',
        beforeAdvancing: 'Ensure students have attempted the exercise.'
      };
    }

    // Analyze each student's latest submission for micro-concept issues
    const issueFrequency = {};
    const issueDetails = {};

    for (const submission of studentList) {
      // Build context for micro-concept analysis
      const context = {
        ast: { node_types: [] }, // We'd need to extract this from AST verifier in a real implementation
        testResults: submission.test_results ?
                     (Array.isArray(submission.test_results) ? submission.test_results : JSON.parse(submission.test_results)) : [],
        compilerErrors: [], // Would need to be stored separately
        code: submission.code,
        timeLimitHit: false, // Would need tracking
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
        context.ast.node_types = Array.from(nodeTypes);
      } catch (astError) {
        // If AST parsing fails, continue with empty node types
        context.ast.node_types = [];
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

    // Generate narrative summary
    let classSummary = '';
    let rootCause = '';
    let recommendedAction = '';
    let beforeAdvancing = '';

    if (mostCommonIssue) {
      classSummary = `${affectedCount} out of ${totalStudents} students (${affectedPercent}%) showed "${mostCommonIssue.name}" - ${mostCommonIssue.description}.`;

      // Generate root cause based on issue type
      if (mostCommonIssue.id.includes('cond')) {
        rootCause = 'Students may not have sufficient practice with boolean expressions and boundary conditions.';
      } else if (mostCommonIssue.id.includes('loop')) {
        rootCause = 'Students may struggle with loop initialization, condition, and increment/decrement concepts.';
      } else if (mostCommonIssue.id.includes('var')) {
        rootCause = 'Students may need more practice with variable declaration and scope concepts.';
      } else if (mostCommonIssue.id.includes('func')) {
        rootCause = 'Students may not fully understand function signatures, parameters, and return values.';
      } else if (mostCommonIssue.id.includes('arr')) {
        rootCause = 'Students may need additional practice with array indexing and bounds checking.';
      } else if (mostCommonIssue.id.includes('dt')) {
        rootCause = 'Students may confuse integer and floating-point data types, especially in division operations.';
      } else {
        rootCause = 'Students encountered difficulties with the specific programming constructs required for this exercise.';
      }

      // Generate recommended action
      if (mostCommonIssue.id.includes('cond_missing_else')) {
        recommendedAction = 'Provide additional practice with if-else statements and have students trace through various test cases.';
      } else if (mostCommonIssue.id.includes('loop_off_by_one')) {
        recommendedAction = 'Use visual aids to show array indices and have students practice with fence-post problems.';
      } else if (mostCommonIssue.id.includes('var_undeclared')) {
        recommendedAction = 'Emphasize the declaration-before-use rule and have students identify variables in code snippets.';
      } else if (mostCommonIssue.id.includes('func_missing_return')) {
        recommendedAction = 'Have students trace function execution paths and identify where return values are needed.';
      } else {
        recommendedAction = `Review the concept of "${mostCommonIssue.name}" with targeted examples and practice problems.`;
      }

      beforeAdvancing = `Ensure students can correctly implement ${mostCommonIssue.name.replace(/_/g, ' ')} in isolation before moving to more complex problems.`;
    } else {
      classSummary = `No significant misconceptions detected among the ${totalStudents} students who submitted this exercise.`;
      rootCause = 'Students demonstrated adequate understanding of the core concepts.';
      recommendedAction = 'Continue to the next concept or provide enrichment activities for advanced students.';
      beforeAdvancing = 'Monitor for any emerging issues in the next exercise.';
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
      rootCause,
      recommendedAction,
      beforeAdvancing,
      generatedAt: new Date().toISOString()
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