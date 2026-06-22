# Admin Controls Overhaul Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Transform the admin from mostly view-only to full platform administrator with user/section/concept CRUD, integrity oversight, configurable system settings, and audit trail coverage.

**Architecture:** Backend additions (routes, controllers, DB migrations) plus frontend pages and component wiring. Each task is independently testable and commitable.

**Tech Stack:** Node/Express backend, PostgreSQL, React frontend with shadcn/ui, Joi validation.

## Global Constraints

- All new mutations must log to a new `admin_audit_log` table (Task 7 requirement, but plan table creation now)
- All new API endpoints go under `backend/routes/admin.js` unless cross-cutting (config lives standalone)
- Follow existing patterns: `adminController.method > route > validator > frontend API call`
- Frontend pages use components from `@/components/ui/*` (card, button, dialog, badge, input, select)
- No new npm packages; use what's already in the codebase (Joi, bcryptjs, date-fns, lucide-react)
- Every new API endpoint must have a Joi validator where applicable
- 117/117 backend tests must still pass after all changes
- Frontend build must pass after all changes

---

### Task 1: Admin sidebar navigation

**Files:**
- Modify: `frontend/src/components/Sidebar.jsx` (lines 34-48 for links, line 56 for role check, line 100 for label)

**Interfaces:**
- Consumes: existing `useAuth()` for `user.role`
- Produces: admin sidebar links visible when `user.role === 'admin'`

**Context:** Currently `Sidebar.jsx:56` falls through to `studentLinks` for admins (admin !== instructor), so admins see "My Exercises", "My Progress", "My Profile" — none point to any admin page.

- [ ] **Step 1: Add adminLinks array before export**

Insert after `instructorLinks` (line 42) and before `export default function Sidebar()`:
```jsx
const adminLinks = [
  { to: '/admin',                label: 'Overview',    icon: LayoutDashboard, end: true },
  { to: '/admin/users',          label: 'Users',       icon: Users },
  { to: '/admin/sections',       label: 'Sections',    icon: ListChecks },
  { to: '/admin/concepts',       label: 'Concepts',    icon: Code },
  { to: '/admin/exercises',      label: 'Exercises',   icon: PlusSquare },
  { to: '/admin/evaluation',     label: 'Evaluation',  icon: TrendingUp },
  { to: '/admin/audit',          label: 'Audit Log',   icon: ShieldAlert },
];
```

Also add `Code` to the icon imports from `lucide-react` at the top.

- [ ] **Step 2: Update role-to-links mapping (line 56)**

Change:
```jsx
const links = user?.role === 'instructor' ? instructorLinks : studentLinks;
```
To:
```jsx
const links = user?.role === 'admin' ? adminLinks
  : user?.role === 'instructor' ? instructorLinks
  : studentLinks;
```

- [ ] **Step 3: Update role label in sidebar header (line 100)**

Change:
```jsx
{user?.role === 'instructor' ? 'Instructor' : 'Student'}
```
To:
```jsx
{user?.role === 'admin' ? 'Admin'
  : user?.role === 'instructor' ? 'Instructor'
  : 'Student'}
```

- [ ] **Step 4: Verify frontend builds**

Run: `npm run build --prefix frontend 2>&1 | tail -5`
Expected: `✓ built in <time>`

- [ ] **Step 5: Commit**

```bash
git add frontend/src/components/Sidebar.jsx && git commit -m "feat(admin): add admin sidebar navigation links"
```

---

### Task 2: Fix concept edit (dead Edit3 button)

**Files:**
- Modify: `backend/controllers/adminController.js` (add `updateConcept`)
- Modify: `backend/routes/admin.js` (add PUT route)
- Modify: `backend/lib/validators.js` (add `adminConceptUpdate`)
- Modify: `frontend/src/pages/admin/Concepts.jsx` (wire edit dialog)

**Interfaces:**
- Consumes: `PUT /api/admin/concepts/:id` (new endpoint)
- Produces: functional edit dialog pre-filled with concept data

**Context:** `Concepts.jsx:185` renders an `<Edit3 />` button with no `onClick` handler. Backend has no PUT endpoint for concepts.

- [ ] **Step 1: Add concept update validator**

In `backend/lib/validators.js`, after `adminConceptCreate`:
```js
const adminConceptUpdate = Joi.object({
  name: Joi.string().trim().min(1).max(100).optional(),
  ast_nodes: Joi.array().items(Joi.string()).optional(),
  knowledge_area_code: Joi.string().trim().max(20).optional().allow('', null),
  bloom_level: Joi.string().valid('remember', 'understand', 'apply', 'analyze', 'evaluate', 'create').optional(),
});
```
Add to module.exports: `adminConceptUpdate`

- [ ] **Step 2: Add updateConcept controller**

In `backend/controllers/adminController.js`, after `deleteConcept`:
```js
exports.updateConcept = async (req, res, next) => {
  try {
    const { id } = req.params;
    const { name, ast_nodes, knowledge_area_code, bloom_level } = req.body;
    const r = await db.query(
      `UPDATE concepts SET name=COALESCE($1,name), ast_nodes=COALESCE($2,ast_nodes),
       knowledge_area_code=COALESCE($3,knowledge_area_code), bloom_level=COALESCE($4,bloom_level)
       WHERE id=$5 RETURNING *`,
      [name??null, ast_nodes??null, knowledge_area_code??null, bloom_level??null, id]
    );
    if (!r.rows.length) throw new AppError('Concept not found', 404, codes.NOT_FOUND);
    res.json({ concept: r.rows[0] });
  } catch (err) { next(err); }
};
```

- [ ] **Step 3: Add route**

In `backend/routes/admin.js`, after `router.delete('/concepts/:id', ...)`:
```js
router.put('/concepts/:id', validate.params(v.idParam), validate.body(v.adminConceptUpdate), ctrl.updateConcept);
```

- [ ] **Step 4: Wire edit button + dialog in Concepts.jsx**

Add state: `const [editTarget, setEditTarget] = useState(null);`

Replace line 185's dead button:
```jsx
<Button variant="ghost" size="sm" className="h-6 w-6 p-0" onClick={() => setEditTarget(c)}><Edit3 className="h-3 w-3" /></Button>
```

Add edit dialog before closing `</div>`:
```jsx
<Dialog open={!!editTarget} onOpenChange={open => !open && setEditTarget(null)}>
  <DialogContent>
    <DialogHeader><DialogTitle>Edit concept</DialogTitle></DialogHeader>
    {editTarget && <EditConceptForm concept={editTarget} onSaved={()=>{setEditTarget(null);load();}} onError={setError} />}
  </DialogContent>
</Dialog>
```

Add EditConceptForm component (inline at bottom of file, before or after default export):
```jsx
function EditConceptForm({ concept, onSaved, onError }) {
  const [name,setName]=useState(concept.name);
  const [astNodes,setAstNodes]=useState((concept.ast_nodes||[]).join(', '));
  const [knowledgeArea,setKnowledgeArea]=useState(concept.knowledge_area_code||'');
  const [bloomLevel,setBloomLevel]=useState(concept.bloom_level||'apply');
  const [busy,setBusy]=useState(false);
  const handleSubmit=async e=>{e.preventDefault();setBusy(true);try{
    const payload={name};
    payload.ast_nodes=astNodes.split(',').map(s=>s.trim()).filter(Boolean);
    if(knowledgeArea)payload.knowledge_area_code=knowledgeArea;
    if(bloomLevel)payload.bloom_level=bloomLevel;
    await api.put(`/api/admin/concepts/${concept.id}`,payload);onSaved();
  }catch(err){onError(err.response?.data?.message||err.message)}finally{setBusy(false)}};
  return (<form onSubmit={handleSubmit} className="space-y-3">
    <div className="space-y-1"><Label>Name</Label><Input value={name} onChange={e=>setName(e.target.value)} required/></div>
    <div className="space-y-1"><Label>Knowledge Area</Label>
      <Select value={knowledgeArea} onValueChange={setKnowledgeArea}>
        <SelectTrigger><SelectValue placeholder="Select area (optional)"/></SelectTrigger>
        <SelectContent>
          <SelectItem value="SDF-FPC">SDF-FPC (Fundamentals)</SelectItem>
          <SelectItem value="SDF-FDS">SDF-FDS (Data Structures)</SelectItem>
          <SelectItem value="SDF-PMD">SDF-PMD (Program Design)</SelectItem>
          <SelectItem value="SDF-OOP">SDF-OOP (Object-Oriented)</SelectItem>
        </SelectContent>
      </Select>
    </div>
    <div className="space-y-1"><Label>Bloom Level</Label>
      <Select value={bloomLevel} onValueChange={setBloomLevel}>
        <SelectTrigger><SelectValue/></SelectTrigger>
        <SelectContent>{Object.entries(BLOOM_LABELS).map(([k,v])=><SelectItem key={k} value={k}>{v}</SelectItem>)}</SelectContent>
      </Select>
    </div>
    <div className="space-y-1"><Label>AST nodes (comma separated)</Label>
      <Input value={astNodes} onChange={e=>setAstNodes(e.target.value)} placeholder="if_statement, switch_statement"/>
    </div>
    <DialogFooter><Button type="submit" disabled={busy}>{busy?'Saving...':'Save'}</Button></DialogFooter>
  </form>);
}
```

- [ ] **Step 5: Verify frontend builds**

Run: `npm run build --prefix frontend 2>&1 | tail -5`
Expected: `✓ built in <time>`

- [ ] **Step 6: Commit**

```bash
git add backend/controllers/adminController.js backend/lib/validators.js backend/routes/admin.js frontend/src/pages/admin/Concepts.jsx && git commit -m "feat(admin): add concept edit endpoint and frontend dialog"
```

---

### Task 3: Section update/delete frontend

**Files:**
- Modify: `frontend/src/pages/admin/Sections.jsx`

**Interfaces:**
- Consumes: `PUT /api/admin/sections/:id` and `DELETE /api/admin/sections/:id` (already exist)
- Produces: inline edit dialog and delete confirmation for section rows

- [ ] **Step 1: Add imports** (Edit3, Trash2, Label, Select components, useEffect)

- [ ] **Step 2: Add state variables** (editTarget, editName, editCode, editYear, editTerm, editPolicy, editMaxSize, busy)

- [ ] **Step 3: Add deleteSection and sectionUpdate handlers** (use api.delete / api.put)

- [ ] **Step 4: Add useEffect to populate form when editTarget changes**

- [ ] **Step 5: Add Actions column header and edit/delete buttons per row**

- [ ] **Step 6: Add edit section Dialog**

- [ ] **Step 7: Verify build** and commit

---

### Task 4: Admin password reset

**Files:**
- Modify: `backend/controllers/adminController.js` (add `resetPassword`)
- Modify: `backend/routes/admin.js` (add PUT route)
- Modify: `backend/lib/validators.js` (add `adminPasswordReset`)
- Modify: `frontend/src/pages/admin/Users.jsx` (add reset password dialog)

- [ ] **Step 1: Add validator** `adminPasswordReset = Joi.object({ password: Joi.string().min(8).max(128).required() })`

- [ ] **Step 2: Add `resetPassword` controller** — bcrypt hash + UPDATE

- [ ] **Step 3: Add route** `router.put('/users/:id/reset-password', ...)`

- [ ] **Step 4: Add reset password UI to Users.jsx** — read existing Users.jsx, add dialog with new password + confirm

- [ ] **Step 5: Verify tests + build**

- [ ] **Step 6: Commit**

---

### Task 5: Exercise archive/flag for admins

**Files:**
- Modify: `backend/controllers/adminController.js` (add `toggleExercise`)
- Modify: `backend/routes/admin.js` (add PATCH route)
- Modify: `frontend/src/pages/admin/Exercises.jsx` (add close/reopen toggle button)

- [ ] **Step 1: Add `toggleExercise` controller** — sets `closed_at` to NOW or NULL

- [ ] **Step 2: Add route** `router.patch('/exercises/:id', ...)`

- [ ] **Step 3: Add toggle button to Exercises.jsx** — call PATCH with `{ closed: true/false }`

- [ ] **Step 4: Verify tests + build**

- [ ] **Step 5: Commit**

---

### Task 6: Flag review dashboard

**Files:**
- Create: `frontend/src/pages/admin/Flags.jsx`
- Modify: `frontend/src/App.jsx` (add route + import)
- Modify: `frontend/src/components/Sidebar.jsx` (add link)
- Modify: `backend/controllers/adminController.js` (add `listFlags`, `updateFlag`)
- Modify: `backend/routes/admin.js` (add GET/PATCH endpoints)

- [ ] **Step 1: Add listFlags + updateFlag controllers** — query integrity_flags with joins, update status

- [ ] **Step 2: Add routes** `GET /api/admin/flags`, `PATCH /api/admin/flags/:id`

- [ ] **Step 3: Create Flags.jsx page** — filter by status/type, list with severity badges, resolve/dismiss buttons, expandable evidence

- [ ] **Step 4: Wire in App.jsx + Sidebar**

- [ ] **Step 5: Verify tests + build**

- [ ] **Step 6: Commit**

---

### Task 7: Admin action audit trail

**Files:**
- Create: `backend/migrations/20260620_admin_audit_log.js`
- Modify: `backend/controllers/adminController.js` (add helper + instrument all mutations)
- Modify: `backend/routes/admin.js` (add GET audit-log endpoint)

- [ ] **Step 1: Create migration** — `CREATE TABLE admin_audit_log (id SERIAL, admin_id, action, target_type, target_id, details JSONB, created_at)`

- [ ] **Step 2: Add `addAuditLog()` helper function** at top of adminController.js

- [ ] **Step 3: Instrument all mutation endpoints** (createUser, updateUser, deleteUser, resetPassword, updateSection, deleteSection, createConcept, updateConcept, deleteConcept, toggleExercise, updateFlag)

- [ ] **Step 4: Add GET /admin/audit-log endpoint**

- [ ] **Step 5: Run migration, verify tests**

- [ ] **Step 6: Commit**

---

### Task 8: System configuration (CDS thresholds + sandbox settings)

**Files:**
- Create: `backend/migrations/20260620_system_settings.js`
- Create: `backend/controllers/adminConfigController.js`
- Create: `backend/routes/adminConfig.js`
- Create: `frontend/src/pages/admin/Settings.jsx`
- Modify: `frontend/src/App.jsx` (add route)
- Modify: `frontend/src/components/Sidebar.jsx` (add link)
- Modify: `backend/app.js` (wire new route file)

- [ ] **Step 1: Create migration** — system_settings(key PK, value JSONB, description, updated_at, updated_by), seed defaults (ner/nrs/nts weights, classification thresholds, sandbox timeout/memory)

- [ ] **Step 2: Create adminConfigController** — listSettings, updateSettings (with audit logging)

- [ ] **Step 3: Create adminConfig routes** — `GET /api/admin/settings`, `PUT /api/admin/settings`

- [ ] **Step 4: Wire into backend app.js** — `app.use('/api/admin', require('./routes/adminConfig'))`

- [ ] **Step 5: Create Settings.jsx** — editable key-value list grouped by category, save per row

- [ ] **Step 6: Wire in App.jsx + Sidebar**

- [ ] **Step 7: Run migration, verify build**

- [ ] **Step 8: Commit**

---

### Task 9: Final verification

- [ ] **Step 1: Run full backend tests** — `cd backend && npm test`

- [ ] **Step 2: Run frontend build** — `npm run build --prefix frontend`

- [ ] **Step 3: Run migrations** — `cd backend && node migrations.js`

- [ ] **Step 4: Push to origin** — `git push origin CodeInsight-V2`
