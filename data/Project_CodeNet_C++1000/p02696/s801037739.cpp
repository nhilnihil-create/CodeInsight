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
	long long a, b, n;

	std::cin >> a >> b >> n;

	long long c = std::min(b - 1, n);

	std::cout << a * c / b - a * (c / b) << std::endl;

	return 0;
}
