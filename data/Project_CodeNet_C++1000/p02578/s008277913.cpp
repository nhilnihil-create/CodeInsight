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

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int curr_max = arr[0], res = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] < curr_max)
			res += curr_max - arr[i];
		curr_max = max(curr_max, arr[i]);
	}
	cout << res;
	return 0;
}
