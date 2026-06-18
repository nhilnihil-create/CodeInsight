const { chromium } = require('playwright');
(async () => {
  const browser = await chromium.launch({ headless: false });
  const page = await browser.newPage();
  
  await page.goto('http://localhost:5173/login');
  await page.waitForLoadState('networkidle');
  await page.fill('input[type="email"]', 'perfect-maria@workflow.test');
  await page.fill('input[type="password"]', 'test1234');
  await page.click('button[type="submit"]');
  await page.waitForTimeout(3000);
  console.log('Logged in, URL:', page.url());
  
  await page.goto('http://localhost:5173/student/exercises/220');
  await page.waitForLoadState('networkidle');
  await page.waitForTimeout(3000);
  console.log('Exercise page URL:', page.url());
  
  const bodyText = await page.evaluate(() => document.body.innerText.substring(0, 800));
  console.log('Page text:', bodyText);
  
  const hasMonaco = await page.evaluate(() => !!window.monaco);
  console.log('Has Monaco:', hasMonaco);
  
  const editorVisible = await page.locator('.monaco-editor').isVisible().catch(() => false);
  console.log('Monaco editor visible:', editorVisible);
  
  await page.screenshot({ path: '/tmp/exercise-check.png', fullPage: true });
  console.log('Screenshot saved');
  
  await browser.close();
})();
