#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	cout << accumulate(arr.begin(), arr.begin()+k, 0);
}