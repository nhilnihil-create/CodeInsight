#include <iostream>
#include <map>
#include <string>
#include <algorithm>

int main() {
	int n;
	long long cnt = 0;
	std::cin >> n;
	std::map<std::string, long long> strs;
	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		std::sort(s.begin(), s.end());
		if (strs.find(s) == strs.end()) {
			strs.insert(std::make_pair(s, 1));
		} else {
			cnt += strs.at(s);
			strs.at(s) += 1;
		}
	}
	std::cout << cnt << "\n";
	return 0;
}