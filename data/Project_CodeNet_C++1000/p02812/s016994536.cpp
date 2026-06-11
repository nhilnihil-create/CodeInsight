#include <iostream>

int main()
{
  int N;
  std::string S;
  std::cin >> N >> S;

  size_t i = 0;
  size_t ret = 0;
  while(i <= S.size() - 3) {
    if((S[i] == 'A' && S[i+1]  == 'B' && S[i+2] == 'C')) {
      ret++;
      i += 3;
    } else {
      i++;
    }
  }

  std::cout << ret << std::endl;
  return 0;
}
