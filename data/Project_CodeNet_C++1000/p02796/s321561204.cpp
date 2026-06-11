#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	void solve() {
		int N;
		cin >> N;

		vector<int> X( N ), L( N );
		for( int i = 0; i < N; ++i ) { cin >> X[i] >> L[i]; }

		vector<pair<int, int>> rl( N );
		for( int i = 0; i < N; ++i ) {
			rl[i] = { X[i]+L[i], X[i]-L[i] };
		}
		sort( rl.begin(), rl.end() );

		int ans = 0;
		int x = -INT_MAX;
		for( int i = 0; i < N; ++i ) {
			if( x <= rl[i].second ) {
				ans += 1;
				x = rl[i].first;
			}
		}

		cout << ans << endl;
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();
	return 0;
}
