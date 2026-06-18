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
      } else if (mostCommonIssue.id.includes('ptr')) {
        rootCause = 'Students have difficulty with pointer semantics: address-of (&), dereference (*), and pointer arithmetic.';
      } else if (mostCommonIssue.id.includes('str')) {
        rootCause = 'Students may not understand std::string as a distinct type requiring <string> header and correct operations.';
      } else if (mostCommonIssue.id.includes('io_')) {
        rootCause = 'Students confuse stream operator direction (>> for extraction, << for insertion) or forget <iostream>.';
      } else if (mostCommonIssue.id.includes('sw_')) {
        rootCause = 'Students may not understand switch fall-through behavior or the need for break and default cases.';
      } else if (mostCommonIssue.id.includes('nl_')) {
        rootCause = 'Students reuse the same loop variable in nested loops, causing inner loop to corrupt the outer loop counter.';
      } else if (mostCommonIssue.id.includes('rec_')) {
        rootCause = 'Students may not fully understand base cases and recurrence relations in recursive problem solving.';
      } else if (mostCommonIssue.id.includes('fio_')) {
        rootCause = 'Students may not check file open success or include the required <fstream> header.';
      } else if (mostCommonIssue.id.includes('scp_')) {
        rootCause = 'Students may not understand that variables declared inside { } blocks are local and not accessible outside.';
      } else if (mostCommonIssue.id.includes('enum_')) {
        rootCause = 'Students may not understand scope pollution from plain enums or the benefits of enum class.';
      } else if (mostCommonIssue.id.includes('st_')) {
        rootCause = 'Students may not initialize all struct fields or may pass large structs by value unnecessarily.';
      } else if (mostCommonIssue.id.includes('dyn_')) {
        rootCause = 'Students may not understand the pairing of new/delete and new[]/delete[], or risk dangling pointers.';
      } else if (mostCommonIssue.id.includes('ll_')) {
        rootCause = 'Students may not check for nullptr during linked list traversal or update next pointers correctly.';
      } else if (mostCommonIssue.id.includes('err_')) {
        rootCause = 'Students may catch exceptions by value (causing slicing) or leave catch blocks empty.';
      } else if (mostCommonIssue.id.includes('cast_') || mostCommonIssue.id.includes('tc_')) {
        rootCause = 'Students may use dangerous C-style casts and not understand narrowing conversion risks.';
      } else if (mostCommonIssue.id.includes('pp_')) {
        rootCause = 'Students may overuse #define macros instead of type-safe alternatives, or omit include guards.';
      } else if (mostCommonIssue.id.includes('ns_')) {
        rootCause = 'Students may not use std:: prefix correctly or may create ambiguous namespace references.';
      } else if (mostCommonIssue.id.includes('inherit_') || mostCommonIssue.id.includes('inh_')) {
        rootCause = 'Students may not understand virtual destructors, base constructor calls, or object slicing in inheritance.';
      } else if (mostCommonIssue.id.includes('poly_')) {
        rootCause = 'Students may not declare base functions as virtual or may have signature mismatches in overrides.';
      } else if (mostCommonIssue.id.includes('oop')) {
        rootCause = 'Students may not understand encapsulation principles: private data members and public accessor methods.';
      } else if (mostCommonIssue.id.includes('cc_')) {
        rootCause = 'Students may have general C++ syntax and style issues (missing semicolons, unused variables, etc.).';
      } else {
        rootCause = 'Students encountered difficulties with the specific programming constructs required for this exercise.';
      }

      // Generate recommended action
      if (mostCommonIssue.id.includes('cond_missing_else')) {
        recommendedAction = 'Provide additional practice with if-else statements and have students trace through various test cases.';
      } else if (mostCommonIssue.id.includes('loop_off_by_one')) {
        recommendedAction = 'Use visual aids to show array indices and have students practice with fence-post problems.';
      } else if (mostCommonIssue.id.includes('loop_missing_increment')) {
        recommendedAction = 'Have students manually trace loop execution to see when the loop variable updates. Use a debugger step-through exercise.';
      } else if (mostCommonIssue.id.includes('var_undeclared')) {
        recommendedAction = 'Emphasize the declaration-before-use rule and have students identify variables in code snippets.';
      } else if (mostCommonIssue.id.includes('var_uninitialized')) {
        recommendedAction = 'Practice initializing all variables at the point of declaration with a known starting value.';
      } else if (mostCommonIssue.id.includes('func_missing_return')) {
        recommendedAction = 'Have students trace function execution paths and identify where return values are needed.';
      } else if (mostCommonIssue.id.includes('func_wrong_signature')) {
        recommendedAction = 'Have students match function declarations to calls, paying attention to parameter count and types.';
      } else if (mostCommonIssue.id.includes('arr_out_of_bounds') || mostCommonIssue.id.includes('arr_hardcoded_index')) {
        recommendedAction = 'Visualize array memory layout and practice accessing elements with loop variables instead of literal indices.';
      } else if (mostCommonIssue.id.includes('dt_integer_division') || mostCommonIssue.id.includes('dt_wrong_output_type')) {
        recommendedAction = 'Review integer vs floating-point arithmetic. Practice type casting with static_cast<double>().';
      } else if (mostCommonIssue.id.includes('ptr_')) {
        recommendedAction = 'Use pointer diagrams to visualize memory. Practice tracing pointer operations on paper before coding.';
      } else if (mostCommonIssue.id.includes('str_')) {
        recommendedAction = 'Review std::string header requirements and compare string operations vs C-string functions.';
      } else if (mostCommonIssue.id.includes('io_')) {
        recommendedAction = 'Practice stream operator direction: cin >> (extraction), cout << (insertion). Memorize the arrow direction rule.';
      } else if (mostCommonIssue.id.includes('sw_')) {
        recommendedAction = 'Review switch syntax: each case needs a break; to prevent fall-through, and a default: case for unexpected values.';
      } else if (mostCommonIssue.id.includes('nl_')) {
        recommendedAction = 'Use different loop variable names (i, j, k) for nested loops. Trace the outer and inner loop iterations separately on paper.';
      } else if (mostCommonIssue.id.includes('rec_')) {
        recommendedAction = 'Identify the base case and recurrence relation before coding. Trace n=0, n=1, n=2 on paper to verify correctness.';
      } else if (mostCommonIssue.id.includes('fio_')) {
        recommendedAction = 'Always check file open success with .is_open() before reading or writing. Include <fstream> header.';
      } else if (mostCommonIssue.id.includes('scp_')) {
        recommendedAction = 'Review block scope rules. Variables declared inside { } are local to that block and cannot be accessed outside.';
      } else if (mostCommonIssue.id.includes('enum_')) {
        recommendedAction = 'Use enum class for type-safe, scoped enumerations instead of plain enum to prevent name conflicts.';
      } else if (mostCommonIssue.id.includes('st_')) {
        recommendedAction = 'Initialize all struct fields before use. Pass large structs by const reference to avoid copying.';
      } else if (mostCommonIssue.id.includes('dyn_')) {
        recommendedAction = 'Every new needs a matching delete. Every new[] needs a matching delete[]. Set pointers to nullptr after delete.';
      } else if (mostCommonIssue.id.includes('ll_')) {
        recommendedAction = 'Draw linked list diagrams and trace pointer updates step by step. Always check for nullptr during traversal.';
      } else if (mostCommonIssue.id.includes('err_')) {
        recommendedAction = 'Catch exceptions by const reference. Never leave catch blocks empty — at minimum log the error.';
      } else if (mostCommonIssue.id.includes('tc_') || mostCommonIssue.id.includes('cast_')) {
        recommendedAction = 'Use static_cast<Type>() instead of C-style casts. Review narrowing conversions and precision loss when casting.';
      } else if (mostCommonIssue.id.includes('pp_')) {
        recommendedAction = 'Replace #define macros with constexpr variables or inline functions. Use #pragma once in headers.';
      } else if (mostCommonIssue.id.includes('ns_')) {
        recommendedAction = 'Use std:: prefix for standard library features. Avoid using namespace std in global scope of large projects.';
      } else if (mostCommonIssue.id.includes('inh_') || mostCommonIssue.id.includes('inherit_')) {
        recommendedAction = 'Add virtual destructors to base classes. Explicitly call base constructors in derived class initializer lists.';
      } else if (mostCommonIssue.id.includes('poly_')) {
        recommendedAction = 'Mark base class functions as virtual and derived class overrides with the override keyword to catch signature mismatches.';
      } else if (mostCommonIssue.id.includes('oop_')) {
        recommendedAction = 'Review encapsulation: make member variables private and provide public getter/setter methods.';
      } else if (mostCommonIssue.id.includes('cc_comma')) {
        recommendedAction = 'Teach that the comma operator in conditions only uses the rightmost value. Use && or || for compound conditions.';
      } else if (mostCommonIssue.id.includes('cc_short_circuit')) {
        recommendedAction = 'Discourage using && as a control-flow replacement for if statements. Emphasize readability over cleverness.';
      } else if (mostCommonIssue.id.includes('cc_empty_loop')) {
        recommendedAction = 'Warn about accidental semicolons after for/while. Use Allman-style braces or linter rules to prevent empty bodies.';
      } else if (mostCommonIssue.id.includes('cc_macro_heavy')) {
        recommendedAction = 'Teach modern C++ alternatives to macros: constexpr, inline functions, and templates.';
      } else {
        recommendedAction = `Review the concept of "${mostCommonIssue.name}" with targeted examples and practice problems.`;
      }

      if (mostCommonIssue.id.includes('cond_')) {
        beforeAdvancing = 'Ensure students can evaluate boolean expressions confidently and use if/else for both branches before moving to switch or complex conditions.';
      } else if (mostCommonIssue.id.includes('loop_') || mostCommonIssue.id.includes('nl_')) {
        beforeAdvancing = 'Ensure students can trace loop iterations manually and understand initialization, condition, and increment before advancing to nested loops.';
      } else if (mostCommonIssue.id.includes('var_') || mostCommonIssue.id.includes('scp_')) {
        beforeAdvancing = 'Ensure students reliably declare variables before use and understand block scope before moving to functions.';
      } else if (mostCommonIssue.id.includes('func_') || mostCommonIssue.id.includes('rec_')) {
        beforeAdvancing = 'Ensure students understand function calls, parameters, and return values before advancing to recursion or function pointers.';
      } else if (mostCommonIssue.id.includes('arr_')) {
        beforeAdvancing = 'Ensure students can iterate arrays with loop variables and avoid out-of-bounds access before moving to dynamic arrays.';
      } else if (mostCommonIssue.id.includes('dt_') || mostCommonIssue.id.includes('tc_') || mostCommonIssue.id.includes('cast_')) {
        beforeAdvancing = 'Ensure students understand type distinctions and safe casting before advancing to generic programming or templates.';
      } else if (mostCommonIssue.id.includes('ptr_') || mostCommonIssue.id.includes('dyn_') || mostCommonIssue.id.includes('ll_')) {
        beforeAdvancing = 'Ensure students can confidently dereference pointers, manage allocation, and visualize memory before advancing to complex data structures.';
      } else if (mostCommonIssue.id.includes('str_') || mostCommonIssue.id.includes('io_') || mostCommonIssue.id.includes('fio_')) {
        beforeAdvancing = 'Ensure students master string and stream operations before advancing to file processing or serialization.';
      } else if (mostCommonIssue.id.includes('sw_')) {
        beforeAdvancing = 'Ensure students understand case/break/default flow before moving to state machines or dispatch patterns.';
      } else if (mostCommonIssue.id.includes('oop_') || mostCommonIssue.id.includes('inh_') || mostCommonIssue.id.includes('inherit_') || mostCommonIssue.id.includes('poly_')) {
        beforeAdvancing = 'Ensure students grasp encapsulation, inheritance, and polymorphism fundamentals before advancing to design patterns.';
      } else if (mostCommonIssue.id.includes('st_')) {
        beforeAdvancing = 'Ensure students properly initialize and pass structs before advancing to classes with methods.';
      } else if (mostCommonIssue.id.includes('enum_')) {
        beforeAdvancing = 'Ensure students use type-safe enum class and understand scoping before advancing to union types or variant.';
      } else if (mostCommonIssue.id.includes('err_')) {
        beforeAdvancing = 'Ensure students handle exceptions properly before advancing to RAII or resource management patterns.';
      } else if (mostCommonIssue.id.includes('pp_') || mostCommonIssue.id.includes('ns_')) {
        beforeAdvancing = 'Ensure students manage namespaces and preprocessor directives correctly before building multi-file projects.';
      } else {
        beforeAdvancing = `Ensure students can correctly implement ${mostCommonIssue.name.replace(/_/g, ' ')} in isolation before moving to more complex problems.`;
      }
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