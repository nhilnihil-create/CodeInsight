#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a[n][n];
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			for(int k = 0; k < 30; ++k) {
				if((i >> k & 1) ^ (j >> k & 1)) {
					a[i][j] = k;
					break;
				}
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			cout << a[i][j] + 1 << (j == n - 1 ? "\n" : " ");
		}
	}
	return 0;
}
