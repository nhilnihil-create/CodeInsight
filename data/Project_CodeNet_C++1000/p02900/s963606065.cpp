#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
int main() {
  ll a,b,ans=1;
  cin>>a>>b;
  for(ll i=2;i*i<=min(a,b);i++){
    if(a%i==0 && b%i==0) ans++;
    if(a%i==0){
      for(;a%i==0;) a/=i;
    }
    if(b%i==0){
      for(;b%i==0;) b/=i;
    }
    if(a*b==1){
      cout<<ans;
      return 0;
    }
  }
  if(max(a,b)%min(a,b)==0 && min(a,b)!=1) ans++;
  cout<<ans;
}
