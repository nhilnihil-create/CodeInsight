#include "bits/stdc++.h"
#define long int64_t
using namespace std;

struct Solver {
	static const long mod = 1000000007;
	
	long powmod( long x, long y ) {
		long r = 1;
		while( y-- > 0 ) { r = r*x % mod; }
		return r;
	}

	void solve() {
		int N;
		cin >> N;

		long ans = powmod( 10, N );
		ans -= powmod( 9, N );
		ans -= powmod( 9, N );
		ans += powmod( 8, N );
		ans = (ans % mod + mod) % mod;

		cout << ans << endl;
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();
	return 0;
}
