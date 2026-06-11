#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fix cout << fixed; cout << setprecision(10)





void solve() {

	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	ll sum = 0;
	for(int i = 0; i < n - k; i++) {
		sum += arr[i];

	}
	cout << sum << "\n";
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	solve();

	return 0;
}