#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int N, M, X;
	cin >> N >> M >> X;
	int C[N];
	int A[N][M];
	rep(i,N){
		cin >> C[i];
		rep(j,M) cin >> A[i][j];
	}
	
	ll cost_min = 0;
	rep(i,N) cost_min += C[i];

	int buy_all = 0;
	int k = 1;
	rep(i,N) {
		buy_all += k;
		k *= 2;
	}

	int mast_all = 1;
	ll und[M];

	for (int i = 0; i <= buy_all; i++) {
		rep(j,M) und[j] = 0;
		ll cost = 0;

		rep(j,N) {
			if (i>>j & 1) {
				cost += C[j];
				rep(k,M) und[k] += A[j][k];
			}
		}
		
		mast_all = 1;
		rep(j,M) {
			if (und[j] < X) {
				mast_all = 0;
				break;
			}
		}
		if (mast_all == 1 && cost <= cost_min) cost_min = cost;
	}

	if (mast_all == 0) cout << -1 << endl;
	else cout << cost_min << endl;

return 0;
}
