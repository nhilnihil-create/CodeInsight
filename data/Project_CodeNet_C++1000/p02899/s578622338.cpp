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
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<ii> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].fi;
    a[i].sc = i + 1;
  }
  sort(all(a));
  for (auto &i : a) cout << i.sc << ' '; cout << '\n';
}
