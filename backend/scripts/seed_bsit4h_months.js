/**
 * Seed: BSIT-4H "ran for months" analytics demo
 *
 * Populates ONE section as if the system had been running for ~3 months:
 *   • Section "BSIT - 4H" (instructor: instructor@psu.edu)
 *   • 24 students across 7 performance personas (top → never-correct + flagged)
 *   • 13 weekly exercises across the concept taxonomy (the six most recent
 *     weeks are Procedural Fundamentals so the default concept-mastery tab is
 *     populated; all four knowledge-area groups are covered, several
 *     multi-tagged)
 *   • Per-student submission histories with realistic attempt counts, pass/fail
 *     progressions, on-time/late/missing mixes, and behavioral telemetry
 *   • Integrity flags (hardcoding / code paste / blank template) on specific
 *     weeks, including one in the current week so the dashboard flags KPI
 *     lights up
 *   • CDS scores derived from each persona's profile (base difficulty ×
 *     learning-curve × concept difficulty + jitter) with backdated computed_at
 *     so the daily trend, weekly concept-mastery chart, heatmap, completion
 *     report, integrity timeline, student profiles, and at-risk roster all show
 *     months of history. Snapshots + High-CDS alerts are written to mirror the
 *     batch engine's outputs.
 *
 * Deterministic: fixed PRNG seed → identical data on every run. Idempotent:
 * re-running wipes and rebuilds only this section's data.
 *
 * Run:
 *   node scripts/seed_bsit4h_months.js
 */
require('dotenv').config({ path: __dirname + '/../.env', quiet: true });
const { Pool } = require('pg');
const bcrypt = require('bcryptjs');
const { classify } = require('../services/cdsEngine');

const pool = new Pool({
  host: process.env.DB_HOST || 'localhost',
  port: process.env.DB_PORT || '5432',
  database: process.env.DB_NAME || 'codeinsight',
  user: process.env.DB_USER || 'codeuser',
  password: process.env.DB_PASSWORD || 'codepassword123',
});

const SECTION_NAME = 'BSIT - 4H';
const COURSE_CODE = 'CS1234';
const PASSWORD = 'password123';

// ── Deterministic PRNG (fixed seed → byte-identical data every run) ──────────
function mulberry32(a) {
  return function () {
    a |= 0;
    a = (a + 0x6D2B79F5) | 0;
    let t = Math.imul(a ^ (a >>> 15), 1 | a);
    t = (t + Math.imul(t ^ (t >>> 7), 61 | t)) ^ t;
    return ((t ^ (t >>> 14)) >>> 0) / 4294967296;
  };
}
const rnd = mulberry32(17082026);
const rand = (min, max) => min + Math.floor(rnd() * (max - min + 1));
const pick = (arr) => arr[Math.floor(rnd() * arr.length)];
const clamp = (v, lo, hi) => Math.min(hi, Math.max(lo, v));

const DAY_MS = 24 * 60 * 60 * 1000;
const now = new Date();
function dayOffset(days, h = 12, m = 0, s = 0) {
  const d = new Date(now.getTime() - days * DAY_MS);
  d.setHours(h, m, s, 0);
  return d;
}

// ── 24 student personas ─────────────────────────────────────────────────────
// maria / jose / ana already exist in the schema seed — the script upserts
// them by email, so their password (password123) is unchanged.
const PERSONAS = [
  // Group A — Top: 1 attempt, correct, fast
  { name: 'Angel Cruz', email: 'angel.cruz@psu.edu', group: 'A' },
  { name: 'Mark Villanueva', email: 'mark.villanueva@psu.edu', group: 'A' },
  { name: 'Sarah Dimagiba', email: 'sarah.dimagiba@psu.edu', group: 'A' },
  // Group B — Good
  { name: 'Kevin Santos', email: 'kevin.santos@psu.edu', group: 'B' },
  { name: 'Patricia Reyes', email: 'patricia.reyes@psu.edu', group: 'B' },
  { name: 'Daniel Torres', email: 'daniel.torres@psu.edu', group: 'B' },
  { name: 'Jessica Alvarez', email: 'jessica.alvarez@psu.edu', group: 'B' },
  // Group C — Average
  { name: 'Marco Gonzales', email: 'marco.gonzales@psu.edu', group: 'C' },
  { name: 'Angela Bautista', email: 'angela.bautista@psu.edu', group: 'C' },
  { name: 'Ramon Dela Cruz', email: 'ramon.delacruz@psu.edu', group: 'C' },
  { name: 'Catherine Lim', email: 'catherine.lim@psu.edu', group: 'C' },
  { name: 'Josefina Ramos', email: 'josefina.ramos@psu.edu', group: 'C' },
  // Group D — Struggling
  { name: 'Michael Garcia', email: 'michael.garcia@psu.edu', group: 'D' },
  { name: 'Isabella Flores', email: 'isabella.flores@psu.edu', group: 'D' },
  { name: 'Roberto Mendoza', email: 'roberto.mendoza@psu.edu', group: 'D' },
  { name: 'Carmen Navarro', email: 'carmen.navarro@psu.edu', group: 'D' },
  // Group E — Very struggling
  { name: 'Antonio Lopez', email: 'antonio.lopez@psu.edu', group: 'E' },
  { name: 'Gloria Hernandez', email: 'gloria.hernandez@psu.edu', group: 'E' },
  // Group F — Never got it right
  { name: 'Pedro Ramirez', email: 'pedro.ramirez@psu.edu', group: 'F' },
  // Group G — Integrity-flagged
  { name: 'Luisa Mercado', email: 'luisa.mercado@psu.edu', group: 'G' },
  // Existing students (schema seed) — enrolled so the student side demos too
  { name: 'Maria Reyes', email: 'maria@student.psu.edu', group: 'B' },
  { name: 'Jose Santos', email: 'jose@student.psu.edu', group: 'C' },
  { name: 'Ana Lim', email: 'ana@student.psu.edu', group: 'A' },
  { name: 'Nihil Hiza', email: 'nihil19@gmail.com', group: 'C' },
];

// base CDS is the persona's long-run difficulty (higher = struggling). curve is
// [start, end] multiplier from the oldest to the newest week: capable students
// improve over the semester, struggling students get worse.
const GROUPS = {
  A: { base: 0.08, attemptsMin: 1, attemptsMax: 1, correctProb: 1.0,  timeMin: 40,  timeMax: 100, pasteMin: 0, pasteMax: 1,  tabMin: 0,  tabMax: 2,  misses: 0, lateProb: 0.0,  curve: [1.10, 0.70] },
  B: { base: 0.22, attemptsMin: 1, attemptsMax: 2, correctProb: 0.95, timeMin: 60,  timeMax: 150, pasteMin: 1, pasteMax: 2,  tabMin: 0,  tabMax: 3,  misses: 0, lateProb: 0.10, curve: [1.05, 0.80] },
  C: { base: 0.45, attemptsMin: 2, attemptsMax: 4, correctProb: 0.80, timeMin: 90,  timeMax: 240, pasteMin: 2, pasteMax: 5,  tabMin: 1,  tabMax: 5,  misses: 1, lateProb: 0.30, curve: [1.00, 0.95] },
  D: { base: 0.66, attemptsMin: 3, attemptsMax: 6, correctProb: 0.55, timeMin: 150, timeMax: 360, pasteMin: 4, pasteMax: 8,  tabMin: 2,  tabMax: 8,  misses: 2, lateProb: 0.50, curve: [0.95, 1.10] },
  E: { base: 0.82, attemptsMin: 6, attemptsMax: 9, correctProb: 0.30, timeMin: 200, timeMax: 480, pasteMin: 6, pasteMax: 12, tabMin: 4,  tabMax: 12, misses: 3, lateProb: 0.70, curve: [0.90, 1.20] },
  F: { base: 0.93, attemptsMin: 5, attemptsMax: 8, correctProb: 0.0,  timeMin: 180, timeMax: 420, pasteMin: 8, pasteMax: 15, tabMin: 6,  tabMax: 15, misses: 4, lateProb: 0.85, curve: [0.95, 1.25] },
  G: { base: 0.45, attemptsMin: 2, attemptsMax: 3, correctProb: 0.75, timeMin: 60,  timeMax: 180, pasteMin: 1, pasteMax: 3,  tabMin: 0,  tabMax: 4,  misses: 1, lateProb: 0.30, curve: [1.00, 1.00] },
};

// Per-concept difficulty offset (CDS = difficulty; pointers/recursion harder)
const CONCEPT_DIFF = {
  1: -0.02,  // Datatypes
  2: -0.02,  // Variables
  3: 0.00,   // Conditionals
  4: 0.02,   // Loops
  5: 0.03,   // Functions
  6: 0.04,   // Arrays
  7: 0.08,   // OOP
  8: 0.10,   // Pointers
  9: 0.02,   // Strings
  10: -0.04, // Input/Output
  12: 0.04,  // Scope
  13: 0.00,  // Enums
  15: 0.00,  // Switch/Case
  16: 0.06,  // Nested Loops
  18: 0.10,  // Dynamic Memory
  21: 0.03,  // Type Casting
};

// ── 13 weekly exercises ──────────────────────────────────────────────────────
// The six most recent weeks (weeksAgo 5..0) are Procedural Fundamentals so the
// default "Concept mastery · Procedural Fundamentals" tab is populated; the
// older weeks cover the other knowledge-area groups for breadth.
function tc(input, expected, hidden = false) {
  return { input, expected_output: expected, isVisible: !hidden, validationType: 'exact', hidden };
}

const STARTER = `#include <iostream>\nusing namespace std;\nint main() {\n  // write code here\n  return 0;\n}`;

const EXERCISES = [
  {
    weeksAgo: 12, conceptId: 3, title: 'Lab 01 — Even or Odd', timeLimit: 30,
    description: 'Read an integer and print "even" or "odd".',
    tests: [tc('4', 'even'), tc('7', 'odd'), tc('0', 'even', true)],
    correct: '#include <iostream>\nusing namespace std;\nint main() {\n  int n; cin >> n;\n  cout << (n % 2 == 0 ? "even" : "odd");\n  return 0;\n}',
    wrong: '#include <iostream>\nusing namespace std;\nint main() {\n  int n; cin >> n;\n  cout << (n % 2 == 0 ? "odd" : "even");\n  return 0;\n}',
    hardcoded: '#include <iostream>\nusing namespace std;\nint main() {\n  cout << "even";\n  return 0;\n}',
  },
  {
    weeksAgo: 11, conceptId: 15, title: 'Lab 02 — Grade Switch', timeLimit: 35,
    description: 'Read a letter grade A-E and print "Excellent"/"Good"/"Fair"/"Poor"/"Fail".',
    tests: [tc('A', 'Excellent'), tc('C', 'Fair'), tc('E', 'Fail', true)],
    correct: '#include <iostream>\nusing namespace std;\nint main() {\n  char g; cin >> g;\n  switch (g) {\n    case \'A\': cout << "Excellent"; break;\n    case \'B\': cout << "Good"; break;\n    case \'C\': cout << "Fair"; break;\n    case \'D\': cout << "Poor"; break;\n    default: cout << "Fail";\n  }\n  return 0;\n}',
    wrong: '#include <iostream>\nusing namespace std;\nint main() {\n  char g; cin >> g;\n  cout << "Excellent";\n  return 0;\n}',
    hardcoded: '#include <iostream>\nusing namespace std;\nint main() {\n  cout << "Excellent";\n  return 0;\n}',
  },
  {
    weeksAgo: 10, conceptId: 4, title: 'Lab 03 — Sum of N Numbers', timeLimit: 35,
    description: 'Read N then N integers; print their sum.',
    tests: [tc('3 1 2 3', '6'), tc('4 10 20 30 40', '100'), tc('2 -5 5', '0', true)],
    correct: '#include <iostream>\nusing namespace std;\nint main() {\n  int n, x, s = 0; cin >> n;\n  for (int i = 0; i < n; i++) { cin >> x; s += x; }\n  cout << s;\n  return 0;\n}',
    wrong: '#include <iostream>\nusing namespace std;\nint main() {\n  int n, x, s = 0; cin >> n;\n  for (int i = 0; i < n; i++) { cin >> x; }\n  cout << s;\n  return 0;\n}',
    hardcoded: '#include <iostream>\nusing namespace std;\nint main() {\n  cout << "6";\n  return 0;\n}',
    secondary: [{ conceptId: 16, weight: 0.5 }], // Nested Loops
  },
  {
    weeksAgo: 9, conceptId: 6, title: 'Lab 04 — Array Maximum', timeLimit: 35,
    description: 'Read N then N integers; print the maximum value.',
    tests: [tc('5 3 1 4 1 5', '5'), tc('3 10 20 15', '20', true)],
    correct: '#include <iostream>\nusing namespace std;\nint main() {\n  int n, mx; cin >> n;\n  int a[100];\n  for (int i = 0; i < n; i++) cin >> a[i];\n  mx = a[0];\n  for (int i = 1; i < n; i++) if (a[i] > mx) mx = a[i];\n  cout << mx;\n  return 0;\n}',
    wrong: '#include <iostream>\nusing namespace std;\nint main() {\n  int n; cin >> n;\n  int a[100];\n  for (int i = 0; i < n; i++) cin >> a[i];\n  cout << a[n-1];\n  return 0;\n}',
    hardcoded: '#include <iostream>\nusing namespace std;\nint main() {\n  cout << "5";\n  return 0;\n}',
    secondary: [{ conceptId: 8, weight: 0.4 }], // Pointers
  },
  {
    weeksAgo: 8, conceptId: 5, title: 'Lab 05 — Factorial Function', timeLimit: 35,
    description: 'Read N and print N! using a recursive function.',
    tests: [tc('5', '120'), tc('10', '3628800'), tc('0', '1', true)],
    correct: '#include <iostream>\nusing namespace std;\nlong long fact(int n) { return n <= 1 ? 1 : n * fact(n - 1); }\nint main() {\n  int n; cin >> n;\n  cout << fact(n);\n  return 0;\n}',
    wrong: '#include <iostream>\nusing namespace std;\nlong long fact(int n) { return n; }\nint main() {\n  int n; cin >> n;\n  cout << fact(n);\n  return 0;\n}',
    hardcoded: '#include <iostream>\nusing namespace std;\nint main() {\n  cout << 120;\n  return 0;\n}',
    secondary: [{ conceptId: 12, weight: 0.4 }], // Scope
  },
  {
    weeksAgo: 7, conceptId: 8, title: 'Lab 06 — Pointer Swap', timeLimit: 40,
    description: 'Write a function that swaps two ints using pointers.',
    tests: [tc('3 5', '5 3'), tc('8 1', '1 8', true)],
    correct: '#include <iostream>\nusing namespace std;\nvoid swp(int* a, int* b) { int t = *a; *a = *b; *b = t; }\nint main() {\n  int a, b; cin >> a >> b;\n  swp(&a, &b);\n  cout << a << " " << b;\n  return 0;\n}',
    wrong: '#include <iostream>\nusing namespace std;\nvoid swp(int a, int b) { int t = a; a = b; b = t; }\nint main() {\n  int a, b; cin >> a >> b;\n  swp(a, b);\n  cout << a << " " << b;\n  return 0;\n}',
    hardcoded: '#include <iostream>\nusing namespace std;\nint main() {\n  cout << "5 3";\n  return 0;\n}',
    secondary: [{ conceptId: 18, weight: 0.4 }], // Dynamic Memory
  },
  {
    weeksAgo: 6, conceptId: 7, title: 'Lab 07 — Class & Object Basics', timeLimit: 40,
    description: 'Define a Rectangle class with width/height and an area() method.',
    tests: [tc('4 5', '20'), tc('7 3', '21', true)],
    correct: '#include <iostream>\nusing namespace std;\nclass Rectangle {\npublic:\n  int w, h;\n  int area() { return w * h; }\n};\nint main() {\n  Rectangle r;\n  cin >> r.w >> r.h;\n  cout << r.area();\n  return 0;\n}',
    wrong: '#include <iostream>\nusing namespace std;\nclass Rectangle {\npublic:\n  int w, h;\n  int area() { return w + h; }\n};\nint main() {\n  Rectangle r;\n  cin >> r.w >> r.h;\n  cout << r.area();\n  return 0;\n}',
    hardcoded: '#include <iostream>\nusing namespace std;\nint main() {\n  cout << 20;\n  return 0;\n}',
  },
  // ── Procedural Fundamentals block (recent weeks → default tab populated) ──
  {
    weeksAgo: 5, conceptId: 10, title: 'Lab 08 — Basic Output', timeLimit: 20,
    description: 'Print the message "Hello, World!" to the console.',
    tests: [tc('', 'Hello, World!'), tc('', 'Hello, World!', true)],
    correct: '#include <iostream>\nusing namespace std;\nint main() {\n  cout << "Hello, World!";\n  return 0;\n}',
    wrong: '#include <iostream>\nusing namespace std;\nint main() {\n  cout << "Hello";\n  return 0;\n}',
    hardcoded: '#include <iostream>\nusing namespace std;\nint main() {\n  cout << "Hello, World!";\n  return 0;\n}',
  },
  {
    weeksAgo: 4, conceptId: 1, title: 'Lab 09 — Data Types & Sizes', timeLimit: 30,
    description: 'Read an int and a double, print them back and print their sizes in bytes.',
    tests: [tc('42 3.14', '42 3.14 4 8'), tc('1 2.5', '1 2.5 4 8', true)],
    correct: '#include <iostream>\nusing namespace std;\nint main() {\n  int a; double b;\n  cin >> a >> b;\n  cout << a << " " << b << " " << sizeof(a) << " " << sizeof(b);\n  return 0;\n}',
    wrong: '#include <iostream>\nusing namespace std;\nint main() {\n  int a; double b;\n  cin >> a >> b;\n  cout << a << " " << b << " " << sizeof(a);\n  return 0;\n}',
    hardcoded: '#include <iostream>\nusing namespace std;\nint main() {\n  cout << "42 3.14 4 8";\n  return 0;\n}',
  },
  {
    weeksAgo: 3, conceptId: 2, title: 'Lab 10 — Variable Swap', timeLimit: 30,
    description: 'Read two integers and print them after swapping their values.',
    tests: [tc('3 5', '5 3'), tc('10 20', '20 10', true)],
    correct: '#include <iostream>\nusing namespace std;\nint main() {\n  int a, b;\n  cin >> a >> b;\n  swap(a, b);\n  cout << a << " " << b;\n  return 0;\n}',
    wrong: '#include <iostream>\nusing namespace std;\nint main() {\n  int a, b;\n  cin >> a >> b;\n  cout << a << " " << b;\n  return 0;\n}',
    hardcoded: '#include <iostream>\nusing namespace std;\nint main() {\n  cout << "5 3";\n  return 0;\n}',
  },
  {
    weeksAgo: 2, conceptId: 9, title: 'Lab 11 — String Reversal', timeLimit: 30,
    description: 'Read a string and print it reversed.',
    tests: [tc('hello', 'olleh'), tc('codeinsight', 'thgisniedoc', true)],
    correct: '#include <iostream>\n#include <string>\n#include <algorithm>\nusing namespace std;\nint main() {\n  string s;\n  cin >> s;\n  reverse(s.begin(), s.end());\n  cout << s;\n  return 0;\n}',
    wrong: '#include <iostream>\n#include <string>\nusing namespace std;\nint main() {\n  string s;\n  cin >> s;\n  cout << s;\n  return 0;\n}',
    hardcoded: '#include <iostream>\nusing namespace std;\nint main() {\n  cout << "olleh";\n  return 0;\n}',
  },
  {
    weeksAgo: 1, conceptId: 13, title: 'Lab 12 — Enums: Weekday Names', timeLimit: 30,
    description: 'Read a number 1-7 and print the corresponding weekday name (1=Monday...7=Sunday).',
    tests: [tc('1', 'Monday'), tc('7', 'Sunday'), tc('4', 'Thursday', true)],
    correct: '#include <iostream>\nusing namespace std;\nint main() {\n  int n; cin >> n;\n  const char* d[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};\n  cout << d[n-1];\n  return 0;\n}',
    wrong: '#include <iostream>\nusing namespace std;\nint main() {\n  int n; cin >> n;\n  cout << "Monday";\n  return 0;\n}',
    hardcoded: '#include <iostream>\nusing namespace std;\nint main() {\n  cout << "Monday";\n  return 0;\n}',
  },
  {
    weeksAgo: 0, conceptId: 21, title: 'Lab 13 — Type Casting Lab', timeLimit: 30,
    description: 'Read an int numerator and denominator, print the double quotient to 2 decimals.',
    tests: [tc('5 2', '2.50'), tc('1 3', '0.33', true)],
    correct: '#include <iostream>\n#include <iomanip>\nusing namespace std;\nint main() {\n  int a, b; cin >> a >> b;\n  cout << fixed << setprecision(2) << (double)a / b;\n  return 0;\n}',
    wrong: '#include <iostream>\nusing namespace std;\nint main() {\n  int a, b; cin >> a >> b;\n  cout << a / b;\n  return 0;\n}',
    hardcoded: '#include <iostream>\nusing namespace std;\nint main() {\n  cout << "2.50";\n  return 0;\n}',
    secondary: [{ conceptId: 1, weight: 0.5 }], // Datatypes
  },
];

// ── Integrity flag plan (by exercise title so reorders stay valid) ─────────
const FLAG_PLANS = [
  { email: 'luisa.mercado@psu.edu', exercise: 'Lab 05 — Factorial Function', flag_type: 'HARDCODING', severity: 'high', evidence: { pattern: 'cout << 120', matchType: 'hardcoded_solution' } },
  { email: 'antonio.lopez@psu.edu', exercise: 'Lab 03 — Sum of N Numbers', flag_type: 'CODE_PASTE', severity: 'moderate', evidence: { matchType: 'code_paste', similarity: 0.92 } },
  { email: 'pedro.ramirez@psu.edu', exercise: 'Lab 01 — Even or Odd', flag_type: 'BLANK_TEMPLATE', severity: 'low', evidence: { matchType: 'blank_template' } },
  { email: 'gloria.hernandez@psu.edu', exercise: 'Lab 13 — Type Casting Lab', flag_type: 'CODE_PASTE', severity: 'moderate', evidence: { matchType: 'code_paste', similarity: 0.85 } },
];

// ── Attempt generator ────────────────────────────────────────────────────────
function genAttempts(profile, ex, group) {
  const n = rand(profile.attemptsMin, profile.attemptsMax);
  const late = rnd() < profile.lateProb;
  const weekIdx = 12 - ex.weeksAgo; // 0 = oldest … 12 = newest
  const k = weekIdx / 12;
  const curve = profile.curve[0] + (profile.curve[1] - profile.curve[0]) * k;
  const diff = CONCEPT_DIFF[ex.conceptId] || 0;
  const cds = clamp(profile.base * curve + diff + (rnd() * 0.06 - 0.03), 0.02, 0.99);

  const windowStart = late ? ex.deadline : dayOffset(ex.weeksAgo * 7 + 6);
  const windowEnd = late ? ex.closed : ex.deadline;
  const span = Math.max(1, windowEnd.getTime() - windowStart.getTime());

  const attempts = [];
  for (let i = 0; i < n; i++) {
    const last = i === n - 1;
    // Group F never gets it right; others ramp toward their success rate.
    let pCorrect;
    if (profile.correctProb === 0) pCorrect = 0;
    else pCorrect = last ? profile.correctProb : Math.min(profile.correctProb * ((i + 1) / n) + 0.15, 0.6);
    const isCorrect = rnd() < pCorrect;
    const t = windowStart.getTime() + (i / Math.max(n - 1, 1)) * span * 0.85 + rnd() * span * 0.15;
    const submittedAt = new Date(Math.min(t, windowEnd.getTime() - 60_000));

    let code;
    if (group === 'G' && ex.title.includes('Factorial') && last) code = ex.hardcoded; // Luisa hardcodes Lab 05
    else if (isCorrect) code = ex.correct;
    else code = rnd() < 0.3 ? ex.hardcoded : ex.wrong;

    const testResults = ex.tests.map((t2) => ({
      input: t2.input,
      expected_output: t2.expected_output,
      passed: isCorrect ? true : t2.hidden ? rnd() < 0.15 : rnd() < 0.35,
      hidden: t2.hidden,
      validationType: 'exact',
    }));

    attempts.push({
      attempt_number: i + 1,
      is_correct: isCorrect,
      time_spent_seconds: rand(profile.timeMin, profile.timeMax),
      tab_switch_count: rand(profile.tabMin, profile.tabMax),
      paste_count: rand(profile.pasteMin, profile.pasteMax),
      idle_time_seconds: rand(5, 90),
      code,
      submitted_at: submittedAt,
      test_results: testResults,
    });
  }
  return { attempts, cds };
}

// ── Main ─────────────────────────────────────────────────────────────────────
async function main() {
  const client = await pool.connect();
  let sectionId;
  try {
    await client.query('BEGIN');

    // 1. Instructor (find by email; create if absent)
    let inst = (await client.query(`SELECT id FROM users WHERE email=$1 AND role='instructor'`, ['instructor@psu.edu'])).rows[0];
    if (!inst) {
      const hash = bcrypt.hashSync(PASSWORD, 10);
      inst = (await client.query(
        `INSERT INTO users (name, email, password_hash, role, email_verified) VALUES ('Dr. Instructor', $1, $2, 'instructor', true) RETURNING id`,
        ['instructor@psu.edu', hash]
      )).rows[0];
    }
    const instructorId = inst.id;

    // 2. Section (find by name; create if absent)
    const sec = (await client.query(`SELECT id FROM sections WHERE name=$1`, [SECTION_NAME])).rows[0];
    if (sec) {
      sectionId = sec.id;
      console.log(`Reusing existing section ${SECTION_NAME} (id=${sectionId}) — wiping its demo data...`);
    } else {
      const r = await client.query(
        `INSERT INTO sections (name, course_code, code, instructor_id, term, semester, join_policy)
         VALUES ($1, $2, $3, $4, '1st Semester 2026-2027', '1st', 'code') RETURNING id`,
        [SECTION_NAME, COURSE_CODE, 'BSIT4H', instructorId]
      );
      sectionId = r.rows[0].id;
      console.log(`Created section ${SECTION_NAME} (id=${sectionId})`);
    }

    // 3. Wipe any previous demo data for this section (FK-safe order)
    await client.query(`DELETE FROM integrity_flags WHERE section_id=$1`, [sectionId]);
    await client.query(`DELETE FROM alerts WHERE section_id=$1`, [sectionId]);
    await client.query(`DELETE FROM cds_scores WHERE section_id=$1`, [sectionId]);
    await client.query(`DELETE FROM behavioral_events WHERE exercise_id IN (SELECT id FROM exercises WHERE section_id=$1)`, [sectionId]);
    await client.query(`DELETE FROM submissions WHERE exercise_id IN (SELECT id FROM exercises WHERE section_id=$1)`, [sectionId]);
    await client.query(`DELETE FROM run_attempts WHERE exercise_id IN (SELECT id FROM exercises WHERE section_id=$1)`, [sectionId]);
    await client.query(`DELETE FROM exercise_concept_tags WHERE exercise_id IN (SELECT id FROM exercises WHERE section_id=$1)`, [sectionId]);
    await client.query(`DELETE FROM exercises WHERE section_id=$1`, [sectionId]);
    await client.query(`DELETE FROM enrollments WHERE section_id=$1`, [sectionId]);

    // 4. Students (upsert by email)
    const hash = bcrypt.hashSync(PASSWORD, 10);
    const students = [];
    for (const p of PERSONAS) {
      const r = await client.query(
        `INSERT INTO users (name, email, password_hash, role, email_verified)
         VALUES ($1, $2, $3, 'student', true)
         ON CONFLICT (email) DO UPDATE SET name=$1
         RETURNING id`,
        [p.name, p.email, hash]
      );
      students.push({ id: r.rows[0].id, ...p });
    }

    // 5. Enrollments (backdated to the start of the semester)
    const enrolledAt = dayOffset(12 * 7 + 6);
    for (const s of students) {
      await client.query(
        `INSERT INTO enrollments (student_id, section_id, enrolled_at) VALUES ($1, $2, $3) ON CONFLICT DO NOTHING`,
        [s.id, sectionId, enrolledAt]
      );
    }

    // 6. Exercises + concept tags
    const exercises = [];
    for (const ex of EXERCISES) {
      const deadline = dayOffset(ex.weeksAgo * 7 + 2, 23, 59, 59);
      const closed = dayOffset(ex.weeksAgo * 7 + 1, 12, 0, 0);
      const r = await client.query(
        `INSERT INTO exercises
           (section_id, concept_id, title, description, starter_code, reference_solution,
            time_limit_minutes, test_cases, deadline, closed_at, created_by, is_draft, is_validated)
         VALUES ($1, $2, $3, $4, $5, $6, $7, $8::jsonb, $9, $10, $11, false, true)
         RETURNING id`,
        [sectionId, ex.conceptId, ex.title, ex.description, STARTER, ex.correct,
         ex.timeLimit, JSON.stringify(ex.tests), deadline, closed, instructorId]
      );
      const id = r.rows[0].id;
      await client.query(
        `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary) VALUES ($1, $2, 1.0, true)`,
        [id, ex.conceptId]
      );
      for (const sec of ex.secondary || []) {
        await client.query(
          `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary) VALUES ($1, $2, $3, false)`,
          [id, sec.conceptId, sec.weight]
        );
      }
      exercises.push({ id, ...ex, deadline, closed });
    }
    console.log(`Created ${exercises.length} weekly exercises`);

    // 7. Submissions (deterministic per persona; bulk insert)
    const submittedPairs = new Set();
    const subRows = [];
    const cdsByStudentExercise = {}; // `${studentId}:${exerciseId}` → { cds, flagged }
    for (const s of students) {
      const profile = GROUPS[s.group];
      const missPool = exercises.filter((e) => e.weeksAgo >= 1).map((e) => e.id);
      const misses = new Set();
      let guard = 0;
      while (misses.size < profile.misses && guard++ < 50) misses.add(pick(missPool));

      for (const ex of exercises) {
        if (misses.has(ex.id)) continue;
        const { attempts, cds } = genAttempts(profile, ex, s.group);
        submittedPairs.add(`${s.id}:${ex.id}`);
        cdsByStudentExercise[`${s.id}:${ex.id}`] = cds;
        for (const a of attempts) {
          subRows.push([
            s.id, ex.id, a.code, a.is_correct, a.attempt_number,
            a.time_spent_seconds, a.tab_switch_count, a.paste_count,
            a.idle_time_seconds, a.submitted_at, JSON.stringify(a.test_results), true,
          ]);
        }
      }
    }
    for (let i = 0; i < subRows.length; i += 500) {
      const chunk = subRows.slice(i, i + 500);
      const params = [];
      const vals = chunk.map((row, idx) => {
        const base = idx * 12;
        params.push(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9], row[10], row[11]);
        return `($${base + 1},$${base + 2},$${base + 3},$${base + 4},$${base + 5},$${base + 6},$${base + 7},$${base + 8},$${base + 9},$${base + 10},$${base + 11}::jsonb,$${base + 12})`;
      });
      await client.query(
        `INSERT INTO submissions
           (student_id, exercise_id, code, is_correct, attempt_number, time_spent_seconds,
            tab_switch_count, paste_count, idle_time_seconds, submitted_at, test_results, is_verified)
         VALUES ${vals.join(',')}`,
        params
      );
    }
    console.log(`Inserted ${subRows.length} submissions across ${students.length} students`);

    // 8. Integrity flags (submission-linked, on specific weeks)
    for (const f of FLAG_PLANS) {
      const st = students.find((s) => s.email === f.email);
      const ex = exercises.find((e) => e.title.includes(f.exercise.split(' — ')[1]) || e.title === f.exercise);
      if (!st || !ex) continue;
      const sub = (await client.query(
        `SELECT id FROM submissions WHERE student_id=$1 AND exercise_id=$2 ORDER BY attempt_number DESC LIMIT 1`,
        [st.id, ex.id]
      )).rows[0];
      // The current-week flag is backdated only a few hours so it lands in the
      // integrity-timeline "Now" bucket AND the dashboard 24h Flags KPI.
      const created = ex.weeksAgo === 0
        ? new Date(Date.now() - 6 * 3600 * 1000)
        : dayOffset(ex.weeksAgo * 7 + 2, 10, 0, 0);
      await client.query(
        `INSERT INTO integrity_flags (section_id, exercise_id, student_id, submission_id, flag_type, severity, evidence, status, created_at)
         VALUES ($1, $2, $3, $4, $5, $6, $7::jsonb, 'flagged', $8)
         ON CONFLICT (exercise_id, student_id, flag_type) DO NOTHING`,
        [sectionId, ex.id, st.id, sub ? sub.id : null, f.flag_type, f.severity,
         JSON.stringify(f.evidence), created]
      );
    }
    console.log(`Inserted ${FLAG_PLANS.length} integrity flags`);

    // 9. Behavioral events (telemetry trail per student × exercise)
    const eventRows = [];
    for (const s of students) {
      for (const ex of exercises) {
        if (!submittedPairs.has(`${s.id}:${ex.id}`)) continue;
        const nEvents = rand(2, 5);
        for (let i = 0; i < nEvents; i++) {
          const type = pick(['TAB_SWITCH', 'PASTE', 'IDLE_TIME', 'FOCUS_LOST', 'RUN_SUBMIT', 'EDITOR_OPEN']);
          let payload = {};
          if (type === 'TAB_SWITCH') payload = { count: rand(1, 10) };
          else if (type === 'PASTE') payload = { count: rand(1, 8), length: rand(10, 140) };
          else if (type === 'IDLE_TIME') payload = { seconds: rand(10, 300) };
          const occurred = new Date(dayOffset(ex.weeksAgo * 7 + 2).getTime() + rand(0, 4) * DAY_MS);
          eventRows.push([s.id, ex.id, type, occurred, JSON.stringify(payload)]);
        }
      }
    }
    for (let i = 0; i < eventRows.length; i += 500) {
      const chunk = eventRows.slice(i, i + 500);
      const params = [];
      const vals = chunk.map((row, idx) => {
        const base = idx * 5;
        params.push(row[0], row[1], row[2], row[3], row[4]);
        return `($${base + 1},$${base + 2},$${base + 3},$${base + 4},$${base + 5}::jsonb)`;
      });
      await client.query(
        `INSERT INTO behavioral_events (student_id, exercise_id, event_type, occurred_at, payload) VALUES ${vals.join(',')}`,
        params
      );
    }
    console.log(`Inserted ${eventRows.length} behavioral events`);

    // 10. CDS scores + snapshots + High-CDS alerts (persona-derived, backdated)
    //     Flagged students on their flagged exercise → 'Flagged-Pending' (null
    //     CDS, excluded from class stats), exactly like the batch engine.
    const flaggedKey = (sid, exId) => FLAG_PLANS.some(
      (f) => students.find((s) => s.email === f.email)?.id === sid &&
        exercises.find((e) => e.title === f.exercise || e.title.includes(f.exercise.split(' — ')[1]))?.id === exId
    );
    const conceptNames = (await client.query('SELECT id, name FROM concepts')).rows.reduce((m, c) => { m[c.id] = c.name; return m; }, {});

    const scoreRows = [];
    const snapshotRows = [];
    const alertRows = [];
    for (const s of students) {
      for (const ex of exercises) {
        const key = `${s.id}:${ex.id}`;
        const submitted = submittedPairs.has(key);
        const flagged = flaggedKey(s.id, ex.id);
        let cds = null, classification = 'Unscored';
        let hasFlagged = false, flagCount = 0;
        if (!submitted) {
          classification = 'Unscored';
        } else if (flagged) {
          classification = 'Flagged-Pending';
          hasFlagged = true;
          flagCount = 1;
        } else {
          cds = Number(cdsByStudentExercise[key].toFixed(2));
          classification = classify(cds);
        }
        // Backdate computed_at to the exercise's week (newest spread across
        // the last 4 days so the dashboard 7-day trend has multiple points).
        let computedAt;
        if (ex.weeksAgo === 0) {
          computedAt = dayOffset(1 + (s.id % 4), 10, 30, 0);
        } else {
          computedAt = dayOffset(ex.weeksAgo * 7 + 1, 9, 0, 0);
        }
        scoreRows.push([s.id, ex.id, sectionId, cds, cds, cds, cds, classification, hasFlagged, flagCount, 'batch', true, computedAt]);
        snapshotRows.push([s.id, ex.id, cds, cds, cds, cds, classification, computedAt]);
        if (classification === 'High' || classification === 'Prelim-High') {
          alertRows.push([s.id, ex.id, sectionId, cds, classification, conceptNames[ex.conceptId] || 'Unknown', computedAt, computedAt]);
        }
      }
    }
    await client.query(
      `INSERT INTO cds_scores
         (student_id, exercise_id, section_id, ner, nrs, nts, cds, classification,
          has_flagged_attempts, integrity_flag_count, source, visible, computed_at)
       VALUES ${scoreRows.map((_, i) => `($${i * 13 + 1},$${i * 13 + 2},$${i * 13 + 3},$${i * 13 + 4},$${i * 13 + 5},$${i * 13 + 6},$${i * 13 + 7},$${i * 13 + 8},$${i * 13 + 9},$${i * 13 + 10},$${i * 13 + 11},$${i * 13 + 12},$${i * 13 + 13})`).join(',')}`,
      scoreRows.flat()
    );
    await client.query(
      `INSERT INTO cds_snapshots
         (student_id, exercise_id, ner, nrs, nts, cds, classification, calculated_at)
       VALUES ${snapshotRows.map((_, i) => `($${i * 8 + 1},$${i * 8 + 2},$${i * 8 + 3},$${i * 8 + 4},$${i * 8 + 5},$${i * 8 + 6},$${i * 8 + 7},$${i * 8 + 8})`).join(',')}`,
      snapshotRows.flat()
    );
    if (alertRows.length) {
      await client.query(
        `INSERT INTO alerts (student_id, exercise_id, section_id, cds_score, classification, concept_name, created_at, computed_at)
         VALUES ${alertRows.map((_, i) => `($${i * 8 + 1},$${i * 8 + 2},$${i * 8 + 3},$${i * 8 + 4},$${i * 8 + 5},$${i * 8 + 6},$${i * 8 + 7},$${i * 8 + 8})`).join(',')}
         ON CONFLICT (student_id, exercise_id) DO NOTHING`,
        alertRows.flat()
      );
    }
    console.log(`Inserted ${scoreRows.length} CDS scores, ${snapshotRows.length} snapshots, ${alertRows.length} High-CDS alerts`);

    await client.query('COMMIT');

    // ── Summary ────────────────────────────────────────────────────────────
    const counts = (await client.query(`
      SELECT
        (SELECT COUNT(*)::int FROM enrollments WHERE section_id=$1) AS students,
        (SELECT COUNT(*)::int FROM submissions s JOIN exercises e ON e.id=s.exercise_id WHERE e.section_id=$1) AS submissions,
        (SELECT COUNT(*)::int FROM cds_scores WHERE section_id=$1) AS cds_scores,
        (SELECT COUNT(*)::int FROM integrity_flags WHERE section_id=$1) AS flags,
        (SELECT COUNT(*)::int FROM alerts WHERE section_id=$1) AS alerts,
        (SELECT COUNT(*)::int FROM behavioral_events be JOIN exercises e ON e.id=be.exercise_id WHERE e.section_id=$1) AS events
    `, [sectionId])).rows[0];

    console.log(`\n✅ BSIT-4H months-long seed complete`);
    console.log(`   Section: ${SECTION_NAME} (id=${sectionId}) · instructor #${instructorId}`);
    console.log(`   Students: ${counts.students} · Exercises: ${exercises.length} · Submissions: ${counts.submissions}`);
    console.log(`   CDS scores: ${counts.cds_scores} · Integrity flags: ${counts.flags} · Alerts: ${counts.alerts}`);
    console.log(`   Behavioral events: ${counts.events}`);
    console.log(`   All passwords: ${PASSWORD}`);
  } catch (err) {
    await client.query('ROLLBACK');
    console.error('Seed failed:', err);
    process.exit(1);
  } finally {
    client.release();
    await pool.end();
  }
}

main();
