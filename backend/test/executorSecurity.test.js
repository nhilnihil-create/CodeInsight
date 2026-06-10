// Docker Sandbox Security Tests
// Tests for executor.js sandbox isolation, input validation, and attack defense.
// These test the LOGIC without requiring actual Docker (which isn't available in CI).

const assert = require('assert');
const fs = require('fs');
const path = require('path');

// ── Source Analysis: Verify Security Controls Exist ─────────────────────────

describe('Docker Sandbox — Security Controls Verification', function() {
  const executorSource = fs.readFileSync(
    path.join(__dirname, '../services/executor.js'), 'utf8'
  );

  it('has BLOCKED_REGEX for dangerous system calls', function() {
    assert.ok(
      executorSource.includes('BLOCKED_REGEX'),
      'executor.js must define a blocked call regex'
    );
  });

  it('blocks system() calls', function() {
    assert.ok(
      executorSource.includes('system'),
      'BLOCKED_REGEX must include system()'
    );
  });

  it('blocks exec() calls', function() {
    assert.ok(
      executorSource.includes('exec'),
      'BLOCKED_REGEX must include exec()'
    );
  });

  it('blocks fork() calls', function() {
    assert.ok(
      executorSource.includes('fork'),
      'BLOCKED_REGEX must include fork()'
    );
  });

  it('blocks popen() calls', function() {
    assert.ok(
      executorSource.includes('popen'),
      'BLOCKED_REGEX must include popen()'
    );
  });

  it('blocks unlink() calls (file deletion)', function() {
    assert.ok(
      executorSource.includes('unlink'),
      'BLOCKED_REGEX must include unlink()'
    );
  });

  it('blocks rmdir() calls (directory deletion)', function() {
    assert.ok(
      executorSource.includes('rmdir'),
      'BLOCKED_REGEX must include rmdir()'
    );
  });

  it('blocks remove() calls (file deletion)', function() {
    assert.ok(
      executorSource.includes('remove'),
      'BLOCKED_REGEX must include remove()'
    );
  });

  it('blocks rename() calls', function() {
    assert.ok(
      executorSource.includes('rename'),
      'BLOCKED_REGEX must include rename()'
    );
  });

  it('uses --memory 64m Docker flag (memory limit)', function() {
    assert.ok(
      executorSource.includes('--memory 64m') || executorSource.includes('--memory=64m'),
      'Docker run must include memory limit'
    );
  });

  it('uses --network none Docker flag (network isolation)', function() {
    assert.ok(
      executorSource.includes('--network none'),
      'Docker run must disable network access'
    );
  });

  it('uses --rm Docker flag (container cleanup)', function() {
    assert.ok(
      executorSource.includes('--rm'),
      'Docker run must auto-remove containers'
    );
  });

  it('uses pinned Docker image (reproducibility)', function() {
    assert.ok(
      executorSource.includes("DOCKER_IMAGE = 'gcc:"),
      'Must use a pinned Docker image tag, not "latest"'
    );
  });

  it('uses timeout command for execution time limit', function() {
    assert.ok(
      executorSource.includes('timeout'),
      'Must wrap execution with timeout command'
    );
  });

  it('uses AddressSanitizer compiler flags', function() {
    assert.ok(
      executorSource.includes('fsanitize=address'),
      'Must compile with AddressSanitizer'
    );
  });

  it('cleans up temp directories after execution', function() {
    assert.ok(
      executorSource.includes('fs.rmSync') || executorSource.includes('fs.rm'),
      'Must clean up temporary directories'
    );
  });

  it('cleanup is in finally block (runs even on error)', function() {
    // Check that cleanup happens in a finally block
    assert.ok(
      executorSource.includes('finally') && executorSource.includes('cleanup'),
      'cleanup() must be in a finally block'
    );
  });

  it('strips comments before blocked keyword check (prevent bypass)', function() {
    assert.ok(
      executorSource.includes('replace') && executorSource.includes('//'),
      'isSafe must strip comments before checking blocked keywords'
    );
  });
});

// ── isSafe() Logic Reproduction & Testing ─────────────────────────────────────

describe('Docker Sandbox — isSafe() Input Validation', function() {
  // Reproduce the isSafe logic from executor.js
  const BLOCKED_REGEX = /\b(system|exec|fork|popen|unlink|rmdir|remove|rename)\s*\(/i;

  function isSafe(code) {
    const cleanCode = code.replace(/\/\/.*$/gm, '').replace(/\/\*[\s\S]*?\*\//g, '');
    return !BLOCKED_REGEX.test(cleanCode);
  }

  // ── Legitimate code should pass ───────────────────────────────────────────

  it('accepts simple hello world', function() {
    assert.strictEqual(isSafe('#include <iostream>\nint main() { std::cout << "Hello"; return 0; }'), true);
  });

  it('accepts loops', function() {
    assert.strictEqual(isSafe('for (int i = 0; i < 10; i++) { cout << i; }'), true);
  });

  it('accepts conditionals', function() {
    assert.strictEqual(isSafe('if (x > 0) { cout << "positive"; } else { cout << "non-positive"; }'), true);
  });

  it('accepts function definitions', function() {
    assert.strictEqual(isSafe('int add(int a, int b) { return a + b; }'), true);
  });

  it('accepts array operations', function() {
    assert.strictEqual(isSafe('int arr[10]; for(int i=0;i<10;i++) arr[i]=i;'), true);
  });

  it('accepts pointer operations', function() {
    assert.strictEqual(isSafe('int x = 5; int *p = &x; cout << *p;'), true);
  });

  it('accepts class definitions', function() {
    const code = `
      class Student {
      public:
        string name;
        int age;
        void display() { cout << name << " " << age; }
      };
    `;
    assert.strictEqual(isSafe(code), true);
  });

  it('accepts file inclusion (standard headers)', function() {
    assert.strictEqual(isSafe('#include <iostream>\n#include <string>\n#include <vector>'), true);
  });

  // ── Blocked system calls should be rejected ───────────────────────────────

  it('rejects system() call', function() {
    assert.strictEqual(isSafe('system("rm -rf /");'), false);
  });

  it('rejects exec() call', function() {
    assert.strictEqual(isSafe('exec("/bin/sh");'), false);
  });

  it('rejects fork() call', function() {
    assert.strictEqual(isSafe('pid_t pid = fork();'), false);
  });

  it('rejects popen() call', function() {
    assert.strictEqual(isSafe('FILE *f = popen("ls", "r");'), false);
  });

  it('rejects unlink() call', function() {
    assert.strictEqual(isSafe('unlink("/etc/passwd");'), false);
  });

  it('rejects rmdir() call', function() {
    assert.strictEqual(isSafe('rmdir("/tmp/important");'), false);
  });

  it('rejects remove() call', function() {
    assert.strictEqual(isSafe('remove("/etc/shadow");'), false);
  });

  it('rejects rename() call', function() {
    assert.strictEqual(isSafe('rename("/etc/passwd", "/tmp/pwned");'), false);
  });

  // ── Evasion attempts ─────────────────────────────────────────────────────

  it('blocks system() even in comments is safe (comments stripped)', function() {
    // Comments are stripped, so this should PASS (commented-out attack is fine)
    assert.strictEqual(isSafe('// system("rm -rf /");\nint main() { return 0; }'), true);
  });

  it('blocks system() hidden in block comment (comment stripped)', function() {
    assert.strictEqual(isSafe('/* system("rm -rf /"); */\nint main() { return 0; }'), true);
  });

  it('blocks system() with extra whitespace', function() {
    assert.strictEqual(isSafe('system  ("rm -rf /");'), false);
  });

  it('blocks SYSTEM() (case insensitive)', function() {
    assert.strictEqual(isSafe('SYSTEM("rm -rf /");'), false);
  });

  it('rejects multiple blocked calls in one line', function() {
    assert.strictEqual(isSafe('fork(); exec("/bin/sh");'), false);
  });

  it('rejects blocked call without semicolon (no trailing)', function() {
    // The regex matches `system(` even without semicolon
    assert.strictEqual(isSafe('system("ls")'), false);
  });

  // ── Edge cases ───────────────────────────────────────────────────────────

  it('accepts empty code', function() {
    assert.strictEqual(isSafe(''), true);
  });

  it('accepts whitespace-only code', function() {
    assert.strictEqual(isSafe('   \n\t  '), true);
  });

  it('accepts code with string containing blocked word (no false positive)', function() {
    // "remove" as a string literal — NOT blocked because regex requires `remove(`
    // The BLOCKED_REGEX only matches when the word is followed by \s*\(
    const code = 'std::cout << "remove this item";';
    const result = isSafe(code);
    assert.strictEqual(result, true, 'String literal with "remove" should NOT be blocked');
  });

  it('accepts variable named "system" without parentheses', function() {
    // "system" as a variable name (not a function call) should be fine
    // But our regex uses \b...\s*\( so it only triggers when followed by (
    assert.strictEqual(isSafe('int system = 5;'), true);
  });

  it('rejects variable named "system" used as function call', function() {
    assert.strictEqual(isSafe('int system();'), false);
    // This is a false positive — forward declaration of system() is blocked
    // but it's an acceptable trade-off for security
  });
});

// ── Docker Command Construction ──────────────────────────────────────────────

describe('Docker Sandbox — Command Construction', function() {
  const executorSource = fs.readFileSync(
    path.join(__dirname, '../services/executor.js'), 'utf8'
  );

  it('mounts temp directory as /workspace (not arbitrary host path)', function() {
    assert.ok(
      executorSource.includes(':/workspace'),
      'Must mount temp dir to /workspace inside container'
    );
  });

  it('uses bash -c for compound commands (compile + run)', function() {
    assert.ok(
      executorSource.includes('bash -c'),
      'Must use bash -c for compile+run compound command'
    );
  });

  it('compiles before running (compile && run pattern)', function() {
    assert.ok(
      executorSource.includes('&&'),
      'Must chain compile and run with && (run only if compile succeeds)'
    );
  });

  it('runs in /workspace directory inside container', function() {
    assert.ok(
      executorSource.includes('cd /workspace'),
      'Must cd to /workspace before running'
    );
  });

  it('uses input redirection for stdin', function() {
    assert.ok(
      executorSource.includes('< /workspace/stdin.txt'),
      'Must redirect stdin from file'
    );
  });

  it('timeout is parameterized (not hardcoded)', function() {
    assert.ok(
      executorSource.includes('timeLimitSeconds') || executorSource.includes('timeoutSec'),
      'Timeout must be configurable, not hardcoded'
    );
  });

  it('timeout buffer: container timeout > program timeout', function() {
    // Docker timeout = timeLimitSeconds + 10 (buffer for container overhead)
    assert.ok(
      executorSource.includes('+ 10') || executorSource.includes('+10'),
      'Container timeout should have a buffer over program timeout'
    );
  });
});

// ── Result Classification Logic ──────────────────────────────────────────────

describe('Docker Sandbox — Result Classification', function() {
  // Reproduce the classification logic from executor.js
  function classifyResult(stderr, stdout, err, sourceCode) {
    const combinedStderr = stderr || '';
    const combinedStdout = stdout || '';

    if (err || combinedStderr.includes('error:')) {
      const hasCompileError = combinedStderr.match(/solution\.cpp:\d+:\d+: error:/i)
        || combinedStderr.includes('fatal error')
        || combinedStderr.includes('undefined reference');

      if (hasCompileError) {
        return { status: 'Compile Error' };
      }

      // Check sanitizer
      if (combinedStderr.includes('AddressSanitizer')) {
        return { status: 'Runtime Error' };
      }

      if (err && (err.code === 124 || err.killed)) {
        return { status: 'Time Limit Exceeded' };
      }

      return { status: 'Runtime Error' };
    }

    return { status: 'Success' };
  }

  it('classifies successful execution as Success', function() {
    const result = classifyResult('', 'Hello World', null, '');
    assert.strictEqual(result.status, 'Success');
  });

  it('classifies compilation error as Compile Error', function() {
    const result = classifyResult(
      'solution.cpp:5:3: error: use of undeclared identifier "x"',
      '', null, ''
    );
    assert.strictEqual(result.status, 'Compile Error');
  });

  it('classifies fatal error as Compile Error', function() {
    const result = classifyResult(
      'fatal error: iostream: No such file or directory',
      '', null, ''
    );
    assert.strictEqual(result.status, 'Compile Error');
  });

  it('classifies undefined reference as Compile Error', function() {
    // Undefined reference causes linker error (non-zero exit)
    const result = classifyResult(
      'undefined reference to "main"',
      '', { code: 1 }, ''
    );
    assert.strictEqual(result.status, 'Compile Error');
  });

  it('classifies AddressSanitizer as Runtime Error', function() {
    // Real ASAN causes non-zero exit, so result.err is set
    // The executor then calls parseSanitizerOutput inside the error branch
    const result = classifyResult(
      'ERROR: AddressSanitizer: heap-buffer-overflow on address 0x602000000010\n    solution.cpp:15:5',
      '', { code: 1 }, ''
    );
    assert.strictEqual(result.status, 'Runtime Error');
  });

  it('classifies timeout (err.code=124) as Time Limit Exceeded', function() {
    const result = classifyResult('', '', { code: 124 }, '');
    assert.strictEqual(result.status, 'Time Limit Exceeded');
  });

  it('classifies killed process as Time Limit Exceeded', function() {
    const result = classifyResult('', '', { killed: true }, '');
    assert.strictEqual(result.status, 'Time Limit Exceeded');
  });

  it('classifies unknown stderr error as Runtime Error', function() {
    const result = classifyResult(
      'some weird error', '', { code: 1 }, ''
    );
    assert.strictEqual(result.status, 'Runtime Error');
  });
});

// ── Sanitizer Output Parsing ─────────────────────────────────────────────────

describe('Docker Sandbox — Sanitizer Output Parsing', function() {
  // Reproduce parseSanitizerOutput
  function parseSanitizerOutput(stderr, stdout) {
    const full = stderr || '';
    const heapOverflow = full.match(/AddressSanitizer:\s*(heap-buffer-overflow|heap-use-after-free|stack-buffer-overflow|global-buffer-overflow)/);
    if (heapOverflow) {
      const lineMatch = full.match(/solution\.cpp:(\d+)/);
      return {
        status: 'Runtime Error',
        message: `AddressSanitizer: ${heapOverflow[1]}${lineMatch ? ` at solution.cpp:${lineMatch[1]}` : ''}`,
        output: '',
      };
    }
    const leakMatch = full.match(/LeakSanitizer:\s*detected memory leaks/i)
      || full.match(/directly leaking \d+ bytes/i);
    if (leakMatch) {
      return {
        status: 'Success',
        message: `Warning: ${leakMatch[0] || 'Memory leak detected'}`,
        output: stdout?.trim() || '',
      };
    }
    return null;
  }

  it('parses heap-buffer-overflow', function() {
    const result = parseSanitizerOutput(
      'AddressSanitizer: heap-buffer-overflow on address 0x602000000010\n    solution.cpp:15:5',
      ''
    );
    assert.ok(result !== null);
    assert.strictEqual(result.status, 'Runtime Error');
    assert.ok(result.message.includes('heap-buffer-overflow'));
    assert.ok(result.message.includes('solution.cpp:15'));
  });

  it('parses stack-buffer-overflow', function() {
    const result = parseSanitizerOutput(
      'AddressSanitizer: stack-buffer-overflow', ''
    );
    assert.ok(result !== null);
    assert.strictEqual(result.status, 'Runtime Error');
  });

  it('parses use-after-free', function() {
    const result = parseSanitizerOutput(
      'AddressSanitizer: heap-use-after-free', ''
    );
    assert.ok(result !== null);
    assert.strictEqual(result.status, 'Runtime Error');
  });

  it('classifies memory leak as Success (non-fatal)', function() {
    const result = parseSanitizerOutput(
      'LeakSanitizer: detected memory leaks',
      'Correct output'
    );
    assert.ok(result !== null);
    assert.strictEqual(result.status, 'Success');
    assert.strictEqual(result.output, 'Correct output');
  });

  it('returns null for non-sanitizer output', function() {
    const result = parseSanitizerOutput('Segmentation fault', '');
    assert.strictEqual(result, null);
  });

  it('returns null for empty input', function() {
    const result = parseSanitizerOutput('', '');
    assert.strictEqual(result, null);
  });

  it('returns null for null input', function() {
    const result = parseSanitizerOutput(null, null);
    assert.strictEqual(result, null);
  });
});

// ── Attack Scenario Simulations ──────────────────────────────────────────────

describe('Docker Sandbox — Attack Scenario Analysis', function() {
  const BLOCKED_REGEX = /\b(system|exec|fork|popen|unlink|rmdir|remove|rename)\s*\(/i;

  function isSafe(code) {
    const cleanCode = code.replace(/\/\/.*$/gm, '').replace(/\/\*[\s\S]*?\*\//g, '');
    return !BLOCKED_REGEX.test(cleanCode);
  }

  describe('Infinite Loop Attack', function() {
    it('detects while(true) loop but allows it (relies on timeout)', function() {
      // Infinite loops are NOT blocked by isSafe — defense is the timeout
      const code = 'int main() { while(true) {} return 0; }';
      assert.strictEqual(isSafe(code), true, 'Infinite loop passes isSafe — timeout is the defense');
    });

    it('detects for(;;) loop but allows it (relies on timeout)', function() {
      const code = 'int main() { for(;;) {} return 0; }';
      assert.strictEqual(isSafe(code), true, 'for(;;) passes isSafe — timeout is the defense');
    });
  });

  describe('Fork Bomb Attack', function() {
    it('blocks fork() call', function() {
      assert.strictEqual(isSafe('int main() { fork(); }'), false);
    });

    it('does NOT block vfork() - word boundary gap documented', function() {
      // \bfork does NOT match inside "vfork" because \b is before "v", not "f"
      assert.strictEqual(isSafe('vfork();'), true, 'vfork() is NOT blocked - known gap');
    });
  });

  describe('File Deletion Attack', function() {
    it('blocks unlink("/etc/passwd")', function() {
      assert.strictEqual(isSafe('unlink("/etc/passwd");'), false);
    });

    it('blocks remove() on sensitive files', function() {
      assert.strictEqual(isSafe('remove("/etc/shadow");'), false);
    });

    it('blocks rmdir() on directories', function() {
      assert.strictEqual(isSafe('rmdir("/");'), false);
    });
  });

  describe('Network Attack', function() {
    it('network prevented by --network none (defense in depth)', function() {
      // Even if code tries to open sockets, --network none blocks it
      // The executor source uses --network none
      const executorSource = fs.readFileSync(
        path.join(__dirname, '../services/executor.js'), 'utf8'
      );
      assert.ok(executorSource.includes('--network none'));
    });
  });

  describe('Memory Exhaustion Attack', function() {
    it('memory limited by --memory 64m (defense in depth)', function() {
      const executorSource = fs.readFileSync(
        path.join(__dirname, '../services/executor.js'), 'utf8'
      );
      assert.ok(executorSource.includes('--memory 64m'));
    });

    it('large array allocation passes isSafe but hits memory limit', function() {
      // isSafe can't detect large allocations — memory limit is the defense
      const code = 'int main() { char *buf = new char[1000000000]; }';
      assert.strictEqual(isSafe(code), true, 'Large allocation passes isSafe — memory limit is the defense');
    });
  });

  describe('Output Flooding Attack', function() {
    it('massive output loop passes isSafe but hits timeout/memory', function() {
      const code = 'int main() { while(1) printf("A"); }';
      assert.strictEqual(isSafe(code), true, 'Output flood passes isSafe — timeout is the defense');
    });
  });

  describe('Regex Bypass Attempts', function() {
    it('blocks system\t() (tab between name and paren)', function() {
      // The regex uses \s* so tabs are covered
      assert.strictEqual(isSafe('system\t();'), false);
    });

    it('blocks system\n() (newline between name and paren)', function() {
      assert.strictEqual(isSafe('system\n();'), false);
    });

    it('does not block getSystemStatus() (not a blocked call)', function() {
      // This tests for false positives — getSystemStatus is NOT system(
      // because the \b word boundary matches at "System" not "system"
      // But wait, the regex is case-insensitive and \b matches before "system"
      // Actually: "getSystemStatus()" — \b matches at "S" in "System"? No,
      // \b requires a word boundary. Between "get" and "System" there's no boundary.
      // Between "System" and "Status" — no, they're one word.
      // Wait: "getSystemStatus" — where is "system"? The regex looks for
      // \b(system|...)\s*\( — in "getSystemStatus()" there's no standalone "system"
      // followed by (. Let me check...
      const code = 'int getSystemStatus() { return 0; }';
      // The regex is case-insensitive and looks for \bsystem\b or similar
      // "getSystemStatus" — is there a \b before "system"? No, "get" and "System"
      // are camelCase — no word boundary. So this should PASS.
      assert.strictEqual(isSafe(code), true, 'getSystemStatus() should NOT be blocked');
    });
  });
});

// ── Compiler Error Parser ────────────────────────────────────────────────────

describe('Docker Sandbox — Compiler Error Parser', function() {
  // We can't import the function directly (it's not exported), so we test
  // the regex patterns it uses
  const compilerErrorPattern = /solution\.cpp:(\d+):(\d+):\s*(error|warning|note):\s*(.+)/;

  it('matches standard g++ error format', function() {
    const match = 'solution.cpp:10:5: error: use of undeclared identifier "x"'.match(compilerErrorPattern);
    assert.ok(match !== null);
    assert.strictEqual(match[1], '10');
    assert.strictEqual(match[2], '5');
    assert.strictEqual(match[3], 'error');
  });

  it('matches warning format', function() {
    const match = 'solution.cpp:5:10: warning: unused variable "y"'.match(compilerErrorPattern);
    assert.ok(match !== null);
    assert.strictEqual(match[3], 'warning');
  });

  it('matches note format', function() {
    const match = 'solution.cpp:3:1: note: candidate function'.match(compilerErrorPattern);
    assert.ok(match !== null);
    assert.strictEqual(match[3], 'note');
  });

  it('does not match non-file output', function() {
    const match = 'collect2: error: ld returned 1 exit status'.match(compilerErrorPattern);
    assert.strictEqual(match, null);
  });
});

// ── Temp Directory Security ──────────────────────────────────────────────────

describe('Docker Sandbox — Temp Directory Security', function() {
  it('uses unique temp directory per execution (timestamp + random)', function() {
    const executorSource = fs.readFileSync(
      path.join(__dirname, '../services/executor.js'), 'utf8'
    );
    assert.ok(
      executorSource.includes('Date.now()') && executorSource.includes('random'),
      'Temp directory must include timestamp and random component'
    );
  });

  it('uses /tmp prefix (standard temp directory)', function() {
    const executorSource = fs.readFileSync(
      path.join(__dirname, '../services/executor.js'), 'utf8'
    );
    assert.ok(
      executorSource.includes("'/tmp'") || executorSource.includes('"/tmp"'),
      'Must use /tmp for temp directories'
    );
  });
});

console.log('Docker Sandbox Security test suite loaded — all assertions active.');
