#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 15;
int matrix[MAX_N][MAX_N];

int main() {
  fill_n(&matrix[0][0], MAX_N * MAX_N, -1);
  int N;
  cin >> N;
  for (int i{}; i < N; ++i) {
    int A;
    cin >> A;
    for (int j{}; j < A; ++j) {
      int x, y;
      cin >> x >> y;
      --x;
      matrix[i][x] = y;
    }
  }

  int ans{};
  for (int i{1}; i < (1 << N); ++i) {
    int num{};
    bool lier{};
    for (int j{}; j < N; ++j) {
      if (i & (1 << j)) {
        for (int k{}; k < N; ++k) {
          if (matrix[j][k] == -1) continue;
          if ((matrix[j][k] && !(i & (1 << k))) ||
              (!matrix[j][k] && (i & (1 << k)))) {
            lier = true;
            break;
          }
        }
        if (lier) break;
        ++num;
      }
    }
    if (!lier)
      ans = max(ans, num);
  }

  cout << ans << endl;
  return 0;
}
