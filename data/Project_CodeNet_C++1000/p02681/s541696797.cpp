#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

int main() {
  std::string s, t; std::cin >> s >> t;
  t.pop_back();

  printf("%s\n", (s == t ? "Yes" : "No"));
  return 0;
}
