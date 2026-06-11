#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll a,b,n;
  cin >> a >> b >> n;
  ll x;
  if (b<=n) {
    x = b-1;
  } else {
    x = n;
  }
  ll ans = (a*x)/b - a*(x/b);
  cout << ans << endl;
  return 0;
}
