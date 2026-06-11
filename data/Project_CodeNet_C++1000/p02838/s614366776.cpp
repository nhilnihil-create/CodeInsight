#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

typedef long long ll;
 
const ll mod = (ll)(1e9+7);

int main() {
  ll n;
  cin >> n;
  ll a[n];
  rep(i,n) cin >> a[i];
  
  ll r = 0;
  rep(k,60) {
    ll m = 0;
    rep(i,n) m += (a[i]>>k) % 2;
    r = (r + (n - m) * m % mod * ((1L<<k) % mod)) % mod;
  }
  cout << r << "\n";
  return 0;
}