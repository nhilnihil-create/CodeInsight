#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll h,w;
  cin >> h >> w;
  if (h == 1 || w == 1) {
    cout << 1 << endl;
    return 0;
  }
  ll ans = (h*w+1)/2;
  printf("%lld\n", ans);
  return 0;
}
