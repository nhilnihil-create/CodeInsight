#include <iostream>

int main() {
  int a, s; std::cin >> a >> s;
  int sum = 1;
  int cnt = 0;
  while (sum < s) {
    sum += (a-1);
    ++cnt;
  }
  std::cout << cnt << std::endl;
  return 0;
}