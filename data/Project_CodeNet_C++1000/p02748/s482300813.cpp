#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A), b(B);
  rep(i, A) cin >> a[i];
  rep(i, B) cin >> b[i];
  vector<int> x(M), y(M), c(M);
  rep(i, M) {
    cin >> x[i] >> y[i] >> c[i];
    x[i]--;
    y[i]--;
  }

  int min_cost = *min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end());
  rep(i, M) min_cost = min(min_cost, a[x[i]] + b[y[i]] - c[i]);
  cout << min_cost << endl;
  return 0;
}