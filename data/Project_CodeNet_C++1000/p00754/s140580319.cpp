#include <cstdio>
#include <stack>
using namespace std;

int main() {
  char str[128];
  while (fgets(str, sizeof(str), stdin)) {
    if (str[0] == '.') { break; }
    stack<char> S;
    for (int i = 0; str[i]; ++i) {
      char c = str[i];
      switch (c) {
      case '(': S.push(')'); break;
      case '[': S.push(']'); break;
      case ')': case ']':
        if (S.empty() || S.top() != c) { goto bad; }
        S.pop();
      }
    }
    if (!S.empty()) { goto bad; }
    puts("yes");
    continue;
bad:
    puts("no");
  }
}