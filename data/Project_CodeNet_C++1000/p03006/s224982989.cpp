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
	int n; cin >> n;
	vector<ll> x(n), y(n);
	rep(i, n)cin >> x[i] >> y[i];
	ll res = n;
	rep(i, n)rep(j, n)
	{
		if (i == j)continue;
		ll p = x[i] - x[j];
		ll q = y[i] - y[j];
		ll cnt = n;
		rep(a, n)rep(b, n)
		{
			if (x[a] == x[b] - p && y[a] == y[b] - q)--cnt;
		}
		res = min(res, cnt);
	}
	cout << res << endl;
}