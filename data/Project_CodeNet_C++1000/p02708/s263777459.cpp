#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

const int MOD = 1e9 + 7;

ll sum(ll l, ll r) { return (l + r) * (r - l + 1) / 2; }

int main() {
  int n, k;
  cin >> n >> k;

  ll ans = 0;
  for(int i = k; i < n + 2; i++) {
    ll a = sum(0, i - 1);
    ll b = sum(n - i + 1, n);
    ans += b - a + 1;
  }

  cout << ans % MOD;
}
