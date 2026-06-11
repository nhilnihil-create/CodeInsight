#include <bits/stdc++.h>

#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  dsu d(n);
  rep(_, m) {
    int a, b;
    cin >> a >> b;
    d.merge(a - 1, b - 1);
  }
  cout << d.groups().size() - 1 << endl;
  return 0;
}