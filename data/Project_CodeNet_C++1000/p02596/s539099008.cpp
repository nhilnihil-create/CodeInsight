#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	int k;
	cin >> k;
	int n = 7 % k;
	for (int i = 1; i <= k; i++) {
		if (n == 0) {
			cout << i;
			return 0;
		}
		n = (n * 10 + 7) % k;
	}
	cout << -1;
	return 0;
}