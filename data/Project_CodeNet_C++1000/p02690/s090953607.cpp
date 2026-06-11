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
const ll MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];


int main(){
  ll x;cin>>x;
  ll a,b;
  bool ok=false;
  rep(i,-120,120){
    rep(j,-120,120){
      if(pow(i,5)+pow(j,5)==x){
        a=i;b=j;
        ok=true;
        break;
      }
    }
    if(ok){break;}
  }
  cout<<a<<" "<<-b<<endl;
}




