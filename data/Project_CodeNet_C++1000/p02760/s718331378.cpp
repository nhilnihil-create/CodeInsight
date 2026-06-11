#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int A[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	int N;
	int b[10];
	int appear[3][3];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			appear[i][j] = false;
			for (int k = 0; k < N; k++) {
				if (b[k] == A[i][j]) appear[i][j] = true;
			}
		}
	}
	string ans = "No";
	for (int i = 0; i < 3; i++) {
		if (appear[i][0] && appear[i][1] && appear[i][2]) ans = "Yes";
	}
	for (int i = 0; i < 3; i++) {
		if (appear[0][i] && appear[1][i] && appear[2][i]) ans = "Yes";
	}
	if (appear[0][0] && appear[1][1] && appear[2][2]) ans = "Yes";
	if (appear[0][2] && appear[1][1] && appear[2][0]) ans = "Yes";
	cout << ans << endl;

	return 0;
}
