 #include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> v( N + 1 );
	for( int i = 0; i < M; i++ ) {
		int a;
		cin >> a;
		v[a] = 1;
	}

	const long long MOD = 1000000000 + 7;
	vector<int> dp( N + 1 );
	dp[0] = 1;
	for( int i = 0; i <= N; i++ ) {
		if( i - 1 >= 0 && v[i - 1] == 0 ) {
			dp[i] += dp[i - 1];
			dp[i] %= MOD;
		}
		if( i - 2 >= 0 && v[i - 2] == 0 ) {
			dp[i] += dp[i - 2];
			dp[i] %= MOD;
		}
	}
	long long ans = dp[N];

	cout << ans << endl;
}
