#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <numeric>

int main() {
	int n, k;

	std::cin >> n >> k;

	if (k != 1) {
		n -= k;
	}
	else {
		n = 0;
	}

	std::cout << n << std::endl;

	return 0;
}