#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define int ll

signed main ()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);

	double now;
	cin >> now;
	now /= 3.0;
	cout << fixed << setprecision(10) << now*now*now << endl;

	return 0;

}
