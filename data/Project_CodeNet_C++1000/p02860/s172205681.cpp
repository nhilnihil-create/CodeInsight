#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;

signed main() {
  int n;
  string s;
  cin >> n >> s;

  if(s.substr(0, n/2) == s.substr(n/2, n/2) && n % 2 == 0) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }

  return 0;
}