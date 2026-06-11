#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define pll  pair <long long,long long>
#define ss second
#define ff first
#define inf 9223372036854775807
#define maa 1000000007
#define ld long double
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define bug(x) cout << #x <<": " << x << '\n';
const ll N=200001 ;
ll  power(ll  i,ll  j)
{
    if(j==0)
    return 1 ;
    ll t=power(i,j/2)%maa ;
    if(j%2==0)
    return (t%maa*t%maa)%maa ;
    else
    return ((t%maa*t%maa)%maa*(i%maa)%maa)%maa ;
}
int main()
{
   fast ;

   ll n,k ;
   cin>>n>>k ;

   ll dp[k+1] ;
   dp[k]=1 ;

   for(ll i=k-1;i>=1;i--)
   {
       ll x=k/i ;
       dp[i]=power(x,n) ;
       for(ll j=2*i;j<=k;j+=i)
       {
           dp[i]-=dp[j] ;
           dp[i]%=maa ;
           dp[i]+=maa ;
           dp[i]%=maa ;
       }
   }
   ll ans=0 ;
   for(ll i=1;i<=k;i++)
   {
       ans+=(dp[i]*i)%maa ;
       ans%=maa ;
   }
   cout<<ans ;





}

