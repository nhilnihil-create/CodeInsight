#include <iostream>
#include<algorithm>
#define pi 3.14159265358979323846
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb emplace_back
#define mp make_pair
#define MOD (int) 1e9+7
#define for0(i, n) for (int i = 0; i < n; i++)
#define ff first
#define ss second
#define endl "\n"
#define bits(n) __builtin_popcount(n)
#define ini(a, i) memset(a, i, sizeof(a))

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	// cin >> t;
	t  = 1;
	while (t--)
	{
		long double a, b, h, m;
		cin >> a >> b >> h >> m;
		//calculating deg
		long double hdeg = h * 30;
		long double mdeg = m * 6;
		hdeg += mdeg / 12;
		long double deg = abs(hdeg - mdeg);

		//apply law of cosines
		long double cosdeg = cos(deg * pi / 180);
		long double asqr = a * a;
		long double bsqr = b * b;
		long double c = sqrt(asqr + bsqr - 2 * a * b * cosdeg);
		cout << fixed << showpoint;
		cout << setprecision(20);
		cout << c << endl;
		return 0;

	}
	return 0;
}
