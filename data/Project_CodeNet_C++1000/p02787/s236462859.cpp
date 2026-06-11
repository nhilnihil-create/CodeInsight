#include <algorithm>
#include <iostream>
#include <cstdint>
#include <cmath>
#include <vector>
#include <utility>
#include <limits>

using namespace std;

int main() {
  int H, N;
  cin >> H >> N;
  
  vector<pair<int, int>> magics;
  magics.reserve(N + 1);
  magics.push_back(make_pair(0, 0));
  for (size_t n = 0; n < N; ++n) {
    int A, B;
    cin >> A >> B;
    magics.push_back(make_pair(A, B));
  }
  sort(magics.begin(), magics.end(), [] (const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.first < rhs.first;
  });
  vector<vector<int>> dp(H + 1, vector<int>(N + 1, numeric_limits<int>::max()));
  for (int h = 1; h <= H; ++h) {
    for (int n = 1; n <= N; ++n) {
      int m = magics[n].second;
      int a = magics[n].first;
      if (h - a >= 0) {
        int cnt = static_cast<int>(ceil(h / static_cast<float>(a)));
        m = magics[n].second * cnt;
        if (dp[h - a][n] != numeric_limits<int>::max()) {
          m = min(m, dp[h - a][n] + magics[n].second);
        }
      }
      if (n != 1) {
        m = min(m, dp[h][n - 1]);
      }
      dp[h][n] = m;
    }
  }
  cout << dp[H][N] << endl;
  
  return 0;
}
