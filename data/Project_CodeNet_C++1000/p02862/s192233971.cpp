#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

ll fac[1000001],inv[1000001],finv[1000001];

void COMinit() {
  fac[0]=fac[1]=1;
  inv[1]=1;
  finv[0]=finv[1]=1;
  FOR(i,2,1000001){
    fac[i]=fac[i-1]*i%MOD;
    inv[i]=(MOD-(MOD/i*inv[MOD%i])%MOD)%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}
ll choose(ll n,ll k){
  return (fac[n]*finv[k]%MOD)*finv[n-k]%MOD;
}

int main() {
  COMinit();
  ll X,Y;
  cin >> X >> Y;
  if((X+Y)%3!=0){
    cout << 0 << endl;
  }
  else{
    ll K=(X+Y)/3;
    X-=K;
    Y-=K;
    if(min(X,Y)<0){
      cout << 0 << endl;
    }
    else{
      cout << choose(K,X) << endl;
    }
  }
}