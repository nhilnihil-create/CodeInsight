#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  int x = -1;
  for (int i = 1; i <= 50000; ++i) {
    if ((int)(i * 1.08) == n) {
      x = i;
      break;
    }
  }
  if (x != -1) cout << x << endl;
  else cout << ":(" << endl;
  return 0;
}