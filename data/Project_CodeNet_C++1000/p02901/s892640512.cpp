#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define mod 1000000007ll
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define db(x) cout << #x << " = " << x << '\n'
#define sep cout << "\n********************************************\n"
#define fast  ios_base::sync_with_stdio(false), cin.tie(NULL)
ll n, m;
pll cost[1003];
ll dp[2][1 << 12];
int main(int argc, char const *argv[])
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		ll sz;
		cin >> cost[i].x >> sz;
		ll mask = 0;
		while (sz --)
		{
			ll id;
			cin >> id;
			id --;
			mask |= (1ll << id);
		}
		cost[i].y = mask;
	}
	memset(dp, -1, sizeof(dp));
	dp[1][0] = 0;
	for (int i = 0; i < m; ++i)
	{
		ll f = (i & 1);
		for (int j = 0; j < (1 << n); ++j)
		{
			dp[f][j] = dp[1 - f][j];
		}
		for (int j = 0; j < (1 << n); ++j)
		{
			if (dp[1 - f][j] == -1)
				continue;
			if (dp[f][j | cost[i].y] == -1)
				dp[f][j | cost[i].y] = dp[1 - f][j] + cost[i].x;
			else
				dp[f][j | cost[i].y] = min(dp[f][j | cost[i].y], dp[1 - f][j] + cost[i].x);
		}
	}
	cout << dp[(m - 1) & 1][(1 << n) - 1];
	return 0;
}