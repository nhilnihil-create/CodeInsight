#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  ll a,b;cin>>a>>b;
  ll ans=a/gcd(a,b)*b;
  cout<<ans<<endl;
}