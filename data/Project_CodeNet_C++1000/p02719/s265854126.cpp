#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <stdio.h>

int main(void){
  long long n,k;
  std::cin >> n >> k;
  (n%k<k-n%k)?std::cout<< n%k:std::cout<< k-n%k;
  return 0;
}