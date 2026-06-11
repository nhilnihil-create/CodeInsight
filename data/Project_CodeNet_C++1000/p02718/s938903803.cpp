#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int s = 0;
  rep(i, n) s += a[i];
  int c = 0;
  rep(i, n) if (a[i] * 4 * m >= s) ++c;
  if (c >= m) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}