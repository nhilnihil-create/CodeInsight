#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int gcd(int arr[]) {
	int res = arr[0];
	for (int i = 1; i < 3; i++) res = __gcd(res, arr[i]);
	return res;
}

int main() {
	int k; cin >> k;
	int res = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			for (int h = 1; h <= k; h++) {
				int arr[3] = {i, j, h};
				res += gcd(arr);
			}
		}
	}
	cout << res;
	return 0;
}