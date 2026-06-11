#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n,k;
  cin >> n >> k;
  ll ans = 0;
  for(ll i = k; k < n + 2; k++){
    ll a, b;
    a = (k-1) * k / 2;
    b = (2*n-k+1) * k / 2;
    ans += (b - a + 1) % 1000000007;
  }
  cout << ans % 1000000007;
  return 0;
}