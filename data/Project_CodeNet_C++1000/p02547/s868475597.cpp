#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

void solve_test() {
	int n;
	cin >> n;
	bool found = false;
	int x = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a == b)
			x++;
		else
			x = 0;
		if (x == 3)
			found = true;
	}

	cout << (found ? "Yes": "No") << '\n';
}

int main() {
	int T;
	T = 1;
	for (int t = 1; t <= T; t++)
		solve_test();

	return 0;
}
