#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> p(n), q(n);
  rep(i, n) cin >> p[i];
  rep(i, n) cin >> q[i];

  vector<int> r(n);
  rep(i, n) r[i] = i+1;

  int a, b;
  int i = 0;
  do {
    bool same_p = true, same_q = true;
    rep(j, n) if (p[j] != r[j]) same_p = false;
    rep(j, n) if (q[j] != r[j]) same_q = false;
    if (same_p) a = i;
    if (same_q) b = i;
    i++;
  } while (next_permutation(r.begin(), r.end()));
  int ans = abs(a - b);
  cout << ans << endl;
  return 0;
}