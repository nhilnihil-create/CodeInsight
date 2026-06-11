#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

bool f(int x) {
  if (x < 100) return false;
  if (2000 <= x) return true;
  rep(i,1,19) {
    int l = 100 * i, r = 105 * i;
    if (l <= x && x <= r) return true;
  }
  return false;
}

int main() {
  int X;
  cin >> X;
  cout << f(X) << endl;
  return 0;
}
