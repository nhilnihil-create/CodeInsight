#include <bits/stdc++.h>
using namespace std;

int MAX = 2010;
int MOD = 1000000007;
vector<long long int> fac(MAX), finv(MAX), inv(MAX);

void COMinit() {
  fac.at(0) = 1;
  fac.at(1) = 1;
  finv.at(0) = 1;
  finv.at(1) = 1;
  inv.at(1) = 1;
  for (int i = 2; i < MAX; i++) {
    fac.at(i) = fac.at(i - 1) * i % MOD;
    inv.at(i) = MOD - inv.at(MOD % i) * (MOD / i) % MOD;
    finv.at(i) = finv.at(i - 1) * inv.at(i) % MOD;
  }
}

long long int COM(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac.at(n) * (finv.at(k) * finv.at(n - k) % MOD) % MOD;
}

int main() {
  int N, K;
  cin >> N >> K;
  COMinit();
  for (int i = 1; i <= K; i++) {
    long long int ans = COM(K - 1, i - 1) * COM(N - K + 1, i) % MOD;
    cout << ans << endl;
  }
}