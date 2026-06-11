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
	vector<ll> memo(3, 0);
	ll MOD = 1e9 + 7;
	ll res = 1;
	rep(i, n)
	{
		int a; cin >> a;
		ll cnt = 0;
		rep(i, 3)
		{
			if (memo[i] == a)++cnt;
		}
		res *= cnt;
		res %= MOD;
		rep(i, 3)
		{
			if (memo[i] == a)
			{
				++memo[i];
				break;
			}
		}
	}
	cout << res << endl;
}