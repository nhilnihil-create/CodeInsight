#include <bits/stdc++.h>
using namespace std;

int n;
char buf[11451419];

int main() {
  while (1) {
    fgets(buf, sizeof(buf), stdin);
    if (buf[0] == '.') return 0;

    stack<char> q;
    bool ans = true;

    n = strlen(buf);
    for (int i=0; i<n; i++) {
      char c = buf[i];
      if (c == '(' || c == '[') {
        q.push(c);
      } else if (c == ')') {
        if (q.empty()) ans = false;
        else {
          if (q.top() != '(') ans = false;
          q.pop();
        }
      } else if (c == ']') {
        if (q.empty()) ans = false;
        else {
          if (q.top() != '[') ans = false;
          q.pop();
        }
      }
    }

    if (!q.empty()) ans = false;

    if (!ans) puts("no");
    else puts("yes");
  }
}