/**
 * backend/scripts/preview_dossier.js
 *
 * No-DB dossier preview: renders a single-student dossier PDF from mock data
 * so layout tweaks (spacing, table widths, page breaks) can be eyeballed
 * without a live Postgres connection. Requires only the pdfkit stack.
 *
 * Run:   node backend/scripts/preview_dossier.js
 * Output: backend/preview-dossier.pdf
 */
const fs = require('fs');
const path = require('path');
const {
  makeDocument,
  collectBuffer,
  drawDossierPages,
} = require('../services/pdfReport');

const meta = {
  name: 'BSIT 4H — Data Structures',
  course_code: 'DS211',
  term: '1st Semester',
  semester: 'Fall 2026',
  school_year: '2026–2027',
};

const student = {
  studentId: 42,
  name: 'Alex Ramirez',
  email: 'alex.ramirez@student.edu',
  trendLabels: [
    '2026-08-03', '2026-08-04', '2026-08-05', '2026-08-06', '2026-08-07',
    '2026-08-10', '2026-08-11', '2026-08-12', '2026-08-13', '2026-08-14',
  ],
  trendValues: [0.18, 0.22, 0.41, 0.38, 0.52, 0.49, 0.61, 0.58, 0.55, 0.47],
  currentCds: 0.47,
  avgCds: 0.441,
  velocity: 'improving',
  radar: {
    axes: ['Loops', 'Arrays', 'Recursion', 'Pointers', 'Strings'],
    values: [0.72, 0.55, 0.41, 0.63, 0.48],
  },
  heatmap: { rowLabels: [], colLabels: [] },
  flags: [
    { flag_type: 'SIMILAR_CODE', severity: 'high', status: 'flagged', created_at: '2026-08-10T14:32:00.000Z' },
    { flag_type: 'TAB_SWITCH', severity: 'low', status: 'reviewed', created_at: '2026-08-11T09:05:00.000Z' },
  ],
  // Mastery mirrors buildStudentReport: (1 − cds) × 100. The Linked Lists
  // row carries cds: null AND mastery: null to exercise both the empty-CDS
  // and empty-Mastery cell formatters.
  submissions: [
    { title: 'Loops Lab', attempt_number: 1, passed: true, cds: 0.18, mastery: 82, submitted: '2026-08-03T09:12:00.000Z' },
    { title: 'Array Slicing', attempt_number: 1, passed: true, cds: 0.22, mastery: 78, submitted: '2026-08-04T10:05:00.000Z' },
    { title: 'Recursion Basics', attempt_number: 2, passed: true, cds: 0.41, mastery: 59, submitted: '2026-08-05T14:22:00.000Z' },
    { title: 'Pointer Arithmetic', attempt_number: 1, passed: false, cds: 0.38, mastery: 62, submitted: '2026-08-06T11:40:00.000Z' },
    { title: 'String Matching', attempt_number: 2, passed: true, cds: 0.52, mastery: 48, submitted: '2026-08-07T09:55:00.000Z' },
    { title: 'Linked Lists', attempt_number: 1, passed: false, cds: null, mastery: null, submitted: '2026-08-10T13:18:00.000Z' },
    { title: 'Binary Search', attempt_number: 2, passed: true, cds: 0.49, mastery: 51, submitted: '2026-08-11T08:47:00.000Z' },
    { title: 'Sorting Intro', attempt_number: 1, passed: true, cds: 0.61, mastery: 39, submitted: '2026-08-12T10:30:00.000Z' },
    { title: 'Stack & Queue', attempt_number: 1, passed: true, cds: 0.58, mastery: 42, submitted: '2026-08-13T15:02:00.000Z' },
    { title: 'Final Drill', attempt_number: 2, passed: true, cds: 0.55, mastery: 45, submitted: '2026-08-14T09:20:00.000Z' },
  ],
};

async function main() {
  const doc = makeDocument();
  let pageCount = 1; // constructor page
  doc.on('pageAdded', () => { pageCount += 1; });

  drawDossierPages(doc, student, meta);

  const buffer = await collectBuffer(doc);
  const out = path.join(__dirname, '..', 'preview-dossier.pdf');
  fs.writeFileSync(out, buffer);
  console.log(`Wrote ${out}`);
  console.log(`Pages: ${pageCount}  ·  Size: ${buffer.length} bytes`);
}

main().catch((err) => {
  console.error(err);
  process.exitCode = 1;
});
