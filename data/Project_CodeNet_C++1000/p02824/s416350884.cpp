#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 100005;

int n, m, v, p, a[N];

ll cum[N];

int main() {
  cin >> n >> m >> v >> p;
  rep(i, n) cin >> a[i];
  sort(a, a + n, greater<int>());
  cum[0] = 0;
  rep(i, n) cum[i+1] = cum[i] + a[i];
  int ans = 0;
  rep(ai, n) {
    if (ai < p) {
      ans++;
      continue;
    }
    int na = a[ai] + m;
    if (a[p-1] > na) continue;
    if (v < p) {
      ans++;
      continue;
    }
    if ((ll)na * (ai-p+1) - cum[ai] + cum[p-1] < (ll)m * max(0, v-p-n+ai+1)) continue;
    ans++;
  }
  cout << ans << endl;
  return 0;
}