#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b, m;
  cin >> a >> b >> m;
  vector<int> va(a), vb(b), vm(m);
  for (auto &i : va) cin >> i;
  for (auto &i : vb) cin >> i;
  for (auto &i : vm) {
    int j, k, l;
    cin >> j >> k >> l;
    i = va[j - 1] + vb[k - 1] - l;
  }
  sort(all(va));
  sort(all(vb));
  sort(all(vm));
  cout << min(va[0] + vb[0], vm[0]) << '\n';
}
