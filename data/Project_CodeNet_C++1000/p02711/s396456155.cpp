#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
static const double PI = 3.14159265359;

int main()
{
	std::string N;
	std::cin >> N;
	for (size_t i = 0; i < N.size(); ++i) {
		if (N[i] == '7') {
			std::cout << "Yes" << std::endl;
			return 0;
		}
	}
	std::cout << "No" << std::endl;
	return 0;
}