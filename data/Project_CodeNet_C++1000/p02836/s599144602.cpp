#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int MOD = 998244353;

void solve_test() {
	string s;
	cin >> s;
	int n = s.length();
	
	int cost = 0;
	for (int i = 0; i < n / 2; i++)
		if (s[i] != s[n - i - 1])
			cost++;
	cout << cost << '\n';
}

int main() {
	int T;
	T = 1;
	for (int t = 1; t <= T; t++)
		solve_test();

	return 0;
}
