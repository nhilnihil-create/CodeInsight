#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	void solve() {
		int N;
		cin >> N;

		vector<map<int, int>> a( N );
		for( int i = 0; i < N; ++i ) {
			int A;
			cin >> A;
			for( int j = 0; j < A; ++j ) {
				int x, y;
				cin >> x >> y;
				a[i][x-1] = y;
			}
		}

		int ans = 0;
		for( int bt = 1; bt < (1<<N); ++bt ) {
			bool ok = true;
			int cnt = 0;
			for( int i = 0; i < N; ++i ) {
				if( bt & (1<<i) ) {
					for( auto& p: a[i] ) {
						if( p.second && (bt & (1<<p.first)) ) {} // ok
						else if( !p.second && !(bt & (1<<p.first)) ) {} // ok
						else {
							ok = false;
							break;
						}
					}
					cnt += 1;
				}
				if( !ok ) { break; }
			}
			if( ok && ans < cnt ) { ans = cnt; }
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
