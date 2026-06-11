#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n;
  string s;
  cin >> n >> s;
  if (s[0] == 'W' || s[2 * n - 1] == 'W') {
    cout << 0 << endl;
    return 0;
  }
  string t = "L";
  REP(i, 2 * n) {
    if (i == 0) continue;
    if (s[i - 1] == s[i]) {
      t += (t[i - 1] == 'L' ? 'R' : 'L');
    } else {
      t += (t[i - 1] == 'L' ? 'L' : 'R');
    }
  }
  int l = 0, r = 0;
  REP(i, 2 * n) { (t[i] == 'L' ? l : r)++; }
  if (l != r) {
    cout << 0 << endl;
    return 0;
  }
  l = 0, r = 0;
  ll ans = 1;
  REP(i, 2 * n) {
    if (t[i] == 'R') {
      ans *= (l - r);
      ans %= MOD;
    }
    (t[i] == 'L' ? l : r)++;
  }
  REP1(i, n) {
    ans *= i;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}