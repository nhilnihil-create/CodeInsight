#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	void solve() {
		long N, A, B;
		cin >> N >> A >> B;

		if( (A&1) == (B&1) ) {
			cout << (B-A)/2 << endl;
		}
		else {
			cout << min( A-1, N-B ) + 1 + (B-A-1)/2 << endl;
		}
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();
	return 0;
}
