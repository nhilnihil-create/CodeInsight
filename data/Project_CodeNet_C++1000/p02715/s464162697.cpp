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

LL modpow(LL a, LL b, LL mod = kMod) {
  LL r = 1;
  while (b) {
    if (b % 2 == 1) r = r * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return r;
}

int main() {
  LL N, K; cin >> N >> K;

  vector<LL> dp(K + 1);
  dp[0] = 0;
  for (int k = 1; k <= K; ++k) {
    int x = K/k;
    dp[k] = modpow(x, N) % kMod;
  }

  LL total = 0;
  for (int k = K; k > 0; --k) {
    for (int j = 2; j * k <= K; ++j) {
      dp[k] = (dp[k] + kMod - dp[j*k]) % kMod;
    }
    LL item = dp[k] * k % kMod;
    total = (total + item) % kMod;
  }
  cout << total << endl;
}
