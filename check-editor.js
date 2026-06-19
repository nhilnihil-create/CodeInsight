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
  
  await page.goto('http://localhost:5173/student/exercises/220');
  await page.waitForLoadState('networkidle');
  await page.waitForTimeout(3000);
  
  // Check all possible editor selectors
  const selectors = ['.monaco-editor', '.monaco-editor .overflow-guard', '[data-mode-id]', '.view-lines', '.monaco-editor .inputarea', 'textarea.inputarea', '.monaco-editor .editor-scrollable'];
  for (const sel of selectors) {
    const count = await page.locator(sel).count();
    const vis = count > 0 ? await page.locator(sel).first().isVisible().catch(() => false) : false;
    console.log(`${sel}: count=${count}, visible=${vis}`);
  }
  
  // Check if monaco API is available
  const hasMonaco = await page.evaluate(() => {
    if (!window.monaco) return 'no monaco';
    const models = window.monaco.editor.getModels();
    return `models=${models.length}, value=${models[0]?.getValue()?.substring(0, 50)}`;
  });
  console.log('Monaco API:', hasMonaco);
  
  // Try to set value via Monaco API
  const setValueResult = await page.evaluate(() => {
    try {
      const models = window.monaco.editor.getModels();
      if (models.length > 0) {
        models[0].setValue('#include <iostream>\nusing namespace std;\nint main() { cout << 42; return 0; }');
        return 'Set value: ' + models[0].getValue().substring(0, 50);
      }
      return 'No models found';
    } catch (e) { return 'Error: ' + e.message; }
  });
  console.log('Set value result:', setValueResult);
  
  await page.screenshot({ path: '/tmp/editor-check.png', fullPage: true });
  await browser.close();
})();
