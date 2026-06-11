#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  ll n,k;cin>>n>>k;
  ll ans=min(n%k,abs(k-n%k));
  cout<<ans<<endl;
}