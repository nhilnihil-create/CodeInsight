//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()



int main() {
  int A, B, m;
  cin >> A >> B >> m;
  vector<int> a(A), b(B), x(m), y(m), c(m), set(m);
  rep(i, A) cin >> a[i];
  rep(i, B) cin >> b[i];
  rep(i, m) {
    cin >> x[i] >> y[i] >> c[i];
    x[i]--; y[i]--;
    set[i] = a[x[i]] + b[y[i]] - c[i];
  }
  sort(all(set));
  sort(all(a));
  sort(all(b));
  cout << min(set[0], a[0]+b[0]) << endl;
  return 0;
}