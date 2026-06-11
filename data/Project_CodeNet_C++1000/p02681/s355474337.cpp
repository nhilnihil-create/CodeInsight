#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <map>
#include <queue>
#define _PI (3.141592653589793)
int main()
{
	std::string S, T;
	std::cin >> S >> T;
	T.resize(T.size() - 1);
	if (T == S) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}
	return 0;
}