#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n;
  cin >> n;
  int ans = 1;
  if(n != 2) ++ans;
  for(ll i=2; i*i<=n; ++i){
    ll x = n;
    if(x%i == 1){
      ans += 2;
      if(i == x/i) --ans;
      continue;
    }
    while(x%i == 0){
      x /= i;
    }
    if(x%i == 1){
      ++ans;
    }
  }
  cout << ans << endl;
}