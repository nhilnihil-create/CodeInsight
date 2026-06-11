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
  long long int N, K, tmp;
  scanf("%lld%lld", &N, &K);
  std::vector<long long int> A;
  for(long long int i = 0; i < N; i++){
    scanf("%lld", &tmp);
    A.push_back(tmp-1);
  }

  // solve problem
  long long int internal_flip = 0;
  std::vector<long long int> count(2000);
  for(long long int i = 0; i < N; i++){
    count[A[i]]++;
    for(long long int j = A[i]+1; j < 2000; j++){
      internal_flip += count[j];
      internal_flip = (internal_flip+MOD)%MOD;
    }
  }

  long long int external_flip = 0;
  for(long long int i = 1998; i >= 0; i--){
    external_flip += count[i]*count[i+1];
    external_flip = (external_flip+MOD)%MOD;
    count[i] = count[i]+count[i+1];
  }

  long long int KC2 = (K*(K-1))/2;
  KC2 = (KC2+MOD)%MOD;

  long long int ans;
  ans = (K*internal_flip+MOD)%MOD;
  ans = (ans + ((KC2*external_flip+MOD)%MOD) + MOD)%MOD;

  std::cerr << "Answer: " << std::endl;
  std::cout << ans << std::endl;
  

  return 0;
}