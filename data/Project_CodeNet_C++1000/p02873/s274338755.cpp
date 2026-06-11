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

	long long ans = 0;

	long long count = 0;

	long long left = 0;
	long long right = 0;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (right > 0) {
			right--;
		}
		else {
			long long j = i;
			while (j < s.length() && s[j] == '>') {
				right++;
				j++;
			}
		}
		ans += std::max(left, right);
		if (s[i] == '<') {
			left++;
		}
		else {
			left = 0;
		}
	}

	if (right > 0) right--;

	std::cout << ans + std::max(left, right) << std::endl;

	return 0;
}
