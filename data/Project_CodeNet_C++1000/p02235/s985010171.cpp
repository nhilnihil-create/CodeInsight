#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
static const int num = 1001;
int lcs(string ch1, string ch2) {
	int s = ch1.size();
	int t = ch2.size();
	ch1.insert(0, " ");
	ch2.insert(0, " ");
	int c[num][num];
	for (int i = 0; i <= s; i++) c[i][0] = 0;
	for (int i = 0; i <= t; i++) c[0][i] = 0;
	for (int i = 1; i <= s; i++) {
		for (int j = 1; j <= t; j++) {
			if (ch1[i] == ch2[j]) c[i][j] = c[i - 1][j - 1] + 1;
			else c[i][j] = max(c[i - 1][j], c[i][j - 1]);
		}
	}
	return c[s][t];
}
int main() {
	int q;
	cin >> q;
	string a, b;
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		cout << lcs(a, b) << endl;
	}
	return 0;
}