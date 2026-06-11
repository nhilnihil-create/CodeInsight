#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;
int main(void){
  ll a,b;
  cin>>a>>b;
  if(b-a+1>=2019) cout<<0<<endl;
  else{
    ll ans=INF;
    for(ll i=a;i<=b-1;i++){
      for(ll j=i+1;j<=b;j++){
        ll L=i%2019,R=j%2019;
        ll a=(L*R)%2019;
        ans=min(a,ans);
      }
    }
    cout<<ans<<endl;
  }
}