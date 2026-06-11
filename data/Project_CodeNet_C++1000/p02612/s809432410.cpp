#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

typedef long long ll;

void solve() {
  int N;
  cin >> N;

  cout << (1000 - N%1000) % 1000;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // int t;
  // cin >> t;
  // while (t--) {
  solve();
  cout << nl;
  // }

  return 0;
}