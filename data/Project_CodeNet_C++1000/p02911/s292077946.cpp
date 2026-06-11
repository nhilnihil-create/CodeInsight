#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(q);
  rep(i, q) {
    cin >> a[i];
    --a[i];
  }

  vector<int> p(n, k - q);
  rep(i, q) ++p[a[i]];
  vector<bool> pass(n, false);
  rep(i, n) if (p[i] > 0) pass[i] = true;
  rep(i, n) {
    if (pass[i]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}