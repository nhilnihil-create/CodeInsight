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
	long long a, b, c, d, e;

	std::cin >> a >> b >> c >> d >> e;

	long long s_min = a * 60 + b; // 起床時間(分)
	long long e_min = c * 60 + d; // 就寝時間(分)

	std::cout << (e_min - s_min) - e << std::endl;

	return 0;
}
