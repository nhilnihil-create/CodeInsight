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
	for(int i = 1; i < n; i++) {
		if(arr[i - 1] > arr[i]) {
			arr[i]++;
			if(arr[i - 1] > arr[i]) {
				cout << "No";
				return;
			}
		}
	}
	cout << "Yes";

	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}