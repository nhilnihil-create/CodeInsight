#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

typedef long long ll;

void solve() {
  string S, T;
  cin >> S >> T;

  int minCost = T.size();
  for (int i = 0; i < S.size() - T.size() + 1; i++) {
    int cost = 0;
    for (int j = i; j < i + T.size(); j++) {
      if (S[j] != T[j - i])
        cost++;
    }
    minCost = min(minCost, cost);
  }

  cout << minCost;
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