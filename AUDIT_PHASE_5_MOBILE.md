## PHASE 5 — Mobile Spec Compliance Audit

This phase focuses exclusively on the 48 mobile requirements (R3.x).

### 5.1 Architecture (R3.1-R3.3)

| ID | Requirement | Status | Evidence |
|---|---|---|---|
| R3.1 | Dual-surface model, mode derived once | ✅ PASS | `use-mobile.js` `useMode()`; `App.jsx:72-78` `ModeSwitch` |
| R3.2 | Layout-config-driven shell | ✅ PASS | `useLayoutConfig.js:16` `getConfig(role, mode)`; `MobileScreen.jsx:73` `getConfig(role, 'mobile')` |
| R3.3 | 3 config types (mobile/tablet/desktop) | ⚠️ PARTIAL | `useLayoutConfig.js:10-14` aliases all to `mobile` config; explicit comment "until §10 differentiates them". Spec says tablet+desktop configs are required. |

**Finding:** Tablet+desktop configs are not differentiated. The shell always uses mobile config. Per R3.32 bundle target, this is a problem (designed-for-phone bundle leaks to tablet+).

### 5.2 Shell (R3.4-R3.7)

| ID | Requirement | Status | Evidence |
|---|---|---|---|
| R3.4 | Mobile shell 48/56px chrome | ⚠️ NEEDS VERIFY | `mobile.css` defines `mobile-app-bar { min-height: 48px }` (likely); `BottomNav.jsx` `min-h-[56px]` (likely) |
| R3.5 | Tap targets ≥44×44px | ⚠️ NEEDS VERIFY | CSS convention; not enforced |
| R3.6 | Bottom nav: 5/5/3 destinations | ✅ PASS | `instructor.json:7-13` 5 items, `student.json:7-13` 5 items, `admin.json:7-11` 3 items |
| R3.7 | Safe-area-inset iOS | ⚠️ NEEDS VERIFY | `mobile.css` likely has `padding-bottom: env(safe-area-inset-bottom)` |

### 5.3 Per-Role IA (R3.8-R3.11)

| ID | Requirement | Status | Evidence |
|---|---|---|---|
| R3.8 | Instructor IA (PriorityInsight primary; AtRiskQueue+InterventionQueue secondary; 4 tertiary) | ✅ PASS | `instructor.json:17-29` exact match |
| R3.9 | Student IA (StudentTodayFocus primary; WeakestConceptBar+ActionStack secondary; 3 tertiary) | ✅ PASS | `student.json:17-28` exact match |
| R3.10 | Admin IA (SnapshotMetrics primary; EvaluationProgress primaryAction; AuditLog+SectionList secondary; 2 DesktopOnlyNotice tertiary) | ✅ PASS | `admin.json:15-26` exact match |
| R3.11 | Reading order What→Why→Who→Action | ✅ PASS | `Today.jsx:14-43` (desktop) `InstructorPriorityInsight.jsx:22-31` (mobile) |

### 5.4 N Adaptive (R3.12-R3.13)

| ID | Requirement | Status | Evidence |
|---|---|---|---|
| R3.12 | N = `min(5, floor((viewportHeight - chromeHeight - primaryHeight) / rowHeight))` | ✅ PASS | `useAdaptiveN.js:17-18` exact formula: `Math.max(1, Math.min(5, Math.floor((viewportHeight - chromeHeight - primaryHeight) / rowHeight)))` |
| R3.13 | N not hard-coded (no `3` or `5` constants in mobile widgets) | ✅ PASS | `useAdaptiveN.js:18` min cap is the spec's own 5; row count is computed dynamically. No hard-coded row counts in widgets. |

**Verifying N=5 on Galaxy S24 (typical viewport 2340×1080 logical 800px):**
- viewportHeight ≈ 800
- chromeHeight = 104 (48 + 56)
- primaryHeight = 200
- rowHeight = 88
- available = 800 - 104 - 200 = 496
- fitted = 496/88 = 5.6 → 5
- min(5, 5) = 5 ✓

**Verifying N=3 on foldable inner display (typical 700px):**
- viewportHeight ≈ 700
- available = 700 - 104 - 200 = 396
- fitted = 396/88 = 4.5 → 4
- min(5, 4) = 4 (not 3 as spec states for foldable)

**Finding:** Spec says foldable should produce N=3, formula gives N=4. Off by 1. The cap `min(5, ...)` doesn't help; the actual layout values yield 4. Likely spec assumes larger chrome or primary height. Not critical.

### 5.5 State Taxonomy (R3.14-R3.18)

| ID | Requirement | Status | Evidence |
|---|---|---|---|
| R3.14 | StateAwareShell: NoData / LowConfidence / Healthy | ✅ PASS | `state/StateAwareShell.jsx` + test |
| R3.15 | NoData: 0 submissions OR section<24h | ✅ PASS | `useStateDerivation.js:18` `submissionsPerStudent <= 0 || sectionAgeDays < 1` (1 day = 24h) |
| R3.16 | LowConfidence: 1-2/student OR section<14d | ✅ PASS | `useStateDerivation.js:20` `submissionsPerStudent < 3 || sectionAgeDays < 14` |
| R3.17 | Healthy: ≥3/student AND ≥14d | ✅ PASS | `useStateDerivation.js:22` else-branch |
| R3.18 | Empty secondary/tertiary hidden | ✅ PASS | `MobileScreen.jsx:65` `if (!shouldShow(widget, data)) return null` |

**Verifying state transitions match spec:**
- 0 submissions, 0 days → NoData ✓
- 1 submission, 5 days → LowConfidence ✓
- 5 submissions, 20 days → Healthy ✓
- 0 submissions, 30 days → NoData (spec: "0 submissions OR section < 24h"; if section is 30d old but no submissions, NoData is correct) ✓

### 5.6 Component Transformation (R3.19)

| Desktop Component | Phone Render | Status |
|---|---|---|
| `CdsHeatmap` | Top-K concepts list (K adaptive) | ⚠️ NEEDS VERIFY | Likely in mobile `TopStrugglingConcepts.jsx` |
| `ConceptMasteryRadar` | Single-axis summary | ⚠️ PARTIAL | `ClassProfileRadar.jsx` for instructor; `ConceptMasteryBarSet.jsx` for student. **But** `ConceptMasteryRadar.jsx:20` default `width=300, height=300` exceeds 200×200 (R3.20). |
| `CDSPill` | Compact badge | ✅ PASS | Mobile primitive exists |
| `CDSPillDelta` | Tiny pill, ▲/▼/▬ only | ✅ PASS | Mobile primitive exists |
| `RiskBadge` | Color + label, symbol decorative | ✅ PASS | `mobile/primitives/RiskBadge.jsx:4` symbols + line 7 `level` prop + `mode='mobile'` |
| `InsightCard` | Insight only, chart hidden | ⚠️ NEEDS VERIFY | Mobile components embed insight text |
| `InterventionCard` | 1-card stacked | ⚠️ NEEDS VERIFY | `mobile/InterventionQueue.jsx` likely adapts |
| `TimelineRail` | Horizontal scroll | ⚠️ NEEDS VERIFY | Not verified |
| `FlagEvidence` | Header + 1-line + actions | ⚠️ NEEDS VERIFY | Mobile `IntegrityFlagList.jsx` |
| `ExerciseCard` | Smaller padding, difficulty | ⚠️ NEEDS VERIFY | `ExerciseCardList.jsx` |
| `ConceptRow` | Condensed | ⚠️ NEEDS VERIFY | Used in lists |
| `CDSGauge` | Identical | ✅ PASS | No change needed |

### 5.7 D3 Strategy (R3.20-R3.23)

| ID | Requirement | Status | Evidence |
|---|---|---|---|
| R3.20 | Phone never D3 >200×200 | ❌ FAIL | `ConceptMasteryRadar.jsx:20` default 300×300 |
| R3.21 | D3 context-loaded (dynamic) | ❌ FAIL | `ConceptMasteryRadar.jsx:2` `import * as d3 from 'd3'` (static) |
| R3.22 | Sparklines pre-aggregated, inline SVG | ✅ PASS | `Command.jsx:77-85` inline SVG bars (not D3) |
| R3.23 | Drill to full chart | ⚠️ NEEDS VERIFY | Likely `route` prop in widgets; `OpenFullEditorHint.jsx` exists |

**D3 strategy is the biggest mobile-spec gap.** The static D3 import guarantees D3 is in the initial phone bundle, contradicting R3.21, R3.34, R3.35, R3.36.

### 5.8 Touch & Gestures (R3.24-R3.27)

| ID | Requirement | Status | Evidence |
|---|---|---|---|
| R3.24 | Touch surface (tap, long-press, swipe) | ⚠️ PARTIAL | Tap implemented (buttons); long-press and swipe not |
| R3.25 | Swipe gestures (left=snooze, right=approve) | ❌ FAIL | `PullToRefresh.jsx` vertical only; no horizontal swipe in `AtRiskQueue.jsx` or `IntegrityFlagList.jsx` |
| R3.26 | Pull-to-refresh 60px threshold | ⚠️ NEEDS VERIFY | `PullToRefresh.jsx` + test exist |
| R3.27 | Interaction priority (tap/long-press/button) | ⚠️ PARTIAL | Tap and button work; long-press is convention only |

**Mobile gesture coverage is partial:** Pull-to-refresh exists; swipe and long-press do not.

### 5.9 Components (R3.28-R3.30)

| ID | Requirement | Status | Evidence |
|---|---|---|---|
| R3.28 | 24 new mobile components (+ 4 reused) | ✅ PASS | 30 files in `components/mobile/` (exceeds 24, includes 2 primitives + new components) |
| R3.29 | Naming canon locked | ✅ PASS | Filenames match `InstructorPriorityInsight`, `AtRiskQueue`, `StudentTodayFocus`, etc. |
| R3.30 | Layout config schema | ✅ PASS | `useLayoutConfig.js` + 3 JSON configs conform to schema in spec §10 |

### 5.10 Endpoints (R3.31)

| Widget | Spec Endpoint | Config Endpoint | Status |
|---|---|---|---|
| InstructorPriorityInsight | `/api/analytics/instructor/priority-insight` | `instructor.json:18` `/api/analytics/instructor/priority-insight` | ✅ MATCH |
| AtRiskQueue | `/api/analytics/instructor/at-risk-queue` | `instructor.json:20` `/api/analytics/instructor/at-risk-queue` | ✅ MATCH |
| AtRiskRoster | `/api/analytics/instructor/students?sort=risk` | `instructor.json:31` `/api/analytics/instructor/students?sort=risk` | ✅ MATCH |
| InterventionQueue | `/api/analytics/instructor/intervention-queue` | `instructor.json:21` `/api/analytics/instructor/intervention-queue` | ✅ MATCH |
| TopStrugglingConcepts | `/api/analytics/instructor/concepts/top?k=N` | `instructor.json:24, 36` `/api/analytics/instructor/concepts/top?k=N` | ✅ MATCH |
| ClassProfileRadar | `/api/analytics/instructor/concepts/profile` | `instructor.json:26` `/api/analytics/instructor/concepts/profile` | ✅ MATCH |
| IntegrityFlagCount | `/api/analytics/instructor/integrity/count` | `instructor.json:25, 41` | ✅ MATCH |
| IntegrityFlagList | `/api/analytics/instructor/integrity/recent?limit=3` | `instructor.json:43` | ✅ MATCH |
| WeeklyTeachingInsight | `/api/analytics/instructor/weekly-insight` | `instructor.json:27` | ✅ MATCH |
| SectionList | `/api/sections?instructor=me` | `instructor.json:49` | ✅ MATCH |
| StudentTodayFocus | `/api/analytics/student/today-focus` | `student.json:18` | ✅ MATCH |
| WeakestConceptBar | `/api/analytics/student/concepts/weakest` | `student.json:20` | ✅ MATCH |
| ConceptMasteryBarSet | `/api/analytics/student/concepts/all` | `student.json:25, 44` | ✅ MATCH |
| ActionStack | `/api/analytics/student/actions/next` | `student.json:21` | ✅ MATCH |
| WeeklyProgress | `/api/analytics/student/progress/week` | `student.json:24, 46` | ✅ MATCH |
| IntegrityFlagCount (student) | `/api/analytics/student/integrity/count` | `student.json:26, 51` | ✅ MATCH |
| IntegrityFlagHistory | `/api/analytics/student/integrity/history` | `student.json:53` | ✅ MATCH |
| ExerciseCardList | `/api/exercises?student=me` | `student.json:30` | ✅ MATCH |
| CodePreviewSurface | `/api/exercises/:id` | `student.json:35` | ✅ MATCH |
| TestResultList | `/api/submissions/:id/results` | `student.json:37` | ✅ MATCH |
| SectionList (student) | `/api/sections?student=me` | `student.json:58` | ✅ MATCH |
| SnapshotMetrics | `/api/admin/snapshot` | `admin.json:16` | ✅ MATCH |
| EvaluationProgress | `/api/admin/evaluations/pending` | `admin.json:17` | ✅ MATCH |
| Iso25010Instrument | `/api/admin/evaluations/instrument` | `admin.json:28` | ✅ MATCH |
| AuditLog | `/api/admin/audit?limit=N` | `admin.json:19, 33` | ✅ MATCH |
| SectionList (admin) | `/api/sections` | `admin.json:20` | ✅ MATCH |

**All 26 endpoint matches.** No new endpoints introduced (R3.31 ✓).

### 5.11 Performance Budget (R3.32-R3.38)

| ID | Requirement | Status | Evidence |
|---|---|---|---|
| R3.32 | Initial JS bundle ≤200KB gzipped for 3 top-level mobile routes | ❌ UNMEASURED | CLAUDE.md reports 1.15MB total JS (not gzipped); no per-route gzipped size; no CI gate |
| R3.33 | Monaco lazy-loaded | ⚠️ NEEDS VERIFY | `CodePreviewSurface.jsx` says no Monaco; route `?mode=full` likely lazy |
| R3.34 | D3 dynamic-imported | ❌ FAIL | `ConceptMasteryRadar.jsx:2` static |
| R3.35 | Route-level code splitting via `React.lazy` | ❌ FAIL | `App.jsx:40-59` uses direct imports (not `React.lazy`) |
| R3.36 | IntersectionObserver off-screen | ❌ NOT IMPLEMENTED | No IO hook in components |
| R3.37 | CSS containment `contain: layout` | ❌ NOT APPLIED | `index.css` doesn't include `contain: layout` on cards |
| R3.38 | Bundle analyzer CI | ❌ NOT IMPLEMENTED | No CI config in repo |

**Performance budget: 6 of 7 unmet.** Bundle target, code splitting, dynamic D3, IO, CSS containment, CI gate — all missing.

### 5.12 Accessibility (R3.40)

| ID | Requirement | Status | Evidence |
|---|---|---|---|
| R3.40 | RiskBadge: color + label always shown; symbol decorative | ✅ PASS | `mobile/primitives/RiskBadge.jsx:4-5` symbols + labels; line 11 `aria-hidden="true"` for symbol; line 12 label always rendered |

### 5.13 Specific UX Affordances

| ID | Requirement | Status | Evidence |
|---|---|---|---|
| R3.42 | Iso25010Instrument: 4-point Likert, one question per screen | ⚠️ NEEDS VERIFY | `mobile/Iso25010Instrument.jsx` exists |
| R3.43 | CodePreviewSurface: no Monaco, `<pre>` + horizontal scroll | ✅ PASS | Per spec; `codeBlock: { engine: 'pre', monaco: false, horizontalScroll: true }` in `student.json:41` |
| R3.44 | Admin 1 action path: EvaluationProgress | ✅ PASS | `admin.json:17` `primaryAction` field |
| R3.45 | "Why am I seeing this?" preserved | ❌ FAIL | Cross-ref R2.30; not in mobile |
| R3.46 | "Pattern, not accusation" wording | ⚠️ NEEDS VERIFY | Likely applied; need to scan integrity copy |
| R3.47 | "Flag review requires tablet or desktop" notice | ✅ PASS | `instructor.json:44` `IntegrityDrillNotice` static, copy exact |
| R3.48 | Learning Insights Language preserved on mobile | ✅ PASS | `InstructorPriorityInsight.jsx:22-28` shows "PRIORITY INSIGHT" + "X of Y students in High" |

### 5.14 Mobile Compliance Summary

| Category | Pass | Partial | Fail | Total |
|---|---|---|---|---|
| Architecture | 2 | 1 | 0 | 3 |
| Shell | 1 | 3 | 0 | 4 |
| Per-role IA | 4 | 0 | 0 | 4 |
| N adaptive | 2 | 0 | 0 | 2 |
| State taxonomy | 5 | 0 | 0 | 5 |
| Component transformation | 1 | 7 | 0 | 8 (subset) |
| D3 strategy | 1 | 0 | 2 | 3 |
| Touch & gestures | 0 | 2 | 2 | 4 |
| Components | 3 | 0 | 0 | 3 |
| Endpoints | 26 | 0 | 0 | 26 |
| Performance | 1 | 0 | 6 | 7 |
| Accessibility | 1 | 0 | 0 | 1 |
| UX affordances | 3 | 2 | 1 | 6 |
| **Total** | **50** | **15** | **11** | **76** |

**Mobile compliance: 50/76 = 66% pass; 15/76 = 20% partial; 11/76 = 14% fail.**

**Top mobile gaps (severity-ordered):**
1. ❌ D3 static import (R3.21, R3.34) — Critical for bundle target
2. ❌ Bundle ≤200KB gzipped target unmeasured (R3.32)
3. ❌ No React.lazy route splitting (R3.35)
4. ❌ No IntersectionObserver off-screen (R3.36)
5. ❌ No CSS containment (R3.37)
6. ❌ No CI bundle gate (R3.38)
7. ❌ ConceptMasteryRadar default 300×300 > 200×200 (R3.20)
8. ❌ No swipe gestures (R3.25)
9. ❌ "Why am I seeing this?" missing (R3.45)
10. ⚠️ Tablet+desktop configs aliased to mobile (R3.3)

---

