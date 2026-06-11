#include <iostream>
#include <string>

int main()
{
  int N;
  std::string S;
  std::cin >> N;
  std::cin >> S;
  int cnt = 0;
  int mode = 0;
  for (int i=0; i<N; i++) {
    switch (mode) {
      case 0:
        if (S[i] == 'A') mode = 1;
        break;
      case 1:
        if (S[i] == 'B') mode = 2;
        else if (S[i] != 'A') mode = 0;
        break;
      case 2:
        if (S[i] == 'A') mode = 1;
        else {
          if (S[i] == 'C') cnt++;
          mode = 0;
        }
        break;
    }
  }
  std::cout << cnt << std::endl;
  return 0;
}
