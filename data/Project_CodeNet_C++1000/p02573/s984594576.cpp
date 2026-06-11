#include <bits/stdc++.h>
#define ll long long
#define pb(x) push_back((x))
#define line() cerr << "DEBUG @" << __LINE__ << endl;
#define debug(x) \
  cerr << "DEBUG @" << __LINE__ << " -> " << #x << " = " << x << endl;
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> Root(n), Size(n, 1);
  function<int(int)> root = [&](int r) {
    if (Root[r] == r) return r;
    return Root[r] = root(Root[r]);
  };
  for (int i = 0; i < n; i++) Root[i] = i;
  auto merge = [&](int a, int b) {
    a = root(a), b = root(b);
    if (a != b) {
      Root[b] = a;
      Size[a] += Size[b];
      Size[b] = 0;
    }
  };
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    merge(u, v);
  }
  int ans = -1;
  for (int i = 0; i < n; i++) {
    ans = max(ans, Size[root(i)]);
  }
  cout << ans << '\n';
}
