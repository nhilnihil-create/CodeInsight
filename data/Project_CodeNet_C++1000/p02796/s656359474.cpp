#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	typedef pair<long long, long long> P;
	vector<P> p( N );
	for( int i = 0; i < N; i++ ) {
		long long X, L;
		cin >> X >> L;
		p[i] = P( X + L, X - L );
	}

	sort( p.begin(), p.end() );
	int ans = 0;
	long long nr = -1000000000;
	for( int i = 0; i < N; i++ ) {
		long long l, r;
		tie( r, l ) = p[i];
		if( l >= nr ) {
			nr = r;
			ans++;
		}
	}

	cout << ans << endl;
}
