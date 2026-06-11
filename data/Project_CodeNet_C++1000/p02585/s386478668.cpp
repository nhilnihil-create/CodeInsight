#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

typedef long long ll;

void solve() {
  int n, k;
  cin >> n >> k;
  int p[n], c[n];
  for (int& i : p) {
    cin >> i;
    i--;
  }
  for (int& i : c)
    cin >> i;

  ll ans = -1e9 - 1;
  for (int i = 0; i < n; i++) {
    int square = i, cycleSize = 0;
    ll cycleSum = 0;
    do {
      cycleSize++;
      cycleSum += c[square];
      square = p[square];
    } while (square != i);

    int moves = 0;
    ll path = 0;
    square = i;
    do {
      if (moves >= k)
        break;
      moves++;
      square = p[square];
      path += c[square];
      int multiplier = (k - moves) / cycleSize;
      ll score = path + max(0ll, cycleSum) * multiplier;
      ans = max(ans, score);
    } while (square != i);
  }

  cout << ans << nl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // int t;
  // cin >> t;
  // while (t--) {
  solve();
  // }

  return 0;
}