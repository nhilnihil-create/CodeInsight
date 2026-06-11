#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int R, S, P;
	cin >> R >> S >> P;
	string T;
	cin >> T;
	vector<string>H(K);
	for (int n = 0;n<N;++n) {
		H[n%K].push_back(T[n]);
	}
	int ans = 0;
	for (int n = 0;n < K;++n) {
		vector<int>DP(3);
		for (int m = 0;m<H[n].size();++m) {
			vector<int>DPtmp(3);
			if (0 == m) {
				if ('r' == H[n][m]) {
					DPtmp[0] = 0; 
					DPtmp[1] = 0; 
					DPtmp[2] = P;
				}
				else if ('s' == H[n][m]) {
					DPtmp[0] = R;
					DPtmp[1] = 0;
					DPtmp[2] = 0;
				}
				else {
					DPtmp[0] = 0;
					DPtmp[1] = S;
					DPtmp[2] = 0;
				}
			}
			else {
				if ('r' == H[n][m]) {//あいてグー
					DPtmp[0] = max(DP[1],DP[2]);
					DPtmp[1] = max(DP[0],DP[2]);
					DPtmp[2] = max(DP[0],DP[1])+P;
				}
				else if ('s' == H[n][m]) {
					DPtmp[0] = max(DP[1], DP[2])+R;
					DPtmp[1] = max(DP[0], DP[2]);
					DPtmp[2] = max(DP[0], DP[1]) ;
				}
				else {
					DPtmp[0] = max(DP[1], DP[2]);
					DPtmp[1] = max(DP[0], DP[2])+S;
					DPtmp[2] = max(DP[0], DP[1]);
				}
			}
			DP = DPtmp;
		}
		ans += max(DP[0], max(DP[1], DP[2]));
	}
	cout << ans << endl;
	return 0;
}