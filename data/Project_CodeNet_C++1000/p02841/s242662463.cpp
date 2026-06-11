#include<iostream>

int main() {
  int M1, D1, M2, D2; std::cin >> M1 >> D1 >> M2 >> D2;
  int ans = (M1==M2)? 0: 1;
  std::cout << ans << std::endl;
  return 0;
}
