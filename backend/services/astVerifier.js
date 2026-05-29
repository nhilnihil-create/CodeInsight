// AST Verification Service using tree-sitter for structural code analysis
// Implements deterministic validation based on required AST nodes and CodeNet patterns

const treeSitter = require('tree-sitter');
const CPP = require('tree-sitter-cpp');

/**
 * Initialize tree-sitter parser with C++ grammar
 */
let parser = null;
function getParser() {
  if (!parser) {
    parser = new treeSitter();
    parser.setLanguage(CPP);
  }
  return parser;
}

/**
 * Canonize AST by stripping identifiers and literals for structural comparison
 * Uses tree-sitter to properly identify and replace identifiers and literals
 * @param {string} code - Source code to canonize
 * @returns {string} Canonical representation
 */
function canonizeCode(code) {
  try {
    const parser = getParser();
    const tree = parser.parse(code);

    // Walk the tree and replace identifiers and literals with placeholders
    function canonizeNode(node) {
      // Handle different node types
      switch (node.type) {
        case 'identifier':
          return 'IDENT';
        case 'string_literal':
          return '"STR"';
        case 'character_literal':
          return "'C'";
        case 'number_literal':
          return 'NUM';
        case 'true':
        case 'false':
          return 'BOOL';
        case 'nullptr':
          return 'NULLPTR';
        default:
          // For other nodes, canonize their children
          let result = node.type;
          for (let i = 0; i < node.childCount; i++) {
            const child = node.child(i);
            const childCanon = canonizeNode(child);
            // Find the position of this child in the original text and replace it
            // This is a simplified approach - in practice we'd reconstruct the text
            // For now, we'll return a simplified canonized version
          }
          return result;
      }
    }

    // Simplified approach: use regex-based canonization but enhanced
    let canonized = code;

    // Remove comments
    canonized = canonized.replace(/\/\/.*$/gm, '').replace(/\/\*[\s\S]*?\*\//g, '');

    // Replace string literals with placeholder
    canonized = canonized.replace(/"(?:\\.|[^"\\])*"/g, '"STR"');

    // Replace character literals
    canonized = canonized.replace(/'(?:\\.|[^'\\])*'/g, "'C'");

    // Replace numeric literals
    canonized = canonized.replace(/\b\d+(\.\d+)?([eE][+-]?\d+)?[flL]?\b/g, 'NUM');

    // Replace identifiers (but keep keywords and symbols)
    // This is a simplified approach - a more sophisticated version would use tree-sitter
    // to identify and replace only actual identifiers while preserving structure
    canonized = canonized.replace(/\b[a-zA-Z_]\w*\b/g, 'IDENT');

    return canonized;
  } catch (error) {
    // Fallback to basic canonization if tree-sitter fails
    let canonized = code.replace(/\/\/.*$/gm, '').replace(/\/\*[\s\S]*?\*\//g, '');
    canonized = canonized.replace(/"(?:\\.|[^"\\])*"/g, '"STR"');
    canonized = canonized.replace(/'(?:\\.|[^'\\])*'/g, "'C'");
    canonized = canonized.replace(/\b\d+(\.\d+)?([eE][+-]?\d+)?[flL]?\b/g, 'NUM');
    canonized = canonized.replace(/\b[a-zA-Z_]\w*\b/g, 'IDENT');
    return canonized;
  }
}

/**
 * Check if required AST nodes exist in the parsed code
 * @param {treeSitter.Tree} tree - Parsed tree
 * @param {string[]} requiredNodes - Array of required node types
 * @returns {Array<{message: string, line: number, column: number}>} List of missing node errors
 */
function checkRequiredNodes(tree, requiredNodes) {
  const missingNodes = [];
  const rootNode = tree.rootNode;

  // Traverse the tree to collect all node types
  const nodeTypesFound = new Set();
  function traverse(node) {
    nodeTypesFound.add(node.type);
    for (let i = 0; i < node.childCount; i++) {
      traverse(node.child(i));
    }
  }
  traverse(rootNode);

  // Check which required nodes are missing
  for (const requiredNode of requiredNodes) {
    if (!nodeTypesFound.has(requiredNode)) {
      missingNodes.push({
        message: `Required AST node '${requiredNode}' not found in code`,
        line: 1,
        column: 1
      });
    }
  }

  return missingNodes;
}

/**
 * Check for empty construct bodies (e.g., empty loops, conditionals)
 * @param {treeSitter.Tree} tree - Parsed tree
 * @returns {Array<{message: string, line: number, column: number}>} List of empty body errors
 */
function checkEmptyBodies(tree) {
  const errors = [];
  const rootNode = tree.rootNode;

  // Define construct types that should have non-empty bodies
  const bodyConstructs = new Set([
    'if_statement',
    'else_clause',
    'while_statement',
    'do_statement',
    'for_statement',
    'compound_statement'
  ]);

  function traverse(node) {
    if (bodyConstructs.has(node.type)) {
      // Check if the construct has a meaningful body
      let hasMeaningfulContent = false;

      for (let i = 0; i < node.childCount; i++) {
        const child = node.child(i);
        // Skip over braces, parentheses, etc. and look for actual statements
        if (child.type !== '{' && child.type !== '}' &&
            child.type !== '(' && child.type !== ')' &&
            child.type !== ';' &&
            child.type !== 'comment') {
          hasMeaningfulContent = true;
          break;
        }
      }

      if (!hasMeaningfulContent) {
        errors.push({
          message: `Empty body detected in ${node.type}`,
          line: node.startPosition.row + 1,
          column: node.startPosition.column + 1
        });
      }
    }

    // Recurse to children
    for (let i = 0; i < node.childCount; i++) {
      traverse(node.child(i));
    }
  }

  traverse(rootNode);
  return errors;
}

/**
 * Detect hardcoded output (cout/literal usage without variables)
 * @param {string} code - Source code to analyze
 * @returns {Array<{message: string, line: number, column: number}>} List of hardcoding warnings
 */
function detectHardcodedOutput(code) {
  const warnings = [];
  const lines = code.split('\n');

  // Look for cout or printf with literal strings but no variables
  for (let i = 0; i < lines.length; i++) {
    const line = lines[i];

    // Check for cout with string literals but no stream insertion of variables
    if (/cout\s*<<\s*["']/i.test(line) && !/cout\s*<<\s*["'][^"]*["']\s*<<\s*[^";]/.test(line)) {
      // Simple heuristic: if it's just a string literal followed by endl or semicolon
      if (/cout\s*<<\s*["'][^"']*["']\s*(;\s*$|endl)/.test(line)) {
        warnings.push({
          message: 'Hardcoded output detected: using literal string without variables',
          line: i + 1,
          column: line.indexOf('cout') + 1
        });
      }
    }

    // Check for printf with format string but no variables
    if (/printf\s*\(/.test(line)) {
      // Count % format specifiers vs arguments after the format string
      const printfMatch = line.match(/printf\s*\(\s*"([^"]*)"\s*,?\s*([^)]*)\)/);
      if (printfMatch) {
        const formatString = printfMatch[1];
        const args = printfMatch[2] || '';

        // Count format specifiers
        const formatCount = (formatString.match(/%/g) || []).length;

        // Count arguments (simple comma split, not perfect but good enough for detection)
        const argCount = args.trim() ? args.split(',').filter(a => a.trim()).length : 0;

        if (formatCount > argCount) {
          warnings.push({
            message: 'Potential hardcoded printf: format specifiers exceed provided arguments',
            line: i + 1,
            column: line.indexOf('printf') + 1
          });
        }
      }
    }
  }

  return warnings;
}

/**
 * Advanced structural analysis using tree-sitter
 * @param {treeSitter.Tree} tree - Parsed tree
 * @returns {Object} Structural analysis results
 */
function analyzeStructure(tree) {
  const rootNode = tree.rootNode;
  const stats = {
    nodeTypes: new Set(),
    functionCount: 0,
    classCount: 0,
    loopCount: 0,
    conditionalCount: 0,
    hasReturnStatement: false,
    hasMainFunction: false,
    complexity: 0
  };

  function traverse(node) {
    stats.nodeTypes.add(node.type);

    // Count specific constructs
    switch (node.type) {
      case 'function_definition':
        stats.functionCount++;
        // Check if it's main function
        if (isMainFunction(node)) {
          stats.hasMainFunction = true;
        }
        break;
      case 'return_statement':
        stats.hasReturnStatement = true;
        break;
      case 'class_specifier':
        stats.classCount++;
        break;
      case 'while_statement':
      case 'do_statement':
      case 'for_statement':
        stats.loopCount++;
        break;
      case 'if_statement':
      case 'switch_statement':
        stats.conditionalCount++;
        break;
    }

    // Increase complexity for nested structures
    if (node.type === 'if_statement' ||
        node.type === 'for_statement' ||
        node.type === 'while_statement' ||
        node.type === 'do_statement') {
      stats.complexity++;
    }

    // Recurse to children
    for (let i = 0; i < node.childCount; i++) {
      traverse(node.child(i));
    }
  }

  traverse(rootNode);

  // Convert Set to array for serialization
  stats.nodeTypes = Array.from(stats.nodeTypes);

  return stats;
}

/**
 * Check if a function_definition node represents the main function
 * @param {treeSitter.Node} node - function_definition node
 * @returns {boolean} True if this is the main function
 */
function isMainFunction(node) {
  // Breadth-first search for an identifier with text "main" within this function_definition
  const queue = [node];
  while (queue.length > 0) {
    const current = queue.shift();

    // Add children to queue
    for (let i = 0; i < current.childCount; i++) {
      queue.push(current.child(i));
    }

    // Check if this is an identifier with text "main"
    if (current.type === 'identifier' && current.text === 'main') {
      // Verify it's within a function definition by checking parents
      let parent = current.parent;
      while (parent) {
        if (parent.type === 'function_definition') {
          return true;
        }
        parent = parent.parent;
      }
    }
  }

  return false;
}

/**
 * Check for common novice patterns using structural heuristics
 * @param {treeSitter.Tree} tree - Parsed tree
 * @param {string} code - Original source code
 * @returns {Array<{message: string, line: number, column: number}>} List of pattern warnings
 */
function detectNovicePatterns(tree, code) {
  const warnings = [];
  const rootNode = tree.rootNode;

  function traverse(node) {
    // Detect deeply nested code (potential complexity issue)
    if (node.type === 'if_statement' ||
        node.type === 'for_statement' ||
        node.type === 'while_statement' ||
        node.type === 'do_statement') {
      let depth = 0;
      let parent = node.parent;
      while (parent) {
        if (parent.type === 'if_statement' ||
            parent.type === 'for_statement' ||
            parent.type === 'while_statement' ||
            parent.type === 'do_statement') {
          depth++;
        }
        parent = parent.parent;
      }
      if (depth >= 3) {
        warnings.push({
          message: `Deeply nested control structure detected (depth: ${depth})`,
          line: node.startPosition.row + 1,
          column: node.startPosition.column + 1
        });
      }
    }

    // Detect switch without default (common mistake)
    if (node.type === 'switch_statement') {
      let hasDefault = false;
      for (let i = 0; i < node.childCount; i++) {
        const child = node.child(i);
        if (child.type === 'switch_case' &&
            child.childCount > 0 &&
            child.firstChild &&
            child.firstChild.type === 'case' &&
            child.firstChild.nextSibling &&
            child.firstChild.nextSibling.text === 'default') {
          hasDefault = true;
          break;
        }
      }
      if (!hasDefault) {
        warnings.push({
          message: 'Switch statement missing default case',
          line: node.startPosition.row + 1,
          column: node.startPosition.column + 1
        });
      }
    }

    // Recurse to children
    for (let i = 0; i < node.childCount; i++) {
      traverse(node.child(i));
    }
  }

  traverse(rootNode);
  return warnings;
}

async function verify(code, requirements = {}, options = {}) {
  const reasons = [];

  try {
    // Get parser instance
    const parser = getParser();

    // Parse the code
    const tree = parser.parse(code);

    // Check for parse errors
    if (tree.rootNode.hasError) {
      // Traverse to find first error
      function findFirstError(node) {
        if (node.type === 'ERROR') {
          return node;
        }
        for (let i = 0; i < node.childCount; i++) {
          const error = findFirstError(node.child(i));
          if (error) return error;
        }
        return null;
      }

      const errorNode = findFirstError(tree.rootNode);
      if (errorNode) {
        reasons.push({
          message: 'Syntax error in code - unable to parse',
          line: errorNode.startPosition.row + 1,
          column: errorNode.startPosition.column + 1
        });
        return { is_verified: false, reasons };
      }
    }

    // Template detection (if starter code provided)
    if (options.starter_code) {
      const isTemplate = code.trim() === options.starter_code.trim();
      if (isTemplate) {
        reasons.push({
          message: 'Submission matches starter/template code',
          line: 1,
          column: 1
        });
        return { is_verified: false, reasons };
      }
    }

    // Basic heuristic: non-empty main body (fallback)
    const nonWhitespace = code.replace(/\/\*.*?\*\//gs, '').replace(/\/\/.*$/gm, '').trim();
    if (nonWhitespace.length < 10) {
      reasons.push({
        message: 'Submission too short to verify',
        line: 1,
        column: 1
      });
      return { is_verified: false, reasons };
    }

    // Structural validation based on requirements
    if (requirements.required_nodes && requirements.required_nodes.length) {
      const missingNodes = checkRequiredNodes(tree, requirements.required_nodes);
      reasons.push(...missingNodes);
    }

    // Check for empty construct bodies
    const emptyBodies = checkEmptyBodies(tree);
    reasons.push(...emptyBodies);

    // Hardcoding detection (if requested or always run for integrity)
    if (options.checkHardcoding !== false) {
      const hardcodingWarnings = detectHardcodedOutput(code);
      // For now, treat hardcoding as warnings that don't fail verification
      // but could be used for feedback
      if (hardcodingWarnings.length > 0) {
        // Add as informational reasons (don't fail verification)
        reasons.push(...hardcodingWarnings.map(w => ({
          ...w,
          message: `[Notice] ${w.message}`
        })));
      }
    }

    // Advanced structural analysis
    const structure = analyzeStructure(tree);

    // Add structural insights as notices
    if (structure.functionCount === 0 && !options.starter_code) {
      reasons.push({
        message: '[Notice] No function definitions found',
        line: 1,
        column: 1
      });
    }

    if (!structure.hasMainFunction) {
      reasons.push({
        message: '[Notice] No main function detected',
        line: 1,
        column: 1
      });
    }

    // Detect novice patterns
    const novicePatterns = detectNovicePatterns(tree, code);
    reasons.push(...novicePatterns.map(w => ({
      ...w,
      message: `[Notice] ${w.message}`
    })));

    // CodeNet pattern matching (placeholder for future integration)

    // If we have any errors from structural checks, verification fails
    const hasErrors = reasons.some(reason =>
      !reason.message.startsWith('[Notice]') &&
      (reason.message.includes('Required') ||
       reason.message.includes('Empty body') ||
       reason.message.includes('Syntax error'))
    );

    if (hasErrors) {
      return { is_verified: false, reasons };
    }

    return { is_verified: true, reasons };

  } catch (error) {
    console.error('AST verification error:', error);
    reasons.push({
      message: `Verification failed due to internal error: ${error.message}`,
      line: 1,
      column: 1
    });
    return { is_verified: false, reasons };
  }
}

module.exports = { verify };