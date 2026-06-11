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
#define SIZE(a) ll((a).size())
#define out(a) cout<<(a)<<endl;
const int inf=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;


int main(){
  ll n,k;cin>>n>>k;
  vll a(n);
  rep(i,0,n){
    cin>>a[i];
  }
  rep(i,0,min(45LL,k)){
    vll sum(n+1,0);
    rep(i,0,n){
      sum[max(i-a[i],0LL)]++;
      sum[min(n,i+a[i]+1)]--;
    }
    rep(i,1,n){
      sum[i]+=sum[i-1];
    }
    rep(i,0,n){
      a[i]=sum[i];
    }
  }
  rep(i,0,n){cout<<a[i]<<" ";}
  cout<<endl;
}

