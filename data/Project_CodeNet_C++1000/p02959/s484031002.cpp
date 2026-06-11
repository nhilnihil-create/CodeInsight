#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
const int INF=1e9+5;
typedef long long ll;

int main() {
  ll N;
  cin>>N;
  vector<ll> a(N+1);
  vector<ll> b(N);
  rep(i,N+1) cin>>a[i];
  rep(i,N) cin>>b[i];
  
  ll ans=0;
  
  rep(i,N){
    if(b[i]>a[i]+a[i+1]){
      ans+=a[i]+a[i+1];
      a[i+1]=0;
    }
    else if(b[i]>a[i]){
      ans+=b[i];
      a[i+1]-=(b[i]-a[i]);
    }
    else{
      ans+=b[i];
    }
  }
  cout<<ans<<endl;
}
