#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll n,k;
  cin >> n >> k;
  n++;
  ll ans=n-k+1;
  for(ll i=k;i<=n;i++){
    ans-=i*i;
    ans+=n*i;
    ans%=1000000007;
  }
  cout << ans << endl;
}