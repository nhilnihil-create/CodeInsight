#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int X;
  cin >> X;

  bool ans = 0;
  rep(i,1,X) {
    int l = 100 * i, r = 105 * i;
    if (l <= X && X <= r) ans = 1;
  }

  cout << ans << endl;
  return 0;
}
