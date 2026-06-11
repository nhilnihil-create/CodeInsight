#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  ll n;
  cin >> n;
  vector<ll>on(60),off(60);
  for(int i=0; i<n; i++){
    ll a;
    cin >> a;
    for(int j=0; j<60; j++){
      if(a >> j & 1) on[j]++;
      else off[j]++;
    }
  }
  ll ans=0;
  for(int i=0; i<60; i++){
    ll count=pow(2,i);
    count%=mod;
    count*=on[i];
    count%=mod;
    count*=off[i];
    count%=mod;
    ans+=count;
    ans%=mod;
  }
  cout << ans << endl;
}
  
  
  
