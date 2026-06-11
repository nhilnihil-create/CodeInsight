#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = (ll)1e9;
const ll MOD = 1000000007;
long long modinv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
} /*
 long long combination(long n, long r, long long mod) {
   // nCrを返す　O(r)
   // 逆元はその場で対応
   if (n < r) return 0;
   //if (n < r) swap(n, r);
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
   return (((bunsi % mod) * modinv(bunbo, mod))) % mod;
 }*/
int memo[2010][2010];
ll comb(int n, int r, int mod) {
  if (n < 0 || r < 0 || n < r) {
    return 0;
  }
  if (memo[n][r] != 0) return memo[n][r];
  if (r == 0 || n == r || n == 0) {
    return memo[n][r] = 1;
  }
  int k = comb(n - 1, r - 1, mod) % mod;
  int l = comb(n - 1, r, mod) % mod;
  memo[n - 1][r - 1] = k, memo[n - 1][r] = l;
  return memo[n][r] = (k + l) % mod;
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
    ll ans = comb(K - 1, i, MOD);
    // while (ans < 0) ans += MOD;
    ans *= comb(N - K + 1, i + 1, MOD);
    // while (ans < 0) ans += MOD;
    cout << ans % MOD << endl;
    if (ans % MOD == 20825) {
      int a = 19;
    }
  }
}