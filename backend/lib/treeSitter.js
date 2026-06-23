let parser = null;
let Parser = null;
let CPP = null;

function getParser() {
  if (parser) return parser;
  Parser = require('tree-sitter');
  CPP = require('tree-sitter-cpp');
  parser = new Parser();
  parser.setLanguage(CPP);
  return parser;
}

function parseAST(code) {
  try {
    const p = getParser();
    const tree = p.parse(code);
    const nodeTypes = new Set();
    const nodeCount = { if_statement: 0, else_clause: 0, private_section: 0, protected_section: 0 };
    (function traverse(node) {
      nodeTypes.add(node.type);
      if (node.type === 'if_statement') nodeCount.if_statement++;
      if (node.type === 'else_clause') nodeCount.else_clause++;
      if (node.type === 'private_section') nodeCount.private_section++;
      if (node.type === 'protected_section') nodeCount.protected_section++;
      for (let i = 0; i < node.childCount; i++) traverse(node.child(i));
    })(tree.rootNode);
    return {
      node_types: Array.from(nodeTypes),
      if_count: nodeCount.if_statement,
      else_count: nodeCount.else_clause,
      has_private: nodeCount.private_section > 0 || nodeCount.protected_section > 0,
    };
  } catch {
    return { node_types: [], if_count: 0, else_count: 0, has_private: false };
  }
}

module.exports = { getParser, parseAST };
