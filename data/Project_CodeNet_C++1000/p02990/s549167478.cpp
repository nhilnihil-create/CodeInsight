#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
struct Combination {
  vector<vector<ll>> memo;
  Combination(int x) {
    memo.resize(x + 1);
    for (int i = 0; i <= x; i++) memo[i].resize(x + 1, 0);
  }
  ll RetCombination(int n, int r, int mod) {
    if (n < 0 || r < 0 || n < r) {
      return 0;
    }
    if (memo[n][r] != 0) return memo[n][r];
    if (r == 0 || n == r || n == 0) {
      return memo[n][r] = 1;
    }
    ll k = RetCombination(n - 1, r - 1, mod) % mod;
    ll l = RetCombination(n - 1, r, mod) % mod;
    memo[n - 1][r - 1] = k, memo[n - 1][r] = l;
    return memo[n][r] = (k + l) % mod;
  }
};
long long longpow(long long n, long long a, long long mod) {
  if (a == 0) return 1;
  if (a == 1) return n % mod;
  if (a % 2 == 1) return (n * longpow(n, a - 1, mod)) % mod;
  ll t = longpow(n, a / 2, mod) % mod;
  return (t * t) % mod;
}
int main() {
  int N, K;
  cin >> N >> K;
  Combination cm(2010);
  for (int i = 1; i <= K; ++i) {
    cout << (cm.RetCombination(K - 1, i - 1, MOD) *
                 cm.RetCombination(N - K + 1, i, MOD) +
             MOD) %
                MOD
         << endl;
  }
}