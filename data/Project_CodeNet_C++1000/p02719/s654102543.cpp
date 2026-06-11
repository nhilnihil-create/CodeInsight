#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  ll n,k;cin>>n>>k;
  ll a=n%k;
  ll ans=min(a,k-a);
  cout<<ans<<endl;
}