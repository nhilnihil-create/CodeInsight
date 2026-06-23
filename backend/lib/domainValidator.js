const dns = require('dns');
const { promisify } = require('util');

const resolveMx = promisify(dns.resolveMx);

const EDU_TLDS = new Set([
  'edu', 'edu.au', 'edu.cn', 'edu.hk', 'edu.in', 'edu.ph',
  'edu.sg', 'edu.my', 'edu.pk', 'edu.eg', 'edu.sa', 'ac.uk',
  'ac.in', 'ac.jp', 'ac.kr', 'ac.nz', 'ac.za', 'ac.il',
  'ac.th', 'ac.id', 'ac.cn', 'edu.tw', 'edu.vn', 'edu.tr',
  'edu.mx', 'edu.ar', 'edu.co', 'edu.br', 'edu.pe', 'edu.ec',
]);

const TEMP_EMAIL_DOMAINS = new Set([
  'mailinator.com', 'guerrillamail.com', '10minutemail.com',
  'tempmail.com', 'throwaway.email', 'yopmail.com', 'sharklasers.com',
  'temp-mail.org', 'mailnator.com', 'getnada.com', 'emailfake.com',
  'tempmail.net', 'tempemail.net', 'trashmail.com', 'mailexpire.com',
  'edumailfree.com', 'edumail.me', 'studentmail.me', 'schoolmail.me',
  'freemail.edu', 'fakemail.edu', 'dispostable.com', 'maildrop.cc',
  'spamgourmet.com', 'emailondeck.com', 'mailmetrash.com', 'thankyou2010.com',
  'trash2009.com', 'mytempemail.com', 'tempinbox.com', 'temp-mail.info',
  'mailmoat.com', 'spambox.us', 'temp-emails.com', 'temporarymail.org',
]);

const UNIVERSITY_WHITELIST = new Set([
  'psu.edu', 'pampanga.edu.ph', 'up.edu.ph', 'dlsu.edu.ph',
  'ust.edu.ph', 'ateneo.edu', 'mit.edu', 'stanford.edu',
  'harvard.edu', 'berkeley.edu', 'cmu.edu', 'gatech.edu',
  'illinois.edu', 'umich.edu', 'ucla.edu', 'washington.edu',
  'utexas.edu', 'uwisc.edu', 'purdue.edu', 'osu.edu',
  'tamu.edu', 'ncsu.edu', 'vt.edu', 'cambridge.org',
  'ox.ac.uk', 'ic.ac.uk', 'ucl.ac.uk', 'ed.ac.uk',
  'nus.edu.sg', 'ntu.edu.sg', 'kyoto-u.ac.jp', 'tokyo.ac.jp',
  'unsw.edu.au', 'usyd.edu.au', 'unimelb.edu.au', 'anu.edu.au',
  'utoronto.ca', 'ubc.ca', 'mcgill.ca',
]);

function getEmailDomain(email) {
  const parts = email.split('@');
  if (parts.length !== 2) return null;
  return parts[1].toLowerCase().trim();
}

function isEduDomain(domain) {
  const parts = domain.split('.');
  if (parts.length < 2) return false;
  const tld = parts.slice(-2).join('.');
  const last = parts[parts.length - 1];
  if (EDU_TLDS.has(tld)) return true;
  if (last === 'edu') return true;
  return false;
}

function isTempEmail(domain) {
  return TEMP_EMAIL_DOMAINS.has(domain);
}

function isUniversityWhitelisted(domain) {
  return UNIVERSITY_WHITELIST.has(domain);
}

async function checkMxRecords(domain) {
  try {
    const records = await resolveMx(domain);
    return records && records.length > 0;
  } catch {
    return false;
  }
}

async function validateEmailDomain(email) {
  const domain = getEmailDomain(email);
  if (!domain) {
    return { valid: false, isUniversity: false, reason: 'Invalid email format' };
  }

  if (isTempEmail(domain)) {
    return { valid: false, isUniversity: false, reason: 'Temporary email addresses are not allowed' };
  }

  const isEdu = isEduDomain(domain);
  const isWhitelisted = isUniversityWhitelisted(domain);
  const isUniversity = isEdu || isWhitelisted;

  const hasMx = await checkMxRecords(domain);
  if (!hasMx) {
    return { valid: false, isUniversity, reason: 'Domain cannot receive emails' };
  }

  return { valid: true, isUniversity };
}

module.exports = { validateEmailDomain, isEduDomain, isTempEmail, isUniversityWhitelisted, checkMxRecords };
