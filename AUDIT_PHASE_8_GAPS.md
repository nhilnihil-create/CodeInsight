## PHASE 8 — Gap Analysis & Risk Ranking

Consolidates all gaps from Phases 3-7, ranked by defense risk.

### 8.1 Critical (Block Defense)

#### GAP-01 — CDS Classification Threshold Mismatch (R4.11)
- **Files:** `backend/services/cdsEngine.js:8-10`, `frontend/src/pages/instructor/SectionDetail.jsx:45-46, 188-193`, `backend/controllers/sectionController.js:62-64, 180-185`
- **Spec:** Low (0.00–0.31), Mod (0.31–0.50), High (0.50–0.66)
- **Code:** Low (0–0.33), Mod (0.33–0.66), High (>0.66)
- **Defense risk:** **CRITICAL.** A committee member comparing the code to Chapter 1 / CLAUDE.md / Design §2.2 will find this mismatch in 5 minutes. The defense will lose credibility if the spec says "0.31" and the code says "0.33."
- **Fix effort:** 1 hour. Update 5 files; rerun tests; verify visual consistency.
- **Recommendation:** Fix before defense. Non-negotiable.

#### GAP-02 — `section_audit_log` Not DB-Level Append-Only (R2.44)
- **Files:** `backend/migrations/007-add-section-memberships.sql:21-34`
- **Spec:** "Append-only at the DB level (no `UPDATE` or `DELETE` granted to the application role)" (Design §1.3, §11.5)
- **Code:** Migration creates the table with no `REVOKE UPDATE, DELETE` statement.
- **Defense risk:** **CRITICAL.** The defense script will likely say "the audit log is append-only at the DB level." If a committee member asks "show me the GRANT/REVOKE statement," the answer is "we forgot to add it." This is a defense-credibility killer.
- **Fix effort:** 30 minutes. Add `REVOKE UPDATE, DELETE ON section_audit_log FROM codeuser;` to migration 007.
- **Recommendation:** Fix before defense. The spec is the source of truth.

#### GAP-03 — Race-Join Without `SELECT ... FOR UPDATE` (R2.48)
- **Files:** `backend/controllers/sectionController.js:209-231` (`joinSection`)
- **Spec:** "Atomic check + insert via `SELECT ... FOR UPDATE` on the section row" (Design §11.8)
- **Code:** Plain `SELECT * FROM sections WHERE code=$1` then `INSERT INTO enrollments` without locking.
- **Defense risk:** **HIGH.** This is a concurrency vulnerability. If 60 students race-join at `max_size=60`, the boundary is off-by-one. The committee may not stress this, but if a test demonstrates it, the section-management thesis is undermined.
- **Fix effort:** 30 minutes. Wrap the join in a transaction with `SELECT ... FOR UPDATE`.
- **Recommendation:** Fix before defense.

### 8.2 High (Strongly Recommend Fix)

#### GAP-04 — Leave Request Flow Not Implemented (R2.43)
- **Files:** `backend/controllers/sectionController.js:246-257` (`updateMembership`)
- **Spec:** 4-state leave flow (`leave_requested` → `leave_acknowledged` or `leave_declined` → revert to `active`)
- **Code:** Only `status === 'dropped'` is handled. Leave flow not implemented.
- **Defense risk:** **HIGH.** The leave/drop asymmetry is a registrar-style design decision; missing it weakens the section-management narrative.
- **Fix effort:** 3-4 hours. Add 3 PATCH handlers; update front-end SectionDetail Roster tab; update mock data.
- **Recommendation:** Fix before defense if time allows; otherwise document as "deferred to v2" (matches Design §11.2 cut list).

#### GAP-05 — Bulk CSV Import Not Transactional (R2.49, §17.6)
- **Files:** `backend/controllers/sectionController.js:259-276` (`bulkImport`)
- **Spec:** All-or-nothing with annotated error CSV (Design §11.9G, §17.6)
- **Code:** `bulkImport` accepts `emails` array (not CSV file); no transaction wrap; partial imports possible.
- **Defense risk:** **HIGH.** §17.6 acceptance criterion is FAIL. The committee will likely test bulk import.
- **Fix effort:** 4-6 hours. CSV parser + transactional wrap + error annotation.
- **Recommendation:** Fix before defense. Or: defer to v2 with explicit cut-list note.

#### GAP-06 — "Why am I seeing this?" Affordance Missing (R2.30, R3.45)
- **Files:** `frontend/src/components/InsightCard.jsx`, `InterventionCard.jsx`, `IntegrityFlagBadge.jsx`, `FlagEvidence`
- **Spec:** "Every insight card, every InterventionCard, every signal row, every flag has a 'Why am I seeing this?' link" (Design §8.7)
- **Code:** No component implements this modal/link.
- **Defense risk:** **HIGH.** This is the "trust engine" — the design's stated UX pattern for explaining insights. Missing it makes the system feel opaque.
- **Fix effort:** 6-8 hours. Modal component + data structure + integration.
- **Recommendation:** Fix before defense, OR document as "deferred to defense Q&A presentation."

#### GAP-07 — `section_memberships` Table Exists But Is Unused
- **Files:** Migration 007 creates `section_memberships`; `sectionController.js` still uses `enrollments`
- **Spec:** R2.46 demands `section_memberships` with role/status enums, soft delete
- **Code:** Migration created the table; controller does not use it.
- **Defense risk:** **MEDIUM-HIGH.** A committee member asking "where is the role/status enum" will find the table exists but is empty. Wasted migration.
- **Fix effort:** 8-12 hours. Migrate data from `enrollments` to `section_memberships`; update all controllers.
- **Recommendation:** Defer to v2 with explicit note. The cut list is large enough that this is acceptable.

#### GAP-08 — `logPassiveBehavior` Is a Stub (R1.17)
- **Files:** `backend/services/academicIntegrityEngine.js:270-285`
- **Spec:** "Passive Behavioral Logging — keeps track of how many times you switch between browser tabs and paste things during a coding session" (Ch.1:385-389)
- **Code:** Returns submission unchanged; no DB column; no actual capture.
- **Defense risk:** **HIGH.** The capstone Chapter 1 explicitly mentions this as a feature. The code is a no-op.
- **Fix effort:** 12-16 hours. Add columns to submissions; capture in frontend; wire in backend.
- **Recommendation:** Document as "out of scope for v1" if committee asks. The "tab switches" feature is named in the paper but not central to the CDS thesis contribution. CLAUDE.md already lists this as a known gap.

### 8.3 Medium (Nice to Fix)

#### GAP-09 — D3 Static Import in Mobile (R3.21, R3.34)
- **Files:** `frontend/src/components/ConceptMasteryRadar.jsx:2`
- **Spec:** D3 must be dynamic-imported behind `mode !== 'mobile' AND render === 'full'`
- **Code:** Static `import * as d3 from 'd3'`
- **Defense risk:** **MEDIUM.** This violates the mobile spec's bundle target. If the committee asks about mobile performance, the answer is "we did not optimize the bundle yet."
- **Fix effort:** 2-3 hours. Convert to `lazy()` and conditional import.
- **Recommendation:** Fix; small effort, high payoff for mobile credibility.

#### GAP-10 — Bundle Target Unmeasured (R3.32)
- **Files:** No CI config; no bundle analyzer
- **Spec:** Initial JS bundle ≤200KB gzipped for 3 top-level mobile routes
- **Code:** CLAUDE.md reports 1.15MB total JS (likely minified, not gzipped).
- **Defense risk:** **MEDIUM.** If committee asks about mobile performance, no measured number is available.
- **Fix effort:** 1-2 hours. Add `vite-plugin-bundle-analyzer`; run on 3 routes; report.
- **Recommendation:** Measure and report; if >200KB, defer with note.

#### GAP-11 — Code Growth Threshold Mismatch (R1.16)
- **Files:** `backend/services/academicIntegrityEngine.js:241`
- **Spec:** "Sudden growth spike of more than 30% in a single attempt" (Ch.1:382-384)
- **Code:** `growthPercent > 100 && lineDelta > 10`
- **Defense risk:** **MEDIUM.** Same threshold-mismatch pattern as GAP-01. Committee may spot it.
- **Fix effort:** 5 minutes. Change `100` to `30`.
- **Recommendation:** Fix.

#### GAP-12 — CI Lint Rule Missing (R2.17)
- **Files:** No ESLint custom rule in repo
- **Spec:** "CI lint rule (frontend): no `<CDSPill>` without an adjacent `<InsightText>`"
- **Defense risk:** **LOW.** "Learning Insights Language" is enforced by code review convention. A lint rule is a nice-to-have.
- **Fix effort:** 3-4 hours.
- **Recommendation:** Skip; document as future work.

#### GAP-13 — `MobileScreen` Doesn't Use `LayoutConfigProvider` (Spec §2.2)
- **Files:** `frontend/src/pages/mobile/MobileScreen.jsx:73` uses `getConfig(role, 'mobile')` directly
- **Spec:** "`<LayoutConfigProvider role={user.role}>`" (Spec §2.1)
- **Code:** Direct function call, no React Context provider.
- **Defense risk:** **LOW.** Functionally equivalent.
- **Fix effort:** 1 hour.
- **Recommendation:** Skip; functionally equivalent.

#### GAP-14 — ConceptMasteryRadar Default Size 300×300 (R3.20)
- **Files:** `frontend/src/components/ConceptMasteryRadar.jsx:20`
- **Spec:** Phone never D3 SVG >200×200
- **Code:** Default `width=300, height=300`
- **Defense risk:** **LOW.** Mobile components pass smaller dimensions; default is for desktop.
- **Fix effort:** 5 minutes. Add `MAX_MOBILE_SIZE = 200` enforcement.
- **Recommendation:** Fix; trivial.

#### GAP-15 — Swipe Gestures Missing (R3.25)
- **Files:** `AtRiskQueue.jsx`, `IntegrityFlagList.jsx`
- **Spec:** Swipe-left=snooze, swipe-right=approve
- **Code:** Not implemented.
- **Defense risk:** **LOW.** Pull-to-refresh works; swipe is incremental.
- **Fix effort:** 4-6 hours.
- **Recommendation:** Skip; defer to v2.

#### GAP-16 — `SectionList` Mobile Mode Has Prop Mismatch
- **Files:** `components/mobile/AtRiskQueue.jsx:36` uses `level={row.risk}`; mobile primitive `RiskBadge` uses `level` ✅
- **Spec:** Naming canon (R3.29)
- **Code:** Mobile primitive correctly uses `level`; desktop uses `tier` (different prop name).
- **Defense risk:** **LOW.** Two coexisting primitives is acceptable.
- **Fix effort:** 0 (already correct).
- **Recommendation:** No action.

#### GAP-17 — Tablet+Desktop Configs Alias to Mobile (R3.3)
- **Files:** `frontend/src/config/useLayoutConfig.js:10-14`
- **Spec:** Tablet and desktop configs required
- **Code:** Both alias to mobile config.
- **Defense risk:** **LOW.** Tablet+desktop use the desktop pages (not mobile), so the config aliasing is theoretical.
- **Fix effort:** 2-3 hours.
- **Recommendation:** Skip; defense won't stress tablet+.

### 8.4 Low (Optional / Cosmetic)

#### GAP-18 — RiskBadge Symbol Set Decorative Only (R3.40)
- Mobile primitive `RiskBadge.jsx:4` shows ●✕/●⚠/●◐/●○ symbols correctly.
- Desktop `RiskBadge.jsx` shows only colored dot.
- **Defense risk:** **LOW.** Mobile is correct; desktop variant is fine.
- **Fix effort:** 0 (mobile is correct).
- **Recommendation:** No action.

#### GAP-19 — K-tier ImpactTag Not Yet Wired to UI
- `backend/lib/impactTag.js` exists; not yet shown in any UI.
- **Defense risk:** **LOW.** Not in defense script.
- **Fix effort:** 2-3 hours.
- **Recommendation:** Skip; not in defense script.

#### GAP-20 — N=4 on Foldable (Spec says 3) (R3.14)
- Spec test says foldable should produce N=3; formula gives N=4.
- **Defense risk:** **VERY LOW.** Test case not in defense.
- **Fix effort:** 30 minutes (adjust constants).
- **Recommendation:** Skip.

#### GAP-21 — Drop Reason Not Required at API Layer
- `updateMembership` accepts `dropReason` but does not require it.
- Spec §11.4: "Reason required? **Yes** — short note"
- **Defense risk:** **LOW.**
- **Fix effort:** 15 minutes.
- **Recommendation:** Fix; trivial.

#### GAP-22 — K-anonymity / Sample Size Threshold (R2.27)
- Spec §8.3: "Insights disabled for this section — too few students for stable CIs."
- Code: Not yet wired.
- **Defense risk:** **LOW.**
- **Fix effort:** 2 hours.
- **Recommendation:** Skip; defense demo will use a populated section.

### 8.5 Defense Risk Matrix

| Severity | Gap Count | Defense Blocker? |
|---|---|---|
| CRITICAL | 3 | YES — fix before defense |
| HIGH | 5 | Strongly recommend fix |
| MEDIUM | 6 | Nice to fix |
| LOW | 8 | Skip |
| **Total** | **22** | |

### 8.6 Top 10 Issues (for defense Q&A preparation)

1. **GAP-01 — CDS threshold mismatch (0.31 vs 0.33)** — committee will spot this; fix in 1h
2. **GAP-02 — `section_audit_log` not DB-level append-only** — defense claim is false; fix in 30min
3. **GAP-03 — Race-join without `FOR UPDATE`** — concurrency vulnerability; fix in 30min
4. **GAP-08 — `logPassiveBehavior` is a stub** — Ch.1 feature is no-op; document as v2 deferral
5. **GAP-05 — Bulk CSV not transactional** — §17.6 fail; defer to v2 with note
6. **GAP-06 — "Why am I seeing this?" missing** — trust engine is gone; defer or implement
7. **GAP-04 — Leave flow not implemented** — registrar pattern incomplete; defer to v2
8. **GAP-11 — Code Growth threshold 100% vs 30%** — fix in 5min
9. **GAP-07 — `section_memberships` table unused** — wasted migration; defer to v2
10. **R2.16 — `summary` field on all analytics endpoints** — partial; verify and document

### 8.7 Effort Estimate to Reach Defense-Ready

| Priority | Items | Total Effort |
|---|---|---|
| Fix all CRITICAL | GAP-01, GAP-02, GAP-03 | ~2 hours |
| Fix all HIGH (defensible) | GAP-11, GAP-21, GAP-14 | ~30 minutes |
| Document deferrals (HIGH) | GAP-04, GAP-05, GAP-06, GAP-07, GAP-08 | 1-2 hours (cut-list doc) |
| Skip (acceptable as-is) | GAP-09, GAP-10, GAP-12-22 | 0 hours |
| **Total to "defense ready"** | | **4-5 hours** |

**After 5 hours of focused work, the system is at the "defensible" tier. The remaining gaps are explicitly deferrable per the design spec's cut list (Design §15).**

---

