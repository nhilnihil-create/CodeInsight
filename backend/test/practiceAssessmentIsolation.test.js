// Practice Submission Isolation Tests
// Verifies that practice submissions (is_practice = true) are excluded from CDS/analytics.
// Mode (learning/assessment) was removed from the system — all exercises have a single path.

const assert = require('assert');

describe('Practice Isolation — CDS Engine', function() {
  const fs = require('fs');
  const path = require('path');
  const cdsSource = fs.readFileSync(path.join(__dirname, '../services/cdsEngine.js'), 'utf8');

  it('CDS queries filter by is_practice IS NOT TRUE', function() {
    const count = (cdsSource.match(/s\.is_practice IS NOT TRUE/g) || []).length;
    assert.ok(count >= 2, `Expected at least 2 is_practice filters, found ${count}`);
  });
});

describe('Practice Isolation — Rubric Scorer', function() {
  const fs = require('fs');
  const path = require('path');
  const rubricSource = fs.readFileSync(path.join(__dirname, '../services/rubricScorer.js'), 'utf8');

  it('rubricScorer median query filters by is_practice IS NOT TRUE', function() {
    assert.ok(
      rubricSource.includes('s.is_practice IS NOT TRUE'),
      'rubricScorer must exclude practice submissions from median'
    );
  });
});

describe('Practice Isolation — Analytics Controller', function() {
  const fs = require('fs');
  const path = require('path');
  const analyticsSource = fs.readFileSync(path.join(__dirname, '../controllers/analyticsController.js'), 'utf8');

  it('getCompletionReport filters by is_practice', function() {
    const completionSection = analyticsSource.substring(
      analyticsSource.indexOf('exports.getCompletionReport'),
      analyticsSource.indexOf('exports.getIntegrityTrends')
    );
    assert.ok(completionSection.includes('sub.is_practice IS NOT TRUE'), 'getCompletionReport must filter out practice');
  });

  it('getReportSummary filters by is_practice', function() {
    const reportSection = analyticsSource.substring(
      analyticsSource.indexOf('exports.getReportSummary'),
      analyticsSource.indexOf('exports.getConceptMasteryReport')
    );
    assert.ok(reportSection.includes('sub.is_practice IS NOT TRUE'), 'getReportSummary must filter out practice');
  });

  it('getInstructorDashboard filters by is_practice', function() {
    const dashboardSection = analyticsSource.substring(
      analyticsSource.indexOf('exports.getInstructorDashboard'),
      analyticsSource.indexOf('exports.getStudentSubmissions')
    );
    assert.ok(dashboardSection.includes('sub.is_practice IS NOT TRUE'), 'Dashboard must filter out practice');
  });

  it('getCommandCenter filters by is_practice', function() {
    const commandSection = analyticsSource.substring(
      analyticsSource.indexOf('exports.getCommandCenter'),
      analyticsSource.indexOf('exports.getSectionHub')
    );
    assert.ok(commandSection.includes('s.is_practice IS NOT TRUE'), 'Command center must filter out practice');
  });

  it('getSectionHub filters by is_practice', function() {
    const hubSection = analyticsSource.substring(
      analyticsSource.indexOf('exports.getSectionHub'),
      analyticsSource.indexOf('exports.getCommandCenter')
    );
    assert.ok(hubSection.includes('s.is_practice IS NOT TRUE'), 'Section hub must filter out practice');
  });
});

describe('Practice Isolation — Student Routes', function() {
  const fs = require('fs');
  const path = require('path');
  const studentSource = fs.readFileSync(path.join(__dirname, '../routes/student.js'), 'utf8');

  it('/dashboard filters by is_practice', function() {
    const dashboardSection = studentSource.substring(
      studentSource.indexOf("router.get('/dashboard'"),
      studentSource.indexOf("router.get('/stats'")
    );
    assert.ok(dashboardSection.includes('s.is_practice IS NOT TRUE'), '/dashboard must filter out practice');
  });

  it('/stats filters by is_practice', function() {
    const statsSection = studentSource.substring(
      studentSource.indexOf("router.get('/stats'"),
      studentSource.indexOf("router.get('/progress'")
    );
    assert.ok(statsSection.includes('s.is_practice IS NOT TRUE'), '/stats must filter out practice');
  });
});

describe('Practice Isolation — Practice Route', function() {
  const fs = require('fs');
  const path = require('path');
  const studentSource = fs.readFileSync(path.join(__dirname, '../routes/student.js'), 'utf8');

  it('practice route sets is_practice = true in INSERT', function() {
    const practiceSection = studentSource.substring(
      studentSource.indexOf("router.post('/exercises/:id/practice'"),
      studentSource.indexOf("router.get('/exercises/:id/attempts'")
    );
    assert.ok(practiceSection.includes('is_practice'), 'Practice route must set is_practice in INSERT');
    assert.ok(practiceSection.includes('true'), 'Practice route must set is_practice to true');
  });

  it('practice route requires prior completion', function() {
    const practiceSection = studentSource.substring(
      studentSource.indexOf("router.post('/exercises/:id/practice'"),
      studentSource.indexOf("router.get('/exercises/:id/attempts'")
    );
    assert.ok(
      practiceSection.includes('is_correct = true') || practiceSection.includes('is_correct=true'),
      'Practice route must verify prior completion'
    );
  });

  it('practice route does NOT call CDS calculation', function() {
    const practiceSection = studentSource.substring(
      studentSource.indexOf("router.post('/exercises/:id/practice'"),
      studentSource.indexOf("router.get('/exercises/:id/attempts'")
    );
    assert.ok(!practiceSection.includes('calculateLiveCDS'), 'Practice route must NOT calculate live CDS');
    assert.ok(!practiceSection.includes('cdsEngine'), 'Practice route must NOT reference cdsEngine');
  });
});

describe('Practice Isolation — Submission Controller', function() {
  const fs = require('fs');
  const path = require('path');
  const subSource = fs.readFileSync(path.join(__dirname, '../controllers/submissionController.js'), 'utf8');

  it('submission controller calculates live CDS', function() {
    assert.ok(subSource.includes('calculateLiveCDS'), 'submissionController must call calculateLiveCDS');
  });

  it('submission controller does NOT set is_practice (default false)', function() {
    const submitSection = subSource.substring(
      subSource.indexOf('exports.submit'),
      subSource.indexOf('exports.mySubmissions')
    );
    const insertMatch = submitSection.match(/INSERT INTO submissions[\s\S]*?VALUES/);
    if (insertMatch) {
      assert.ok(!insertMatch[0].includes('is_practice'), 'Regular submit must NOT set is_practice (default false)');
    }
  });
});

describe('Practice Isolation — Database Schema', function() {
  const fs = require('fs');
  const path = require('path');

  it('submissions table has is_practice column (in V2 migration)', function() {
    const migrationPath = path.join(__dirname, '../migrations/20260610_v2_audit.sql');
    const migration = fs.readFileSync(migrationPath, 'utf8');
    assert.ok(migration.includes('is_practice'), 'V2 audit migration must add is_practice column');
  });
});

// ── Isolation Logic Simulation ───────────────────────────────────────────────

describe('Practice Isolation — Logic Simulation', function() {
  function simulateCDSFilter(submissions) {
    return submissions.filter(sub => sub.is_practice !== true);
  }

  it('excludes practice submissions from CDS', function() {
    const submissions = [
      { student_id: 1, exercise_id: 1, is_correct: true, is_practice: false },
      { student_id: 1, exercise_id: 1, is_correct: true, is_practice: true },
      { student_id: 1, exercise_id: 1, is_correct: false, is_practice: true },
    ];
    const filtered = simulateCDSFilter(submissions);
    assert.strictEqual(filtered.length, 1);
    assert.strictEqual(filtered[0].is_practice, false);
  });

  it('includes non-practice submissions', function() {
    const submissions = [
      { student_id: 1, exercise_id: 1, is_correct: true, is_practice: false },
      { student_id: 1, exercise_id: 2, is_correct: true, is_practice: false },
    ];
    const filtered = simulateCDSFilter(submissions);
    assert.strictEqual(filtered.length, 2);
  });

  it('handles NULL is_practice (old data) — NULL IS NOT TRUE = true in SQL', function() {
    const submissions = [
      { student_id: 1, exercise_id: 1, is_correct: true, is_practice: null },
    ];
    const filtered = simulateCDSFilter(submissions);
    assert.strictEqual(filtered.length, 1);
  });
});

console.log('Practice Isolation test suite loaded — all assertions active.');
