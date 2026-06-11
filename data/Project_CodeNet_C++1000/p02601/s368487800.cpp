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
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  while (b <= a) {
    b *= 2;
    k--;
  }
  while (c <= b) {
    c *= 2;
    k--;
  }
  if (k >= 0) cout << "Yes" << '\n';
  else cout << "No" << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) Main();
}
