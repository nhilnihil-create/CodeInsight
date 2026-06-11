#include <iostream>
#include <cstdlib>
#include <climits>

/*
 * http://ttrsq.exblog.jp/24318687/
 */

const int MAX_N = 100;
int DP[MAX_N + 1][MAX_N + 1] = {0};
int *p;

int best(int r, int c) {
  int min = INT_MAX;
  int num = c - r;

  for (int i = 0; i < num; i++) {
    min = std::min(min, DP[r][r + i] + DP[r + i + 1][c] + p[r - 1] * p[r + i] * p[c]);
  }
  
  return min;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n = 0;
  std::cin >> n;
  
  p = (int *) std::malloc(sizeof(int) * n + 1);

  int bb = 0;

  std::cin >> p[0];
  std::cin >> p[1];
  
  for (int i = 2; i <= n; i++) {
    std::cin >> bb;
    std::cin >> p[i];
  }

  if (n == 1) {
    std::cout << "0" << std::endl;

    return 0;
  }  

  for (int i = 1; i < n; i++) {
    DP[i][i + 1] = p[i - 1] * p[i] * p[i + 1];
  }

  for (int j = 0; j <= n - 3; j++) {
    for (int i = j + 3; i <= n; i++) {
      DP[i - 2 - j][i] = best(i - 2 - j, i);
    }
  }

  std::cout << DP[1][n] << std::endl;

  return 0;
}