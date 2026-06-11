#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef vector<pair<ll,ll> > vp;
typedef vector<vp> vvp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>(b);--i)
const int MOD = 1000000007;
const int MAX = 510000;

int main(){
  ll n,k,ans=0;cin>>n>>k;
  if(k>((n-1)*(n-2))/2){cout<<-1<<endl;}
  else{
    vvb g(n,vb(n,false));
    rep(i,1,n)g[0][i]=true;
    ans=n-1;
    ll i=((n-1)*(n-2))/2-k;
    rep(j,1,n){
      rep(k,j+1,n){
        if(i<=0){break;}
        g[j][k]=true;i--;
        ans++;
      }
    }
    cout<<ans<<endl;
    rep(k,0,n){
      rep(l,0,n){
        if(g[k][l]){cout<<k+1<<" "<<l+1<<endl;}
      }
    }
  }
}

