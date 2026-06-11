#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	void solve() {
		int N;
		cin >> N;

		vector<int> A( N );
		for( int i = 0; i < N; ++i ) { cin >> A[i]; }
		sort( A.begin(), A.end() );

		const int amax = (int)1e6;
		vector<int> tb( amax+1 );
		for( int i = 0; i < N; ++i ) {
			if( tb[A[i]] >= 2 ) { continue; }

			for( int j = A[i]; j <= amax; j += A[i] ) {
				tb[j] += 1;
			}
		}

		int ans = 0;
		for( int i = 0; i < N; ++i ) {
			if( tb[A[i]] == 1 ) { ans += 1; }
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
