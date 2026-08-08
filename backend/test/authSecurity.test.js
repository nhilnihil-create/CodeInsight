const { isEduDomain, isTempEmail, getEmailDomain } = require('../lib/domainValidator');
const { generateOtp, storeOtp, verifyOtp } = require('../lib/otpStore');

describe('Auth Security', () => {
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

    it('should accept student role in registration', () => {
      const v = require('../lib/validators');
      const { error } = v.register.validate({
        name: 'Test',
        email: 'test@test.com',
        password: 'Test1234!',
        role: 'student',
      });
      expect(error).toBeUndefined();
    });

    it('should accept registration without explicit role', () => {
      const v = require('../lib/validators');
      const { error } = v.register.validate({
        name: 'Test',
        email: 'test@test.com',
        password: 'Test1234!',
      });
      expect(error).toBeUndefined();
    });

    it('should reject weak passwords', () => {
      const v = require('../lib/validators');
      const cases = [
        { pwd: 'short1A', expectError: true },
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

  describe('Domain validation', () => {
    it('should detect .edu domains', () => {
      expect(isEduDomain('psu.edu')).toBe(true);
      expect(isEduDomain('mit.edu')).toBe(true);
      expect(isEduDomain('pampanga.edu.ph')).toBe(true);
      expect(isEduDomain('ox.ac.uk')).toBe(true);
    });

    it('should reject non-edu domains', () => {
      expect(isEduDomain('gmail.com')).toBe(false);
      expect(isEduDomain('yahoo.com')).toBe(false);
      expect(isEduDomain('company.co.uk')).toBe(false);
    });

    it('should detect temp email domains', () => {
      expect(isTempEmail('mailinator.com')).toBe(true);
      expect(isTempEmail('guerrillamail.com')).toBe(true);
      expect(isTempEmail('10minutemail.com')).toBe(true);
    });

    it('should not flag normal domains as temp', () => {
      expect(isTempEmail('gmail.com')).toBe(false);
      expect(isTempEmail('psu.edu')).toBe(false);
    });
  });

  describe('OTP store', () => {
    afterEach(() => {
      jest.useRealTimers();
    });

    it('should generate 6-digit OTP', () => {
      const otp = generateOtp();
      expect(otp).toMatch(/^\d{6}$/);
    });

    it('should store and verify OTP', async () => {
      const otp = generateOtp();
      await storeOtp('alice@test.com', otp);
      const result = await verifyOtp('alice@test.com', otp);
      expect(result.valid).toBe(true);
    });

    it('should reject wrong OTP', async () => {
      await storeOtp('bob@test.com', '111111');
      const result = await verifyOtp('bob@test.com', '000000');
      expect(result.valid).toBe(false);
    });

    it('should block after 5 failed attempts', async () => {
      await storeOtp('spam@test.com', '123456');
      for (let i = 0; i < 5; i++) {
        await verifyOtp('spam@test.com', '000000');
      }
      const result = await verifyOtp('spam@test.com', '000000');
      expect(result.valid).toBe(false);
      expect(result.reason).toMatch(/too many|request a new/i);
    });
  });
});
