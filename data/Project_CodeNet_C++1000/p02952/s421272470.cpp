#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (to_string(i).size() % 2 != 0) ans++;
	}
	cout << ans << '\n';
	return 0;
}