#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
typedef pair<double,double> pdd;
const double EPS=1e-9;
#define debug(c) (cerr<<#c<<": "<<c<<"\n")
#define fi first
#define se second
#define mod 1000000007
#define pi acos(-1)
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
map<ll,set<ll> > row;
map<ll,set<ll> > col;
set<ll> rval;
map<ll,ll> rcnt;
int main()
{
	ios;
	ll h,w,m,x,y,maxr=0,maxc=0,len,i,j;
	cin>>h>>w>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		row[x].insert(y);
		col[y].insert(x);
		ll l=row[x].size();
		maxr=max(maxr,l);
		l=col[y].size();
		maxc=max(maxc,l);
	}
	for(auto it=row.begin();it!=row.end();it++)
	{
		if((it->se).size()==maxr)
			rval.insert(it->fi);
	}
	len=0;
	for(auto it=col.begin();it!=col.end();it++)
	{
		if((it->se).size()==maxc)
		{
			for(auto it1=(it->se).begin();it1!=(it->se).end();it1++)
				rcnt[*it1]++;
			len++;
		}	
	}
	for(i=1;i<=h;i++)
	{
		if(rval.find(i)!=rval.end())
		{
			if(rcnt[i]!=len)
			{
				cout<<maxr+maxc<<endl;
				exit(0);
			}
		}
	}
	cout<<maxr+maxc-1<<endl;
}
