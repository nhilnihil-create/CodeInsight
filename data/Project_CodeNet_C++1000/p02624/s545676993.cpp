#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin  >> n;
  vector<ll> p(n);
  ll j=1;
  for(ll i=1;i<=n;i++){
    j=1;
    while(i+j-2<n){
      p.at(i+j-2)++;
      j+=i;
    }
  }
  ll ans=0;
  for(ll i=1;i<=n;i++){
    ans+=i*p.at(i-1);
  }
  cout << ans;
}
    
    