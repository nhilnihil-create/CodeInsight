#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll a,b;
  cin >> a >> b;
  ll ans = -1;
  rep(i, 10000000){
    if(i*8/100 == a && i/10 == b){
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}