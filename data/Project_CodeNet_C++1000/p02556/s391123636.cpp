#include <iostream>
#include <vector>
#include <string>
#include <climits>
#define input std::cin

using vector = std::vector<int>;
using lint = long long int;
using string = std::string;

int main() {
  int n; input >> n;
  int max_sum = INT_MIN, min_sum = INT_MAX;
  int max_dif = INT_MIN, min_dif = INT_MAX;
  for (int i=0; i<n; i++) {
	int x,y; input >> x >> y;
	int sum = x + y;
	int dif = x - y;
	if (sum > max_sum)
	  max_sum = sum;
	if (sum < min_sum)
	  min_sum = sum;
	if (dif > max_dif)
	  max_dif = dif;
	if (dif < min_dif)
	  min_dif = dif;
  }
  std::cout << std::max(max_sum-min_sum, max_dif-min_dif) << std::endl;
}

