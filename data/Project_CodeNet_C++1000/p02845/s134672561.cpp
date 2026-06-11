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
  int max_hats[100005] = {};
  int mid_hats[100005] = {};
  int min_hats[100005] = {};
  ll ans = 3;
  int data[100005] = {};

  REP(i, n) { cin >> data[i]; }
  max_hats[0] = 1;

  FOR(i, 1, n) {
    if (data[i] >= max_hats[i - 1]) {
      max_hats[i]++;
    } else if (data[i] >= mid_hats[i - 1]) {
      mid_hats[i]++;
    } else {
      min_hats[i]++;
    }
    max_hats[i] += max_hats[i - 1];
    mid_hats[i] += mid_hats[i - 1];
    min_hats[i] += min_hats[i - 1];
  }

  FOR(i, 1, n) {
    int cnt = (data[i] == max_hats[i - 1]) + (data[i] == mid_hats[i - 1]) +
              (data[i] == min_hats[i - 1]);
    ans *= cnt;
    ans %= MOD;
  }
  if (data[0] != 0) ans = 0;
  cout << ans << endl;
}