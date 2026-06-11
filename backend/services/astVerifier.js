// AST Verification Service using tree-sitter for structural code analysis
// Implements deterministic validation based on required AST nodes and CodeNet patterns

const treeSitter = require('tree-sitter');
const CPP = require('tree-sitter-cpp');
const { getBadPatterns } = require('./badPatterns');

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

// ── Canonization ────────────────────────────────────────────────────────────

function canonizeCode(code) {
  try {
    const parser = getParser();
    const tree = parser.parse(code);
    let result = '';

    function walk(node) {
      if (node.type === 'comment') return;
      if (node.childCount === 0 || node.type === 'string_literal' || node.type === 'number_literal' || node.type === 'char_literal') {
        switch (node.type) {
          case 'identifier': result += 'IDENT '; break;
          case 'string_literal': result += 'STR '; break;
          case 'number_literal': result += 'NUM '; break;
          case 'char_literal': result += 'CHAR '; break;
          case 'true': case 'false': result += 'BOOL '; break;
          default: result += node.text + ' ';
        }
      } else {
        for (let i = 0; i < node.childCount; i++) walk(node.child(i));
      }
    }
    walk(tree.rootNode);
    return result.trim();
  } catch (error) {
    console.error('Canonization error:', error);
    let canonized = code.replace(/\/\/.*$/gm, '').replace(/\/\*[\s\S]*?\*\//g, '');
    canonized = canonized.replace(/"(?:\\.|[^"\\])*"/g, 'STR');
    canonized = canonized.replace(/'(?:\\.|[^'\\])*'/g, 'CHAR');
    canonized = canonized.replace(/\b\d+(\.\d+)?([eE][+-]?\d+)?[flL]?\b/g, 'NUM');
    canonized = canonized.replace(/\b[a-zA-Z_]\w*\b/g, (match) => {
      const keywords = ['int','float','double','char','bool','void','if','else','for','while','do','switch','case','default','break','continue','return','using','namespace','std','include','main'];
      return keywords.includes(match) ? match : 'IDENT';
    });
    return canonized.trim();
  }
}

// ── Node collection helper ──────────────────────────────────────────────────

function collectNodeTypes(rootNode) {
  const types = new Set();
  const stack = [rootNode];
  while (stack.length > 0) {
    const node = stack.pop();
    types.add(node.type);
    for (let i = node.childCount - 1; i >= 0; i--) stack.push(node.child(i));
  }
  return types;
}

function collectNodesByType(rootNode, type) {
  const found = [];
  const stack = [rootNode];
  while (stack.length > 0) {
    const node = stack.pop();
    if (node.type === type) found.push(node);
    for (let i = node.childCount - 1; i >= 0; i--) stack.push(node.child(i));
  }
  return found;
}

// ── Check 1: Required AST nodes ─────────────────────────────────────────────

function checkRequiredNodes(tree, requiredNodes) {
  const missingNodes = [];
  const nodeTypesFound = collectNodeTypes(tree.rootNode);
  for (const requiredNode of requiredNodes) {
    if (!nodeTypesFound.has(requiredNode)) {
      missingNodes.push({
        message: `Required AST node '${requiredNode}' not found in code`,
        line: 1, column: 1
      });
    }
  }
  return missingNodes;
}

// ── Check 2: Empty body check ───────────────────────────────────────────────

function checkEmptyBodies(tree) {
  const errors = [];
  const bodyConstructs = new Set([
    'if_statement', 'else_clause', 'while_statement',
    'do_statement', 'for_statement', 'compound_statement'
  ]);

  function traverse(node) {
    if (bodyConstructs.has(node.type)) {
      let hasMeaningfulContent = false;
      for (let i = 0; i < node.childCount; i++) {
        const child = node.child(i);
        if (child.isNamed && child.type !== 'comment') {
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
    for (let i = 0; i < node.childCount; i++) traverse(node.child(i));
  }
  traverse(tree.rootNode);
  return errors;
}

// ── Check 3: Bad pattern matching (CodeNet-derived) — GAP #1 ────────────────

/**
 * Check submission against known bad patterns from CodeNet analysis.
 * Patterns are concept-specific tree-sitter queries that match syntactically-valid
 * but semantically-wrong code structures.
 *
 * @param {treeSitter.Tree} tree - Parsed AST
 * @param {string} conceptName - Concept tag of the exercise (e.g., "Loops")
 * @returns {Array<{message: string, line: number, column: number}>}
 */
function checkBadPatterns(tree, conceptName) {
  const errors = [];
  const patterns = getBadPatterns(conceptName);

  for (const pattern of patterns) {
    // Use simplified node type matching since tree-sitter S-expressions
    // require query compilation which isn't available in the JS API.
    // We detect bad patterns by checking for the node types they reference.
    const nodeTypes = collectNodeTypes(tree.rootNode);

    // Assignment in condition detection
    if (pattern.id === 'assignment_in_condition') {
      const ifStmts = collectNodesByType(tree.rootNode, 'if_statement');
      for (const ifStmt of ifStmts) {
        for (let i = 0; i < ifStmt.childCount; i++) {
          const child = ifStmt.child(i);
          if (child.type === 'condition' || (i === 1 && child.type !== 'compound_statement')) {
            // Check if condition contains assignment_expression
            const hasAssign = hasNodeType(child, 'assignment_expression');
            if (hasAssign) {
              errors.push({
                message: `Bad pattern: ${pattern.message}`,
                line: ifStmt.startPosition.row + 1,
                column: ifStmt.startPosition.column + 1
              });
            }
            break;
          }
        }
      }
    }

    // Always-true condition detection
    if (pattern.id === 'tautology_condition') {
      const ifStmts = collectNodesByType(tree.rootNode, 'if_statement');
      for (const ifStmt of ifStmts) {
        for (let i = 0; i < ifStmt.childCount; i++) {
          const child = ifStmt.child(i);
          if (child.type === 'true' || (child.type === 'number_literal' && child.text !== '0')) {
            // Only flag if it's in the condition position
            if (i <= 1) {
              errors.push({
                message: `Bad pattern: ${pattern.message}`,
                line: ifStmt.startPosition.row + 1,
                column: ifStmt.startPosition.column + 1
              });
            }
          }
        }
      }
    }

    // Missing return in non-void function
    if (pattern.id === 'missing_return') {
      const funcDefs = collectNodesByType(tree.rootNode, 'function_definition');
      for (const func of funcDefs) {
        // Check return type
        let isVoid = false;
        for (let i = 0; i < func.childCount; i++) {
          const child = func.child(i);
          if (child.type === 'primitive_type' && child.text === 'void') {
            isVoid = true;
            break;
          }
        }
        if (isVoid) continue;

        // Check for return statement in body
        const hasReturn = hasNodeType(func, 'return_statement');
        if (!hasReturn) {
          const nameNode = findIdentifier(func);
          const name = nameNode ? nameNode.text : 'unknown';
          errors.push({
            message: `Bad pattern: Non-void function '${name}' has no return statement`,
            line: func.startPosition.row + 1,
            column: func.startPosition.column + 1
          });
        }
      }
    }
  }

  return errors;
}

function hasNodeType(node, type) {
  if (node.type === type) return true;
  for (let i = 0; i < node.childCount; i++) {
    if (hasNodeType(node.child(i), type)) return true;
  }
  return false;
}

function findIdentifier(node) {
  if (node.type === 'identifier') return node;
  for (let i = 0; i < node.childCount; i++) {
    const found = findIdentifier(node.child(i));
    if (found) return found;
  }
  return null;
}

// ── Check 4: Output Dependency Check — GAP #2 ───────────────────────────────

/**
 * Verify that detected constructs (loops, conditionals) actually affect program output.
 * A construct fails this check if its body contains no output path:
 *   - No cout/printf/call to output functions
 *   - No return statement with a value
 *   - No assignment to a variable that is later output
 *
 * @param {treeSitter.Tree} tree - Parsed AST
 * @returns {Array<{message: string, line: number, column: number}>}
 */
function checkOutputDependency(tree) {
  const errors = [];
  const constructTypes = ['for_statement', 'while_statement', 'do_statement', 'if_statement'];

  for (const type of constructTypes) {
    const constructs = collectNodesByType(tree.rootNode, type);

    for (const construct of constructs) {
      // Find the body of the construct
      let body = null;
      for (let i = 0; i < construct.childCount; i++) {
        const child = construct.child(i);
        if (child.type === 'compound_statement' || child.type === 'statement') {
          body = child;
          break;
        }
      }
      if (!body) continue;

      // Check if body has output-affecting code
      const hasOutput = bodyHasOutput(body);
      const hasSideEffect = bodyHasSideEffects(body);

      if (!hasOutput && !hasSideEffect) {
        errors.push({
          message: `${type.replace('_statement', '')} does not affect program output (dead code)`,
          line: construct.startPosition.row + 1,
          column: construct.startPosition.column + 1
        });
      }
    }
  }

  return errors;
}

function bodyHasOutput(node) {
  // Check for cout, printf, scanf, cin, or any call that affects I/O
  if (node.type === 'call_expression') {
    const fn = node.firstChild;
    if (fn) {
      const text = fn.text;
      if (text.includes('cout') || text.includes('printf') || text.includes('scanf') ||
          text.includes('cin') || text.includes('puts') || text.includes('getchar')) {
        return true;
      }
    }
  }

  // Check for << operator with cout
  if (node.type === 'binary_expression') {
    const text = node.text || '';
    if (text.includes('cout') || text.includes('<<')) {
      // Verify it's actually a cout chain
      if (hasNodeType(node, 'identifier')) {
        for (let i = 0; i < node.childCount; i++) {
          if (node.child(i).text === 'cout') return true;
        }
      }
    }
  }

  // Check for return statement with value
  if (node.type === 'return_statement' && node.childCount > 1) {
    return true;
  }

  // Recurse into children
  for (let i = 0; i < node.childCount; i++) {
    if (bodyHasOutput(node.child(i))) return true;
  }
  return false;
}

function bodyHasSideEffects(node) {
  // Check for variable assignments (which might feed into output later)
  if (node.type === 'assignment_expression' || node.type === 'init_declarator' ||
      node.type === 'update_expression') {
    return true;
  }

  // Check for function calls (may have side effects)
  if (node.type === 'call_expression') {
    const fn = node.firstChild;
    if (fn && fn.type === 'identifier') {
      // Ignore known pure functions
      const pure = ['main', 'abs', 'sqrt', 'pow', 'strlen', 'strcmp', 'min', 'max'];
      if (!pure.includes(fn.text)) return true;
    }
  }

  // Recurse
  for (let i = 0; i < node.childCount; i++) {
    if (bodyHasSideEffects(node.child(i))) return true;
  }
  return false;
}

// ── Check 5: Variable Usage Check (upgraded) — GAP #5 ───────────────────────

/**
 * Verify that constructs use variables (not just constants).
 * e.g., `for (int i = 0; i < 10; i++) { cout << 42; }` → flagged
 *
 * @param {treeSitter.Tree} tree - Parsed AST
 * @returns {Array<{message: string, line: number, column: number}>}
 */
function checkVariableUsage(tree) {
  const warnings = [];
  const constructTypes = ['for_statement', 'while_statement', 'do_statement'];

  for (const type of constructTypes) {
    const constructs = collectNodesByType(tree.rootNode, type);

    for (const construct of constructs) {
      // Find the body
      let body = null;
      for (let i = 0; i < construct.childCount; i++) {
        const child = construct.child(i);
        if (child.type === 'compound_statement' || child.type === 'statement') {
          body = child;
          break;
        }
      }
      if (!body) continue;

      // Check: does the body use any variables?
      const usesVariables = bodyUsesVariables(body);
      if (!usesVariables) {
        warnings.push({
          message: `Construct body uses only constants (no variables)`,
          line: construct.startPosition.row + 1,
          column: construct.startPosition.column + 1
        });
      }
    }
  }

  return warnings;
}

function bodyUsesVariables(node) {
  // Check for identifiers that are variables (not keywords/functions)
  if (node.type === 'identifier') {
    const ignore = ['endl', 'cout', 'std', 'printf', 'scanf', 'cin', 'main',
                    'int', 'float', 'double', 'char', 'bool', 'void', 'string',
                    'size_t', 'true', 'false', 'NULL', 'nullptr'];
    if (!ignore.includes(node.text)) return true;
  }

  // Check for subscript expressions (array access with variable index)
  if (node.type === 'subscript_expression') {
    for (let i = 0; i < node.childCount; i++) {
      if (node.child(i).type === 'identifier') return true;
    }
  }

  // Recurse
  for (let i = 0; i < node.childCount; i++) {
    if (bodyUsesVariables(node.child(i))) return true;
  }
  return false;
}

// ── Hardcoded output check (existing, unchanged) ────────────────────────────

function detectHardcodedOutput(tree) {
  const warnings = [];

  function hasVariables(node) {
    if (node.type === 'identifier') {
      const text = node.text;
      const ignore = ['endl', 'cout', 'std', 'printf', 'scanf', 'cin', 'size_t', 'string'];
      return !ignore.includes(text);
    }
    for (let i = 0; i < node.childCount; i++) {
      if (hasVariables(node.child(i))) return true;
    }
    return false;
  }

  function traverse(node) {
    if (node.type === 'binary_expression' && node.childCount > 1 && node.child(1).text === '<<') {
      let curr = node;
      while (curr.type === 'binary_expression' && curr.childCount > 1 && curr.child(1).text === '<<') {
        curr = curr.child(0);
      }
      if (curr.text.endsWith('cout')) {
        let p = node.parent;
        let isTopLevelInsertion = true;
        if (p && p.type === 'binary_expression' && p.childCount > 1 && p.child(1).text === '<<') {
          isTopLevelInsertion = false;
        }
        if (isTopLevelInsertion) {
          let hasVar = false;
          function checkChain(n) {
            if (n.type === 'binary_expression' && n.childCount > 1 && n.child(1).text === '<<') {
              if (n.childCount > 2 && hasVariables(n.child(2))) hasVar = true;
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

    if (node.type === 'call_expression' && node.firstChild &&
        (node.firstChild.text === 'printf' || node.firstChild.text === 'std::printf')) {
      const args = node.lastChild;
      let hasVar = false;
      let namedArgsFound = 0;
      if (args) {
        for (let i = 0; i < args.childCount; i++) {
          const arg = args.child(i);
          if (arg.isNamed) {
            namedArgsFound++;
            if (namedArgsFound > 1) {
              if (hasVariables(arg)) { hasVar = true; break; }
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

    for (let i = 0; i < node.childCount; i++) traverse(node.child(i));
  }

  traverse(tree.rootNode);
  return warnings;
}

// ── Structure analysis ──────────────────────────────────────────────────────

function analyzeStructure(tree) {
  const stats = {
    nodeTypes: new Set(), functionCount: 0, classCount: 0,
    loopCount: 0, conditionalCount: 0, hasReturnStatement: false,
    hasMainFunction: false, complexity: 0
  };

  function traverse(node) {
    stats.nodeTypes.add(node.type);
    switch (node.type) {
      case 'function_definition':
        stats.functionCount++;
        if (isMainFunction(node)) stats.hasMainFunction = true;
        break;
      case 'return_statement': stats.hasReturnStatement = true; break;
      case 'class_specifier': stats.classCount++; break;
      case 'while_statement': case 'do_statement': case 'for_statement': stats.loopCount++; break;
      case 'if_statement': case 'switch_statement': stats.conditionalCount++; break;
    }
    if (['if_statement', 'for_statement', 'while_statement', 'do_statement'].includes(node.type)) {
      stats.complexity++;
    }
    for (let i = 0; i < node.childCount; i++) traverse(node.child(i));
  }
  traverse(tree.rootNode);
  stats.nodeTypes = Array.from(stats.nodeTypes);
  return stats;
}

function isMainFunction(node) {
  const queue = [node];
  while (queue.length > 0) {
    const current = queue.shift();
    for (let i = 0; i < current.childCount; i++) queue.push(current.child(i));
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

function detectNovicePatterns(tree, code) {
  const warnings = [];

  function traverse(node) {
    if (['if_statement', 'for_statement', 'while_statement', 'do_statement'].includes(node.type)) {
      let depth = 0;
      let parent = node.parent;
      while (parent) {
        if (['if_statement', 'for_statement', 'while_statement', 'do_statement'].includes(parent.type)) depth++;
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

    if (node.type === 'switch_statement') {
      let hasDefault = false;
      const body = node.lastChild;
      if (body && body.type === 'compound_statement') {
        for (let i = 0; i < body.childCount; i++) {
          const child = body.child(i);
          if (child.type === 'case_statement' && child.firstChild && child.firstChild.text === 'default') {
            hasDefault = true; break;
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

    for (let i = 0; i < node.childCount; i++) traverse(node.child(i));
  }
  traverse(tree.rootNode);
  return warnings;
}

// ── Main verify function ────────────────────────────────────────────────────

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

    // Check: matches starter code
    if (options.starter_code) {
      if (code.trim() === options.starter_code.trim()) {
        reasons.push({
          message: 'Submission matches starter/template code',
          line: 1, column: 1
        });
        return { is_verified: false, reasons };
      }
    }

    // Check: too short
    const nonWhitespace = code.replace(/\/\*.*?\*\//gs, '').replace(/\/\/.*$/gm, '').trim();
    if (nonWhitespace.length < 10) {
      reasons.push({
        message: 'Submission too short to verify',
        line: 1, column: 1
      });
      return { is_verified: false, reasons };
    }

    // Check 1: Required AST nodes (construct presence)
    if (requirements.required_nodes && requirements.required_nodes.length) {
      const missingNodes = checkRequiredNodes(tree, requirements.required_nodes);
      reasons.push(...missingNodes);
    }

    // Check 2: Non-empty body check
    const emptyBodies = checkEmptyBodies(tree);
    reasons.push(...emptyBodies);

    // Check 3: Bad pattern matching (CodeNet-derived) — GAP #1
    if (options.concept_name) {
      const badPatternErrors = checkBadPatterns(tree, options.concept_name);
      reasons.push(...badPatternErrors);
    }

    // Check 4: Output dependency check — GAP #2
    const outputDeps = checkOutputDependency(tree);
    reasons.push(...outputDeps.map(e => ({
      ...e,
      message: `Output dependency: ${e.message}`
    })));

    // Check 5: Variable usage check (upgraded) — GAP #5
    const varUsageWarnings = checkVariableUsage(tree);
    reasons.push(...varUsageWarnings.map(w => ({
      ...w,
      message: `Variable usage: ${w.message}`
    })));

    // Existing: Hardcoded output check
    if (options.checkHardcoding !== false) {
      const hardcodingWarnings = detectHardcodedOutput(tree);
      if (hardcodingWarnings.length > 0) {
        reasons.push(...hardcodingWarnings.map(w => ({
          ...w,
          message: `[Notice] ${w.message}`
        })));
      }
    }

    // Structure analysis
    const structure = analyzeStructure(tree);
    if (structure.functionCount === 0 && !options.starter_code) {
      reasons.push({
        message: '[Notice] No function definitions found',
        line: 1, column: 1
      });
    }
    if (!structure.hasMainFunction) {
      reasons.push({
        message: '[Notice] No main function detected',
        line: 1, column: 1
      });
    }

    const novicePatterns = detectNovicePatterns(tree, code);
    reasons.push(...novicePatterns.map(w => ({
      ...w,
      message: `[Notice] ${w.message}`
    })));

    // Determine verification result
    const hasErrors = reasons.some(reason =>
      !reason.message.startsWith('[Notice]') &&
      (reason.message.includes('Required') ||
       reason.message.includes('Empty body') ||
       reason.message.includes('Syntax error') ||
       reason.message.includes('Bad pattern') ||
       reason.message.includes('Output dependency') ||
       reason.message.includes('starter/template') ||
       reason.message.includes('too short'))
    );

    if (hasErrors) {
      return { is_verified: false, reasons };
    }

    return { is_verified: true, reasons };

  } catch (error) {
    console.error('AST verification error:', error);
    reasons.push({
      message: `Verification failed due to internal error: ${error.message}`,
      line: 1, column: 1
    });
    return { is_verified: false, reasons };
  }
}

module.exports = { verify, canonizeCode };
