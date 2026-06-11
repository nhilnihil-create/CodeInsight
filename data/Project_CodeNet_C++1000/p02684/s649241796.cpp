#include <iostream>
#include <vector>

int main() {
  int N;
  long long K;
  std::cin >> N >> K;

  std::vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
    A[i] -= 1;
  }

  int x = 0; // 交差する点までの長さ
  int y = 0; // ループの長さ
  int cross = -1;

  {
    std::vector<int> c(N, 0);

    int k = 0;
    c[k] += 1;
    while (c[k] <= 1) {
      k = A[k];
      c[k] += 1;
    }
    // <= ここで k は交差する点
    cross = k;

    int l = 0;
    while (l != k) {
      l = A[l];
      x += 1;
    }
    // <= ここで l == k
    l = A[l];
    y += 1;
    while (l != k) {
      l = A[l];
      y += 1;
    }
  }
  // std::cout << "x: " << x << std::endl;
  // std::cout << "y: " << y << std::endl;

  if (K <= x) {
    // ループには入らない
    int k = 0;
    for (int i = 0; i < K; ++i)
      k = A[k];
    std::cout << k + 1 << std::endl;
  } else {
    // ループに入る
    K -= x;
    K %= y;

    int k = cross;
    for (int i = 0; i < K; ++i)
      k = A[k];
    std::cout << k + 1 << std::endl;
  }
}
