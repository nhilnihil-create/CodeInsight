#include <iostream>

long distance(long x, long y) { return x * x + y * y; }

int main(int argc, char *argv[]) {
  long n, d;
  std::cin >> n >> d;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    if (distance(x, y) <= d * d)
      cnt++;
  }
  std::cout << cnt << std::endl;
}
