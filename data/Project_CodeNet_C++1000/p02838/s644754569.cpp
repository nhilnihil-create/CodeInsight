#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;
const int N = 3e5 + 5;
int n;
ll t, res;
ll psum[N];
ll cnt[63];


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    for (int j = 0; j <= 62; ++j) {
      if (t & (1LL << j)) {
        ++cnt[j];
      }
    }
  }
  for (int i = 0; i <= 62; ++i) {
    ll p = cnt[i] * (n - cnt[i]) % MOD;
    res = (res + ll (pow(2, i)) % MOD * p % MOD) % MOD;
  }
  cout << res << endl;

  return 0;
}
