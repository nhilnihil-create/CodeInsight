#include <iostream>
#include <string>

int main() {
  std::string S, T; std::cin >> S >> T;
  int ans = 0;
  for (int i = 0; i < S.size(); ++i)
    if (S[i] != T[i])
      ans++;
  std::cout << ans << "\n";

  return 0;
}
