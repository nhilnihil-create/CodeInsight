/**
 * backend/services/astHasher.js
 *
 * Multi-language AST normalizer with sliding-window (K-mer) hashing.
 * Uses Tree-Sitter for structural parsing with a defensive regex tokenizer
 * fallback for malformed / adversarial submissions.
 *
 * Returns:
 *   { fullHash: string, windows: string[], structuralTokens: string[] }
 */

const crypto = require('crypto');

// ── Language parsers ────────────────────────────────────────────────────────
// Lazy-loaded to avoid crashing if a language grammar is missing.

let cppParser = null;
function getCppParser() {
  if (!cppParser) {
    const Parser = require('tree-sitter');
    const CPP = require('tree-sitter-cpp');
    cppParser = new Parser();
    cppParser.setLanguage(CPP);
  }
  return cppParser;
}

let pythonParser = null;
function getPythonParser() {
  if (!pythonParser) {
    const Parser = require('tree-sitter');
    const Python = require('tree-sitter-python');
    pythonParser = new Parser();
    pythonParser.setLanguage(Python);
  }
  return pythonParser;
}

const PARSER_REGISTRY = {
  cpp: getCppParser,
  c: getCppParser,       // reuse C++ parser — C++ grammar is a superset
  python: getPythonParser,
};

// ── Structural node types ───────────────────────────────────────────────────
// Only these node types participate in the structural fingerprint.
// Literals, comments, identifiers, and whitespace are intentionally excluded
// so that variable-renamed / comment-only changes don't alter the hash.

const STRUCTURAL_TYPES = new Set([
  'function_definition',
  'function_declarator',
  'for_statement',
  'while_statement',
  'do_statement',
  'if_statement',
  'else_clause',
  'return_statement',
  'assignment_expression',
  'binary_expression',
  'call_expression',
  'declaration',
  'init_declarator',
  'type_identifier',
  'compound_statement',
  'expression_statement',
  'conditional_expression',
  'update_expression',
  'unary_expression',
  'subscript_expression',
  'field_expression',
  'switch_statement',
  'case_statement',
  'break_statement',
  'continue_statement',
  'struct_specifier',
  'class_specifier',
  'namespace_definition',
  'template_declaration',
  'lambda_expression',
]);

// ── Constants ───────────────────────────────────────────────────────────────

const WINDOW_SIZE = 5;    // K-mer window size (structural tokens per chunk)
const HASH_PREFIX = 'w';  // prefix for window hash strings

// ── Tokenizer (tree-sitter path) ────────────────────────────────────────────

function extractStructuralTokens(tree) {
  const tokens = [];

  function traverse(node) {
    if (STRUCTURAL_TYPES.has(node.type)) {
      tokens.push(node.type);
    }
    // Skip leaf data: comments, string literals, numbers
    const skip = new Set(['comment', 'string_literal', 'char_literal',
                          'number_literal', 'true', 'false', 'null', 'string']);

    for (const child of node.children) {
      if (!skip.has(child.type)) {
        traverse(child);
      }
    }
  }

  traverse(tree.rootNode);
  return tokens;
}

// ── Defensive fallback tokenizer (regex path) ──────────────────────────────

function tokenizeRegexFallback(sourceCode) {
  // Strip comments, string literals, and identifiers; keep structural chars
  // and keywords. This is a best-effort backup when tree-sitter fails.
  const stripped = sourceCode
    .replace(/\/\/.*$/gm, '')                       // single-line comments
    .replace(/\/\*[\s\S]*?\*\//g, '')               // block comments
    .replace(/"[^"]*"/g, '"')                        // string literals → ""
    .replace(/'[^']*'/g, "'")                        // char literals → ''
    .replace(/\b[a-zA-Z_]\w*\b/g, 'ID')             // identifiers → ID
    .replace(/\b(int|float|double|char|void|long|short|unsigned|signed|bool|string|auto|const|static|extern|volatile|register|class|struct|enum|union|namespace|using|typedef|template|typename|public|private|protected|virtual|override|final|friend|inline|explicit|constexpr|noexcept)\b/g,
      (m) => m.toUpperCase())                        // keywords preserved
    .replace(/\s+/g, ' ')                            // collapse whitespace
    .trim();

  // Tokenize: split on whitespace and structural punctuation
  const structuralChars = /[{}();,<>+\-*/=&|!%\[\]?:\.]/g;
  const tokens = [];
  const words = stripped.split(/\s+/).filter(Boolean);

  for (const word of words) {
    // If it's a keyword (uppercased), add it
    if (/^[A-Z]+$/.test(word) && word.length > 1) {
      tokens.push(word.toLowerCase());
    }
    // Extract structural punctuation
    const punctMatches = word.match(structuralChars);
    if (punctMatches) {
      tokens.push(...punctMatches);
    }
    // Add placeholder for identifiers
    if (word === 'ID') {
      tokens.push('identifier');
    }
  }

  return tokens;
}

// ── Sliding window hasher ──────────────────────────────────────────────────

function slidingWindowHash(tokens, windowSize = WINDOW_SIZE) {
  if (tokens.length === 0) {
    return { fullHash: '', windows: [] };
  }

  // Full structural hash: hash the entire token sequence
  const serialized = tokens.join('|');
  const fullHash = crypto.createHash('sha256').update(serialized).digest('hex');

  // Sliding window (K-mer) hashing
  const windows = [];
  if (tokens.length < windowSize) {
    // Too few tokens for a window — hash the whole sequence as single window
    windows.push(
      HASH_PREFIX + crypto.createHash('sha256').update(serialized).digest('hex').slice(0, 16)
    );
  } else {
    for (let i = 0; i <= tokens.length - windowSize; i++) {
      const chunk = tokens.slice(i, i + windowSize);
      const chunkSerialized = chunk.join('|');
      const chunkHash = crypto.createHash('sha256')
        .update(chunkSerialized)
        .digest('hex')
        .slice(0, 16);  // truncate for storage efficiency
      windows.push(HASH_PREFIX + chunkHash);
    }
  }

  return { fullHash, windows };
}

// ── Public API ──────────────────────────────────────────────────────────────

/**
 * Parse source code with Tree-Sitter and compute structural fingerprints.
 * Falls back to regex tokenizer if parsing fails (adversarial / malformed code).
 *
 * @param {string} sourceCode - The source code to analyze
 * @param {string} language - Language hint: 'cpp', 'c', 'python'
 * @returns {{
 *   fullHash: string,
 *   windows: string[],
 *   structuralTokens: string[],
 *   parseError: string|null,
 *   usedFallback: boolean
 * }}
 */
function normalizeAST(sourceCode, language = 'cpp') {
  const parserFn = PARSER_REGISTRY[language] || PARSER_REGISTRY.cpp;

  try {
    const parser = parserFn();
    const tree = parser.parse(sourceCode);

    // If the tree has errors, try the fallback
    if (tree.rootNode.hasError) {
      throw new Error('Tree-Sitter parse tree contains syntax errors');
    }

    const structuralTokens = extractStructuralTokens(tree);
    const { fullHash, windows } = slidingWindowHash(structuralTokens);

    return {
      fullHash,
      windows,
      structuralTokens,
      parseError: null,
      usedFallback: false,
    };
  } catch (err) {
    // DEFENSIVE FALLBACK: regex-based structural tokenizer
    const structuralTokens = tokenizeRegexFallback(sourceCode);
    const { fullHash, windows } = slidingWindowHash(structuralTokens);

    return {
      fullHash,
      windows,
      structuralTokens,
      parseError: err.message,
      usedFallback: true,
    };
  }
}

/**
 * Compute the Jaccard similarity between two sets of window hashes.
 * Returns a value in [0, 1].
 */
function windowIntersection(windowsA, windowsB) {
  if (!windowsA.length || !windowsB.length) return 0;

  const setA = new Set(windowsA);
  const setB = new Set(windowsB);
  const intersection = [...setA].filter(w => setB.has(w)).length;
  const union = new Set([...setA, ...setB]).size;

  return union > 0 ? intersection / union : 0;
}

/**
 * Compute the match density — for each window in A, check if it exists in B.
 * Returns the fraction of A's windows found in B.
 */
function matchDensity(windowsA, windowsB) {
  if (!windowsA.length) return 0;
  const setB = new Set(windowsB);
  const matched = windowsA.filter(w => setB.has(w)).length;
  return matched / windowsA.length;
}

module.exports = {
  normalizeAST,
  windowIntersection,
  matchDensity,
  STRUCTURAL_TYPES,
  WINDOW_SIZE,
};
