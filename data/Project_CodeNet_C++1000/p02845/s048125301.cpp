#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  int md = 1e9 + 7;
  vector<ll> cnts(n + 1, 0);
  cnts[0] = 3;

  ll ans = 1;
  for (int i = 0; i < n; ++i) {
    ans = ans * cnts[va[i]] % md;
    cnts[va[i] + 1]++;
    cnts[va[i]]--;
  }

  cout << ans << '\n';
}