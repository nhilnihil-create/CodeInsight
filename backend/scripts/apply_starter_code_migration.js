const db = require('../config/db');

const snippet = `#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  int sum = 0;\n  for (int i = 1; i <= n; i++) {\n    sum += i;\n  }\n  cout << sum;\n  return 0;\n}\n`;

async function run() {
  try {
    console.log('Applying starter_code migration...');
    await db.query('BEGIN');
    const res = await db.query(
      `UPDATE exercises SET starter_code = $1 WHERE starter_code IS NULL OR starter_code LIKE '%// Write code here%'`,
      [snippet]
    );
    await db.query('COMMIT');
    console.log(`Updated ${res.rowCount} exercises`);
    process.exit(0);
  } catch (err) {
    await db.query('ROLLBACK').catch(()=>{});
    console.error('Migration failed:', err.message);
    process.exit(1);
  }
}

run();
