#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <array>

const uint32_t D = 365 + 1;
const uint32_t contests = 26 + 1;

int main() {
  {
    uint32_t Dtmp = 0;
    std::cin >> Dtmp;
  }

  std::array<uint32_t, contests> cost;
  for (size_t c = 1; c < contests; c++) std::cin >> cost[c];
  
  std::array<std::array<uint32_t, contests>, D> sat;
  for (size_t d = 1; d < D; d++) for (size_t c = 1; c < contests; c++) std::cin >> sat[d][c];
  
  // solve problem
  std::array<uint32_t, D> test;
  for (size_t d = 1; d < D; d++) std::cin >> test[d];

  // calc satisfaction
  std::array<int64_t, D> value;
  value[0] = 0;
  std::array<uint32_t, contests> last;
  last.fill(0);
  for (size_t d = 1; d < D; d++)
  {
    value[d] = value[d-1] + sat[d][test[d]];
    last[test[d]] = d;

    int64_t c_sum = 0;
    for (size_t c = 0; c < contests; c++) c_sum += cost[c]*(d-last[c]);    
    value[d] -= c_sum;
  }

  for(size_t d = 1; d < D; d++) std::cout << value[d] << std::endl;
  

  return 0;
}