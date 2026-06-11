#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	void solve() {
		int X, Y;
		cin >> X >> Y;

		int ans = 0;
		if( X <= 3 ) { ans += 100000 * (4-X); }
		if( Y <= 3 ) { ans += 100000 * (4-Y); }
		if( X == 1 && Y == 1 ) { ans += 400000; }

		cout << ans << endl;
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();

	return 0;
}
