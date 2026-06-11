#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

typedef long long LL;
typedef vector<int> VI;

const static int MAX_NUM_DIGITS = 60;

const static uint64_t MOD = 1000000007LL;

int main() {
  int N;
  cin >> N;
  vector<uint64_t> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<vector<int>> num_ones_vec(MAX_NUM_DIGITS, std::vector<int>(N, 0));
  for (int digit = 0; digit < MAX_NUM_DIGITS; digit++) {
    int one_count = 0;
    for (int i = 0; i < N; i++) {
      if (((A[i] >> digit) & 1) == 1) {
        one_count++;
      }
      num_ones_vec[digit][i] = one_count;
    }
  }
  uint64_t ans = 0;
  uint64_t base = 1;
  for (int digit = 0; digit < MAX_NUM_DIGITS; digit++) {
    for (int i = 0; i < N-1; i++) {
      int rest_num_ones = num_ones_vec[digit][N-1] - num_ones_vec[digit][i];
      int rest_num_zeros = N-1-i-rest_num_ones;
      if (((A[i] >> digit) & 1) == 1) {
        ans += (base % MOD) * (rest_num_zeros % MOD);
      } else {
        ans += (base % MOD) * (rest_num_ones % MOD);
      }
      ans %= MOD;
    }
    base *= 2;
  }
  cout << ans << endl;
  return 0;
}
