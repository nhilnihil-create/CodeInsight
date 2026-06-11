#include <bits/stdc++.h>
using namespace std;

int main()
{
	int X, Y, A, B, C;
	cin >> X >> Y >> A >> B >> C;
	vector<long long> p( A );
	for( int i = 0; i < A; i++ ) {
		cin >> p[i];
	}
	vector<long long> q( B );
	for( int i = 0; i < B; i++ ) {
		cin >> q[i];
	}
	vector<long long> r( C );
	for( int i = 0; i < C; i++ ) {
		cin >> r[i];
	}

	sort( p.begin(), p.end(), greater<long long>() );
	sort( q.begin(), q.end(), greater<long long>() );
	sort( r.begin(), r.end(), greater<long long>() );
	long long ans = 0;
	int pi = 0;
	int qi = 0;
	int ri = 0;
	for( int i = 0; i < X + Y; i++ ) {
		long long ma = 0;
		int s = -1;
		if( pi < min( X, A ) ) {
			ma = p[pi];
			s = 0;
		}
		if( qi < min( Y, B ) && q[qi] > ma ) {
			ma = q[qi];
			s = 1;
		}
		if( ri < C && r[ri] > ma ) {
			ma = r[ri];
			s = 2;
		}
		if( s == 0 ) pi++;
		else if( s == 1 ) qi++;
		else if( s == 2 ) ri++;
		ans += ma;
	}

	cout << ans << endl;
}
