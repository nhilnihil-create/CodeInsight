#include <bits/stdc++.h>
 
 
using namespace std;
 
typedef long long ll;
 
#define MOD 998244353
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>b;--i)
#define vi vector<int>
#define vl vector<ll>
#define ld long double
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define fix(f,n) fixed<<setprecision(n)<<f
#define all(x) x.begin(),x.end()
 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
ll newmod(ll a,ll b)
 {
  return ((a%b)+b)%b;
}
 
 
ll powM(ll a,ll b,ll m )
{ 
  a%=m;
  ll ans=1;
  while(b)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }
 
return ans;
}
 
ll pow(ll a,ll b)
{ 
  
  ll ans=1;
  while(b)
  {
    if(b&1)ans=ans*a;
    a=a*a;
    b>>=1;
  }
 
return ans;
}
 
 
 
/*const int N=200000;
 
ll fac[N+1];
ll inv[N+1];
ll p=998244353;
 
ll c(ll a, ll b,ll m)
{
  if(a<b)return 0;
  return (fac[a]*inv[b]%m)*(inv[a-b])%m;
}
 
*/

ll dp[2005][2005];

int main()
{ fast

ll n;cin>>n;

vpll a(n+1);

for(int i=1;i<=n;i++)
{
  cin>>a[i].ff;
  a[i].ss=i;
}

sort(a.begin()+1,a.end(),greater<>());

for(ll i=1;i<n;i++)
{
  for(ll j=n;j>i;j--)
  {
    ll pos=n+i-j;
    dp[i+1][j]=max(dp[i+1][j],dp[i][j]+(a[pos].ff)*abs(a[pos].ss-i));
    dp[i][j-1]=max(dp[i][j-1],dp[i][j]+a[pos].ff*abs(a[pos].ss-j));
  }
}

ll ans=0;

for(int i=1;i<=n;i++)
{
  ans=max(ans,dp[i][i]+a[n].ff*abs(a[n].ss-i));
}

cout<<ans<<endl;




 return 0;
 
 
}