#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  ll h,w;cin>>h>>w;
  ll ans=(h*w+1)/2;
  if(h==1||w==1)cout<<1<<endl;
  else cout<<ans<<endl;
}