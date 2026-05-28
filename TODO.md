## CodeInsight TODO — prioritized checklist (snapshot: 2026-05-27)

Summary
- This file captures prioritized fixes and next steps based on the current codebase analysis (backend + frontend). See the detailed notes and links to implementation locations below.

Critical / High Priority
- ✅ **Starter code column:** Add `starter_code` column to the `exercises` table (backend/schema). Frontend expects [frontend/src/pages/student/CodeEditor.jsx](frontend/src/pages/student/CodeEditor.jsx) to read this field. See backend schema in [backend/schema.sql](backend/schema.sql).
- ✅ **Blank submission detection:** Replace `code==''` checks with comparison to `starter_code` in [backend/services/cdsEngine.js](backend/services/cdsEngine.js) and submission handlers in [backend/controllers/submissionController.js](backend/controllers/submissionController.js).
- ✅ **Hidden test enforcement:** Separate visible vs hidden test execution in [backend/services/executor.js](backend/services/executor.js) and ensure the API only returns visible test outputs to students while hidden tests still affect `allPassed`.
- ✅ **NTS edge case:** If `NTS >= 0.9` and `successCount == 0`, force CDS classification to `High` in [backend/services/cdsEngine.js](backend/services/cdsEngine.js).
- ✅ **Hidden test case UI:** Add checkbox to instructor exercise creation form to mark test cases as hidden from students (while still affecting score) in [frontend/src/pages/instructor/CreateExercise.jsx](frontend/src/pages/instructor/CreateExercise.jsx).

Medium Priority
- ✅ **Post-solution cutoff:** For NRS/NER calculations, only count submissions up to the student's first Accepted attempt. Update logic in [backend/services/cdsEngine.js](backend/services/cdsEngine.js).
- ✅ **Outlier capping:** Cap class maxima at `mean + 2*stddev` to prevent extreme retryers from skewing class-relative scores (cds engine batch computation).
- ✅ **Minimum class size warning:** Mark CDS as `Preliminary` when fewer than 3–5 distinct students submitted (configurable baseline).

Frontend Improvements
- ✅ **Active time tracking (Page Visibility):** Use Page Visibility API in [frontend/src/pages/student/CodeEditor.jsx](frontend/src/pages/student/CodeEditor.jsx) to send `activeTimeSeconds` instead of raw elapsed time.

Verification Layer (AST) — Planned
- **Skeleton and scope:** Add `backend/services/astVerifier.js` (tree-sitter-cpp). Start with a minimal API: `verify(code, exerciseRequirements) -> {is_verified, reasons[]}`.
- **Persistence & logs:** Add `verification_logs` table and `is_verified`, `verification_note` columns to `submissions` (migration script). Link verification to CDS flow: if `is_verified === false` then CDS should either be marked Unscored or treat NRS differently (TBD).

Tests & Safety
- ✅ Add unit tests for CDS edge cases and hidden test separation (preferably under `backend/test`).
- ✅ Add migration scripts and a small rollout plan for adding `starter_code` to existing exercises (default to standard template where missing).

Next Actions
- No immediate actions required - all prioritized items have been completed.

References (quick links)
- `backend/services/cdsEngine.js` — CDS computation and current edge-case logic
- `backend/controllers/submissionController.js` — run/submit endpoints
- `backend/services/executor.js` — compile & run harness
- `frontend/src/pages/student/CodeEditor.jsx` — editor + time tracking

If you want, I can: run the migration and implement the cdsEngine fixes now, or open PR branches for each major item above. What should I do next?

## Archived Details (original detailed notes)

The following is the original, more granular list of edge cases, implementation notes, and verification-layer steps preserved from the earlier TODO. I appended it here so no detail was lost.

# CDS Safety Measures, Baselines And Deep AST verification layer - TODO

## Blank Submission Detection
- Compare submission against template for blank detection
- Track if student modified code beyond template
- Implement character count increase check from template
- Detect template-only submissions with no modifications

## Implement CDS Baselines
- Add min_requests_threshold and target_completion_time columns to the assignments table.
- Update the cds_calculator.js to use Math.max(classMax, baseline) for all denominators.
- Prevent "Division by Zero" errors when Class Max Failed is 0 by defaulting to 1.
- Verification Layer Sync
- Ensure the Verification Layer (the AST check) flags the submission as "Valid" before the CDS even looks at the time or request count.
- If the AST check fails, do not increment the NRS (Maria shouldn't be penalized for structural mistakes, only logic errors).
- Edge Case Handling
- Add a "Warm-up" phase: Label scores as "Preliminary" until at least 5 students have submitted to ensure class-relative data is stable.

## Edge Case Handling
- Handle NTS maxed but no successful submission edge case
- Flag high NTS with zero success rate as High difficulty
- Update blank submission detection in cdsEngine.js

## Implement Hidden test cases(In exercises)
- makes sure that the student code is not hardcoded

## Code Strucure Checking(Verification Layer before CDS)
- Core AST Infrastructure
- Initialize tree-sitter with the tree-sitter-cpp grammar in the backend.
- Build a "Traversal Utility" to walk the tree without hitting recursion limits.
- Implement a "Canonizer" to strip identifiers (variable names) and literals for pure structural comparison.
- Structural Template Dataset (Netcode)
- Collection: Curate 5–10 diverse structural "templates" for each of the 6 fundamentals (Ideal, Creative, and Forbidden).
- Ingestion Script: Create a standalone Node.js script to parse these templates into AST "skeletons."
- Hashing: Generate SHA-256 hashes of these skeletons for O(1) database lookup speed.
- Versioning: Ensure the dataset is stored outside the main Git repo (using .gitignore) but has a schema version in PostgreSQL.
- Fundamental Node Mapping
- Map Variables to declaration and init_declarator nodes.
- Map Conditionals to if_statement and switch_statement nodes.
- Map Loops to for_statement, while_statement, and do_statement.
- Map Arrays to array_declarator and subscript_expression.
- Map Functions to function_definition and parameter_list.
- Map Basic I/O to operator_archive (for << and >>) or call_expression (for printf).
- Validation & Constraint Logic
- Presence Check: Ensure the required node exists in the translation_unit
- Negative Constraints: Block "forbidden" nodes (e.g., block goto or global_variables).
- Complexity Check: Ensure the required node isn't empty (e.g., a while(true); with no body).
- Nesting Validation: Verify if the assignment requires nested structures (e.g., a loop inside an if).
- Database & Schema Integration
- Update the assignments table to include a required_node and min_node_count column.
- Create a verification_logs table to store why a student's code failed the structural check.
- Link the Verification Layer output to the CDS trigger (CDS only runs if is_verified = true).
- Feedback & Error Reporting
- Capture the line/column of the "wrong" structure to highlight it in the frontend editor.
- Git & Deployment Workflow
- Create a feature branch: git checkout -b feat/ast-verification.
- Secure the Netcode Dataset on your local WSL environment (back up to a private cloud/drive).
- Push the verified logic (the "engine") to GitHub.

