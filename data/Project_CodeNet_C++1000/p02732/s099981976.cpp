#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

ll chose2(ll n) {
  return n * (n - 1) / 2;
}

int main() {
  int n;
  cin >> n;
  vector<int> as(n);
  rep(i, n) cin >> as[i];
  rep(i, n) as[i]--;
  vector<int> cnt(n);
  rep(i, n) cnt[as[i]]++;
  ll tot = 0;
  rep(i, n) { tot += chose2(cnt[i]); }
  rep(i, n) {
    ll ans = tot;
    ans -= chose2(cnt[as[i]]);
    ans += chose2(cnt[as[i]] - 1);
    cout << ans << endl;
  }
  return 0;
}