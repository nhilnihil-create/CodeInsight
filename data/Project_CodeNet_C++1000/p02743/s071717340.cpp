// Panasonic_2020_C

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll a, b, c;
	cin >> a >> b >> c;

	ll m = 4 * a * b;
	ll n = (c - a - b) * (c - a -b);

	//cout << m << "\n";
	//cout << n << "\n";

	if((c - a -b > 0) && m < n) cout << "Yes" << "\n";
	else cout << "No";

	return 0;
}                                