# CodeInsight Design System v1.0

**Status:** Active. Reference for all frontend work.
**Last updated:** 2026-06-06.
**Applies to:** Every component, every page, every commit. No exceptions.

---

## 0. The Rule

Every page follows one hierarchy, in this order:

> **Primary Insight → Primary Action → Supporting Evidence → Details**

If a component does not serve one of those four purposes on its page, it is removed. There is no other reason for a component to exist.

The **Primary Insight** is one sentence that answers the user's single decision on this page. The **Primary Action** is the one button that resolves it. **Supporting Evidence** is 1–4 metric chips that justify urgency. **Details** is everything else, below the fold.

---

## 1. Aesthetic Direction

**"Refined Operational Density"** — Linear meets a Bloomberg terminal meets Vercel's deploy-status discipline. Restraint, precision, high signal-to-noise. The product is a coding education analytics platform; the visual language is an instrument panel, not a marketing surface.

**Distinguishing choices:**
- `font-variant-numeric: tabular-nums` on every number, always.
- `font-feature-settings: "ss01", "cv11"` for Inter stylistic alternates — subtly distinctive, never decorative.
- `tracking-tighter` on display sizes; `leading-[1.1]` on hero numbers.
- Borders over shadows; one shadow elevation reserved for floating UI (menus, dialogs).
- Single accent (`--primary` teal). Used sparingly. Never for status; status uses semantic colors.
- `strokeWidth={1.5}` on lucide icons (technical, not playful).

**Banned:**
- `backdrop-blur-*` (no glassmorphism).
- `bg-gradient-to-*` except brand logos and empty-state illustrations.
- `shadow-2xl` on flat data.
- `text-[8px]…text-[11px]` (minimum 12px).
- `bg-[#hex]`, `text-[#hex]`, `border-[#hex]` (use tokens).
- `rounded-2xl`+ on functional cards.
- `font-bold` (use `font-semibold`; Inter at 700 reads heavy on UI).
- Color-only status (always pair with text label or icon).
- `window.alert` / `window.confirm` (use `sonner` toast / `Dialog`).
- Emoji as functional UI icons (decorative in empty states is fine).

---

## 2. Typography

**Base:** `Inter` (sans), `JetBrains Mono` (code/numerics). Both already loaded in `src/index.css`.

| Token | Class | Size / Line | Use |
|---|---|---|---|
| `display-xl` | `text-3xl font-semibold tracking-tight` | 30/36 | Page hero title |
| `display-lg` | `text-2xl font-semibold tracking-tight` | 24/32 | Section hero, modal title |
| `title` | `text-lg font-semibold tracking-tight` | 18/26 | Card header, dialog title |
| `subtitle` | `text-sm font-medium` | 14/20 | List group label, table header |
| `body` | `text-sm` | 14/20 | Default copy, table cell |
| `body-strong` | `text-sm font-medium` | 14/20 | KPI value, name in row |
| `caption` | `text-xs` | 12/16 | Helper text, metadata, axis label |
| `overline` | `text-[10px] font-semibold uppercase tracking-wider` | 10/16 | Section label, badge text |
| `code` | `font-mono text-[13px] leading-snug` | 13/18 | Inline code, CDS value |

**Numerics:** `font-mono tabular-nums` for any value that should align column-wise (CDS scores, percentages, timestamps, counts). Always.

**Pairs (always use these, never raw `text-white`/`text-black`):**
- `text-foreground` on `bg-background`
- `text-muted-foreground` on `bg-background` (secondary)
- `text-card-foreground` on `bg-card`
- `text-primary-foreground` on `bg-primary`
- `text-destructive-foreground` on `bg-destructive`

**Floor rule:** never render below 12px. Codemod target: every `text-[8px]…text-[11px]` → `text-xs`.

---

## 3. Spacing

**4px base.** Layout rhythm uses multiples of 4. Component padding uses multiples of 2. There are no other spacing values.

| Token | Tailwind | Use |
|---|---|---|
| `space-1` | `p-1` / `gap-1` | 4px — micro icon-to-text |
| `space-2` | `p-2` / `gap-2` | 8px — tight stack |
| `space-3` | `p-3` / `gap-3` | 12px — list-item vertical pad |
| `space-4` | `p-4` / `gap-4` | 16px — card padding (default) |
| `space-5` | `p-5` / `gap-5` | 20px — spacious card (dashboards) |
| `space-6` | `p-6` / `gap-6` | 24px — section gap |
| `space-8` | `p-8` / `gap-8` | 32px — page-level block gap |
| `space-12` | `p-12` / `gap-12` | 48px — empty-state padding |

**Container width:** `max-w-7xl mx-auto px-4 sm:px-6 lg:px-8`.
**Page vertical rhythm:** `space-y-8` between sections; `space-y-6` between cards inside a section; `space-y-2` between sibling elements inside a card.
**Card internal padding:** `p-4` (default) or `p-5` (dashboards, hero).

---

## 4. Border Radius

| Token | Class | Value | Use |
|---|---|---|---|
| `radius-sm` | `rounded` | 4px | Table inner controls, code chip |
| `radius-md` | `rounded-md` | 6px | Inputs, buttons, small badges |
| `radius-lg` | `rounded-lg` | 8px | Cards, popovers, dialogs |
| `radius-xl` | `rounded-xl` | 12px | Hero card, empty-state container |
| `radius-full` | `rounded-full` | 9999px | Avatar, pill badge, status dot |

**Rule:** interactive = `rounded-md`. Container = `rounded-lg`. Never `rounded-2xl`+ on functional cards.

---

## 5. Shadow

| Token | Class | Use |
|---|---|---|
| `shadow-xs` | `shadow-[0_1px_2px_0_rgb(0_0_0_/_0.04)]` | Sidebar, sticky header |
| `shadow-sm` | `shadow-sm` | Default card, popover |
| `shadow-md` | `shadow-md` | Dialog, dropdown, command palette |
| `shadow-lg` | `shadow-lg` | Modal, sheet, focused overlay |

**Dark mode:** prefer `border` over `shadow`. A single border is more readable than a soft drop shadow on a dark surface.

**Card border is mandatory:** `border border-border`. Never `shadow-md` without a border.

---

## 6. Color Tokens

Layered: **base** (defined in `index.css`) → **semantic** (status) → **domain** (CDS, integrity).

### Base (existing)
`background`, `foreground`, `card`, `card-foreground`, `card-border`, `popover`, `popover-border`, `primary`, `primary-foreground`, `secondary`, `secondary-foreground`, `muted`, `muted-foreground`, `accent`, `accent-foreground`, `destructive`, `destructive-foreground`, `border`, `input`, `ring`, `chart-1…5`, `sidebar-*`.

### Semantic status (added)
`success`, `success-foreground`, `warning`, `warning-foreground`, `info`, `info-foreground`.

### Domain (added)
`cds-low`, `cds-mod`, `cds-high`, `cds-na`, `trend-up`, `trend-down`, `trend-flat`.

### Paired Tailwind classes
| Purpose | Class |
|---|---|
| Page bg | `bg-background text-foreground` |
| Card | `bg-card text-card-foreground border border-border` |
| Popover | `bg-popover text-popover-foreground border border-popover-border shadow-md` |
| Success badge | `bg-success/10 text-success border border-success/20` |
| Warning badge | `bg-warning/10 text-warning-foreground border border-warning/20` |
| Destructive | `bg-destructive/10 text-destructive border border-destructive/20` |
| Info | `bg-info/10 text-info-foreground border border-info/20` |
| CDS low | `bg-cds-low/10 text-cds-low border border-cds-low/20` |
| CDS high | `bg-cds-high/10 text-cds-high border border-cds-high/20` |
| Focus ring | `focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring focus-visible:ring-offset-2 focus-visible:ring-offset-background` |

**Tailwind utility for status chip (reusable):**
```
inline-flex items-center gap-1.5 px-2 py-0.5 rounded-full text-[11px] font-medium
  + {variant classes}
```

---

## 7. Card Patterns

### 7.1 Default card
```
bg-card text-card-foreground border border-border rounded-lg shadow-sm p-4 sm:p-5
```
Header row: `flex items-center justify-between gap-3 pb-3 mb-3 border-b border-border`.
Title: `text-sm font-semibold`. Eyebrow: `text-[10px] font-semibold uppercase tracking-wider text-muted-foreground mb-1`.

### 7.2 KPI card
```
bg-card text-card-foreground border border-border rounded-lg shadow-sm p-5
  flex flex-col gap-3
    div flex items-center justify-between
      p text-[10px] font-semibold uppercase tracking-wider text-muted-foreground
      lucide icon h-3.5 w-3.5 text-muted-foreground strokeWidth={1.5}
    div flex items-baseline gap-2
      p text-2xl font-semibold font-mono tabular-nums tracking-tight leading-[1.1]
      span text-xs font-medium px-1.5 py-0.5 rounded-md (trend chip)
    p text-xs text-muted-foreground (vs. last period)
    div h-12 mt-1 (sparkline, w-full)
```

### 7.3 Hero card
```
bg-card text-card-foreground border border-border rounded-xl p-6 sm:p-8
```

### 7.4 Inset / nested card
```
bg-muted/40 border border-border rounded-md p-3
```

---

## 8. Table Patterns

Wrap in `rounded-lg border border-border bg-card overflow-hidden`.
```jsx
<table class="w-full text-sm">
  <thead class="border-b border-border bg-muted/40">
    <tr><th class="h-9 px-3 text-left text-xs font-medium text-muted-foreground">Header</th></tr>
  </thead>
  <tbody>
    <tr class="border-b border-border last:border-0 hover:bg-muted/40 transition-colors">
      <td class="px-3 py-2.5 align-middle text-sm">Cell</td>
    </tr>
  </tbody>
</table>
```

- Numeric cell: `font-mono tabular-nums` + `text-right`.
- Identity cell: `flex items-center gap-3` + avatar (`h-7 w-7 rounded-full bg-muted text-xs font-semibold flex items-center justify-center`).
- Status cell: `inline-flex items-center gap-1.5 px-2 py-0.5 rounded-full text-[11px] font-medium` + colored dot.
- Row actions: appear on hover (`opacity-0 group-hover:opacity-100`), icon buttons `h-7 w-7 rounded-md text-muted-foreground hover:bg-muted hover:text-foreground`.

---

## 9. Form Patterns

### 9.1 Input
```
flex h-9 w-full rounded-md border border-input bg-card px-3 py-1 text-sm
text-foreground placeholder:text-muted-foreground
focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring focus-visible:ring-offset-2 focus-visible:ring-offset-background
disabled:cursor-not-allowed disabled:opacity-50
```

### 9.2 Label
```
text-sm font-medium leading-none text-foreground mb-1.5 block
```
Required: `<span class="text-destructive ml-0.5">*</span>`.

### 9.3 Helper
```
mt-1.5 text-xs text-muted-foreground
```

### 9.4 Field group
```
flex flex-col gap-1.5
```

### 9.5 Form section
```
space-y-6
  div space-y-4
    h3 text-sm font-semibold
    p text-xs text-muted-foreground
    div space-y-4
```

---

## 10. Navigation Patterns

### 10.1 Sidebar (desktop)
`w-60` (240px) desktop, drawer on mobile.
```
hidden lg:flex w-60 shrink-0 flex-col border-r border-sidebar-border bg-sidebar text-sidebar-foreground
  div h-14 px-4 border-b border-sidebar-border flex items-center (logo + product)
  nav flex-1 overflow-y-auto p-2
    div space-y-1 (groups)
      h3 px-2.5 py-1.5 text-[10px] font-semibold uppercase tracking-wider text-sidebar-foreground/50
      div space-y-0.5
        Item: flex items-center gap-2.5 rounded-md px-2.5 py-1.5 text-sm font-medium
              text-sidebar-foreground/70 hover:bg-sidebar-accent hover:text-sidebar-accent-foreground
              active:bg-sidebar-accent active:text-sidebar-foreground
              lucide icon h-4 w-4 shrink-0 strokeWidth={1.5}
              optional kbd (cmd shortcut)
              optional Badge (count, ml-auto)
  div p-3 border-t border-sidebar-border (user menu)
```

### 10.2 Bottom nav (mobile)
```
fixed bottom-0 inset-x-0 z-40 border-t border-border bg-background lg:hidden
  grid grid-cols-5 h-16
    Item: flex flex-col items-center justify-center gap-1 text-[10px] font-medium
          text-muted-foreground aria-[current=page]:text-foreground
          lucide icon h-5 w-5 strokeWidth={1.5}
          label
```

### 10.3 Top bar
`h-14 border-b border-border bg-background` (no glass). Left: breadcrumb. Center: search trigger (desktop only). Right: notification, theme toggle, avatar menu.

### 10.4 Breadcrumb
```
flex items-center gap-1.5 text-sm text-muted-foreground
  a hover:text-foreground transition-colors
  ChevronRight h-3.5 w-3.5
  span text-foreground font-medium (current)
```

### 10.5 Tabs
`border-b border-border` with `h-10` tab buttons, `text-sm font-medium`. Active: `border-b-2 border-foreground -mb-px`.

---

## 11. Dashboard Composition

### 11.1 Page shell
```
min-h-screen bg-background text-foreground
  Sidebar (desktop) | Sheet (mobile)
  div flex-1 flex flex-col min-w-0
    Topbar
    main flex-1 overflow-y-auto
      div max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-6 sm:py-8
        div space-y-8
          PageHeader
          InsightHeader
          EvidenceRow
          (Details sections)
```

### 11.2 Page header
```
flex flex-col sm:flex-row sm:items-end sm:justify-between gap-4
  div
    h1 text-2xl font-semibold tracking-tight
    p mt-1 text-sm text-muted-foreground
  div flex items-center gap-2
    (SectionFilter, PeriodSelector, primary action)
```

### 11.3 KPI grid
`grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-4 gap-4`.

### 11.4 Chart card
```
bg-card text-card-foreground border border-border rounded-lg shadow-sm
  Header h-12 px-5 flex items-center justify-between border-b border-border
    div flex items-center gap-3
      h3 text-sm font-semibold
      (period segmented control)
    Button size=sm variant=ghost (Export)
  Body p-5 h-64
```

### 11.5 Empty state (EATS)
Container: `flex flex-col items-center justify-center text-center py-16 px-6 rounded-xl border border-dashed border-border bg-card/50`.
- Symbol: `h-10 w-10 rounded-full bg-muted flex items-center justify-center text-muted-foreground` + lucide icon.
- Title: `text-sm font-semibold mt-4`.
- Description: `text-sm text-muted-foreground mt-1 max-w-sm`.
- Action: `mt-6` primary button.
- Footnote: `mt-2 text-xs text-muted-foreground`.

### 11.6 Loading
Use `<Skeleton>` from `components/ui/skeleton.jsx`. Card skeleton: outer card + 3 stacked `h-4 w-{X}` bars.

### 11.7 Inline feedback
Use `sonner` toast. Position `top-right`.

---

## 12. Responsive

| Surface | Mobile | Tablet | Desktop |
|---|---|---|---|
| Sidebar | Sheet | Collapsed rail (60px) | Fixed `w-60` |
| Bottom nav | Fixed `h-16` | Hidden | Hidden |
| Topbar search | Hidden (⌘K) | Visible | Visible |
| Page padding | `px-4` | `px-6` | `px-6 lg:px-8` |
| KPI grid | 1 col | 2 col | 4 col |
| Tables | Card list | Condensed | Full table |
| Code editor | Tabs | 2-pane | 3-pane resizable |
| Modal/Drawer | Full-screen sheet | Right drawer | Centered dialog |
| Command palette | Bottom sheet | Centered | Centered |

**Mobile table → card list:** at `<md`, each row becomes a stacked card:
```
rounded-lg border bg-card p-4 space-y-2
  div flex items-center justify-between text-sm
    span text-muted-foreground (label)
    span (value)
```

---

## 13. Motion

| Use | Class | Duration |
|---|---|---|
| Color transitions | `transition-colors` | 150ms |
| Opacity in/out | `transition-opacity` | 150ms |
| Layout (panel resize) | `transition-all` | 200ms |
| Skeleton pulse | built-in | 2s |

Easing: default Tailwind. Never `ease-bounce` on functional UI. Respect `prefers-reduced-motion` (Tailwind v4 prefixes `motion-safe:` / `motion-reduce:`).

---

## 14. Accessibility (every screen)

- [ ] Exactly one `<h1>` per page.
- [ ] Every status badge pairs color with text or icon.
- [ ] Every interactive element has a visible focus ring.
- [ ] Sidebar nav uses `aria-current="page"` on active.
- [ ] Tables have `<caption>` or `aria-label`.
- [ ] Empty states have `role="status"`.
- [ ] Toasts use `aria-live="polite"`.
- [ ] Modal/Drawer traps focus + returns focus on close (Radix default).
- [ ] Color contrast ≥ 4.5:1 body, ≥ 3:1 large text.
- [ ] Touch targets ≥ 44×44px on mobile.
- [ ] No keyboard traps.
- [ ] Skip-to-content link in `Layout.jsx`.

---

## 15. Components (canonical inventory)

### 15.1 Base (shadcn/ui primitives — in `components/ui/`)
`alert-dialog`, `alert`, `avatar`, `badge`, `button`, `card`, `checkbox`, `dialog`, `dropdown-menu`, `input`, `label`, `popover`, `progress`, `scroll-area`, `select`, `separator`, `sheet`, `skeleton`, `switch`, `table`, `tabs`, `textarea`, `tooltip`.

### 15.2 Domain components (in `components/ui/`)
| Component | Purpose | Status |
|---|---|---|
| `InsightHeader` | Top-of-page: eyebrow + insight + 1 primary action | **NEW** |
| `EvidenceRow` | 1–4 KPI chips supporting the insight | **NEW** |
| `KPIChartCard` | KPI value + delta + sparkline + period | **NEW** |
| `EmptyState` | EATS formula container | **NEW** |
| `DecisionList` | Ranked actionable list with multi-select | **NEW** |
| `DetailDrawer` | Slide-in panel for atomic drilldown | **NEW** |
| `PageBreadcrumb` | Context for non-landing pages | **NEW** |
| `CommandPalette` | ⌘K global search | **NEW** |
| `PeriodSelector` | 7d / 30d / 90d segmented control | **NEW** |
| `RiskBadge` | Semantic token-driven | **REWRITE** |
| `CDSPillDelta` | Token-driven | **REWRITE** |
| `PageHeader` | Page-level title + actions | **NEW** |

### 15.3 Feature components (preserve)
- `Sidebar.jsx`, `Layout.jsx`, `MobileChrome.jsx`
- `SectionFilter.jsx` (used by 8 instructor pages)
- `analytics/IntegrityMonitoringBanner.jsx` (theme via CSS file)
- `analytics/ClassMisconceptionReport.jsx` (theme via CSS file)
- All `mobile/*` components

---

## 16. Implementation Order

| Week | Focus | Deliverable |
|---|---|---|
| 1 | Foundation + 4 reference pages | Tokens, 4 critical components, redesigned `instructor/Dashboard`, `student/CodeEditor`, `student/Today`, `instructor/Integrity` |
| 2 | Instructor suite | `SectionDetail` split, `StudentDetail`, `Sections`, `Exercises`, `Reports`, ⌘K palette, breadcrumb, mobile sheet sidebar |
| 3 | Student + admin + mobile | All remaining student pages, all admin pages, mobile mirrors, BottomNav a11y |
| 4 | Polish | axe-core pass, empty states, loading pass, Storybook (optional), visual regression, perf |

---

## 17. Acceptance Gates (every page)

A page is "shipped" only when:
1. Linear Test: Q1–Q5 all pass.
2. Hierarchy: Insight → Action → Evidence → Details, in that order, top to bottom.
3. Token purity: no arbitrary hex, no `text-[<12px]`, no glass, no `rounded-2xl`+.
4. A11y: 12-point checklist (§14) passes.
5. Responsive: passes Linear Test at 360px, 768px, 1024px, 1440px.
6. Build: `npm run build` clean, `npm run lint` clean.
