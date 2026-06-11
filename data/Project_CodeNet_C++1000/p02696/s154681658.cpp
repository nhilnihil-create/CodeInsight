#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>

int main()
{
	int64_t A, B, N;
	std::cin >> A >> B >> N;
	if (N < B) {
		std::cout << A * N / B << std::endl;
	}
	else{
		int64_t x = B-1;
		std::cout << (A * x) / B - A * (x / B) << std::endl;
	}
	return 0;
}