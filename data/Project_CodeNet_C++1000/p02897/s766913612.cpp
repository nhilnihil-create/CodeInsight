#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define mod 1000000007
#define mem(a,val) memset(a,val,sizeof(a))
#define ps(x,noOfDecimal) fixed<<setprecision(noOfDecimal)<<x

using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	int t = 1;
	// cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long double val;

		if (n & 1) {
			int x = n / 2 + 1;
			int y = n ;
			// cout << x << " " << y << endl;
			val = (x / (double) y);
			cout << ps(val, 10);
		}
		else {
			cout << "0.5000000000";
		}


	}
	return 0;
}