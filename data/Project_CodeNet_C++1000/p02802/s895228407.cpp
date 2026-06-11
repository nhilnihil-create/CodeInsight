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
  int n, m;
  cin >> n >> m;
  map<int, int> pen, ac;
  int cp = 0, ca = 0;
  for (int i = 1; i <= m; i++) {
    int id;
    string s;
    cin >> id >> s;
    if (s == "WA") pen[id]++;
    else if (!ac[id]) {
      ac[id] = 1;
      cp += pen[id];
      ca += 1;
    }
  }
  cout << ca << ' ' << cp << '\n';
}
