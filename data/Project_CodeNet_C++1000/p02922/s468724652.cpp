#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll a, b;
	cin >> a >> b;
	ll ans = 0;
	ll nr = 1;
	while (nr < b)
	{
		ans++;
		nr += (a - 1);
	}
	cout << ans;
	return 0;
}
