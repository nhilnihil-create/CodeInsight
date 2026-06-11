#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <stack>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

char str[1000];
int main() {
  while (fgets(str, 999, stdin), str[0] != '.') {
    stack<int> st;
    int len = strlen(str);
    bool ok = true;
    REP(i, len) {
      if (str[i] == '(') { st.push('('); }
      else if (str[i] == '[') { st.push('['); }
      else if (str[i] == ')') {
        if (st.empty() || st.top() != '(') { ok = false; break; }
        st.pop();
      } else if (str[i] == ']') {
        if (st.empty() || st.top() != '[') { ok = false; break; }
        st.pop();
      }
    }
    if (!st.empty()) { ok = false; }
    puts(ok ? "yes" : "no");
  }
}