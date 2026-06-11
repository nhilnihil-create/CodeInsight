#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <cmath>
#include <bitset>
#include <queue>
#include <set>
#include <numeric>
#include <unordered_set>
#include <iomanip>
#include <string>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	ll n, d, a;
	cin >> n >> d >> a;
	vector<pair<ll, ll>> v(n);
	for (auto &x : v)
	{
		cin >> x.first >> x.second;
		x.second = (x.second + a - 1) / a;
	}
	sort(v.begin(), v.end());

	ll runsum=0;
	vector<ll> change(n+1);

	ll tot = 0;
	for (ll i = 0; i < n; ++i)
	{
		runsum += change[i];
		ll h = v[i].second - runsum;
		if (h <= 0)
			continue;
		ll lo = 0, hi = n - 1, ans = -1;
		while (lo <= hi)
		{
			ll mid = lo + (hi - lo) / 2;
			if (v[mid].first <= v[i].first + 2 * d)
			{
				ans = mid;
				lo = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}
		}
		runsum += h;
		change[ans + 1] -= h;
		tot += h;
	}
	cout << tot;
}