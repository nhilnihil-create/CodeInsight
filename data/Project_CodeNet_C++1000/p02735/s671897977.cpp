#include <bits/stdc++.h>
using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;
	vector<string> s( H );
	for( int i = 0; i < H; i++ ) {
		cin >> s[i];
	}

	vector<vector<int>> dp( H, vector<int>( W, INT32_MAX / 2 ) );
	dp[0][0] = 0;
	if( s[0][0] == '#' ) dp[0][0] = 1;
	int dx[2] = { 0, 1 };
	int dy[2] = { 1, 0 };
	for( int y = 0; y < H; y++ ) {
		for( int x = 0; x < W; x++ ) {
			for( int i = 0; i < 2; i++ ) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if( ny >= H || nx >= W ) continue;
				int a = 0;
				if( s[y][x] == '.' && s[ny][nx] == '#' ) a = 1;
				dp[ny][nx] = min( dp[ny][nx], dp[y][x] + a );
			}
		}
	}
	int ans = dp[H - 1][W - 1];

	cout << ans << endl;
}
