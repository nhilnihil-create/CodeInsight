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
	int64_t N, M;
	std::cin >> N >> M;
	int64_t day = 0;
	for (int64_t i = 0; i < M; ++i) {
		int64_t A;
		std::cin >> A;
		day += A;
		if (day > N) {
			std::cout << "-1" << std::endl;
			return 0;
		}
	}
	std::cout << N - day << std::endl;
	return 0;
}