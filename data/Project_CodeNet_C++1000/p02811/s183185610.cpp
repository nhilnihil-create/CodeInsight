#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>
int main()
{
	int K, X;
	std::cin >> K >> X;
	if (K * 500 >= X) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}
	return 0;
}