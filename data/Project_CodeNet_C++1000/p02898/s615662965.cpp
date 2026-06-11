#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  int n, k;
  std::cin >> n >> k;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int h;
    std::cin >> h;
    if (h >= k)
      ++cnt;
  }
  std::cout << cnt << std::endl;
}
