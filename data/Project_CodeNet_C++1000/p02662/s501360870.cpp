#include <iomanip>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, S;
  cin >> N >> S;
  vector<int64_t> A(N);
  rep(i, N) cin >> A[i];

  const int64_t mod = 998244353;
  vector<vector<int64_t>> DP(N + 1, vector<int64_t>(S + 1, 0));
  DP[0][0] = 1;
  rep(i, N) {
    for (int j = S; j >= 0; --j) {
      DP[i + 1][j] += (DP[i][j] * 2L) % mod;
      DP[i + 1][j] %= mod;

      int nj = j + A[i];
      if (nj <= S) {
        DP[i + 1][nj] += (DP[i][j]) % mod;
        DP[i + 1][nj] %= mod;
      }
    }
  }

  cout << DP[N][S] << endl;
  return 0;
}
