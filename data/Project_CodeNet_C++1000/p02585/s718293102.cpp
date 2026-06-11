#include<bits/stdc++.h>
#define ll long long 
#define MM(arr,x) memset(arr,x,sizeof(arr))
#define INF 0x3f3f3f3f
#define Maxn 1e5+10
#define M 5050
using namespace std;
ll dis[M][M],sco[M],step[M];
int vis[M],pos[M];
int main()
{
	ios::sync_with_stdio(0);
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>pos[i];
	for(int i=1;i<=n;i++)
		cin>>sco[i];
	for(int i=1;i<=n;i++)
	{
		MM(vis,0);
		int t=pos[i],idx=0;
		while(!vis[t])
		{
			vis[t] = 1;
			idx++;
			dis[i][idx]=dis[i][idx-1]+sco[t];
			t=pos[t];
		}
		step[i]=idx;
	}
	ll res=-1e18;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=step[i];j++)
		{
			ll t=dis[i][j];
			if(k<j) break;
			if(dis[i][step[i]]>=0)
				t+=(k-j)/step[i]*dis[i][step[i]];
			res = max(res,t);
		}
	}
	cout<<res;
	return 0;
} 