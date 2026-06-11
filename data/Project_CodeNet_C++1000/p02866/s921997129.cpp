#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll MOD = 998244353;

int d[100009];

int main() {
  int n;
  cin >> n;
  rep(i, n) cin >> d[i];

  if (d[0] > 0) {
    cout << 0 << endl;
    return 0;
  }

  sort(d + 1, d + n);
  if (d[1] == 0) {
    cout << 0 << endl;
    return 0;
  }

  vector<int> cnt(n, 0);
  cnt[0] = 1;
  ll ans = 1;
  for (int i = 1; i < n; ++i) {
    ans = ans * cnt[d[i]-1] % MOD;
    ++cnt[d[i]];
  }
  cout << ans << endl;
  return 0;
}