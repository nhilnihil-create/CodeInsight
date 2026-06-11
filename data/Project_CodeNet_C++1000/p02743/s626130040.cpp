#include <iostream>
#include <vector>

/*
          /a + /b < /c
  a + b + 2 * /ab < c
          2 * /ab < c - a - b
           4 * ab < (c - a - b) ** 2
*/

int main(int argc, char *argv[]) {
  long long a, b, c;
  std::cin >> a >> b >> c;
  long long d = c - a - b;
  if (d <= 0) {
    std::cout << "No" << std::endl;
    return 0;
  }

  if (4 * a * b < d * d)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;
}
