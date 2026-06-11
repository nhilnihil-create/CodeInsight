#include <iostream>
#include <string>

template<class H> void print(H&& head){std::cout << head << std::endl;}

int main()
{
  std::string S, T;
  std::cin >> S >> T;

  int cnt = 0LL;
  for (int i = 0; i < 3; i++) {
    if (S[i] == T[i]) cnt++;
  }

  print(cnt);

  return 0;
}
