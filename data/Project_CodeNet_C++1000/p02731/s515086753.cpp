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
  int l;
  std::cin >> l;
  std::cout << std::setprecision(32) << (double)l*l*l/27;
  return 0;
}