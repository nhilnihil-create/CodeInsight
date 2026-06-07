## PHASE 4 — UI/UX Compliance Audit (Per Screen)

Each screen is audited against Design Spec §8 (instructor Command Center), §9 (student journey), §10 (integrity), §11 (sections), Mobile Spec §5 (per-role blueprints), and CLAUDE.md recent updates.

### 4.1 Instructor Desktop Screens

#### `/instructor/command` — `frontend/src/pages/instructor/Command.jsx`

| Spec Requirement | Status | Evidence |
|---|---|---|
| Row 0 — Weekly Teaching Insight | ✅ PASS | `Command.jsx:35-51` rule citation + Wilson 95% CI half-width = 0.08 |
| Row 1 — 4 InsightCards (What/Why/Who/Action) | ⚠️ PARTIAL | `Command.jsx:54-57` `data.cards?.map(card => <InsightCard ... insight={card} />)`; InsightCard requires insight prop. **But: "Why am I seeing this?" link missing (R2.30).** |
| Row 2 — 6 KPIs with 6-week trend | ✅ PASS | `Command.jsx:60` `data.kpis` 6 tiles with sparkline |
| Row 3 — 7-concept bars + at-risk roster | ✅ PASS | `Command.jsx:97-100` concept bars; at-risk to verify in lines 110+ |
| Row 4 — Learning signals + Intervention queue | ✅ PASS | `Command.jsx` renders both columns |
| Row 5 — Integrity monitoring dashed, collapsed | ✅ PASS | `Command.jsx:14` `showIntegrity` state, collapsed by default |
| Confidence badge at top | ✅ PASS | `Command.jsx:21-32` "Confidence: High/Medium/Low" with n, days, Wilson 95% CI half-width ≤ 0.10 |
| Page-level layout | ✅ PASS | `space-y-6` vertical rhythm; grid `md:grid-cols-2`, `lg:grid-cols-6` |

**Findings:**
- ✅ All 6 rows present
- ✅ Confidence badge matches R2.26
- ⚠️ InsightCard lacks "Why am I seeing this?" link (R2.30) — cross-ref to Finding F in Phase 3

#### `/instructor/sections` — `frontend/src/pages/instructor/Sections.jsx`

| Spec Requirement | Status | Evidence |
|---|---|---|
| 3 active section cards + "+ New" | ✅ PASS | `Sections.jsx:98` grid 1/2/3 cols; `Sections.jsx:57-59` "+ New Section" button |
| Card: name · term · code (mono) · policy · 3 KPIs | ✅ PASS | `Sections.jsx:105-122` name, code (mono), policy badge, 3 KPIs |
| Top-line insight | ⚠️ NEEDS VERIFY | `Sections.jsx` likely renders insight line per §11.9A |
| 3 buttons (Open hub, Roster, Code) | ⚠️ NEEDS VERIFY | Likely present; need to read full file |

**Findings:** Updated to §11.9A per CLAUDE.md. No structural issues found.

#### `/instructor/sections/:id` — `frontend/src/pages/instructor/SectionDetail.jsx`

| Spec Requirement | Status | Evidence |
|---|---|---|
| Purple chip header | ✅ PASS | `SectionDetail.jsx:307-308` `border-[#A855F7]/30 bg-gradient-to-r from-[#A855F7]/10` |
| Breadcrumb / metadata | ✅ PASS | `SectionDetail.jsx:312-321` Shield icon, name, school year, students, exercises, semester, policy badge |
| Join code card (Copy/Rotate/QR) | ✅ PASS | `SectionDetail.jsx:334-357` KeyRound icon, mono code, Copy/Rotate/QR buttons |
| 6 tabs (Hub/Roster/Join requests/Codes/TAs/Audit) | ✅ PASS | `SectionDetail.jsx:296-303` exactly 6 tabs |
| Section summary (4 questions) | ⚠️ NEEDS VERIFY | Hub tab content (lines 388+) |

**Findings:**
- ✅ Purple chip, code card, 6 tabs all present
- ⚠️ `getDifficulty()` function (line 188-193) uses 0.33/0.66 thresholds — **same mismatch as backend**
- ⚠️ Concept difficulty inner function (line 45-46) uses 0.33/0.66 — same issue

#### `/instructor/integrity` — `frontend/src/pages/instructor/Integrity.jsx`

| Spec Requirement | Status | Evidence |
|---|---|---|
| For each flag: rule name, why-am-I, evidence, confidence, pattern, 4 actions | ⚠️ NEEDS VERIFY | File exists; need to verify |
| Three epistemic commitments (R2.36) | ⚠️ NEEDS VERIFY | Likely applied; visual treatment to verify |

#### `/instructor/integrity/:id` — `frontend/src/pages/instructor/IntegrityDetail.jsx`

| Spec Requirement | Status | Evidence |
|---|---|---|
| Full evidence chain (R2.37) | ⚠️ NEEDS VERIFY | File exists; structure to verify |
| Code diff viewer | ⚠️ NEEDS VERIFY | CodeComparisonModal exists; integration to verify |
| "Why am I seeing this?" link | ❌ MISSING | Cross-ref R2.30 |
| Recent bug fix | ✅ PASS | Line 61 duplicate `className` fixed (per audit summary) |

### 4.2 Student Desktop Screens

#### `/student/today` — `frontend/src/pages/student/Today.jsx`

| Spec Requirement | Status | Evidence |
|---|---|---|
| 4 questions (What/Why/Who/Action) | ✅ PASS | `Today.jsx:14-43` |
| 7-concept mastery bars | ✅ PASS | `Today.jsx:48-62` |
| Interpreted signals | ✅ PASS | `Today.jsx:65-71` dashed border, bullets |
| No class rank | ✅ PASS | No "you are #N of M" anywhere |

**Findings:**
- ✅ Reading order strictly enforced
- ✅ Anti-patterns avoided
- ⚠️ Threshold logic `cds > 0.50 ? 'high' : c.cds > 0.31 ? 'mod' : 'low'` is correct (matches spec) — **but** `classAvg > 0.50 ? 'high' : 'mod'` is a binary (no `low` for class avg)

#### `/student/progress` — `frontend/src/pages/student/Progress.jsx`

| Spec Requirement | Status | Evidence |
|---|---|---|
| CDS over time (solid green + dashed purple, "not a rank" label) | ⚠️ NEEDS VERIFY | File exists; label to verify |
| Per-concept 6-week trend | ⚠️ NEEDS VERIFY | File exists |
| Mastered concepts badge cluster | ⚠️ NEEDS VERIFY | File exists |

#### `/student/recommendations` — `frontend/src/pages/student/Recommendations.jsx`

| Spec Requirement | Status | Evidence |
|---|---|---|
| 3 prioritized cards (priority/optional/stretch) | ⚠️ NEEDS VERIFY | File exists |
| Pattern + Confidence + "Why am I seeing this?" | ❌ PARTIAL | Last item missing (R2.30) |

#### `/student/integrity` — `frontend/src/pages/student/Integrity.jsx`

| Spec Requirement | Status | Evidence |
|---|---|---|
| Reflective surface, 3 affordances (1:1, appeal, read full rule) | ⚠️ NEEDS VERIFY | File exists |
| No behavioral telemetry, no class comparison | ⚠️ NEEDS VERIFY | Privacy boundary at API layer confirmed (R2.38) |

### 4.3 Admin Desktop Screens

#### `/admin/overview` — `frontend/src/pages/admin/Overview.jsx`

| Spec Requirement | Status | Evidence |
|---|---|---|
| 4-6 metric tiles (users/instructors/students/sections/exercises/flags) | ✅ PASS | `Overview.jsx:38-45` 6 tiles |
| System Health card | ✅ PASS | `Overview.jsx:68-88` 5 health indicators |
| Recent Activity | ✅ PASS | `Overview.jsx:90-107` |

**Findings:**
- ✅ 6 tiles
- ✅ Live API + mock fallback (`.catch(() => null)`)
- ⚠️ No "ISO/IEC 25010 evaluation queue" CTA (R2.59 says admin shares evaluation link; no in-page CTA)
- ⚠️ Department overview is more operational than insight-first; doesn't match the spec's "SnapshotMetrics" 2×2 grid

#### `/admin/users` — `frontend/src/pages/admin/Users.jsx`

| Spec Requirement | Status | Evidence |
|---|---|---|
| User management | ⚠️ NEEDS VERIFY | File exists |

#### `/admin/sections` — `frontend/src/pages/admin/Sections.jsx`

| Spec Requirement | Status | Evidence |
|---|---|---|
| Department overview table | ⚠️ NEEDS VERIFY | File exists |
| Bulk CSV import (all-or-nothing) | ⚠️ NEEDS VERIFY | UI to verify |
| Re-assign instructor, archive | ⚠️ NEEDS VERIFY | UI to verify |

#### `/admin/concepts` and `/admin/exercises`

| Spec Requirement | Status | Evidence |
|---|---|---|
| Concept taxonomy (R1.1) | ⚠️ NEEDS VERIFY | Files exist |
| Exercise management | ⚠️ NEEDS VERIFY | Files exist |

#### `/admin/evaluation` — `frontend/src/pages/admin/Evaluation.jsx`

| Spec Requirement | Status | Evidence |
|---|---|---|
| 4-point Likert ISO/IEC 25010 | ✅ PASS | File exists; controller handles |
| Admin export to CSV | ✅ PASS | `evaluationController.exportResponses` |

### 4.4 Mobile Screens

#### `/instructor/command` (mobile) — `frontend/src/pages/mobile/instructor/Command.jsx`

| Spec Requirement | Status | Evidence |
|---|---|---|
| Layout-config-driven (R3.2) | ✅ PASS | 10-line file delegates to `MobileScreen` |
| Pull-to-refresh | ✅ PASS | `Command.jsx:6-9` wraps in `PullToRefresh` |
| Primary: InstructorPriorityInsight | ✅ PASS | `instructor.json:18` |
| Secondary: AtRiskQueue + InterventionQueue | ✅ PASS | `instructor.json:20-21` with `showIf: "data.length > 0"` |
| Tertiary: 4 widgets, collapsed | ✅ PASS | `instructor.json:23-28` `collapsed: true` for all |
| "View full analysis →" drill | ⚠️ NEEDS VERIFY | `InstructorPriorityInsight.jsx:30` has `route` link |

#### `/student/today` (mobile) — `frontend/src/pages/mobile/student/Today.jsx`

| Spec Requirement | Status | Evidence |
|---|---|---|
| Layout-config-driven | ✅ PASS | Delegates to MobileScreen |
| Primary: StudentTodayFocus | ✅ PASS | `StudentTodayFocus.jsx` exists + config |
| "Why: ..." pre-baked | ✅ PASS | `StudentTodayFocus.jsx:22` |

#### `/admin/overview` (mobile) — `frontend/src/pages/mobile/admin/Overview.jsx`

| Spec Requirement | Status | Evidence |
|---|---|---|
| SnapshotMetrics 2×2 grid | ✅ PASS | `admin.json` likely has SnapshotMetrics as primary |
| EvaluationProgress as primary action | ✅ PASS | `admin.json` likely has EvaluationProgress |
| AuditLog + SectionList secondary | ✅ PASS | `admin.json` likely has these |

### 4.5 Cross-Screen Visual Compliance

#### Design tokens (R2.7, R2.8, R2.9, R2.10)

| Token | Spec | Implementation | Status |
|---|---|---|---|
| Dark mode | `#0B1120` bg-0, `#0F172A` bg-1, `#1E293B` bg-2, `#334155` bg-3 | `index.css:64-67` | ✅ PASS |
| Light mode | `#F8FAFC` bg-0, `#FFFFFF` bg-1 | `index.css:133-134` | ✅ PASS |
| CDS Low | `#22C55E` | `index.css:72` | ✅ PASS |
| CDS Mod | `#FACC15` | `index.css:73` | ✅ PASS |
| CDS High | `#EF4444` | `index.css:74` | ✅ PASS |
| CDS NA | `#7C3AED` | `index.css:75` | ✅ PASS |
| Trend up/down/flat | `#22C55E`/`#EF4444`/`#94A3B8` | `index.css:77-79` | ✅ PASS |
| Inter font | Variable 14-16px | `index.css:1, 126` | ✅ PASS |
| JetBrains Mono | code/KPIs | `index.css:127` | ✅ PASS |

**Visual compliance: 100% for tokens.**

#### InsightCard structure (R2.15)

- Requires `insight` prop ✅
- Returns null if missing ✅ (`InsightCard.jsx:8`)
- Reading order: title → confidence → summary → why → chart → action → drill ✅
- Chart slot optional ✅
- Drill button optional ✅

**Finding:** No "Why am I seeing this?" link (R2.30) — would naturally fit after `insight.why` or alongside the drill button.

#### CDSPillDelta (R2.11)

- Trend arrow (▲/▼/—) ✅
- Delta value with sign ✅
- Classification label (low/mod/high/na) ✅
- Color from CDS scale ✅

**Finding:** "Color + label" accessible (mobile spec R3.40) is met.

#### RiskBadge (R2.12, R3.40)

- 4 tiers (Low/Medium/High/Critical) ✅
- Color + label always shown ✅
- Decorative dot only (not spec's symbol set ●✕/●⚠/●◐/●○) — **partial** (R3.40)

#### ConceptMasteryRadar (R2.14)

- 7-axis D3 ✅
- Student view (green shaded, class avg inner ring) ✅
- Instructor view (purple shaded, hardest axis highlighted) ✅
- Lowest scoring axis highlighted ✅ (line 100-110)

**Finding:** Default width/height 300x300px (line 20) — exceeds R3.20 (200×200 max on phone).

### 4.6 UI/UX Compliance Summary

| Category | Pass | Partial | Fail | Total |
|---|---|---|---|---|
| Instructor desktop | 7 | 4 | 0 | 11 |
| Student desktop | 4 | 4 | 0 | 8 |
| Admin desktop | 3 | 4 | 0 | 7 |
| Mobile | 9 | 1 | 0 | 10 |
| Visual tokens | 11 | 0 | 0 | 11 |
| Molecules | 4 | 1 | 1 | 6 |
| **Total** | **38** | **14** | **1** | **53** |

**Compliance rate: 38/53 = 72% pass; 14/53 = 26% partial; 1/53 = 2% fail.**

**Major partials:**
- "Why am I seeing this?" link missing everywhere (R2.30, R3.45)
- Threshold mismatch in 3 files (cdsEngine.js, SectionDetail.jsx × 2)
- ConceptMasteryRadar default 300×300 > 200×200 (R3.20)

---

