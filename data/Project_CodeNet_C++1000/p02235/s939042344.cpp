#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int lcs(string x, string y) {
	static int c[1001][1001];
	int m = x.size();
	int n = y.size();
	int max1 = 0;
	x = ' ' + x;
	y = ' ' + y;
	for (int i = 0; i <= m; i++)c[i][0] = 0;
	for (int j = 1; j <= n; j++)c[0][j] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i] == y[j])c[i][j] = c[i - 1][j - 1] + 1;
			else c[i][j] = max(c[i - 1][j], c[i][j - 1]);
			max1 = max(max1, c[i][j]);

		}
	}
	return max1;
}

int main() {
	string s1, s2;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2;
		cout << lcs(s1, s2) << endl;
	}
	return 0;
}