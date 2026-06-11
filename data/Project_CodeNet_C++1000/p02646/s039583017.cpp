
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fast_io() ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int32_t main() {
	fast_io();
	int a, v, b, w, t;
	cin >> a >> v >> b >> w >> t;
	if (w >= v)
		cout << "NO\n";
	else
	{
		int d1 = v * t;
		int d2 = w * t;
		if (d1 >= d2 + abs(a - b))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}