#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
static const double PI = 3.14159265359;

int main()
{
	int N;
	std::cin >> N;
	int64_t sum = 0;
	for (int i = 1; i <= N; ++i) {
		if ((i % 3 != 0) && (i % 5 != 0)) {
			sum += i;
		}
	}
	std::cout << sum << std::endl;
	return 0;
}