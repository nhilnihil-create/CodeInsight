#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int n;
  cin >> n;
  vector<ll> data(n);
  REP(i, n) { cin >> data[i]; }
  ll ans = 0;
  REP(d, 60) {
    ll one_cnt = 0;
    REP(i, n) {
      if (data[i] >> d & 1) one_cnt++;
    }
    ll now = one_cnt * (n - one_cnt) % MOD;
    REP(j, d) {
      now *= 2;
      now %= MOD;
    }
    ans += now;
    ans %= MOD;
  }
  cout << ans << endl;
}