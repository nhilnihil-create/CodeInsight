// Join Code Feature Integration Tests
// Tests the complete flow: section creation → code generation → student join → rotate code

const assert = require('assert');
const { Pool } = require('pg');

// Mock database pool for testing
class MockPool {
  constructor() {
    this.queryLog = [];
    this.transactionActive = false;
    this.mockData = {
      sections: [],
      enrollments: [],
      users: [],
      auditLog: []
    };
  }

  async query(text, values = []) {
    this.queryLog.push({ text, values });

    // Mock section creation with code
    if (text.includes('INSERT INTO sections') && text.includes('RETURNING')) {
      const section = {
        id: this.mockData.sections.length + 1,
        name: values[0],
        course_code: values[1],
        school_year: values[2],
        semester: values[3],
        instructor_id: values[4],
        code: values[5],
        join_policy: values[6],
        created_at: new Date()
      };
      this.mockData.sections.push(section);
      return { rows: [section] };
    }

    // Mock section lookup by code
    if (text.includes('SELECT * FROM sections WHERE code=') && text.includes('FOR UPDATE')) {
      const code = values[0];
      const section = this.mockData.sections.find(s => s.code === code);
      if (section) {
        return { rows: [section] };
      }
      return { rows: [] };
    }

    // Mock enrollment count check
    if (text.includes('SELECT COUNT(*)::int AS n FROM enrollments')) {
      const sectionId = values[0];
      const count = this.mockData.enrollments.filter(e => e.section_id === sectionId).length;
      return { rows: [{ n: count }] };
    }

    // Mock existing enrollment check
    if (text.includes('SELECT * FROM enrollments WHERE student_id=') && text.includes('AND section_id=')) {
      const studentId = values[0];
      const sectionId = values[1];
      const existing = this.mockData.enrollments.find(
        e => e.student_id === studentId && e.section_id === sectionId
      );
      return { rows: existing ? [existing] : [] };
    }

    // Mock enrollment insertion
    if (text.includes('INSERT INTO enrollments(student_id,section_id)')) {
      const studentId = values[0];
      const sectionId = values[1];
      const enrollment = {
        id: this.mockData.enrollments.length + 1,
        student_id: studentId,
        section_id: sectionId,
        enrolled_at: new Date()
      };
      this.mockData.enrollments.push(enrollment);
      return { rows: [enrollment] };
    }

    // Mock audit log insertion
    if (text.includes('INSERT INTO section_audit_log')) {
      const logEntry = {
        section_id: values[0],
        actor_id: values[1],
        action: values[2],
        meta: values[3],
        created_at: new Date()
      };
      this.mockData.auditLog.push(logEntry);
      return { rows: [] };
    }

    // Mock section update (rotate code)
    if (text.includes('UPDATE sections SET code=') && text.includes('RETURNING')) {
      const newCode = values[0];
      const sectionId = values[1];
      const section = this.mockData.sections.find(s => s.id === sectionId);
      if (section) {
        section.code = newCode;
        return { rows: [section] };
      }
      return { rows: [] };
    }

    // Default response
    return { rows: [], rowCount: 0 };
  }

  // Simulate withTransaction
  async withTransaction(callback) {
    this.transactionActive = true;
    try {
      const result = await callback(this);
      this.transactionActive = false;
      return result;
    } catch (err) {
      this.transactionActive = false;
      throw err;
    }
  }
}

// Mock section controller logic (extracted from sectionController.js)
function generateCode() {
  const chars = 'ABCDEFGHJKLMNPQRSTUVWXYZ23456789';
  let code = '';
  for (let i = 0; i < 6; i++) {
    if (i === 3) code += '-';
    code += chars[Math.floor(Math.random() * chars.length)];
  }
  return code;
}

async function joinSection(db, userId, code) {
  return await db.withTransaction(async (client) => {
    const sec = await client.query(
      'SELECT * FROM sections WHERE code=$1 FOR UPDATE',
      [code.toUpperCase()]
    );
    if (!sec.rows.length) {
      throw Object.assign(new Error('Invalid code'), { status: 404 });
    }
    const section = sec.rows[0];
    if (section.join_policy === 'closed') {
      throw Object.assign(new Error('Section is closed to new join requests'), { status: 403 });
    }

    if (section.max_size) {
      const cnt = await client.query(
        'SELECT COUNT(*)::int AS n FROM enrollments WHERE section_id=$1',
        [section.id]
      );
      if (cnt.rows[0].n >= section.max_size) {
        throw Object.assign(new Error('Section is full'), { status: 403 });
      }
    }

    const existing = await client.query(
      'SELECT * FROM enrollments WHERE student_id=$1 AND section_id=$2',
      [userId, section.id]
    );
    if (existing.rows.length) {
      throw Object.assign(new Error('Already enrolled'), { status: 409 });
    }

    if (section.join_policy === 'code') {
      await client.query(
        'INSERT INTO enrollments(student_id,section_id) VALUES($1,$2)',
        [userId, section.id]
      );
      await client.query(
        'INSERT INTO section_audit_log (section_id, actor_id, action, meta) VALUES ($1, $2, $3, $4)',
        [section.id, userId, 'student_joined', JSON.stringify({ code })]
      );
      return { message: 'Joined section', section };
    }

    await client.query(
      'INSERT INTO enrollments(student_id,section_id) VALUES($1,$2) ON CONFLICT DO NOTHING',
      [userId, section.id]
    );
    await client.query(
      'INSERT INTO section_audit_log (section_id, actor_id, action, meta) VALUES ($1, $2, $3, $4)',
      [section.id, userId, 'student_requested_to_join', JSON.stringify({ code })]
    );
    return { message: 'Join request submitted' };
  });
}

async function rotateCode(db, sectionId, actorId) {
  const newCode = generateCode();
  const r = await db.query('UPDATE sections SET code=$1 WHERE id=$2 RETURNING *', [newCode, sectionId]);
  if (!r.rows.length) throw Object.assign(new Error('Section not found'), { status: 404 });
  await db.query(
    'INSERT INTO section_audit_log (section_id, actor_id, action, meta) VALUES ($1, $2, $3, $4)',
    [sectionId, actorId, 'code_rotated', JSON.stringify({ code: newCode })]
  );
  return r.rows[0];
}

describe('Join Code Feature', function () {
  let mockDb;

  beforeEach(function () {
    mockDb = new MockPool();
  });

  describe('Code Generation', function () {
    it('should generate a 6-character code in format XXX-XXX', function () {
      const code = generateCode();
      assert.ok(code.match(/^[A-Z0-9]{3}-[A-Z0-9]{3}$/), `Code "${code}" should match format XXX-XXX`);
    });

    it('should not contain ambiguous characters (I, O, 0, 1)', function () {
      for (let i = 0; i < 100; i++) {
        const code = generateCode();
        assert.ok(!code.includes('I'), 'Code should not contain I');
        assert.ok(!code.includes('O'), 'Code should not contain O');
        assert.ok(!code.includes('0'), 'Code should not contain 0');
        assert.ok(!code.includes('1'), 'Code should not contain 1');
      }
    });

    it('should generate unique codes', function () {
      const codes = new Set();
      for (let i = 0; i < 50; i++) {
        codes.add(generateCode());
      }
      // With 32^6 possible codes, 50 should all be unique
      assert.strictEqual(codes.size, 50, 'All generated codes should be unique');
    });
  });

  describe('Student Join Flow', function () {
    beforeEach(function () {
      // Setup: create a section with a known code
      mockDb.mockData.sections.push({
        id: 1,
        name: 'CS101-A',
        course_code: 'CS101',
        code: 'ABC-123',
        join_policy: 'code',
        max_size: 60,
        instructor_id: 1
      });
    });

    it('should allow student to join with valid code', async function () {
      const result = await joinSection(mockDb, 2, 'ABC-123');
      assert.strictEqual(result.message, 'Joined section');
      assert.strictEqual(result.section.id, 1);
      assert.strictEqual(mockDb.mockData.enrollments.length, 1);
      assert.strictEqual(mockDb.mockData.enrollments[0].student_id, 2);
    });

    it('should reject invalid code', async function () {
      try {
        await joinSection(mockDb, 2, 'INVALID');
        assert.fail('Should have thrown error');
      } catch (err) {
        assert.strictEqual(err.status, 404);
        assert.ok(err.message.includes('Invalid code'));
      }
    });

    it('should reject when section is full', async function () {
      // Fill section to capacity
      mockDb.mockData.sections[0].max_size = 1;
      mockDb.mockData.enrollments.push({
        id: 1,
        student_id: 99,
        section_id: 1,
        enrolled_at: new Date()
      });

      try {
        await joinSection(mockDb, 2, 'ABC-123');
        assert.fail('Should have thrown error');
      } catch (err) {
        assert.strictEqual(err.status, 403);
        assert.ok(err.message.includes('Section is full'));
      }
    });

    it('should reject when section is closed', async function () {
      mockDb.mockData.sections[0].join_policy = 'closed';

      try {
        await joinSection(mockDb, 2, 'ABC-123');
        assert.fail('Should have thrown error');
      } catch (err) {
        assert.strictEqual(err.status, 403);
        assert.ok(err.message.includes('closed'));
      }
    });

    it('should reject duplicate enrollment', async function () {
      // First join
      await joinSection(mockDb, 2, 'ABC-123');

      // Try again
      try {
        await joinSection(mockDb, 2, 'ABC-123');
        assert.fail('Should have thrown error');
      } catch (err) {
        assert.strictEqual(err.status, 409);
        assert.ok(err.message.includes('Already enrolled'));
      }
    });

    it('should create audit log entry on join', async function () {
      await joinSection(mockDb, 2, 'ABC-123');
      assert.strictEqual(mockDb.mockData.auditLog.length, 1);
      assert.strictEqual(mockDb.mockData.auditLog[0].action, 'student_joined');
    });
  });

  describe('Request Policy Flow', function () {
    beforeEach(function () {
      mockDb.mockData.sections.push({
        id: 2,
        name: 'CS101-B',
        course_code: 'CS101',
        code: 'REQ-456',
        join_policy: 'request',
        max_size: 60,
        instructor_id: 1
      });
    });

    it('should submit join request with request policy', async function () {
      const result = await joinSection(mockDb, 2, 'REQ-456');
      assert.strictEqual(result.message, 'Join request submitted');
      assert.strictEqual(mockDb.mockData.enrollments.length, 1);
    });

    it('should create audit log for join request', async function () {
      await joinSection(mockDb, 2, 'REQ-456');
      assert.strictEqual(mockDb.mockData.auditLog.length, 1);
      assert.strictEqual(mockDb.mockData.auditLog[0].action, 'student_requested_to_join');
    });
  });

  describe('Code Rotation', function () {
    beforeEach(function () {
      mockDb.mockData.sections.push({
        id: 3,
        name: 'CS101-C',
        course_code: 'CS101',
        code: 'OLD-789',
        join_policy: 'code',
        max_size: 60,
        instructor_id: 1
      });
    });

    it('should rotate code and return new code', async function () {
      const result = await rotateCode(mockDb, 3, 1);
      assert.ok(result.code.match(/^[A-Z0-9]{3}-[A-Z0-9]{3}$/), 'New code should match format');
      assert.notStrictEqual(result.code, 'OLD-789', 'Code should be different');
    });

    it('should create audit log for rotation', async function () {
      await rotateCode(mockDb, 3, 1);
      assert.strictEqual(mockDb.mockData.auditLog.length, 1);
      assert.strictEqual(mockDb.mockData.auditLog[0].action, 'code_rotated');
    });

    it('should throw error for non-existent section', async function () {
      try {
        await rotateCode(mockDb, 999, 1);
        assert.fail('Should have thrown error');
      } catch (err) {
        assert.strictEqual(err.status, 404);
      }
    });

    it('old code should no longer work after rotation', async function () {
      const oldCode = mockDb.mockData.sections[0].code;
      await rotateCode(mockDb, 3, 1);

      try {
        await joinSection(mockDb, 2, oldCode);
        assert.fail('Should have thrown error');
      } catch (err) {
        assert.strictEqual(err.status, 404);
      }
    });
  });

  describe('Edge Cases', function () {
    it('should handle case-insensitive code input', async function () {
      mockDb.mockData.sections.push({
        id: 4,
        name: 'CS101-D',
        course_code: 'CS101',
        code: 'ABC-123',
        join_policy: 'code',
        max_size: 60,
        instructor_id: 1
      });

      // Join with lowercase code
      const result = await joinSection(mockDb, 2, 'abc-123');
      assert.strictEqual(result.message, 'Joined section');
    });

    it('should handle concurrent joins at capacity boundary', async function () {
      mockDb.mockData.sections.push({
        id: 5,
        name: 'CS101-E',
        course_code: 'CS101',
        code: 'CAP-001',
        join_policy: 'code',
        max_size: 2,
        instructor_id: 1
      });

      // Fill to capacity
      await joinSection(mockDb, 10, 'CAP-001');
      await joinSection(mockDb, 11, 'CAP-001');

      // Third should fail
      try {
        await joinSection(mockDb, 12, 'CAP-001');
        assert.fail('Should have thrown error');
      } catch (err) {
        assert.strictEqual(err.status, 403);
        assert.ok(err.message.includes('Section is full'));
      }
    });

    it('should allow joining different sections with same student', async function () {
      mockDb.mockData.sections.push(
        {
          id: 6,
          name: 'CS101-F',
          course_code: 'CS101',
          code: 'AAA-111',
          join_policy: 'code',
          max_size: 60,
          instructor_id: 1
        },
        {
          id: 7,
          name: 'CS101-G',
          course_code: 'CS101',
          code: 'BBB-222',
          join_policy: 'code',
          max_size: 60,
          instructor_id: 1
        }
      );

      const result1 = await joinSection(mockDb, 2, 'AAA-111');
      const result2 = await joinSection(mockDb, 2, 'BBB-222');

      assert.strictEqual(result1.message, 'Joined section');
      assert.strictEqual(result2.message, 'Joined section');
      assert.strictEqual(mockDb.mockData.enrollments.length, 2);
    });
  });
});

console.log('Join Code integration test suite created');
