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
	int sortedArr[n]; 
	copy(arr, arr + n, sortedArr);
	partial_sort(sortedArr, sortedArr + 2, sortedArr + n, greater<int>());
	for(int i = 0; i < n; i++) {
		if(arr[i] == sortedArr[0]) {
			cout << sortedArr[1] << "\n";
		}
		else {
			cout << sortedArr[0] << "\n";
		}
	}

	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}