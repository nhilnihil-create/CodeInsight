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

int main() {
	long long h, w, n;

	std::cin >> h >> w >> n;

	std::cout << int(std::ceil(1.0 * n / std::max(h, w))) << std::endl;

	return 0;
}
