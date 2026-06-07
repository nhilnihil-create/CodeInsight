# CodeInsight 9-Phase Compliance Audit

**Audit date:** 2026-06-06
**Auditor:** opencode (Claude M3)
**Sources:**
- `docs/superpowers/specs/2026-06-05-codeinsight-redesign-design.md` (681 lines)
- `docs/superpowers/specs/2026-06-05-codeinsight-mobile-design.md` (604 lines)
- `IT53_CODEINSIGHT_Chapter1.pdf` (Introduction, ~855 lines extracted)
- `IT53_CodeInsight_Chapter2.pdf` (Review of Related Literature, ~535 lines)
- `IT53_CodeInsight_Chapter3.pdf` (Methodology, ~1632 lines)
- `CLAUDE.md` (project status, CDS formula, prior decisions)
- All codebase files under `frontend/src/` and `backend/`

**Methodology:** Evidence-based, file:line citations, strict pass/partial/fail judgments. No inferred compliance — every claim is grounded in a file or spec section.

---

## PHASE 1 — Master Requirements Catalog

### R1. Research / Thesis Requirements (Capstone Ch. 1, 3)

| ID | Requirement | Source | Capstone citation |
|---|---|---|---|
| **R1.1** | Seven C++ concepts: DT, VR, CD, LP, FN, AR, OP | Design §2.3, Ch.3 §Planning | Ch.1:61-62, Ch.3:128-130 |
| **R1.2** | CDS formula: `CDS = (0.40 × NER) + (0.35 × NRS) + (0.25 × NTS)` | CLAUDE.md, Design §2.1, Ch.1:300-301 | Ch.1:300-301, Ch.3:182-184, 1162-1166 |
| **R1.3** | Behavioral metrics: error frequency, retry count, time-on-task | Ch.1:124-126, Ch.3 | Ch.1:252-258 |
| **R1.4** | Concept tagging mechanism links exercises to one or more of the 7 concepts | Ch.1:243-247, Design §2.3 | Ch.1:243-247, Ch.3:180-181 |
| **R1.5** | Two submission modes: Run (visible tests, no metrics) vs Submit (all tests, counted in CDS) | Ch.1:236-241, Ch.3:155-160 | Ch.1:236-241, Ch.3:155-160 |
| **R1.6** | AST-based code structure verification using tree-sitter | Ch.1:262-263, Ch.3:162-163 | Ch.1:262-291 |
| **R1.7** | Five AST checks: Construct Presence, Non-Empty Body, Variable Usage, Output Dependency, Known Bad Pattern | Ch.1:276-291 | Ch.1:276-291 |
| **R1.8** | Canonicalized pattern matching from IBM Project CodeNet (~15K solutions) | Ch.3:162-163, 191-194 | Ch.3:162-163, 191-194 |
| **R1.9** | GCC C++ compiler as execution engine | Ch.3:130-131, 165-167 | Ch.3:130-131, 165-167 |
| **R1.10** | Compiler error patterns feed micro-concept analysis | Ch.1:333-337, Ch.3:194-195 | Ch.1:333-337, Ch.3:194-195 |
| **R1.11** | Concept Difficulty Score (CDS) engine real-time on Submit | Ch.1:297-303 | Ch.1:297-303 |
| **R1.12** | Analytics Dashboard with: Difficulty Heatmap, Early Warning Alerts, Individual Student Profile, Longitudinal Progress Reports, Micro-Concept Analysis, Class-Wide Report, Structure Violations, Academic Integrity Flags | Ch.1:305-351 | Ch.1:305-351 |
| **R1.13** | Hardcoding Detection (literals in output) | Ch.1:357-370 | Ch.1:357-370 |
| **R1.14** | Blank/Template-Only Detection (code unchanged from starter) | Ch.1:371-375 | Ch.1:371-375 |
| **R1.15** | Behavioral Anomaly Detection (instant success, extreme speed) | Ch.1:376-381 | Ch.1:376-381 |
| **R1.16** | Code Growth Anomaly Detection (>30% line growth) | Ch.1:382-384 | Ch.1:382-384 |
| **R1.17** | Passive Behavioral Logging (tab switches, paste events) | Ch.1:385-389 | Ch.1:385-389 |
| **R1.18** | Three user roles: Student, Instructor, Admin | Ch.1:213-234, Ch.3:534 | Ch.1:213-234, Ch.3:534 |
| **R1.19** | Three ISO/IEC 25010 attributes: Functional Suitability, Usability, Performance Efficiency | Ch.3:72-76, 1160-1186 | Ch.3:72-76, 1160-1186 |
| **R1.20** | 4-point Likert scale (no neutral): 1=SD, 2=D, 3=A, 4=SA | Ch.3:1061-1082 | Ch.3:1061-1082 |
| **R1.21** | Weighted mean and grand mean as statistical methods | Ch.3:1112-1142 | Ch.3:1112-1142 |
| **R1.22** | Slovin's formula for sample size (N=550, e=0.05 → n=232) | Ch.3:1280-1306 | Ch.3:1280-1306 |
| **R1.23** | Pre-test and post-test evaluation for learning gain | Ch.3:1189-1200 | Ch.3:1189-1200 |
| **R1.24** | System Usability Scale (SUS) instrument as supplement | Ch.3:223-224, 1172-1173 | Ch.3:223-224, 1172-1173 |
| **R1.25** | Web-based platform, accessible by internet | Ch.3:1423-1431 | Ch.3:1423-1431 |
| **R1.26** | Hidden test cases for Submit mode (run all, including hidden) | Ch.1:239-241, Ch.3:156-160 | Ch.1:239-241, Ch.3:156-160 |
| **R1.27** | Pseudocode/heuristic engine for difficulty mapping (not ML) | Ch.1:299-303 | Ch.1:299-303 |

### R2. Design Spec Requirements — Redefined (Design Spec, 17 sections)

| ID | Requirement | Source |
|---|---|---|
| **R2.1** | Insight-first analytics: every chart answers What/Why/Who/Action | Design §1.1 |
| **R2.2** | Learning insights language: never bare CDS without context | Design §1.2, §7.4 |
| **R2.3** | Provenance & attribution: section management as audit log layer | Design §1.3, §11 |
| **R2.4** | Three epistemic modes: Insight (green/purple), Integrity (dashed), Operational (purple chip) | Design §4 |
| **R2.5** | Three roles with equal weight: Student, Instructor, Admin | Design §4 |
| **R2.6** | Hub + Drill architecture: Command Center headline | Design §4, §8 |
| **R2.7** | Dark-first design tokens; light as `[data-theme="light"]` override | Design §6.1, §6.2 |
| **R2.8** | CDS color scale: Low #22C55E, Mod #FACC15, High #EF4444, NA #7C3AED | Design §6.3 |
| **R2.9** | CDS delta/trend tokens (trend-up, trend-down, trend-flat) | Design §6.4 |
| **R2.10** | Inter (UI) + JetBrains Mono (code) typography | Design §6.5 |
| **R2.11** | 15 atoms + 12 molecules (4 new: CDSPillDelta, RiskBadge, ConceptMasteryRadar, InterventionCard) | Design §7 |
| **R2.12** | RiskBadge 4-tier: Low/Medium/High/Critical | Design §7.1 |
| **R2.13** | InterventionCard 4-slot: Student/Problem/Evidence/Action; only component allowed to call primary action on a student | Design §7.2 |
| **R2.14** | ConceptMasteryRadar 7-axis (D3) | Design §7.3 |
| **R2.15** | InsightCard requires `insight` prop; reading order Insight→Chart→Drill | Design §7.4 |
| **R2.16** | Every analytics endpoint returns `summary` field | Design §5, §17 |
| **R2.17** | CI lint rule: no `<CDSPill>` without `<InsightText>` | Design §5, §17 |
| **R2.18** | Empty states always have a CTA, never "No data" alone | Design §7.4 |
| **R2.19** | Instructor Command Center: 5 rows (Insight, 4 cards, KPI strip, concepts+roster, signals+interventions, integrity) | Design §8.1 |
| **R2.20** | Weekly Teaching Insight (Row 0) with rule citation, Wilson CI | Design §8.1, §8.4 |
| **R2.21** | KPI strip: 6 KPIs with 6-week trend (Class avg CDS, Submissions, At-risk, Flags open, Active sections, Mastery rate) | Design §8.1 |
| **R2.22** | 7-concept sortable bars + at-risk roster (Row 3) | Design §8.1 |
| **R2.23** | Learning signals as interpreted bullets, NOT raw counts (Row 4) | Design §8.1 |
| **R2.24** | Top-5 InterventionCards in queue (Row 4 right) | Design §8.1 |
| **R2.25** | Integrity monitoring dashed border, muted, collapsed (Row 5) | Design §8.1 |
| **R2.26** | Page-level confidence badge (Wilson 95% CI, n≥10, days≥14, half-width≤0.10) | Design §8.2, §8.4 |
| **R2.27** | Empty states: Week 1 (no data), Mid-term all clear, Low-N class | Design §8.3 |
| **R2.28** | K-tier ImpactTag: K≥5 full, K=2-4 directional, K<2 render "—" | Design §8.5 |
| **R2.29** | Pattern vs Why Now: observational, not causal | Design §8.6 |
| **R2.30** | "Why am I seeing this?" affordance on every insight, intervention, signal, flag | Design §8.7 |
| **R2.31** | Student anti-patterns: no class rank, no behavioral telemetry, no grade shame | Design §9.1, §10.5 |
| **R2.32** | Student Today: 4 questions (What/Why/Who/Action) | Design §9.2 |
| **R2.33** | Student Progress: solid green student line, dashed purple class avg, "not a rank" label | Design §9.3 |
| **R2.34** | Student Recommendations: 3 prioritized cards (priority/optional/stretch) | Design §9.4 |
| **R2.35** | Student Integrity: reflective surface with 3 affordances (1:1, appeal, read full rule) | Design §10.4 |
| **R2.36** | Instructor Integrity queue: rule name, evidence, confidence, pattern, 4 actions | Design §10.2 |
| **R2.37** | Integrity single flag detail: full evidence chain, code diff, timeline, baseline, confidence | Design §10.3 |
| **R2.38** | Privacy boundary at API layer: student endpoint returns different fields | Design §10.5 |
| **R2.39** | Section management: 3 actors (instructor/student/admin) with asymmetric powers | Design §11.1 |
| **R2.40** | No `open` join policy (audit-log thesis) | Design §11.2, §11.3 |
| **R2.41** | No `pending_approval` section status | Design §11.2 |
| **R2.42** | 3 join policies: code (default), request, closed | Design §11.3 |
| **R2.43** | Asymmetric leave/drop: instructor drop (immediate, reason required); student leave (pending ack, default 7-day grace) | Design §11.4 |
| **R2.44** | `section_audit_log` append-only at DB level (no UPDATE/DELETE granted) | Design §1.3, §11.5 |
| **R2.45** | Section data model with 6-char join code, term, join_policy, max_size, status | Design §11.5 |
| **R2.46** | `section_memberships` with role/status enums, soft delete, drop_reason | Design §11.5 |
| **R2.47** | 17 audit log actions enumerated | Design §11.7 |
| **R2.48** | Concurrency: race-join serialized via `SELECT ... FOR UPDATE` at max_size | Design §11.8 |
| **R2.49** | Bulk CSV import all-or-nothing with annotated error CSV | Design §11.6, §11.10 |
| **R2.50** | New backend endpoint: `GET /api/analytics/section/:id/hub` | Design §5, §12 |
| **R2.51** | New table: `evaluation_responses` (ISO/IEC 25010) | Design §5, §13 |
| **R2.52** | Sections index (`/instructor/sections`): 3 cards + "+ New" | Design §11.9A |
| **R2.53** | Section hub (`/instructor/sections/:id`): purple chip, 6 tabs (Hub/Roster/Join req/Codes/TAs/Audit) | Design §11.9B |
| **R2.54** | Student sections list with status badges, "Join another" code input | Design §11.9C |
| **R2.55** | Roster tab: search/filter/sort, 6-col grid, leave req row type, drop modal | Design §11.9D |
| **R2.56** | Codes & policy tab: 3 options, code history | Design §11.9E |
| **R2.57** | Audit log tab: WHEN/WHAT/WHO/WHY, append-only, exportable CSV | Design §11.9F |
| **R2.58** | Admin sections: dept overview, CSV import, instructor reassign, archive | Design §11.9G |
| **R2.59** | ISO/IEC 25010 instrument in-app at `/admin/evaluation` with 4-point Likert | Design §14, §5 |
| **R2.60** | 11th-table `evaluation_responses` storage | Design §14 |
| **R2.61** | Tech stack frozen: Node/Express/Postgres/React+Vite/Monaco/D3+Chart.js/GCC/tree-sitter | Design §3 |
| **R2.62** | Additive only: no removed APIs, no modified responses | Design §16 |
| **R2.63** | D3 + Chart.js, **NOT Recharts** | Design §3, §16 |
| **R2.64** | D3 is dynamic-imported, never on phone bundle summary-mode | (Mobile §6.2) |

### R3. Mobile Spec Requirements

| ID | Requirement | Source |
|---|---|---|
| **R3.1** | Dual-surface model: `mode` derived once at root, no per-component viewport queries | Mobile §2.1 |
| **R3.2** | Layout-config-driven shell: `useLayoutConfig(role, mode)` returns config | Mobile §2.2 |
| **R3.3** | Three config types: mobile (required), tablet (optional), desktop (required) | Mobile §2.2, §10 |
| **R3.4** | Mobile shell: 48px app bar, scrollable content, 56px bottom nav + safe-area | Mobile §3 |
| **R3.5** | Tap targets ≥ 44×44px, no hover-only affordances | Mobile §3, §6.3, §13.9 |
| **R3.6** | Bottom nav: Instructor 5 tabs, Student 5 tabs, Admin 3 tabs | Mobile §3.1 |
| **R3.7** | Safe-area-inset for iOS home indicator (iPhone 14/15) | Mobile §3.2, §13.13 |
| **R3.8** | Instructor IA: Primary (1 PriorityInsight), Secondary (AtRiskQueue, InterventionQueue), Tertiary (TopStrugglingConcepts, IntegrityFlagCount, ClassProfileRadar, WeeklyTeachingInsight) | Mobile §4.1, §5.1 |
| **R3.9** | Student IA: Primary (StudentTodayFocus), Secondary (WeakestConceptBar, ActionStack), Tertiary (WeeklyProgress, ConceptMasteryBarSet, IntegrityFlagCount) | Mobile §4.2, §5.2 |
| **R3.10** | Admin IA: Primary (SnapshotMetrics), Primary Action (EvaluationProgress), Secondary (AuditLog, SectionList), Tertiary (DesktopOnlyNotice×2) | Mobile §4.3, §5.3 |
| **R3.11** | Reading order: What → Why → Who → Action on every screen | Mobile §4 |
| **R3.12** | N is adaptive: `min(5, floor((viewportHeight - chromeHeight - primaryHeight) / rowHeight))` | Mobile §5.1, §13.4, §13.14 |
| **R3.13** | N is not hard-coded (no `3` or `5` constants) | Mobile §13.15 |
| **R3.14** | StateAwareShell: NoData / LowConfidence / Healthy taxonomy | Mobile §8 |
| **R3.15** | NoData trigger: 0 submissions OR section < 24h | Mobile §8 |
| **R3.16** | LowConfidence trigger: 1-2 submissions/student OR section < 14d | Mobile §8 |
| **R3.17** | Healthy trigger: ≥3 submissions/student AND section ≥14d | Mobile §8 |
| **R3.18** | Secondary/tertiary widgets with 0 rows: hidden entirely, not empty | Mobile §8 |
| **R3.19** | Component transformation table (12 rules for desktop→mobile) | Mobile §6.1 |
| **R3.20** | Phone never instantiates D3 SVG > 200×200px | Mobile §6.2 |
| **R3.21** | D3 is context-loaded (dynamic import), not blanket-blocked | Mobile §6.2 |
| **R3.22** | Sparklines pre-aggregated server-side, inline SVG | Mobile §6.2 |
| **R3.23** | Drill to full chart: "View full analysis →" link | Mobile §6.2 |
| **R3.24** | Touch & gesture surface: tap=primary, long-press=metadata, swipe=secondary action | Mobile §6.3 |
| **R3.25** | Swipe-left=snooze, swipe-right=approve/clear, with undo toast | Mobile §6.3 |
| **R3.26** | Pull-to-refresh: 60px threshold, on top-level role pages only | Mobile §6.3 |
| **R3.27** | Interaction priority: Tap=primary, Long-press=metadata, Button=explicit action | Mobile §6.4 |
| **R3.28** | 24 new mobile components (in addition to 4 reused) | Mobile §7, §13.17 |
| **R3.29** | Naming canon locked: PriorityInsight, AtRiskQueue, etc. — no synonyms | Mobile §9 |
| **R3.30** | Layout config schema: Mode, Role, WidgetRef, Screen, LayoutConfig | Mobile §10 |
| **R3.31** | 24 mobile-touchpoint endpoints, all pre-existing, 0 new | Mobile §11, §13.8 |
| **R3.32** | Initial JS bundle ≤ 200KB gzipped for 3 top-level mobile routes | Mobile §12, §13.4 |
| **R3.33** | Monaco lazy-loaded only on `/student/exercises/:id?mode=full` | Mobile §12 |
| **R3.34** | D3 dynamic-imported behind `mode !== 'mobile'` AND `render === 'full'` | Mobile §12 |
| **R3.35** | Route-level code splitting via React.lazy + Suspense | Mobile §12 |
| **R3.36** | Off-screen lazy load via IntersectionObserver | Mobile §12 |
| **R3.37** | CSS containment `contain: layout` on cards | Mobile §12 |
| **R3.38** | Bundle analyzer CI fails if phone-route bundle > 200KB | Mobile §12 |
| **R3.39** | 17 acceptance criteria: instructor triage <10s, student next-action <3s, no horizontal scroll on chart, etc. | Mobile §13 |
| **R3.40** | RiskBadge accessibility: always color + label, symbol decorative only | Mobile §6.1, §13.10 |
| **R3.41** | 3 mobile routes per role + secondary routes (Command/Today/Overview + Students/Concepts/Integrity/Sections) | Mobile §5.4 |
| **R3.42** | `Iso25010Instrument`: 4-point Likert, one question per screen, progress bar | Mobile §5.4, §13.12 |
| **R3.43** | CodePreviewSurface: no Monaco, `<pre>` + horizontal scroll, Run/Submit | Mobile §7, §5.4 |
| **R3.44** | Admin has 1 action path: EvaluationProgress | Mobile §13.11 |
| **R3.45** | "Why am I seeing this?" preserved on every insight | (cross-ref R2.30) |
| **R3.46** | "Pattern, not accusation" wording on student integrity | (cross-ref R2.31, Design §10.1) |
| **R3.47** | "Flag review requires tablet or desktop" notice on instructor mobile integrity | Mobile §5.4 |
| **R3.48** | Learning Insights Language preserved on mobile | Mobile §1.3, §16 |

### R4. CLAUDE.md / Project Status Requirements

| ID | Requirement | Source |
|---|---|---|
| **R4.1** | 12/12 database tables present | CLAUDE.md |
| **R4.2** | 50+ endpoints implemented | CLAUDE.md |
| **R4.3** | Frontend build passing | CLAUDE.md |
| **R4.4** | 16/16 unit tests + 71/71 backend API tests (now 117/117) | CLAUDE.md |
| **R4.5** | Academic Integrity Engine: `checkHardcoding()`, `checkBlankTemplate()` functional | CLAUDE.md |
| **R4.6** | `checkBehavioralAnomaly()`, `checkCodeGrowthAnomaly()` need historical data | CLAUDE.md |
| **R4.7** | Code Paste Detection fixed (no crash) | CLAUDE.md |
| **R4.8** | Notification Queue sends email or falls back to console | CLAUDE.md |
| **R4.9** | Hidden test case separation verified | CLAUDE.md |
| **R4.10** | E2E flow tested (cdsIntegrityPipeline.test.js) | CLAUDE.md |
| **R4.11** | Risk thresholds: Low (0-0.31), Mod (0.31-0.50), High (0.50-0.66) | CLAUDE.md |
| **R4.12** | CDS formula weights: 0.40 NER, 0.35 NRS, 0.25 NTS | CLAUDE.md |
| **R4.13** | 7 concepts: DT, VR, CD, LP, FN, AR, OP | CLAUDE.md |

### R5. Performance / Architecture Requirements

| ID | Requirement | Source |
|---|---|---|
| **R5.1** | D3 + Chart.js only, no Recharts | Design §3, §16 |
| **R5.2** | Additive only: no removed APIs, no modified responses | Design §16 |
| **R5.3** | Web responsive only (no native mobile) | Design §15, §16 |
| **R5.4** | Oracle Cloud ARM deployment target | Design §3 |
| **R5.5** | GCC C++ compiler only (v1) | Design §3 |
| **R5.6** | tree-sitter AST verification | Design §3 |
| **R5.7** | Project CodeNet baseline similarity | Design §3 |
| **R5.8** | No new auth provider (email-based remains) | Design §16 |
| **R5.9** | No real-time websocket in v1 | Design §16 |
| **R5.10** | Polling / batch refresh only | Design §15, §16 |

**Total: 27 thesis + 64 design + 48 mobile + 13 project + 10 performance = 162 distinct requirements.**

---

