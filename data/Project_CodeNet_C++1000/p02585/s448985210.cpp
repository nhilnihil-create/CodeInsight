#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

const int N = 5005;
const ll INF = 1e18;
int p[N], c[N];
bool seen[N];

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
  for (int i = 0; i < n; i++) cin >> c[i];

  ll ans = -INF;
  for (int i = 0; i < n; i++) {
    if (seen[i]) continue;
    VI cur;
    ll tot = 0;
    for (int j = i; !seen[j]; j = p[j]) {
      seen[j] = true;
      cur.push_back(c[j]);
      tot += c[j];
    }
    int sz = cur.size();
    tot = max(0ll, tot);

    for (int st = 0; st < sz; st++) {
      ll sum = 0;
      for (int j = 0; j < k && j < sz; j++) {
        sum += cur[(st + j) % sz];
        int cyc = (k - j - 1) / sz;
        ans = max(ans, sum + tot * cyc);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
