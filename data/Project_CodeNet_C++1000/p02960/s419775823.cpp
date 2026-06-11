#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;
const int MAXV = 13;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  int n = s.size();

  vector<ll> dp(MAXV, 0);
  dp[0] = 1;

  int mul = 1;
  repr(i, 0, n) {
    vector<ll> next(MAXV, 0);
    char c = s[i];

    if (c == '?') {
      rep(k, 0, 10) {
        rep(j, 0, MAXV) {
          next[(k * mul + j) % MAXV] += dp[j];
          next[(k * mul + j) % MAXV] %= MOD;
        }
      }
    } else {
      int k = (int)(s[i] - '0');
      rep(j, 0, MAXV) {
        next[(k * mul + j) % MAXV] += dp[j];
        next[(k * mul + j) % MAXV] %= MOD;
      }
    }
    mul *= 10;
    mul %= MAXV;
    dp = next;
  }

  cout << dp[5] << endl;
}
