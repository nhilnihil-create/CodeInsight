#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>

int main()
{
	int A, B;
	std::cin >> A >> B;
	int C, D;
	std::cin >> C >> D;
	while (true) {
		C -= B;
		if (C <= 0) {
			std::cout << "Yes" << std::endl;
			break;
		}
		A -= D;
		if (A <= 0) {
			std::cout << "No" << std::endl;
			break;
		}
	}
	return 0;
}