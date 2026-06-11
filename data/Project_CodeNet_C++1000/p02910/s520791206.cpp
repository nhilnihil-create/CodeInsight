#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for (int i = s; i < n; i++)

int main() {
  string s;
  cin >> s;
  int n = s.size();
  bool ok = true;
  rep(i,1,n+1) {
    if (i % 2 == 1) {
      if (s.substr(i-1,1) == "L") {
        ok = false;
      }
    } else {
      if (s.substr(i-1,1) == "R") {
        ok = false;
      }
    }
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}