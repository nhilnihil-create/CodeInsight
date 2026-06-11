#include "bits/stdc++.h"
#define long int64_t
using namespace std;

struct Solver {
	void solve() {
		int A, V, B, W, T;
		cin >> A >> V >> B >> W >> T;

		int x = abs( A-B );
		long y = V - W;
		if( x <= y*T ) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();
	return 0;
}
