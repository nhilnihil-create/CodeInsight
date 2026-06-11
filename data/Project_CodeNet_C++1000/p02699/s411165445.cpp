#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>

int main()
{
	int S, W;
	std::cin >> S >> W;
	std::cout << ((W >= S) ? "unsafe" : "safe") << std::endl;
	return 0;
}