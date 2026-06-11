#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

void solve() {
  ll d, t, s;
  cin >> d >> t >> s;
  if (d <= t * s) {
    cout << "Yes\n";
    return;
  }
  cout << "No\n";
}

int main() {
  ll t;
  // cin >> t;
  t = 1;
  while (t--)
    solve();
  return 0;
}