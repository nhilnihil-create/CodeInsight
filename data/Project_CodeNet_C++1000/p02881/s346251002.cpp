#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll n;
  cin >> n;
  ll ans = 10000000000000;
  for(ll i=1; i*i<=n; i++){
    if(n%i != 0) continue;
    ll j = n/i;
    ans = min(ans, i+j-2);
  }
  cout << ans << endl;
}
