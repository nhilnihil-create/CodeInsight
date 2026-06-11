#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;


void solve()
{
	ld w, h, x, y;
	cin >> w >> h >> x >> y;

	int mul = 0;
	if (x == w / 2 && y == h / 2)
		mul = 1;
	ld ans= (ld)(w * h) / 2;
	cout << ans << " " << mul;
}

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}


