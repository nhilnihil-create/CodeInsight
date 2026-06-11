#pragma region
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <iomanip>
#include <cstdint>
#include <cstdlib>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	ll n, k; cin >> n >> k;
	vector<ll> a(n); rep(i, n)cin >> a[i];
	ll sum = 0;
	rep(i, n)sum += a[i];
	vector<ll> factors;
	for (int i = 1; i*i <= sum; ++i)
	{
		if (sum%i == 0)
		{
			factors.push_back(i);
			factors.push_back(sum / i);
		}
	}
	sort(all(factors));
	ll res = 1;
	for (ll x : factors)
	{
		vector<ll> r(n); rep(i, n)r[i] = a[i] % x;
		sort(all(r));
		vector<ll> m(n + 1), p(n + 1);
		rep(i, n)m[i + 1] = m[i] + r[i];
		rep(i, n)p[i + 1] = p[i] + (x - r[i]);
		rep(i, n + 1)
		{
			ll can = max(m[i], p[n] - p[i]);
			if (can <= k)res = x;
		}
	}
	cout << res << endl;
}
