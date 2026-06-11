#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll l, r;
  cin >> l >> r;
  ll ans = 10000;
  for(ll i=l; i <= l+2020; i++){
    if(i==r) break;
    for(ll j=l+1; j <= l+2021; j++){
      ans = min(ans, (i*j)%2019);
      if(j == r) break;
    }
  }
  cout << ans << endl;
}
