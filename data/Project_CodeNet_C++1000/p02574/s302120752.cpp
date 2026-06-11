#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

typedef long long ll;

void solve() {
  int N;
  cin >> N;
  int gcd = 0, maxA = 0;
  vector<int> cnts(1e6 + 5);
   for (int i = 0, e; i < N; i++) {
    cin >> e;
    if (!gcd)
      gcd = e;
    gcd = __gcd(gcd, e);
    maxA = max(maxA, e);
    cnts[e]++;
  }

  bool flag = true;
  for (int i = 2; i <= maxA; i++) {
    int cnt = 0;
    for (int p = i; p <= maxA; p += i) {
      cnt += cnts[p];
    }
    if (cnt > 1) {
      flag = false;
    }
  }

  if (flag) {
    cout << "pairwise coprime";
    return;
  }

  if (gcd == 1) {
    cout << "setwise coprime";
    return;
  }
  cout << "not coprime";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // int t;
  // cin >> t;
  // while (t--) {
  solve();
  // cout << nl;
  // }

  return 0;
}