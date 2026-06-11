#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 100005;
const ll MOD = 1e9+7;
vector<int> G[MAX_N];
ll N,K;

ll dfs(int x, int from)
{
	ll c = K-1;
	if (from != -1) c--;
	ll res = 1;
	rep(i,G[x].size())
	{
		if (G[x][i] == from) continue;
		res *= c;
		c--;
		res %= MOD;
	}
	rep(i,G[x].size())
	{
		if (G[x][i] == from) continue;
		res *= dfs(G[x][i],x);
		res %= MOD;
	}
	return res;
}

int main()
{
	cin >> N >> K;
	rep(i,N-1)
	{
		int a,b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	ll ans = K * dfs(0,-1);
	ans %= MOD;
	cout << ans << endl;
	return 0;
}