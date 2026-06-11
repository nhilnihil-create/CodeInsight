#include <iostream>

int main(int argc, char *argv[]) {
  char c;
  int i = 1;
  bool ok = true;
  while (std::cin >> c) {
    if (i % 2 == 0) {
      if (c == 'R')
        ok = false;
    } else if (c == 'L')
      ok = false;
    ++i;
  }

  std::cout << (ok ? "Yes" : "No") << std::endl;
}
