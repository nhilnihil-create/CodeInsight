#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define MOD (1000000007l)
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)

using namespace std;

void solve() {
  ll k, q;
  cin >> k >> q;
  vector<ll> d(k);
  rep (i, k) cin >> d[i];

  // TODO
  rep (i, q) {
    ll n, x, m;
    cin >> n >> x >> m;
    n--;
    vector<ll> tmp = d;
    rep (j, k) tmp[j] %= m;

    ll inc = 0;
    rep (j, k) if (tmp[j] > 0) inc++;
    inc *= n / k;
    rep (j, n % k) if (tmp[j] > 0) inc++;

    ll sum = 0;
    rep (j, k) sum += tmp[j];
    sum *= n / k;
    rep (j, n % k) sum += tmp[j];
    sum += x % m;

    ll shuukai = sum / m;

    ll ans = inc - shuukai;
    cout << ans << endl;
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  cout << fixed;
  solve();
  return 0;
}
