#include <bits/stdc++.h>
   
using namespace std;
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define vll vector<long long>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define deb(x) cout << #x << "=" << x << endl
#define F(i,a,b) for(ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) F(i,0,n-1)cin>>a[i]
#define vi vector<int>
#define out(a,n) F(i,0,n-1)cout<<a[i]<<" ";cout<<endl
#define mod 998244353
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define int long long

const int N = 1e5 + 5;
 	int connected;
	int par[N], sz[N];
 
struct DSU
{
 
	void init(int n) 
	{
		for(int i=1;i<=n;i++)
		{
			par[i]=i;
			sz[i]=1;
		}
		connected=n;
	}
 
	int getPar(int k)
	{
		while(k!=par[k])
		{
			par[k]=par[par[k]];
			k=par[k];
		}
		return k;
	}
 
	int getSize(int k)
	{
		return sz[getPar(k)];
	}
 
	void unite(int u, int v)
	{
		int par1=getPar(u), par2=getPar(v);
 
		if(par1==par2)
			return;
 
		connected--;
 
		if(sz[par1]>sz[par2])
			swap(par1, par2);
 
		sz[par2]+=sz[par1];
		sz[par1]=0;
		par[par1]=par[par2];
	}
};
 DSU dsu;

void solve()
{   
    
    
    int n,m;
    cin>>n>>m;
    dsu.init(n);
    
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        dsu.unite(a,b);
    }
    cout<<connected-1;
    
    
}

int32_t main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t=1;
//	cin>>t;
	while(t--)solve();
	    
   
}