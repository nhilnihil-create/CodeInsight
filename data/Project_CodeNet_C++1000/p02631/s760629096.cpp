#include <iostream>

int N, B[200005];

int main() {
  std::cin >> N;
  int S = 0;
  for (int i = 0; i < N; ++i) {
    std::cin >> B[i];
    S ^= B[i];
  }

  for (int i = 0; i < N; ++i)
    std::cout << (S ^ B[i]) << " ";
  std::cout << "\n";

  return 0;
}
