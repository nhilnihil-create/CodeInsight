const ast = require('../services/astVerifier');

async function main() {
  const starter = '#include <iostream>\nusing namespace std;\nint main(){ return 0; }';
  const templateRes = await ast.verify(starter, {}, { starter_code: starter });
  console.log('Template verification result:', templateRes);

  const code = '#include <iostream>\nusing namespace std;\nint main(){ int x; cin>>x; cout<<x; return 0; }';
  const goodRes = await ast.verify(code, { required_nodes: ['if_statement'] }, { starter_code: starter });
  console.log('Non-template verification result:', goodRes);
}

main().catch(err=>{ console.error(err); process.exit(1); });
