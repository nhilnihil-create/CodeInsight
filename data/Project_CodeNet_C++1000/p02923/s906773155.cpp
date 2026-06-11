#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	int n;
	cin >> n;
	int arr[n];	
	int cnt = 0;
	int mx = 0;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for(int i = 1; i < n; i++) {
		if(arr[i] <= arr[i - 1]) {
			cnt++;
		}
		else {
			mx = max(mx, cnt);
			cnt = 0;
		}
	}
	mx = max(mx, cnt);
	cout << mx << "\n";
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}