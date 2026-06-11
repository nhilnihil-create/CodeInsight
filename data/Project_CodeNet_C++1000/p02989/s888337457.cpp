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
	sort(arr, arr + n);
	cout << max(0, arr[n / 2] - arr[n / 2 - 1]) << "\n";
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}