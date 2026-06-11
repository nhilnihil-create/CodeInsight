#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define f1(i, a, b) for (int i = a; i <= (b); ++i)
#define rep(i, n) f(i, 0, n)
using namespace std;
using ll = long long;

int main(void) {
  int n;
  cin >> n;
  vector<int> p(n), q(n);
  rep(i, n) cin >> p[i];
  rep(i, n) cin >> q[i];
  vector<int> a(n);
  rep(i, n) a[i] = i + 1;

  map<vector<int>, int> np;
  do {
    np[a] = np.size();
  } while (next_permutation(a.begin(), a.end()));

  int ans = abs(np[p] - np[q]);
  cout << ans << '\n';
  return 0;
}