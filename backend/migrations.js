// Database migrations/setup — verify tables and apply idempotent schema patches
const path = require('path');
require('dotenv').config({ path: path.join(__dirname, '.env') });
const fs = require('fs');
const db = require('./config/db');

async function columnExists(table, column) {
  const result = await db.query(
    `SELECT 1 FROM information_schema.columns
     WHERE table_name = $1 AND column_name = $2`,
    [table, column]
  );
  return result.rows.length > 0;
}

async function constraintExists(table, constraint) {
  const result = await db.query(
    `SELECT 1 FROM information_schema.table_constraints
     WHERE table_name = $1 AND constraint_name = $2`,
    [table, constraint]
  );
  return result.rows.length > 0;
}

async function tableExists(table) {
  const result = await db.query(
    `SELECT EXISTS (
       SELECT 1 FROM information_schema.tables
       WHERE table_name = $1
     ) AS exists`,
    [table]
  );
  return result.rows[0].exists;
}

async function addColumnIfMissing(table, column, definition) {
  if (!(await columnExists(table, column))) {
    await db.query(`ALTER TABLE ${table} ADD COLUMN ${column} ${definition}`);
    console.log(`✓ Added ${table}.${column}`);
    return true;
  }
  return false;
}

/**
 * Idempotent patches for databases created before the latest schema.sql.
 */
async function applySchemaPatches() {
  const patches = [];

  if (await tableExists('exercises')) {
    patches.push(addColumnIfMissing('exercises', 'reference_solution', 'TEXT'));
    patches.push(addColumnIfMissing('exercises', 'starter_code', `TEXT DEFAULT E'#include <iostream>\\nusing namespace std;\\n\\nint main() {\\n  return 0;\\n}'`));
    // Per-exercise required AST node types used by structure verification.
    // Declared in schema.sql; patch keeps pre-existing databases in sync.
    patches.push(addColumnIfMissing('exercises', 'ast_nodes', `TEXT[] DEFAULT '{}'`));
    // Per-exercise required patterns (tree-sitter queries + JS-handler kinds)
    // used by structure verification. Declared in schema.sql.
    patches.push(addColumnIfMissing('exercises', 'required_patterns', `JSONB DEFAULT '[]'`));
  }

  // Backfill: known catalog exercises that require a specific construct or
  // pattern. Guarded by empty ast_nodes/required_patterns so instructor-
  // customized values are never overwritten. Matches the declarations in
  // scripts/seedMasterTaxonomy.js.
  if (await tableExists('exercises') && await columnExists('exercises', 'ast_nodes') && await columnExists('exercises', 'required_patterns')) {
    try {
      // ── Shared required-pattern definitions (JSON-mirror of astVerifier) ──
      const P_IO_OUTPUT = { query: '[(binary_expression operator: "<<") (call_expression)]', label: 'stream output (cout <<) or printf', hint: 'your solution must print using cout << or printf' };
      const P_LOOP = { query: '[(for_statement) (while_statement) (do_statement)]', label: 'a loop', hint: 'your solution must use a loop' };
      const P_CONDITIONAL = { query: '[(if_statement) (switch_statement)]', label: 'an if or switch statement', hint: 'your solution must branch with if or switch — ternary-only solutions are rejected' };
      const P_ARRAY_USAGE = { query: '[(array_declarator) (subscript_expression)]', label: 'an array', hint: 'your solution must store the values in an array' };
      const P_STRING_TYPE = { kind: 'string_type', label: 'a std::string variable', hint: 'declare your strings with the string type (e.g. string name;)' };
      const P_SELF_CALL = { kind: 'self_call', label: 'a recursive call', hint: 'your solution must call a function from within itself' };
      const P_NO_LOOPS = { kind: 'forbidden', node: ['for_statement', 'while_statement', 'do_statement'], label: 'loops', hint: 'recursion exercises must not use loops — call the function from within itself' };
      const P_USER_FUNCTION = { kind: 'user_function', label: 'a function other than main', hint: 'your solution must define and use a function other than main' };
      const P_MIN_LOOPS2 = { kind: 'min_count', node: ['for_statement', 'while_statement', 'do_statement'], min: 2, label: 'at least two loops', hint: 'your solution must use nested loops (a loop inside a loop)' };

      // 30-row catalog table — rows 6/7/12 (Variables concepts) carry no gate.
      const EXERCISE_REQUIREMENTS = [
        { title: 'Print Hello World', required_patterns: [P_IO_OUTPUT] },
        { title: 'Print Test Cases', required_patterns: [P_IO_OUTPUT, P_LOOP] },
        { title: 'Formal Name Formatter', required_patterns: [P_STRING_TYPE] },
        { title: 'Simple Calculator', required_patterns: [P_CONDITIONAL] },
        { title: 'Print Many Numbers', ast_nodes: ['for_statement'] },
        { title: 'Print a Rectangle', required_patterns: [P_MIN_LOOPS2] },
        { title: 'Find Missing Number', required_patterns: [P_ARRAY_USAGE] },
        { title: 'Print a Frame', required_patterns: [P_MIN_LOOPS2] },
        { title: 'Even and Odd Numbers', required_patterns: [P_CONDITIONAL] },
        { title: 'Largest Number in a Sequence', required_patterns: [P_ARRAY_USAGE] },
        { title: 'Multiplication Table', required_patterns: [P_MIN_LOOPS2] },
        { title: 'Dice Game', required_patterns: [P_CONDITIONAL] },
        { title: 'Fibonacci Sequence', required_patterns: [P_SELF_CALL, P_NO_LOOPS] },
        { title: 'Factorial Function', required_patterns: [P_USER_FUNCTION] },
        { title: 'Prime Number Check', required_patterns: [P_CONDITIONAL] },
        { title: 'Grade Classification', ast_nodes: ['switch_statement'] },
        { title: 'Array Sorting (Bubble Sort)', required_patterns: [P_ARRAY_USAGE] },
        { title: 'String Reversal', required_patterns: [P_STRING_TYPE] },
        { title: 'Count Characters in a String', required_patterns: [P_STRING_TYPE] },
        { title: 'Compute Power', required_patterns: [P_USER_FUNCTION] },
        { title: 'Maximum and Minimum', required_patterns: [P_ARRAY_USAGE] },
        { title: 'Palindrome Check', required_patterns: [P_STRING_TYPE] },
        { title: 'GCD and LCM', required_patterns: [P_USER_FUNCTION] },
        { title: 'Convert Base', required_patterns: [P_LOOP] },
        { title: 'Matrix Addition', required_patterns: [P_ARRAY_USAGE, P_MIN_LOOPS2] },
        { title: 'Count Frequency', required_patterns: [P_ARRAY_USAGE] },
        { title: 'Simple Struct: Point Distance', ast_nodes: ['struct_specifier'] },
      ];

      let backfillCount = 0;
      for (const req of EXERCISE_REQUIREMENTS) {
        const res = await db.query(
          `UPDATE exercises SET ast_nodes = $2::text[], required_patterns = $3::jsonb
           WHERE title = $1
             AND (ast_nodes IS NULL OR ast_nodes = '{}')
             AND (required_patterns IS NULL OR required_patterns = '[]'::jsonb)`,
          [req.title, req.ast_nodes || null, req.required_patterns ? JSON.stringify(req.required_patterns) : null]
        );
        backfillCount += res.rowCount;
      }
      if (backfillCount > 0) {
        console.log(`✓ Backfilled ast_nodes/required_patterns for ${backfillCount} exercise row(s)`);
      }

      // Fix broken concept-level gates. Guarded by the OLD ast_nodes value so
      // an instructor's own customized list is never overwritten.
      const CONCEPT_NODE_FIXES = [
        { name: 'Scope', old: ['block'], new: [] },
        { name: 'Input/Output', old: ['call_expression'], new: [] },
        { name: 'Strings', old: ['string_literal'], new: [] },
        { name: 'Dynamic Memory', old: ['call_expression'], new: ['new_expression', 'call_expression'] },
        { name: 'Structs', old: ['struct_declaration'], new: ['struct_specifier'] },
      ];
      for (const fix of CONCEPT_NODE_FIXES) {
        const res = await db.query(
          'UPDATE concepts SET ast_nodes = $3::text[] WHERE name = $1 AND ast_nodes = $2::text[]',
          [fix.name, fix.old, fix.new]
        );
        if (res.rowCount > 0) {
          console.log(`✓ Fixed concept ast_nodes for '${fix.name}' (${res.rowCount} row(s))`);
        }
      }
    } catch (err) {
      console.warn('⚠ Could not backfill exercise requirements:', err.message);
    }
  }

  // One-time deactivation of over-broad bad patterns: `missing_include_iostream`
  // matched EVERY expression_statement (rejecting every Input/Output solution)
  // and `redundant_recursion` matched EVERY function body (rejecting every
  // Recursion solution). Guarded by the old query text so an instructor's own
  // customized version is never touched.
  if (await tableExists('verification_rules')) {
    try {
      const deactivated = await db.query(
        `UPDATE verification_rules SET is_active = false, updated_at = CURRENT_TIMESTAMP
         WHERE rule_type = 'bad_pattern' AND is_active = true AND (
           (pattern_id = 'missing_include_iostream' AND tree_sitter_query = '(expression_statement)')
           OR
           (pattern_id = 'redundant_recursion' AND tree_sitter_query = '(function_definition body: (compound_statement) @body)')
         )`
      );
      if (deactivated.rowCount > 0) {
        console.log(`✓ Deactivated over-broad bad patterns (${deactivated.rowCount} row(s))`);
      }
    } catch (err) {
      console.warn('⚠ Could not deactivate over-broad bad patterns:', err.message);
    }
  }

  // One-time deactivation of over-broad bad patterns (v2): these 38 patterns
  // matched VALID code and hard-rejected every submission in their concept
  // (e.g. `same_loop_variable`'s sibling `wrong_loop_order`, `empty_if_body`,
  // `void_return_value`, ...). They were removed from badPatterns.js; prod rows
  // are deactivated here so existing databases get the same fix. Guarded and
  // idempotent — never crashes startup.
  if (await tableExists('verification_rules')) {
    try {
      const REMOVED_BAD_PATTERN_IDS = [
        'narrowing_conversion',
        'cin_without_check',
        'string_compare_eq',
        'missing_string_include',
        'empty_if_body',
        'wrong_loop_order',
        'undeclared_array',
        'out_of_bounds_literal',
        'void_return_value',
        'no_base_case',
        'missing_break',
        'missing_default',
        'large_struct_by_value',
        'uninitialized_struct_field',
        'missing_delete',
        'double_delete',
        'no_file_open_check',
        'missing_fstream_include',
        'declaration_in_loop',
        'missing_braces',
        'dereference_null',
        'pointer_arithmetic_literal',
        'plain_enum',
        'enum_value_reuse',
        'no_null_check_traversal',
        'lost_node_reference',
        'empty_catch',
        'catch_by_value',
        'c_style_cast',
        'precision_loss_cast',
        'macro_no_parens',
        'missing_include_guard',
        'using_namespace_header',
        'missing_std_prefix',
        'non_virtual_destructor',
        'missing_override',
        'object_slicing',
        'non_virtual_call',
      ];
      const removed = await db.query(
        `UPDATE verification_rules SET is_active = false, updated_at = CURRENT_TIMESTAMP
         WHERE pattern_id = ANY($1::text[]) AND rule_type = 'bad_pattern' AND is_active = true`,
        [REMOVED_BAD_PATTERN_IDS]
      );
      if (removed.rowCount > 0) {
        console.log(`✓ Deactivated over-broad bad patterns v2 (${removed.rowCount} row(s))`);
      }
    } catch (err) {
      console.warn('⚠ Could not deactivate over-broad bad patterns v2:', err.message);
    }

    // Make the prod `same_loop_variable` rule precise: previously it matched
    // EVERY classic for-loop (query had no handler) and rejected valid nested
    // loops with distinct variable names. Point the prod row at the
    // checkSameLoopVariable handler and keep the current query. Idempotent.
    try {
      const fixed = await db.query(
        `UPDATE verification_rules
         SET tree_sitter_query = '(for_statement (declaration (init_declarator (identifier) @outer)))',
             handler = 'checkSameLoopVariable',
             updated_at = CURRENT_TIMESTAMP
         WHERE pattern_id = 'same_loop_variable' AND rule_type = 'bad_pattern'`
      );
      if (fixed.rowCount > 0) {
        console.log(`✓ Attached checkSameLoopVariable handler to same_loop_variable (${fixed.rowCount} row(s))`);
      }
    } catch (err) {
      console.warn('⚠ Could not fix same_loop_variable rule:', err.message);
    }
  }

  if (await tableExists('sections')) {
    patches.push(addColumnIfMissing('sections', 'code', 'TEXT'));
    patches.push(addColumnIfMissing('sections', 'term', 'TEXT'));
    patches.push(addColumnIfMissing('sections', 'semester', 'TEXT'));
    patches.push(addColumnIfMissing('sections', 'join_policy', `TEXT NOT NULL DEFAULT 'code' CHECK (join_policy IN ('code', 'request', 'closed'))`));
    patches.push(addColumnIfMissing('sections', 'max_size', 'INTEGER NOT NULL DEFAULT 60'));
    
    // Add NOT NULL constraint to sections.code (if not already present)
    if (await columnExists('sections', 'code')) {
      try {
        // Ensure no NULL codes exist before adding NOT NULL constraint
        await db.query(`UPDATE sections SET code = course_code || '-' || id WHERE code IS NULL`);
        await db.query(`ALTER TABLE sections ALTER COLUMN code SET NOT NULL`);
        console.log('✓ Added NOT NULL constraint to sections.code');
      } catch (err) {
        console.log('✓ sections.code NOT NULL constraint already exists');
      }
    }
    
    // Add UNIQUE constraint to sections.code (if not already present)
    if (await columnExists('sections', 'code')) {
      try {
        await db.query(`ALTER TABLE sections ADD CONSTRAINT sections_code_key UNIQUE (code)`);
        console.log('✓ Added UNIQUE constraint to sections.code');
      } catch (err) {
        console.log('✓ sections.code UNIQUE constraint already exists');
      }
    }
  }

  if (await tableExists('submissions')) {
    // Keep databases created before the latest schema.sql in sync with it.
    patches.push(addColumnIfMissing('submissions', 'test_results', `JSONB DEFAULT '[]'`));
    patches.push(addColumnIfMissing('submissions', 'created_at', 'TIMESTAMP DEFAULT NOW()'));
    patches.push(addColumnIfMissing('submissions', 'code_growth_delta', 'INTEGER DEFAULT 0'));
    patches.push(addColumnIfMissing('submissions', 'is_verified', 'BOOLEAN DEFAULT false'));
    patches.push(addColumnIfMissing('submissions', 'verification_note', 'TEXT'));
    patches.push(addColumnIfMissing('submissions', 'compiler_log', 'TEXT'));
    patches.push(addColumnIfMissing('submissions', 'time_limit_hit', 'BOOLEAN DEFAULT false'));
  }

  // Soft-drop enrollment support: students can leave a section without the
  // instructor's roster history being destroyed. `dropped_at IS NULL` means
  // an active enrollment; non-NULL means the student left the section.
  if (await tableExists('enrollments')) {
    patches.push(addColumnIfMissing('enrollments', 'dropped_at', 'TIMESTAMP NULL'));
  }

  // Fail-closed: is_verified must default to false so submissions that were
  // never run through the AST verifier are never treated as verified.
  // Idempotent — only alters when the current default differs.
  if (await tableExists('submissions') && await columnExists('submissions', 'is_verified')) {
    try {
      const defaultRes = await db.query(
        `SELECT column_default FROM information_schema.columns
         WHERE table_name = 'submissions' AND column_name = 'is_verified'`
      );
      if (defaultRes.rows[0]?.column_default !== 'false') {
        await db.query(`ALTER TABLE submissions ALTER COLUMN is_verified SET DEFAULT false`);
        console.log('✓ Set submissions.is_verified DEFAULT false');
      }
    } catch (err) {
      console.warn('⚠ Could not set submissions.is_verified DEFAULT false:', err.message);
    }
  }

  // One-time fix for the over-broad off_by_one bad pattern: the original
  // query matched ANY <= loop bound and rejected correct "1..n" loops
  // (e.g. for (int i = 1; i <= n; i++)). Guarded by the old query text so an
  // instructor's own customized version is never overwritten.
  if (await tableExists('verification_rules')) {
    try {
      const oldOffByOneQuery = '(for_statement (binary_expression operator: "<=") @cond)';
      const fixedOffByOneQuery = '(binary_expression operator: "<=" (number_literal) @bound)';
      const fixRes = await db.query(
        `UPDATE verification_rules SET tree_sitter_query = $1, updated_at = CURRENT_TIMESTAMP
         WHERE pattern_id = 'off_by_one' AND rule_type = 'bad_pattern' AND tree_sitter_query = $2`,
        [fixedOffByOneQuery, oldOffByOneQuery]
      );
      if (fixRes.rowCount > 0) {
        console.log('✓ Fixed over-broad off_by_one verification rule (literal-bound only)');
      }
    } catch (err) {
      console.warn('⚠ Could not fix off_by_one verification rule:', err.message);
    }
  }

  if (!(await tableExists('run_attempts'))) {
    await db.query(`
      CREATE TABLE run_attempts (
        id              SERIAL PRIMARY KEY,
        student_id      INT REFERENCES users(id) ON DELETE CASCADE,
        exercise_id     INT REFERENCES exercises(id) ON DELETE CASCADE,
        code            TEXT NOT NULL,
        compiler_log    TEXT,
        error_count     INT DEFAULT 0,
        time_limit_hit  BOOLEAN DEFAULT false,
        run_at              TIMESTAMP DEFAULT NOW(),
        tab_switch_count    INT NOT NULL DEFAULT 0,
        paste_count         INT NOT NULL DEFAULT 0,
        time_spent_seconds  INT NOT NULL DEFAULT 0,
        line_count          INT NOT NULL DEFAULT 0,
        code_growth_delta   INT NOT NULL DEFAULT 0
      )
    `);
    await db.query(`CREATE INDEX IF NOT EXISTS idx_run_attempts_student_exercise ON run_attempts(student_id, exercise_id)`);
    console.log('✓ Created run_attempts table');
  }

  // ── Run-checkpoint snapshot columns (per-run behavioral + growth data) ──
  if (await tableExists('run_attempts')) {
    patches.push(addColumnIfMissing('run_attempts', 'tab_switch_count', 'INT NOT NULL DEFAULT 0'));
    patches.push(addColumnIfMissing('run_attempts', 'paste_count', 'INT NOT NULL DEFAULT 0'));
    patches.push(addColumnIfMissing('run_attempts', 'time_spent_seconds', 'INT NOT NULL DEFAULT 0'));
    patches.push(addColumnIfMissing('run_attempts', 'line_count', 'INT NOT NULL DEFAULT 0'));
    patches.push(addColumnIfMissing('run_attempts', 'code_growth_delta', 'INT NOT NULL DEFAULT 0'));
  }

  if (await tableExists('cds_scores')) {
    patches.push(addColumnIfMissing('cds_scores', 'has_flagged_attempts', 'BOOLEAN DEFAULT false'));
    patches.push(addColumnIfMissing('cds_scores', 'integrity_flag_count', 'INTEGER DEFAULT 0'));
    patches.push(addColumnIfMissing('cds_scores', 'source', `VARCHAR(20) DEFAULT 'batch'`));
    patches.push(addColumnIfMissing('cds_scores', 'visible', 'BOOLEAN DEFAULT true'));
  }

  if (await tableExists('users')) {
    // Bring CHECK constraint in line with migration 006 (adds 'admin').
    // Idempotent: drops the stale constraint, then adds the up-to-date one.
    // Skipped with a warning if the application role is not the table
    // owner (e.g. on legacy DBs where constraint was added out-of-band
    // by a superuser). Constraint is a strict superset of the original.
    try {
      await db.query(`ALTER TABLE users DROP CONSTRAINT IF EXISTS users_role_check`);
      await db.query(`
        ALTER TABLE users ADD CONSTRAINT users_role_check
        CHECK (role IN ('student','instructor','admin'))
      `);
      console.log('✓ Updated users.role CHECK to include admin');
    } catch (chkErr) {
      console.warn('⚠ Could not update users.role CHECK (likely a permissions issue). Run as superuser:');
      console.warn("  psql -U postgres -d codeinsight -c \"ALTER TABLE users DROP CONSTRAINT users_role_check; ALTER TABLE users ADD CONSTRAINT users_role_check CHECK (role IN ('student','instructor','admin'));\"");
    }
  }

  if (!(await tableExists('evaluation_responses'))) {
    // Migration 006 — ISO/IEC 25010 evaluation instrument (spec §14).
    // Additive only. Required by adminController.overview.
    try {
      await db.query(`
        CREATE TABLE evaluation_responses (
          id            UUID PRIMARY KEY DEFAULT gen_random_uuid(),
          respondent_id INTEGER REFERENCES users(id) ON DELETE SET NULL,
          role          TEXT NOT NULL CHECK (role IN ('student', 'instructor', 'admin')),
          fs_1 INTEGER NOT NULL CHECK (fs_1 BETWEEN 1 AND 4),
          fs_2 INTEGER NOT NULL CHECK (fs_2 BETWEEN 1 AND 4),
          fs_3 INTEGER NOT NULL CHECK (fs_3 BETWEEN 1 AND 4),
          fs_4 INTEGER NOT NULL CHECK (fs_4 BETWEEN 1 AND 4),
          us_1 INTEGER NOT NULL CHECK (us_1 BETWEEN 1 AND 4),
          us_2 INTEGER NOT NULL CHECK (us_2 BETWEEN 1 AND 4),
          us_3 INTEGER NOT NULL CHECK (us_3 BETWEEN 1 AND 4),
          us_4 INTEGER NOT NULL CHECK (us_4 BETWEEN 1 AND 4),
          us_5 INTEGER NOT NULL CHECK (us_5 BETWEEN 1 AND 4),
          pe_1 INTEGER NOT NULL CHECK (pe_1 BETWEEN 1 AND 4),
          pe_2 INTEGER NOT NULL CHECK (pe_2 BETWEEN 1 AND 4),
          pe_3 INTEGER NOT NULL CHECK (pe_3 BETWEEN 1 AND 4),
          feedback_text TEXT,
          created_at    TIMESTAMPTZ NOT NULL DEFAULT NOW()
        )
      `);
      await db.query(`CREATE INDEX IF NOT EXISTS idx_evaluation_responses_created_at ON evaluation_responses(created_at)`);
      await db.query(`CREATE INDEX IF NOT EXISTS idx_evaluation_responses_role ON evaluation_responses(role)`);
      console.log('✓ Created evaluation_responses table');
    } catch (evalErr) {
      console.warn('⚠ Could not create evaluation_responses (likely a permissions issue). Run as superuser:');
      console.warn("  psql -U postgres -d codeinsight -f backend/migrations/006-add-evaluation.sql");
    }
  }

  if (!(await tableExists('integrity_flags'))) {
    await db.query(`
      CREATE TABLE integrity_flags (
        id                  SERIAL PRIMARY KEY,
        section_id          INT NOT NULL REFERENCES sections(id) ON DELETE CASCADE,
        exercise_id         INT NOT NULL REFERENCES exercises(id) ON DELETE CASCADE,
        student_id          INT NOT NULL REFERENCES users(id) ON DELETE CASCADE,
        submission_id       INT REFERENCES submissions(id) ON DELETE SET NULL,
        run_id              INT REFERENCES run_attempts(id) ON DELETE SET NULL,
        flag_type           VARCHAR(50) NOT NULL,
        severity            VARCHAR(20) NOT NULL,
        evidence            JSONB DEFAULT '{}',
        context_behaviors   TEXT[] DEFAULT '{}',
        status              VARCHAR(20) DEFAULT 'flagged',
        instructor_note     TEXT,
        reviewed_at         TIMESTAMP,
        created_at          TIMESTAMP DEFAULT NOW(),
        UNIQUE(exercise_id, student_id, flag_type)
      )
    `);
    console.log('✓ Created integrity_flags table');
  }

  // ── Link flags to the run snapshot that produced them (run checkpoint) ──
  if (await tableExists('integrity_flags')) {
    patches.push(addColumnIfMissing('integrity_flags', 'run_id', 'INT REFERENCES run_attempts(id) ON DELETE SET NULL'));
  }

  // ── Code-growth rate detection: per-session token-count samples ───────
  // Sampled by the student editor every few seconds of active editing and
  // posted to POST /api/student/code-snapshots. Analyzed at submit time by
  // the rate-burst detector (services/codeGrowthRateDetector.js). Declared
  // in schema.sql; this keeps pre-existing databases in sync.
  if (!(await tableExists('code_snapshots'))) {
    await db.query(`
      CREATE TABLE code_snapshots (
        id            SERIAL PRIMARY KEY,
        student_id    INT NOT NULL REFERENCES users(id) ON DELETE CASCADE,
        exercise_id   INT NOT NULL REFERENCES exercises(id) ON DELETE CASCADE,
        session_id    TEXT NOT NULL,
        token_count   INT NOT NULL,
        active_elapsed_seconds INT NOT NULL,
        autocomplete  BOOLEAN NOT NULL DEFAULT FALSE,
        occurred_at   TIMESTAMPTZ NOT NULL DEFAULT NOW(),
        UNIQUE (session_id, active_elapsed_seconds)
      )
    `);
    await db.query(`CREATE INDEX IF NOT EXISTS idx_code_snapshots_session_lookup ON code_snapshots (student_id, exercise_id, session_id, active_elapsed_seconds)`);
    console.log('✓ Created code_snapshots table');
  }

  if (!(await tableExists('section_memberships'))) {
    await db.query(`
      CREATE TABLE section_memberships (
        id          UUID PRIMARY KEY DEFAULT gen_random_uuid(),
        section_id  INTEGER NOT NULL REFERENCES sections(id) ON DELETE CASCADE,
        user_id     INTEGER NOT NULL REFERENCES users(id) ON DELETE CASCADE,
        role        TEXT NOT NULL DEFAULT 'student' CHECK (role IN ('student', 'ta', 'co_instructor')),
        status      TEXT NOT NULL DEFAULT 'active' CHECK (status IN ('active', 'pending', 'denied', 'dropped', 'left_requested', 'left')),
        joined_at   TIMESTAMPTZ NOT NULL DEFAULT NOW(),
        dropped_at  TIMESTAMPTZ,
        drop_reason TEXT,
        UNIQUE(section_id, user_id)
      )
    `);
    await db.query(`CREATE INDEX IF NOT EXISTS idx_section_memberships_section ON section_memberships(section_id)`);
    await db.query(`CREATE INDEX IF NOT EXISTS idx_section_memberships_user ON section_memberships(user_id)`);
    await db.query(`CREATE INDEX IF NOT EXISTS idx_section_memberships_status ON section_memberships(status)`);
    console.log('✓ Created section_memberships table');
  }

  if (!(await tableExists('section_audit_log'))) {
    await db.query(`
      CREATE TABLE section_audit_log (
        id          UUID PRIMARY KEY DEFAULT gen_random_uuid(),
        section_id  INTEGER NOT NULL REFERENCES sections(id) ON DELETE CASCADE,
        actor_id    INTEGER REFERENCES users(id) ON DELETE SET NULL,
        action      TEXT NOT NULL,
        meta        JSONB NOT NULL DEFAULT '{}',
        created_at  TIMESTAMPTZ NOT NULL DEFAULT NOW()
      )
    `);
    await db.query(`CREATE INDEX IF NOT EXISTS idx_section_audit_log_section ON section_audit_log(section_id)`);
    await db.query(`CREATE INDEX IF NOT EXISTS idx_section_audit_log_created ON section_audit_log(created_at)`);
    console.log('✓ Created section_audit_log table');
  }

  // ── Migration 010: Taxonomy Refactor (ADRs 001-006) ─────────────────────
  // Run standalone: node migrations/010_taxonomy_refactor.js
  // Here we just check if it's been applied
  if (await tableExists('concepts') && !(await columnExists('concepts', 'knowledge_area_code'))) {
    console.log('⚠ Migration 010 (taxonomy refactor) not applied.');
    console.log('  Run: node backend/migrations/010_taxonomy_refactor.js');
  } else if (await tableExists('concepts')) {
    console.log('✓ Migration 010 (taxonomy refactor) applied');
  }

  // ── Backfill: ensure every exercise's primary concept has an
  //    exercise_concept_tags row (is_primary = true). Exercises created via
  //    bulkPublish (databank → section) historically skipped this junction,
  //    making them invisible to tag-based analytics (heatmap, concept CMI, …).
  if (await tableExists('exercise_concept_tags')) {
    const backfill = await db.query(`
      INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary)
      SELECT id, concept_id, 1.0, true FROM exercises WHERE concept_id IS NOT NULL
      ON CONFLICT (exercise_id, concept_id)
        DO UPDATE SET is_primary = true
        WHERE exercise_concept_tags.is_primary IS DISTINCT FROM true
    `);
    if (backfill.rowCount > 0) {
      console.log(`✓ Backfilled exercise_concept_tags (${backfill.rowCount} row(s) corrected)`);
    }
  }

  await Promise.all(patches);
}

/**
 * Run v2 migration SQL files idempotently.
 * Each file is wrapped in a transaction on our end; the files themselves use
 * IF NOT EXISTS / ADD COLUMN IF NOT EXISTS patterns for safety.
 */
async function applyV2Migrations() {
  const migrationsDir = path.join(__dirname, 'migrations');
  const v2Files = [
    '20260610_v2_concepts.sql',
    '20260610_v2_audit.sql',
    '20260610_validation_mode.sql',

  ];

  for (const file of v2Files) {
    const filePath = path.join(migrationsDir, file);
    if (!fs.existsSync(filePath)) {
      console.warn(`⚠ v2 migration file not found: ${file}`);
      continue;
    }
    const sql = fs.readFileSync(filePath, 'utf8');
    // Check if tables already exist to skip idempotently
    const baseName = file.replace('.sql', '');
    const markers = {
      '20260610_v2_concepts':        { table: 'exercise_concepts', label: 'exercise_concepts + FTS' },
      '20260610_v2_audit':           { table: 'audit_log',      label: 'audit_log + cds_snapshots' },
      '20260610_validation_mode':    { table: 'exercises',    col: 'is_validated', label: 'validation mode columns' },

    };
    const marker = markers[baseName];
    if (marker) {
      if (marker.col && await tableExists(marker.table) && await columnExists(marker.table, marker.col)) {
        console.log(`✓ ${marker.label} already applied`);
        continue;
      }
      if (!marker.col && await tableExists(marker.table)) {
        console.log(`✓ ${marker.label} already applied`);
        continue;
      }
    }
    try {
      await db.query(sql);
      console.log(`✓ Applied ${file}`);
    } catch (err) {
      // Ignore "already exists" errors for idempotency
      if (err.code === '42P07' || err.code === '42701') {
        console.log(`✓ ${marker?.label || file} already exists`);
      } else {
        console.warn(`⚠ v2 migration ${file} failed:`, err.message);
      }
    }
  }
}

async function ensureTablesExist() {
  try {
    console.log('Verifying database tables...');

    const tables = [
      'users', 'sections', 'enrollments', 'concepts', 'exercises', 'submissions',
      'cds_scores', 'alerts', 'verification_logs', 'performance_logs', 'auto_close_log',
      'integrity_flags'
    ];
    const results = [];

    for (const table of tables) {
      const exists = await tableExists(table);
      results.push({ table, exists });
      if (exists) {
        console.log(`✓ ${table} table exists`);
      } else {
        console.warn(`⚠ ${table} table not found`);
      }
    }

    try {
      await applySchemaPatches();
    } catch (patchErr) {
      console.warn('⚠ Schema patches skipped:', patchErr.message);
    }

    try {
      await applyV2Migrations();
    } catch (v2Err) {
      console.warn('⚠ v2 migrations failed:', v2Err.message);
    }

    // system_settings table (CDS thresholds, sandbox config)
    if (!(await tableExists('system_settings'))) {
      try {
        const { up } = require('./migrations/20260620_system_settings');
        await up(db);
        console.log('✓ system_settings table seeded');
      } catch (ssErr) {
        console.warn('⚠ system_settings migration failed:', ssErr.message);
      }
    }

    // verification_rules table (data-driven AST pattern matching)
    if (!(await tableExists('verification_rules'))) {
      try {
        const { createVerificationRules } = require('./migrations/20260617_verification_rules');
        await createVerificationRules(db);
        console.log('✓ verification_rules table seeded');
      } catch (vrErr) {
        console.warn('⚠ verification_rules migration failed:', vrErr.message);
      }
    }

    // Renumber duplicate submission attempt numbers (deterministic + idempotent).
    try {
      const { up } = require('./migrations/20260810_renumber_submission_attempts');
      await up(db);
      console.log('✓ submission attempt numbers renumbered');
    } catch (renErr) {
      console.warn('⚠ attempt renumber migration failed:', renErr.message);
    }

    // Remove unused learning outcome tables (sink nodes, never referenced)
    if (await tableExists('learning_outcomes')) {
      try {
        const { up } = require('./migrations/20260621_remove_outcome_tables');
        await up(db);
        console.log('✓ Removed unused learning_outcomes, outcome_concept_map, section_active_outcomes');
      } catch (roErr) {
        console.warn('⚠ outcome table removal failed:', roErr.message);
      }
    }

    // Auth security hardening (June 2026): email verification + JWT revocation
    if (await tableExists('users')) {
      try {
        await addColumnIfMissing('users', 'email_verified', 'BOOLEAN DEFAULT false');
        await addColumnIfMissing('users', 'verification_token', 'VARCHAR(255)');
        await addColumnIfMissing('users', 'verification_token_expires', 'TIMESTAMP');
      } catch (colErr) {
        console.warn('⚠ Could not add auth columns to users table:', colErr.message);
      }
    }

    if (!(await tableExists('token_blacklist'))) {
      await db.query(`
        CREATE TABLE token_blacklist (
          id         SERIAL PRIMARY KEY,
          jti        VARCHAR(255) NOT NULL UNIQUE,
          expires_at TIMESTAMP NOT NULL
        )
      `);
      await db.query(`CREATE INDEX idx_token_blacklist_jti ON token_blacklist(jti)`);
      await db.query(`CREATE INDEX idx_token_blacklist_expires ON token_blacklist(expires_at)`);
      console.log('✓ Created token_blacklist table');
    }

    if (!(await tableExists('otp_codes'))) {
      await db.query(`
        CREATE TABLE otp_codes (
          email     VARCHAR(255) PRIMARY KEY,
          otp       VARCHAR(6) NOT NULL,
          expires_at TIMESTAMP NOT NULL,
          attempts  INTEGER DEFAULT 0,
          created_at TIMESTAMP DEFAULT NOW()
        )
      `);
      console.log('✓ Created otp_codes table');
    }

    const criticalTables = ['users', 'sections', 'enrollments', 'concepts', 'exercises', 'submissions'];
    const allCriticalExist = criticalTables.every(table =>
      results.find(r => r.table === table)?.exists === true
    );

    if (!allCriticalExist) {
      console.warn('Some critical tables are missing — run: psql -d codeinsight -f backend/schema.sql');
    }

    return allCriticalExist;
  } catch (err) {
    console.error('Database check error:', err.message);
    return false;
  }
}

module.exports = { ensureTablesExist, applySchemaPatches, columnExists, tableExists };

if (require.main === module) {
  ensureTablesExist()
    .then((ok) => process.exit(ok ? 0 : 1))
    .catch((err) => {
      console.error(err);
      process.exit(1);
    });
}
