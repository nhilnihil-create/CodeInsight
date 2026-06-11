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

int h,w,m,a[300005],b[300005],p1,p2;
set<pii> st;

signed main()
{
 	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	cin>>h>>w>>m;
	vector<int> l,r;
	int x,y;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		st.insert(mk(x,y));
		a[x]++;
		b[y]++;
		if(a[x]>p1)
		{
			l.clear();
			p1=a[x];
		}
		if(a[x]==p1)
			l.pb(x);
		if(b[y]>p2)
		{
			r.clear();
			p2=b[y];
		}
		if(b[y]==p2)
			r.pb(y);
	}
	for(i=0;i<l.size();i++)
	{
		for(j=0;j<r.size();j++)
		{
			if(st.find(mk(l[i],r[j]))==st.end())
			{
				cout<<p1+p2<<endl;
				return 0;
			}
		}
	}
	cout<<p1+p2-1<<endl;
	return 0;
}
