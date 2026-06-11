#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int MOD = 1e9 + 7;

ll fexp(int a, int n) {
  ll tmp = a, ans = 1;

  while (n > 0) {
    if (n & 1) ans = (ans * tmp) % MOD;
    tmp = (tmp * tmp) % MOD;
    n >>= 1;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  ll ans = fexp(10, n);

  ans = (2 * MOD + ans - 2 * fexp(9, n)) % MOD;
  ans = (ans + fexp(8, n)) % MOD;

  cout << ans << endl;

  return 0;
}
