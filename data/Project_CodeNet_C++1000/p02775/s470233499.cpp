#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


const int INF = 1e10;


int main() {
	string s;
	cin >> s;

	int D = s.length();

	vector<int> N(D);
	for (int i = 0; i < D; ++i) N[i] = s[D - i - 1] - '0'; // 下位桁から順に格納

	vector<int> M(D);
	int carry = 0;
	for (int i = 0; i < D; ++i) {
		M[i] = 10 - carry - N[i];
		carry = 1 - M[i] / 10;
		M[i] %= 10;
	}

	vector<int> dp0(D + 1, INF), dp1(D + 1, INF); // dp0が表、dp1が裏
	dp0[0] = dp1[0] = 0;

	for (int i = 1; i <= D; ++i) {
		int a = N[i - 1], b = M[i - 1];
		dp0[i] = min(a + dp0[i - 1], 1 + b + dp1[i - 1]);
		if (b + 1 < 10) dp0[i] = min(dp0[i], 2 + b + dp0[i - 1]);
		dp1[i] = min(b + dp1[i - 1], 1 + a + dp0[i - 1]);
		if (a + 1 < 10) dp1[i] = min(dp1[i], 2 + a + dp1[i - 1]);
	}

	cout << dp0[D] << endl;

	return 0;
}