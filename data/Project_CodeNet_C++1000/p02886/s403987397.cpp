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
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			sum += arr[i] * arr[j];
		}
	}
	cout << sum << "\n";

	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}