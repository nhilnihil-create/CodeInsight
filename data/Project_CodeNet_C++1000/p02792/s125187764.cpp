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
#define getbit(x, k) ((x >> k) & 1)
#define all(x) (x).begin(),(x).end()
// ---------------------------------

void Main() {
  int n; cin >> n;
  map<int, map<int, int>> m;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    string s = to_string(i);
    ans += m[s.back()][s.front()] * 2;
    m[s.front()][s.back()]++;
    if (s.front() == s.back()) ans++;
  }
  cout << ans << '\n';
}

signed main() {
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) Main();
}
