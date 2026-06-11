#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <numeric>
#include <functional>
#include <stack>
#include <map>

int main (){
	int x, y;

	std::cin >> x >> y;

	int count = 0;

	if (x == 1) {
		count += 300000;
	}

	if (x == 2) {
		count += 200000;
	}

	if (x == 3) {
		count += 100000;
	}

	if (y == 1) {
		count += 300000;
	}

	if (y == 2) {
		count += 200000;
	}

	if (y == 3) {
		count += 100000;
	}


	if (x == 1 && y == 1) {
		count += 400000;
	}

	std::cout << count << std::endl;

	return 0;
}