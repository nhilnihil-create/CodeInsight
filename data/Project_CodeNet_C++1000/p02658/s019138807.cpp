#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
	int n; cin >> n;
	ll ans = 1, maxvalue = 1e18;

	for (int i = 0; i < n; ++i)
	{
		ll a; cin >> a;
		if (a == 0)
		{
			cout << 0 << endl;
			return 0;
		}
		if (a <= maxvalue/ans)
			ans *= a;
		else 
			ans = -1;
	}
	cout << ans << endl;
}

