#include "bits/stdc++.h"

using namespace std;

int main() {
	vector<vector<int>> A(3, vector<int>(3));
	for (int i = 0;i<3;++i) {
		for (int j = 0;j<3;++j) {
			cin >> A[i][j];
		}
	}
	int N;
	cin >> N;
	vector<int>B(N);
	for (int n = 0;n<N;++n) {
		cin >> B[n]; 
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (B[n]==A[i][j]) {
					A[i][j] = -1;
				}
			}
		}
	}
	bool b = false;	
	for (int n = 0; n < 3; ++n) {
		if (-3 == A[n][0] + A[n][1] + A[n][2]) {
			b = true;
		}
	}
	for (int n = 0; n < 3; ++n) {
		if (-3 == A[0][n] + A[1][n] + A[2][n]) {
			b = true;
		}
	}
	if (-3==A[0][0]+A[1][1]+A[2][2]) {
		b = true;
	}
	if (-3 == A[0][2] + A[1][1] + A[2][0]) {
		b = true;
	}
	if (b) {
		cout <<"Yes"<<endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}