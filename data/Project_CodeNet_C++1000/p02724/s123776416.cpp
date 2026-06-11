#include <bits/stdc++.h>

int main() {
  int m;
  int c_500, c_5;
  
  std::cin >> m;
  c_500 = m / 500;
  m -= c_500*500;
  c_5 = m / 5;

  int p = c_500*1000 + c_5*5;

  std::cout << p;

}