#include <iostream>
#include <algorithm>

int main()
{
  char S[5];
  for (int i=0; i<4; i++) std::cin >> S[i];
  std::sort(S, S+4);
  if (S[0]==S[1] && S[1] != S[2] && S[2] == S[3]) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}
