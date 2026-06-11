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

void MAIN() {
  int n; cin >> n;
  vector<int> a(n);
  int s = 0;
  for (auto &i : a) {
    cin >> i;
    s ^= i;
  }
  for (auto &i : a) {
    cout << (s ^ i) << ' ';
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
