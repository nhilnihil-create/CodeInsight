#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

#define INF 1001001001
#define MAX 200005

int main() {
  int n, q;
  cin >> n >> q;
  dsu d(n);
  vector<int> ans;
  rep(i,q) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t==0) {
      d.merge(u,v);
    } else {
      ans.push_back(d.same(u,v));
    }
  }
  for (auto a : ans) cout << a << endl;

  return 0;
}
