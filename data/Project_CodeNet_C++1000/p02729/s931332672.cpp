#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <stdio.h>

int main(void){
  int n,m;
  std::cin >> n >> m;

  std::cout << n*(n-1)/2 + m*(m-1)/2;
  return 0;
}