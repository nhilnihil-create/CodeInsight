#include "bits/stdc++.h"
using namespace std;
const int INF = 1001001001;
int main() {
	int H,N;
	cin >> H>>N;
	//vector<vector<int>> DP0(K + 1, vector<int>(N.size())); 
	//DP0[0][0] = 1; 
	vector<int> DP(H + 1,INF);
	DP[0] = 0;
	for (int n = 0;n < N;++n) {
		int a, b;
		cin >> a >> b;
		for (int m = 0; m < H; ++m) {
			int nj = min(m + a, H);
			DP[nj] = min(DP[nj], DP[m] + b);
		}
	}
	cout << DP[H]<< endl;
	return 0;
}