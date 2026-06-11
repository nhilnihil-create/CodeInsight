#include <bits/stdc++.h>
using namespace std;

typedef tuple<double, long long, long long> TP;

int main()
{
	int N;
	cin >> N;
	vector<TP> xy( N * 2 );
	for( int i = 0; i < N; i++ ) {
		cin >> get<1>( xy[i] ) >> get<2>( xy[i] );
		get<0>( xy[i] ) = atan2( (double)get<2>( xy[i] ), (double)get<1>( xy[i] ) );
	}

	sort( xy.begin(), xy.begin() + N );
	for( int i = 0; i < N; i++ ) {
		xy[i + N] = xy[i];
	}
	long long ans = 0;
	for( int i = 0; i < N; i++ ) {
		long long x = 0;
		long long y = 0;
		for( int j = i; j < i + N; j++ ) {
			x += get<1>( xy[j] );
			y += get<2>( xy[j] );
			ans = max( ans, x * x + y * y );
		}
	}

	cout << fixed << setprecision(12) << sqrt( (double)ans ) << endl;
}
