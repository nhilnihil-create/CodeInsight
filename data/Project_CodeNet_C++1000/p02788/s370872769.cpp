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

	vector<ll> bit(n+1);
	auto update =[&](ll idx, ll val){
		for (++idx; idx <=n; idx += idx & -idx){
			bit[idx] += val;
		}
	};
	auto query = [&](ll idx){
		ll res = 0;
		for (++idx; idx > 0; idx -= idx & -idx){
			res += bit[idx];
		}
		return res;
	};
	auto range_update = [&](ll l, ll r, ll val){
		update(l, val);
		update(r+1, -val);
	};
	for (ll i =0;i<n;++i){
		range_update(i, i, v[i].second);
	}

	ll tot = 0;
	for (ll i = 0; i < n; ++i)
	{
		ll h = query(i);
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
		range_update(i, ans, -h);
		tot += h;
	}
	cout << tot;
}