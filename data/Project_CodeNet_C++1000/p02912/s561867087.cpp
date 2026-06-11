#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define popcnt __builtin_popcount
#define getBit(x, k) ((x >> k) & 1)
#define all(x) (x).begin(),(x).end()
// ---------------------------------

void Main() {
  int n, m;
  cin >> n >> m;
  priority_queue<int> q;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    q.push(t);
  }
  for (int i = 0; i < m; i++) {
    int j = q.top(); q.pop();
    q.push(j / 2);
  }
  int ans = 0;
  while (q.size()) {
    ans += q.top(); q.pop();
  }
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  cerr << "i love ------- <3 \n";
#endif
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  // cin >> T;
  while (T--) Main();
}
