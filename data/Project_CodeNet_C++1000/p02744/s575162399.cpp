#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

std::vector<std::string> ans;

void rec(std::string str, char max_c, int n) {
	if (str.size() == n) {
		ans.push_back(str);
		return;
	}
	for (char c = 'a'; c <= max_c + 1; ++c) {
		str.push_back(c);
		if (c == max_c + 1) rec(str, max_c + 1, n);
		else rec(str, max_c, n);
		str.pop_back();
	}
}

int main(void) {
	int n;
	std::cin >> n;

	rec("a", 'a', n);

	for (int i = 0; i < ans.size(); ++i) std::cout << ans[i] << std::endl;
	return 0;
}
