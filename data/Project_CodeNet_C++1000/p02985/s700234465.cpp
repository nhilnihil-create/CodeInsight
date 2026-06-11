#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll dis1[100006],dis2[100006],dis0[100006];;
const ll MOD = 1e9+7;
vector<int> G[100006];
int n,k;

ll ans;
void dfs(int idx,int p=100005,int pp=100005)
{
	ll x = k - dis1[p] - dis0[pp] - dis0[p];
	ans = ans * x % MOD;
	dis0[idx] ++ ;
	dis1[p]++;
	for(auto &i:G[idx])
	{
		if(i==p)continue;
		dfs(i,idx,p);
	}
	
		

}

int main()
{
	ans = 1;
	cin >> n >> k;
	for(int i = 0;i<n-1;i++)
	{
		int x,y;
		cin >> x >> y;
		x--;y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(0);
	cout << ans << endl;

	
}
