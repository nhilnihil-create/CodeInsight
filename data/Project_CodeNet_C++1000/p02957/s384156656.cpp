#include<bits/stdc++.h>
int main() {
  int a, b;
  std::cin >> a >> b;
  if((a+b)&1) std::cout << "IMPOSSIBLE" << std::endl;
  else {
    std::cout << (a+b)/2 << std::endl;
  }
}