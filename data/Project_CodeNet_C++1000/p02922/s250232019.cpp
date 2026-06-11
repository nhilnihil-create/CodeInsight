#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int A, B; std::cin >> A >> B;
	int all = 1;
	int ans = 0;
	while (all < B) {
		--all;
		all += A;
		++ans;
	}
	std::cout << ans << std::endl;
	return 0;
}