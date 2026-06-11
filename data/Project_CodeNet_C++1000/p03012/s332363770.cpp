#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  int N ;
  std::cin >> N;
  std::vector<int> W(N);
  std::vector<int> diff(N);
  for(int i=0; i<N; i++) {
    std::cin >> W[i];
  }

  for(int t=0; t<N; t++) {
    for(int i=0; i<=t; i++) {
      diff[t] += W[i];
    }
    for(int i=t+1; i<N; i++) {
      diff[t] -= W[i];
    }
    if(diff[t] < 0) {
      diff[t] *= -1;
    }
  }

  std::cout << *std::min_element(diff.begin(), diff.end()) << std::endl;

  return 0;
}
