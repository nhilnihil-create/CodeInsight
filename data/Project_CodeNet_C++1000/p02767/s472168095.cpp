#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000000;
//------------------------------------------//

int main(){
  int N;cin>>N;
  int X[101];
  ll ans=M;
  rep(i,N) cin>>X[i];
  
  rep(i,100){
    ll cnt=0;
    rep(j,N){
      cnt+=(i-X[j])*(i-X[j]);
    }
    ans=min(ans,cnt);
  }
  cout<<ans<<endl;
}