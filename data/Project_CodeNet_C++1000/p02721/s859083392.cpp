#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 1000010
using namespace std;
ll n,k,c,mst=0,sz,segt[N][2];
string s;
vector<ll> num[N];
void update(ll x,ll v,ll verd)
{
	segt[x][verd]=v;
	x/=2;
	while(x)
	{
		segt[x][verd]=max(segt[x][verd],v);
		x/=2;
	}
	return;
}
ll getans(ll l,ll r,ll verd)
{
	ll ret=-LINF;
	while(l<r)
	{
		if(l%2==1)
		{
			ret=max(ret,segt[l][verd]);
		}
		if(r%2==1)
		{
			ret=max(ret,segt[r-1][verd]);
		}
		l=(l+(ll)1)>>(ll)1;
		r>>=(ll)1;
	}
	return ret;
}
int main(){
	ll i,v;
	cin>>n>>k>>c>>s;
	s="!"+s+"!";
	for(i=1;i<=n;i++)
	{
		if(s[i]=='o')
		{
			mst++;
			i+=c;
		}
	}
	if(mst>k)
	{
		return 0;
	}
	for(sz=1;sz<2*(n+1);sz<<=1);
	memset(segt,-127,sizeof(segt));
	sz>>=(ll)1;
	update(sz,0,0);
	for(i=1;i<=n;i++)
	{
		v=(s[i]=='o')+getans(sz,max(sz+1,sz+i-c),0);
		update(sz+i,v,0);
	}
	update(sz+n+1,0,1);
	for(i=n;i>=1;i--)
	{
		v=(s[i]=='o')+getans(min(sz+n+1,sz+i+c+1),sz+n+2,1);
		update(sz+i,v,1);
	}
	for(i=1;i<=n;i++)
	{
		if(s[i]=='o')
		{
			v=getans(sz,max(sz+1,sz+i-c),0);
			if(v+getans(min(sz+n+1,sz+i+c+1),sz+n+2,1)==k-1)
			{
				num[v].push_back(i);
			}
		}
	}
	for(i=0;i<=k;i++)
	{
		if(num[i].size()==1)
		{
			cout<<num[i][0]<<endl;
		}
	}
	return 0;
}