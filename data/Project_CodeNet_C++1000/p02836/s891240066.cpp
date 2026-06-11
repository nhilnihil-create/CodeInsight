#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size(), ans = 0;
  if(n == 1) {
    cout << 0 << endl;
    return 0;
  }
  else {
    rep(i, n/2) {
      if(s.at(i) != s.at(n-1-i)) ans++;
    }
    cout << ans << endl;
  }
}