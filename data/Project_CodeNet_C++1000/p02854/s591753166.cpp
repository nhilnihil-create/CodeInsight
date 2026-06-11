#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define fi first
#define se second
#define INF 1000000009
#define LLINF 1000000000000000009LL
using ll = long long;

int main(){
  int n;
  cin>>n;
  vector<ll>a(n);
  rep(i,n)cin>>a[i];
  ll sum=0;
  rep(i,n)sum+=a[i];
  ll s=0;
  ll ans=LLINF;
  rep(i,n){
    s+=a[i];
    ans=min(ans,llabs(sum-s-s));
  }
  cout<<ans<<endl;
  return(0);
}
