#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int main()
{
  int N, L;
  std::cin >> N >> L;
  std::vector<int> w(N);
  std::vector<int> diff(N);

  int sum = 0;
  for(int i=0; i<N; i++) {
    w[i] = L + i;
    sum += w[i];
  }
  for(int i=0; i<N; i++) {
    diff[i] = std::abs(sum - (sum - w[i]));
  }
  auto it = std::min_element(diff.begin(), diff.end());

  std::cout << sum - w[it-diff.begin()] << std::endl;


  return 0;
}
