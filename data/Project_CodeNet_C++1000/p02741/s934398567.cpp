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
  int k;
  std::cin >> k;
  std::vector<int> out = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  std::cout << out.at(k-1);
  return 0;
}