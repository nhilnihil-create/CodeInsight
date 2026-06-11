#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define frw(i, a, b) for(int i = a; i < b; i++)
#define fi first
#define se second
#define pb push_back
#define in insert
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) int(a.size())
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<ll, ll>
#define plll pair<ll, pll>
#define vpii vector<pii>
#define vpiii vector<piii>
#define vpll vector<pll>
#define vplll vector<plll>
#define mod 1000000007

int modInverse(ll a, ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
    if (m == 1) 
      return 0; 
    while (a > 1) 
    { 
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
    return x; 
} 
 ll dp[200000];

int po(ll x,ll y)
{
	ll res=1;
	while(y>0)
	{
		if(y&1)
			res=(res*x)%mod;
		y=y>>1;
		x=(x*x)%mod;
	}
	return res;
}

ll nck(ll n, ll k) {
	ll ans=1;
	for(int i=1; i<=k; ++i)
		ans=ans*(n-i+1)%mod*dp[i]%mod;
	return ans;
}
	int main(){
    string s; cin >> s; 
    int n = s.size();
    reverse(all(s));
 
    vector<vi> dp(n+1,vi(2,(1<<29)));
    dp[0][0] = 0;
    for(int i=0;i<n;i++){
        int x = s[i] - '0';
        dp[i+1][0] = min(dp[i][0]+x, dp[i][1]+x);
        dp[i+1][1] = min(dp[i][0]+1+10-x, dp[i][1]-1+1+10-x-1);
    }
 
    cout << min(dp[n][0], dp[n][1]) << endl;
    
}
