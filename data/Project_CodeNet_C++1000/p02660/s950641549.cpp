#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  ll n,ans=0; cin >>n;
  for(ll i = 2, m=n; i*i<=m;i++){
    ll z = i;
    while(n%z==0){
      ans++;
      n/=z;
      z*=i;
    }
    while(n%i==0) n/=i;
  }
  cout << ans + (n!=1) << endl;
  return 0;
}