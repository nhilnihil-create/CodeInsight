#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF (int)1e9+7
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
//#define N 100005
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795


ll powM(ll a,ll b,ll m )
{ 
  a%=m;
  ll ans=1;
  while(b>0)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }

return ans;
}

ll N=2e5+1;

vl fac(N);

ll c(ll n,ll r,ll m)
{
  ll y=1;
 // ll y=powM(fac[n-r],m-2,m);
  for(int i=1;i<=r;i++)
  {
    y=y*(n-i+1)%m;
  }
  ll z=powM(fac[r],m-2,m);
  return y*z%m;
}



int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

ll n,a,b;
cin>>n>>a>>b;
ll m=(ll)1e9+7;

//invf[0]=1;
fac[0]=1;
  for(int i=1;i<=N;i++)
  {
    fac[i]=fac[i-1]*i%m;
    ///nvf[i]=powM(fac[i],m-2,m);
  }

  ll ans=powM(2,n,m)-c(n,a,m)-c(n,b,m)-1;

  ans=(ans+3*m)%m;

  cout<<ans<<"\n";

}