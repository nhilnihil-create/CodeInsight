#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 1100000;
const int MOD = 1e9 + 7;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  int x, y;
  cin >> x >> y;
  int tmp = min(x, y) / 3;
  int c = -1;
  rep(i, tmp + 1) {
    int a = x - 3 * i;
    int b = y - 3 * i;
    if (a == 2 * b || b == 2 * a) {
      c = i;
      break;
    }
  }
  if (c == -1) {
    cout << 0 << endl;
  } else {
    int d = min(x - 3 * c, y - 3 * c);
    COMinit();

    cout << COM(2 * c + d, c) << endl;
  }

  return 0;
}