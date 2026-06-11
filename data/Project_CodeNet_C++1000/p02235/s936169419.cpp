#include<iostream>
#include<string>
#include<algorithm>

#define N 1000

int lcs(std::string x, std::string y) {
	int c[N + 1][N + 1];
	int m = x.size();
	int n = y.size();
	int maxl = 0;

	x = ' ' + x;
	y = ' ' + y;
	for (int i = 0; i <= m; i++) c[i][0] = 0;
	for (int i = 0; i <= m; i++) c[0][i] = 0;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i] == y[j]) c[i][j] = c[i - 1][j - 1] + 1;
			else c[i][j] = std::max(c[i - 1][j], c[i][j - 1]);
			maxl = std::max(maxl, c[i][j]);
		}
	}
	return maxl;
}

int main() {
	std::string s1, s2;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> s1 >> s2;
		std::cout << lcs(s1, s2) << std::endl;
	}
	return 0;
}