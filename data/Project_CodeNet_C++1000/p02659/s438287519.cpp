#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int MOD = 998244353;

int to_int(string s) {
	int result = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '.')
			continue;
		result = result * 10 + (s[i] - '0');
	}
	return result;
}

void solve_test() {
	LL a;
	string b;
	cin >> a >> b;
	int B = to_int(b);

	cout << a * B / 100 << '\n';
}

int main() {
	int T;
	T = 1;
	for (int t = 1; t <= T; t++)
		solve_test();

	return 0;
}
