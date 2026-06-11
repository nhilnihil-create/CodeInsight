#include <iostream>

int main()
{
  int N;
  std::cin >> N;
  bool flg = false;
  for (int i=1; i<=9; i++) {
    int M = N/i;
    if (M*i==N && 1 <= M && M <= 9) {
      flg = true; break;
    }
  }
  if (flg) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}