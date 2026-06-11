#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

int		main(void)
{
	ll n, k;
	cin >> n >> k;
	vector<ll> H(n);
	for (int i = 0; i < n; ++i)
		cin >> H[i];
	sort(rall(H));
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (k)
			--k;
		else
			ans += H[i];
	}
	cout << ans << endl;
}

