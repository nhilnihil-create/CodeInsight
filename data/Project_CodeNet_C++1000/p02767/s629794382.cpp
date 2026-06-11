#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

int main()
{
  int N;
  std::cin >> N;
  std::vector<int> X(N);
  for(int i=0; i<N; i++) {
    std::cin >> X[i];
  }

  // argmin in real number
  float sum = std::accumulate(X.begin(), X.end(), 0);
  float argmin_f = sum / N;
  int c = std::floor(argmin_f);
  int argmin = argmin_f - c < c + 1 - argmin_f ? c : c+1;

  int min = 0;
  for(auto x : X) {
    min += (x - argmin) * (x - argmin);
  }

  std::cout << min << std::endl;

  return 0;
}
