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
const ll MOD = 1L<<32;
ll fac[MAX], finv[MAX], inv[MAX];

int main(){
  ll n,k;cin>>n>>k;
  vll a(n);
  rep(i,0,n){
    cin>>a[i];
  }
  rep(i,0,min(41LL,k)){
    vll b(n,0);
    rep(j,0,n){
      ll l=max(0LL,j-a[j]),r=min(n-1,j+a[j]);
      b[l]++;
      if(r+1<n)b[r+1]--;
    }
    rep(j,0,n-1){b[j+1]+=b[j];}
    a=b;
  }
  rep(i,0,n){
    cout<<a[i]<<' ';
  }
  cout<<endl;
}



