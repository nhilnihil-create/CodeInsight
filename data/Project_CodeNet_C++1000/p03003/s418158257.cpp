#include<bits/stdc++.h>
#define ll          long long int
#define lld          long double
#define pb          push_back
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define vec         vector<ll>
#define all(a)     (a).begin(),(a).end()
#define F           first
#define S           second
#define mod         1000000007
#define rep(i,a,b)	for(ll  i=a;i<b;i++)
#define repi(i,a,b)	for(ll  i=a;i<=b;i++)
#define per(i,a,b)  for(ll i=a;i>=b;i--)
#define mp          make_pair
#define mit         map<ll,ll>::iterator
#define sit         set<ll>::iterator
#define pit         pair<ll,ll>::iterator
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;
ll xo(ll x, ll y) 
{ 
   return (x | y) & (~x | ~y); 
}  
ll bin_Expo(ll x,ll n)
{
		if(x==0)
		return 0;
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return bin_Expo(x*x,n/2);
    else                             //n is odd
        return x*bin_Expo(x*x,(n-1)/2);
}
ll mod_Expo(ll x,ll n,ll M)
{
		if(x==0)
		return 0;
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return mod_Expo((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*mod_Expo((x*x)%M,(n-1)/2,M))%M;
 
}
ll NcR(int n, int r) 
{ 
    ll p = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
            ll m=__gcd(p, k); 
            p /= m; 
            k /= m; 
            n--; 
            r--; 
        } 
    } 
    else
        p = 1; 
    return p;
}
bool prime_check(ll x)
{
    bool prime = (x >= 2);
    for (ll i = 2; i * i <= x; i++) 
    {
        if (x % i == 0) 
        {
            prime = false;
            break;
        }
    }
    return prime;
}
ll logg(ll base,ll x)
{
    return (ll)(log(x)/log(base));
}
ll n,m,s[2005],t[2005],dp[2005][2005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
    while(TESTS--)
    {
    	ll i,j,ans,x,sum,c,k,w,h,y;
    	cin>>n>>m;
    	repi(i,1,n)
    	cin>>s[i];
    	repi(i,1,m)
    	cin>>t[i];
    	memset(dp,0,sizeof(dp));
    	repi(i,1,n)
    	{
    		repi(j,1,m)
    		{
    			dp[i][j]=(dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+mod)%mod;
    			if(s[i]==t[j])
    			dp[i][j]=(dp[i][j]+1+dp[i-1][j-1])%mod;
			}
		}
		cout<<1+dp[n][m];
    } 
	return 0;
}