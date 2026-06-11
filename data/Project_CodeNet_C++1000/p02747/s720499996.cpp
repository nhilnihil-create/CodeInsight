#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

int main() {
  string s, t;
  cin >> s;

  REP(i, s.size() / 2) {
    t += "hi";
  }
  
  if (s == t)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
  return 0;
}