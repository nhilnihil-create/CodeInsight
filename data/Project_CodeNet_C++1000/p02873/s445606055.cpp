#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

intt func(intt n) {
	intt r = 0;
	while (n > 0) {
		r += n;
		--n;
	}
	return r;
}

int main() {
	std::string s; std::cin >> s;
	intt N = s.size();
	intt ans = 0;
	std::vector<intt> L(N + 1), R(N + 1);
	for (intt i = 0; i < N; ++i)
		if (s[i] == '<')
			L[i + 1] = L[i] + 1;
	for (intt i = N - 1; i >= 0; --i)
		if (s[i] == '>')
			R[i] = R[i + 1] + 1;
	for (intt i = 0; i < N + 1; ++i)
		ans += std::max(L[i], R[i]);
	std::cout << ans << std::endl;
}