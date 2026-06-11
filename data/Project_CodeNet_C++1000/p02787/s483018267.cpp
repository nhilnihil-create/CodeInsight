#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   " << endl;
		for(int j=0; j<v[i].size(); j++){
			cout << v[i][j] << "   ";
		}
		cout << endl;
	}
}




int main(){//
	int H, N;
	cin >> H >> N;
	vector<int> A(N), B(N);
	for(int i=0; i<N; i++) cin >> A[i] >> B[i];

	const int H_MAX = 10000;
	const int B_MAX = 10000;
	const int INF = H_MAX*B_MAX+1;
	//dp[n][h]: 0~n-1番目までの魔法を考慮して体力hを減らすのに必要な最小魔力
	vector<vector<int>> dp(N+1, vector<int>(H+1, INF));
	dp[0][0] = 0;//魔法使わないで体力0を減らすのに必要な魔力は0
	for(int n=0; n<=N; n++) dp[n][0] = 0;

	//解1 //dp[n][h]: 魔法0~n-1番目まで考慮した時，体力h以下の敵を倒すのに必要な最小魔力
	//解2に(★)の行を足しただけで，　解2の最後のansを探すforループがいらなくなる
	for(int h=0; h<=H; h++){
		for(int n=0; n<N; n++){
			if(h<A[n]) dp[n+1][h] = min(dp[n+1][h], dp[n][0]+B[n]);//........(★)
			dp[n+1][h] = min(dp[n+1][h], dp[n][h]+0*B[n]);//魔法n番を使わない
			if(h+A[n] < (int)dp[0].size()) dp[n+1][h+A[n]] = min(dp[n+1][h+A[n]], dp[n][h] + B[n]);//魔法nを使う(1回目)
			if(h+A[n] < (int)dp[0].size()) dp[n+1][h+A[n]] = min(dp[n+1][h+A[n]], dp[n+1][h]+B[n]);//魔法nを使う(2回目以降)(1回目の時のh+A[n]が今回のhと等しくなる時に影響)
		}
	}
	cout << dp[N][H] << endl;

	//解2
	// vector<vector<int>> dp(N+1, vector<int>(H+H_MAX+1, INF));
	//
	// // for(int n=0; n<N; n++){
	// // 	for(int h=0; h<=H+H_MAX; h++){
	// for(int h=0; h<H+H_MAX; h++){
	// 	for(int n=0; n<N; n++){
	// 		dp[n+1][h] = min(dp[n+1][h], dp[n][h]+0*B[n]);//魔法n番を使わない
	// 		if(h+A[n] < (int)dp[0].size()) dp[n+1][h+A[n]] = min(dp[n+1][h+A[n]], dp[n][h] + B[n]);//魔法nを使う(1回目)
	// 		if(h+A[n] < (int)dp[0].size()) dp[n+1][h+A[n]] = min(dp[n+1][h+A[n]], dp[n+1][h]+B[n]);//魔法nを使う(2回目以降)(1回目の時のh+A[n]が今回のhと等しくなる時に影響)
	// 	}
	// }
	// //print_vec2(dp);
	// int ans = INF;
	// for(int h=H; h<=H+H_MAX; h++){//答えは体力H以上削った場合の最小消費体力
	// 	ans = min(ans, dp[N][h]);
	// }
	// cout << ans << endl;

}
