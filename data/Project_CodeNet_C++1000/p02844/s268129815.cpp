 #include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	string S;
	cin >> N >> S;

	vector<vector<vector<bool>>> dp( N + 1, vector<vector<bool>>( 4, vector<bool>( 10000 ) ) );
	dp[0][0][0] = true;
	for( int i = 0; i < N; i++ ) {
		for( int j = 0; j <= 3; j++ ) {
			for( int k = 0; k < 1000; k++ ) {
				if( dp[i][j][k] == false ) continue;
				dp[i + 1][j][k] = dp[i][j][k];
				if( j <= 2 ) dp[i + 1][j + 1][k * 10 + S[i] - '0'] = true;
			}
		}
	}
	int ans = 0;
	for( int k = 0; k < 1000; k++ ) {
		if( dp[N][3][k] ) ans++;
	}

	cout << ans << endl;
}
