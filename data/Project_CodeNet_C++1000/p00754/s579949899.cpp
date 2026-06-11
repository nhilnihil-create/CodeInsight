#include <bits/stdc++.h>
using namespace std;

const string C = "[]()";

int main() {
  for(string s; getline(cin, s) && s != ".";) {
    try {
      stack<int> stk;
      for(int i = 0; i < s.size(); ++i) {
        int p = C.find(s[i]);
        if(p == string::npos) continue;
        if(p % 2 == 0) {
          stk.push(p);
        } else {
          if(stk.empty() || stk.top() != p-1) {
            throw "no";
          }
          stk.pop();
        }
      }
      if(stk.size()) throw "no";
      throw "yes";
    } catch(const char *res) {
      cout << res << endl;
    }
  }
  return 0;
}