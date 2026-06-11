#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>

int main(){
  long long S;
  scanf("%lld", &S);
  long long x1, x2, x3, y1, y2, y3;
  x1=0;
  y1=0;
  x2=1e9;
  y2=1;
  if (S<(long long)1e9){
    y3=0;
    x3=S;
  } else if (S==(long long)1e18){
    y3=1e9;
    x3=0;
  } else {
    y3 = S/(long long)1e9 + 1;
    x3 = 1e9-S%(long long)1e9;
  }

  printf("%lld %lld %lld %lld %lld %lld\n", x1, y1, x2, y2, x3, y3);
  //std::cout << abs(x2*y3-x3*y2) << std::endl;
  return 0;
}
