#include <bits/stdc++.h>

int main() {
  long long a, b, c;
  long long d;
  std::cin >> a >> b >> c;
  d = c - a - b;
  if (d > 0 && 4*a*b < d*d) std::cout << "Yes";
  else std::cout << "No";
  
  return 0;
}