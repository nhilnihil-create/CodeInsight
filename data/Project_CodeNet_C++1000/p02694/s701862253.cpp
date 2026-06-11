#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
int main()
{
	int64_t X;
	std::cin >> X;
	uint64_t money = 100;
	uint64_t year = 1;
	while (true) {
		money += money / 100;
		if (money >= X) {
			break;
		}
		else {
			++year;
		}
	}
	std::cout << year << std::endl;
	return 0;
}