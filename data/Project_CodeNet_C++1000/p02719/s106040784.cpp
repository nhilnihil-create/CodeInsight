#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	if (n == 0)
		cout << 0;
	else if (k == 1)
		cout << 0;
	else
	{
		ll r = n % k;
		cout << min(r, abs(r - k));
	}
	return 0;
}
