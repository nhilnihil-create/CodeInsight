#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int S, W;
  cin >> S >> W;
  bool bl;
  bl = (S > W);
  if (bl) cout << "safe" << '\n';
  else cout << "unsafe" << '\n';
  return 0;
}