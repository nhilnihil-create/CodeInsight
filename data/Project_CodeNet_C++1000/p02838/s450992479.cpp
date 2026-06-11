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

const int mod = 1e9 + 7;

#define pow abcdef
int pow(int a, int b) {
  if (b == 0) return 1;
  int t = pow(a, b / 2);
  t = (t * t) % mod;
  if (b % 2) return (t * a) % mod;
  return t;
}

void Main() {
  int n; cin >> n;
  vector<int> a(n), b(60);
  for (auto &i : a) {
    cin >> i;
    for (int j = 0; j < 60; j++) {
      b[j] += getBit(i, j);
    }
  }
  int cal = 0;
  for (int j = 0; j < 60; j++) {
    cal += ((1ll << j) % mod) * ((b[j] * (n - b[j])) % mod);
    cal %= mod;
  }
  cout << cal << '\n';
}

signed main() {
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) Main();
}
