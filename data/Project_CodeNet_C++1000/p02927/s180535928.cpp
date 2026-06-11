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
  
  long long int M, D;
  scanf("%lld%lld", &M, &D);

  long long int ans = 0;
  for(long long int i = 20; i <= D; i++){
    if((i+10)%10 >= 2 && (i/10)*(i%10) <= M){
      ans++;
    }
  }

  std::cerr << "Answer: " << std::endl;
  std::cout << ans << std::endl;

  return 0;
}