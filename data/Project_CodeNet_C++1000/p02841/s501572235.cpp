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

  long long int M1, D1, M2, D2;
  scanf("%lld%lld", &M1, &D1);
  scanf("%lld%lld", &M2, &D2);

  std::cerr << "Answer: " << std::endl;
  if(M1 != M2){
    std::cout << 1 << std::endl;
  }
  else{
    std::cout << 0 << std::endl;
  }

  return 0;
}
