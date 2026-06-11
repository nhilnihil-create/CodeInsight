#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const ll MOD = 1e9 + 7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string l;
  cin >> l;
  
  vector<vector<ll>> dp(l.size() + 1, vector<ll>(2));
  dp.at(0).at(0) = 1;
  for (int i = 0; i < l.size(); i++) {
    for (int j = 0; j < 2; j++) {
      for (int d = 0; d <= (j ? 1 : l.at(i) - '0'); d++) {
        if (d == 0) {
          dp.at(i + 1).at(j || (d < l.at(i) - '0')) += dp.at(i).at(j);
          dp.at(i + 1).at(j || (d < l.at(i) - '0')) %= MOD;
        }
        else {
          dp.at(i + 1).at(j || (d < l.at(i) - '0')) += 2 * dp.at(i).at(j);
          dp.at(i + 1).at(j || (d < l.at(i) - '0')) %= MOD;
        }
      }
    }
  }
  
  cout << (dp.at(l.size()).at(0) + dp.at(l.size()).at(1)) % MOD << '\n';
}