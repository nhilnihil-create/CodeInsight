#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file 
//#include <ext/pb_ds/tree_policy.hpp> 
#define int long long
#define pb push_back
#define ff first
#define ss second
#define ii insert
#define ld long double
#define ppb pop_back
#define nuenxfiu ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define input freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define TT int testcases;cin>>testcases;while(testcases--)
#define mk make_pair
#define MAX ((int)2e9+17)
#define N 200005
#define mod ((int)1e9+7)
#define MOD 1000003
//int fact[1000007]={0};
int fpow(int n, int k, int p = mod) {int r = 1; while(k > 0) {if (k & 1) r = r * n%p; n = n * n%p; k = k >> 1;} return r;}
int expo(int x,int y){ int res=1; while(y) {if(y%2) res=(res*x%mod)%mod; x=(x*x)%mod; y/=2; } return res;}
int sub(int a, int b) {return (a%mod - b%mod + mod)%mod;}
int mul(int a, int b) {return ((a%mod)*(b%mod) + mod)%mod;}
int inv(int x) {return expo(x, mod-2);}
using namespace std;





void solve()
{
	int n;
	cin>>n;
	
	int a[n];
	int x=0;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		x^=a[i];
	}
	
	for(int i=0;i<n;i++)
	cout<<(x^a[i])<<" ";
	cout<<endl;
	
}
signed main()
{
    
	nuenxfiu
	//TT
	solve();
     return 0;
}