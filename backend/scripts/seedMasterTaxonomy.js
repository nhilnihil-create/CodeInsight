/**
 * Seed Script: Master Taxonomy (Phase 2)
 *
 * Seeds:
 *   1. Expand concepts from 7 → 20 (ACM/IEEE CS2023-inspired)
 *   2. Complete concept dependency graph
 *   3. Seed 30 AIZU ITP1 exercises from CodeNet with concept tags
 *   4. Verify learning outcome mappings
 *
 * Run: node backend/scripts/seedMasterTaxonomy.js
 *
 * CDS COMPATIBILITY: All inserts use ON CONFLICT DO NOTHING / DO UPDATE.
 * Existing exercises and CDS data are never modified.
 */

require('dotenv').config();
const { Pool } = require('pg');

function generateCode() {
  const chars = 'ABCDEFGHJKLMNPQRSTUVWXYZ23456789';
  let code = '';
  for (let i = 0; i < 6; i++) {
    if (i === 3) code += '-';
    code += chars[Math.floor(Math.random() * chars.length)];
  }
  return code;
}

const db = new Pool({
  host: process.env.DB_HOST,
  port: parseInt(process.env.DB_PORT || '5432'),
  database: process.env.DB_NAME,
  user: process.env.DB_USER,
  password: process.env.DB_PASSWORD,
  ssl: process.env.DB_SSL ? { rejectUnauthorized: false } : undefined,
});

// ── Shared required-pattern definitions (JSON-mirror of astVerifier) ──────
// Exercises reference these in their `required_patterns` array; the insert
// path stringifies them into the exercises.required_patterns JSONB column.

const P_IO_OUTPUT = { query: '[(binary_expression operator: "<<") (call_expression)]', label: 'stream output (cout <<) or printf', hint: 'your solution must print using cout << or printf' };
const P_LOOP = { query: '[(for_statement) (while_statement) (do_statement)]', label: 'a loop', hint: 'your solution must use a loop' };
const P_CONDITIONAL = { query: '[(if_statement) (switch_statement)]', label: 'an if or switch statement', hint: 'your solution must branch with if or switch — ternary-only solutions are rejected' };
const P_ARRAY_USAGE = { query: '[(array_declarator) (subscript_expression)]', label: 'an array', hint: 'your solution must store the values in an array' };
const P_STRING_TYPE = { kind: 'string_type', label: 'a std::string variable', hint: 'declare your strings with the string type (e.g. string name;)' };
const P_SELF_CALL = { kind: 'self_call', label: 'a recursive call', hint: 'your solution must call a function from within itself' };
const P_NO_LOOPS = { kind: 'forbidden', node: ['for_statement', 'while_statement', 'do_statement'], label: 'loops', hint: 'recursion exercises must not use loops — call the function from within itself' };
const P_USER_FUNCTION = { kind: 'user_function', label: 'a function other than main', hint: 'your solution must define and use a function other than main' };
const P_MIN_LOOPS2 = { kind: 'min_count', node: ['for_statement', 'while_statement', 'do_statement'], min: 2, label: 'at least two loops', hint: 'your solution must use nested loops (a loop inside a loop)' };

// ── 1. Expand concepts to 20 rows ──────────────────────────────────────────

const NEW_CONCEPTS = [
  // [name, knowledge_area_code, slug, bloom_level, ast_nodes[]]
  ['File I/O',        'SDF-FPC', 'file-io',        'apply',    ['function_definition']],
  ['Scope',           'SDF-PMD', 'scope',          'analyze',  []],
  ['Enums',           'SDF-FPC', 'enums',          'understand', []],
  ['Structs',         'SDF-FDS', 'structs',        'understand', ['struct_specifier']],
  ['Pointers',        'SDF-FDS', 'pointers',       'analyze',  ['pointer_declarator','pointer_expression']],
  ['Strings',         'SDF-FPC', 'strings',        'understand', []],
  ['Input/Output',    'SDF-FPC', 'input-output',   'apply',    []],
  ['Switch/Case',     'SDF-PMD', 'switch-case',    'apply',    ['switch_statement']],
  ['Nested Loops',    'SDF-PMD', 'nested-loops',   'analyze',  ['for_statement','while_statement']],
  ['Recursion',       'SDF-PMD', 'recursion',      'evaluate', ['function_definition']],
  ['Dynamic Memory',  'SDF-FDS', 'dynamic-memory', 'analyze',  ['new_expression','call_expression']],
  ['Linked Lists',    'SDF-FDS', 'linked-lists',   'analyze',  ['struct_declaration','pointer_declarator']],
  ['Error Handling',  'SDF-PMD', 'error-handling', 'apply',    ['if_statement']],
  ['Type Casting',    'SDF-FPC', 'type-casting',   'understand', ['cast_expression']],
  ['Preprocessor',    'SDF-OOP', 'preprocessor',   'remember', []],
  ['Namespaces',      'SDF-OOP', 'namespaces',     'understand', []],
  ['Inheritance',     'SDF-OOP', 'inheritance',    'apply',    ['class_specifier']],
  ['Polymorphism',    'SDF-OOP', 'polymorphism',   'evaluate', ['class_specifier','function_definition']],
];

// ── 2. Additional dependencies ─────────────────────────────────────────────

const NEW_DEPS = [
  // [parent, child, weight]
  ['Arrays', 'Strings', 0.5],
  ['Arrays', 'Pointers', 0.8],
  ['Pointers', 'Dynamic Memory', 1.0],
  ['Pointers', 'Linked Lists', 1.0],
  ['Structs', 'Linked Lists', 0.7],
  ['Functions', 'Recursion', 1.0],
  ['Recursion', 'Linked Lists', 0.3],
  ['Conditionals', 'Switch/Case', 0.5],
  ['Loops', 'Nested Loops', 1.0],
  ['Variables', 'Type Casting', 0.3],
  ['Datatypes', 'Type Casting', 0.5],
  ['Functions', 'Error Handling', 0.3],
  ['Input/Output', 'File I/O', 1.0],
  ['Datatypes', 'Enums', 0.5],
  ['Datatypes', 'Structs', 0.5],
  ['Structs', 'OOP', 0.3],
  ['OOP', 'Inheritance', 1.0],
  ['OOP', 'Polymorphism', 1.0],
  ['Inheritance', 'Polymorphism', 0.7],
  ['Loops', 'File I/O', 0.3],
  ['Conditionals', 'Error Handling', 0.5],
  ['Variables', 'Scope', 1.0],
  ['Functions', 'Scope', 0.8],
  ['Functions', 'Namespaces', 0.3],
  ['Preprocessor', 'Input/Output', 0.3],
];

// ── 3. AIZU ITP1 exercises (30 exercises, ~20 unique problems + variants) ───

const CODENET_EXERCISES = [
  {
    title: 'Print Hello World',
    description: 'Write a program that prints "Hello World" on a single line.',
    concept: 'Input/Output',
    secondary_concepts: [],
    required_patterns: [P_IO_OUTPUT],
    test_cases: [
      { input: '', expected: 'Hello World', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Print Hello World\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint main() { cout << "Hello World" << endl; return 0; }',
  },
  {
    title: 'Print Test Cases',
    description: 'Given a number x, print its square. Repeat until x is 0.',
    concept: 'Input/Output',
    secondary_concepts: ['Loops'],
    required_patterns: [P_IO_OUTPUT, P_LOOP],
    test_cases: [
      { input: '5', expected: '25', passed: false },
      { input: '3', expected: '9', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Read integers and print their squares until 0\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint main() { int x; while(cin>>x && x!=0) cout << x*x << endl; return 0; }',
  },
  {
    title: 'Formal Name Formatter',
    description: 'Given three strings (first, middle, last name), output the formatted name: "Last, First M."',
    concept: 'Strings',
    secondary_concepts: ['Input/Output'],
    required_patterns: [P_STRING_TYPE],
    test_cases: [
      { input: 'John\nFitzgerald\nKennedy', expected: 'Kennedy, John F.', passed: false },
    ],
    starter_code: '#include <iostream>\n#include <string>\nusing namespace std;\n\nint main() {\n  // Format name output\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\n#include <string>\nusing namespace std;\nint main() { string f,m,l; cin>>f>>m>>l; cout << l << ", " << f << " " << m[0] << "." << endl; return 0; }',
  },
  {
    title: 'Simple Calculator',
    description: 'Read two integers and an operator (+, -, *, /). Print the result. Division truncates toward zero.',
    concept: 'Conditionals',
    secondary_concepts: ['Input/Output'],
    required_patterns: [P_CONDITIONAL],
    test_cases: [
      { input: '1 + 2', expected: '3', passed: false },
      { input: '5 - 3', expected: '2', passed: false },
      { input: '4 * 5', expected: '20', passed: false },
      { input: '7 / 2', expected: '3', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Read two integers and an operator, print result\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint main() { int a,b; char op; while(cin>>a>>op>>b) { int r = (op=='+')?(a+b):(op=='-')?(a-b):(op=='*')?(a*b):(a/b); cout << r << endl; } return 0; }',
  },
  {
    title: 'Print Many Numbers',
    description: 'Print integers from 1 to N, each on a separate line.',
    concept: 'Loops',
    secondary_concepts: ['Input/Output'],
    // Strict per-exercise structure requirement: this exercise must be solved
    // with a for loop (recursion or while-only solutions fail verification).
    ast_nodes: ['for_statement'],
    test_cases: [
      { input: '5', expected: '1\n2\n3\n4\n5', passed: false },
      { input: '1', expected: '1', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Read N and print 1 to N\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint main() { int n; cin>>n; for(int i=1;i<=n;i++) { cout << i; if(i<n) cout << endl; } return 0; }',
  },
  {
    title: 'Sum and Average',
    description: 'Given N integers, compute the sum and average (as a floating-point number).',
    concept: 'Variables',
    secondary_concepts: ['Input/Output', 'Datatypes'],
    test_cases: [
      { input: '3\n1 2 3', expected: '6 2.00000', passed: false },
      { input: '1\n10', expected: '10 10.00000', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Read N, then N integers. Print sum and average.\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\n#include <iomanip>\nusing namespace std;\nint main() { int n; cin>>n; double s=0; for(int i=0;i<n;i++){int x;cin>>x;s+=x;} cout << (int)s << " " << fixed << setprecision(5) << s/n << endl; return 0; }',
  },
  {
    title: 'Swap Two Numbers',
    description: 'Given two integers, swap them and print the smaller first.',
    concept: 'Variables',
    secondary_concepts: ['Conditionals'],
    test_cases: [
      { input: '5 3', expected: '3 5', passed: false },
      { input: '2 2', expected: '2 2', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Swap and print smaller first\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint main() { int a,b; cin>>a>>b; if(a>b) swap(a,b); cout << a << " " << b << endl; return 0; }',
  },
  {
    title: 'Print a Rectangle',
    description: 'Given H and W, print an H×W rectangle of # characters.',
    concept: 'Nested Loops',
    secondary_concepts: ['Loops'],
    required_patterns: [P_MIN_LOOPS2],
    test_cases: [
      { input: '3 4', expected: '####\n####\n####', passed: false },
      { input: '1 1', expected: '#', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Print H rows of W # characters\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint main() { int h,w; while(cin>>h>>w && (h||w)) { for(int i=0;i<h;i++) { for(int j=0;j<w;j++) cout<<"#"; cout<<endl; } cout<<endl; } return 0; }',
  },
  {
    title: 'Find Missing Number',
    description: 'Given n integers from 1 to n+1 with one missing, find the missing number.',
    concept: 'Arrays',
    secondary_concepts: ['Variables'],
    required_patterns: [P_ARRAY_USAGE],
    test_cases: [
      { input: '5\n2 5 4 1', expected: '3', passed: false },
      { input: '3\n1 2 4', expected: '3', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Find missing number in sequence\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint main() { int n; cin>>n; int s1=0,s2=0; for(int i=1;i<=n;i++){s1+=i;int x;cin>>x;s2+=x;} cout << s1+(n+1)-s2 << endl; return 0; }',
  },
  {
    title: 'Print a Frame',
    description: 'Given H and W, print a rectangular frame with # on the border and . inside.',
    concept: 'Nested Loops',
    secondary_concepts: ['Conditionals'],
    required_patterns: [P_MIN_LOOPS2],
    test_cases: [
      { input: '3 4', expected: '####\n#..#\n####', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Print frame with border and dots inside\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint main() { int h,w; while(cin>>h>>w && (h||w)) { for(int i=0;i<h;i++) { for(int j=0;j<w;j++) { if(i==0||i==h-1||j==0||j==w-1) cout<<"#"; else cout<<"."; } cout<<endl; } cout<<endl; } return 0; }',
  },
  {
    title: 'Even and Odd Numbers',
    description: 'Given N pairs of integers (a, b), for each pair print whether a*b is even or odd.',
    concept: 'Conditionals',
    secondary_concepts: ['Input/Output'],
    required_patterns: [P_CONDITIONAL],
    test_cases: [
      { input: '2\n3 4\n5 5', expected: 'even\nodd', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Determine if product is even or odd\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint main() { int n; cin>>n; for(int i=0;i<n;i++){int a,b;cin>>a>>b;cout<<(a*b%2==0?"even":"odd")<<endl;} return 0; }',
  },
  {
    title: 'Sum of N Integers',
    description: 'Read N integers on a single line and compute their sum.',
    concept: 'Variables',
    secondary_concepts: ['Loops', 'Input/Output'],
    test_cases: [
      { input: '5\n1 2 3 4 5', expected: '15', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Read N, then N integers. Print sum.\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint main() { int n; while(cin>>n && n!=0) { int s=0; for(int i=0;i<n;i++){int x;cin>>x;s+=x;} cout<<s<<endl; } return 0; }',
  },
  {
    title: 'Largest Number in a Sequence',
    description: 'Given N integers, find and print the largest value.',
    concept: 'Arrays',
    secondary_concepts: ['Conditionals'],
    required_patterns: [P_ARRAY_USAGE],
    test_cases: [
      { input: '5\n3 7 2 9 1', expected: '9', passed: false },
      { input: '1\n42', expected: '42', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Find the largest number\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint main() { int n; cin>>n; int mx=-1e9; for(int i=0;i<n;i++){int x;cin>>x;if(x>mx)mx=x;} cout<<mx<<endl; return 0; }',
  },
  {
    title: 'Multiplication Table',
    description: 'Print the 9×9 multiplication table in the standard Japanese format (N×N = result).',
    concept: 'Nested Loops',
    secondary_concepts: ['Loops', 'Input/Output'],
    required_patterns: [P_MIN_LOOPS2],
    test_cases: [
      { input: '', expected: '1x1=1\n1x2=2', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Print 9x9 multiplication table\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint main() { for(int i=1;i<=9;i++) for(int j=1;j<=9;j++) cout << i << "x" << j << "=" << i*j << endl; return 0; }',
  },
  {
    title: 'Dice Game',
    description: 'Two dice are rolled N times. Count how many times player 1 wins, player 2 wins, or it\'s a draw.',
    concept: 'Conditionals',
    secondary_concepts: ['Loops', 'Variables'],
    required_patterns: [P_CONDITIONAL],
    test_cases: [
      { input: '2\n3 5\n6 2', expected: 'p2:1\np1:1', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Count wins for dice game\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint main() { int n; cin>>n; int p1=0,p2=0,d=0; for(int i=0;i<n++){int a,b;cin>>a>>b;if(a>b)p1++;else if(b>a)p2++;else d++;} cout<<"p1:"<<p1<<endl;cout<<"p2:"<<p2<<endl;cout<<"d:"<<d<<endl; return 0; }',
  },
  {
    title: 'Fibonacci Sequence',
    description: 'Compute the nth Fibonacci number. f(0)=0, f(1)=1, f(n)=f(n-1)+f(n-2).',
    concept: 'Recursion',
    secondary_concepts: ['Functions'],
    required_patterns: [P_SELF_CALL, P_NO_LOOPS],
    test_cases: [
      { input: '0', expected: '0', passed: false },
      { input: '1', expected: '1', passed: false },
      { input: '5', expected: '5', passed: false },
      { input: '10', expected: '55', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint fibonacci(int n) {\n  // Implement fibonacci\n}\n\nint main() {\n  int n; cin >> n;\n  cout << fibonacci(n) << endl;\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint fibonacci(int n) { if(n<=1) return n; return fibonacci(n-1)+fibonacci(n-2); } int main() { int n; cin>>n; cout<<fibonacci(n)<<endl; return 0; }',
  },
  {
    title: 'Factorial Function',
    description: 'Write a function that computes n! (factorial of n).',
    concept: 'Functions',
    secondary_concepts: ['Loops'],
    required_patterns: [P_USER_FUNCTION],
    test_cases: [
      { input: '0', expected: '1', passed: false },
      { input: '5', expected: '120', passed: false },
      { input: '10', expected: '3628800', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint factorial(int n) {\n  // Compute factorial\n}\n\nint main() {\n  int n; cin >> n;\n  cout << factorial(n) << endl;\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint factorial(int n) { int r=1; for(int i=2;i<=n;i++) r*=i; return r; } int main() { int n; cin>>n; cout<<factorial(n)<<endl; return 0; }',
  },
  {
    title: 'Prime Number Check',
    description: 'Determine whether a given integer N is a prime number.',
    concept: 'Conditionals',
    secondary_concepts: ['Loops', 'Functions'],
    required_patterns: [P_CONDITIONAL],
    test_cases: [
      { input: '2', expected: 'prime', passed: false },
      { input: '4', expected: 'not prime', passed: false },
      { input: '17', expected: 'prime', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Check if N is prime\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint main() { int n; cin>>n; bool p=true; if(n<2)p=false; else for(int i=2;i*i<=n;i++) if(n%i==0){p=false;break;} cout<<(p?"prime":"not prime")<<endl; return 0; }',
  },
  {
    title: 'Grade Classification',
    description: 'Given a score (0-100), print the grade: A (>=90), B (>=80), C (>=70), D (>=60), F (<60).',
    concept: 'Switch/Case',
    secondary_concepts: ['Conditionals'],
    // Strict per-exercise structure requirement: this exercise must be solved
    // with a switch statement (ternary-only solutions fail verification).
    ast_nodes: ['switch_statement'],
    test_cases: [
      { input: '95', expected: 'A', passed: false },
      { input: '80', expected: 'B', passed: false },
      { input: '59', expected: 'F', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Classify grade\n  return 0;\n}\n',
    reference_solution: "#include <iostream>\nusing namespace std;\nint main() { int s; cin>>s; char g = s>=90?'A':s>=80?'B':s>=70?'C':s>=60?'D':'F'; cout<<g<<endl; return 0; }",
  },
  {
    title: 'Array Sorting (Bubble Sort)',
    description: 'Sort an array of N integers in ascending order using bubble sort.',
    concept: 'Arrays',
    secondary_concepts: ['Nested Loops', 'Functions'],
    required_patterns: [P_ARRAY_USAGE],
    test_cases: [
      { input: '5\n5 4 3 2 1', expected: '1 2 3 4 5', passed: false },
      { input: '3\n1 2 3', expected: '1 2 3', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nvoid bubbleSort(int arr[], int n) {\n  // Implement bubble sort\n}\n\nint main() {\n  int n; cin >> n;\n  int arr[100];\n  for(int i=0;i<n;i++) cin>>arr[i];\n  bubbleSort(arr, n);\n  for(int i=0;i<n;i++) cout << arr[i] << (i<n-1?" ":"");\n  cout << endl;\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nvoid bubbleSort(int a[],int n){for(int i=0;i<n-1;i++)for(int j=0;j<n-i-1;j++)if(a[j]>a[j+1]){int t=a[j];a[j]=a[j+1];a[j+1]=t;}} int main(){int n;cin>>n;int a[100];for(int i=0;i<n;i++)cin>>a[i];bubbleSort(a,n);for(int i=0;i<n;i++)cout<<a[i]<<(i<n-1?" ":"");cout<<endl;return 0;}',
  },
  {
    title: 'String Reversal',
    description: 'Read a string and print it reversed.',
    concept: 'Strings',
    secondary_concepts: ['Loops'],
    required_patterns: [P_STRING_TYPE],
    test_cases: [
      { input: 'hello', expected: 'olleh', passed: false },
      { input: 'a', expected: 'a', passed: false },
    ],
    starter_code: '#include <iostream>\n#include <string>\nusing namespace std;\n\nint main() {\n  // Read and reverse string\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\n#include <string>\n#include <algorithm>\nusing namespace std;\nint main() { string s; cin>>s; reverse(s.begin(),s.end()); cout<<s<<endl; return 0; }',
  },
  {
    title: 'Count Characters in a String',
    description: 'Count the number of uppercase letters, lowercase letters, and digits in a given string.',
    concept: 'Strings',
    secondary_concepts: ['Conditionals', 'Loops'],
    required_patterns: [P_STRING_TYPE],
    test_cases: [
      { input: 'Hello World 123', expected: 'Upper: 2, Lower: 8, Digit: 3', passed: false },
    ],
    starter_code: '#include <iostream>\n#include <string>\nusing namespace std;\n\nint main() {\n  // Count character types\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\n#include <string>\nusing namespace std;\nint main() { string line; getline(cin,line); int u=0,l=0,d=0; for(char c:line) { if(isupper(c))u++; else if(islower(c))l++; else if(isdigit(c))d++; } cout<<"Upper: "<<u<<", Lower: "<<l<<", Digit: "<<d<<endl; return 0; }',
  },
  {
    title: 'Compute Power',
    description: 'Write a function power(a, b) that computes a^b for non-negative integer b.',
    concept: 'Functions',
    secondary_concepts: ['Loops'],
    required_patterns: [P_USER_FUNCTION],
    test_cases: [
      { input: '2 0', expected: '1', passed: false },
      { input: '2 10', expected: '1024', passed: false },
      { input: '3 3', expected: '27', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint power(int a, int b) {\n  // Compute a^b\n}\n\nint main() {\n  int a, b; cin >> a >> b;\n  cout << power(a, b) << endl;\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint power(int a,int b){int r=1;for(int i=0;i<b;i++)r*=a;return r;} int main(){int a,b;cin>>a>>b;cout<<power(a,b)<<endl;return 0;}',
  },
  {
    title: 'Maximum and Minimum',
    description: 'Given a list of integers, find the maximum and minimum values.',
    concept: 'Arrays',
    secondary_concepts: ['Variables'],
    required_patterns: [P_ARRAY_USAGE],
    test_cases: [
      { input: '5\n3 1 4 1 5', expected: 'max 5\nmin 1', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Find max and min\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint main(){int n;cin>>n;int mn=1e9,mx=-1e9;for(int i=0;i<n++){int x;cin>>x;if(x<mn)mn=x;if(x>mx)mx=x;}cout<<"max "<<mx<<endl;cout<<"min "<<mn<<endl;return 0;}',
  },
  {
    title: 'Palindrome Check',
    description: 'Determine if a given string is a palindrome (reads the same forwards and backwards).',
    concept: 'Strings',
    secondary_concepts: ['Conditionals', 'Loops'],
    required_patterns: [P_STRING_TYPE],
    test_cases: [
      { input: 'racecar', expected: 'palindrome', passed: false },
      { input: 'hello', expected: 'not palindrome', passed: false },
    ],
    starter_code: '#include <iostream>\n#include <string>\nusing namespace std;\n\nint main() {\n  // Check palindrome\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\n#include <string>\nusing namespace std;\nint main(){string s;cin>>s;bool p=true;for(int i=0;i<s.size()/2;i++)if(s[i]!=s[s.size()-1-i])p=false;cout<<(p?"palindrome":"not palindrome")<<endl;return 0;}',
  },
  {
    title: 'GCD and LCM',
    description: 'Compute the GCD and LCM of two positive integers a and b.',
    concept: 'Functions',
    secondary_concepts: ['Variables'],
    required_patterns: [P_USER_FUNCTION],
    test_cases: [
      { input: '12 18', expected: '6 36', passed: false },
      { input: '7 13', expected: '1 91', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint gcd(int a, int b) {\n  // Compute GCD\n}\n\nint main() {\n  int a, b; cin >> a >> b;\n  int g = gcd(a, b);\n  cout << g << " " << (long long)a*b/g << endl;\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint gcd(int a,int b){while(b){int t=b;b=a%b;a=t;}return a;} int main(){int a,b;cin>>a>>b;int g=gcd(a,b);cout<<g<<" "<<(long long)a*b/g<<endl;return 0;}',
  },
  {
    title: 'Convert Base',
    description: 'Convert a decimal integer to binary representation.',
    concept: 'Loops',
    secondary_concepts: ['Datatypes'],
    required_patterns: [P_LOOP],
    test_cases: [
      { input: '10', expected: '1010', passed: false },
      { input: '0', expected: '0', passed: false },
      { input: '255', expected: '11111111', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Convert decimal to binary\n  return 0;\n}\n',
    reference_solution: `#include <iostream>\n#include <string>\n#include <algorithm>\nusing namespace std;\nint main(){int n;cin>>n;if(n==0){cout<<0<<endl;return 0;}string s;while(n>0){s+=(n%2?'1':'0');n/=2;}reverse(s.begin(),s.end());cout<<s<<endl;return 0;}`,
  },
  {
    title: 'Matrix Addition',
    description: 'Add two N×M matrices element by element.',
    concept: 'Arrays',
    secondary_concepts: ['Nested Loops'],
    required_patterns: [P_ARRAY_USAGE, P_MIN_LOOPS2],
    test_cases: [
      { input: '2 3\n1 2 3\n4 5 6\n7 8 9\n1 2 3', expected: '8 10 12\n5 7 9', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Add two matrices\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\nint main(){int n,m;cin>>n>>m;int a[10][10],b[10][10];for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>b[i][j];for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]+b[i][j];if(j<m-1)cout<<" ";}cout<<endl;}return 0;}',
  },
  {
    title: 'Count Frequency',
    description: 'Given N integers, count the frequency of each number and print sorted by value.',
    concept: 'Arrays',
    secondary_concepts: ['Conditionals'],
    required_patterns: [P_ARRAY_USAGE],
    test_cases: [
      { input: '6\n3 1 2 3 2 1', expected: '1: 2\n2: 2\n3: 2', passed: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Count frequency of each number\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\n#include <map>\nusing namespace std;\nint main(){int n;cin>>n;map<int,int>freq;for(int i=0;i<n++){int x;cin>>x;freq[x]++;}for(auto p:freq)cout<<p.first<<": "<<p.second<<endl;return 0;}',
  },
  {
    title: 'Simple Struct: Point Distance',
    description: 'Define a struct Point with x and y coordinates. Given two points, compute the Euclidean distance.',
    concept: 'Structs',
    secondary_concepts: ['Datatypes', 'Functions'],
    // Strict per-exercise structure requirement: tree-sitter-cpp parses
    // structs as struct_specifier (struct_declaration does not exist).
    ast_nodes: ['struct_specifier'],
    test_cases: [
      { input: '0 0 3 4', expected: '5.00000', passed: false },
      { input: '1 1 4 5', expected: '5.00000', passed: false },
    ],
    starter_code: '#include <iostream>\n#include <cmath>\n#include <iomanip>\nusing namespace std;\n\nstruct Point {\n  double x, y;\n};\n\ndouble distance(Point p1, Point p2) {\n  // Compute Euclidean distance\n}\n\nint main() {\n  Point p1, p2;\n  cin >> p1.x >> p1.y >> p2.x >> p2.y;\n  cout << fixed << setprecision(5) << distance(p1, p2) << endl;\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\n#include <cmath>\n#include <iomanip>\nusing namespace std;\nstruct Point{double x,y;}; double dist(Point a,Point b){return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));} int main(){Point a,b;cin>>a.x>>a.y>>b.x>>b.y;cout<<fixed<<setprecision(5)<<dist(a,b)<<endl;return 0;}',
  },
];

async function run() {
  console.log('=== Seed Master Taxonomy (Phase 2) ===\n');

  const client = await db.connect();

  try {
    await client.query('BEGIN');

    // ──────────────────────────────────────────────────────────────────────
    // Step 1: Insert new concepts (existing 7 are already populated)
    // ──────────────────────────────────────────────────────────────────────
    console.log('[Step 1] Seeding concepts...');

    const existingConcepts = await client.query(`SELECT id, name FROM concepts`);
    const existingNames = new Set(existingConcepts.rows.map(r => r.name.toLowerCase()));
    const existingMap = {};
    for (const row of existingConcepts.rows) {
      existingMap[row.name.toLowerCase()] = row.id;
    }

    let newCount = 0;
    for (const [name, ka, slug, bloom, astNodes] of NEW_CONCEPTS) {
      if (!existingNames.has(name.toLowerCase())) {
        await client.query(
          `INSERT INTO concepts (name, knowledge_area_code, slug, bloom_level, ast_nodes)
           VALUES ($1, $2, $3, $4, $5)`,
          [name, ka, slug, bloom, astNodes]
        );
        existingMap[name.toLowerCase()] = (await client.query('SELECT lastval() AS id')).rows[0].id;
        newCount++;
      }
    }
    console.log(`  ✓ Inserted ${newCount} new concepts (total: ${existingConcepts.rows.length + newCount})`);

    // Update existing concept IDs map (re-query for safety)
    const allConcepts = await client.query(`SELECT id, name FROM concepts`);
    const conceptMap = {};
    for (const row of allConcepts.rows) {
      conceptMap[row.name.toLowerCase()] = row.id;
    }

    // ──────────────────────────────────────────────────────────────────────
    // Step 2: Seed concept dependencies
    // ──────────────────────────────────────────────────────────────────────
    console.log('[Step 2] Seeding concept dependencies...');

    let depCount = 0;
    for (const [parent, child, weight] of NEW_DEPS) {
      const parentId = conceptMap[parent.toLowerCase()];
      const childId = conceptMap[child.toLowerCase()];
      if (parentId && childId) {
        await client.query(
          `INSERT INTO concept_dependencies (parent_concept_id, child_concept_id, weight)
           VALUES ($1, $2, $3) ON CONFLICT DO NOTHING`,
          [parentId, childId, weight]
        );
        depCount++;
      } else {
        console.warn(`  ⚠ Missing concept: ${parentId ? '' : parent}${childId ? '' : child}`);
      }
    }
    console.log(`  ✓ Seeded ${depCount} new dependencies`);

    // ──────────────────────────────────────────────────────────────────────
    // Step 3: Seed AIZU ITP1 exercises
    // ──────────────────────────────────────────────────────────────────────
    console.log('[Step 3] Seeding CodeNet/AIZU exercises...');

    // Get or create the instructor user
    const instructor = await client.query(`SELECT id FROM users WHERE role = 'instructor' LIMIT 1`);
    const instructorId = instructor.rows.length > 0 ? instructor.rows[0].id : 1;

    // Create a demo section for these exercises if none exists
    let section = await client.query(`SELECT id FROM sections WHERE course_code = 'ITP1' LIMIT 1`);
    let sectionId;

    if (section.rows.length === 0) {
      const secResult = await client.query(
        `INSERT INTO sections (name, course_code, school_year, instructor_id, code, join_policy, max_size)
         VALUES ('Introduction to Programming I', 'ITP1', '2025-2026', $1, $2, 'code', 50)
         RETURNING id`,
        [instructorId, generateCode()]
      );
      sectionId = secResult.rows[0].id;
      console.log(`  ✓ Created ITP1 section (id: ${sectionId})`);
    } else {
      sectionId = section.rows[0].id;
      // Ensure the section has a join code
      const existingCode = await client.query(`SELECT code FROM sections WHERE id = $1`, [sectionId]);
      if (!existingCode.rows[0]?.code) {
        const newCode = generateCode();
        await client.query(`UPDATE sections SET code = $1 WHERE id = $2`, [newCode, sectionId]);
        console.log(`  ✓ Generated join code for existing ITP1 section: ${newCode}`);
      }
      console.log(`  ✓ Using existing ITP1 section (id: ${sectionId})`);
    }

    let exerciseCount = 0;
    for (const ex of CODENET_EXERCISES) {
      // Check if exercise already exists by title
      const existing = await client.query(
        `SELECT id FROM exercises WHERE title = $1`,
        [ex.title]
      );

      let exerciseId;
      const primaryConceptId = conceptMap[ex.concept.toLowerCase()];

      if (existing.rows.length === 0) {
        const result = await client.query(
          `INSERT INTO exercises (title, description, concept_id, section_id, created_by,
            test_cases, starter_code, reference_solution, ast_nodes, required_patterns)
           VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10::jsonb)
           RETURNING id`,
          [ex.title, ex.description, primaryConceptId, sectionId, instructorId,
           JSON.stringify(ex.test_cases), ex.starter_code, ex.reference_solution,
           ex.ast_nodes || null, JSON.stringify(ex.required_patterns || [])]
        );
        exerciseId = result.rows[0].id;
      } else {
        // Update existing exercise with reference_solution if missing
        exerciseId = existing.rows[0].id;
        await client.query(
          `UPDATE exercises SET reference_solution = $1 WHERE id = $2 AND reference_solution IS NULL`,
          [ex.reference_solution, exerciseId]
        );
        // Backfill ast_nodes idempotently — COALESCE preserves any explicit
        // value already set on the exercise (e.g. manual instructor edits).
        await client.query(
          `UPDATE exercises SET ast_nodes = COALESCE($2, ast_nodes) WHERE id = $1`,
          [exerciseId, ex.ast_nodes || null]
        );
        // Backfill required_patterns idempotently — COALESCE preserves any
        // explicit value already set on the exercise.
        await client.query(
          `UPDATE exercises SET required_patterns = COALESCE($2::jsonb, required_patterns) WHERE id = $1`,
          [exerciseId, ex.required_patterns ? JSON.stringify(ex.required_patterns) : null]
        );
      }

      // Tag in exercise_concept_tags
      if (primaryConceptId) {
        await client.query(
          `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary)
           VALUES ($1, $2, 1.0, true)
           ON CONFLICT (exercise_id, concept_id) DO UPDATE SET is_primary = true`,
          [exerciseId, primaryConceptId]
        );
      }

      for (const secConcept of ex.secondary_concepts) {
        const secId = conceptMap[secConcept.toLowerCase()];
        if (secId && secId !== primaryConceptId) {
          await client.query(
            `INSERT INTO exercise_concept_tags (exercise_id, concept_id, weight, is_primary)
             VALUES ($1, $2, 0.5, false)
             ON CONFLICT (exercise_id, concept_id) DO UPDATE SET weight = EXCLUDED.weight`,
            [exerciseId, secId]
          );
        }
      }

      exerciseCount++;
    }
    console.log(`  ✓ Seeded/updated ${exerciseCount} exercises`);

    // Note: exercise_bank uses UUID IDs (templates), not INT (exercises).
    // exercise_concept_tags only references exercises.id (INT), so bank items
    // are not tagged here. When bank items are promoted to exercises, they
    // inherit concept tags from their concept_name field.

    await client.query('COMMIT');

    // ──────────────────────────────────────────────────────────────────────
    // Summary
    // ──────────────────────────────────────────────────────────────────────
    const totalConcepts = await client.query(`SELECT COUNT(*) FROM concepts`);
    const totalDeps = await client.query(`SELECT COUNT(*) FROM concept_dependencies`);
    const totalTags = await client.query(`SELECT COUNT(*) FROM exercise_concept_tags`);
    const totalExercises = await client.query(`SELECT COUNT(*) FROM exercises`);

    console.log('\n=== Seed Complete ===');
    console.log(`  Concepts: ${totalConcepts.rows[0].count} total`);
    console.log(`  Dependencies: ${totalDeps.rows[0].count} total`);
    console.log(`  Exercise-Concept Tags: ${totalTags.rows[0].count} total`);
    console.log(`  Exercises: ${totalExercises.rows[0].count} total`);

  } catch (err) {
    await client.query('ROLLBACK');
    console.error('\n✗ Seed failed (rolled back):', err.message);
    console.error(err.stack);
    process.exitCode = 1;
  } finally {
    client.release();
    await db.end();
  }
}

run();
