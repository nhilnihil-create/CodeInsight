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
	double sum = arr[0];
	for(int i = 1; i < n; i++) {
		sum = (sum + arr[i]) / 2.0;
	}
	cout << sum;
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}