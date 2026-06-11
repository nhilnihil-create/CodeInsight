#include <bits/stdc++.h>

int main(void)
{
  int n;
  std::cin >> n;

  bool flag = false;

  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      if (i*j == n) {
        flag =true;
        break;
      }
    }
  }

  if (flag) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }
}