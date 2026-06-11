#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>

int main(void)
{
  while (true) {
    int n;
    std::cin >> n;
    if (n == 0) break;

    std::map<char, char> table;
    for (int i = 0; i < n; i++) {
      char c1, c2;
      std::cin >> c1 >> c2;
      table[c1] = c2;
    }

    int m;
    std::cin >> m;
    std::string str;
    for (int i = 0; i < m; i++) {
      char c;
      std::cin >> c;
      if (table.count(c) > 0) c = table[c];
      str.push_back(c);
    }

    std::cout << str << std::endl;
  }

  return 0;
}