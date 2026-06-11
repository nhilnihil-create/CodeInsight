#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h1, m1, h2, m2, k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  int w = (h2 - h1) * 60 + (m2 - m1);
  int ans = w - k;
  cout << ans << endl;
  return 0;
}