const { exec } = require('child_process');
const fs     = require('fs');
const path   = require('path');
const { gradeSubmission, validateOutput } = require('./streamMatcher');

const BLOCKED_REGEX = /\b(system|exec|fork|popen|unlink|rmdir|remove|rename)\s*\(/i;

// Pinned Docker image for reproducibility (defense: "Can the experiment be reproduced next year?")
const DOCKER_IMAGE = 'gcc:14-bookworm';

// Compiler flags: -O1 for reasonable speed, sanitizer for memory/UB detection
// Note: ASAN works best at -O0/-Og for detecting heap overflows; -O1 may
// optimize away some bounds checks. We use -O1 as required by spec; ASAN
// still catches stack-buffer-overflow, use-after-free, and null-deref issues.
const COMPILE_FLAGS = '-O1 -fno-omit-frame-pointer -fsanitize=address -std=c++17';

function isSafe(code) {
  // Remove comments before checking for blocked keywords to avoid false positives
  const cleanCode = code.replace(/\/\/.*$/gm, '').replace(/\/\*[\s\S]*?\*\//g, '');
  return !BLOCKED_REGEX.test(cleanCode);
}

// ── Docker helpers ─────────────────────────────────────────────────────────

// Simulation/test mode: cap sandbox timeout to prevent infinite loops from
// consuming CPU/RAM. In production, infinite loops get the full timeout;
// in simulation, 1.5s is enough to detect the loop.
const SANDBOX_TIMEOUT_OVERRIDE_MS = process.env.SANDBOX_TIMEOUT_MS
  ? parseInt(process.env.SANDBOX_TIMEOUT_MS)
  : null; // null = no override

function getEffectiveTimeoutSec(defaultSec = 30) {
  if (SANDBOX_TIMEOUT_OVERRIDE_MS !== null) {
    return Math.max(SANDBOX_TIMEOUT_OVERRIDE_MS / 1000, 1); // min 1s
  }
  return defaultSec;
}

function dockerAvailable() {
  return new Promise((resolve) => {
    exec('docker info --format "{{.ServerVersion}}"', { timeout: 5000 }, (err) => {
      resolve(!err);
    });
  });
}

function runInDocker(command, timeoutSec = 30) {
  return new Promise((resolve) => {
    exec(command, { timeout: timeoutSec * 1000 }, (err, stdout, stderr) => {
      resolve({ err, stdout: stdout || '', stderr: stderr || '' });
    });
  });
}

// ── Cppcheck ────────────────────────────────────────────────────────────────

/**
 * Run cppcheck on source code (static analysis — no execution, runs natively).
 * Returns structured warnings array.
 */
async function runCppcheck(sourceCode) {
  const tmpDir = path.join('/tmp', `ci_cppcheck_${Date.now()}_${Math.random().toString(36).slice(2)}`);
  fs.mkdirSync(tmpDir, { recursive: true });
  const srcFile = path.join(tmpDir, 'solution.cpp');
  fs.writeFileSync(srcFile, sourceCode);

  return new Promise((resolve) => {
    exec(
      `cppcheck --enable=warning,style,performance,portability ` +
      `--template='{file}:{line}:{severity}:{message}:{id}' --quiet ${srcFile} 2>&1`,
      { timeout: 10000 },
      (err, stdout, stderr) => {
        try { fs.rmSync(tmpDir, { recursive: true, force: true }); } catch (_) {}
        const output = (stdout + stderr).trim();
        if (!output) return resolve([]);
        resolve(parseCppcheckOutput(output));
      }
    );
  });
}

/**
 * Parse cppcheck output into structured warnings.
 * Format: {file}:{line}:{severity}:{message}:{id}
 */
function parseCppcheckOutput(output) {
  const warnings = [];
  const lines = output.split('\n');

  for (const line of lines) {
    // Match: /tmp/.../solution.cpp:1:error:Uninitialized variable: x:uninitvar
    // or: /workspace/solution.cpp:10:warning:Variable 'x' is not assigned a value:unassignedVariable
    const match = line.match(/solution\.cpp:(\d+):(\w+):(.+?):(\w+)$/);
    if (match) {
      warnings.push({
        file: 'solution.cpp',
        line: parseInt(match[1]),
        severity: match[2],
        message: match[3],
        id: match[4],
      });
    } else if (line.trim() && !line.includes('Checking') && !line.includes('information')) {
      warnings.push({ severity: 'info', message: line.trim(), id: 'unknown' });
    }
  }

  return warnings;
}

// ── Execute code in Docker sandbox ─────────────────────────────────────────

/**
 * Compile and execute C++ code inside a Docker container with AddressSanitizer.
 */
function executeCode(sourceCode, stdin, timeLimitSeconds = 5) {
  return new Promise(async (resolve) => {
    if (!isSafe(sourceCode)) {
      return resolve({
        status: 'Rejected',
        output: '',
        error: 'Unsafe system call detected',
        isCorrect: false
      });
    }

    const dockerOk = await dockerAvailable();
    if (!dockerOk) {
      return resolve({
        status: 'Error',
        output: '',
        error: 'Docker is required but unavailable. Please ensure Docker is installed and running.',
        isCorrect: false
      });
    }

    const tmpDir = path.join('/tmp', `ci_${Date.now()}_${Math.random().toString(36).slice(2)}`);
    fs.mkdirSync(tmpDir, { recursive: true });
    const srcFile = path.join(tmpDir, 'solution.cpp');
    const stdinFile = path.join(tmpDir, 'stdin.txt');
    fs.writeFileSync(srcFile, sourceCode);
    fs.writeFileSync(stdinFile, stdin || '');

    try {
      // Compile + Run in a single Docker command
      const effectiveSec = getEffectiveTimeoutSec(timeLimitSeconds);
      const compileCmd = `g++ ${COMPILE_FLAGS} /workspace/solution.cpp -o /workspace/solution`;
      const runCmd = `timeout ${effectiveSec}s /workspace/solution < /workspace/stdin.txt`;
      const dockerCmd = `docker run --rm --pids-limit=32 --memory="256m" --cpus="0.5" --cap-drop=ALL --cap-add=DAC_OVERRIDE --network none -v ${tmpDir}:/workspace ${DOCKER_IMAGE} bash -c "${compileCmd} && cd /workspace && ${runCmd}"`;

      const result = await runInDocker(dockerCmd, effectiveSec + 10);

      let status, output, error, isCorrect;

      // Determine result from combined output
      const combinedStderr = result.stderr || '';
      const combinedStdout = result.stdout || '';

      // Check for compile error
      if (result.err || combinedStderr.includes('error:')) {
        // Distinguish compile errors from runtime sanitizer output
        const hasCompileError = combinedStderr.match(/solution\.cpp:\d+:\d+: error:/i)
          || combinedStderr.includes('fatal error')
          || combinedStderr.includes('undefined reference');

        if (hasCompileError) {
          status = 'Compile Error';
          error = parseCompilerError(combinedStderr + combinedStdout, sourceCode);
          output = '';
        } else {
          // Likely AddressSanitizer output (runtime error)
          const sanitizerOutput = parseSanitizerOutput(combinedStderr, combinedStdout);
          if (sanitizerOutput) {
            status = sanitizerOutput.status;
            error = sanitizerOutput.message;
            output = sanitizerOutput.output || '';
          } else if (result.err && (result.err.code === 124 || result.err.killed)) {
            status = 'Time Limit Exceeded';
            error = 'Program exceeded time limit';
            output = '';
          } else {
            status = 'Runtime Error';
            error = combinedStderr || combinedStdout || result.err?.message || 'Unknown runtime error';
            output = '';
          }
        }
        isCorrect = false;
      } else {
        // Successful execution
        status = 'Success';
        output = combinedStdout.trim();
        error = '';
        isCorrect = false; // Graded against test cases by caller
      }

      resolve({ status, output, error, isCorrect });
    } finally {
      cleanup(tmpDir);
    }
  });
}

// ── Sanitizer output parser ────────────────────────────────────────────────

/**
 * Parse AddressSanitizer output into structured error info.
 */
function parseSanitizerOutput(stderr, stdout) {
  const full = stderr || '';

  // AddressSanitizer: heap-buffer-overflow on address 0x...
  const heapOverflow = full.match(/AddressSanitizer:\s*(heap-buffer-overflow|heap-use-after-free|stack-buffer-overflow|global-buffer-overflow)/);
  if (heapOverflow) {
    const lineMatch = full.match(/solution\.cpp:(\d+)/);
    return {
      status: 'Runtime Error',
      message: `AddressSanitizer: ${heapOverflow[1]}${lineMatch ? ` at solution.cpp:${lineMatch[1]}` : ''}`,
      output: '',
    };
  }

  // LeakSanitizer: detected memory leaks
  const leakMatch = full.match(/LeakSanitizer:\s*detected memory leaks/i)
    || full.match(/directly leaking \d+ bytes/i);
  if (leakMatch) {
    return {
      status: 'Success', // Leaks don't prevent correct output
      message: `Warning: ${leakMatch[0] || 'Memory leak detected'}`,
      output: stdout?.trim() || '',
    };
  }

  return null;
}

// ── Compiler error parser (kept from original, unchanged) ──────────────────

function parseCompilerError(errorOutput, sourceCode) {
  if (!errorOutput || !sourceCode) {
    return errorOutput || 'Compilation failed';
  }

  const codeLines = sourceCode.split('\n');
  const lines = errorOutput.split('\n');
  const formatted = [];

  for (const line of lines) {
    if (!line.trim()) continue;

    // Match g++ error formats: solution.cpp:10:5: error: message
    const match = line.match(/solution\.cpp:(\d+):(\d+):\s*(error|warning|note):\s*(.+)/);

    if (match) {
      const lineNum = parseInt(match[1]);
      const col = parseInt(match[2]);
      const type = match[3];
      const msg = match[4];
      const errorCodeLine = codeLines[lineNum - 1] || '';
      const columnPointer = ' '.repeat(Math.max(0, col - 1)) + '^';

      if (type === 'error' || type === 'warning' || (type === 'note' && formatted.length === 0)) {
        formatted.push(`[Line ${lineNum}:${col}] ${type.toUpperCase()}: ${msg}\n    ${errorCodeLine}\n    ${columnPointer}`);
      }
    } else if (line.trim() && !line.match(/^compilation terminated/i) && !line.match(/^In function/i)) {
      if (formatted.length > 0) {
        formatted.push(line);
      }
    }
  }

  return formatted.length > 0 ? formatted.join('\n').trim() : errorOutput.trim();
}

// ── Cleanup ────────────────────────────────────────────────────────────────

function cleanup(dir) {
  try { fs.rmSync(dir, { recursive: true, force: true }); } catch (_) {}
}

// ── Run against test cases ─────────────────────────────────────────────────

/**
 * Execute code against multiple test cases with structured validation.
 *
 * Each test case supports:
 *   input          - stdin to feed the program
 *   expectedOutput - expected stdout (string or regex pattern)
 *   validationType - 'exact' | 'contains' | 'regex'
 *   isVisible      - whether to show details to students (true) or hide (false)
 *
 * @param {string} sourceCode     - Student's C++ source code
 * @param {Array}  testCases      - Array of test case objects
 * @param {number} timeLimitSeconds
 * @param {boolean} maskHidden    - If true, hide isVisible=false test case details
 * @returns {Promise<Array>}
 */
async function runAgainstTestCases(sourceCode, testCases, timeLimitSeconds = 5, maskHidden = true) {
  const results = [];
  for (const tc of testCases) {
    // Normalize field names: support both legacy and new schema
    const stdin = (tc.input || tc.stdin || '').toString();
    const expectedRaw = tc.expectedOutput || tc.expected_output || tc.expected || '';
    const expectedStr = expectedRaw === null || expectedRaw === undefined ? '' : expectedRaw.toString();
    const validationType = tc.validationType || tc.validation_type || 'exact';
    const isVisible = tc.isVisible !== undefined ? tc.isVisible : (tc.hidden === undefined ? true : !tc.hidden);

    const result = await executeCode(sourceCode, stdin, timeLimitSeconds);
    const actualStr = (result.output || '').toString();

    // Validate output using the structured validation type
    const validation = validateOutput(actualStr, expectedStr, validationType);
    const passed = result.status === 'Success' && validation.passed;

    // Masking: hide details for tests where isVisible is false
    const shouldMask = maskHidden && !isVisible;

    // Extract cppcheck warnings if this is the first run
    let cppcheckWarnings = [];
    if (results.length === 0) {
      try {
        cppcheckWarnings = await runCppcheck(sourceCode);
      } catch (_) {
        // Non-fatal: cppcheck is advisory
      }
    }

    results.push({
      input:          shouldMask ? '[Hidden]' : stdin,
      expected:       shouldMask ? '[Hidden]' : expectedStr,
      actual:         shouldMask ? (passed ? '[Hidden]' : 'Output Mismatch') : actualStr,
      passed,
      status:         result.status,
      error:          shouldMask ? (result.status === 'Success' ? '' : result.status) : (validation.reason || result.error),
      hidden:         !isVisible,
      validationType,
      divergence:     shouldMask ? undefined : {
        index: validation.divergenceIndex,
        actualTokens: validation.actualTokens,
        expectedTokens: validation.expectedTokens,
      },
      sanitizerWarning: result.status === 'Success' && result.error ? result.error : undefined,
      cppcheckWarnings: results.length === 0 ? cppcheckWarnings : undefined,
    });
  }

  return results;
}

module.exports = { executeCode, runAgainstTestCases, runCppcheck };
