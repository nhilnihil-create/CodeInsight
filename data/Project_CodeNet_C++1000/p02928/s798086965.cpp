#pragma region
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
	vector<int> a(n); rep(i, n)cin >> a[i];
	ll res = 0;
	ll MOD = 1e9 + 7;
	rep(i, n)
	{
		ll cnt = 0;
		rep(j, n)
		{
			if (a[i] > a[j])++cnt;
		}
		ll tmp = (k - 1)*k / 2;
		tmp %= MOD;
		res += cnt * tmp;
		res %= MOD;
	}
	rep(i, n)
	{
		ll cnt = 0;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[i] > a[j])++cnt;
		}
		res += cnt * k;
		res %= MOD;
	}
	cout << res << endl;
}