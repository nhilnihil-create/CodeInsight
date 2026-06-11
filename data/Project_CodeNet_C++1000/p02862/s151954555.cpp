#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// フェルマーの小定理より、素数Mに対しa^(-1)はa^(M - 2)と合同であることを使う。
const ll MOD = 1000000007;

ll pow(ll x, ll n) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % MOD;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main() {
  int X, Y;
  cin >> X >> Y;

  if (!( ((2 * X - Y) >= 0) && ((2 * Y - X) >= 0) && ((2 * X - Y) % 3 == 0) && ((2 * Y - X) % 3 == 0))) {
    cout << 0 << endl;
    return 0;
  }

  int a = (2 * X - Y) / 3, b = (2 * Y - X) / 3;

  ll bunshi = 1, bunbo1 = 1, bunbo2 = 1;
  for(int i = 1; i <= a + b; i++) {
    bunshi *= i;
    bunshi %= MOD;
  }
  for(int i = 1; i <= a; i++) {
    bunbo1 *= i;
    bunbo1 %= MOD;
  }
  bunbo1 = pow(bunbo1, MOD - 2);

  for(int i = 1; i <= b; i++) {
    bunbo2 *= i;
    bunbo2 %= MOD;
  }
  bunbo2 = pow(bunbo2, MOD - 2);

  ll ans;
  ans = bunshi * bunbo1;
  ans %= MOD;
  ans *= bunbo2;
  ans %= MOD;

  cout << ans << endl;
  return 0;
}
