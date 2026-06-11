# Paper-vs-Implementation Cross-Check — CodeInsight

**Date**: 2026-06-11
**Method**: Every claim in the paper checked against actual code

## Legend
- ✅ **Full** — Implemented, working, matches paper
- ⚠️ **Partial** — Exists but doesn't fully match paper spec
- ❌ **Missing** — Claimed in paper but not implemented
- 📝 **Docs Only** — Mentioned in comments but no implementation

---

## 1. User Login and Registration

| Paper Claim | Status | Evidence |
|-------------|--------|----------|
| Users can create and access accounts | ✅ Full | `Login.jsx`, `Landing.jsx`, JWT auth middleware |
| Instructor role | ✅ Full | `pages/instructor/*` (13 pages) |
| Student role | ✅ Full | `pages/student/*` (12 pages + 12 editor components) |

## 2. Run vs Submit Modes

| Paper Claim | Status | Evidence |
|-------------|--------|----------|
| Run button tests against first visible test case only | ✅ Full | `submissionController.js:86-88` — `visibleTC[0]` |
| Run provides immediate feedback | ✅ Full | Returns result with pass/fail |
| Run does NOT save to database | ✅ Full | `exports.run` has no INSERT |
| Run does NOT count toward behavioral metric | ✅ Full | No submission row created |
| Submit tests against ALL test cases including hidden | ✅ Full | `submissionController.js:288` — `exercise.test_cases` (all) |
| Submit saves attempt to database | ✅ Full | INSERT into `submissions` |
| Submit counts in CDS computation | ✅ Full | `calculateLiveCDS` called after submit |

## 3. Exercise Management

| Paper Claim | Status | Evidence |
|-------------|--------|----------|
| Teachers create programming exercises | ✅ Full | `admin/Exercises.jsx` |
| Tag each with programming concepts | ✅ Full | `exercises.concept_id` FK, `concepts` table |
| Concepts: variables, conditionals, loops, functions, arrays, OOP | ⚠️ Partial | Concepts table exists; default seed has 7 concepts but not verified against this exact list |

## 4. Web-based Code Editor

| Paper Claim | Status | Evidence |
|-------------|--------|----------|
| Built-in code editor | ✅ Full | `student/CodeEditor.jsx` + 12 editor components |
| C++ code execution | ✅ Full | `executor.js` — Docker sandbox with gcc |
| Error Frequency tracked | ✅ Full | Counted as `failed_attempts` in submissions, used in NER |
| Retry Count tracked | ✅ Full | `attempt_number` in submissions, used in NRS |
| Time-on-Task tracked | ✅ Full | `time_spent_seconds` in submissions, used in NTS |

## 5. Code Structure Verification (AST)

### Paper claims 5 checks performed in order:

| # | Paper Claim | Status | Evidence |
|---|-------------|--------|----------|
| 1 | **Construct Presence Check** — AST has node type for tagged concept (e.g., `for_statement`/`while_statement` for Loops) | ✅ Full | `astVerifier.js:96-121` — `checkRequiredNodes(tree, requiredNodes)` |
| 2 | **Non-Empty Body Check** — detected construct has meaningful statements | ✅ Full | `astVerifier.js:129-173` — `checkEmptyBodies(tree)` |
| 3 | **Variable Usage Check** — construct uses variables not just constants | ⚠️ Partial | `astVerifier.js:180-247` — `detectHardcodedOutput()` checks for cout/printf with literals only, but this is about hardcoded *output*, not about variable usage in constructs generally |
| 4 | **Output Dependency Check** — construct affects program output, not dead code | ❌ Missing | No implementation of dead code / output dependency analysis |
| 5 | **Known Bad Pattern Matching from Project CodeNet** — compares AST to library of common beginner mistakes from CodeNet (e.g., `sum = x` instead of `sum += x`) | ❌ Missing | Comment says "CodeNet patterns" (line 2) but no CodeNet dataset ingested, no pattern library exists |

### Additional AST verification:

| Paper Claim | Status | Evidence |
|-------------|--------|----------|
| Fails → `structure_valid = false` | ⚠️ Partial | Uses `is_verified` field (renamed from paper's `structure_valid`) |
| Not counted toward CDS | ⚠️ Partial | Submission IS saved to DB but with `is_verified=false`. CDS engine still processes it unless flagged as blank. The "not counted" claim is NOT enforced. |
| Shown in Structure Violations panel | ⚠️ Partial | `verification_logs` table populated, but no dedicated frontend "Structure Violations Report" page |

## 6. CDS Engine

| Paper Claim | Status | Evidence |
|-------------|--------|----------|
| Formula: CDS = (0.40×NER)+(0.35×NRS)+(0.25×NTS) | ✅ Full | `cdsEngine.js:187`, consistent across batch/live/instant |
| Section-relative normalization | ✅ Full | `getNormalizedValue()` with outlier capping |
| Updated in real time after each submission | ✅ Full | `calculateLiveCDS` called in submission controller |
| Centralized thresholds (Low≤0.31, Moderate≤0.50, High>0.50) | ✅ Full | `CDS_THRESHOLDS` constant, all callers use it |

## 7. Analytics Dashboard

| Paper Claim | Status | Evidence |
|-------------|--------|----------|
| Difficulty Heatmap (CDS matrix per student per concept) | ✅ Full | `instructor/Heatmap.jsx` |
| Early Warning Alerts (automated when CDS crosses threshold) | ✅ Full | `alertEngine.js` generates alerts, `instructor/Dashboard.jsx` shows them |
| Individual Student Profile (CDS across all concepts) | ✅ Full | `student/Profile.jsx` — radar chart + per-concept cards |
| Longitudinal Progress Reports (CDS changes over time) | ✅ Full | `longitudinalReportEngine.js`, `instructor/Reports.jsx` |

## 8. Micro-Concept Analysis

| Paper Claim | Status | Evidence |
|-------------|--------|----------|
| Deterministic rule-based feedback | ✅ Full | `microConceptTaxonomy.js` — 200+ lines of if-then rules |
| Compiler error patterns (GCC) | ⚠️ Partial | Rules check for compiler error strings, but `compilerErrors` array is always `[]` in current submission controller — not populated from executor output |
| Code structure (AST nodes) | ✅ Full | `microContext.ast.node_types` populated via tree-sitter |
| Test case failure patterns | ✅ Full | `microContext.testResults` includes pass/fail per test case |
| Early Warning Alert integration | ⚠️ Partial | Micro-concept feedback returned in submission response but not linked to alert engine |
| Class-Wide Micro-Concept Report | ⚠️ Partial | `classMisconceptionReport.js` exists and has tests, but no dedicated frontend page for it |

## 9. Structure Violation Report

| Paper Claim | Status | Evidence |
|-------------|--------|----------|
| List of submissions where construct was missing/empty/incorrect | ⚠️ Partial | `verification_logs` table exists and is populated, but no dedicated frontend page titled "Structure Violation Report" |
| Shows student, concept, validation message | ⚠️ Partial | Data exists in DB but not surfaced in a dedicated report UI |

## 10. Academic Integrity Monitoring

| Paper Claim | Status | Evidence |
|-------------|--------|----------|
| a. **Hardcoding Detection** (literals instead of variables) | ✅ Full | `checkHardcoding()` — regex for `cout << literal;` with computation score |
| b. **Blank/Template Submission Detection** | ✅ Full | `checkBlankTemplate()` — compares against starter code |
| c. **Behavioral Anomaly Detection** (instant success, extreme speed) | ✅ Full | `checkBehavioralAnomaly()` — z-score < -2.0, <30s, first attempt correct |
| d. **Code Growth Anomaly Detection** (>30% growth spike) | ✅ Full | `checkCodeGrowthAnomaly()` — line count delta, 30% threshold |
| e. **Passive Behavioral Logging** (tab switches, paste events) | ❌ Missing | `logPassiveBehavior()` is a no-op stub — just returns spread of input. No `visibilitychange` listener, no paste event tracking, no tab switch count in frontend. `behavioralData: {}` sent empty from controller. DB columns (`tab_switch_count`, etc.) don't exist. |
| Hardcoded submissions excluded from class normalization | ⚠️ Partial | Integrity flags are created but batch CDS still includes flagged students' scores (no `WHERE integrity_flag_count = 0` filter in `computeBatchCDS`) |
| Blank submissions excluded from CDS | ✅ Full | Blank check in `computeBatchCDS` forces CDS=1.0 and classification='High' |
| Academic Integrity Flags panel | ✅ Full | `instructor/AcademicIntegrityFlags.jsx` |

## 11. Concept Tagging

| Paper Claim | Status | Evidence |
|-------------|--------|----------|
| Teachers tag exercises with concepts | ✅ Full | `concepts` table, `exercises.concept_id` FK |
| Tags are semantic backbone of analytics | ✅ Full | CDS, heatmaps, reports all join through concept_id |

## 12. Progress Tracking

| Paper Claim | Status | Evidence |
|-------------|--------|----------|
| Student concept difficulty profiles | ✅ Full | `student/Profile.jsx` — radar chart + per-concept mastery cards |
| Self-reflection on improvement | ✅ Full | `student/Progress.jsx` — longitudinal view |

---

## Summary

| Category | Full | Partial | Missing |
|----------|------|---------|---------|
| Authentication | 3 | 0 | 0 |
| Run/Submit | 5 | 0 | 0 |
| Exercise Management | 2 | 1 | 0 |
| Code Editor | 4 | 0 | 0 |
| AST Verification | 2 | 1 | 2 |
| CDS Engine | 4 | 0 | 0 |
| Analytics Dashboard | 4 | 0 | 0 |
| Micro-Concept | 2 | 2 | 0 |
| Structure Violation Report | 0 | 1 | 1 |
| Academic Integrity | 4 | 1 | 1 |
| Concept Tagging | 2 | 0 | 0 |
| Progress Tracking | 2 | 0 | 0 |
| **TOTAL** | **34** | **6** | **4** |

---

## Gaps Requiring Implementation (4 missing, 6 partial)

### Critical (defense-risk)
1. **Known Bad Pattern Matching from CodeNet** (AST #5) — Paper explicitly claims it; no implementation
2. **Output Dependency Check** (AST #4) — Paper claims dead code detection; not implemented
3. **Passive Behavioral Logging** (Integrity #5e) — Paper claims tab switch + paste tracking; completely absent

### Medium (partial gaps)
4. **Variable Usage Check** (AST #3) — Exists as hardcoded output check, but not the general "construct uses variables" check
5. **Structure Valid → Not Counted in CDS** — Paper says unverified submissions aren't counted; they currently still are
6. **Structure Violation Report** — Data exists but no dedicated frontend page
7. **Compiler Errors in Micro-Concept** — Rules exist but `compilerErrors` array is never populated
8. **Hardcoded Submissions Excluded from Normalization** — Flags created but batch CDS still processes them
9. **Class-Wide Micro-Concept Report** — Engine exists, no frontend page
10. **Micro-Concept → Alert Integration** — Feedback exists but not linked to alerts
