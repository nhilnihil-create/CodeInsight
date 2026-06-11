#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x;
  cin >> x;
  bool exist = false;
  for (int i = 0; i <= 100000; ++i) {
    int y = x - 100 * i;
    if (y >= 0 && y <= 5 * i) exist = true;
  }
  if (exist) cout << 1 << endl;
  else cout << 0 << endl;
  return 0;
}