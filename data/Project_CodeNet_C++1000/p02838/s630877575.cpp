#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll ans = 0;
  for (ll i = 0; i < 60; ++i) {
    ll one = 0;
    for (int j = 0; j < n; ++j) {
      if ((a[j] >> i) & 1ll) {
        one++;
      }
    }
    ll t = (one * (n - one)) % MOD;
    ll u = (1ll << i) % MOD;
    ll res = (t * u) % MOD;
    ans = (ans + res) % MOD;
  }
  cout << ans << endl;
  return 0;
}