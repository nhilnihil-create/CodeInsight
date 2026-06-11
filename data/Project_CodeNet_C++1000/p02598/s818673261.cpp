#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int n, k;

bool check(double arr[], double mid) {
	int cut = 0;
	for (int i = 0; i < n; i++) {
		cut += ceil(arr[i] / mid) - 1;
		if (cut > k)
			return false;
	}
	return true;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	cin >> n >> k;
	double arr[n];
	double left = 0, right = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		right = max(right, arr[i]);
	}
	for (int i = 0; i < 200; i++) {
		double mid = (left + right) * 0.5;
		if (check(arr, mid))
			right = mid;
		else
			left = mid;
	}
	int ans = ceil(right);
	cout << ans;
	return 0;
}
