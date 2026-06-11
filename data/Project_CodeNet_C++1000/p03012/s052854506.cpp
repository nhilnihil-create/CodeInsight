#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	
	int n;
	cin >> n;
	int total = 0;
	int arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i];
	}
	int left = 0;
	int mn = 1e9;
	for(int i = 0; i < n; i++) {
		left += arr[i];
		total -= arr[i];
		if(abs(total - left) < mn) {
			mn = abs(total - left);
		}
	}
	cout << mn;



	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}