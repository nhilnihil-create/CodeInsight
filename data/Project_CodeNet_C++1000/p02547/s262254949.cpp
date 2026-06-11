// Alert!!! This program may have some NARGLE.
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second
#define endl '\n'

using namespace std;

const int Mod = 1e9 + 7, Inf = 1e9;

int32_t main ()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int k, n = 0, x, y;
	cin >> k;
	bool f = 0;
	while (k--)
	{
		cin >> x >> y;
		if (x == y)
			n++;
		else
			n = 0;
		if (n == 3)
			f = 1;
	}
	cout << (f? "Yes": "No");
	return 0;
}