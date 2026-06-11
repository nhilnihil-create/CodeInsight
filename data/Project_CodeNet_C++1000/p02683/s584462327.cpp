#include <iostream>
#include <vector>

int main() {
  int N, M, X;
  std::cin >> N >> M >> X;

  std::vector<int> C(N);
  std::vector<std::vector<int>> A(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> C[i];
    A[i].resize(M);
    for (int j = 0; j < M; ++j) {
      std::cin >> A[i][j];
    }
  }

  bool res = false;
  int resCost = 1 << 30;
  for (int k = 0; k < (1 << N); ++k) {
    std::vector<int> bit(N, 0);
    for (int i = 0; i < N; ++i)
      if (k & (1 << i))
        bit[i] = 1;

    std::vector<long long> val(M, 0LL);
    int cost = 0;
    for (int i = 0; i < N; ++i) {
      if (bit[i] == 0)
        continue;
      cost += C[i];

      for (int j = 0; j < M; ++j)
        val[j] += A[i][j];
    }

    bool ok = true;
    for (int j = 0; j < M; ++j) {
      if (val[j] < X) {
        ok = false;
        break;
      }
    }

    if (ok) {
      res = true;
      if (cost < resCost)
        resCost = cost;
    }
  }

  if (!res)
    std::cout << "-1" << std::endl;
  else
    std::cout << resCost << std::endl;
}
