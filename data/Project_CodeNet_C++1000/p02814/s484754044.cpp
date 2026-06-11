#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 10000;
ll fac[MAX], finv[MAX], inv[MAX];

//最大公約数
ll gcd(ll a,ll b){
   if (a%b == 0){
        return(b);
    }
   else{
       return(gcd(b, a%b));
    }
}
//ax+by=gcd(a,b)を満たす(x,y)
ll extgcd(ll a,ll b,ll &x,ll &y){
    ll d=a;
    if(b==0){
      x=1,y=0;
    }
    else{
      d=extgcd(b,a%b,y,x);
      y-=(a/b)*x;
    }
    return d;
}
//最小公倍数
ll lcm(ll a,ll b){
   return a * b / gcd(a, b);
}

int main (){
  ll n,m,x=1,cnt=0;cin>>n>>m;
  vll a(n);
  bool ok=false;
  rep(i,0,n){
    cin>>a[i];
    ll c=0;
    x=lcm(x,a[i]/2);

    while(a[i]%2==0){
      a[i]/=2;
      if(i==0)cnt++;
      else {
        c++;
      }
    }
    if(i!=0&&c!=cnt){ok=true;break;}
  }

  if(ok){cout<<0<<endl;return 0;}
  ll ans=m/x;
  if(ans%2)ans=(ans+1)/2;
  else ans/=2;
  cout<<ans<<endl;
}