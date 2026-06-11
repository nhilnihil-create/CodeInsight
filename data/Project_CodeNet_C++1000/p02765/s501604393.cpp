#include <iostream>

int main()
{
  int N, R;
  std::cin >> N >> R;

  int S; // internal rating
  if(10 < N) {
    S = R;
  } else {
    S = R + 100*(10-N);
  }

  std::cout << S << std::endl;
  return 0;
}
