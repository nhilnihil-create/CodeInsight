#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const int INF = 10010010;

int main() {
	int N, M;
	cin >> N >> M;

	vector <int> a(M);
	vector <int> dec(M);	//ベクタc[ii]をinteger値に変換したもの
	for (int ii = 0; ii < M; ++ii){
		int b;
		cin >> a[ii] >> b;
		for (int jj = 0; jj < b; ++jj){
			int c;
			cin >> c;
			c--;
			dec[ii] += (1<<c);
		}
	}

	int stateNum = (1<<N);
	vector <int> dp(stateNum, INF);	//最小値
	vector <bool> visit(stateNum, false);
	visit[0] = true;
	dp[0] = 0;
	for (int state = 0; state < stateNum; ++state){
		if (!visit[state]) continue;
		for (int jj = 0; jj < M; ++jj){
			int newState = state | dec[jj];
			visit[newState] = true;
			dp[newState] = min(dp[newState], dp[state] + a[jj]);
		}
	}

	if (visit[stateNum-1]){
		cout << dp[stateNum-1] << "\n";
	} else {
		cout << -1 << "\n";		
	}

	return 0;
}
