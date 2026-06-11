#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
	int n; cin >> n;
	ll ans = 1, maxvalue = 1e18;
	double t = 1;

	for (int i = 0; i < n; ++i)
	{
		ll a; cin >> a;
		ans *= a;
		t *= a;
	}
	if (ans > maxvalue || t > maxvalue)
		cout << -1 << endl;
	else
		cout << ans << endl;
}

