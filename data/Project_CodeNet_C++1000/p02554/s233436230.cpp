#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll MOD = 1e9+7;

int main() {
  ll N;
  cin >> N;
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 1, temp = 1, temp2 = 1;;
  rep(i, N) ans = (ans * 10) % MOD;
  rep(i, N) temp = (temp * 9) % MOD;
  rep(i, N) temp2 = (temp2 * 8) % MOD;
  ans -= temp;
  if (ans < 0) ans += MOD;
  ans -= temp;
  if (ans < 0) ans += MOD;
  ans += temp2;
  ans %= MOD;
  cout << ans << endl;
  return 0;
}