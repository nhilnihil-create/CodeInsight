#include <bits/stdc++.h>

int main() {
  int K;
  std::cin >> K;
  std::string s;
  std::cin >> s;
  if (s.size() <= K) std::cout << s << "\n";
  else std::cout << s.substr(0, K) << "...\n";
}
