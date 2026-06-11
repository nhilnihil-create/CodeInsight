#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>

int main() {
	long long N, A, B; std::cin >> N >> A >> B;
	if ((B - A) % 2 == 0)
		std::cout << (B - A) / 2 << std::endl;
	else
		std::cout << (std::min(A - 1, N - B) + (B - A - 1) / 2 + 1)<< std::endl;
}
