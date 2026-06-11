#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int cnt = 0;
	for(int i = 1; i < n - 1; i++) {
		int mx = max(arr[i], max(arr[i - 1], arr[i + 1]));
		int mn = min(arr[i], min(arr[i - 1], arr[i + 1]));
		if(arr[i] != mx && arr[i] != mn) {
			cnt++;
		}
	}
	cout << cnt;

	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}