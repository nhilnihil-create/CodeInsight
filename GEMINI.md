# CodeInsight — Gemini Code Assist Implementation Authority

## 🎯 Research Objectives Alignment (Chapters 1-3)
This document tracks the implementation of the remaining components required to satisfy the research methodology and theoretical pillars (Pillars 1-10).

---

## 📅 6-Day Implementation Sprint
To prevent rate limiting, each day focuses on a specific service layer. 

### Day 1: The Integrity & Persistence Layer
**Focus:** Finalizing the data foundation for Objective 1.
- **Database Sync:** Execute `20260410_add_starter_code_and_baselines.sql` to enable starter code comparison and baseline stability.
- **Blank/Template Detection:** Update `cdsEngine.js` and `submissionController.js` to compare `code` against `exercises.starter_code`.
- **Code Growth Tracking:** Implement a logic in `submissionController` to calculate line-count delta from the previous attempt (Pillar 4: Jadud 2006).

### Day 2: AST Infrastructure (The "Brain")
**Focus:** Implementing the deterministic structure analysis (Pillar 3).
- **Dependency Setup:** Install `tree-sitter` and `tree-sitter-cpp`.
- **AST Verifier Service:** Replace the skeleton in `backend/services/astVerifier.js`.
- **The Canonizer:** Implement logic to strip identifiers and literals to create structural fingerprints.
- **Verification Workflow:** Integrate `astVerifier` into the submission pipeline—flag submissions where `is_verified = false`.

### Day 3: CodeNet Pattern Ingestion
**Focus:** Loading the research knowledge base (Pillar 3).
- **Ingestion Script:** Create `backend/scripts/ingestCodeNet.js`.
- **Filtering Logic:** Filter IBM Project CodeNet (14M → 15k intro-level C++ solutions).
- **Hash Ingestion:** Populate the `ast_templates` table with canonical hashes of ideal vs. novice solutions for the 7 core concepts.

### Day 4: Micro-Concept & Hardcoding Detection
**Focus:** Implementing the diagnosis engine (Pillar 5 & 10).
- **Hardcoding Detector:** Use the AST to verify if `cout` or `printf` outputs rely on variables/logic or just hardcoded literals (Pillar 4: Naude et al. 2010).
- **Rule Engine:** Implement `backend/services/microConceptEngine.js` using the taxonomy defined in `microConceptTaxonomy.js`.
- **Student Feedback UI:** Update `CodeEditor.jsx` to show the "Specific Feedback" panel after a submission is processed.

### Day 5: Pedagogical & Longitudinal Reporting
**Focus:** Transforming data into instructor insights (Objective 3).
- **Class Misconception Report:** Implement `backend/services/classMisconceptionReport.js` to aggregate class-wide patterns.
- **Longitudinal Engine:** Implement `backend/services/longitudinalReportEngine.js` to calculate "Mastery Velocity" (Pillar 9).
- **Dashboard Update:** Add "Mastery Trend" charts to the Instructor Analytics page using Recharts.

### Day 6: Automation & ISO Evaluation Hooks
**Focus:** System stability and research evaluation (Objective 4).
- **Auto-Close Service:** Implement a `node-schedule` job to close exercises at deadlines and trigger batch CDS.
- **Evaluation Hooks:** Add hidden logging for "Time-to-Interactive" and "Response Latency" to support the ISO 25010 Performance Efficiency evaluation.
- **Final System Audit:** Run the comprehensive verification suite.

---

## 🛠 Technical Specifications

### The CDS Safety Rules (Consolidated)
| Rule | Logic | Override |
| :--- | :--- | :--- |
| **Blank Check** | `code === starter_code` | Force High |
| **NTS Edge Case** | `nts >= 0.9 && success === 0` | Force High |
| **Outlier Cap** | `val > mean + 2σ` | Cap at `mean + 2σ` |
| **Post-Solution** | `attempt > first_accepted` | Exclude from NRS |
| **Integrity Flag** | `hardcoded === true` | Flag for Review |

### Micro-Concept Rule Map (Pillar 5)
Each concept must trigger at least 2 of these deterministic rules:
- **Conditionals:** `cond_missing_else`, `cond_assignment_vs_comparison`.
- **Loops:** `loop_off_by_one`, `loop_missing_increment`.
- **Arrays:** `arr_hardcoded_index`, `arr_out_of_bounds`.
- **Functions:** `func_missing_return`, `func_defined_never_called`.

---

## 🛡️ Academic Integrity Guardrails (Pillar 4)
These checks must run before a submission is deemed "Verified" for CDS:
1. **Structural Presence:** Does the code contain the required concept node (e.g., `for_statement`)?
2. **Non-Triviality:** Is the body of the construct non-empty?
3. **Variable Dependency:** Does the output change if the input variables change (AST-level dependency check)?
4. **Growth Anomaly:** Did the student paste >30% of the code in one attempt (Jadud's Growth Signal)?

---

## 📈 ISO 25010 Evaluation Metrics
To satisfy Objective 4, we must collect:
- **Functional Suitability:** % of correctly identified micro-concepts vs. human grader.
- **Usability:** System Usability Scale (SUS) score from PSU CCS pilot.
- **Performance Efficiency:** Mean time for AST verification + CodeNet matching (<500ms target).

---

## 🚀 Execution Strategy to Avoid Rate Limits
1. **Single-File Context:** When implementing a service, provide the full file content in one go.
2. **Schema-First:** Always ensure DB migrations are run before logic updates.
3. **Mocking:** Use the `seed data` for testing logic locally before asking Gemini for complex re-calculations.

---
*Last Updated: April 15, 2026*
*Authoritative for Gemini Code Assist sessions.*
```

<!--
[PROMPT_SUGGESTION]Implement Day 1: Update cdsEngine.js and submissionController.js to use the starter_code for blank detection.[/PROMPT_SUGGESTION]
[PROMPT_SUGGESTION]Implement Day 2: Create the AST Verifier service using tree-sitter to check for required node presence.[/PROMPT_SUGGESTION]
