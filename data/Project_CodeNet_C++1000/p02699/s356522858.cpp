#include <iostream>
#define _USE_MATH_DEFINES
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;

int main()
{
	int S, W;
	std::cin >> S >> W;
	if (W >= S) {
		std::cout << "unsafe";
	}
	else {
		std::cout << "safe";
	}

	return 0;
}

	