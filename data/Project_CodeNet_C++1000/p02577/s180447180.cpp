#include <iostream>
#include <string>

std::string S;

int main() {
  std::cin >> S;
  int sum = 0;
  for (int i = 0; i < S.size(); ++i)
    sum += (S[i] - '0');
  std::cout << (sum % 9 == 0 ? "Yes" : "No") << "\n";

  return 0;
}
