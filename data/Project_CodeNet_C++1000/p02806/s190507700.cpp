#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N;
  cin >> N;
  string s[100];
  int t[100];
  for (int i = 0; i < N; i++) {
    cin >> s[i] >> t[i];
  }
  string x;
  cin >> x;

  bool flag = false;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (flag) {
      ans += t[i];
    }

    if (s[i] == x) {
      flag = true;
    }
  }

  cout << ans << endl;
  return 0;
}