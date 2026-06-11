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

long long int MOD = 1e9+7;

int main(){

  // read problem
  long long int N, tmp;
  std::vector<long long int> A;

  scanf("%lld", &N);
  for(long long int i = 0; i < N; i++){
    scanf("%lld", &tmp);
    A.push_back(tmp);
  }

  // solve problem
  std::vector<long long int> tmp_state(N);
  tmp_state[0] = 3;
  long long int ans = 1;
  for(long long int i = 0; i < N; i++){
    if(tmp_state[A[i]] > 0){
      // update answer
      ans *= tmp_state[A[i]];
      ans = (ans + MOD)%MOD;
      // update state
      tmp_state[A[i]]--;
      tmp_state[A[i]+1]++;
    }
    else{
      ans = 0;
      break;
    }
  }

  std::cerr << "Answer: " << std::endl;
  std::cout << ans << std::endl;

  return 0;
}
