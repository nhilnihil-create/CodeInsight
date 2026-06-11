#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	const double PI = acos( -1 );

	void solve() {
		double A, B, X;
		cin >> A >> B >> X;

		double l = PI/2;
		double r = 0;

		for( int i = 0; i < 10000; ++i ) {
			double m = (l+r) / 2;
			if( f( A, B, m ) < X ) {
				l = m;
			}
			else {
				r = m;
			}
		}

		cout << l/PI * 180 << endl;
	}

	double f( double a, double b, double theta ) {
		if( theta >= PI/2 ) { return 0; }

		double ret;
		double t = tan( theta );
		if( a*t <= b ) {
			ret = a*a*b - a*a*a*t/2;
		}
		else {
			ret = b*b/t*a/2;
		}

		return ret;
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();
	return 0;
}
