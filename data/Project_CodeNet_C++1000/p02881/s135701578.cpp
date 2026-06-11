#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  ll n;cin>>n;
  int ans;
  for(int i=1;i<=sqrt(n);i++){
    ll x=n%i;
    if(x==0)ans=i;
  }
  cout<<ans-1+n/ans-1<<endl;
}