#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define mset(s, _) memset(s, _, sizeof s)
#define ALL(a) (a).begin(), (a).end()
using namespace std;
const int MAX_N = 1000000;
pair<int, int> itv[MAX_N];
int S[MAX_N];
int E[MAX_N];

int main(void) {
  int n;
  cin >> n;
  int x, l;
  rep(i, 0, n - 1) {
    cin >> x >> l;
    S[i] = x - l;
    E[i] = x + l;
  }

  rep(i, 0, n - 1) {
    itv[i].first = E[i];
    itv[i].second = S[i];
  }

  sort(itv, itv + n);

  int ans = 0;
  int tmp_e = -pow(10, 9) - 1;
  rep(i, 0, n - 1) {
    // cout << itv[i].second << " " << itv[i].first << ": ";
    if (tmp_e <= itv[i].second) {
      ans++;
      tmp_e = itv[i].first;
      // cout << "+";
    } else {
      // cout << "-";
    }
    // cout << endl;
  }
  cout << ans << endl;
  return 0;
}
