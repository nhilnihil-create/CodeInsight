
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
const ll INF=1e18;


int main() {
  ll n;
  cin>>n;
  ll ans=0;
  rep(i,n){
    ll temp=(i+1)*(n-i);
    ans+=temp;
  }
//  cout<<ans<<endl;
  rep(i,n-1){
    ll u1,v1;
    cin>>u1>>v1;
    u1--;v1--;
    if (u1>v1)swap(u1,v1);
    ll temp=(u1+1)*(n-v1);
    ans-=temp;
  }
  cout<<ans;
}
