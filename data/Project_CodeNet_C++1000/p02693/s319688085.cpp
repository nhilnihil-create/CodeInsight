#include <bits/stdc++.h>

int main(void)
{
  int k, a, b;
  std::cin >> k;
  std::cin >> a >> b;

  int range = (b / k) * k;
  if (range >= a) {
    std::cout << "OK" << std::endl;
  }
  else {
    std::cout << "NG" << std::endl;
  }
}