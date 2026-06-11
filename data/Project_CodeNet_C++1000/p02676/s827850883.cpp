#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int K;  std::cin >> K;
  std::string S;  std::cin >> S;
  if (S.length() <= K)
    std::cout << S << "\n";
  else {
    for (int i = 0; i < K; ++i)
      std::cout << S[i];
    std::cout << "...\n";
  }

  return 0;
}
