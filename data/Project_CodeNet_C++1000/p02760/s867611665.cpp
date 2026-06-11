#include <iostream>
#include <algorithm>

int main()
{
	int a[9];
	for (auto &e : a) std::cin >> e;
	int n;
	std::cin >> n;
	int b;
	for (int i = 0; i < n; i++) {
		std::cin >> b;
		auto p = std::find(a, a + 9, b);
		if (p != a + 9) *p = 0;
	}
	
	for (int i = 0; i < 9; i += 3) {
		if ((a[i] | a[i + 1] | a[i + 2]) == 0) {
			goto BINGO;
		}
	}
	for (int i = 0; i < 3; i++) {
		if ((a[i] | a[i + 3] | a[i + 6]) == 0) {
			goto BINGO;
		}
	}
	if ((a[0] | a[4] | a[8]) == 0) {
		goto BINGO;
	}
	if ((a[2] | a[4] | a[6]) == 0) {
		goto BINGO;
	}
	std::cout << "No" << std::endl;
	return 0;
	
BINGO:
	std::cout << "Yes" << std::endl;
	return 0;
}
