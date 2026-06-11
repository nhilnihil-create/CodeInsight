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
	vector<ll> a(n), f(n);
	rep(i, n)cin >> a[i];
	rep(i, n)cin >> f[i];
	sort(all(a));
	sort(all(f), greater<ll>());
	ll ok = 1e12 + 1, ng = -1;
	while (abs(ok - ng) > 1)
	{
		ll mid = abs(ok + ng) / 2;
		ll cnt = 0;
		rep(i, n)cnt += max(0LL, a[i] - mid / f[i]);
		if (cnt <= k)ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
}
