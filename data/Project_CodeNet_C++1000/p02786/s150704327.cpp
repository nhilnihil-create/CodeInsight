#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll h;
  cin >> h;
  ll ans = 0;
  ll cnt = 1;
  while (h > 0) {
    ans += cnt;
    cnt *= 2;
    h /= 2;
  }
  cout << ans << endl;
  return 0;
}
