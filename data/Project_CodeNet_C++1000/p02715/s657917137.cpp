//@@@@@@@@@@ JAI BAJRANG BALI @@@@@@@@@

// COMPILE BY:) NAMAN


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define maxn 10000001
#define endl "\n"
#define inf INT_MAX
#define vec vector <ll>
#define mps map <ll,ll>
#define ppl vector<pair<ll,ll>> 
#define fi first
#define si second
#define pr pair<ll,ll> 
#define mvec map<ll,vector <ll>>
#define all(v) v.begin(),v.end()
#define infi LLONG_MAX
#define pi 3.141592653
#define ninf INT_MIN
#define ninfi LLONG_MIN
#define lbn lower_bound
#define ubn upper_bound
#define memset(a,b) memset(a,(b),sizeof(a))
ll modexpo(ll a, ll b, ll c)  
{  
    if (a == 0)  
        return 0;  
    if (b == 0)  
        return 1;  
    ll y;  
    if (b % 2 == 0) {  
        y = modexpo(a, b / 2, c);  
        y = (y * y) % c;  
    }  
    else {  
        y = a % c;  
        y = (y * modexpo(a, b - 1, c) % c) % c;  
    }  
  
    return y;
}  
  
  

  
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vec dp(k+1);
    for(ll i=k;i>=1;i--)
    {
    	ll q=modexpo(k/i,n,mod);
    	// cout<<q<<endl;
    	q%=mod;
    	dp[i]=q;

    }

    // for(ll i=1;i<=k;i++)
    // 	cout<<dp[i]<<" ";

    for(ll i=k;i>=1;i--)
    {
    	for(ll j=2*i;j<=k;j+=i)
    		dp[i]-=dp[j];
    }
    ll sum=0;

    for(ll i=1;i<=k;i++)
    {
    	dp[i]=i*dp[i];
    	dp[i]%=mod;
    	sum+=dp[i];
    	sum%=mod;
    }

    cout<<sum<<endl;


return 0;
}
