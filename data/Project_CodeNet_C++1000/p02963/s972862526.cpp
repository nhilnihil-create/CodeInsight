#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	void solve() {
		long S;
		cin >> S;

		const long n = 1e9;
		long x2 = n;
		long y2 = 1;
		long x3 = (n - S%n) % n;
		long y3 = (S + x3) / n;
		cout << "0 0 " << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << endl;
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();
	return 0;
}
