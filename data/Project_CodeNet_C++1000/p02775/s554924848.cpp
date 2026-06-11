//Catchharsh
#include<bits/stdc++.h>
#define ll long long int 
#define ld long double
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define F first
#define S second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define pb push_back
#define endl '\n'
#define see(x) cout<<#x<<" = "<<x<<endl
const ll MOD = 1e9+7;
const ll INF = 1011111111;
const ll LLINF = 1000111000111000111LL;
const ld EPS = 1e-10;
const ld PI = 3.14159265358979323;
using namespace std;
ll power (ll base,ll exponent)
{
    ll ans=1;
    //base%=MOD;
    //exponent%=(MOD-1);
    while(exponent!=0)
    {
      if(exponent&1) ans=(1LL*ans*base);
      base=(1LL*base*base);
      exponent>>=1;
    }
    return ans;
}
ll num[1000005];
ll dp[1000005][2];
ll solve(ll idx,ll carry)
{
   if(idx<0) return carry;
   if(dp[idx][carry]!=-1) return dp[idx][carry];
   if(num[idx]==9&&carry==1) return dp[idx][carry]=solve(idx-1,1);
   return dp[idx][carry]=min((num[idx]+carry+solve(idx-1,0)),(10-num[idx]-carry+solve(idx-1,1)));
}
int32_t main()
{   
     IOS;
     string s;
     cin>>s;
     memset(dp,-1,sizeof dp);
     ll n=s.length();
     for(ll i=0;i<n;i++)
      num[i]=s[i]-'0';
    cout<<solve(n-1,0);
     
     
     
     cerr <<endl<< "Time elapsed : " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';             
}