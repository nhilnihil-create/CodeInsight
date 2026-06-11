#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, n;
  cin >> h >> w >> n;
  h = max(h, w);
  cout << (n + h - 1) / h;
  return 0;
}
