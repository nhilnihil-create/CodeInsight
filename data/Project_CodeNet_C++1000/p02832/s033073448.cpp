#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int now = 0;
  rep(i, n) if (a[i] == now + 1) ++now;
  if (now == 0) cout << -1 << endl;
  else cout << n - now << endl;
  return 0;
}