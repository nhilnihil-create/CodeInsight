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
ll roundd(ll x,ll n){
  if(x>n){return x%n;}
  else if(x<0){return x%n+n;}
  else return x;
}
int main(){
  ll k;cin>>k;
  ll ans=0;
  queue<ll> q;
  rep(i,1,10)q.push(i);
  rep(i,0,k){
    ll tmp=q.front();
    q.pop();
    if(tmp%10!=0){q.push(tmp*10+(tmp%10)-1);}
    q.push(tmp*10+(tmp%10));
    if(tmp%10!=9){q.push(tmp*10+(tmp%10)+1);}
    ans=tmp;
  }
  cout<<ans<<endl;
}

