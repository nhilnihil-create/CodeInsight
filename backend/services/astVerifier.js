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
    let result = '';

    function walk(node) {
      // Skip comments entirely
      if (node.type === 'comment') return;

      if (node.childCount === 0 || node.type === 'string_literal' || node.type === 'number_literal' || node.type === 'char_literal') {
        // Atomic nodes or literals
        switch (node.type) {
          case 'identifier':
            result += 'IDENT ';
            break;
          case 'string_literal':
            result += 'STR ';
            break;
          case 'number_literal':
            result += 'NUM ';
            break;
          case 'char_literal':
            result += 'CHAR ';
            break;
          case 'true':
          case 'false':
            result += 'BOOL ';
            break;
          default:
            // Keywords, symbols, etc.
            result += node.text + ' ';
        }
      } else {
        // Recursive walk for interior nodes
        for (let i = 0; i < node.childCount; i++) {
          walk(node.child(i));
        }
      }
    }

    walk(tree.rootNode);
    return result.trim();
  } catch (error) {
    console.error('Canonization error:', error);
    // Fallback to basic regex-based canonization
    let canonized = code.replace(/\/\/.*$/gm, '').replace(/\/\*[\s\S]*?\*\//g, '');
    canonized = canonized.replace(/"(?:\\.|[^"\\])*"/g, 'STR');
    canonized = canonized.replace(/'(?:\\.|[^'\\])*'/g, 'CHAR');
    canonized = canonized.replace(/\b\d+(\.\d+)?([eE][+-]?\d+)?[flL]?\b/g, 'NUM');
    canonized = canonized.replace(/\b[a-zA-Z_]\w*\b/g, (match) => {
      const keywords = ['int', 'float', 'double', 'char', 'bool', 'void', 'if', 'else', 'for', 'while', 'do', 'switch', 'case', 'default', 'break', 'continue', 'return', 'using', 'namespace', 'std', 'include', 'main'];
      return keywords.includes(match) ? match : 'IDENT';
    });
    return canonized.trim();
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
        if (child.isNamed && child.type !== 'comment') {
          hasMeaningfulContent = true;
          break;
        }
        // Special case: if it's an expression_statement containing only a semicolon, it's still "empty" in some contexts,
        // but for now we follow named node check.
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
 * @param {treeSitter.Tree} tree - Parsed tree
 * @returns {Array<{message: string, line: number, column: number}>} List of hardcoding warnings
 */
function detectHardcodedOutput(tree) {
  const warnings = [];
  const rootNode = tree.rootNode;

  /**
   * Helper to check if a node contains any variables/logic
   * (Identifiers that aren't keywords or standard library names)
   */
  function hasVariables(node) {
    if (node.type === 'identifier') {
      const text = node.text;
      const ignore = ['endl', 'cout', 'std', 'printf', 'scanf', 'cin', 'size_t', 'string'];
      return !ignore.includes(text);
    }
    // Check children
    for (let i = 0; i < node.childCount; i++) {
      if (hasVariables(node.child(i))) return true;
    }
    return false;
  }

  function traverse(node) {
    // 1. Check for cout streams
    if (node.type === 'binary_expression' && node.child(1).text === '<<') {
      // Find the base of the stream (the leftmost part)
      let curr = node;
      while (curr.type === 'binary_expression' && curr.child(1).text === '<<') {
        curr = curr.child(0);
      }

      // If the base is cout or std::cout
      if (curr.text.endsWith('cout')) {
        // Check if this is a top-level cout insertion
        let p = node.parent;
        let isTopLevelInsertion = true;
        if (p && p.type === 'binary_expression' && p.child(1).text === '<<') {
          isTopLevelInsertion = false;
        }

        if (isTopLevelInsertion) {
          // Check for variables in the entire chain
          let hasVar = false;
          function checkChain(n) {
            if (n.type === 'binary_expression' && n.child(1).text === '<<') {
              if (hasVariables(n.child(2))) hasVar = true;
              checkChain(n.child(0));
            }
          }
          checkChain(node);

          if (!hasVar) {
            warnings.push({
              message: 'Hardcoded output detected: cout used with only literals/constants',
              line: node.startPosition.row + 1,
              column: node.startPosition.column + 1
            });
          }
        }
      }
    }

    // 2. Check for printf calls
    if (node.type === 'call_expression' &&
        (node.firstChild.text === 'printf' || node.firstChild.text === 'std::printf')) {
      const args = node.lastChild; // argument_list
      let hasVar = false;
      let namedArgsFound = 0;

      for (let i = 0; i < args.childCount; i++) {
        const arg = args.child(i);
        if (arg.isNamed) {
          namedArgsFound++;
          if (namedArgsFound > 1) { // Not the format string
            if (hasVariables(arg)) {
              hasVar = true;
              break;
            }
          }
        }
      }

      if (namedArgsFound > 0 && !hasVar) {
        warnings.push({
          message: 'Hardcoded output detected: printf used without variables',
          line: node.startPosition.row + 1,
          column: node.startPosition.column + 1
        });
      }
    }

    // Recurse
    for (let i = 0; i < node.childCount; i++) {
      traverse(node.child(i));
    }
  }

  traverse(rootNode);
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
  const queue = [node];
  while (queue.length > 0) {
    const current = queue.shift();
    for (let i = 0; i < current.childCount; i++) {
      queue.push(current.child(i));
    }
    if (current.type === 'identifier' && current.text === 'main') {
      let parent = current.parent;
      while (parent) {
        if (parent.type === 'function_definition') return true;
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
    // Detect deeply nested code
    if (['if_statement', 'for_statement', 'while_statement', 'do_statement'].includes(node.type)) {
      let depth = 0;
      let parent = node.parent;
      while (parent) {
        if (['if_statement', 'for_statement', 'while_statement', 'do_statement'].includes(parent.type)) {
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

    // Detect switch without default
    if (node.type === 'switch_statement') {
      let hasDefault = false;
      const body = node.lastChild;
      if (body && body.type === 'compound_statement') {
        for (let i = 0; i < body.childCount; i++) {
          const child = body.child(i);
          if (child.type === 'case_statement' && child.firstChild && child.firstChild.text === 'default') {
            hasDefault = true;
            break;
          }
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
    const parser = getParser();
    const tree = parser.parse(code);

    if (tree.rootNode.hasError) {
      function findFirstError(node) {
        if (node.type === 'ERROR') return node;
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

    if (options.starter_code) {
      if (code.trim() === options.starter_code.trim()) {
        reasons.push({
          message: 'Submission matches starter/template code',
          line: 1,
          column: 1
        });
        return { is_verified: false, reasons };
      }
    }

    const nonWhitespace = code.replace(/\/\*.*?\*\//gs, '').replace(/\/\/.*$/gm, '').trim();
    if (nonWhitespace.length < 10) {
      reasons.push({
        message: 'Submission too short to verify',
        line: 1,
        column: 1
      });
      return { is_verified: false, reasons };
    }

    if (requirements.required_nodes && requirements.required_nodes.length) {
      const missingNodes = checkRequiredNodes(tree, requirements.required_nodes);
      reasons.push(...missingNodes);
    }

    const emptyBodies = checkEmptyBodies(tree);
    reasons.push(...emptyBodies);

    if (options.checkHardcoding !== false) {
      const hardcodingWarnings = detectHardcodedOutput(tree);
      if (hardcodingWarnings.length > 0) {
        reasons.push(...hardcodingWarnings.map(w => ({
          ...w,
          message: `[Notice] ${w.message}`
        })));
      }
    }

    const structure = analyzeStructure(tree);

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

    const novicePatterns = detectNovicePatterns(tree, code);
    reasons.push(...novicePatterns.map(w => ({
      ...w,
      message: `[Notice] ${w.message}`
    })));

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

module.exports = { verify, canonizeCode };