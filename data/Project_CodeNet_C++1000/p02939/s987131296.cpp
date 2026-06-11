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
	char pre = '\0';

	for (long long  i = 0; i < s.length(); i++)
	{
		if (pre == '\0' || s[i] != pre) {
			pre = s[i];
			ans++;
		}
		else {
			if (i + 1 < s.length()) {
				i++;
				ans++;
				pre = '\0';
			}
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
