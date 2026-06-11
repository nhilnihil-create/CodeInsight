#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n) cin >> d[i];
  int smd = 0;
  rep(i, n) smd += d[i];
  int ans = smd * smd;
  rep(i, n) ans -= d[i] * d[i];
  ans /= 2;
  cout << ans << endl;
  return 0;
}