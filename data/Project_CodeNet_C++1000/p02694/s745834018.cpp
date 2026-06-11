#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
	ll x;
	cin >> x;

	ll s = 100;
	int cnt = 0;
	while(s < x)
	{
		cnt++;
		s += s/100;
	}
	cout << cnt << "\n";
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
