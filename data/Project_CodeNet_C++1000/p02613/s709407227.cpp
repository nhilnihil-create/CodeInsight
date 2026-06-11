#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

typedef long long ll;

void solve() {
  int N;
  cin >> N;

  unordered_map<string, int> cnt;
  while (N--) {
    string status;
    cin >> status;
    cnt[status]++;
  }

  cout << "AC"
       << " x " << cnt["AC"] << nl;
  cout << "WA"
       << " x " << cnt["WA"] << nl;
  cout << "TLE"
       << " x " << cnt["TLE"] << nl;
  cout << "RE"
       << " x " << cnt["RE"] << nl;
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