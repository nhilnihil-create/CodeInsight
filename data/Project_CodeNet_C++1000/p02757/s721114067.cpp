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
	int n, p; cin >> n >> p;
	string s; cin >> s;
	ll res = 0;
	if (p == 2 || p == 5)
	{
		rrep(i, n)if ((s[i] - '0') % p == 0)res += i + 1;
		cout << res << endl;
	}
	else
	{
		int f = 1;
		int r = 0;
		vector<ll> v(p, 0);
		rrep(i, n)
		{
			r = (r + f * (s[i] - '0')) % p;
			++v[r];
			f = (f * 10) % p;
		}
		res = v[0];
		rep(i, p)res += v[i] * (v[i] - 1) / 2;
		cout << res << endl;
	}
}
