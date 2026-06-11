#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N, A, B;
	cin >> N >> A >> B;

	long long d = abs( A - B );
	long long ans = d / 2;
	if( d % 2 ) {
		long long mi = min( A, B );
		long long ma = max( A, B );
		ans = min( ma - 1, N - mi );
		long long ans1 = min( mi - 1, N - ma ) + (d + 1) / 2;
		ans = min( ans, ans1 );
	}

	cout << ans << endl;
}
