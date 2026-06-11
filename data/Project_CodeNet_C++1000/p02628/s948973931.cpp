#include <iostream>
#include <set>

int main()
{
  int N, K;
  std::cin >> N >> K;
  std::multiset<int> ps;

  for(int i=0; i<N; i++) {
    int p;
    std::cin >> p;
    ps.insert(p);
  }

  int sum = 0;
  int i = 0;
  for(auto p: ps) {
    sum += p;
    i++;
    if(i == K) {
      break;
    }
  }

  std::cout << sum << std::endl;
  return 0;
}
