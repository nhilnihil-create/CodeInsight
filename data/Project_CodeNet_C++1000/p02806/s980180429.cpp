#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

signed main() {
  int n;
  cin >> n;

  vector<string> t(n);
  vector<int> s(n);
  rep(i,n) {
    cin >> t[i] >> s[i];
  }

  for (int i = 1; i < n; i++) {
    s[i] += s[i - 1];
  }

  string x;
  cin >> x;

  int sum = s[n - 1];
  for (int i = 0; i < n; i++) {
    if(t[i] == x) {
      sum = sum - s[i];
      break;
    }
  }

  cout << sum << '\n';

}