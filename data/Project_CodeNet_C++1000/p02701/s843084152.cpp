#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;
	std::set<std::string> S;
	for (int i = 0; i < N; ++i) {
		std::string s;
		std::cin >> s;
		S.insert(s);
	}
	std::cout << S.size() << std::endl;
	return 0;
}