#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, P> T;

const ll mod = 1000000007;
const ll INF = 100000010000;

ll N, K, H[310], dp[310][310];
vector<ll> height;

ll ans;

ll pow_mod(ll x, ll y)
{
	if (y == 0) return 1;
	if (y % 2 == 1)
	{
		return x * pow_mod(x, y - 1) % mod;
	}
	else
	{
		ll half = pow_mod(x, y / 2);
		return half * half % mod;
	}
}

ll div_mod(ll x)
{
	return pow_mod(x, mod - 2);
}

/*ll sum_bit(ll i)
{
	ll s = 0;
	while (i > 0)
	{
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add_bit(ll i, ll x)
{
	while (i <= 2 * N + 10)
	{
		bit[i] += x;
		i += i & -i;
	}
}*/

void init()
{
	cin >> N >> K;
	height.push_back(0);
	for (int i = 1; i <= N; i++)
	{
		cin >> H[i];
		height.push_back(H[i]);
	}
	sort(height.begin(), height.end());
}

void output()
{
	cout << ans << endl;
}



void solve()
{
	for (ll used = 0; used <= K; used++)
	{
		for (ll i = 0; i <= N + 1; i++)
		{
			dp[used][i] = INF;
		}
	}

	dp[0][0] = 0;
	
	for (ll used = 0; used <= K; used++)
	{
		for (ll i = 1; i <= N + 1; i++)
		{
			for (ll j = 0; j < i; j++)
			{
				if (used < i - j - 1) continue;
				dp[used][i] = min(dp[used - (i - j - 1)][j] + max(H[i] - H[j], (ll)0), dp[used][i]);
			}
		}
	}

	ans = INF;

	for (ll i = 0; i <= K; i++)
	{
		ans = min(ans, dp[K][N + 1]);
	}
}

int main()
{
	init();

	solve();

	

	output();

	cin >> N;
}