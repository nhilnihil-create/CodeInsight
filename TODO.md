# CDS Safety Measures, Baselines And Deep AST verification layer - TODO

## Blank Submission Detection
- [ ] Compare submission against template for blank detection
- [ ] Track if student modified code beyond template
- [ ] Implement character count increase check from template
- [ ] Detect template-only submissions with no modifications

## Implement CDS Baselines
- [ ] Add min_requests_threshold and target_completion_time columns to the assignments table.
- [ ] Update the cds_calculator.js to use Math.max(classMax, baseline) for all denominators.
- [ ] Prevent "Division by Zero" errors when Class Max Failed is 0 by defaulting to 1.
- [ ] Verification Layer Sync
- [ ] Ensure the Verification Layer (the AST check) flags the submission as "Valid" before the CDS even looks at the time or request count.
- [ ] If the AST check fails, do not increment the NRS (Maria shouldn't be penalized for structural mistakes, only logic errors).
- [ ] Edge Case Handling
- [ ] Add a "Warm-up" phase: Label scores as "Preliminary" until at least 5 students have submitted to ensure class-relative data is stable.

## Edge Case Handling
- [ ] Handle NTS maxed but no successful submission edge case
- [ ] Flag high NTS with zero success rate as High difficulty
- [ ] Update blank submission detection in cdsEngine.js

## Implement Hidden test cases(In exercises)
- [ ] makes sure that the student code is not hardcoded

## Code Strucure Checking(Verification Layer before CDS)
- [ ] Core AST Infrastructure
- [ ] Initialize tree-sitter with the tree-sitter-cpp grammar in the backend.
- [ ] Build a "Traversal Utility" to walk the tree without hitting recursion limits.
- [ ] Implement a "Canonizer" to strip identifiers (variable names) and literals for pure structural comparison.
- [ ] Structural Template Dataset (Netcode)
- [ ] Collection: Curate 5–10 diverse structural "templates" for each of the 6 fundamentals (Ideal, Creative, and Forbidden).
- [ ] Ingestion Script: Create a standalone Node.js script to parse these templates into AST "skeletons."
- [ ] Hashing: Generate SHA-256 hashes of these skeletons for O(1) database lookup speed.
- [ ] Versioning: Ensure the dataset is stored outside the main Git repo (using .gitignore) but has a schema version in PostgreSQL.
- [ ] Fundamental Node Mapping
- [ ] Map Variables to declaration and init_declarator nodes.
- [ ] Map Conditionals to if_statement and switch_statement nodes.
- [ ] Map Loops to for_statement, while_statement, and do_statement.
- [ ] Map Arrays to array_declarator and subscript_expression.
- [ ] Map Functions to function_definition and parameter_list.
- [ ] Map Basic I/O to operator_archive (for << and >>) or call_expression (for printf).
- [ ] Validation & Constraint Logic
- [ ] Presence Check: Ensure the required node exists in the translation_unit
- [ ] Negative Constraints: Block "forbidden" nodes (e.g., block goto or global_variables).
- [ ] Complexity Check: Ensure the required node isn't empty (e.g., a while(true); with no body).
- [ ] Nesting Validation: Verify if the assignment requires nested structures (e.g., a loop inside an if).
- [ ] Database & Schema Integration
- [ ] Update the assignments table to include a required_node and min_node_count column.
- [ ] Create a verification_logs table to store why a student's code failed the structural check.
- [ ] Link the Verification Layer output to the CDS trigger (CDS only runs if is_verified = true).
- [ ] Feedback & Error Reporting
- [ ] Map AST errors to human-readable hints (e.g., "Logic is correct, but please use a While Loop as requested").
- [ ] Capture the line/column of the "wrong" structure to highlight it in the frontend editor.
- [ ] Git & Deployment Workflow
- [ ] Create a feature branch: git checkout -b feat/ast-verification.
- [ ] Secure the Netcode Dataset on your local WSL environment (back up to a private cloud/drive).
- [ ] Push the verified logic (the "engine") to GitHub.



## Implementation Notes
- Current issue: Default template `#include <iostream>` is always present, so `code=''` check never triggers
- Solution: Compare against `starter_code`, not empty string
- Edge case: Student maxes time limit (NTS=1.0) but never succeeds → Currently shows 25% "Low" difficulty
- Safety fix: If NTS ≥ 0.9 AND zero success rate → Force classification to "High"
