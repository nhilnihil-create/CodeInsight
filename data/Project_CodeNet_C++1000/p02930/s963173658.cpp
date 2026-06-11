#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) for (int j = i + 1; j <= n; ++j) {
		int x = i ^ j;
		cout << log2(x & -x) + 1 << (j == n ? '\n' : ' ');
	}
	return 0;
}
