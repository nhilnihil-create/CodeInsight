const { exec } = require('child_process');
const fs        = require('fs');
const path      = require('path');

const BLOCKED_REGEX = /\b(system|exec|fork|popen|unlink|rmdir|remove|rename)\s*\(/i;

function isSafe(code) {
  // Remove comments before checking for blocked keywords to avoid false positives
  const cleanCode = code.replace(/\/\/.*$/gm, '').replace(/\/\*[\s\S]*?\*\//g, '');
  return !BLOCKED_REGEX.test(cleanCode);
}

// Parse g++ error messages to extract line numbers, code, and format them nicely
// Handles multiple g++ error formats: errors, warnings, and notes
function parseCompilerError(errorOutput, sourceCode) {
  if (!errorOutput || !sourceCode) {
    return errorOutput || 'Compilation failed';
  }
  
  const codeLines = sourceCode.split('\n');
  const lines = errorOutput.split('\n');
  const formatted = [];
  let lastProcessedLineNum = -1;
  
  for (const line of lines) {
    if (!line.trim()) continue;
    
    // Match various g++ error/warning formats:
    // Format 1: solution.cpp:10:5: error: message
    // Format 2: solution.cpp:10:5: warning: message
    // Format 3: solution.cpp:10:5: note: message
    // Format 4: At global scope (context line)
    const match = line.match(/solution\.cpp:(\d+):(\d+):\s*(error|warning|note):\s*(.+)/);
    
    if (match) {
      const lineNum = parseInt(match[1]);
      const col = parseInt(match[2]);
      const type = match[3];
      const msg = match[4];
      
      // Extract the actual code line (adjust for 0-based indexing)
      const errorCodeLine = codeLines[lineNum - 1] || '';
      
      // Create a pointer to the error column
      const columnPointer = ' '.repeat(Math.max(0, col - 1)) + '^';
      
      // Only include "error" and "warning" entries; skip notes unless they're the first message
      if (type === 'error' || type === 'warning' || (type === 'note' && formatted.length === 0)) {
        formatted.push(`[Line ${lineNum}:${col}] ${type.toUpperCase()}: ${msg}\n    ${errorCodeLine}\n    ${columnPointer}`);
        lastProcessedLineNum = lineNum;
      }
    } else if (line.trim() && !line.match(/^compilation terminated/i) && !line.match(/^In function/i)) {
      // Keep other non-empty lines as context (but skip common non-essential compiler messages)
      if (formatted.length > 0) {
        formatted.push(line);
      }
    }
  }
  
  // If no errors were found, return the raw output
  return formatted.length > 0 ? formatted.join('\n').trim() : errorOutput.trim();
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
      // Use a temporary file for stdin to avoid shell escaping issues with multi-line input
      const stdinFile = path.join(tmpDir, 'stdin.txt');
      fs.writeFileSync(stdinFile, stdin || '');

      const cmd = `timeout ${timeLimitSeconds}s "${binFile}" < "${stdinFile}" 2>&1`;

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

// Execute code against multiple test cases
// maskHidden: if true, masks hidden test case details; if false, returns full results (for internal use only)
async function runAgainstTestCases(sourceCode, testCases, timeLimitSeconds = 5, maskHidden = true) {
  const results = [];
  for (const tc of testCases) {
    // Normalize input and expected fields to be robust to different test case shapes
    const stdin = (tc.input || tc.stdin || '').toString();
    const expectedRaw = tc.expected_output || tc.expected || tc.expectedOutput || '';
    const expectedStr = expectedRaw === null || expectedRaw === undefined ? '' : expectedRaw.toString();

    const result = await executeCode(sourceCode, stdin, timeLimitSeconds);
    const actualStr = (result.output || '').toString();
    const passed = result.status === 'Success' && actualStr.trim() === expectedStr.trim();
    
    // Apply masking based on parameter and hidden flag
    const shouldMask = maskHidden && tc.hidden;
    
    results.push({
      // Mask data for hidden test cases only if maskHidden=true
      input:    shouldMask ? "[Hidden]" : stdin,
      expected: shouldMask ? "[Hidden]" : expectedStr,
      actual:   shouldMask ? (passed ? "[Hidden]" : "Output Mismatch") : actualStr,
      passed,
      status:   result.status,
      error:    shouldMask ? (result.status === 'Success' ? '' : result.status) : result.error,
      hidden:   !!tc.hidden
    });
  }

  return results;
}

module.exports = { executeCode, runAgainstTestCases };
