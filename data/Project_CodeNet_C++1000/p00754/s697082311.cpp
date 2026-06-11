/*
 * by purple
 * at 12-01-01 10:58:09
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define sz(x) ((int)((x).size()))
#define out(x) printf(#x" %d\n", x)
#define rep(i,n) for(int i=0;i<(n);++i)
#define repf(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 100 + 10;

char s[maxn];
bool st[maxn];
int top;

int main() {
    while (cin.getline(s, maxn)) {
        if (strcmp(s, ".") == 0) {
            break;
        }
        top = -1;
        bool f = true;
        for (int i = 0; s[i]; ++i) {
            if (s[i] == '[') {
                st[++top] = true;
            } else if (s[i] == ']') {
                if (top == -1 || st[top] != true) {
                    f = false;
                    break;
                }
                --top;
            } else if (s[i] == '(') {
                st[++top] = false;
            } else if (s[i] == ')') {
                if (top == -1 || st[top] != false) {
                    f = false;
                    break;
                }
                --top;
            }
        }
        if (top != -1) {
            f = false;
        }
        puts (f? "yes" : "no");
    }
    return 0;
}