#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i < n; i++)
		ans += (n - 1) / i;
	cout << ans << endl;
	return 0;
}