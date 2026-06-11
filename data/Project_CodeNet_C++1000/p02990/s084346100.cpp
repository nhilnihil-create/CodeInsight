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

constexpr int kMax=1e5;
LL fact[kMax], finv[kMax], inv[kMax];

void ComInit(int N) {
//  fact = vector<LL>(N + 1);
//  inv = vector<LL>(N + 1);
//  finv = vector<LL>(N + 1);
  fact[0] = fact[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i <= N; i++){
    fact[i] = fact[i-1] * i % kMod;
    inv[i] = kMod - inv[kMod % i] * (kMod / i) % kMod;
    finv[i] = finv[i-1] * inv[i] % kMod;
  }
}

LL nCr(int n, int r) {
  LL numerator = fact[n];
  LL denominator = finv[r] * finv[n-r] % kMod;
  return (numerator * denominator) % kMod;
}

int main() {
  int N, K; std::cin >> N >> K;
  ComInit(5e4);
  for (int k = 1; k <= K; ++k) {
    std::cout << nCr(N - K + 1, k) * nCr(K - 1,  k - 1) % kMod << std::endl;
  }
}
