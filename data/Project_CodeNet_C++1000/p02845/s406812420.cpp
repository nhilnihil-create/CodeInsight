#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> A( N );
	for( int i = 0; i < N; i++ ) {
		cin >> A[i];
	}

	vector<vector<int>> dp( N + 1, vector<int>( 3 ) );
	for( int i = 0; i < N; i++ ) {
		int flag = 0;
		for( int j = 0; j < 3; j++ ) {
			if( flag == 0 && dp[i][j] == A[i] ) {
				flag = 1;
				dp[i + 1][j] = dp[i][j] + 1;
			}
			else dp[i + 1][j] = dp[i][j];
		}
	}
	const long long MOD = 1000000000 + 7;
	long long ans = 1;
	for( int i = 0; i < N; i++ ) {
		int n = 0;
		int a = A[i];
		for( int j = 0; j < 3; j++ ) {
			if( dp[i][j] == a ) n++;
		}
		ans = ans * n % MOD;
	}

	cout << ans << endl;
}
