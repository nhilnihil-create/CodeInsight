#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file 
//#include <ext/pb_ds/tree_policy.hpp> 
#define int long long
#define pb push_back
#define ff first
#define ss second
#define ii insert
#define ld long double
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
#define ppb pop_back
#define nuenxfiu ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define input freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define TT int testcases;cin>>testcases;while(testcases--)
#define mk make_pair
#define MAX ((int)2e9+17)
#define mod ((int)1e9+7)
#define MOD 1000003
//int fact[1000007]={0};
#define N (int)1e6+10
int fpow(int n, int k, int p = mod) {int r = 1; while(k > 0) {if (k & 1) r = r * n%p; n = n * n%p; k = k >> 1;} return r;}
int expo(int x,int y){ int res=1; while(y) {if(y%2) res=(res*x%mod)%mod; x=(x*x)%mod; y/=2; } return res;}
int sub(int a, int b) {return (a%mod - b%mod + mod)%mod;}
int mul(int a, int b) {return ((a%mod)*(b%mod) + mod)%mod;}
int inv(int x) {return expo(x, mod-2);}
using namespace std;



void solve()
{
	int n,m;
	cin>>n>>m;
	
	int h[n+1];
	
	vector<int>v[n+1];
	
	for(int i=1;i<n+1;i++)
	cin>>h[i];
	
	int a;
	int b;
	
	while(m--)
	{
		cin>>a>>b;
		v[a].pb(h[b]);
		v[b].pb(h[a]);
	}
	
	int cnt=0;
	
	for(int i=1;i<=n;i++)
	{
		if(v[i].size()==0)
		cnt++;
		else
		{
		sort(all(v[i]));
		if(v[i].back()<h[i])
		cnt++;
		}
	}
	
	//for(int i=1;i<=n;i++)
	//{
		//for(int j=0;j<v[i].size();j++)
		//cout<<v[i][j]<<" ";
		//cout<<endl;
//	}
	
	cout<<cnt<<endl;
	
}
signed main()
{
    
	nuenxfiu
	//TT
	solve();
     return 0;
}