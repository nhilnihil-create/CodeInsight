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
  long long int X,Y;
  scanf("%lld%lld", &X, &Y);
  long long int ans = 0;
  if(X == 3){
    ans += 100000;
  }
  else if(X == 2){
    ans += 200000;
  }
  else if(X == 1){
    ans += 300000;
  }

  if(Y == 3){
    ans += 100000;
  }
  else if(Y == 2){
    ans += 200000;
  }
  else if(Y == 1){
    ans += 300000;
  }

  if(X == Y && X == 1){
    ans += 400000;
  }

  std::cerr << "Answer: " << std::endl;
  std::cout << ans << std::endl;

  return 0;
}
