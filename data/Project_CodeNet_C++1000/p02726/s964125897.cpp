#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	void solve() {
		int N, X, Y;
		cin >> N >> X >> Y;
		if( X > Y ) { swap( X, Y ); }

		vector<int> ans(N);
		for( int i = 1; i <= N-1; ++i ) {
			for( int j = i+1; j <= N; ++j ) {
				int d = min( j-i, abs( X-i ) + 1 + abs( j-Y ) );
				ans[d] += 1;
			}
		}

		for( int i = 1; i < N; ++i ) {
			cout << ans[i] << '\n';
		}
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();
	return 0;
}
