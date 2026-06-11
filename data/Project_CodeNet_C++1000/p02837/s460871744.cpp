#include "bits/stdc++.h"

using namespace std;


int main() {
	
	int N;
	cin >> N;
	vector<int>A(N); 
	int g[15][15];
	for (int i = 0;i<15;++i) {
		for (int j = 0;j<15;++j) {
			g[i][j] = -1;
		}
	}
	for (int n = 0;n<N;++n) {
		cin >> A[n];
		for (int m = 0;m<A[n];++m) {
			int x, y;
			cin >> x >> y;
			x--;
			g[n][x] = y;
		}
	}
	int ans = 0;
	for (int i = 0;i< (1 << N);++i) {
		int anstmp = 0;
		vector<int>B(N);//正直者リスト
		for (int j = 0;j<N;++j) {
			if (1 & (i >> j)) {
				B[j] = 1;
				anstmp++;
			}
		}
		bool bans = true;
		for (int j = 0; j < N; ++j) {
			if (1 == B[j]) {
				for (int k = 0;k < N;++k) {
					if (-1 == g[j][k]) {
						continue;
					}
					if (B[k] != g[j][k]) {
						bans = false;
					}
				}
			}
		}
		if (bans) {
			ans = max(ans, anstmp);
		}

	}
	cout << ans <<endl;
	return 0;
}
