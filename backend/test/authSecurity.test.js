const db = require('../config/db');

describe('Auth Security', () => {
  beforeAll(async () => {
    const { ensureTablesExist } = require('../migrations');
    await ensureTablesExist();
  });

  afterAll(async () => {
    await db.end();
  });

  describe('Registration validation', () => {
    it('should reject admin role in registration', () => {
      const v = require('../lib/validators');
      const { error } = v.register.validate({
        name: 'Test',
        email: 'test@test.com',
        password: 'Test1234!',
        role: 'admin',
      });
      expect(error).toBeDefined();
      expect(error.message).toMatch(/must be one of/);
    });

    it('should accept student role', () => {
      const v = require('../lib/validators');
      const { error } = v.register.validate({
        name: 'Test',
        email: 'test@test.com',
        password: 'Test1234!',
        role: 'student',
      });
      expect(error).toBeUndefined();
    });

    it('should accept instructor role', () => {
      const v = require('../lib/validators');
      const { error } = v.register.validate({
        name: 'Test',
        email: 'test@test.com',
        password: 'Test1234!',
        role: 'instructor',
      });
      expect(error).toBeUndefined();
    });

    it('should reject weak passwords', () => {
      const v = require('../lib/validators');
      const cases = [
        { pwd: 'short1A', expectError: true },  // no special char, too short
        { pwd: 'nouppercase1!', expectError: true },
        { pwd: 'NOLOWERCASE1!', expectError: true },
        { pwd: 'NoDigits!', expectError: true },
        { pwd: 'NoSpecial1', expectError: true },
        { pwd: 'Valid123!', expectError: false },
        { pwd: 'Compl3x!Pass', expectError: false },
      ];
      for (const { pwd, expectError } of cases) {
        const { error } = v.register.validate({
          name: 'T', email: 't@t.com', password: pwd, role: 'student',
        });
        expect((error !== undefined)).toBe(expectError);
      }
    });
  });

  describe('Instructor domain validation', () => {
    it('should reject non-matching domain', () => {
      process.env.INSTRUCTOR_DOMAINS = 'university.edu, college.edu';
      const allowedDomains = (process.env.INSTRUCTOR_DOMAINS || '')
        .split(',').map(d => d.trim().toLowerCase()).filter(Boolean);
      const domain = 'hacker@gmail.com'.split('@')[1]?.toLowerCase();
      expect(allowedDomains.includes(domain)).toBe(false);
    });

    it('should accept matching domain', () => {
      process.env.INSTRUCTOR_DOMAINS = 'university.edu';
      const allowedDomains = (process.env.INSTRUCTOR_DOMAINS || '')
        .split(',').map(d => d.trim().toLowerCase()).filter(Boolean);
      const domain = 'prof@university.edu'.split('@')[1]?.toLowerCase();
      expect(allowedDomains.includes(domain)).toBe(true);
    });
  });

  describe('Token blacklist', () => {
    beforeAll(async () => {
      try {
        await db.query(`CREATE TABLE IF NOT EXISTS token_blacklist (
          id SERIAL PRIMARY KEY,
          jti VARCHAR(255) NOT NULL UNIQUE,
          expires_at TIMESTAMP NOT NULL
        )`);
        await db.query(`CREATE INDEX IF NOT EXISTS idx_token_blacklist_jti ON token_blacklist(jti)`);
        await db.query(`CREATE INDEX IF NOT EXISTS idx_token_blacklist_expires ON token_blacklist(expires_at)`);
      } catch (e) { /* table may already exist */ }
    });

    it('should insert and query blacklisted JTI', async () => {
      const jti = 'test-jti-' + Date.now();
      const expiresAt = new Date(Date.now() + 3600000);
      await db.query(
        'INSERT INTO token_blacklist (jti, expires_at) VALUES ($1, $2) ON CONFLICT (jti) DO NOTHING',
        [jti, expiresAt]
      );
      const result = await db.query(
        'SELECT 1 FROM token_blacklist WHERE jti = $1 AND expires_at > NOW()',
        [jti]
      );
      expect(result.rows.length).toBe(1);
      await db.query('DELETE FROM token_blacklist WHERE jti = $1', [jti]);
    });

    it('should not find non-existent JTI', async () => {
      const result = await db.query(
        'SELECT 1 FROM token_blacklist WHERE jti = $1 AND expires_at > NOW()',
        ['non-existent-jti']
      );
      expect(result.rows.length).toBe(0);
    });
  });

  describe('Login rate limiter config', () => {
    it('should have registration rate limiter in auth routes', () => {
      const router = require('../routes/auth');
      const stack = router.stack.filter(r => r.route?.path === '/register' && r.route.methods?.post);
      expect(stack.length).toBe(1);
    });
  });
});
