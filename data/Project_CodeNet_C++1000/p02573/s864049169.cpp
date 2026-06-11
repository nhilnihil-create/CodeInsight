/*
	Name:
	Author: xiaruize
	Date:
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define MOD 1000000007
#define ALL(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define form(i,j,n) for(int i=int(j);i<=int(n);i++)
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define pis pair<int,string>
#define sec second
#define ll long long
#define fir first
#define sz(a) int((a).size())

int fa[200005];
int cntf[200005];
int ans=0;
int get(int x)
{
	if(x==fa[x])
		return x;
	return fa[x]=get(fa[x]);
}

void _merge(int a,int b)
{
	int x=get(a),y=get(b);
	if(x==y)
		return ;
	fa[x]=y;
	cntf[y]+=cntf[x];
	cntf[x]=0;
	ans=max(ans,cntf[y]);
}

signed main()
{
 	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n+1;i++)
	{
		fa[i]=i;
		cntf[i]=1;
	}
	int a,b;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		_merge(a,b);
	}
	if(ans==0)
		ans=1;
	cout<<ans<<endl;
	return 0;
}
