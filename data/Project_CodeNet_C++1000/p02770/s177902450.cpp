#include <bits/stdc++.h>
       
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  int k, q;
  cin >> k >> q;
  vector<ll> d(k), e(k);
  for (int i = 0; i < (int)(k); ++i) cin >> d[i];

  for (int i = 0; i < (int)(q); ++i) {
    ll n, x, m;
    cin >> n >> x >> m;

    x %= m;
    for (int i = 0; i < (int)(k); ++i) e[i] = d[i] % m;
    ll ans = n - 1, s = accumulate((e).begin(), (e).end(), 0LL);
    ll l = (n - 1) / k;

    ans -= l * count((e).begin(), (e).end(), 0LL);
    for (int i = 0; i < (int)((n - 1) % k); ++i) ans -= (e[i] == 0);

    ll y = x + l * s;
    for (int i = 0; i < (int)((n - 1) % k); ++i) y += e[i];
    ans -= y / m - x / m;

    cout << ans << endl;
  }

  return 0;
}
