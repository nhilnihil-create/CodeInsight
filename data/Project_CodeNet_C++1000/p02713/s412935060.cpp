#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

int gcd(int p, int q){
  while(q != 0){
  int r = p % q;
  p = q;
  q = r;
  }
  return p;
}


int main(void){
  long long s=0;
  int k;
  std::cin >> k;
  for(int a=1;a<=k;a++){
    for(int b=1;b<=k;b++){
      for(int c=1;c<=k;c++){
        s += gcd(gcd(a,b),c);
      }
    }
  }
  std::cout << s;
  return 0;
}