#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve()
{
	ll a, b, v, w, x;
	cin >> a >> v >> b >> w >> x;
	ll sum = abs(b - a);
	for(int i = 0; i < x; i++)
	{
		sum += w - v;
		if(sum <= 0)
		{
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main()
{
	int t = 1;
//	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}

