#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1000000007;

int64_t accum(int64_t num) { return num * (num + 1) / 2; }

int main() {
  int64_t N, K;
  cin >> N >> K;

  int64_t ans = 1;
  for (int i = K; i <= N; i++) {
    int64_t min = accum(i - 1);
    int64_t max = accum(N) - accum(N - i);
    ans += ((max - min) + 1) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
