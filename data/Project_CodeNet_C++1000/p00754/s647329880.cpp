#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

int main() {
  string s;
  while(getline(cin,s), s!=".") {
    stack<char> stk;
    bool f = 1;
    REP(i,s.size()) {
      if (s[i]=='[' || s[i]=='(')
        stk.push(s[i]);
      if (s[i]==']') {
        if (stk.empty() || stk.top() != '[') {
          f = 0;
          break;
        } else
          stk.pop();
      } else if (s[i]==')') {
        if (stk.empty() || stk.top() != '(') {
          f = 0;
          break;
        } else
          stk.pop();
      }
    }
    if (f && stk.empty())
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
}