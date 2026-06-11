#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ll n; cin >> n;
  if (n%2) cout << 0 << endl;
  else {
    ll res = 0;
    ll tmp = 10;
    while (tmp <= n) {
      res += n/tmp;
      tmp *= 5;
    }
    cout << res << endl;
  }
}