#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define pf push_front
#define mp make_pair
#define mod 1000000007
#define vll vector<ll>
#define inf 1e12
#define pll pair<ll,ll>
#define ff first 
#define ss second 
#define PI acos(-1)
#define prm 998244353
#define endl '\n'
using namespace std;
using namespace __gnu_pbds; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//cout << fixed << setprecision(0)
/*
ll power(ll x,ll y)
{
	ll res=1;
	while(y>0)
	{
		if(y%2==1)res=(res*x)%mod;
		y=y/2;
		x=(x*x)%mod;
	}
	return res;
}
ll inv(ll a) 
{
return power(a,mod-2);
}
 
ll fact[2000007];
ll inr[2000007];
void pre()
{
	fact[0]=1;
	for(ll i=1;i<=2000005;i++)fact[i]=(fact[i-1]*i)%mod;
	inr[0]=1;
	for(ll i=1;i<=2000005;i++)inr[i]=inv(fact[i]);
}
 
ll ncr(ll n,ll r)
{
	ll a=(fact[n]*inr[r])%mod;
	ll b=(a*inr[n-r])%mod;
	return b;
}
 
ll spf[10000050];
void sieve()
{
	for(ll i=2;i*i<=10000030;i++)
	{
		if(spf[i]==0)
		{
			for(ll j=i+i;j<=10000030;j+=i)
			{
				if(spf[j]==0)
				{
					spf[j]=i;
				}
			}
		}
	}
}
*/

int main()
{
    fastio; 
    //sieve();
    //pre();
    ll T=1;
    //cin>>T;  
    while(T--)
    {
    int n, k;
    cin >> n >> k;
  	vll p(n), c(n);
  	for(ll i=0;i<n;i++) 
	{
    cin >> p[i];
    p[i]--;
  	}
 
  	for(ll i=0;i<n;i++) cin >> c[i];
 
  	ll ans = -1e18;
  	ll vis[n];
  	for(ll i=0;i<n;i++)vis[i]=0;
  	for(ll si=0;si<n;si++)
	{
	//if(vis[si]==1)continue;
    ll x = si;
    vll s;
    ll total = 0;
    while (1) 
	{
      total += c[x];
      s.pb(c[x]);
      vis[x]=1;
      x = p[x];
      if (x == si) break;
    }
    
    ll cur = 0;
    int m = s.size();
    for(ll i=0;i<m;i++)
	{
      if (i + 1 > k) break;
      cur += s[i];
      ll t = cur;
      if (total > 0) 
	  t += ((k - (i + 1)) / m) * total;
      ans = max(ans, t);
    }
  	} 
  	cout << ans << endl;
	}
}