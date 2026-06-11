#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <stdio.h>

int main(void){
  long long h,w;
  std::cin >> h >> w;
  
  if(h==1||w==1) std::cout << "1";
  else std::cout << (h*w+1)/2;
  return 0;
}