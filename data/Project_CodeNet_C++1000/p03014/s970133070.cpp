#include "bits/stdc++.h"
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> S(H);
	for (int n = 0; n < H; ++n) {
		cin >> S[n];
	}
	vector<vector<int>> L(H, vector<int>(W));	
	for (int n = 0; n < H; ++n) {
		for (int m = 0; m < W; ++m) {
			if ('#' != S[n][m]) {
				if (0 == m) {
					L[n][m] = 1;
				}
				else {
					L[n][m] = L[n][m - 1] + 1;
				}
				
			}
			else {
				L[n][m] = 0;
			}
		}
	}
	vector<vector<int>> R(H, vector<int>(W));	
	for (int n = 0; n < H; ++n) {
		for (int m = W - 1; m >= 0; --m) {
			if ('#' != S[n][m]) {
				if (W - 1 == m) {
					R[n][m] = 1;
				}
				else {
					R[n][m] = R[n][m +1 ] + 1;
				}

			}
			else {
				R[n][m] = 0;
			}
		}
	}
	vector<vector<int>> D(H, vector<int>(W));
	for (int n = H - 1; n >= 0; --n) {
		for (int m = 0; m < W; ++m) {
			if ('#' != S[n][m]) {
				if (H - 1 == n) {
					D[n][m] = 1;
				}
				else {
					D[n][m] = D[n + 1][m] + 1;
				}

			}
			else {
				D[n][m] = 0;
			}
		}
	}
	vector<vector<int>> U(H, vector<int>(W));	
	for (int n = 0; n < H; ++n) {
		for (int m = 0; m < W; ++m) {
			if ('#' != S[n][m]) {
				if (0 == n) {
					U[n][m] = 1;
				}
				else {
					U[n][m] = U[n - 1][m] + 1;
				}

			}
			else {
				U[n][m] = 0;
			}
		}
	}
	int ans = 0;
	for (int n = 0; n < H; ++n) {
		for (int m = 0; m < W; ++m) {
			if ('#' != S[n][m]) {
				ans = max(ans, L[n][m]+R[n][m]+D[n][m]+U[n][m] - 3);
			}
		}
	}
	cout << ans << endl;
	return 0;
}