#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  sort(a.begin(), a.end());
  double cur = a[0];
  for (int i = 1; i < n; i++) {
    cur = (cur + a[i]) / 2;
  }
  cout << fixed << setprecision(10) << cur << endl;

  return 0;
}
