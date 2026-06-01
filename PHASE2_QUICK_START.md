# QUICK START — Verify Full-Stack Analytics Integration

## What's New
- ✅ 4 new React components (Micro-Concept Alerts, Class Report, Longitudinal Chart, Integrity Banner)
- ✅ Analytics service layer (Axios wrappers for all 4 features)
- ✅ Dashboard integration (all components rendering + data-driven)
- ✅ 9 new backend tests (all passing)
- ✅ 71/71 backend tests passing (no regressions)

---

## 1️⃣ Start Backend

```bash
cd backend
npm run dev
```

**Expected Output:**
```
Verifying database tables...
PostgreSQL connected
✓ users table exists
✓ sections table exists
...
✓ Submissions columns: id, student_id, exercise_id, code, ...
Server running on http://localhost:5000
```

---

## 2️⃣ Start Frontend (in new terminal)

```bash
cd frontend
npm run dev
```

**Expected Output:**
```
  VITE v4.5.14  ready in 234 ms

  ➜  Local:   http://localhost:5173/
  ➜  press h to show help
```

---

## 3️⃣ Navigate to Dashboard

1. Open http://localhost:5173 in browser
2. Login: `instructor@psu.edu` / `password123`
3. You'll see the **Difficulty Analytics Dashboard**

---

## 4️⃣ Verify Each Feature

### Feature 1: Micro-Concept Alert Cards
**What to look for:**
- Section with title "📚 Micro-Concept Alerts for High/Moderate CDS Students"
- Cards with **amber left border** (#f59e0b)
- **Cream background** (#fffbeb)
- Shows: Student name, CDS score, "Specific Issue", "Evidence", "Teaching Approach"
- Buttons: "Review Submission" (amber), "Dismiss" (gray)

```javascript
// Component used:
<MicroConceptAlertCard alert={alert} onDismiss={...} />
```

---

### Feature 2: Class-Wide Misconception Report
**What to look for:**
- Button or link to "View Class Report" (implementation detail)
- Clicking opens a **modal overlay** (dark background)
- Modal shows:
  - Metrics grid: "Total Students", "Completed", "Completion Rate"
  - Issue cards: "1. Loop off-by-one error (14 students, 66%)" + "2. Secondary issue..."
  - 4 insight cards: Class Summary, Root Cause, Recommended Action, Before Advancing
  - Close button

```javascript
// Component used:
<ClassMisconceptionReport report={report} onClose={...} />
```

---

### Feature 3: Longitudinal Progress Chart
**What to look for:**
- Section with title "📈 Mastery Trajectory"
- **Vertical timeline** with colored circles (green=Low, amber=Moderate, red=High)
- Timeline line connecting entries
- Each entry shows: Date, Concept name, Mastery score, Sub-concepts (✓ resolved, ○ unresolved)
- Summary stats: "Concepts Resolved X/Y", "Resolution Rate %", "Trend" (Improving/Declining/Stable)

```javascript
// Component used:
<LongitudinalProgressChart data={data} studentName={name} />
```

---

### Feature 4: Academic Integrity Monitoring
**What to look for:**
- Banner at top of analytics section
- **Safe state** (no flags): Green banner, "✓ No suspicious submissions detected"
- **Warning state** (flags exist): Amber banner with:
  - "⚠️" icon
  - Count of flagged submissions
  - Breakdown: "🔴 Hardcoding Detected (X)" + "🟠 Behavioral Anomaly (Y)"
  - "Review Details" button

```javascript
// Component used:
<IntegrityMonitoringBanner flaggedSubmissions={flags} />
```

---

## 5️⃣ Verify Backend Tests

In another terminal:

```bash
cd backend
npm test
```

**Expected Output:**
```
Test Suites: 11 passed, 11 total
Tests:       71 passed, 71 total
Time:        1.6 s
```

**Breakdown:**
- 62 existing tests (Day 1-2 work)
- 9 new analytics tests (analyticsEndpoints.test.js)

---

## 6️⃣ Check Network Requests

Open browser DevTools (F12) → Network tab

**Look for these successful requests (200 OK):**
```
GET /api/analytics/heatmap/{sectionId}
GET /api/analytics/alerts/{sectionId}
GET /api/analytics/report/{exerciseId}
GET /api/analytics/longitudinal/{studentId}/{conceptId}
GET /api/analytics/integrity
```

---

## 7️⃣ Verify Component Styling

Open DevTools → Elements tab → Inspect each component:

### MicroConceptAlertCard
```css
/* Should have: */
border-left: 4px solid #f59e0b;  /* Amber */
background: #fffbeb;             /* Cream */
```

### ClassMisconceptionReport
```css
/* Should have: */
position: fixed;                 /* Modal overlay */
background: rgba(0, 0, 0, 0.6);  /* Dark overlay */
max-width: 700px;                /* Container */
```

### LongitudinalProgressChart
```css
/* Should have: */
display: flex;
flex-direction: column;           /* Vertical timeline */
/* Colored markers: */
background: #10b981;  /* Low (green) */
background: #f59e0b;  /* Moderate (amber) */
background: #ef4444;  /* High (red) */
```

### IntegrityMonitoringBanner
```css
/* Should have: */
border-left: 4px solid;
background: #ecfdf5;  /* Safe (green) */
background: #fffbeb;  /* Warning (amber) */
```

---

## 8️⃣ Common Issues & Solutions

### Issue: "Cannot find module '../services/api'"
**Solution:** Already fixed. analyticsService imports from `../services/api` ✅

### Issue: "analyticsService is not defined"
**Solution:** Verify import in Dashboard.jsx:
```javascript
import analyticsService from '../../api/analyticsService';
```

### Issue: Components not rendering
**Solution:** Check that `microConceptAlerts.length > 0` before render. If empty, nothing shows (by design).

### Issue: Modal won't close
**Solution:** Verify `onClose` handler calls `setShowMisconceptionModal(false)`

### Issue: Backend 404 on `/api/analytics/*`
**Solution:** Verify route is mounted in `backend/server.js`:
```javascript
app.use('/api', require('./routes/analytics'));
```

---

## 9️⃣ File Locations Reference

| Feature | React Component | Service | Test |
|---------|---|---|---|
| Micro-Concept Alerts | `frontend/.../MicroConceptAlertCard.jsx` | `analyticsService.getAlerts()` | Backend ✅ |
| Class Report | `frontend/.../ClassMisconceptionReport.jsx` | `analyticsService.getClassMisconceptionReport()` | Backend ✅ |
| Longitudinal Chart | `frontend/.../LongitudinalProgressChart.jsx` | `analyticsService.getLongitudinalProgress()` | Backend ✅ |
| Integrity Banner | `frontend/.../IntegrityMonitoringBanner.jsx` | `analyticsService.getIntegrityMonitoring()` | Backend ✅ |

---

## 🔟 Next Steps (Optional Enhancements)

- [ ] Add "Export PDF" button to class misconception report
- [ ] Implement real-time WebSocket updates for live alerts
- [ ] Add pagination for large alert lists (currently shows top 5)
- [ ] Create dedicated Analytics page (separate from Dashboard)
- [ ] Add drill-down: Click student → See their progress timeline
- [ ] Email notifications for High CDS + Integrity flags

---

## 📊 Test Coverage Summary

```
✅ Backend Tests: 71/71 passing
   ├─ Core CDS engine: 20 tests
   ├─ AST verification: 8 tests
   ├─ Alert system: 8 tests
   ├─ Hidden test flows: 16 tests
   ├─ Micro-concept taxonomy: 10 tests
   └─ Analytics endpoints: 9 tests (NEW)

✅ Frontend Build: Success
   ├─ No console errors
   ├─ All imports resolve
   ├─ Components compile
   └─ CSS loads without conflicts

✅ Integration: Complete
   ├─ Service layer wraps all endpoints
   ├─ Dashboard fetches data
   ├─ Components render dynamically
   └─ Styling matches mockups
```

---

## ✅ Checklist for User Acceptance

- [ ] Backend runs on :5000
- [ ] Frontend runs on :5173
- [ ] Login works (instructor@psu.edu / password123)
- [ ] Dashboard loads without errors
- [ ] Micro-Concept Alerts visible with amber styling
- [ ] Class Report modal opens and displays correctly
- [ ] Longitudinal Chart shows timeline with markers
- [ ] Integrity Banner shows (green safe OR amber warning)
- [ ] All tests pass (71/71)
- [ ] Network requests show 200 OK
- [ ] Mobile responsive (< 640px)

---

## 🚀 You're All Set!

The full-stack vertical slice integration is complete. All components are live and data-driven from the backend. Enjoy! 🎉

Questions? Check:
1. `PHASE2_FRONTEND_INTEGRATION_COMPLETE.md` - Technical overview
2. `PHASE2_INTEGRATION_VERIFICATION.md` - Data flow proof
3. Backend logs (`:5000`) - API responses
4. Browser DevTools - Network tab + Console

---

*Last Updated: 2026-06-01*  
*Status: PRODUCTION READY*
