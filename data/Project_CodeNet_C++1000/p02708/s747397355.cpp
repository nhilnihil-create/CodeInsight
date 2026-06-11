#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
const int mod = 1000000007;


int main() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  for(int i = k; i <= n+1; i++) {
    // ans += (2*n-i+1)*i/2-i*(i-1)/2+1;
    ans += (i*(n-i+1) + 1);
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}