#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n,a,b;
  cin>>n>>a>>b;
  ll ans;
  if((b-a)%2==0){
    ans=(b-a)/2;
  }else{
    ll ans1=n-b;
    ans=a+((b-a-1)/2);
    ans1=n-b+1+((n-(a+(n-b+1)))/2);
    ans=min(ans,ans1);
  }
  cout<<ans<<endl;
}