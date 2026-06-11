#include <bits/stdc++.h>

int main(void)
{
  int s, w;
  std::cin >> s >> w;

  if (w >= s)
    std::cout << "unsafe" << std::endl;
  else
    std::cout << "safe" << std::endl;
}