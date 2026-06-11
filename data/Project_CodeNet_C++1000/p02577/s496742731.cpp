#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

typedef long long ll;

void solve() {
  string N;
  cin >> N;

  ll sum = 0;
  for (char n : N)
    sum += (n - '0');

  cout << (sum % 9 == 0 ? "Yes" : "No");
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