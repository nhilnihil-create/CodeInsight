// https://atcoder.jp/contests/agc046/virtual

#include <iostream>
#define _ std::ios::sync_with_stdio(false); std::cin.tie(0);

int lcm(int m, int n){
  int a;
  a = (m > n) ? m : n;
  while (true) {
    if (a % m == 0 && a % n == 0)
      return a;
    ++a;
  }
}

int main() { _
  int x;
  std::cin >> x;
  std::cout << lcm(360, x)/x << '\n';
  
  return 0;
}
