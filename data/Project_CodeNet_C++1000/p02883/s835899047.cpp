#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,int>;

const int N = 200000;
const ll INF = 1e18;

int n, a[N], f[N];
ll k;
P af[N];

bool isOK(ll key) {
  ll tr = 0;
  rep(i, n) {
    if (af[i].first <= key) continue;
    tr += (af[i].first - key + af[i].second - 1) / af[i].second;
  }
  return tr <= k;
}

ll binary_search(ll ok, ll ng) {
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (isOK(mid)) ok = mid;
    else ng = mid;
  }
  return ok;
}

int main() {
  cin >> n >> k;
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> f[i];
  sort(a, a + n);
  sort(f, f + n, greater<int>());
  rep(i, n) af[i] = make_pair((ll)a[i] * f[i], f[i]);
  ll ans = binary_search(INF, -1);
  cout << ans << endl;
  return 0;
}