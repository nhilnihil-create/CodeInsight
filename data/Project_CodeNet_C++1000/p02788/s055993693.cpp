#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template <typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n = 0) : n(n), d(n + 1) {}
  void add(int i, T x = 1) {
    for (i++; i <= n; i += i & -i) d[i] += x;
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i & -i) x += d[i];  // 最下位bitの加算
    return x;
  }
  T sum(int l, int r) { return sum(r - 1) - sum(l - 1); }
};

int main() {
  ll n, d, a, ans = 0;
  cin >> n >> d >> a;
  vector<P> p(n);

  rep(i, n) cin >> p[i].first >> p[i].second;
  sort(p.begin(), p.end());

  BIT<ll> bit(n + 1);

  rep(i, n) {
    ll x = p[i].first;
    ll h = p[i].second;
    h -= bit.sum(i);
    if (h <= 0) continue;
    ll num = (h + a - 1) / a;
    ans += num;
    ll da = num * a;
    bit.add(i, da);
    bit.add(upper_bound(p.begin(), p.end(), P(x + d * 2 + 1, 0)) - p.begin(),
            -da);
  }
  cout << ans << endl;
  return 0;
}