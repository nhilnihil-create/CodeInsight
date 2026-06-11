#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int H, N;
  cin >> H >> N;
  vector<pair<int, int>> magics(N+1);
  for (int n = 1; n <= N; ++n) {
    int A, B;
    cin >> A >> B;
    magics[n] = {A, B};
  }
  sort(magics.begin(), magics.end());

  vector<vector<int>> dp(H+1, vector<int>(N+1, 1000000001));
  for (int h = 1; h <= H; ++h) {
    for (int n = 1; n <= N; ++n) {
      int mp = magics[n].second;
      if (magics[n].first <= h) {
        mp = static_cast<int>(ceil(h / static_cast<float>(magics[n].first))) * magics[n].second;
        mp = min(mp, dp[h-magics[n].first][n] + magics[n].second);
      }
      dp[h][n] = min(mp, dp[h][n-1]);
    }
  }
  cout << dp[H][N] << endl;

  return 0;
}
