#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, V, P;
	long long M;
	cin >> N >> M >> V >> P;
	vector<long long> A( N );
	for( int i = 0; i < N; i++ ) {
		cin >> A[i];
	}

	sort( A.begin(), A.end(), greater<long long>() );
	auto f = [&]( int x ) -> bool
	{
		if( x < P ) return true;
		long long now = A[x] + M;
		if( now < A[P - 1] ) return false;
		long long score = 0;
		score = (P - 1) * M + (N - x) * M;
		for( int i = P - 1; i < x; i++ ) {
			score += min( M, max( 0LL, now - A[i] ) );
		}
		return score >= M * V;
	};
	int l = -1;
	int r = N;
	while( r - l > 1 ) {
		int m = (l + r) / 2;
		if( f( m ) ) l = m;
		else r = m;
	}
	int ans = l + 1;

	cout << ans << endl;
}
