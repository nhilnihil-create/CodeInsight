#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a;
	cin >> n;

	vector<int> ans(n+1, 0);
	for (int i = 1; i < n; i++) {
		cin >> a;
		ans[a]++;
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}
}