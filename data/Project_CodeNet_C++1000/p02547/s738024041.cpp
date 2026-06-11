#include <iostream>

int N, D[105][3];

int main() {
  std::cin >> N;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < 2; ++j)
      std::cin >> D[i][j];

  bool meron = false;
  for (int i = 0; i < N-2; ++i) {
    bool cor = true;
    for (int j = 0; j < 3; ++j)
      if (D[i+j][0] != D[i+j][1])
        cor = false;
    meron |= cor;
  }
  std::cout << (meron ? "Yes" : "No") << "\n";

  return 0;
}
