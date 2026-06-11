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
  int n;
  cin >> n;
  map<string, int> m;
  int ma = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    m[s]++;
    ma = max(ma, m[s]);
  }
  for (auto &i : m) {
    if (i.sc == ma) cout << i.fi << '\n';
  }
}
