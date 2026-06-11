#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
  ll a,b;
  cin >> a >> b;
  vector<ll>ans(10,0);
  if(a>b){
    for(ll i=0;i<a;i++){
      ans[i]=b;
    }
  }
  else {
    for(ll i=0;i<b;i++){
      ans[i]=a;
    }
  }
  for(ll i=0;i<10;i++){
    if(ans[i]==0) break;
    cout << ans[i];
  }
  cout << endl;
}