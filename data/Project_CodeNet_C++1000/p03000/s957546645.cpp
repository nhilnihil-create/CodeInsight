#include <iostream>
#include <vector>

int main()
{
  int N, X;
  std::cin >> N >> X;
  std::vector<int> L(N);
  for(int i=0; i<N; i++) {
    std::cin >> L[i];
  }

  int d = 0;
  int n_bounds = 1; // 0
  for(int i=0; i<N; i++) {
    d += L[i];
    if(d <= X) {
      n_bounds++;
    }
  }

  std::cout << n_bounds << std::endl;
  return 0;
}

