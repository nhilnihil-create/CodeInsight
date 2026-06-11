#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	vector<long long> arr(n);
	long long sm = 0;
	for (int i=0; i<n; i++) {
		cin >> arr[i];
		sm ^= arr[i];
	}
	for (int i=0; i<n; i++) {
		cout << (sm^arr[i]);
		cout << " ";
	}
}
