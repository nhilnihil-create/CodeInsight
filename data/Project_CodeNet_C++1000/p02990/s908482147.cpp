#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = (ll)1e9;
const ll MOD = 1000000007;
long long modpow(long long a, long long n) {
  long long res = 1;
  long long mod = n + 2;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}
long long inverse(long long x, long long modding) {
  return modpow(x, modding - 2);
}
long long combination(long n, long r, long long mod) {
  // nCrを返す　O(r)
  // 逆元はその場で対応
  if (n < r) return 0;
  if (n < r) swap(n, r);
  long long bunbo = 1;
  long cnt = r;
  while (0 < cnt) {
    bunbo *= cnt;
    bunbo % mod;
    cnt--;
  }
  if (bunbo == 0) return 1;
  long long bunsi = 1;
  cnt = 0;
  while (cnt < r) {
    bunsi *= (n - cnt);
    bunsi %= mod;
    cnt++;
  }
  return (((bunsi % mod) * inverse(bunbo, mod))) % mod;
}
long long longpow(long long n, long long a, long long mod) {
  if (a == 0) return 1;
  if (a == 1) return n % mod;
  if (a % 2 == 1) return (n * longpow(n, a - 1, mod)) % mod;
  ll t = longpow(n, a / 2, mod) % mod;
  return (t * t) % mod;
}
struct Combination {
  // Combnation(x)　xCxまでを生成
  // RetCombination(n,r) nCrを返す
  vector<vector<long long>> combination;
  Combination(int x) {
    combination.resize(x + 1);
    for (int i = 0; i < x + 1; i++) {
      combination[i].resize(x + 1);
    }
    combination[0][0] = 1;
    for (int i = 0; i < x; i++) {
      for (int j = 0; j <= i; j++) {
        combination[i + 1][j] += combination[i][j];
        combination[i + 1][j + 1] += combination[i][j];
        combination[i + 1][j] %= MOD, combination[i + 1][j + 1] %= MOD;
      }
    }
  }
  long long RetCombination(int n, int r) { return combination[n][r]; }
};
int main() {
  ll N, K;
  cin >> N >> K;
  Combination cm(N + 10);
  ll blue = K, red = N - K;
  REP(i, blue) {
    /*ll ans = combination(K - 1, i, MOD);
    while (ans < 0) ans += MOD;
    ans *= combination(N - K + 1, i + 1, MOD);
    while (ans < 0) ans += MOD;*/
    cout << (cm.RetCombination(K - 1, i) *
             cm.RetCombination(N - K + 1, i + 1)) %
                MOD
         << endl;
  }
}