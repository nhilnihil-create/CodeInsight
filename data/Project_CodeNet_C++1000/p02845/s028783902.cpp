#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

const int mod = 1e9 + 7;

signed main() {
  int n;
  cin >> n;

  vector<int> a(n),cnt(n + 1);
  rep(i,n) cin >> a[i];

  cnt[0] = 3;
  int ans = 1;

  for (int i = 0; i < n; i++) {
    ans *= cnt[a[i]];
    ans %= mod;

    cnt[a[i]]--;
    cnt[a[i] + 1]++;
  }

  cout << ans << '\n';

}
