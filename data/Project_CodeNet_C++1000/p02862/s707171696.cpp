#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int X, Y;
const int MOD = 1000000007;
const int MAX = 2100000;

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
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  COMinit();

  cin >> X >> Y;

  int N = 2 * Y - X;
  int M = 2 * X - Y;
  if (N % 3 != 0 || M % 3 != 0) {
    cout << "0" << endl;
    return 0;
  }
  N /= 3;
  M /= 3;

  cout << COM(N + M, min(N, M)) << endl;
  return 0;
}
