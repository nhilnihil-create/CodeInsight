#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int MOD = 998244353;

void solve_test() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b + c >= 22) {
		cout << "bust\n";
		return;
	}
	cout << "win\n";
}

int main() {
	int T;
	T = 1;
	for (int t = 1; t <= T; t++)
		solve_test();

	return 0;
}
