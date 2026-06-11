#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
int main()
{
	int X;
	std::cin >> X;
	std::cout << (X / 500) * 1000 + (X % 500) / 5 * 5 << std::endl;
	return 0;
}