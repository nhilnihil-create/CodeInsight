#include <iostream>
#include <vector>
#include <string>
#define input std::cin

using vector = std::vector<int>;
using lint = long long int;
using string = std::string;

int main() {
  int d, t, s; input >> d >> t >> s;
  bool reachable = t * s >= d;
  if (reachable)
	std::cout << "Yes" << std::endl;
  else
	std::cout << "No" << std::endl;
}

