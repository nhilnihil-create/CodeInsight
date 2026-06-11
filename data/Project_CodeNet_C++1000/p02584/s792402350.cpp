#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  ll x,k,d;cin>>x>>k>>d;
  x=abs(x);
  if(k<=x/d)cout<<x-k*d<<endl;
  else {
    if((k-x/d)%2==0)cout<<x-x/d*d<<endl;
    else cout<<d-(x-x/d*d)<<endl;
  }
}
