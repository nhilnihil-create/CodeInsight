#include <iostream>

int main()
{
  int N, K;
  std::cin >> N >> K;
  int ret = 0;
  for(int i=0; i<N; i++) {
    int h;
    std::cin >> h;
    if(h >= K) ret++;
  }

  std::cout << ret << std::endl;
  return 0;
}
