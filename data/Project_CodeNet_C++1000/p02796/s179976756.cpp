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
	long long n;

	std::cin >> n;

	long long hani = -10000000000LL;
	long long ans = 0;

	std::vector<std::pair<long long, long long> > v(n);
	for (long long i = 0; i < n; i++)
	{
		long long x, l;

		std::cin >> x >> l;

		v[i] = { x + l, x - l };
	}

	std::sort(v.begin(), v.end());

	for (long long i = 0; i < n; i++)
	{
		long long x = v[i].first, l = v[i].second;

		if (hani <= l) {
			hani = x;
		}
		else {
			ans++;
		}
	}

	std::cout << n - ans << std::endl;

	return 0;
}