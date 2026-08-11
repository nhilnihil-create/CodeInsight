/**
 * exerciseController.update tag handling tests (weighted multi-tag feature)
 *
 * Drives the real update handler against the codeinsight_test DB (config/db
 * mocked with a delegate to the test pool, same pattern as
 * runCheckpointIntegrity.test.js) and asserts the resulting
 * exercise_concept_tags rows via testPool.query.
 *
 * cdsJobQueue.enqueueCdsComputation and conceptAnalytics.computeAllMetrics are
 * stubbed with jest.spyOn to no-ops BEFORE update is called so the
 * fire-and-forget recompute after a successful tag change stays deterministic
 * (no cds_job_queue row is written and no polling interval is started).
 */

jest.mock('../config/db', () => {
  const { pool } = require('./setup');
  return {
    query: (text, values) => pool.query(text, values),
    withTransaction: async (fn) => {
      const client = await pool.connect();
      try {
        await client.query('BEGIN');
        const result = await fn(client);
        await client.query('COMMIT');
        return result;
      } catch (err) {
        try { await client.query('ROLLBACK'); } catch (_) { /* ignore */ }
        throw err;
      } finally {
        client.release();
      }
    },
  };
});

const assert = require('assert');
const exerciseController = require('../controllers/exerciseController');
const cdsJobQueue = require('../services/cdsJobQueue');
const conceptAnalytics = require('../services/conceptAnalytics');
const {
  pool: testPool,
  seedTestInstructor,
  seedTestSection,
  seedTestConcept,
  seedTestExercise,
} = require('./setup');

// ── Helpers ─────────────────────────────────────────────────────────────────

async function seedConceptByName(name) {
  const { rows } = await testPool.query(
    `INSERT INTO concepts (name) VALUES ($1)
     ON CONFLICT (name) DO UPDATE SET name = $1
     RETURNING id`,
    [name]
  );
  return rows[0].id;
}

async function seedTag(exerciseId, conceptId, weight, isPrimary) {
  await testPool.query(
    `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary)
     VALUES ($1, $2, $3, $4)`,
    [exerciseId, conceptId, weight, isPrimary]
  );
}

// seedTestExercise does not set exercises.created_by (schema default NULL),
// but update() rejects requests whose req.user.id !== created_by. Mark the
// exercise as owned by the given instructor right after seeding.
async function seedOwnedExercise(instructorId, sectionId, conceptId, opts = {}) {
  const exerciseId = await seedTestExercise(sectionId, conceptId, opts);
  await testPool.query(
    'UPDATE exercises SET created_by = $1 WHERE id = $2',
    [instructorId, exerciseId]
  );
  return exerciseId;
}

async function seedInstructor(name, email) {
  const { rows } = await testPool.query(
    `INSERT INTO users (name, email, password_hash, role)
     VALUES ($1, $2, 'hashed_pw', 'instructor')
     ON CONFLICT (email) DO UPDATE SET name = $1
     RETURNING id`,
    [name, email]
  );
  return rows[0].id;
}

function mockRes() {
  return {
    status: jest.fn().mockReturnThis(),
    json: jest.fn().mockReturnThis(),
  };
}

async function callUpdate(exerciseId, instructorId, body) {
  const req = {
    params: { id: String(exerciseId) },
    user: { id: instructorId },
    body,
  };
  const res = mockRes();
  const next = jest.fn();
  await exerciseController.update(req, res, next);
  return { res, next };
}

async function getTags(exerciseId) {
  const { rows } = await testPool.query(
    `SELECT concept_id, weight, is_primary
     FROM exercise_concept_tags
     WHERE exercise_id = $1
     ORDER BY concept_id`,
    [exerciseId]
  );
  return rows;
}

describe('exerciseController.update tag handling', function() {
  beforeEach(async function() {
    jest.spyOn(cdsJobQueue, 'enqueueCdsComputation').mockResolvedValue(undefined);
    jest.spyOn(conceptAnalytics, 'computeAllMetrics').mockResolvedValue({});
  });

  afterEach(function() {
    jest.restoreAllMocks();
  });

  it('replaces ALL tags when concept_tags is provided', async function() {
    const instructorId = await seedTestInstructor();
    const sectionId = await seedTestSection(instructorId);
    const loops = await seedTestConcept();
    const arrays = await seedConceptByName('Arrays');
    const functions = await seedConceptByName('Functions');

    const exerciseId = await seedOwnedExercise(instructorId, sectionId, loops, { title: 'Tagged Ex' });
    await seedTag(exerciseId, loops, 1.0, true);
    await seedTag(exerciseId, arrays, 0.5, false);

    const { res, next } = await callUpdate(exerciseId, instructorId, {
      title: 'Tagged Ex',
      concept_tags: [
        { concept_id: loops, weight: 1.0, is_primary: true },
        { concept_id: functions, weight: 0.4, is_primary: false },
      ],
    });

    assert.strictEqual(next.mock.calls.length, 0, 'no error expected');
    assert.strictEqual(res.json.mock.calls.length, 1, 'update should respond via res.json');

    const tags = await getTags(exerciseId);
    assert.strictEqual(tags.length, 2, `expected exactly 2 tags, got ${JSON.stringify(tags)}`);
    const loopsRow = tags.find(t => t.concept_id === loops);
    const funcsRow = tags.find(t => t.concept_id === functions);
    assert.ok(loopsRow && funcsRow, 'both new tags should be present');
    assert.strictEqual(Number(loopsRow.weight), 1.0);
    assert.strictEqual(loopsRow.is_primary, true);
    assert.strictEqual(Number(funcsRow.weight), 0.4);
    assert.strictEqual(funcsRow.is_primary, false);
    assert.ok(!tags.some(t => t.concept_id === arrays),
      'old secondary tag should be removed');
  });

  it('clears secondaries and keeps exactly one primary when concept_tags is []', async function() {
    const instructorId = await seedTestInstructor();
    const sectionId = await seedTestSection(instructorId);
    const loops = await seedTestConcept();
    const arrays = await seedConceptByName('Arrays');

    const exerciseId = await seedOwnedExercise(instructorId, sectionId, loops, { title: 'Clear Ex' });
    await seedTag(exerciseId, loops, 1.0, true);
    await seedTag(exerciseId, arrays, 0.5, false);

    const { res, next } = await callUpdate(exerciseId, instructorId, {
      title: 'Clear Ex',
      concept_tags: [],
    });

    assert.strictEqual(next.mock.calls.length, 0, 'no error expected');
    assert.strictEqual(res.json.mock.calls.length, 1);

    const tags = await getTags(exerciseId);
    assert.strictEqual(tags.length, 1, `expected exactly one tag, got ${JSON.stringify(tags)}`);
    assert.strictEqual(tags[0].concept_id, loops);
    assert.strictEqual(tags[0].is_primary, true);
  });

  it('swaps the primary tag when a new concept_name is provided', async function() {
    const instructorId = await seedTestInstructor();
    const sectionId = await seedTestSection(instructorId);
    const loops = await seedTestConcept();
    const arrays = await seedConceptByName('Arrays');

    const exerciseId = await seedOwnedExercise(instructorId, sectionId, loops, { title: 'Swap Ex' });
    await seedTag(exerciseId, loops, 1.0, true);
    await seedTag(exerciseId, arrays, 0.5, false);

    const { res, next } = await callUpdate(exerciseId, instructorId, {
      title: 'Swap Ex',
      concept_name: 'Arrays',
    });

    assert.strictEqual(next.mock.calls.length, 0, 'no error expected');
    assert.strictEqual(res.json.mock.calls.length, 1);

    const tags = await getTags(exerciseId);
    assert.strictEqual(tags.length, 1,
      `old primary row should be deleted and only the new primary remain, got ${JSON.stringify(tags)}`);
    assert.strictEqual(tags[0].concept_id, arrays);
    assert.strictEqual(tags[0].is_primary, true);
    assert.strictEqual(Number(tags[0].weight), 1.0);

    // exercises.concept_id should be updated to the new primary
    const { rows } = await testPool.query(
      `SELECT concept_id FROM exercises WHERE id = $1`,
      [exerciseId]
    );
    assert.strictEqual(rows[0].concept_id, arrays);
  });

  it('leaves tags untouched when neither concept_tags nor concept_name is sent', async function() {
    const instructorId = await seedTestInstructor();
    const sectionId = await seedTestSection(instructorId);
    const loops = await seedTestConcept();
    const arrays = await seedConceptByName('Arrays');

    const exerciseId = await seedOwnedExercise(instructorId, sectionId, loops, { title: 'Rename Ex' });
    await seedTag(exerciseId, loops, 1.0, true);
    await seedTag(exerciseId, arrays, 0.5, false);

    const { res, next } = await callUpdate(exerciseId, instructorId, { title: 'Renamed' });

    assert.strictEqual(next.mock.calls.length, 0, 'no error expected');
    assert.strictEqual(res.json.mock.calls.length, 1);
    assert.strictEqual(res.json.mock.calls[0][0].title, 'Renamed');

    const tags = await getTags(exerciseId);
    assert.strictEqual(tags.length, 2, `tags must be untouched, got ${JSON.stringify(tags)}`);
    const loopsRow = tags.find(t => t.concept_id === loops);
    const arraysRow = tags.find(t => t.concept_id === arrays);
    assert.ok(loopsRow && arraysRow, 'both original tags should still exist');
    assert.strictEqual(loopsRow.is_primary, true);
    assert.strictEqual(arraysRow.is_primary, false);
    assert.strictEqual(Number(arraysRow.weight), 0.5);
  });

  it('returns 400 when a concept_tags entry is missing concept_id', async function() {
    const instructorId = await seedTestInstructor();
    const sectionId = await seedTestSection(instructorId);
    const loops = await seedTestConcept();

    const exerciseId = await seedOwnedExercise(instructorId, sectionId, loops, { title: 'Bad Tag Ex' });
    await seedTag(exerciseId, loops, 1.0, true);

    const { next } = await callUpdate(exerciseId, instructorId, {
      title: 'Bad Tag Ex',
      concept_tags: [{ weight: 0.5 }],
    });

    assert.strictEqual(next.mock.calls.length, 1, 'validation error should call next(err)');
    const err = next.mock.calls[0][0];
    assert.strictEqual(err.status, 400);
    assert.ok(/concept_id/.test(err.message), `message should mention concept_id, got: ${err.message}`);

    // Transaction rolled back — original tags unchanged
    const tags = await getTags(exerciseId);
    assert.strictEqual(tags.length, 1, 'no tags should be changed after a rejected update');
  });

  it('returns 404 when the exercise is not owned by req.user.id', async function() {
    const instructorId = await seedTestInstructor();
    const sectionId = await seedTestSection(instructorId);
    const loops = await seedTestConcept();

    const exerciseId = await seedOwnedExercise(instructorId, sectionId, loops, { title: 'Owned Ex' });
    await seedTag(exerciseId, loops, 1.0, true);

    const otherInstructor = await seedInstructor('Other Instructor', 'other@test.com');
    const { next } = await callUpdate(exerciseId, otherInstructor, { title: 'Hijack' });

    assert.strictEqual(next.mock.calls.length, 1, 'not-owned update should call next(err)');
    assert.strictEqual(next.mock.calls[0][0].status, 404);
  });

  it('succeeds with a tags-only update when no column fields are sent', async function() {
    const instructorId = await seedTestInstructor();
    const sectionId = await seedTestSection(instructorId);
    const loops = await seedTestConcept();
    const arrays = await seedConceptByName('Arrays');

    const exerciseId = await seedOwnedExercise(instructorId, sectionId, loops, { title: 'Tags Only Ex' });
    await seedTag(exerciseId, loops, 1.0, true);
    await seedTag(exerciseId, arrays, 0.5, false);

    // Body contains ONLY concept_tags — no title or any other column field.
    // This exercises the empty-SET path: the tag rows are replaced in-transaction
    // but the dynamic UPDATE must be skipped instead of building `SET ` (which
    // would be a Postgres syntax error → 500).
    const { res, next } = await callUpdate(exerciseId, instructorId, {
      concept_tags: [
        { concept_id: loops, weight: 1.0, is_primary: true },
        { concept_id: arrays, weight: 0.7, is_primary: false },
      ],
    });

    assert.strictEqual(next.mock.calls.length, 0, 'tags-only update must not error');
    assert.strictEqual(res.json.mock.calls.length, 1, 'update should respond via res.json');

    const returned = res.json.mock.calls[0][0];
    assert.strictEqual(Number(returned.id), exerciseId, 'exercise row should be returned');
    assert.strictEqual(returned.title, 'Tags Only Ex');

    const tags = await getTags(exerciseId);
    assert.strictEqual(tags.length, 2, `expected 2 tags, got ${JSON.stringify(tags)}`);
    const loopsRow = tags.find(t => t.concept_id === loops);
    const arraysRow = tags.find(t => t.concept_id === arrays);
    assert.ok(loopsRow && arraysRow, 'both tags should still be present');
    assert.strictEqual(loopsRow.is_primary, true);
    assert.strictEqual(arraysRow.is_primary, false);
    assert.strictEqual(Number(arraysRow.weight), 0.7, 'secondary tag weight should be replaced');
  });
});
