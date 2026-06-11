#include <algorithm>
#include <iostream>
#include <vector>

namespace {

int combination(int a, int b, int c, int d)
{
  // (a,a,a,a)
  if (a == d) {
    return 1;
  }
  // (a,a,a,d) or (a,b,b,b)
  else if (a == c || b == d) {
    return 4;
  }
  // (a,a,c,c)
  else if (a == b && c == d) {
    return 6;
  }
  // (a,a,c,d) or (a,b,b,d) or (a,b,c,c)
  else if (a == b || b == c || c == d) {
    return 12;
  }
  // (a,b,c,d)
  else {
    return 24;
  }
}

int calc(int n)
{
  int com = 0;
  int a, b, c, d;

  for (a = 0; a <= 9; ++a) {
    if (a > n) break;
    for (b = a; b <= 9; ++b) {
      if (a + b > n) break;
      for (c = b; c <= 9; ++c) {
        if (a + b + c > n) break;
        for (d = c; d <= 9; ++d) {
          const int sum = a + b + c + d;
          if (sum == n) {
            com += combination(a, b, c, d);
          }
          else if (sum > n) {
            break;
          }
        }
      }
    }
  }

  return com;
}

} // unnamed namespace

int main()
{
  int n;
  while (std::cin >> n) {
    std::cout << calc(n) << std::endl;
  }

  return 0;
}