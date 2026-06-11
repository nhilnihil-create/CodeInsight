#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long L, R;
	cin >> L >> R;

	long long ans = 2019;
	if( R - L + 1 >= 2019 ) ans = 0;
	else {
		for( long long l = L; l < R; l++ ) {
			for( long long r = l + 1; r <= R; r++ ) {
				ans = min( ans, l * r % 2019 );
			}
		}
	}

	cout << ans << endl;
}
