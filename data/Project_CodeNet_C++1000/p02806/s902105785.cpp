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

	std::vector<std::pair<std::string, long long> > v(n);
	
	for (long long i = 0; i < n; i++)
	{
		long long a;
		std::string s;

		std::cin >> s >> a;
		v[i] = { s, a };
	}

	std::string s;
	std::cin >> s;

	bool flag = false;
	long long ans = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (flag) {
			ans += v[i].second;
		}
		if (v[i].first == s) {
			flag = true;
		}
	}

	std::cout << ans << std::endl;

	return 0;
}