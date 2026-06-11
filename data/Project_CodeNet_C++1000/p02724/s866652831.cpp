#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <stdio.h>

int main(void){
  int x,out=0;
  std::cin >> x;
  while(x>=500){
    x=x-500;
    out=out+1000;
  }
  while(x>=5){
    x=x-5;
    out=out+5;
  }
  std::cout << out;
  return 0;
}