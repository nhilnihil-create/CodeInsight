#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n;
  cin>>n;
  vector<ll> a(n+1),b(n);
  rep(i,n+1){
    cin>>a[i];
  }
  ll ans=0;
  rep(i,n){
    ll b;
    cin>>b;
    if(a[i]>0){
      ans+=min(a[i],b);
      a[i]-=b;
      if(a[i]<0){
      ans+=min(a[i+1],abs(a[i]));
      a[i+1]+=a[i];
    }
    }else{
      ans+=min(a[i+1],b);
      a[i+1]-=b;
    }
  }
  cout<<ans<<endl;
}