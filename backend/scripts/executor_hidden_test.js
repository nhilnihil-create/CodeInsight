const executor = require('../services/executor');

async function main() {
  const source = `#include <iostream>\nusing namespace std;\nint main(){int x; if(!(cin>>x)) return 0; cout<<x+1; return 0;}`;
  const testCases = [
    { input: '1', expected_output: '2', hidden: false },
    { input: '2', expected_output: '3', hidden: true }
  ];

  console.log('Running test cases through executor.runAgainstTestCases...');
  const results = await executor.runAgainstTestCases(source, testCases, 2);
  console.log('Results:', results);

  const hasHiddenFlag = results.some(r => 'hidden' in r);
  const visible = results.filter(r => !r.hidden);
  const hidden = results.filter(r => r.hidden);

  if (!hasHiddenFlag) {
    console.error('FAIL: hidden flag missing from results');
    process.exit(2);
  }
  if (visible.length !== 1 || hidden.length !== 1) {
    console.error('FAIL: expected 1 visible and 1 hidden result');
    process.exit(2);
  }

  console.log('PASS: hidden flag present and separation correct');
}

main().catch(err => { console.error(err); process.exit(1); });
