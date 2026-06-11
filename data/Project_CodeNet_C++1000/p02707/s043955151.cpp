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
	std::vector<int> A;
	for (int i = 0; i < N; ++i) {
		A.push_back(0);
	}
	for (int i = 1; i < N; ++i) {
		int a;
		std::cin >> a;
		A[a - 1] += 1;
	}
	for (int i = 0; i < N; ++i) {
		std::cout << A[i] << std::endl;
	}
	return 0;
}