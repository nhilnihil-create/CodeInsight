#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD (int)1e9+7
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



int main()
{


ll n;cin>>n;

vl a(n);
ll p=1e9+7;
ll ans=0,mxn=0;

for(int i=0;i<n;i++)
{
  cin>>a[i];
//mxn=max(mxn,a[i]);
}

for(ll pos=0;pos<64;pos++)
{
  ll c=0,d=0;
  for(ll i=0;i<n;i++)
  {
if(a[i]&1)c++;
else d++;
a[i]>>=1;
  }
 // if(d==n)break;
  ans+=((1LL<<pos)%p)*(c*d%p);
  ans%=p;
}

cout<<ans<<"\n";

return 0;

}
