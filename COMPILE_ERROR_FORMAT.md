# Compile Error Display Format

## Backend Output Format (executor.js)
When g++ returns an error like:
```
solution.cpp:6:1: error: 'fgdf' was not declared in this scope
```

The parseCompilerError function formats it as:
```
[Line 6:1] ERROR: 'fgdf' was not declared in this scope
    fgdf
    ^
```

## Frontend Parsing (Exercises.jsx)
The parseErrorBlock function:
- Splits error text by newlines
- Matches header: `[Line X:Y] TYPE: message`
- Extracts code line: starts with 4 spaces, no `^` character
- Extracts pointer: starts with 4 spaces, contains `^` character

## Display (renderErrorBlock)
Shows as a clickable error block with:
- Red header: `● [Line X:Y] ERROR`
- Yellow message
- Gray code block with code line and caret pointer
- Click to jump to line in editor
- Highlights when selected

## Example Full Error Output
```
[Line 6:1] ERROR: 'fgdf' was not declared in this scope
    fgdf
    ^
[Line 8:0] ERROR: no newline at end of file
    }
    ^
```

## Testing
Run code with compilation errors to verify:
1. Error is parsed correctly
2. Code line is extracted
3. Column pointer is shown
4. Clicking error jumps to line in editor
