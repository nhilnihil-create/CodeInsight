#include <cstdio>

int main() {
  int factors[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  for (auto i : factors) {
    for (auto j : factors) {
      std::printf("%dx%d=%d\n", i, j, i * j);
    }
  }
  return 0;
}