#include <bits/stdc++.h>
int main() {
  std::string S, T;
  std::cin >> S >> T;
  std::cout << (S[0] == T[0]) + (S[1] == T[1]) + (S[2] == T[2]) << std::endl;
  return 0;
}