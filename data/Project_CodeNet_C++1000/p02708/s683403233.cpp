// g++ .cpp && ./a.out
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef pair<int, int> p;
typedef long long ll;

const int mod = 1000000007;
const int inf = 1000000007;

int main() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  for (ll i = k; i <= n + 1; i++) {
    ans += ((i * (2 * n - i + 1) - i * (i - 1)) / 2 + 1) % mod;
    // cout << (i * (2 * n - i + 1) - i * (i - 1)) / 2 << endl;
    ans %= mod;
  }
  cout << ans << endl;
}
