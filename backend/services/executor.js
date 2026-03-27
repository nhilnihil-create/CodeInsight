const { exec } = require('child_process');
const fs        = require('fs');
const path      = require('path');

const BLOCKED = ['system(','exec(','fork(','popen(','unlink(','rmdir('];

function isSafe(code) {
  return !BLOCKED.some(p => code.includes(p));
}

// Parse g++ error messages to extract line numbers, code, and format them nicely
function parseCompilerError(errorOutput, sourceCode) {
  if (!errorOutput || !sourceCode) {
    return errorOutput || 'Compilation failed';
  }
  
  const codeLines = sourceCode.split('\n');
  const lines = errorOutput.split('\n');
  const formatted = [];
  
  for (const line of lines) {
    if (!line.trim()) continue;
    
    // Format: solution.cpp:10:5: error: name 'x' is not declared
    const match = line.match(/solution\.cpp:(\d+):(\d+):\s*(error|warning):\s*(.+)/);
    if (match) {
      const lineNum = parseInt(match[1]);
      const col = parseInt(match[2]);
      const type = match[3];
      const msg = match[4];
      
      // Extract the actual code line (adjust for 0-based indexing)
      const errorCodeLine = codeLines[lineNum - 1] || '';
      
      // Create a pointer to the error column
      const columnPointer = ' '.repeat(Math.max(0, col - 1)) + '^';
      
      formatted.push(`[Line ${lineNum}:${col}] ${type.toUpperCase()}: ${msg}\n    ${errorCodeLine}\n    ${columnPointer}`);
    } else if (line.trim()) {
      // Keep other non-empty lines as context
      formatted.push(line);
    }
  }
  
  return formatted.join('\n');
}

function executeCode(sourceCode, stdin, timeLimitSeconds = 5) {
  return new Promise((resolve) => {
    if (!isSafe(sourceCode)) {
      return resolve({
        status: 'Rejected',
        output: '',
        error: 'Unsafe system call detected',
        isCorrect: false
      });
    }

    const tmpDir = path.join('/tmp', `ci_${Date.now()}_${Math.random().toString(36).slice(2)}`);
    fs.mkdirSync(tmpDir, { recursive: true });
    const srcFile = path.join(tmpDir, 'solution.cpp');
    const binFile = path.join(tmpDir, 'solution');
    fs.writeFileSync(srcFile, sourceCode);

    // Step 1: Compile
    exec(`g++ "${srcFile}" -o "${binFile}" -std=c++17 2>&1`, (compErr, stdout, stderr) => {
      if (compErr) {
        cleanup(tmpDir);
        // Capture compilation error output
        const compilerOutput = (stdout && stdout.trim()) || (stderr && stderr.trim()) || '';
        
        // If we have compiler output with error info, parse it
        if (compilerOutput) {
          const formattedError = parseCompilerError(compilerOutput, sourceCode);
          return resolve({
            status: 'Compile Error',
            output: '',
            error: formattedError,
            isCorrect: false
          });
        }
        
        // Fallback if no compiler output captured
        return resolve({
          status: 'Compile Error',
          output: '',
          error: compErr.message || 'Compilation failed (no output)',
          isCorrect: false
        });
      }

      // Step 2: Run with timeout and stdin
      const safeStdin = (stdin || '').replace(/"/g, '\\"');
      const cmd = `echo "${safeStdin}" | timeout ${timeLimitSeconds}s "${binFile}" 2>&1`;

      exec(cmd, { timeout: (timeLimitSeconds + 2) * 1000 }, (runErr, stdout, stderr) => {
        cleanup(tmpDir);
        if (runErr) {
          if (runErr.killed || runErr.code === 124) {
            return resolve({ status: 'Time Limit Exceeded', output: '', error: 'Program exceeded time limit', isCorrect: false });
          }
          const errorMsg = stderr || runErr.message;
          return resolve({ status: 'Runtime Error', output: '', error: errorMsg, isCorrect: false });
        }
        resolve({ status: 'Success', output: stdout.trim(), error: '', isCorrect: false });
      });
    });
  });
}

function cleanup(dir) {
  try { fs.rmSync(dir, { recursive: true, force: true }); } catch (_) {}
}

async function runAgainstTestCases(sourceCode, testCases, timeLimitSeconds = 5) {
  const results = [];
  for (const tc of testCases) {
    const result = await executeCode(sourceCode, tc.input, timeLimitSeconds);
    const passed = result.status === 'Success' &&
                   result.output.trim() === (tc.expected_output || '').trim();
    results.push({
      input:    tc.input,
      expected: tc.expected_output,
      actual:   result.output,
      passed,
      status:   result.status,
      error:    result.error
    });
  }
  return results;
}

module.exports = { executeCode, runAgainstTestCases };
