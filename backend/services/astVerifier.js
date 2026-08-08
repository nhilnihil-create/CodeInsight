// AST Verification Service using tree-sitter for structural code analysis
// Implements deterministic validation based on required AST nodes and CodeNet patterns
//
// tree-sitter is lazy-loaded: if unavailable, falls back to regex-based
// structural analysis so the submission pipeline never crashes.

const { getPatternsForConcept, getVariableUsageRule } = require('./verificationRulesService');

// Module-level parser + module reference kept alive via globalThis prevents
// native addon GC when tree-sitter is loaded.
let _parser = null;
function getParser() {
  // Test seam — lets the jest suite force the no-parser fallback path even
  // when the tree-sitter native addon is installed and loadable.
  if (globalThis.__ci_force_no_parser) return null;
  if (!globalThis.__ci_ts_module) {
    try {
      globalThis.__ci_ts_module = require('tree-sitter');
      globalThis.__ci_ts_lang_cpp = require('tree-sitter-cpp');
    } catch (e) {
      globalThis.__ci_ts_module = null;
    }
  }
  if (!globalThis.__ci_ts_module) return null;
  if (!_parser) {
    try {
      _parser = new (globalThis.__ci_ts_module)();
      _parser.setLanguage(globalThis.__ci_ts_lang_cpp);
    } catch (e) {
      _parser = null;
    }
  }
  return _parser;
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

// Human-readable labels for required AST node types. Used to build feedback
// that students can act on ("must use a for loop") instead of raw node names.
const REQUIRED_NODE_LABELS = {
  for_statement: 'a for loop',
  while_statement: 'a while loop',
  do_statement: 'a do-while loop',
  if_statement: 'an if statement',
  function_definition: 'a function',
  class_specifier: 'a class',
  switch_statement: 'a switch statement',
  array_declarator: 'an array',
  subscript_expression: 'array indexing',
  pointer_declarator: 'a pointer',
  string_literal: 'a string literal',
  call_expression: 'a function call',
  struct_specifier: 'a struct',
  struct_declaration: 'a struct',
  new_expression: 'a new expression',
};

function humanLabel(nodeType) {
  return REQUIRED_NODE_LABELS[nodeType] || `a ${nodeType.replace(/_/g, ' ')}`;
}

/**
 * Verify that all required AST node types are present in the code.
 *
 * Per-exercise requirements (exercise.ast_nodes) are strict: EVERY required
 * construct must appear (anyOf = false). Concept-level requirements
 * (concepts.ast_nodes) describe alternatives — the student only needs to
 * demonstrate ONE of them (anyOf = true, e.g. Loops: for/while/do).
 */
function checkRequiredNodes(tree, requiredNodes, anyOf = false) {
  const nodeTypesFound = collectNodeTypes(tree.rootNode);

  const found = anyOf
    ? requiredNodes.some(node => nodeTypesFound.has(node))
    : requiredNodes.every(node => nodeTypesFound.has(node));
  if (found) return [];

  const missing = anyOf
    ? requiredNodes
    : requiredNodes.filter(node => !nodeTypesFound.has(node));
  const labels = missing.map(humanLabel);

  return [{
    message: `Required construct not found: ${labels.join(', ')} — your solution must use ${labels.join(', ')}`,
    line: 1, column: 1
  }];
}

// ── Check 1b: Required patterns (per-exercise queries + JS handlers) ────────

// Tree-sitter queries shared by the JS-handler pattern kinds. A self-call
// cannot be expressed as a single tree-sitter query (a call_expression is an
// expression, not a direct child of compound_statement), so the handler
// combines two working queries and correlates each function with the calls
// inside its own body.
const FN_NAME_QUERY = '(function_definition declarator: (function_declarator declarator: (identifier) @name))';
const CALL_NAME_QUERY = '(call_expression function: (identifier) @call)';
const STRING_TYPE_QUERIES = [
  '(declaration type: (type_identifier) @type)',
  '(declaration type: (qualified_identifier) @type)',
];

function collectQueryCaptureTexts(rootNode, querySource, captureName) {
  const query = new (globalThis.__ci_ts_module).Query(globalThis.__ci_ts_lang_cpp, querySource);
  const texts = [];
  for (const match of query.matches(rootNode)) {
    for (const capture of match.captures) {
      if (capture.name === captureName) texts.push(capture.node.text);
    }
  }
  return texts;
}

function functionNameOf(node) {
  const declarator = node.childForFieldName('declarator');
  if (!declarator) return null;
  const nameNode = declarator.childForFieldName('declarator');
  return nameNode && nameNode.type === 'identifier' ? nameNode.text : null;
}

function countNodeTypes(rootNode, nodeTypes) {
  // `node` in a min_count/forbidden pattern may be a single type string or an
  // array of type strings; normalize so a string is not iterated char-by-char.
  const types = Array.isArray(nodeTypes) ? nodeTypes : [nodeTypes];
  let total = 0;
  for (const type of types) {
    total += collectNodesByType(rootNode, type).length;
  }
  return total;
}

/**
 * Evaluate a single required pattern against a parsed tree.
 *
 * Pattern kinds:
 *  - 'query' (default): a tree-sitter query; passes when it yields ≥1 match.
 *  - 'self_call': passes when any function calls itself directly.
 *  - 'user_function': passes when a function other than main is defined.
 *  - 'string_type': passes when a `string` / `std::string` declaration exists.
 *  - 'min_count': passes when the combined count across `node` types is ≥ min.
 *  - 'forbidden': fails with a "Bad pattern" error when any `node` type appears.
 *
 * Query compile errors fail closed (passed = false) so a broken rule can
 * never grant verification.
 */
function evaluateRequiredPattern(tree, pattern) {
  const kind = pattern.kind || 'query';
  try {
    switch (kind) {
      case 'self_call': {
        const fnNodes = collectNodesByType(tree.rootNode, 'function_definition');
        for (const fnNode of fnNodes) {
          const name = functionNameOf(fnNode);
          if (!name) continue;
          const body = fnNode.childForFieldName('body');
          if (!body) continue;
          const calleeNames = collectQueryCaptureTexts(body, CALL_NAME_QUERY, 'call');
          if (calleeNames.includes(name)) return { passed: true };
        }
        return { passed: false };
      }
      case 'user_function': {
        const names = collectQueryCaptureTexts(tree.rootNode, FN_NAME_QUERY, 'name');
        return { passed: names.some(name => name !== 'main') };
      }
      case 'string_type': {
        const texts = [];
        for (const querySource of STRING_TYPE_QUERIES) {
          texts.push(...collectQueryCaptureTexts(tree.rootNode, querySource, 'type'));
        }
        return { passed: texts.some(t => t === 'string' || t === 'std::string') };
      }
      case 'min_count': {
        const total = countNodeTypes(tree.rootNode, pattern.node || []);
        return { passed: total >= (pattern.min || 1) };
      }
      case 'forbidden': {
        const total = countNodeTypes(tree.rootNode, pattern.node || []);
        if (total > 0) {
          return { passed: false, errorMessage: `Bad pattern: ${pattern.label} — ${pattern.hint}` };
        }
        return { passed: true };
      }
      default: {
        const query = new (globalThis.__ci_ts_module).Query(globalThis.__ci_ts_lang_cpp, pattern.query);
        return { passed: query.matches(tree.rootNode).length > 0 };
      }
    }
  } catch (queryError) {
    console.warn(`Required pattern query failed (kind: ${kind}):`, queryError.message);
    return { passed: false, errorMessage: `Required construct not found: ${pattern.label}` };
  }
}

/**
 * Verify that every required pattern is satisfied. Each failure produces a
 * `Required construct not found` error (recognized by the hasErrors matcher);
 * forbidden patterns emit their own "Bad pattern" error instead.
 */
function checkRequiredPatterns(tree, patterns) {
  const errors = [];
  for (const pattern of patterns) {
    const result = evaluateRequiredPattern(tree, pattern);
    if (!result.passed) {
      errors.push({
        message: result.errorMessage || `Required construct not found: ${pattern.label} — ${pattern.hint}`,
        line: 1, column: 1,
      });
    }
  }
  return errors;
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

// ── Check 2b: Variable Usage Verification (paper check #3) ─────────────────

/**
 * Verify that the student used variables to control program logic
 * instead of just using constants/literals.
 *
 * Reads rule config from verification_rules DB table (rule_type='variable_usage')
 * with hardcoded fallback for common concepts when DB is unavailable.
 *
 * @param {treeSitter.Tree} tree - Parsed AST
 * @param {string} conceptName - Concept tag (e.g., "Loops", "Conditionals")
 * @returns {Array<{message: string, line: number, column: number}>}
 */
async function checkVariableUsage(tree, conceptName) {
  const errors = [];

  const rule = await getVariableUsageRule(conceptName);

  if (rule) {
    // DB-driven path
    const config = typeof rule.config === 'string' ? JSON.parse(rule.config) : (rule.config || {});
    const checkNodeTypes = config.checkNodeTypes || [];
    const message = rule.student_message;

    for (const nodeType of checkNodeTypes) {
      const nodes = collectNodesByType(tree.rootNode, nodeType);
      for (const node of nodes) {
        let conditionNode = null;
        for (let i = 0; i < node.childCount; i++) {
          const child = node.child(i);
          if (child.type === 'condition' || child.type === 'binary_expression' || child.type === 'condition_clause') {
            conditionNode = child;
            break;
          }
        }
        if (!conditionNode) continue;

        const hasIdentifier = hasNodeType(conditionNode, 'identifier');
        const isTautology = conditionNode.type === 'true' ||
          (conditionNode.type === 'number_literal' && conditionNode.text !== '0');
        const hasLiteral = hasNodeType(conditionNode, 'number_literal');

        if (isTautology) {
          errors.push({ message: `${message} (tautology)`, line: node.startPosition.row + 1, column: node.startPosition.column + 1 });
        } else if (hasLiteral && !hasIdentifier) {
          errors.push({ message, line: node.startPosition.row + 1, column: node.startPosition.column + 1 });
        }
      }
    }
    return errors;
  }

  // Hardcoded fallback when DB unavailable
  if (conceptName === 'Loops') {
    const loopTypes = ['for_statement', 'while_statement', 'do_statement'];
    for (const loopType of loopTypes) {
      const loops = collectNodesByType(tree.rootNode, loopType);
      for (const loop of loops) {
        for (let i = 0; i < loop.childCount; i++) {
          const child = loop.child(i);
          if (child.type === 'condition' || child.type === 'binary_expression') {
            const hasIdentifier = hasNodeType(child, 'identifier');
            const hasLiteral = hasNodeType(child, 'number_literal');
            if (hasLiteral && !hasIdentifier) {
              errors.push({
                message: `Loop condition uses only literals — use variables to control loop logic`,
                line: loop.startPosition.row + 1,
                column: loop.startPosition.column + 1,
              });
            }
            break;
          }
        }
      }
    }
  }

  if (conceptName === 'Conditionals') {
    const ifStmts = collectNodesByType(tree.rootNode, 'if_statement');
    for (const ifStmt of ifStmts) {
      for (let i = 0; i < ifStmt.childCount; i++) {
        const child = ifStmt.child(i);
        if (child.type === 'condition' || child.type === 'condition_clause') {
          const hasIdentifier = hasNodeType(child, 'identifier');
          const isTautology = child.type === 'true' ||
            (child.type === 'number_literal' && child.text !== '0');
          if (isTautology || (!hasIdentifier && hasNodeType(child, 'number_literal'))) {
            errors.push({
              message: `Conditional uses hardcoded values — use variables to control logic`,
              line: ifStmt.startPosition.row + 1,
              column: ifStmt.startPosition.column + 1,
            });
          }
          break;
        }
      }
    }
  }

  return errors;
}

// ── Check 2c: Output Dependency Verification (paper check #4) ──────────────

/**
 * Verify that the required construct actually affects the program's output.
 * Ensures the construct isn't "dead code" that runs but never influences results.
 *
 * Per the paper: "Checks that the required construct actually affects
 * the program's output (ensuring it isn't 'dead code')."
 *
 * @param {treeSitter.Tree} tree - Parsed AST
 * @param {string[]} requiredNodes - Required AST node types
 * @returns {Array<{message: string, line: number, column: number}>}
 */
function checkOutputDependency(tree, requiredNodes) {
  const errors = [];

  // Collect all identifiers used in output statements (cout, return)
  const outputIdentifiers = new Set();

  // Find all output statements (cout, printf, puts, fprintf)
  const callExprs = collectNodesByType(tree.rootNode, 'call_expression');
  for (const call of callExprs) {
    const text = call.text || '';
    const outputFn = ['cout', 'printf', 'puts', 'fprintf', 'sprintf', 'write', 'cin'];
    if (outputFn.some(fn => text.includes(fn))) {
      const identifiers = collectIdentifiersFromNode(call);
      identifiers.forEach(id => outputIdentifiers.add(id));
    }
  }

  // Find all return statements
  const returnStmts = collectNodesByType(tree.rootNode, 'return_statement');
  for (const ret of returnStmts) {
    const identifiers = collectIdentifiersFromNode(ret);
    identifiers.forEach(id => outputIdentifiers.add(id));
  }

  // For each required construct, check if variables modified inside it
  // appear in output statements
  for (const nodeType of requiredNodes) {
    const constructs = collectNodesByType(tree.rootNode, nodeType);
    for (const construct of constructs) {
      // Collect variables modified inside this construct
      const modifiedVars = new Set();
      const assignments = collectNodesByType(construct, 'assignment_expression');
      for (const assign of assignments) {
        // Left side of assignment is the modified variable
        if (assign.childCount > 0) {
          const leftIdentifiers = collectIdentifiersFromNode(assign.child(0));
          leftIdentifiers.forEach(id => modifiedVars.add(id));
        }
      }

      // Also check for increment/decrement operators
      const updates = collectNodesByType(construct, 'update_expression');
      for (const update of updates) {
        const identifiers = collectIdentifiersFromNode(update);
        identifiers.forEach(id => modifiedVars.add(id));
      }

      // If no variables are modified inside the construct, skip
      if (modifiedVars.size === 0) continue;

      // Check if any modified variable appears in output
      const affectsOutput = [...modifiedVars].some(v => outputIdentifiers.has(v));

      if (!affectsOutput && outputIdentifiers.size > 0) {
        errors.push({
          message: `Required construct (${nodeType}) modifies variables that don't affect program output — possible dead code`,
          line: construct.startPosition.row + 1,
          column: construct.startPosition.column + 1,
        });
      }
    }
  }

  return errors;
}

/**
 * Collect all identifier names from a node and its descendants.
 */
function collectIdentifiersFromNode(node) {
  const identifiers = [];
  if (node.type === 'identifier') {
    identifiers.push(node.text);
  }
  for (let i = 0; i < node.childCount; i++) {
    identifiers.push(...collectIdentifiersFromNode(node.child(i)));
  }
  return identifiers;
}

// ── Handler functions for post-query processing ────────────────────────────

const HANDLERS = {
  checkHasReturn(tree, code, queryMatch, pattern) {
    const funcNode = queryMatch.captures.find(c => c.name === 'func')?.node;
    const bodyNode = queryMatch.captures.find(c => c.name === 'body')?.node;
    if (!funcNode || !bodyNode) return null;

    let isVoid = false;
    for (let i = 0; i < funcNode.childCount; i++) {
      const child = funcNode.child(i);
      if (child.type === 'primitive_type' && child.text === 'void') {
        isVoid = true;
        break;
      }
    }
    if (isVoid) return null;

    const hasReturn = hasNodeType(bodyNode, 'return_statement');
    if (!hasReturn) {
      const nameNode = findIdentifier(funcNode);
      const name = nameNode ? nameNode.text : 'unknown';
      return {
        message: `Bad pattern: Non-void function '${name}' has no return statement`,
        line: funcNode.startPosition.row + 1,
        column: funcNode.startPosition.column + 1
      };
    }
    return null;
  },

  checkAllPublic(tree, code, queryMatch, pattern) {
    const fieldsNode = queryMatch.captures.find(c => c.name === 'fields')?.node;
    if (!fieldsNode) return null;
    const fieldsText = code.substring(fieldsNode.startIndex, fieldsNode.endIndex);
    if (!fieldsText.includes('private') && !fieldsText.includes('protected')) {
      return {
        message: `Bad pattern: ${pattern.message}`,
        line: fieldsNode.startPosition.row + 1,
        column: fieldsNode.startPosition.column + 1
      };
    }
    return null;
  },

  checkHasConstructor(tree, code, queryMatch, pattern) {
    const classNode = queryMatch.captures.find(c => c.name === 'class_name')?.node;
    const bodyNode = queryMatch.captures.find(c => c.name === 'body')?.node;
    if (!classNode || !bodyNode) return null;

    const className = code.substring(classNode.startIndex, classNode.endIndex);
    const bodyText = code.substring(bodyNode.startIndex, bodyNode.endIndex);

    const hasConstructor = hasNodeType(bodyNode, 'function_definition') &&
      (bodyText.includes(className + '(') || bodyText.includes(className + '::' + className));

    if (!hasConstructor) {
      return {
        message: `Bad pattern: ${pattern.message}`,
        line: classNode.startPosition.row + 1,
        column: classNode.startPosition.column + 1
      };
    }
    return null;
  },

  checkUninitialized(tree, code, queryMatch, pattern) {
    const uninitNode = queryMatch.captures.find(c => c.name === 'uninit')?.node;
    if (!uninitNode) return null;
    const varName = code.substring(uninitNode.startIndex, uninitNode.endIndex);
    const declNode = uninitNode.parent;
    const bodyNode = findEnclosingBody(declNode);
    if (!bodyNode) return null;
    const bodyText = code.substring(bodyNode.startIndex, bodyNode.endIndex);
    const firstUsePos = bodyText.indexOf(varName);
    const assignPos = bodyText.indexOf(varName + ' =');
    if (assignPos === -1 || (firstUsePos >= 0 && firstUsePos < assignPos)) {
      return null;
    }
    return {
      message: `Bad pattern: ${pattern.message} '${varName}'`,
      line: uninitNode.startPosition.row + 1,
      column: uninitNode.startPosition.column + 1
    };
  },

  checkShadowed(tree, code, queryMatch, pattern) {
    const nameNode = queryMatch.captures.find(c => c.name === 'name')?.node;
    if (!nameNode) return null;
    const varName = code.substring(nameNode.startIndex, nameNode.endIndex);
    let parent = nameNode.parent;
    while (parent) {
      parent = parent.parent;
      if (!parent) break;
      const parentText = code.substring(parent.startIndex, parent.endIndex);
      if (parentText.includes(varName) && parent.type !== 'translation_unit') {
        const sibDecls = [];
        for (let i = 0; i < parent.childCount; i++) {
          const c = parent.child(i);
          if (c.type === 'declaration') {
            const ct = code.substring(c.startIndex, c.endIndex);
            sibDecls.push(ct);
          }
        }
        const siblingCount = sibDecls.filter(t => t.includes(varName)).length;
        if (siblingCount > 1) {
          return {
            message: `Bad pattern: ${pattern.message} '${varName}'`,
            line: nameNode.startPosition.row + 1,
            column: nameNode.startPosition.column + 1
          };
        }
        break;
      }
    }
    return null;
  },

  checkLoopVarReassigned(tree, code, queryMatch, pattern) {
    const loopVarNode = queryMatch.captures.find(c => c.name === 'loopvar')?.node;
    const bodyNode = queryMatch.captures.find(c => c.name === 'body')?.node;
    if (!loopVarNode || !bodyNode) return null;
    const varName = code.substring(loopVarNode.startIndex, loopVarNode.endIndex);
    const bodyText = code.substring(bodyNode.startIndex, bodyNode.endIndex);

    const assignPattern = new RegExp(`(^|[\\s;])${varName}\\s*(=|\\+=|-=|\\*=|\\/=|%=)`, 'g');
    if (assignPattern.test(bodyText)) {
      return {
        message: `Bad pattern: Loop variable '${varName}' reassigned inside loop body`,
        line: bodyNode.startPosition.row + 1,
        column: bodyNode.startPosition.column + 1
      };
    }
    return null;
  },

  checkSameLoopVariable(tree, code, queryMatch, pattern) {
    const innerNode = queryMatch.captures.find(c => c.name === 'outer')?.node;
    if (!innerNode) return null;
    const innerVarName = code.substring(innerNode.startIndex, innerNode.endIndex);

    // The for_statement that OWNS the declaration containing this identifier.
    // Skipping it is critical: without that, every loop would "match itself"
    // and reject valid single/nested loops.
    let owner = innerNode.parent;
    while (owner && owner.type !== 'for_statement') {
      owner = owner.parent;
    }
    if (!owner) return null;

    // Only enclosing for_statement ancestors (excluding the owner) count: a
    // nested loop that reuses an ancestor loop's variable name is the pattern.
    let ancestor = owner.parent;
    while (ancestor) {
      if (ancestor.type === 'for_statement') {
        const outerVarName = getForLoopVariableName(ancestor, code);
        if (outerVarName && outerVarName === innerVarName) {
          return {
            message: `Bad pattern: ${pattern.message}`,
            line: innerNode.startPosition.row + 1,
            column: innerNode.startPosition.column + 1
          };
        }
      }
      ancestor = ancestor.parent;
    }
    return null;
  },
};

function findEnclosingBody(node) {
  let cur = node.parent;
  while (cur) {
    if (cur.type === 'compound_statement' || cur.type === 'function_definition') return cur;
    cur = cur.parent;
  }
  return null;
}

/**
 * Return the name of the loop variable declared in a classic for-statement's
 * init clause, or null when the loop has no in-clause declaration (e.g.
 * `for (i = 0; ...)` with a pre-declared variable, or a range-for loop).
 */
function getForLoopVariableName(forNode, code) {
  if (!forNode) return null;
  for (let i = 0; i < forNode.childCount; i++) {
    const child = forNode.child(i);
    if (child.type !== 'declaration') continue;
    for (let j = 0; j < child.childCount; j++) {
      const declarator = child.child(j);
      if (declarator.type !== 'init_declarator') continue;
      for (let k = 0; k < declarator.childCount; k++) {
        const sub = declarator.child(k);
        if (sub.type === 'identifier') {
          return code.substring(sub.startIndex, sub.endIndex);
        }
      }
    }
  }
  return null;
}

// ── Check 3: Bad pattern matching (CodeNet-derived) via tree-sitter Query API

/**
 * Check submission against known bad patterns using compiled tree-sitter queries.
 * Patterns come from the verification_rules DB table (data-driven) with fallback
 * to badPatterns.js in-memory definitions when the DB is unavailable.
 *
 * @param {treeSitter.Tree} tree - Parsed AST
 * @param {string} conceptName - Concept tag (e.g., "Loops")
 * @param {string} code - Raw source code (needed by some handlers)
 * @returns {Array<{message: string, line: number, column: number}>}
 */
async function checkBadPatterns(tree, conceptName, code) {
  if (!globalThis.__ci_ts_module) return [];

  const errors = [];
  const patterns = await getPatternsForConcept(conceptName);

  for (const pattern of patterns) {
    try {
      const query = new (globalThis.__ci_ts_module).Query(globalThis.__ci_ts_lang_cpp, pattern.query);
      const matches = query.matches(tree.rootNode);

      for (const match of matches) {
        if (pattern.handler && HANDLERS[pattern.handler]) {
          const result = HANDLERS[pattern.handler](tree, code || '', match, pattern);
          if (result) errors.push(result);
        } else if (match.captures.length > 0) {
          const cap = match.captures[0];
          errors.push({
            message: `Bad pattern: ${pattern.message}`,
            line: cap.node.startPosition.row + 1,
            column: cap.node.startPosition.column + 1
          });
        }
      }
    } catch (queryError) {
      console.warn(`Bad pattern query failed for '${pattern.id}':`, queryError.message);
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

// ── Main verify function ────────────────────────────────────────────────────

async function verify(code, requirements = {}, options = {}) {
  const reasons = [];

  try {
    const parser = getParser();

    // When tree-sitter is unavailable, fall back to regex-based analysis
    if (!parser) {
      if (options.starter_code && canonicFallback(code) === canonicFallback(options.starter_code)) {
        reasons.push({ message: 'Submission matches starter/template code', line: 1, column: 1 });
        return { is_verified: false, reasons };
      }
      if (code.length < 10) {
        reasons.push({ message: 'Submission too short to verify', line: 1, column: 1 });
        return { is_verified: false, reasons };
      }
      // Fail closed when required constructs cannot be confirmed: a solution
      // that passes tests but whose required structure is unverifiable must
      // not count as verified. Without declared requirements, fall back to
      // the permissive regex-based pass (legacy behavior).
      if ((requirements.required_nodes && requirements.required_nodes.length) ||
          (requirements.required_patterns && requirements.required_patterns.length)) {
        reasons.push({
          message: 'Structure verification unavailable (parser not loaded) — cannot confirm required constructs. Please try again.',
          line: 1, column: 1
        });
        return { is_verified: false, reasons };
      }
      return { is_verified: true, reasons };
    }

    const tree = parser.parse(code);

    // Check for actual ERROR nodes (tree.rootNode.hasError can be a false positive in v0.22)
    function findErrorNode(node) {
      if (node.type === 'ERROR') return node;
      for (let i = 0; i < node.childCount; i++) {
        const error = findErrorNode(node.child(i));
        if (error) return error;
      }
      return null;
    }
    // A healthy tree-sitter parse always yields a root node; if it is missing
    // (corrupted native/parser state), fail closed instead of crashing.
    if (!tree || !tree.rootNode) {
      reasons.push({
        message: 'Verification failed due to internal error: parser returned an invalid parse tree',
        line: 1, column: 1
      });
      return { is_verified: false, reasons };
    }
    const errorNode = findErrorNode(tree.rootNode);
    if (errorNode) {
      reasons.push({
        message: 'Syntax error in code - unable to parse',
        line: errorNode.startPosition.row + 1,
        column: errorNode.startPosition.column + 1
      });
      return { is_verified: false, reasons };
    }

    // Check: matches starter code (compare canonical forms per paper spec)
    if (options.starter_code) {
      if (canonizeCode(code) === canonizeCode(options.starter_code)) {
        reasons.push({
          message: 'Submission matches starter/template code',
          line: 1, column: 1
        });
        return { is_verified: false, reasons };
      }
    }

    // Check: too short (after canonicalization, comments already stripped)
    if (code.length < 10) {
      reasons.push({
        message: 'Submission too short to verify',
        line: 1, column: 1
      });
      return { is_verified: false, reasons };
    }

    // Check 1: Required AST nodes (construct presence)
    // anyOf = true → alternatives (concept-level lists); default → all required
    if (requirements.required_nodes && requirements.required_nodes.length) {
      const missingNodes = checkRequiredNodes(tree, requirements.required_nodes, requirements.any_of === true);
      reasons.push(...missingNodes);
    }

    // Check 1b: Required patterns (per-exercise tree-sitter queries + handlers)
    if (requirements.required_patterns && requirements.required_patterns.length) {
      const patternErrors = checkRequiredPatterns(tree, requirements.required_patterns);
      reasons.push(...patternErrors);
    }

    // Check 2: Non-empty body check
    const emptyBodies = checkEmptyBodies(tree);
    reasons.push(...emptyBodies);

    // Check 2b: Variable usage verification (paper check #3)
    if (options.concept_name) {
      const variableErrors = await checkVariableUsage(tree, options.concept_name);
      reasons.push(...variableErrors);
    }

    // Check 2c: Output dependency verification (paper check #4)
    if (requirements.required_nodes && requirements.required_nodes.length) {
      const outputErrors = checkOutputDependency(tree, requirements.required_nodes);
      reasons.push(...outputErrors);
    }

    // Check 3: Bad pattern matching (CodeNet-derived) via tree-sitter Query API
    if (options.concept_name) {
      const badPatternErrors = await checkBadPatterns(tree, options.concept_name, code);
      reasons.push(...badPatternErrors);
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

    // Determine verification result
    const hasErrors = reasons.some(reason =>
      !reason.message.startsWith('[Notice]') &&
      (reason.message.includes('Required') ||
       reason.message.includes('Empty body') ||
       reason.message.includes('Syntax error') ||
       reason.message.includes('Bad pattern') ||
       reason.message.includes('starter/template') ||
       reason.message.includes('too short') ||
       reason.message.includes('Loop condition uses only literals') ||
       reason.message.includes('Conditional uses hardcoded') ||
       reason.message.includes("doesn't affect program output"))
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

function canonicFallback(code) {
  let c = code.replace(/\/\/.*$/gm, '').replace(/\/\*[\s\S]*?\*\//g, '');
  c = c.replace(/"(?:\\.|[^"\\])*"/g, 'STR');
  c = c.replace(/'(?:\\.|[^'\\])*'/g, 'CHAR');
  c = c.replace(/\b\d+(\.\d+)?([eE][+-]?\d+)?[flL]?\b/g, 'NUM');
  c = c.replace(/\b[a-zA-Z_]\w*\b/g, (match) => {
    const keywords = ['int','float','double','char','bool','void','if','else','for','while','do','switch','case','default','break','continue','return','using','namespace','std','include','main'];
    return keywords.includes(match) ? match : 'IDENT';
  });
  return c.trim();
}

module.exports = { verify, canonizeCode };
