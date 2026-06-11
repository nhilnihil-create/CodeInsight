#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define pb push_back
#define fi first
#define se second
#define vii vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define pq priority_queue<int>
#define test int tcase; cin>>tcase; for(int tc = 1; tc <= tcase; tc++)
#define inp(a,n,f) int a[n+f];for(int hh=f;hh<n+f;hh++)cin>>a[hh];
#define prdec(k) cout<<fixed<<setprecision(k);
#define mem(a,k) memset(a,k,sizeof(a))
#define ub upper_bound
#define lb lower_bound
#define mii map<int,int>
#define all(v) v.begin(),v.end()
#define inf LLONG_MAX


signed main()
{
	#ifndef ONLINE_JUDGE
   		freopen("input.txt","r",stdin);
   		freopen("output.txt","w",stdout);   
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

   	int n,k,i,ret=0,ch=0;
	cin>>n>>k;
	inp(p,n,1);
	inp(cost,n,1);
	for(i=1;i<=n;i++)
		if(cost[i]<=0)
			ch++;
	if(ch==n)
	{
		ret=-inf;
		for(i=1;i<=n;i++)
			ret=max(ret,cost[i]);
		cout<<ret;
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		int node=i,sz=0,res=0;
		int h[n+1]={0};
		while(h[node]==0)
		{
			h[node]++;
			sz++;
			node=p[node];
		}
		if(sz>k)
		{
			int cnt=0,ans=0;
			node=i;
			while(cnt!=k)
			{
				ans+=cost[p[node]];
				res=max(res,ans);
				node=p[node];
				cnt++;
			}
		}
		else
		{
			int cnt=0,ans=0;
			node=i;
			while(cnt!=sz)
			{
				ans+=cost[p[node]];
				res=max(res,ans);
				node=p[node];
				cnt++;
			}
			if(ans>=0)
			{
				int anss=0,mx=0;
				int ans1=ans*(k/sz);
				int kk=k%sz;
				cnt=0;
				node=i;
				while(cnt!=kk)
				{
					anss+=cost[p[node]];
					mx=max(mx,anss);
					node=p[node];
					cnt++;
				}
				ans1+=mx;
				res=max(res,ans1);
				cnt=0,node=i,anss=0,mx=0;
				int ans2=ans*max(0LL,k/sz-1);
				while(cnt!=sz)
				{
					anss+=cost[p[node]];
					mx=max(mx,anss);
					node=p[node];
					cnt++;
				}
				ans2+=mx;
				res=max(res,ans2);
			}
		}
		ret=max(ret,res);
	}
	cout<<ret;
	return 0;
}
