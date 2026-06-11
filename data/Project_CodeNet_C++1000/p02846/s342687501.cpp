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
  long long int T1, T2, A1, A2, B1, B2, tmp;
  scanf("%lld%lld", &T1, &T2);
  scanf("%lld%lld", &A1, &A2);
  scanf("%lld%lld", &B1, &B2);

  long long int Dt1=0, Dt2=0, ans=0;
  Dt1 = A1*T1 - B1*T1;
  Dt2 = Dt1 + A2*T2 - B2*T2;

  // do not meet
  if((Dt1>0 && Dt2 > 0) || (Dt1 < 0 && Dt2<0)){
    std::cerr << "Answer: do not meet" << std::endl;
    std::cout << 0 << std::endl;
  }
  // meet infinite times
  else if(Dt2 == 0){
    std::cerr << "Answer: meet infinite times" << std::endl;
    std::cout << "infinity";
  }
  // meet finite times
  else{
    Dt1 = std::abs(Dt1);
    Dt2 = std::abs(Dt2);

    tmp = Dt1/Dt2;
    if((Dt1%Dt2) == 0){
      ans = 2*tmp;
    }
    else{
      ans = 2*tmp+1;
    }

    std::cerr << "Answer: meet finite times" << std::endl;
    std::cout << ans << std::endl;
  }

  return 0;
  
}
