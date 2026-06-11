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

	std::replace(s.begin(), s.end(), '?', 'D');

	std::cout << s << std::endl;

	return 0;
}
