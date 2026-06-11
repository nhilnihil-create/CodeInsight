#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

void solve_test() {
	int n;
	cin >> n;

	vector<int> div(n + 1);
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i)
			div[j]++;

	int total = 0;
	for (int c = 1; c < n; c++)
		total += div[n - c];

	cout << total << '\n';
}

int main() {
	int T;
	T = 1;
	for (int t = 1; t <= T; t++)
		solve_test();

	return 0;
}
