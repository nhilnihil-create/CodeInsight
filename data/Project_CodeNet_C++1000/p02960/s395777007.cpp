#include <iomanip>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  int N = S.size();

  vector<vector<int64_t>> DP(N + 1, vector<int64_t>(13, 0));
  const int64_t mod = 1e9 + 7;
  if (S[0] == '?') {
    rep(k, 10) DP[0][k] = 1;
  } else {
    DP[0][S[0] - '0'] = 1;
  }

  for (int i = 1; i < N; ++i) {
    if (S[i] == '?') {
      rep(j, 13) {
        rep(k, 10) {
          int mod13 = (j * 10 + k) % 13;
          DP[i][mod13] = (DP[i][mod13] + DP[i - 1][j]) % mod;
        }
      }
    } else {
      rep(j, 13) {
        int mod13 = (j * 10 + (S[i] - '0')) % 13;
        DP[i][mod13] = (DP[i][mod13] + DP[i - 1][j]) % mod;
      }
    }
  }
  cout << DP[N - 1][5] << endl;
  return 0;
}
