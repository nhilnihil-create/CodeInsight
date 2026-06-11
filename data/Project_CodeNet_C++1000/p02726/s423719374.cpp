#include <bits/stdc++.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define deb(x) cout<<#x<<"="<<x<<endl;
#define endl '\n'
#define M 1000000007
#define int long long
#define INF 1e18
#define max_n 2005

using namespace std;

vector<ll> g[max_n];
ll n, x, y;

void solve()
{
	cin >> n >> x >> y;
	for (int i = 1; i < n; ++i)
	{
		g[i].push_back(i + 1);
		g[i + 1].push_back(i);
	}
	g[x].push_back(y);
	g[y].push_back(x);
	vector<ll> ans(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		queue<ll> q;
		vector<ll> d(n + 1, 0LL);
		q.push(i);
		bool vis[n + 1];
		memset(vis, false, sizeof vis);
		vis[i] = true;
		while (!q.empty())
		{
			ll cur = q.front();
			q.pop();
			for (ll c : g[cur])
			{
				if (!vis[c])
				{
					d[c] = d[cur] + 1LL;
					q.push(c);
					vis[c] = true;
				}
			}
		}
		for (int i = 0; i < n + 1; ++i)
		{
			ans[d[i]]++;
		}
	}
	for (int i = 1; i <= n - 1; ++i)
	{
		cout << ans[i] / 2 << endl;
	}
}

int32_t main()
{
	IOS
	ll T = 1;
	// cin>>T;
	for (ll i = 1; i <= T; ++i)
	{
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}