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
#define P pair<ll, ll>
#define V vector<ll>
#define C vector<char>
#define vpiii vector<piii>
#define vpll vector<pll>
#define vplll vector<plll>
#define mod 1000000007
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)


int power(ll x, unsigned int y)  
{  
	ll p=mod;
    ll res = 1;      
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0)  
    { 
        if (y & 1)  
            res = (res*x) % p;   
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
}  
ll gcdExtended(ll a, ll b, ll *x, ll *y)  
{  
    // Base Case  
    if (a == 0)  
    {  
        *x = 0;  
        *y = 1;  
        return b;  
    }  
  
    ll x1, y1; // Tor store results of recursive call  
    ll gcd = gcdExtended(b%a, a, &x1, &y1);  
  
    // Update x and y using results of  
    // recursive call  
    *x = y1 - (b/a) * x1;  
    *y = x1;  
  
    return gcd;  
}  

int main()
{
	ll n,m;
	cin>>n>>m;
	ll d[n],b[n];
	vector<pair<ll,ll>>v;
	for(int i=0;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	ll ans=0,cnt=0;
	priority_queue<ll>q;
	sort(v.begin(),v.end());
	for(int i=1;i<=m;i++)
	{
		while(cnt<n&&v[cnt].fi<=i)
		{
			q.push(v[cnt].se);
			cnt++;
			//cout<<i<<" "<<v[cnt].se<<" "<<cnt<<endl;
		}
		if(!q.empty())
		{
			ans+=q.top();
			q.pop();
		}

	}
	cout<<ans<<endl;



}
