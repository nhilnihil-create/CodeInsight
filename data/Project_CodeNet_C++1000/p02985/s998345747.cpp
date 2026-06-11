#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 100005;
const ll MOD = 1e9+7;
ll ans = 1;
vector<int> G[MAX_N];
bool visit1[MAX_N],visit2[MAX_N];
int pa[MAX_N];
ll ch[MAX_N]; //子の数

void dfs_pa(int x)
{
	visit1[x] = true;
	rep(i,G[x].size())
	{
		if (!visit1[G[x][i]])
		{
			pa[G[x][i]] = x;
			dfs_pa(G[x][i]);
		}
	}
	return;
}

void dfs(int x, int c, int fcnt, int d)
{
	visit2[x] = true;
	ans = (ans * c) % MOD;
	//cout << x << " " << c << endl;
	int cnt = 0;
	rep(i,G[x].size())
	{
		if (!visit2[G[x][i]])
		{
			dfs(G[x][i],c-1-cnt+fcnt+(d>=2),cnt,d+1);
			cnt++;
		}
	}
	return;
}


int main()
{
	ll N,K;
	cin >> N >> K;
	rep(i,N-1)
	{
		int a,b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	ch[0] = G[0].size();
	rep(i,N-1)
	{
		ch[i+1] = G[i+1].size() - 1;
	}
	//pa[0] = 0;
	//dfs_pa(0);
	dfs(0,K,0,0);
	cout << ans << endl;
	return 0;
}