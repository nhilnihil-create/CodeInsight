#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <complex>

int main(){
  long long int N, tmp;
  std::vector<long long int> A, A_cum;
  A_cum.push_back(0);

  scanf("%lld", &N);
  for(long long int i = 0; i < N; i++){
    scanf("%lld", &tmp);
    A.push_back(tmp);
    A_cum.push_back(A_cum[i]+tmp);
  }

  long long int ans = 1e18;
  for(long long int i = 0; i < N; i++){
    ans = std::min(ans, std::abs(A_cum[N]- 2*A_cum[i]));
  }

  std::cerr << "A_cum: " << std::endl;
  for(long long int i = 0; i <= N; i++){
    std::cerr << A_cum[i] << std::endl;
  }

  std::cerr << "Answer: " << std::endl;
  std::cout << ans << std::endl;

  return 0;
}
