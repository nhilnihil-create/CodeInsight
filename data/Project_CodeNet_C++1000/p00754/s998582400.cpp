#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char S[101];

bool solve() {
    stack<char> ps;
    for (int i = 0; S[i]; i++) {
        switch (S[i]) {
            case '(':
                ps.push('(');
                break;
            case '[':
                ps.push('[');
                break;
            case ')':
                if (ps.empty() || ps.top() != '(') {
                    return false;
                }
                ps.pop();
                break;
            case ']':
                if (ps.empty() || ps.top() != '[') {
                    return false;
                }
                ps.pop();
                break;
        }
    }
    return ps.empty();
}

int main() {
    for (;;) {
        gets(S);
        if (strcmp(S, ".") == 0) { break; }
        printf("%s\n", solve() ? "yes" : "no");
    }
    return 0;
}