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
	long double a, b, c;

	std::cin >> a >> b >> c;

	if (std::sqrt(a) + std::sqrt(b) + 1.0E-14 < std::sqrt(c)) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}

	return 0;
}
