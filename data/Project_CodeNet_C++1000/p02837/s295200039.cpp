#include <bits/stdc++.h>

#ifndef M_PI
#define M_PI 3.14159265358979
#endif
#define deg_to_rad(deg) (((deg) / 360) * 2 * M_PI)
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)

using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

int main()
{
	ll i, j, k;
	ll N;
	cin >> N;
	vector<vll> X, Y;
	for (i = 0; i < N; i++)
	{
		ll a;
		cin >> a;
		vll xi, yi;
		for (j = 0; j < a; j++)
		{
			ll xij, yij;
			cin >> xij >> yij;
			xij--;
			xi.push_back(xij);
			yi.push_back(yij);
		}
		X.push_back(xi);
		Y.push_back(yi);
	}
	ll ans = 0;
	ll honest = 0;
	for (honest = 0; honest < (1 << N); honest++)
	{
		// cout << bitset<3>(honest) << endl;
		bool ok = true;
		for (i = 0; i < N; i++)
		{
			if (honest & 1 << i)
			{
				for (j = 0; j < X[i].size(); j++)
				{
					ll x = X[i][j], y = Y[i][j];
					if (y)
					{
						if (!(honest & 1 << x))
						{
							ok = false;
						}
					}
					else
					{
						if (honest & 1 << x)
						{
							ok = false;
						}
					}
				}
			}
		}
		if (!ok)
		{
			continue;
		}
		else
		{
			ans = max(ans, (ll)__builtin_popcountll(honest));
		}
	}
	cout << ans << endl;

	return 0;
}
