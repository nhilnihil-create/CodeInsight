#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	ll a, v; cin >> a >> v;
	ll b, w; cin >> b >> w;
	ll t; cin >> t;

	if (v <= w)
	{
		cout << "NO" << endl;
		return 0;
	}
	else
	{
		ll s = v - w;
		if (s*t >= llabs(a-b))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return (0);
}