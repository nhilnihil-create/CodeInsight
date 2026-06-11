/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~


#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
vector<vector<pair<int, int> > > v;
int colour[maxn];
void dfs(int node, int pre, int t)
{
	int ct=1;
	for(auto i: v[node])
	{
		int next=i.fi;
		if(next==pre)
			continue;
		if(ct==t)
			++ct;
		colour[i.se]=ct;
		dfs(next,node,ct);
		++ct;
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0,k=0,x=0,y=0;
    cin>>n;
    v.resize(n);
    for(int i=0;i+1<n;++i)
    {
    	cin>>x>>y;
    	--x;--y;
    	v[x].pb({y,i});
    	v[y].pb({x,i});
    	k=max({k,(int)v[x].size(),(int)v[y].size()});
    }
    cout<<k<<endl;
    dfs(0,-1,-1);
    for(int i=0;i+1<n;++i)
    {
    	cout<<colour[i]<<endl;
    }
}