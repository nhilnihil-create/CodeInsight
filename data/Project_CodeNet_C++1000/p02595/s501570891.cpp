#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, d, ans = 0;
	cin >> n >> d;

	for (int i=0; i<n; i++)
	{
		long long x, y;
		cin >> x >> y;
		if ( ( x*x+y*y ) <= d*d ) {
			ans++;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}