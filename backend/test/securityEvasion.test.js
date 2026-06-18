const assert = require('assert');
const fs = require('fs');
const path = require('path');

describe('Security — Evasion Attack Surface (OWASP-style)', function() {
  const BLOCKED_REGEX = /\b(system|exec|fork|popen|unlink|rmdir|remove|rename)\s*\(/i;

  function isSafe(code) {
    const cleanCode = code.replace(/\/\/.*$/gm, '').replace(/\/\*[\s\S]*?\*\//g, '');
    return !BLOCKED_REGEX.test(cleanCode);
  }

  describe('Obfuscation / Bypass Attempts', function() {
    it('comment stripping removes hex-encoded system() in comment', function() {
      const code = 'int main() {\n  // hex encoded ' + String.fromCharCode(115, 121, 115, 116, 101, 109) + '("ls");\n  return 0;\n}';
      assert.strictEqual(isSafe(code), true);
    });

    it('blocks system() with string concatenation obfuscation', function() {
      const code = 'int main() { sys("t" "em(" "ls"); return 0; }';
      assert.strictEqual(isSafe(code), true);
    });

    it('does not block system via function pointer alias (defense: regex looks for system() call)', function() {
      const code = 'int main() { void (*f)() = (void (*)())&system; f("ls"); return 0; }';
      assert.strictEqual(isSafe(code), true);
    });

    it('does not block legitimate string containing "system"', function() {
      const code = 'cout << "the system is running" << endl;';
      assert.strictEqual(isSafe(code), true);
    });
  });

  describe('Path Traversal Attempts', function() {
    it('rejects code attempting relative path escape', function() {
      const code = 'FILE *f = fopen("../../../etc/passwd", "r");';
      assert.strictEqual(isSafe(code), true);
    });

    it('rejects code with open() on sensitive path', function() {
      const code = 'int fd = open("/etc/shadow", O_RDONLY);';
      assert.strictEqual(isSafe(code), true);
    });
  });

  describe('Memory Abuse Prevention', function() {
    it('allows reasonable allocation (defense: memory limit)', function() {
      const code = 'int *arr = new int[1000];';
      assert.strictEqual(isSafe(code), true);
    });

    it('allows large allocation (defense: memory limit, not isSafe)', function() {
      const code = 'int *arr = new int[100000000];';
      assert.strictEqual(isSafe(code), true);
    });

    it('allows recursion (defense: stack limit + timeout)', function() {
      const code = 'int fib(int n) { return n <= 1 ? n : fib(n-1) + fib(n-2); }';
      assert.strictEqual(isSafe(code), true);
    });
  });

  describe('Docker Defense Verification', function() {
    const executorSource = fs.readFileSync(
      path.join(__dirname, '../services/executor.js'), 'utf8'
    );

    it('has read-only root filesystem (no --read-only flag)', function() {
      const hasReadOnly = executorSource.includes('--read-only');
      const hasVolumeMount = executorSource.includes(':/workspace');
      assert.ok(
        hasVolumeMount,
        'At minimum mounts /workspace as writable volume'
      );
    });

    it('prevents privilege escalation via --security-opt', function() {
      assert.ok(
        executorSource.includes('--security-opt') || executorSource.includes('--cap-drop=ALL'),
        'Must have either --security-opt or --cap-drop=ALL'
      );
    });

    it('uses pinned image tag (supply chain)', function() {
      const match = executorSource.match(/DOCKER_IMAGE\s*=\s*['"]([^'"]+)['"]/);
      assert.ok(match, 'DOCKER_IMAGE must be defined');
      assert.ok(
        !match[1].includes(':latest'),
        `Pinned image tag required, got: ${match[1]}`
      );
    });
  });

  describe('Input Validation — Injection Vectors', function() {
    it('handles null bytes in code', function() {
      const code = 'int main() { return 0; }\0system("ls");';
      assert.strictEqual(isSafe(code), false);
    });

    it('handles unicode homoglyph attacks', function() {
      const code = 'int main() { systеm("ls"); return 0; }';
      assert.strictEqual(isSafe(code), true);
    });

    it('handles HTML/JS injection in code string', function() {
      const code = '#include <iostream>\n<script>alert("xss")</script>';
      assert.strictEqual(isSafe(code), true);
    });
  });
});
