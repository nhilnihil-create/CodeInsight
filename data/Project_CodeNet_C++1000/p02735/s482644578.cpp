#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int H, W;
	cin >> H >> W;

	vector <string> s(H);
	for (int ii = 0; ii < H; ++ii){
		cin >> s[ii];
	}

	vector<vector<int>> dp(H, vector <int> (W, 0));

	//スタート地点の処理
	dp[0][0] = (s[0][0]=='.') ? 0 : 1;

	//列0の処理
	for (int h = 1; h < H; ++h){
		dp[h][0] = dp[h-1][0];
		if ( (s[h-1][0]=='.') && (s[h][0]=='#') ){
			dp[h][0]++;
		}
	}

	//行0の処理
	for (int w = 1; w < W; ++w){
		dp[0][w] = dp[0][w-1];
		if ( (s[0][w-1]=='.') && (s[0][w]=='#') ){
			dp[0][w]++;
		}
	}

	//残りのマスの処理
	for (int h = 1; h < H; ++h){
		for (int w = 1; w < W; ++w){
			int up = dp[h-1][w];
			if ( (s[h-1][w]=='.') && (s[h][w]=='#') ){
				up++;
			}
			int left = dp[h][w-1];
			if ( (s[h][w-1]=='.') && (s[h][w]=='#') ){
				left++;
			}
			dp[h][w] = min(up, left);
		}
	}

	int ans = dp[H-1][W-1];
	cout << ans << endl;


	return 0;
}
