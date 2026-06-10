/**
 * Integration tests for the upload/import endpoints.
 *
 * Tests the UploadsController with a mocked database pool
 * to verify transaction safety, error handling, and response formats.
 */

const assert = require('assert');
const db = require('../config/db');
const ctrl = require('../controllers/UploadsController');

describe('Uploads Controller — Import', () => {
  // ── Transaction rollback on error ────────────────────────────────────────
  describe('importRoster — transaction safety', () => {
    it('rolls back the entire transaction if a DB insert fails mid-batch', async () => {
      let insertCount = 0;
      let step = 'select-existing';
      const savedFn = db.withTransaction;

      db.withTransaction = async (fn) => {
        const mockClient = {
          query: async (text, values) => {
            if (text.includes('SELECT') && text.includes('users')) {
              if (step === 'select-existing') {
                return { rows: [
                  { id: 1, email: 'a@test.com', name: 'A' },
                  { id: 2, email: 'b@test.com', name: 'B' },
                ]};
              }
              return { rows: [
                { id: 1, email: 'a@test.com', name: 'A' },
                { id: 2, email: 'b@test.com', name: 'B' },
                { id: 3, email: 'c@test.com', name: 'C' },
                { id: 4, email: 'd@test.com', name: 'D' },
              ]};
            }
            if (text.includes('INSERT INTO users')) {
              step = 'select-after-create';
              return { rowCount: 1 };
            }
            if (text.includes('INSERT INTO enrollments')) {
              insertCount++;
              if (insertCount === 3) {
                throw new Error('unique constraint violation on enrollments');
              }
              return { rowCount: 1 };
            }
            return { rows: [], rowCount: 0 };
          },
        };
        try { return await fn(mockClient); } catch (err) { throw err; }
      };

      let errorCaught = false;
      let errorMsg = '';
      const mockRes = {
        json: (data) => { mockRes._data = data; },
        status: (code) => { mockRes._status = code; return mockRes; },
      };
      const mockReq = {
        params: { id: 1 },
        body: { createMissingUsers: true },
        file: {
          buffer: Buffer.from('email,name\na@test.com,A\nb@test.com,B\nc@test.com,C\nd@test.com,D'),
          originalname: 'roster.csv',
          mimetype: 'text/csv',
        },
        user: { id: 1, role: 'instructor' },
      };

      await ctrl.importRoster(mockReq, mockRes, (err) => {
        errorCaught = true;
        errorMsg = err.message;
      });

      assert.ok(errorCaught, 'Expected the controller to call next(err) on DB failure');
      assert.ok(errorMsg.includes('constraint'), `Expected constraint error, got: ${errorMsg}`);
      assert.strictEqual(insertCount, 3, 'Should have attempted 3 inserts before failure');

      db.withTransaction = savedFn;
    });
  });

  // ── Missing users response ───────────────────────────────────────────────
  describe('importRoster — missing users handling', () => {
    it('returns missing emails when createMissingUsers is false', async () => {
      const savedFn = db.withTransaction;

      db.withTransaction = async (fn) => {
        const mockClient = { query: async () => ({ rows: [] }) };
        return fn(mockClient);
      };

      let responseData;
      const mockRes = {
        json: (data) => { responseData = data; },
        status: () => mockRes,
      };
      const mockReq = {
        params: { id: 1 },
        body: { createMissingUsers: false },
        file: {
          buffer: Buffer.from('email,name\nunknown@test.com,Unknown User\n'),
          originalname: 'roster.csv',
          mimetype: 'text/csv',
        },
        user: { id: 1, role: 'instructor' },
      };

      await ctrl.importRoster(mockReq, mockRes, () => {});

      assert.ok(responseData, 'Should have a JSON response');
      assert.ok(responseData.missing, 'Response should include missing array');
      assert.strictEqual(responseData.missing.length, 1);
      assert.strictEqual(responseData.missing[0].email, 'unknown@test.com');
      assert.ok(responseData.message.includes('not found'));

      db.withTransaction = savedFn;
    });
  });

  // ── No file uploaded ─────────────────────────────────────────────────────
  describe('importRoster — no file', () => {
    it('returns 400 when no file is attached', async () => {
      let responseData;
      let responseStatus;
      const mockRes = {
        json: (data) => { responseData = data; },
        status: (code) => { responseStatus = code; return mockRes; },
      };
      const mockReq = {
        params: { id: 1 },
        body: {},
        file: null,
        user: { id: 1, role: 'instructor' },
      };

      await ctrl.importRoster(mockReq, mockRes, () => {});

      assert.strictEqual(responseStatus, 400);
      assert.ok(responseData.error.includes('No file'));
    });
  });
});

// ── Routes mount test ─────────────────────────────────────────────────────

describe('Sections Routes — Import & Export', () => {
  it('has bulk-import route (POST /:id/bulk-import)', () => {
    const router = require('../routes/sections');
    const routes = router.stack
      .filter(layer => layer.route)
      .map(layer => ({ path: layer.route.path, methods: Object.keys(layer.route.methods) }));

    const bulkImport = routes.find(r => r.path === '/:id/bulk-import');
    assert.ok(bulkImport, 'Should have /:id/bulk-import route');
    assert.ok(bulkImport.methods.includes('post'), 'Should accept POST');

    const exportRoute = routes.find(r => r.path === '/:id/export');
    assert.ok(exportRoute, 'Should have /:id/export route');
    assert.ok(exportRoute.methods.includes('get'), 'Should accept GET');
  });
});
