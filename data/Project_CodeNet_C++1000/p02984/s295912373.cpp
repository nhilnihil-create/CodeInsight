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
ll roundd(ll n,ll x){
  if(0<=x&&x<n){return x;}
  else if(x<0){return x+n;}
  else{return x%n;}
}
int main(){
  ll n;cin>>n;
  vll a(n),ans(n);
  ll sum=0;
  rep(i,0,n){
    cin>>a[i];
    sum+=a[i];
  }
  
  ans[0]=2*a[roundd(n,-1)];ll kari=ans[0];
  rep(i,1,n){
    ans[i]=2*a[roundd(n,i-1)]-ans[i-1];
    kari+=ans[i];
  }
  ll x=kari-sum;
  rep(i,0,n){
    if(i%2){cout<<ans[i]+x<<" ";}
    else{cout<<ans[i]-x<<" ";}
    
  }


}

