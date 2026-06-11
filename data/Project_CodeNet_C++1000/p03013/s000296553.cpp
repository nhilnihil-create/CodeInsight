#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll MOD = 1000000007;
  ll n,m;
  cin >> n >> m;
  vector<ll> a(m+2);
  a[m+1] = n+1, a[0] = -1;
  rep(i,m) cin >> a[i+1];
  rep(i,m){
    if(a[i] + 1 == a[i+1]){
      cout << 0 << endl;
      return 0;
    }
  }
  vector<ll> b(n+1);
  b[1] = 1, b[2] = 2;
  for(ll i=3; i<=n; i++){
    b[i] = (b[i-1] + b[i-2]) % MOD;
  }
  ll ans = 1;
  rep(i,m+1){
    if(a[i+1] == 1 || a[i] == n-1 || a[i+1] - a[i] -2 == 0) continue;
    else{
      ans *= b[a[i+1] - a[i] -2];
      ans %= MOD;
      //cout << a[i+1] - a[i] -2 << endl;
    }
  }
  cout << ans << endl;
}
