#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  std::cin >> k;
  std::string s;
  std::cin >> s;
  if (s.length() <= k) {
    std::cout << s << std::endl;
  }
  else {
    s = s.substr(0,k);
    std::cout << s << "..." << std::endl;
  }
}