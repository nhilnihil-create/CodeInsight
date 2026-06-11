#include <iostream>
#include <string>

char shift(char c, int n)
{
  int order = c - 'A';
  order = (order + n) % 26;
  return (char)(order + 'A');
}

int main()
{
  int N;
  std::string S;
  std::cin >> N;
  std::cin >> S;
  for (int i=0; i<S.length(); i++) S[i] = shift(S[i], N);
  std::cout << S << std::endl;
  return 0;
}
