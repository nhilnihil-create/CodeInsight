#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans = 2e18;
  if ((b - a) % 2 == 0) ans = min(ans, (b - a) / 2);
  else {
    ans = min(ans, (n-b) + (b-a-1)/2 + 1);
    ans = min(ans, (a-1) + (b-a-1)/2 + 1);
  }
  cout << ans << endl;
  return 0;
}