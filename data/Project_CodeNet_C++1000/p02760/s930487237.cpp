#include <bits/stdc++.h>

int main() {
  int A[3][3];
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      std::cin >> A[i][j];
  
  int N; std::cin >> N;
  std::vector<int> b(N);
  for (int i = 0; i < N; ++i) std::cin >> b[i];

  for (int p : b)
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        if (A[i][j] == p) A[i][j] = 0;

  bool ans = false;
  /* 縦 */
  for (int i = 0; i < 3; ++i) {
    if (A[0][i] + A[1][i] + A[2][i] == 0) ans = true;
  }

  /* 横 */
  for (int i = 0; i < 3; ++i) {
    if (A[i][0] + A[i][1] + A[i][2] == 0) ans = true;
  }

  /* 斜め */
  if (A[0][0] + A[1][1] + A[2][2] == 0) ans = true;
  if (A[0][2] + A[1][1] + A[2][0] == 0) ans = true;

  if (ans) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
   
  return 0;

}
