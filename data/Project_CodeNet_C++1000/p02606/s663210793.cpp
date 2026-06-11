#include "bits/stdc++.h"
using namespace std;
#define int long long
#define repp(i,a,b) for(int i = a ; i < b ; i++)
#define rep(i,n) repp(i,0,n)
#define endl '\n'
#define pb push_back
#define mod 1000000007
#define reppr(i,a,b) for(int i = a-1 ; i>=b ; i--)
#define repr(i,n) reppr(i,n,0)
#define ff first
#define ss second
#define all(n) n.begin(),n.end()
#define SORT(a) sort(all(a));
#define REVERSE(a) reverse(all(a));

int powmod(int x,int y) 
{ 
    if (y == 0) return 1; 
    int p = powmod(x, y/2) % mod; 
    p = (p * p) % mod;   
    return (y%2 == 0) ? p : (x * p) % mod; 
}
 
int inverse(int a) 
{ 
   return powmod(a,mod-2); 
}

void solve();
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t = 1;
	// cin >> t;
	while(t--) solve();
}

void solve()
{
	int l , r , d;
	cin >> l >> r >> d;
	cout << r/d - (l-1)/d << endl;	
}