#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i)=0;(i)<(n);(i)++)
using ll = long long;
bool custom1 (pair<int, int> a, pair<int, int> b) {
  return (a.first < b.first);
}
bool custom2(pair<int, int> a, pair<int, int> b) {
  return (a.second < b.second);
}

const int MAX = 510000;
const long long MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
  int k, q;
  cin >> k >> q;
  vector<long long> d(k);
  rep(i, k) cin >> d[i];
  rep(i, q) {
    long long n, x, m;
    cin >> n >> x >> m;
    vector<long long> d_mod(k);
    x %= m;
    rep(j, k) d_mod[j] = d[j] % m;
    long long t = (n-1) / k;
    long long r = (n-1) % k;
    vector<long long> times(k, t);
    rep(j, k) {
      if(j+1 <= r) times[j]++;
      else break;
    }
    long long last = x;
    long long diff = 0;
    rep(j, k) {
      if(d_mod[j] == 0) diff += times[j];
      last += d_mod[j] * times[j];
    }
    diff += (last / m) - (x / m);
    cout << (n-1) - diff << endl;
  }
}
