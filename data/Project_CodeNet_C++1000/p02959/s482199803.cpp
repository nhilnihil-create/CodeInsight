#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++) 
int main() {
  int n;cin>>n;
  vector<int> a(n+1),b(n);
  rep(i,n+1)cin>>a[i];
  rep(i,n)cin>>b[i];
  ll ans=0;
  rep(i,n){
    if(a[i]>b[i])ans+=b[i];
    else{
      ans+=min(b[i],a[i]+a[i+1]);
      a[i+1]=max(0,a[i]+a[i+1]-b[i]);
    }
  }
  cout<<ans<<endl;
  return 0;
}
