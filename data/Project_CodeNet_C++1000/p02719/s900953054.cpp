#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 

int main() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  if (n < k) {
    ans = min(n, abs(n-k));
  }
  else if (n%k == 0) ans = 0;
  else ans = min(n%k, abs(n%k - k));
  cout << ans << endl;
  return 0;
}