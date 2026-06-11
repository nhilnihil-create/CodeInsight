#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n, a, b;
	cin >> n >> a >> b;
	if (!((b-a)&1)) {
		cout << ((b-a)>>1ll);
		return 0;
	}
	cout << min(a-1, n-b) + 1 + ((b-a)>>1ll);
	return 0;
}
