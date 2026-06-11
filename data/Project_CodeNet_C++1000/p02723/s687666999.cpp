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
	std::string S;
	std::cin >> S;
	std::cout << (((S[2] == S[3]) && (S[4] == S[5])) ? "Yes" : "No") << std::endl;
	return 0;
}