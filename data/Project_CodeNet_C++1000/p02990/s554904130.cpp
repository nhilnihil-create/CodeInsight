#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

vector<LL> fact, finv, inv;

void init_nCk(int N) {
  fact.resize(N + 1);
  finv.resize(N + 1);
  inv.resize(N + 1);
  fact[0] = fact[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i <= N; i++) {
    fact[i] = fact[i - 1] * i % kMod;
    inv[i] = kMod - inv[kMod % i] * (kMod / i) % kMod;
    finv[i] = finv[i - 1] * inv[i] % kMod;
  }
}

LL nCk(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fact[n] * (finv[k] * finv[n - k] % kMod) % kMod;
}

int main() {
  int N, K; cin >> N >> K;
  init_nCk(N);

  for (int i = 0; i < K; ++i) {
    LL a = nCk(N-K+1, i+1);
    LL b = nCk(K-1, i);
    cout << (a * b) % kMod << endl;
  }
}
