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
	long long a, b, m;

	std::cin >> a >> b >> m;

	std::vector<long long> va(a), vb(b);

	for (long long i = 0; i < a; i++)
	{
		std::cin >> va[i];
	}

	for (long long i = 0; i < b; i++)
	{
		std::cin >> vb[i];
	}

	long long min = *std::min_element(va.begin(), va.end()) + *std::min_element(vb.begin(), vb.end());

	for (long long i = 0; i < m; i++)
	{
		long long x, y, z;

		std::cin >> x >> y >> z;
		x--; y--;

		min = std::min(min, va[x] + vb[y] - z);
	}

	std::cout << min << std::endl;

	return 0;
}