#include <iostream>
#include <string>

int main()
{
  std::string S, T;
  std::cin >> S;
  std::cin >> T;
  int cnt = 0;
  for (int i=0; i<3; i++) cnt += (S[i] == T[i]) ? 1 : 0;
  std::cout << cnt << std::endl;
  return 0;
}