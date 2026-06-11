#include <iostream>

signed main() {
  int s, w;
  std::cin >> s >> w;

  if(w >= s)
    std::cout << "unsafe";
  else
    std::cout << "safe";

  std::cout << std::endl;
  return 0;
}

