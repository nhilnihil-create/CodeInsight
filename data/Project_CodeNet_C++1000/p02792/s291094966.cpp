#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for(int i = 0; i < n; ++i)
#define INF (2e9)

int main() {
  ll n; cin >> n;
  ll cnt[10][10];

  for(int i = 0; i <= 9; ++i) {
    for(int j = 0; j <= 9; ++j) {
      cnt[i][j] = 0;
    }
  }

  for(int k = 1; k <= n; ++k) {
    string strk = to_string(k);
    cnt[strk[0]-'0'][strk[strk.length()-1]-'0']++;
  }
  
  ll ans = 0;
  for(int i = 0; i <= 9; ++i) {
    for(int j = 0; j <= 9; ++j) {
      ans += cnt[i][j] * cnt[j][i];
    }
  }

  cout << ans << endl;

  return 0;
}