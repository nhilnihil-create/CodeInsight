

#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF=1e18;


int main() {
  ll n,k;
  cin >> n>>k;
  ll t=(n-1)*(n-2)/2;
  //cout<<t<<endl;

  if(k>t) {
    cout<<-1;
    return 0;
  }
  ll c=n-1+t-k;
  cout<<c<<endl;
  rep(i,n-1){
    cout<<"1 "<<(i+2)<<endl;
  }
  ll now=t-k;
    for(ll i=2;i<=n;i++){
      for(ll j=i+1;j<=n;j++){
        if (now<=0)break;
        cout<<i<<" "<<j<<endl;
        //cout<<now<<endl;
        now--;

      }
    }
return 0;

}
