#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include <numeric>
#include <functional>
#include <stack>
#include <iomanip>
#include <map>
#include <cstdio>

int main() {
	std::string s;

	std::cin >> s;

	if (s.length() < 2 || s.length() % 2 == 1) {
		std::cout << "No" << std::endl;
		return 0;
	}
	
	for (size_t i = 0; i < s.length(); i+=2)
	{
		if (s[i] != 'h' || s[i + 1] != 'i') {
			std::cout << "No" << std::endl;
			return 0;
		}
	}
	
	std::cout << "Yes" << std::endl;

	return 0;
}
