#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  int p = max(h, w);
  int ans = (n + p - 1) / p;
  cout << ans << endl;
  return 0;
}