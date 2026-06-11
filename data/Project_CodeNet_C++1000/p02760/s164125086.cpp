#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int A[3][3];
	rep(i,3)rep(j,3) cin >> A[i][j];
	int N;
	cin >> N;
	int b[N];
	rep(i,N) cin >> b[i];

	int h[3][3] = {0};
	rep(i,N)rep(j,3)rep(k,3){
		if (b[i] == A[j][k]) h[j][k] = 1;
	}

	int bingo = 0;
	rep(i,3) {
		if (h[i][0]*h[i][1]*h[i][2] == 1) {
			bingo = 1;
			break;
		}
	}
	rep(i,3) {
		if (h[0][i]*h[1][i]*h[2][i] == 1) {
			bingo = 1;
			break;
		}
	}
	if (h[0][0]*h[1][1]*h[2][2] == 1) bingo = 1;
	if (h[0][2]*h[1][1]*h[2][0] == 1) bingo = 1;

	if (bingo) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
