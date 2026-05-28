/**
 * CodeNet Pattern Ingestion Script
 * Filters IBM Project CodeNet dataset for C++ introductory problems
 * Parses code with tree-sitter to extract AST skeletons
 * Generates hashes for O(1) lookup and stores in ast_templates table
 */

require('dotenv').config();
const { Pool } = require('pg');
const treeSitter = require('tree-sitter');
const CPP = require('tree-sitter-cpp');
const crypto = require('crypto');
const fs = require('fs');
const path = require('path');

// Database connection
const db = new Pool({
  host: process.env.DB_HOST,
  port: process.env.DB_PORT,
  database: process.env.DB_NAME,
  user: process.env.DB_USER,
  password: process.env.DB_PASSWORD
});

// Initialize tree-sitter parser
function getParser() {
  const parser = new treeSitter();
  parser.setLanguage(CPP);
  return parser;
}

/**
 * Extract AST node types from parsed code
 * @param {string} code - Source code to analyze
 * @returns {string[]} Array of unique AST node types found
 */
function extractNodeTypes(code) {
  try {
    const parser = getParser();
    const tree = parser.parse(code);

    const nodeTypes = new Set();

    function traverse(node) {
      nodeTypes.add(node.type);
      for (let i = 0; i < node.childCount; i++) {
        traverse(node.child(i));
      }
    }

    traverse(tree.rootNode);
    return Array.from(nodeTypes);
  } catch (error) {
    console.warn('Error parsing code for node types:', error.message);
    return [];
  }
}

/**
 * Create canonical representation by stripping identifiers/literals
 * @param {string} code - Source code to canonize
 * @returns {string} Canonical string
 */
function createCanonicalString(code) {
  // Remove comments
  let canonical = code.replace(/\/\/.*$/gm, '').replace(/\/\*[\s\S]*?\*\//g, '');

  // Replace string literals with placeholder
  canonical = canonical.replace(/"(?:\\.|[^"\\])*"/g, '"STR"');

  // Replace character literals
  canonical = canonical.replace(/'(?:\\.|[^'\\])*'/g, "'C'");

  // Replace numeric literals
  canonical = canonical.replace(/\b\d+(\.\d+)?([eE][+-]?\d+)?[flL]?\b/g, 'NUM');

  // Replace identifiers (simplified approach)
  canonical = canonical.replace(/\b[a-zA-Z_]\w*\b/g, 'IDENT');

  return canonical;
}

/**
 * Generate SHA-256 hash of canonical string
 * @param {string} canonicalString - Canonical representation of code
 * @returns {string} SHA-256 hash (hex)
 */
function generateASTHash(canonicalString) {
  return crypto.createHash('sha256').update(canonicalString).digest('hex');
}

/**
 * Map file path or metadata to concept ID
 * This is a simplified mapper - in reality, you'd have a proper mapping
 * based on problem categories or metadata from CodeNet
 * @param {string} filePath - Path to the source file
 * @param {Object} metadata - Additional metadata about the problem
 * @returns {number} Concept ID
 */
function mapToConceptId(filePath, metadata = {}) {
  // For demonstration, we'll distribute across concepts
  // In practice, this would be based on problem classification
  const hash = crypto.createHash('md5').update(filePath).digest('hex');
  const conceptIndex = parseInt(hash.substring(0, 8), 16) % 7; // 7 concepts
  return conceptIndex + 1; // Concept IDs are 1-7
}

/**
 * Simulate downloading/filtering CodeNet dataset
 * In a real implementation, this would:
 * 1. Download/filter IBM Project CodeNet for C++ introductory problems
 * 2. Focus on 14M total → ~15k intro-level solutions
 * 3. Apply filtering criteria (correct solutions, reasonable size, etc.)
 * @returns {Array<Object>} Array of code samples with metadata
 */
async function getCodeNetSamples() {
  console.log('Simulating CodeNet dataset filtering...');

  // This is a placeholder - in reality, you'd download and filter the actual CodeNet dataset
  // For now, we'll create some sample code patterns for each concept

  const samples = [
    // Conditionals
    {
      code: `#include <iostream>\nusing namespace std;\n\nint main() {\n  int x = 10;\n  if (x > 5) {\n    cout << "x is greater than 5" << endl;\n  }\n  return 0;\n}`,
      metadata: { problem_id: 1, source: 'CodeNet', quality: 90, difficulty: 'Easy' }
    },
    {
      code: `#include <iostream>\nusing namespace std;\n\nint main() {\n  int score;\n  cin >> score;\n  if (score >= 90) {\n    cout << "Grade: A" << endl;\n  } else if (score >= 80) {\n    cout << "Grade: B" << endl;\n  } else {\n    cout << "Grade: C" << endl;\n  }\n  return 0;\n}`,
      metadata: { problem_id: 2, source: 'CodeNet', quality: 85, difficulty: 'Medium' }
    },

    // Loops
    {
      code: `#include <iostream>\nusing namespace std;\n\nint main() {\n  int sum = 0;\n  for (int i = 1; i <= 100; i++) {\n    sum += i;\n  }\n  cout << "Sum: " << sum << endl;\n  return 0;\n}`,
      metadata: { problem_id: 3, source: 'CodeNet', quality: 95, difficulty: 'Easy' }
    },
    {
      code: `#include <iostream>\nusing namespace std;\n\nint main() {\n  int n = 50;\n  while (n > 0) {\n    cout << n << " ";\n    n--;\n  }\n  cout << endl;\n  return 0;\n}`,
      metadata: { problem_id: 4, source: 'CodeNet', quality: 88, difficulty: 'Medium' }
    },

    // Functions
    {
      code: `#include <iostream>\nusing namespace std;\n\nint add(int a, int b) {\n  return a + b;\n}\n\nint main() {\n  int result = add(5, 3);\n  cout << "5 + 3 = " << result << endl;\n  return 0;\n}`,
      metadata: { problem_id: 5, source: 'CodeNet', quality: 92, difficulty: 'Easy' }
    },
    {
      code: `#include <iostream>\nusing namespace std;\n\nint factorial(int n) {\n  if (n <= 1) return 1;\n  return n * factorial(n - 1);\n}\n\nint main() {\n  cout << "Factorial of 5: " << factorial(5) << endl;\n  return 0;\n}`,
      metadata: { problem_id: 6, source: 'CodeNet', quality: 95, difficulty: 'Medium' }
    },

    // Arrays
    {
      code: `#include <iostream>\nusing namespace std;\n\nint main() {\n  int numbers[5] = {1, 2, 3, 4, 5};\n  for (int i = 0; i < 5; i++) {\n    cout << numbers[i] << " ";\n  }\n  cout << endl;\n  return 0;\n}`,
      metadata: { problem_id: 7, source: 'CodeNet', quality: 90, difficulty: 'Easy' }
    },
    {
      code: `#include <iostream>\nusing namespace std;\n\nint main() {\n  int matrix[3][3];\n  // Initialize matrix\n  for (int i = 0; i < 3; i++) {\n    for (int j = 0; j < 3; j++) {\n      matrix[i][j] = i + j;\n    }\n  }\n  // Print matrix\n  for (int i = 0; i < 3; i++) {\n    for (int j = 0; j < 3; j++) {\n      cout << matrix[i][j] << " ";\n    }\n    cout << endl;\n  }\n  return 0;\n}`,
      metadata: { problem_id: 8, source: 'CodeNet', quality: 87, difficulty: 'Hard' }
    }
  ];

  console.log(`Generated ${samples.length} CodeNet samples for processing`);
  return samples;
}

/**
 * Process a single code sample and insert into ast_templates table
 * @param {Object} sample - Code sample with code and metadata
 */
async function processCodeSample(sample) {
  try {
    const { code, metadata } = sample;

    // Extract information
    const nodeTypes = extractNodeTypes(code);
    const canonicalString = createCanonicalString(code);
    const astHash = generateASTHash(canonicalString);
    const conceptId = mapToConceptId(`problem_${metadata.problem_id}`, metadata);

    // Check if this hash already exists (avoid duplicates)
    const existingCheck = await db.query(
      'SELECT id FROM ast_templates WHERE ast_hash = $1',
      [astHash]
    );

    if (existingCheck.rows.length > 0) {
      console.log(`Template with hash ${astHash.substring(0,8)}... already exists, skipping`);
      return;
    }

    // Insert into ast_templates table
    await db.query(`
      INSERT INTO ast_templates (
        problem_id, ast_hash, node_types, canonical_string,
        concept_id, source, solution_quality_score, difficulty_level,
        correct_solution, codenet_snapshot_date
      ) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10)
    `, [
      metadata.problem_id,
      astHash,
      nodeTypes,
      canonicalString,
      conceptId,
      metadata.source || 'CodeNet',
      metadata.quality || 80,
      metadata.difficulty || 'Medium',
      code,
      new Date().toISOString().split('T')[0] // YYYY-MM-DD format
    ]);

    console.log(`✓ Inserted template for problem ${metadata.problem_id} (hash: ${astHash.substring(0,8)}...)`);

  } catch (error) {
    console.error(`✗ Error processing sample ${sample.metadata?.problem_id || 'unknown'} `, error.message);
  }
}

// Main ingestion function
async function main() {
  let client;
  try {
    console.log('Starting CodeNet pattern ingestion process...');

    // Get client for transaction
    client = await db.connect();

    // Get CodeNet samples (filtered dataset)
    const samples = await getCodeNetSamples();

    // Process each sample
    for (const sample of samples) {
      await processCodeSample(sample);
    }

    // Release client
    client.release();

    // Show summary
    const countResult = await db.query('SELECT COUNT(*) as total FROM ast_templates');
    console.log(`\n✓ Ingestion complete! Total templates in database: ${countResult.rows[0].total}`);

  } catch (error) {
    if (client) client.release();
    console.error('✗ CodeNet ingestion failed:', error.message);
    throw error;
  }
}

// Run if executed directly
if (require.main === module) {
  main()
    .then(() => process.exit(0))
    .catch(err => {
      console.error('Ingestion script failed:', err.message);
      process.exit(1);
    });
}

module.exports = { ingestCodeNet: main };