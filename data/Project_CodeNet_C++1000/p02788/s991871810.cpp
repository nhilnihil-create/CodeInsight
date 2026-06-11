#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long double PI = acos(-1);
#define chmin(i, j) i = min(i, j);
#define chmax(i, j) i = max(i, j);
#define rep(i, n) for(int i=0;i<n;i++)
ll MOD = 1000000007;
ll fact(ll m) {
  if(m == 0 || m == 1) return 1LL;
  else return (m * fact(m-1LL)) % MOD;
}
bool custom(pair<ll, ll> a, pair<ll, ll> b) {
  if(a.first == b.first) return (a.second > b.second);
  else return a.first < b.first;
}
int main() {
  ll n, d, a;
  cin >> n >> d >> a;
  vector<ll> x(n);
  vector<ll> h(n);
  vector<pair<ll, ll>> xh(n);
  for(int i=0;i<n;i++) {
    cin >> x[i];
    cin >> h[i];
    xh[i].first = x[i];
    xh[i].second = h[i];
  }
  sort(xh.begin(), xh.end(), custom);
  for(int i=0;i<n;i++) {
    x[i] = xh[i].first;
    h[i] = xh[i].second;
  }
  vector<ll> damage(n);
  ll ans = 0;
  for(int i=0;i<n;i++) {
    if(i == 0) damage[i] = 0;
    else damage[i] = damage[i-1] + damage[i];
    h[i] -= damage[i];
    if(h[i] <= 0) continue;
    auto it = upper_bound(x.begin(), x.end(), x[i] + 2LL * d);
    int dist = distance(x.begin(), it);
    ll da;
    ll time;
    if(h[i] % a == 0) time = h[i] / a;
    else time = h[i] / a + 1;
    da = a * time;
    damage[i] += da;
    if(dist != n) damage[dist] -= da;
    ans += time;
  }
  cout << ans << endl;
}
