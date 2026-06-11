#include <iostream>
#include <string>

int main()
{
  size_t K;
  std::string S;
  std::cin >> K >> S;

  if(S.size() > K) {
    S.resize(K+3);
    S[K] = '.';
    S[K+1] = '.';
    S[K+2] = '.';
  }

  std::cout << S << std::endl;
  return 0;
}
