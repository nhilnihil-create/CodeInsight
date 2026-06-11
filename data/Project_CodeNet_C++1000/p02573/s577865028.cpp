#include "bits/stdc++.h"
#define long int64_t
using namespace std;

struct Solver {
	struct UF {
		vector<int> r;

		UF( int n ): r( n, -1 ) {}
		int root( int x ) {
			if( r[x] < 0 ) { return x; }
			r[x] = root( r[x] );
			return r[x];
		}
		bool unite( int x, int y ) {
			x = root( x );
			y = root( y );
			if( x == y ) { return false; }
			if( r[x] > r[y] ) { swap( x, y ); }
			r[x] += r[y];
			r[y] = x;
			return true;
		}
		int size( int x ) {
			return -r[root( x )];
		}
	};

	void solve() {
		int N, M;
		cin >> N >> M;

		UF uf( N );
		for( int i = 0; i < M; ++i ) {
			int A, B;
			cin >> A >> B;
			uf.unite( A-1, B-1 );
		}

		int ans = 0;
		for( int i = 0; i < N; ++i ) {
			ans = max( ans, uf.size( i ) );
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
