#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

void MAIN() {
  int n; cin >> n;
  vector<ii> a(n);
  for (auto &i : a) {
    cin >> i.sc >> i.fi;
  }
  sort(all(a));
  int time = 0;
  for (auto &i : a) {
    time += i.sc;
    if (time > i.fi) {
      cout << "No" << '\n';
      return;
    }
  }
  cout << "Yes" << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
