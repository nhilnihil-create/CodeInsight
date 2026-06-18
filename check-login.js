const { chromium } = require('playwright');
(async () => {
  const browser = await chromium.launch({ headless: false });
  const page = await browser.newPage();
  
  await page.goto('http://localhost:5173/login');
  await page.waitForLoadState('networkidle');
  await page.waitForTimeout(2000);
  
  // Check form elements
  const inputs = await page.locator('input').all();
  for (const input of inputs) {
    const type = await input.getAttribute('type');
    const name = await input.getAttribute('name');
    const placeholder = await input.getAttribute('placeholder');
    console.log(`Input: type=${type}, name=${name}, placeholder=${placeholder}`);
  }
  
  const buttons = await page.locator('button').all();
  for (const btn of buttons) {
    const text = await btn.innerText();
    const type = await btn.getAttribute('type');
    console.log(`Button: type=${type}, text="${text}"`);
  }
  
  // Try to login
  const emailInput = page.locator('input[type="email"]').first();
  const passInput = page.locator('input[type="password"]').first();
  
  console.log('Email visible:', await emailInput.isVisible().catch(() => false));
  console.log('Password visible:', await passInput.isVisible().catch(() => false));
  
  await emailInput.fill('perfect-maria@workflow.test');
  await passInput.fill('test1234');
  
  // Listen for console errors
  page.on('console', msg => {
    if (msg.type() === 'error') console.log('Console error:', msg.text());
  });
  
  // Listen for network errors
  page.on('requestfailed', req => {
    console.log('Request failed:', req.url(), req.failure().errorText);
  });
  
  await page.click('button[type="submit"]');
  await page.waitForTimeout(5000);
  console.log('After submit URL:', page.url());
  
  // Check for error messages
  const bodyText = await page.evaluate(() => document.body.innerText);
  if (bodyText.includes('Invalid') || bodyText.includes('error') || bodyText.includes('Error')) {
    console.log('Error found in page:', bodyText.substring(0, 300));
  }
  
  await page.screenshot({ path: '/tmp/login-check.png', fullPage: true });
  await browser.close();
})();
