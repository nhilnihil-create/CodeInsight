# Analytics Components — Dark Theme Color Scheme

## 🎨 Overview
All new analytics components (Phase 2) have been updated to match CodeInsight's **dark theme** color palette from `/frontend/src/index.css`.

---

## 🌈 Core Color Palette

### Dark Theme Variables (from :root)
```css
--bg: #0c1220              /* Primary background */
--surface: #131d30         /* Surface layers */
--s2: #1a2640              /* Secondary surface */
--border: #1e304d          /* Border color */
--amber: #fbbf24           /* Status: Moderate/Warning */
--green: #4ade80           /* Status: Low/Safe */
--red: #f87171             /* Status: High/Danger */
--text: #dce8f5            /* Primary text */
--muted: #6a85a8           /* Muted/secondary text */
--teal: #85D2D0            /* Accent (primary buttons) */
```

---

## 📊 Component Color Mappings

### 1️⃣ MicroConceptAlertCard
**Purpose:** Per-student feedback alerts for High/Moderate CDS students

| Element | Color | Variable | Purpose |
|---------|-------|----------|---------|
| Background | `rgba(251, 191, 36, 0.05)` | Amber 5% opacity | Subtle alert background |
| Left Border | `#fbbf24` | --amber | Indicates Moderate/Alert status |
| Text (Primary) | `#dce8f5` | --text | Headers, titles |
| Text (Secondary) | `#a1aebd` | Muted variant | Content, descriptions |
| Buttons (Review) | `#fbbf24` → `#f59e0b` | --amber + darker hover | Call-to-action |
| Buttons (Dismiss) | `#1e304d` | --border | Secondary action |

**Visual Reference:**
```
┌─────────────────────────────┐ ← #1e304d border left
│ Student Name: Maria         │ ← --text
│ Exercise: Sum of 1 to N     │ ← Muted text
├─────────────────────────────┤ ← #1e304d divider
│ Specific Issue: Loop Error  │ ← --text
│ Evidence: Line 12...        │ ← Muted text
│ Teaching Approach: ...      │ ← Muted text
├─────────────────────────────┤ ← #1e304d divider
│ [Review] [Dismiss]          │ ← Amber + Border buttons
└─────────────────────────────┘
```

---

### 2️⃣ ClassMisconceptionReport
**Purpose:** Class-wide misconception patterns (modal overlay)

| Element | Color | Variable | Purpose |
|---------|-------|----------|---------|
| Modal Background | `#131d30` | --surface | Main container |
| Modal Border | `#1e304d` | --border | Subtle edge definition |
| Header Background | Gradient #1a2640→#131d30 | --s2→--surface | Visual hierarchy |
| Header Text | `#dce8f5` | --text | Clear readability |
| Metric Cards | `#1a2640` | --s2 | Data container |
| Metric Values | `#fbbf24` | --amber | Highlight numbers |
| Primary Issue | `rgba(251, 191, 36, 0.05)` | Amber 5% opacity | Primary issue highlight |
| Primary Border | `#fbbf24` | --amber | Primary accent |
| Secondary Issue | `rgba(16, 185, 129, 0.05)` | Green 5% opacity | Secondary highlight |
| Insight Cards | `#1a2640` | --s2 | Content containers |
| Recommendation Cards | `rgba(16, 185, 129, 0.05)` | Green 5% opacity | Positive action |
| Close Button | `#85D2D0` | --teal | Primary action color |

**Visual Reference:**
```
╔═══════════════════════════════════╗
║ Class Misconception Report    [×] ║ ← Header gradient
║ Exercise: Sum of 1 to N           ║ ← --text
╠═══════════════════════════════════╣
│ ┌─────────────┐ ┌─────────────┐  │
│ │ Total:    21│ │ Completed: 14│ ← #1a2640 cards
│ │ Completion %│ │  66%        │ ← #fbbf24 values
│ └─────────────┘ └─────────────┘  │
├───────────────────────────────────┤
│ 1. Loop off-by-one error (14 stu) ← Amber background
│ 2. Missing increment (6 stu)      ← Green background
├───────────────────────────────────┤
│ 📊 Class Summary: [text]          │ ← --muted text
│ 💡 Root Cause: [text]             │
│ 📝 Recommended Action: [text]     │
│ ✓ Before Advancing: [text]        │ ← Green accent
├───────────────────────────────────┤
│                          [Close]  │ ← --teal button
╚═══════════════════════════════════╝
```

---

### 3️⃣ LongitudinalProgressChart
**Purpose:** Student mastery trajectory timeline

| Element | Color | Variable | Purpose |
|---------|-------|----------|---------|
| Background | `#131d30` | --surface | Container |
| Border | `#1e304d` | --border | Edge definition |
| Title Text | `#dce8f5` | --text | Header |
| Label Text | `#6a85a8` | --muted | Metadata |
| Summary Stats | `#0c1220` | --bg | Stat boxes |
| Stat Values | `#fbbf24` | --amber | Highlight data |
| Timeline Line | Gradient #85D2D0→#1e304d | --teal→--border | Visual flow |
| Marker (Low) | `#4ade80` | --green | Low difficulty |
| Marker (Moderate) | `#fbbf24` | --amber | Moderate difficulty |
| Marker (High) | `#ef4444` | --red | High difficulty |
| Concept Info | `#1a2640` | --s2 | Content cards |
| Concept Tags (Resolved) | `rgba(74, 222, 128, 0.1)` | Green 10% | Completed status |
| Concept Tags (Unresolved) | `rgba(248, 113, 113, 0.1)` | Red 10% | Pending status |

**Visual Reference:**
```
Timeline Markers:
● Green (#4ade80) = Low CDS / Mastered
● Amber (#fbbf24) = Moderate CDS / In Progress
● Red (#ef4444) = High CDS / Struggling

2026-04-01 ● Datatypes       Low (0.92)     ✓ Resolved
           │ └─ I/O ✓, Variables ✓
           │
2026-04-08 ● Loops          High (0.28)     ○ Unresolved
           │ └─ Init ○, Increment ○, Termination ○
           │
           └─

Concepts Resolved: 1/2 (50%)
Trend: 📉 Declining
```

---

### 4️⃣ IntegrityMonitoringBanner
**Purpose:** Academic integrity status banner

| Element | Color | Variable | Purpose |
|---------|-------|----------|---------|
| Safe Background | `rgba(16, 185, 129, 0.05)` | Green 5% opacity | Good status |
| Safe Border | `#4ade80` | --green | Positive indicator |
| Warning Background | `rgba(251, 191, 36, 0.05)` | Amber 5% opacity | Alert status |
| Warning Border | `#fbbf24` | --amber | Warning indicator |
| Title Text | `#dce8f5` | --text | Main message |
| Message Text | `#a1aebd` | Muted variant | Details |
| Flag Badges | `#1e304d` | --border | Flag containers |
| Hardcoding Flag | `#f87171` | --red | Red flag |
| Anomaly Flag | `#fbbf24` | --amber | Amber warning |
| Review Button | `#fbbf24` → `#f59e0b` | --amber + hover | Call-to-action |

**Visual Reference:**
```
SAFE STATE:
┌─────────────────────────────┐
│ ✓ No suspicious submissions │ ← Green border
│   detected this session.    │ ← Green background (5% opacity)
└─────────────────────────────┘

WARNING STATE:
┌──────────────────────────────────┐
│ ⚠️ 2 submission(s) flagged       │ ← Amber border
│    for manual review             │ ← Amber background (5% opacity)
│                                  │
│ 🔴 Hardcoding Detected (2)       │ ← Red text
│ 🟠 Behavioral Anomaly (1)        │ ← Amber text
│                        [Review]  │ ← Amber button
└──────────────────────────────────┘
```

---

## 📐 Consistency Rules

### Text Hierarchy
```
PRIMARY TEXT (Headings, Important):    #dce8f5 (--text)
SECONDARY TEXT (Labels, Details):      #a1aebd (--muted variant)
MUTED TEXT (Meta, Timestamps):         #6a85a8 (--muted)
```

### Background Layering
```
LEVEL 1 (Main bg):        #0c1220 (--bg)
LEVEL 2 (Containers):     #131d30 (--surface)
LEVEL 3 (Nested):         #1a2640 (--s2)
LEVEL 4 (Modals):         #131d30 (--surface)
```

### Status Indicators
```
LOW (Success/Good):       #4ade80 (--green) / #10b981
MODERATE (Warning):       #fbbf24 (--amber)
HIGH (Danger/Alert):      #f87171 or #ef4444 (--red)
ACCENT (Primary action):  #85D2D0 (--teal)
```

### Opacity for Highlights
```
5% opacity:   Subtle background (rgba(color, 0.05))
10% opacity:  Medium background (rgba(color, 0.1))
20% opacity:  Strong background (rgba(color, 0.2))
Solid:        Borders and text
```

---

## ✅ Verified Compatibility

- [x] Dark theme (primary use case)
- [x] All components render correctly on #131d30 background
- [x] Text readability AA/AAA contrast ratios met
- [x] Mobile responsive (640px breakpoint)
- [x] No light theme "flashing" on load
- [x] Consistent with existing Dashboard styling
- [x] Production build succeeds: 358 KB gzipped

---

## 🔄 If Updating Colors

1. **Update CSS files** (not component JSX):
   - `MicroConceptAlertCard.css`
   - `ClassMisconceptionReport.css`
   - `LongitudinalProgressChart.css`
   - `IntegrityMonitoringBanner.css`

2. **Test in dark mode**: `npm run dev` and visually inspect

3. **Verify build**: `npm run build` should complete without errors

4. **Check contrast**: Use WebAIM contrast checker for text/background pairs

---

## 📝 Notes

- All components use **CSS variables** from `:root` in `/index.css` where possible
- Fallback colors are hard-coded for specific states (e.g., badge colors)
- No hardcoded light theme colors remain in analytics components
- Components are fully responsive and work on all screen sizes

---

*Last Updated: 2026-06-01*  
*Status: Dark Theme Complete ✅*
