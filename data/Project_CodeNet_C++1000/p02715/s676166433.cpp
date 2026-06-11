#include <iostream>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

const int64_t mod = 1e9 + 7;
unordered_map<int64_t, int64_t> memo;

int64_t mod_pow(int64_t x, int64_t n) {
  int64_t key = x * 1e6 + n;
  if (memo.count(key)) return memo[key];
  int64_t ret = 1;
  while (n) {
    if (n % 2) {
      ret = (ret * x) % mod;
    }
    x = x * x % mod;
    n /= 2;
  }
  return memo[key] = ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  int64_t N, K;
  cin >> N >> K;

  vector<int64_t> count(K + 1, 0);
  for (int64_t X = K; X >= 1; --X) {
    count[X] = mod_pow(K / X, N);
    for (int64_t m = 2; m * X <= K; ++m) {
      count[X] = (count[X] - count[m * X] + mod) % mod;
    }
  }

  int64_t answer = 0;
  rep(i, K + 1) {
    int64_t add = (i * count[i]) % mod;
    answer = (answer + add) % mod;
  }
  cout << answer << endl;
  return 0;
}
